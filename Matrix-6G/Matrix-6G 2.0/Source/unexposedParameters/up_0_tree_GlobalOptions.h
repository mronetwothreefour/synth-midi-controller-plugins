#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

class GlobalOptions
{
	ValueTree globalOptionsTree;

public:
	GlobalOptions();
	void resetAllOptionsToDefaults();

	const uint8 basicChannel();
	void setBasicChannel(const uint8 newChannel);

	const bool omniModeIsEnabled();
	void setOmniModeIsEnabled(const bool shouldBeEnabled);

	const bool controllersAreEnabled();
	void setControllersAreEnabled(const bool shouldBeEnabled);

	const bool voiceChangesAreEnabled();
	void setVoiceChangesAreEnabled(const bool shouldBeEnabled);

	const bool sysExIsEnabled();
	void setSysExIsEnabled(const bool shouldBeEnabled);

	const bool spilloverIsEnabled();
	void setSpilloverIsEnabled(const bool shouldBeEnabled);

	const bool midiEchoIsEnabled();
	void set_MIDI_EchoIsEnabled(const bool shouldBeEnabled);

	const bool midiMonoIsEnabled();
	void set_MIDI_MonoIsEnabled(const bool shouldBeEnabled);

	const bool activeSensingIsEnabled();
	void setActiveSensingIsEnabled(const bool shouldBeEnabled);

	const bool localControlIsEnabled();
	void setLocalControIsEnabled(const bool shouldBeEnabled);

	const uint8 pedal_1_ControllerNumber();
	void setPedal_1_ControllerNumber(const uint8 newControllerNum);

	const uint8 pedal_2_ControllerNumber();
	void setPedal_2_ControllerNumber(const uint8 newControllerNum);

	const uint8 lever_2_ControllerNumber();
	void setLever_2_ControllerNumber(const uint8 newControllerNum);

	const uint8 lever_3_ControllerNumber();
	void setLever_3_ControllerNumber(const uint8 newControllerNum);

	const uint8 vibratoSpeed();
	void setVibratoSpeed(const uint8 newSpeed);

	const VibratoWaveType vibratoWaveType();
	void setVibratoWaveType(const VibratoWaveType newWaveType);

	const uint8 vibratoAmplitude();
	void setVibratoAmplitude(const uint8 newAmplitude);

	const VibratoModSource vibratoSpeedModSource();
	void setVibratoSpeedModSource(const VibratoModSource newSource);

	const uint8 vibratoSpeedModAmount();
	void setVibratoSpeedModAmount(const uint8 newAmount);

	const VibratoModSource vibratoAmpModSource();
	void setVibratoAmpModSource(const VibratoModSource newSource);

	const uint8 vibratoAmpModAmount();
	void setVibratoAmpModAmount(const uint8 newAmount);

	const uint8 globalTune();
	void setGlobalTune(const uint8 newTune);

	const bool splitStereoIsEnabled();
	void setSplitStereoIsEnabled(const bool shouldBeEnabled);

	const bool voicesMapIsEnabled();
	void setVoicesMapIsEnabled(const bool shouldBeEnabled);

	const bool voicesMapEchoIsEnabled();
	void setVoicesMapEchoIsEnabled(const bool shouldBeEnabled);

	const uint8 displayBrightness();
	void setDisplayBrightness(const uint8 newBrightness);

	const bool squickIsEnabled();
	void set_SQUICK_IsEnabled(const bool shouldBeEnabled);

	const uint8 voicesMapInVoiceForProgramNumber(const uint8 programNumber);
	void setVoicesMapInVoiceForProgramNumber(const uint8 newInVoice, const uint8 programNumber);

	const uint8 voicesMapOutVoiceForProgramNumber(const uint8 programNumber);
	void setVoicesMapOutVoiceForProgramNumber(const uint8 newOutVoice, const uint8 programNumber);

	void resetVoicesMap();

	Value getGobalParamAsValue(const Identifier paramID);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalOptions)
};