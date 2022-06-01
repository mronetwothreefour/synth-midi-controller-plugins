#pragma once

#include <JuceHeader.h>

#include "2_voices_comp_VoiceSlots.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



class ButtonForExportingEntireBankToFile :
	public TextButton
{
public:

	ButtonForExportingEntireBankToFile() = delete;

	ButtonForExportingEntireBankToFile(VoicesBank bank, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::button_Export_VoicesBank_.toString() + String((int)bank));
		auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
		String tipString{ "" };
		if (tooltipOptions->shouldShowDescriptions()) {
			tipString += "Exports the data for all the programs in the storage bank to a\n";
			tipString += "file which can be read by other instances of the MophoGUI plugin.";
		}
		setTooltip(tipString);
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

	ButtonForExportingSelectedVoiceToFile(VoicesBank bank, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::button_Export_VoiceFromBank_.toString() + String((int)bank));
		auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
		String tipString{ "" };
		if (tooltipOptions->shouldShowDescriptions()) {
			tipString += "Exports the program data stored in the selected slot to a file\n";
			tipString += "which can be read by other instances of the MophoGUI plugin.";
		}
		setTooltip(tipString);
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

	ButtonForImportingEntireBankFromFile(VoicesBank bank, UnexposedParameters* unexposedParams)
	{
		jassert(bank == VoicesBank::custom_1 || bank == VoicesBank::custom_2 || bank == VoicesBank::custom_3);
		setComponentID(ID::button_Import_AllVoicesIntoBank_.toString() + String((int)bank));
		auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
		String tipString{ "" };
		if (tooltipOptions->shouldShowDescriptions()) {
			tipString += "Replace all the programs in the storage\n";
			tipString += "bank with those stored in a file.";
		}
		setTooltip(tipString);
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

	ButtonForImportingVoiceFromFile(VoicesBank bank, UnexposedParameters* unexposedParams)
	{
		jassert(bank == VoicesBank::custom_1 || bank == VoicesBank::custom_2 || bank == VoicesBank::custom_3);
		setComponentID(ID::button_Import_VoiceIntoBank_.toString() + String((int)bank));
		auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
		String tipString{ "" };
		if (tooltipOptions->shouldShowDescriptions()) {
			tipString += "Imports the program data stored in\n";
			tipString += "a file into the selected storage slot.";
		}
		setTooltip(tipString);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForImportingVoiceFromFile)
};




class ButtonForLoadingSelectedVoice :
	public TextButton
{
public:

	ButtonForLoadingSelectedVoice() = delete;

	ButtonForLoadingSelectedVoice(VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::button_Load.toString());
		auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
		String tipString{ "" };
		if (tooltipOptions->shouldShowDescriptions()) {
			tipString += "Applies the program settings stored in the selected slot to the\n";
			tipString += "plugin GUI and to the Mopho hardware" + GUI::apostrophe + "s program edit buffer.";
		}
		setTooltip(tipString);
		onClick = [this, voiceSlots] { voiceSlots->loadVoiceFromSelectedSlot(); };
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForLoadingSelectedVoice)
};




class ButtonForPullingEntireBankFromHardware : 
	public TextButton
{
public:
	ButtonForPullingEntireBankFromHardware() = delete;

	ButtonForPullingEntireBankFromHardware(VoicesBank bank, UnexposedParameters* unexposedParams)
	{
		jassert(bank == VoicesBank::custom_1 || bank == VoicesBank::custom_2 || bank == VoicesBank::custom_3);
		setComponentID(ID::button_Pull_VoicesBank_.toString() + String((int)bank));
		auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
		String tipString{ "" };
		if (tooltipOptions->shouldShowDescriptions()) {
			tipString += "Pull all the programs stored in the storage bank in\n";
			tipString += "the Mopho hardware into this plugin storage bank.";
		}
		setTooltip(tipString);
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
		setComponentID(ID::button_Pull_SelectedVoice.toString());
		auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
		String tipString{ "" };
		if (tooltipOptions->shouldShowDescriptions()) {
			tipString += "Pull the data from the selected program storage slot in the Mopho\n";
			tipString += "hardware and save it in the corresponding storage slot in the plugin.";
		}
		setTooltip(tipString);
		onClick = [this, voiceSlots] { voiceSlots->pullSelectedVoiceFromHardware(); };
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

	ButtonForPushingEntireBankToHardware(VoicesBank bank, UnexposedParameters* unexposedParams)
	{
		jassert(bank == VoicesBank::custom_1 || bank == VoicesBank::custom_2 || bank == VoicesBank::custom_3);
		setComponentID(ID::button_Push_VoicesBank_.toString() + String((int)bank));
		auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
		String tipString{ "" };
		if (tooltipOptions->shouldShowDescriptions()) {
			tipString += "Push all the programs stored in this bank to the\n";
			tipString += "corresponding storage bank in the Mopho hardware.";
		}
		setTooltip(tipString);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPushingEntireBankToHardware)
};




class ButtonForPushingSelectedVoiceToHardware :
	public TextButton
{
public:

	ButtonForPushingSelectedVoiceToHardware() = delete;

	ButtonForPushingSelectedVoiceToHardware(VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::button_Push_SelectedVoice.toString());
		auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
		String tipString{ "" };
		if (tooltipOptions->shouldShowDescriptions()) {
			tipString += "Push the data in the selected program storage slot\n";
			tipString += "to the corresponding storage slot in the Mopho hardware.";
		}
		setTooltip(tipString);
		onClick = [this, voiceSlots] { voiceSlots->pushSelectedVoiceToHardware(); };
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPushingSelectedVoiceToHardware)
};




class ButtonForSavingVoiceIntoSelectedSlot :
	public TextButton
{
public:

	ButtonForSavingVoiceIntoSelectedSlot() = delete;

	ButtonForSavingVoiceIntoSelectedSlot(VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::button_Save.toString());
		auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
		String tipString{ "" };
		if (tooltipOptions->shouldShowDescriptions()) {
			tipString += "Saves the plugin GUI" + GUI::apostrophe + "s current settings\n";
			tipString += "into the selected program storage slot.";
		}
		setTooltip(tipString);
		onClick = [this, voiceSlots] { voiceSlots->saveCurrentVoiceSettingsIntoSelectedSlot(); };
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSavingVoiceIntoSelectedSlot)
};
