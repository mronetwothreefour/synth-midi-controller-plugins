#pragma once

#include <JuceHeader.h>



class GlobalOptions
{
	ValueTree globalOptionsTree;

public:
	GlobalOptions();

private:
	void fillGlobalOptionsTreeWithProperties();

public:
	void resetAllOptionsToDefaults();
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);

	const uint8 basicChannel();
	void setBasicChannel(uint8 newValue);

	const uint8 omniModeEnabled();
	void setOmniModeEnabled(uint8 newValue);

	const uint8 controllersEnabled();
	void setControllersEnabled(uint8 newValue);

	const uint8 voiceChangesEnabled();
	void setVoiceChangesEnabled(uint8 newValue);

	const uint8 sysExEnabled();
	void setSysExEnabled(uint8 newValue);

	const uint8 spilloverEnabled();
	void setSpilloverEnabled(uint8 newValue);

	const uint8 midiEchoEnabled();
	void setMIDIechoEnabled(uint8 newValue);

	const uint8 midiMonoEnabled();
	void setMIDImonoEnabled(uint8 newValue);

	const uint8 activeSensingEnabled();
	void setActiveSensingEnabled(uint8 newValue);

	const uint8 localControlEnabled();
	void setLocalControlEnabled(uint8 newValue);

	const uint8 pedal1ControllerNumber();
	void setPedal1ControllerNumber(uint8 newValue);

	const uint8 pedal2ControllerNumber();
	void setPedal2ControllerNumber(uint8 newValue);

	const uint8 lever2ControllerNumber();
	void setLever2ControllerNumber(uint8 newValue);

	const uint8 lever3ControllerNumber();
	void setLever3ControllerNumber(uint8 newValue);

	const uint8 vibratoSpeed();
	void setVibratoSpeed(uint8 newValue);

	const uint8 vibratoWaveType();
	void setVibratoWaveType(uint8 newValue);

	const uint8 vibratoAmplitude();
	void setVibratoAmplitude(uint8 newValue);

	const uint8 vibratoSpeedModSource();
	void setVibratoSpeedModSource(uint8 newValue);

	const uint8 vibratoSpeedModAmount();
	void setVibratoSpeedModAmount(uint8 newValue);

	const uint8 vibratoAmplitudeModSource();
	void setVibratoAmplitudeModSource(uint8 newValue);

	const uint8 vibratoAmplitudeModAmount();
	void setVibratoAmplitudeModAmount(uint8 newValue);

	const uint8 globalTune();
	void setGlobalTune(uint8 newValue);

	const uint8 splitStereoEnabled();
	void setSplitStereoEnabled(uint8 newValue);

	const uint8 voicesMapEnabled();
	void setVoicesMapEnabled(uint8 newValue);

	const uint8 voicesMapEchoEnabled();
	void setVoicesMapEchoEnabled(uint8 newValue);

	const uint8 displayBrightness();
	void setDisplayBrightness(uint8 newValue);

	const uint8 squickEnabled();
	void setSQUICKenabled(uint8 newValue);

	const uint8 voicesMapInVoiceForProgramNumber(uint8 programNumber);
	void setVoicesMapInVoiceForProgramNumber(uint8 newValue, uint8 programNumber);

	const uint8 voicesMapOutVoiceForProgramNumber(uint8 programNumber);
	void setVoicesMapOutVoiceForProgramNumber(uint8 newValue, uint8 programNumber);

	void resetVoicesMap();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalOptions)
};