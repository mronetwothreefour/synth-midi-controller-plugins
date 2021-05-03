#pragma once

#include <JuceHeader.h>



class MasterOptions
{
	ValueTree masterOptionsTree;

public:
	MasterOptions();

private:
	void fillMasterOptionsTreeWithProperties();

public:
	void resetMasterOptionsToDefaults();
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);

	const uint8 basicChannel();
	void setBasicChannel(uint8 newValue);

	const uint8 omniModeEnabled();
	void setOmniModeEnabled(uint8 newValue);

	const uint8 controllersEnabled();
	void setControllersEnabled(uint8 newValue);

	const uint8 patchChangesEnabled();
	void setPatchChangesEnabled(uint8 newValue);

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

	const uint8 masterTune();
	void setMasterTune(uint8 newValue);

	const uint8 splitStereoEnabled();
	void setSplitStereoEnabled(uint8 newValue);

	const uint8 patchMapEnabled();
	void setPatchMapEnabled(uint8 newValue);

	const uint8 patchMapEchoEnabled();
	void setPatchMapEchoEnabled(uint8 newValue);

	const uint8 displayBrightness();
	void setDisplayBrightness(uint8 newValue);

	const uint8 squickEnabled();
	void setSQUICKenabled(uint8 newValue);

	const uint8 patchMapInPatchForProgramNumber(uint8 programNumber);
	void setPatchMapInPatchForProgramNumber(uint8 newValue, uint8 programNumber);

	const uint8 patchMapOutPatchForProgramNumber(uint8 programNumber);
	void setPatchMapOutPatchForProgramNumber(uint8 newValue, uint8 programNumber);

	void resetPatchMap();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MasterOptions)
};