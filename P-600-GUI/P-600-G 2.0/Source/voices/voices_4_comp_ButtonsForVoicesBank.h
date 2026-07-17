#pragma once

#include <JuceHeader.h>

#include "voices_3_comp_VoiceSlots.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

class ButtonForEditingSelectedVoiceName :
	public TextButton
{
public:

	ButtonForEditingSelectedVoiceName() = delete;

	ButtonForEditingSelectedVoiceName(VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Name.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Click to change the name of the selected program.\n";
			tip += "NOTE: The Prophet-600 hardware doesn" + GUI::apostrophe + "t store program names.";
		}
		setTooltip(tip);
		onClick = [voiceSlots] { voiceSlots->showVoiceNameEditorForSelectedSlot(); };
		setSize(GUI::buttons_w, GUI::buttons_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForEditingSelectedVoiceName)
};




class ButtonForExportingEntireBankToFile :
	public TextButton
{
public:

	ButtonForExportingEntireBankToFile() = delete;

	ButtonForExportingEntireBankToFile(UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Expt_VoicesBank.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Exports the data for all the programs in the storage bank to a\n";
			tip += "file which can be read by other instances of the P-600-G plugin.";
		}
		setTooltip(tip);
		setSize(GUI::buttons_w, GUI::buttons_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForExportingEntireBankToFile)
};




class ButtonForExportingSelectedVoiceToFile :
	public TextButton
{
public:

	ButtonForExportingSelectedVoiceToFile() = delete;

	ButtonForExportingSelectedVoiceToFile(UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Expt_Voice.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Exports the program data stored in the selected slot to a file\n";
			tip += "which can be read by other instances of the P-600-G plugin.";
		}
		setTooltip(tip);
		setSize(GUI::buttons_w, GUI::buttons_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForExportingSelectedVoiceToFile)
};




class ButtonForImportingEntireBankFromFile :
	public TextButton
{
public:

	ButtonForImportingEntireBankFromFile() = delete;

	ButtonForImportingEntireBankFromFile(UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Impt_VoicesBank.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Replace all the programs in the storage\n";
			tip += "bank with those stored in a file.";
		}
		setTooltip(tip);
		setSize(GUI::buttons_w, GUI::buttons_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForImportingEntireBankFromFile)
};




class ButtonForImportingVoiceFromFile :
	public TextButton
{
public:

	ButtonForImportingVoiceFromFile() = delete;

	ButtonForImportingVoiceFromFile(UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Impt_Voice.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Imports the program data stored in\n";
			tip += "a file into the selected storage slot.";
		}
		setTooltip(tip);
		setSize(GUI::buttons_w, GUI::buttons_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForImportingVoiceFromFile)
};




class ButtonForLoadingSelectedVoice :
	public TextButton,
	private Timer
{
public:

	ButtonForLoadingSelectedVoice() = delete;

	ButtonForLoadingSelectedVoice(VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Load.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Applies the program settings stored in the selected slot\n";
			tip += "to the plugin GUI and pushes them to the corresponding\n";
			tip += "hardware storage slot. NOTE: This overwrites the program\n";
			tip += "data in the hardware storage slot and cannot be undone.";
		}
		setTooltip(tip);
		onClick = [this, voiceSlots, unexposedParams] {
			if (voiceSlots->selectedSlot < VCS::numberOfSlotsInVoicesBank) {
				voiceSlots->loadVoiceFromSelectedSlot();
				auto transmitTime{ unexposedParams->getVoiceTransmissionOptions()->voiceTransmitTime() };
				unexposedParams->getOutgoing_MIDI_Buffers()->addProgramChangeMessageAfterDelay(voiceSlots->selectedSlot, transmitTime);
			}
		};
		setSize(GUI::buttons_w, GUI::buttons_h);
	}

private:
	void timerCallback() override {}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForLoadingSelectedVoice)
};




class ButtonForPullingEntireBankFromHardware :
	public TextButton
{
public:
	ButtonForPullingEntireBankFromHardware() = delete;

	ButtonForPullingEntireBankFromHardware(UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Pull_VoicesBank.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Pull all the programs stored in the Prophet-600\n";
			tip += "hardware into the plugin storage bank. NOTE: The\n";
			tip += "Prophet-600 does not store program names, so the\n";
			tip += "names displayed in the slots will be deleted.";
		}
		setTooltip(tip);
		setSize(GUI::buttons_w, GUI::buttons_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPullingEntireBankFromHardware)
};




