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
		setComponentID(ID::btn_Expt_VoicesBank_.toString() + String((int)bank));
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Exports the data for all the patches in the storage bank to a\n";
			tip += "file which can be read by other instances of the Matrix-6G plugin.";
		}
		setTooltip(tip);
		setSize(GUI::buttons_VoicesBank_w, GUI::buttons_small_h);
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
		setComponentID(ID::btn_Expt_VoiceFromBank_.toString() + String((int)bank));
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Exports the patch data stored in the selected slot to a file\n";
			tip += "which can be read by other instances of the Matrix-6G plugin.";
		}
		setTooltip(tip);
		setSize(GUI::buttons_VoicesBank_w, GUI::buttons_small_h);
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
		jassert(bank == VoicesBank::custom_A || bank == VoicesBank::custom_B);
		setComponentID(ID::btn_Impt_AllVoicesIntoBank_.toString() + String((int)bank));
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Replace all the patches in the storage\n";
			tip += "bank with those stored in a file.";
		}
		setTooltip(tip);
		setSize(GUI::buttons_VoicesBank_w, GUI::buttons_small_h);
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
		jassert(bank == VoicesBank::custom_A || bank == VoicesBank::custom_B);
		setComponentID(ID::btn_Impt_VoiceIntoBank_.toString() + String((int)bank));
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Imports the patch data stored in\n";
			tip += "a file into the selected storage slot.";
		}
		setTooltip(tip);
		setSize(GUI::buttons_VoicesBank_w, GUI::buttons_small_h);
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
		setComponentID(ID::btn_Load_Voice.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Applies the patch settings stored in the selected slot\n";
			tip += "to the plugin GUI and pushes them to the corresponding\n";
			tip += "hardware storage slot. NOTE: This overwrites the program\n";
			tip += "data in the hardware storage slot and cannot be undone.";
		}
		setTooltip(tip);
		onClick = [this, voiceSlots, unexposedParams] {
			voiceSlots->loadVoiceFromSelectedSlot();
			auto transmitTime{ unexposedParams->getVoiceTransmissionOptions()->voiceTransmitTime() };
			callAfterDelay(transmitTime, [this, unexposedParams, voiceSlots] {
				auto channel{ unexposedParams->getGlobalOptions()->basicChannel() };
				unexposedParams->getOutgoing_MIDI_Buffers()->addProgramChangeMessage(channel, voiceSlots->selectedSlot);
			});
		};
		setSize(GUI::buttons_VoicesBank_w, GUI::buttons_small_h);
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

	ButtonForPullingEntireBankFromHardware(VoicesBank bank, UnexposedParameters* unexposedParams)
	{
		jassert(bank == VoicesBank::custom_A || bank == VoicesBank::custom_B);
		setComponentID(ID::btn_Pull_VoicesBank_.toString() + String((int)bank));
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Pull all the patches stored in the storage bank in\n";
			tip += "the Matrix-6R hardware into this plugin storage bank.";
		}
		setTooltip(tip);
		setSize(GUI::buttons_VoicesBank_w, GUI::buttons_small_h);
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
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Pull the data from the selected patch storage slot in the Matrix-6R\n";
			tip += "hardware and save it in the corresponding storage slot in the plugin.";
		}
		setTooltip(tip);
		onClick = [this, voiceSlots] { voiceSlots->pullSelectedVoiceFromHardware(); };
		setSize(GUI::buttons_VoicesBank_w, GUI::buttons_small_h);
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
			tip += "Push all the patches stored in the plugin bank to\n";
			tip += "the Matrix-6R hardware" + GUI::apostrophe + "s storage bank. NOTE:\n";
			tip += "All the patch data stored in the hardware will be\n";
			tip += "overwritten and this cannot be undone.";
		}
		setTooltip(tip);
		setSize(GUI::buttons_VoicesBank_w, GUI::buttons_small_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPushingEntireBankToHardware)
};




class ButtonForSavingVoiceIntoSelectedSlot :
	public TextButton
{
public:

	ButtonForSavingVoiceIntoSelectedSlot() = delete;

	ButtonForSavingVoiceIntoSelectedSlot(VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Save_Voice.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Saves the plugin GUI" + GUI::apostrophe + "s current settings in the\n";
			tip += "selected patch storage slot, both in this\n";
			tip += "storage bank and in the Matrix-6R hardware.\n";
			tip += "NOTE: This will overwrite the data stored\n";
			tip += "in the hardware and cannot be undone.";
		}
		setTooltip(tip);
		onClick = [this, voiceSlots] { voiceSlots->saveCurrentVoiceSettingsIntoSelectedSlot(); };
		setSize(GUI::buttons_VoicesBank_w, GUI::buttons_small_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSavingVoiceIntoSelectedSlot)
};
