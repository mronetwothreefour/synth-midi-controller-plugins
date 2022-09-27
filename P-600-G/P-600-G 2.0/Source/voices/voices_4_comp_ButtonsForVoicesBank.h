#pragma once

#include <JuceHeader.h>

#include "voices_3_comp_VoiceSlots.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

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
		String tipString{ "" };
		if (tooltips->shouldShowDescription()) {
			tipString += "Exports the program data stored in the selected slot to a file\n";
			tipString += "which can be read by other instances of the P-600-G plugin.";
		}
		setTooltip(tipString);
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
		String tipString{ "" };
		if (tooltips->shouldShowDescription()) {
			tipString += "Replace all the programs in the storage\n";
			tipString += "bank with those stored in a file.";
		}
		setTooltip(tipString);
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
		String tipString{ "" };
		if (tooltips->shouldShowDescription()) {
			tipString += "Imports the program data stored in\n";
			tipString += "a file into the selected storage slot.";
		}
		setTooltip(tipString);
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
		String tipString{ "" };
		if (tooltips->shouldShowDescription()) {
			tipString += "Applies the program settings stored in the selected slot\n";
			tipString += "to the plugin GUI and pushes them to the corresponding\n";
			tipString += "hardware storage slot. NOTE: This overwrites the program\n";
			tipString += "data in the hardware storage slot and cannot be undone.";
		}
		setTooltip(tipString);
		onClick = [this, voiceSlots, unexposedParams] {
			voiceSlots->loadVoiceFromSelectedSlot();
			auto transmitTime{ unexposedParams->getVoiceTransmissionOptions()->voiceTransmitTime() };
			callAfterDelay(transmitTime, [this, unexposedParams, voiceSlots] {
				unexposedParams->getOutgoing_MIDI_Buffers()->addProgramChangeMessage(voiceSlots->selectedSlot);
			});
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
		String tipString{ "" };
		if (tooltips->shouldShowDescription()) {
			tipString += "Pull all the programs stored in the Prophet-600\n";
			tipString += "hardware into the plugin storage bank. NOTE: The\n";
			tipString += "Prophet-600 does not store program names, so the\n";
			tipString += "names displayed in the slots will be deleted.";
		}
		setTooltip(tipString);
		setSize(GUI::buttons_w, GUI::buttons_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPullingEntireBankFromHardware)
};




class ButtonForPullingSelectedVoiceFromHardware :
	public TextButton
{
public:

	ButtonForPullingSelectedVoiceFromHardware() = delete;

	ButtonForPullingSelectedVoiceFromHardware(VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Pull_Voice.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tipString{ "" };
		if (tooltips->shouldShowDescription()) {
			tipString += "Pull the data from the selected program storage slot in the\n";
			tipString += "Prophet-600 hardware and save it in the corresponding slot in\n";
			tipString += "the plugin storage bank. There will then be a prompt to name\n";
			tipString += "the program (the hardware does not store program names).";
		}
		setTooltip(tipString);
		onClick = [this, voiceSlots] { voiceSlots->pullSelectedVoiceFromHardware(); };
		setSize(GUI::buttons_w, GUI::buttons_h);
	}

private:
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
		String tipString{ "" };
		if (tooltips->shouldShowDescription()) {
			tipString += "Push all the programs stored in the plugin bank\n";
			tipString += "to the Prophet-600 hardware" + GUI::apostrophe + "s storage bank. NOTE:\n";
			tipString += "All the program data stored in the hardware will\n";
			tipString += "be overwritten and this cannot be undone.";
		}
		setTooltip(tipString);
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
		String tipString{ "" };
		if (tooltips->shouldShowDescription()) {
			tipString += "Restores the entire plugin bank to the original\n";
			tipString += "factory programs. NOTE: This cannot be undone.";
		}
		setTooltip(tipString);
		setSize(GUI::buttons_w, GUI::buttons_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForRestoringFactoryVoices)
};




class ButtonForSavingVoiceIntoSelectedSlot :
	public TextButton
{
public:

	ButtonForSavingVoiceIntoSelectedSlot() = delete;

	ButtonForSavingVoiceIntoSelectedSlot(VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Save.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tipString{ "" };
		if (tooltips->shouldShowDescription()) {
			tipString += "Saves the plugin GUI" + GUI::apostrophe + "s current settings in the\n";
			tipString += "selected program storage slot, both in this\n";
			tipString += "storage bank and in the Prophet-600 hardware.\n";
			tipString += "NOTE: This will overwrite the data stored in\n";
			tipString += "the hardware and cannot be undone. There will\n";
			tipString += "then be a prompt to change the program" + GUI::apostrophe + "s name.";
		}
		setTooltip(tipString);
		onClick = [this, voiceSlots] { voiceSlots->saveCurrentVoiceSettingsIntoSelectedSlot(); };
		setSize(GUI::buttons_w, GUI::buttons_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSavingVoiceIntoSelectedSlot)
};