class ButtonForPullingSelectedVoiceFromHardware :
	public TextButton,
	private Timer
{
public:

	ButtonForPullingSelectedVoiceFromHardware() = delete;

	ButtonForPullingSelectedVoiceFromHardware(VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Pull_Voice.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Pull the data from the selected program storage slot in the\n";
			tip += "Prophet-600 hardware and save it in the corresponding slot in\n";
			tip += "the plugin storage bank. There will then be a prompt to name\n";
			tip += "the program (the hardware does not store program names).";
		}
		setTooltip(tip);
		onClick = [this, voiceSlots, unexposedParams] {
			voiceSlots->pullSelectedVoiceFromHardware(); 
			auto transmitTime{ unexposedParams->getVoiceTransmissionOptions()->voiceTransmitTime() };
			unexposedParams->getOutgoing_MIDI_Buffers()->addProgramChangeMessageAfterDelay(voiceSlots->selectedSlot, transmitTime);
			callAfterDelay(transmitTime, [unexposedParams, voiceSlots] { voiceSlots->showVoiceNameEditorForSelectedSlot(); });
		};
		setSize(GUI::buttons_w, GUI::buttons_h);
	}

private:
	void timerCallback() override {}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPullingSelectedVoiceFromHardware)
};




class ButtonForPushingEntireBankToHardware :
	public TextButton
{
public:
	ButtonForPushingEntireBankToHardware() = delete;

	ButtonForPushingEntireBankToHardware(UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Push_VoicesBank.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Push all the programs stored in the plugin bank\n";
			tip += "to the Prophet-600 hardware" + GUI::apostrophe + "s storage bank. NOTE:\n";
			tip += "All the program data stored in the hardware will\n";
			tip += "be overwritten and this cannot be undone.";
		}
		setTooltip(tip);
		setSize(GUI::buttons_w, GUI::buttons_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPushingEntireBankToHardware)
};




class ButtonForRestoringFactoryVoices :
	public TextButton
{
public:

	ButtonForRestoringFactoryVoices() = delete;

	ButtonForRestoringFactoryVoices(UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_RestoreFactoryVoices.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Restores the entire plugin bank to the original\n";
			tip += "factory programs. NOTE: This cannot be undone.";
		}
		setTooltip(tip);
		setSize(GUI::buttons_w, GUI::buttons_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForRestoringFactoryVoices)
};




class ButtonForSavingVoiceIntoSelectedSlot :
	public TextButton,
	private Timer
{
public:

	ButtonForSavingVoiceIntoSelectedSlot() = delete;

	ButtonForSavingVoiceIntoSelectedSlot(VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Save.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Saves the plugin GUI" + GUI::apostrophe + "s current settings in the\n";
			tip += "selected program storage slot, both in this\n";
			tip += "storage bank and in the Prophet-600 hardware.\n";
			tip += "NOTE: This will overwrite the data stored in\n";
			tip += "the hardware and cannot be undone. There will\n";
			tip += "then be a prompt to change the program" + GUI::apostrophe + "s name.";
		}
		setTooltip(tip);
		onClick = [this, voiceSlots, unexposedParams] {
			if (voiceSlots->selectedSlot < VCS::numberOfSlotsInVoicesBank) {
				voiceSlots->saveCurrentVoiceSettingsIntoSelectedSlot();
				auto transmitTime{ unexposedParams->getVoiceTransmissionOptions()->voiceTransmitTime() };
				unexposedParams->getOutgoing_MIDI_Buffers()->addProgramChangeMessageAfterDelay(voiceSlots->selectedSlot, transmitTime);
				callAfterDelay(transmitTime, [unexposedParams, voiceSlots] { voiceSlots->showVoiceNameEditorForSelectedSlot(); });
			}
		};
		setSize(GUI::buttons_w, GUI::buttons_h);
	}

private:
	void timerCallback() override {}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSavingVoiceIntoSelectedSlot)
};
