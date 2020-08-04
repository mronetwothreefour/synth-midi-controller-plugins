#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_CustomColors.h"
#include "../helpers/helper_Identifiers.h"
#include "../midiTools/midi_ProgramEditBufferDump.h"
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
	private Label::Listener,
	private Timer
{
	TextButton button;
	AudioProcessorValueTreeState* exposedParams;
	Label pgmNameEditor;
	String programName;
	int nameCharacter{ 0 };

	String getProgramNameFromExposedParemeters() {
		std::string pgmName{ "" };
		for (auto i = 1; i != 17; ++i) {
			auto param{ exposedParams->getParameter("nameChar" + (String)i) };
			pgmName += std::string(1, char(roundToInt(param->getValue() * 127)));
		}
		return pgmName;
	}

	void showPgmNameEditor() {
		pgmNameEditor.setText(getProgramNameFromExposedParemeters(), dontSendNotification);
		pgmNameEditor.showEditor();
		String basicASCIIcharacters{ " !\"#$ % &'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" };
		pgmNameEditor.getCurrentTextEditor()->setInputRestrictions(16, basicASCIIcharacters);
		String nameEditorTooltip;
		nameEditorTooltip =  "Type in a new name for the program (max. 16 characters) and hit Enter to apply it.\n";
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
		if (newName.length() < 16) {
			addSpacesToEndOfName(newName);
		}
		updateProgramNameOnHardware(newName);
	}

	void addSpacesToEndOfName(String& name) {
		for (auto i = name.length(); i != 16; ++i)
			name += " ";
	}

	void updateProgramNameOnHardware(String newName) {
		programName = newName;
		nameCharacter = 0;
		startTimer(10);
	}

	void timerCallback() override {
		stopTimer();
		if (nameCharacter > -1 && nameCharacter < 16) {
			updateNameCharacterInExposedParams();
		}
	}

	void updateNameCharacterInExposedParams() {
		auto param{ exposedParams->getParameter("nameChar" + (String)(nameCharacter + 1)) };
		if (param != nullptr) {
			auto normalizedValue{ (char)programName[nameCharacter] / 127.0f };
			param->setValueNotifyingHost(normalizedValue);
		}
		if (nameCharacter < 15) {
			++nameCharacter;
			startTimer(10);
		}
		else
			nameCharacter = -1;
	}

public:
	ButtonAndLabelForEditingPgmName(AudioProcessorValueTreeState* exposedParams) :
		button{ "EDIT" },
		exposedParams{ exposedParams },
		pgmNameEditor{ "pgmNameEditor", getProgramNameFromExposedParemeters() }
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
		tooltipString += "type in a new program name.";
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
	public TextButton,
	private Timer
{
	int trackNum;
	AudioProcessorValueTreeState* exposedParams;
	int sequencerStep{ 0 };

	void clearSequencerTrack() {
		sequencerStep = 1;
		startTimer(10);
	}

	void timerCallback() override {
		stopTimer();
		if (sequencerStep > 0 && sequencerStep < 17) {
			clearSequencerStep(sequencerStep);
			if (sequencerStep < 16) {
				++sequencerStep;
				startTimer(10);
			}
			else
				sequencerStep = 0;
		}
	}

	void clearSequencerStep(int step) {
		auto param{ exposedParams->getParameter("track" + (String)trackNum + "Step" + (String)step) };
		auto clearedValue{ trackNum == 1 ? 1.0f : 0.0f };
		param->setValueNotifyingHost(clearedValue);
	}

public:
	ButtonForClearingSequencerTrack() = delete;

	ButtonForClearingSequencerTrack(int trackNum, AudioProcessorValueTreeState* exposedParams) :
		TextButton{ "CLEAR" },
		trackNum{ trackNum },
		exposedParams{ exposedParams }
	{
		jassert(trackNum > 0 && trackNum < 5);
		String tipString;
		tipString = "Sets all steps in sequencer\n";
		if (trackNum == 1)
			tipString += "track 1 to 127 (\"rest\")";
		else 
			tipString += "track " + (String)trackNum + " to 0 (C0)";
		setTooltip(tipString);
		onClick = [this] { clearSequencerTrack(); };
	}

	~ButtonForClearingSequencerTrack() {
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForClearingSequencerTrack)
};



class ButtonForSendingProgramEditBufferDump :
	public TextButton
{
	AudioProcessorValueTreeState* exposedParams;

	void sendProgramEditBufferDump() {
		ProgramEditBufferDump::send(exposedParams);
	}

public:
	ButtonForSendingProgramEditBufferDump() = delete;

	explicit ButtonForSendingProgramEditBufferDump(AudioProcessorValueTreeState* exposedParams) :
		TextButton{ "WRITE" },
		exposedParams{ exposedParams }
	{
		String tipString;
		tipString =  "Writes the plugin's current program settings\n";
		tipString += "into the Mopho hardware's program edit buffer.";
		setTooltip(tipString);
		onClick = [this] { sendProgramEditBufferDump(); };
	}

	~ButtonForSendingProgramEditBufferDump() {
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSendingProgramEditBufferDump)
};



class ButtonForSendingProgramEditBufferDumpRequest :
	public TextButton
{
	void sendProgramEditBufferDumpRequest() {
		ProgramEditBufferDump::request();
	}

public:
	ButtonForSendingProgramEditBufferDumpRequest() :
		TextButton{ "READ" }
	{
		String tipString;
		tipString =  "Requests a program edit buffer dump from the Mopho hardware\n";
		tipString += "and applies it to the plugin's program settings.";
		setTooltip(tipString);
		onClick = [this] { sendProgramEditBufferDumpRequest(); };
	}

	~ButtonForSendingProgramEditBufferDumpRequest() {
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSendingProgramEditBufferDumpRequest)
};



class ButtonForOpeningProgramBanksWindow :
	public TextButton
{

public:
	ButtonForOpeningProgramBanksWindow() :
		TextButton{ "BANKS" }
	{
		String tipString;
		tipString =  "Opens a window where you can manage the\n";
		tipString += "three storage banks for program presets.";
		setTooltip(tipString);
	}

	~ButtonForOpeningProgramBanksWindow() {
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForOpeningProgramBanksWindow)
};
