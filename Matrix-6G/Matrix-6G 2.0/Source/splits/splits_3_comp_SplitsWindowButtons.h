#pragma once

#include <JuceHeader.h>

#include "splits_2_comp_SplitSlots.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

class ButtonForLoadingSelectedSplit :
	public TextButton,
	private Timer
{
public:

	ButtonForLoadingSelectedSplit() = delete;

	ButtonForLoadingSelectedSplit(SplitSlots* splitSlots, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Load_Split.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Loads the split settings stored in the selected slot into the plugin GUI\n";
			tip += "and pushes it into the corresponding slot on the hardware. NOTE: This will\n";
			tip += "overwrite the split data in the hardware storage slot and cannot be undone.";
		}
		setTooltip(tip);
		onClick = [this, splitSlots, unexposedParams] {
			splitSlots->loadSplitFromSelectedSlot();
			auto transmitTime{ unexposedParams->getVoiceTransmissionOptions()->voiceTransmitTime() };
			callAfterDelay(transmitTime, [this, unexposedParams, splitSlots] {
				auto channel{ unexposedParams->getGlobalOptions()->basicChannel() };
				unexposedParams->getOutgoing_MIDI_Buffers()->addProgramChangeMessage(channel, splitSlots->selectedSlot);
			});
		};
		setSize(GUI::buttons_SplitsBank_w, GUI::buttons_small_h);
	}

private:
	void timerCallback() override {}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForLoadingSelectedSplit)
};




class ButtonForPullingSelectedSplitFromHardware :
	public TextButton,
	private Timer
{
public:

	ButtonForPullingSelectedSplitFromHardware() = delete;

	ButtonForPullingSelectedSplitFromHardware(SplitSlots* splitSlots, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Pull_Split.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Pull the data from the selected split storage slot in\n";
			tip += "the Matrix-6R hardware and save it in the corresponding\n";
			tip += "slot in the plugin storage bank.";
		}
		setTooltip(tip);
		onClick = [this, splitSlots, unexposedParams] {
			splitSlots->pullSelectedSplitFromHardware(); 
			auto transmitTime{ unexposedParams->getVoiceTransmissionOptions()->voiceTransmitTime() };
			callAfterDelay(transmitTime, [this, unexposedParams, splitSlots] {
				auto channel{ unexposedParams->getGlobalOptions()->basicChannel() };
				unexposedParams->getOutgoing_MIDI_Buffers()->addProgramChangeMessage(channel, splitSlots->selectedSlot);
			});
		};
		setSize(GUI::buttons_SplitsBank_w, GUI::buttons_small_h);
	}

private:
	void timerCallback() override {}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPullingSelectedSplitFromHardware)
};




class ButtonForPullingEntireSplitsBankFromHardware :
	public TextButton
{
public:
	ButtonForPullingEntireSplitsBankFromHardware() = delete;

	explicit ButtonForPullingEntireSplitsBankFromHardware(UnexposedParameters* unexposedParams) 
	{
		setComponentID(ID::btn_Pull_SplitsBank.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Pull all the splits stored in the Matrix-6R\n";
			tip += "hardware into this plugin storage bank.";
		}
		setTooltip(tip);
		setSize(GUI::buttons_SplitsBank_w, GUI::buttons_small_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPullingEntireSplitsBankFromHardware)
};




class ButtonForPushingEntireSplitsBankToHardware :
	public TextButton
{
public:
	ButtonForPushingEntireSplitsBankToHardware() = delete;

	explicit ButtonForPushingEntireSplitsBankToHardware(UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Push_SplitsBank.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Push all the splits stored in this bank to\n";
			tip += "the Matrix hardware" + GUI::apostrophe + "s storage bank. NOTE: All\n";
			tip += "the split data stored in the hardware will be\n";
			tip += "overwritten and this cannot be undone.";
		}
		setTooltip(tip);
		setSize(GUI::buttons_SplitsBank_w, GUI::buttons_small_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPushingEntireSplitsBankToHardware)
};




class ButtonForSavingSplitIntoSelectedSlot :
	public TextButton,
	private Timer
{
public:

	ButtonForSavingSplitIntoSelectedSlot() = delete;

	ButtonForSavingSplitIntoSelectedSlot(SplitSlots* splitSlots, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Save_Split.toString());
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			tip += "Saves the current split settings in the\n";
			tip += "selected patch storage slot, both in the\n";
			tip += "plugin storage bank and in the Matrix-6R\n";
			tip += "hardware. NOTE: This will overwrite the data\n";
			tip += "stored in the hardware and cannot be undone.";
		}
		setTooltip(tip);
		onClick = [this, splitSlots, unexposedParams] {
			splitSlots->saveCurrentSplitSettingsIntoSelectedSlot(); 
			callAfterDelay(100, [this, splitSlots, unexposedParams] {
				splitSlots->pushSelectedSplitToHardware(); 
				auto transmitTime{ unexposedParams->getVoiceTransmissionOptions()->voiceTransmitTime() };
				callAfterDelay(transmitTime, [this, unexposedParams, splitSlots] {
					auto channel{ unexposedParams->getGlobalOptions()->basicChannel() };
					unexposedParams->getOutgoing_MIDI_Buffers()->addProgramChangeMessage(channel, splitSlots->selectedSlot);
				});
			});
		};
		setSize(GUI::buttons_SplitsBank_w, GUI::buttons_small_h);
	}

private:
	void timerCallback() override {}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSavingSplitIntoSelectedSlot)
};
