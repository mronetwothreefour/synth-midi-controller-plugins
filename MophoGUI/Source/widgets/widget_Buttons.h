#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_CustomColors.h"
#include "../helpers/helper_Identifiers.h"
#include "../parameters/params_InfoForExposedParameters_Singleton.h"
#include "widget_TooltipSetters.h"

using ButtonAttachment = AudioProcessorValueTreeState::ButtonAttachment;



class ToggleButtonWithWithExposedParamAttacher : public Component
{
protected:
	ToggleButton toggle;
	std::unique_ptr<ButtonAttachment> attachment;
	uint8 param;
	TooltipSetterForExposedParamToggles tooltipSetter;

public:
	ToggleButtonWithWithExposedParamAttacher() = delete;

	explicit ToggleButtonWithWithExposedParamAttacher(uint8 param) :
		param{ param },
		tooltipSetter{ toggle, param }
	{
		addAndMakeVisible(toggle);
		toggle.setComponentID(ID::component_ToggleButton.toString());
		auto ctrlWidth{ InfoForExposedParameters::get().ctrlWidthFor(param) };
		auto ctrlHeight{ InfoForExposedParameters::get().ctrlHeightFor(param) };
		setSize(ctrlWidth, ctrlHeight);
		toggle.setSize(ctrlWidth, ctrlHeight);
	}

	~ToggleButtonWithWithExposedParamAttacher() {
	}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
		attachment.reset(new ButtonAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), toggle));
	}

	void deleteAttachment() {
		attachment = nullptr;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleButtonWithWithExposedParamAttacher)
};



class ButtonAndLabelForEditingPgmName : 
	public Component,
	private Label::Listener
{
	TextButton button;
	PluginProcessor& processor;
	Label pgmNameEditor;

	String getPgmName() {
		auto& info{ InfoForExposedParameters::get() };
		std::string pgmName{ "" };
		for (auto i = 1; i != 17; ++i) {
			auto paramIndex{ info.indexFor("nameChar" + (String)i) };
			auto param{ processor.getParameters()[paramIndex] };
			pgmName += std::string(1, char(roundToInt(param->getValue() * 127)));
		}
		return pgmName;
	}

	void showPgmNameEditor() {
		pgmNameEditor.showEditor();
		String basicASCIIcharacters{ " !\"#$ % &'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" };
		pgmNameEditor.getCurrentTextEditor()->setInputRestrictions(16, basicASCIIcharacters);
		String nameEditorTooltip;
		nameEditorTooltip = "Type in a new name for the program (max. 16 characters) and hit Enter to apply it.\n";
		nameEditorTooltip += "Hit Esc to cancel. The Mopho's hardware LCD characters use the basic ASCII\n";
		nameEditorTooltip += "character set, with a few exceptions: 'backslash' becomes a yen sign and 'tilde'\n";
		nameEditorTooltip += "becomes a right arrow. The 'delete' character becomes a left arrow; obviously,\n";
		nameEditorTooltip += "you can't type that in the editor. However, you can access it by changing a\n";
		nameEditorTooltip += "character in the GUI's name display with the mouse. The hardware name display\n";
		nameEditorTooltip += "will not update immediately - press the Program Mode button to see the new name.";
		pgmNameEditor.getCurrentTextEditor()->setTooltip(nameEditorTooltip);
	}

	void labelTextChanged(Label* labelThatHasChanged) override {
		String newName{ labelThatHasChanged->getText() };
		auto newNameLength{ newName.length() };
		if (newNameLength < 16) {
			for (auto i = newNameLength; i != 16; ++i)
				newName += " ";
		}
		processor.updateProgramNameOnHardware(newName);
	}

public:
	ButtonAndLabelForEditingPgmName(PluginProcessor& processor) :
		button{ "EDIT" },
		processor{ processor },
		pgmNameEditor{ "pgmNameEditor", getPgmName() }
	{
		setInterceptsMouseClicks(false, true);

		pgmNameEditor.setInterceptsMouseClicks(false, true);
		pgmNameEditor.setComponentID("pgmNameEditor");
		pgmNameEditor.setJustificationType(Justification::centredLeft);
		pgmNameEditor.setColour(Label::backgroundColourId, Colours::transparentBlack);
		pgmNameEditor.setColour(Label::outlineColourId, Colours::transparentBlack);
		pgmNameEditor.setColour(Label::textWhenEditingColourId, Color::controlText);
		pgmNameEditor.setColour(Label::backgroundWhenEditingColourId, Color::black);
		pgmNameEditor.setColour(Label::outlineWhenEditingColourId, Color::black);
		pgmNameEditor.addListener(this);
		addAndMakeVisible(pgmNameEditor);

		addAndMakeVisible(button);
		String tooltipString;
		tooltipString =  "Opens an editor where you can\n";
		tooltipString += "type in a new program name.\n";
		button.setTooltip(tooltipString);
		button.onClick = [this] { showPgmNameEditor(); };

		auto buttonAndEditor_w{ 222 };
		auto buttonAndEditor_h{ 50 };
		setSize(buttonAndEditor_w, buttonAndEditor_h);
		button.setBounds(115, 0, 42, 16);
		pgmNameEditor.setBounds(0, 32, 242, 18);
	}

	~ButtonAndLabelForEditingPgmName() {
		pgmNameEditor.removeListener(this);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonAndLabelForEditingPgmName)
};



class ButtonForClearingSequencerTrack :
	public TextButton
{
	int trackNum;
	PluginProcessor& processor;

	void clearSequencerTrack() {
		processor.clearSequencerTrack(trackNum);
	}

public:
	ButtonForClearingSequencerTrack() = delete;

	ButtonForClearingSequencerTrack(int trackNum, PluginProcessor& processor) :
		TextButton{ "CLEAR" },
		trackNum{ trackNum },
		processor{ processor }
	{
		onClick = [this] { clearSequencerTrack(); };
	}

	~ButtonForClearingSequencerTrack() {
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForClearingSequencerTrack)
};