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

	ButtonForExportingEntireBankToFile(VoicesBank bank, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Export_VoicesBank_.toString() + String((int)bank));
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Exports the data for all the programs in the storage bank to a\n";
			tip += "file which can be read by other instances of the MophoGUI plugin.";
		}
		setTooltip(tip);
		setSize(GUI::voicesBanksLayerButtons_w, GUI::redButton_h);
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
		setComponentID(ID::btn_Export_VoiceFromBank_.toString() + String((int)bank));
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Exports the program data stored in the selected slot to a file\n";
			tip += "which can be read by other instances of the MophoGUI plugin.";
		}
		setTooltip(tip);
		setSize(GUI::voicesBanksLayerButtons_w, GUI::redButton_h);
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
		setComponentID(ID::btn_Import_AllVoicesIntoBank_.toString() + String((int)bank));
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Replace all the programs in the storage\n";
			tip += "bank with those stored in a file.";
		}
		setTooltip(tip);
		setSize(GUI::voicesBanksLayerButtons_w, GUI::redButton_h);
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
		setComponentID(ID::btn_Import_VoiceIntoBank_.toString() + String((int)bank));
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Imports the program data stored in\n";
			tip += "a file into the selected storage slot.";
		}
		setTooltip(tip);
		setSize(GUI::voicesBanksLayerButtons_w, GUI::redButton_h);
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
		setComponentID(ID::btn_Load.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Applies the program settings stored in the selected slot to the\n";
			tip += "plugin GUI and to the Mopho hardware" + GUI::apostrophe + "s program edit buffer.";
		}
		setTooltip(tip);
		onClick = [this, voiceSlots] { voiceSlots->loadVoiceFromSelectedSlot(); };
		setSize(GUI::voicesBanksLayerButtons_w, GUI::redButton_h);
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
		setComponentID(ID::btn_Pull_VoicesBank_.toString() + String((int)bank));
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Pull all the programs stored in the storage bank in\n";
			tip += "the Mopho hardware into this plugin storage bank.";
		}
		setTooltip(tip);
		setSize(GUI::voicesBanksLayerButtons_w, GUI::redButton_h);
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
		setComponentID(ID::btn_Pull_SelectedVoice.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Pull the data from the selected program storage slot in the Mopho\n";
			tip += "hardware and save it in the corresponding storage slot in the plugin.";
		}
		setTooltip(tip);
		onClick = [this, voiceSlots] { voiceSlots->pullSelectedVoiceFromHardware(); };
		setSize(GUI::voicesBanksLayerButtons_w, GUI::redButton_h);
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
		setComponentID(ID::btn_Push_VoicesBank_.toString() + String((int)bank));
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Push all the programs stored in this bank to the\n";
			tip += "corresponding storage bank in the Mopho hardware.";
		}
		setTooltip(tip);
		setSize(GUI::voicesBanksLayerButtons_w, GUI::redButton_h);
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
		setComponentID(ID::btn_Push_SelectedVoice.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Push the data in the selected program storage slot\n";
			tip += "to the corresponding storage slot in the Mopho hardware.";
		}
		setTooltip(tip);
		onClick = [this, voiceSlots] { voiceSlots->pushSelectedVoiceToHardware(); };
		setSize(GUI::voicesBanksLayerButtons_w, GUI::redButton_h);
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
		setComponentID(ID::btn_Save.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Saves the plugin GUI" + GUI::apostrophe + "s current settings\n";
			tip += "into the selected program storage slot.";
		}
		setTooltip(tip);
		onClick = [this, voiceSlots] { voiceSlots->saveCurrentVoiceSettingsIntoSelectedSlot(); };
		setSize(GUI::voicesBanksLayerButtons_w, GUI::redButton_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSavingVoiceIntoSelectedSlot)
};
