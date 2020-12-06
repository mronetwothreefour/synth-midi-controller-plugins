#include "banks_ProgramBanksTabbedComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ProgramBanksTabbedComponent::ProgramBanksTabbedComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	TabbedComponent(TabbedButtonBar::TabsAtTop),
	unexposedParams{ unexposedParams },
	bank1{ 0, exposedParams, unexposedParams, programCopyBuffer },
	bank2{ 1, exposedParams, unexposedParams, programCopyBuffer },
	bank3{ 2, exposedParams, unexposedParams, programCopyBuffer }
{
	setTabBarDepth(30);
	setOutline(0);
	addTab("BANK    1", Color::device, &bank1, true, 1);
	addTab("BANK    2", Color::device, &bank2, true, 2);
	addTab("BANK    3", Color::device, &bank3, true, 3);
	setColour(backgroundColourId, Color::device.darker(0.25f));
	auto tab_w{ bank1.getWidth() };
	auto tab_h{ bank1.getHeight() };
	setSize(tab_w, tab_h + getTabBarDepth());

	auto tooltips{ unexposedParams->tooltipOptions_get() };
	String label_txTimeTooltip{ "" };
	if (tooltips->shouldShowDescription()) {
		label_txTimeTooltip += "The amount of time, in milliseconds, to allow for the complete transmission\n";
		label_txTimeTooltip += "of a single program between the plugin and the Mopho hardware. Increase\n";
		label_txTimeTooltip += "this value if programs are getting 'lost' during pushes or pulls.\n";
		label_txTimeTooltip += "Minimum time: 50 ms. Maximum time 5000 ms.";
	}
	label_txTime.setTooltip(label_txTimeTooltip);
	label_txTime.addListener(this);
	label_txTime.setComponentID(ID::component_EditLabel.toString());
	label_txTime.setEditable(true);
	labelTextChanged(&label_txTime);
	addAndMakeVisible(label_txTime);

	auto control_y{ 364 };
	auto control_w{ 50 };
	auto control_h{ 21 };
	label_txTime.setBounds(827, control_y, control_w, control_h);
}

void ProgramBanksTabbedComponent::editorShown(Label* label, TextEditor& editor) {
	if (label == &label_txTime) {
		editor.setInputRestrictions(4, "0123456789");
		auto midiOptions{ unexposedParams->midiOptions_get() };
		editor.setFont(FontsMenu::fontFor_Labels);
		editor.setText((String)midiOptions->programTransmitTime());
		editor.selectAll();
	}
}

void ProgramBanksTabbedComponent::labelTextChanged(Label* label) {
	if (label == &label_txTime) {
		auto midiOptions{ unexposedParams->midiOptions_get() };
		if (label->getText().isNotEmpty())
		{
			auto newValue{ label->getText().getIntValue() };
			if (newValue > 49 && newValue < 5001)
				midiOptions->setProgramTransmitTime(newValue);
		}
		label->setText((String)midiOptions->programTransmitTime() + " ms", dontSendNotification);
	}
}

ProgramBankTab* ProgramBanksTabbedComponent::getCurrentProgramBankTab() {
	switch (getCurrentTabIndex())
	{
	case 0:
		return &bank1;
	case 1:
		return &bank2;
	case 2:
		return &bank3;
	default:
		return nullptr;
	}
}

void ProgramBanksTabbedComponent::updateTextForAllProgramSlotsInAllBanks() {
	auto programBanks{ unexposedParams->programBanks_get() };
	for (uint8 slot = 0; slot != programBanks->programSlotOutOfRange(); ++slot) {
		bank1.updateProgramSlotText(slot);
		bank2.updateProgramSlotText(slot);
		bank3.updateProgramSlotText(slot);
	}
}

ProgramBanksTabbedComponent::~ProgramBanksTabbedComponent() {
}
