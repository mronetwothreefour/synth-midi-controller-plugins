#include "params_MasterOptions.h"

#include "params_Identifiers.h"
#include "../master/master_Constants.h"
#include "../voices/voices_Constants.h"

using namespace constants;




MasterOptions::MasterOptions() :
	masterOptionsTree{ ID::master_Options }
{
	fillMasterOptionsTreeWithProperties();
}

void MasterOptions::fillMasterOptionsTreeWithProperties() {
	masterOptionsTree.setProperty(ID::master_BasicChannel, (uint8)1, nullptr);
	masterOptionsTree.setProperty(ID::master_OmniModeEnabled, (uint8)0, nullptr);
	masterOptionsTree.setProperty(ID::master_ControllersEnabled, (uint8)1, nullptr);
	masterOptionsTree.setProperty(ID::master_VoiceChangesEnabled, (uint8)1, nullptr);
	masterOptionsTree.setProperty(ID::master_SysExEnabled, (uint8)0, nullptr);
	masterOptionsTree.setProperty(ID::master_LocalControlEnabled, (uint8)1, nullptr);
	masterOptionsTree.setProperty(ID::master_Pedal1ControllerNumber, (uint8)4, nullptr);
	masterOptionsTree.setProperty(ID::master_Pedal2ControllerNumber, (uint8)64, nullptr);
	masterOptionsTree.setProperty(ID::master_Lever2ControllerNumber, (uint8)1, nullptr);
	masterOptionsTree.setProperty(ID::master_Lever3ControllerNumber, (uint8)2, nullptr);
	masterOptionsTree.setProperty(ID::master_SpilloverEnabled, (uint8)0, nullptr);
	masterOptionsTree.setProperty(ID::master_MIDIechoEnabled, (uint8)0, nullptr);
	masterOptionsTree.setProperty(ID::master_MIDImonoEnabled, (uint8)0, nullptr);
	masterOptionsTree.setProperty(ID::master_VibratoSpeed, (uint8)30, nullptr);
	masterOptionsTree.setProperty(ID::master_VibratoWaveType, (uint8)0, nullptr);
	masterOptionsTree.setProperty(ID::master_VibratoAmplitude, (uint8)0, nullptr);
	masterOptionsTree.setProperty(ID::master_VibratoSpeedModSource, (uint8)0, nullptr);
	masterOptionsTree.setProperty(ID::master_VibratoSpeedModAmount, (uint8)0, nullptr);
	masterOptionsTree.setProperty(ID::master_VibratoAmplitudeModSource, (uint8)1, nullptr);
	masterOptionsTree.setProperty(ID::master_VibratoAmplitudeModAmount, (uint8)63, nullptr);
	masterOptionsTree.setProperty(ID::master_Tune, (uint8)63, nullptr);
	masterOptionsTree.setProperty(ID::master_SplitStereoEnabled, (uint8)0, nullptr);
	masterOptionsTree.setProperty(ID::master_VoicesMapEnabled, (uint8)0, nullptr);
	masterOptionsTree.setProperty(ID::master_VoicesMapEchoEnabled, (uint8)0, nullptr);
	masterOptionsTree.setProperty(ID::master_DisplayBrightness, (uint8)27, nullptr);
	masterOptionsTree.setProperty(ID::master_SQUICKenabled, (uint8)0, nullptr);
	resetVoicesMap();
}

void MasterOptions::resetMasterOptionsToDefaults() {
	fillMasterOptionsTreeWithProperties();
}

void MasterOptions::addListener(ValueTree::Listener* listener) {
	masterOptionsTree.addListener(listener);
}

void MasterOptions::removeListener(ValueTree::Listener* listener) {
	masterOptionsTree.removeListener(listener);
}

const uint8 MasterOptions::basicChannel() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_BasicChannel);
}

void MasterOptions::setBasicChannel(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_BasicChannel, newValue, nullptr);
}

const uint8 MasterOptions::omniModeEnabled() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_OmniModeEnabled);
}

void MasterOptions::setOmniModeEnabled(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_OmniModeEnabled, newValue, nullptr);
}

const uint8 MasterOptions::controllersEnabled() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_ControllersEnabled);
}

void MasterOptions::setControllersEnabled(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_ControllersEnabled, newValue, nullptr);
}

const uint8 MasterOptions::voiceChangesEnabled() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_VoiceChangesEnabled);
}

void MasterOptions::setVoiceChangesEnabled(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_VoiceChangesEnabled, newValue, nullptr);
}

const uint8 MasterOptions::sysExEnabled() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_SysExEnabled);
}

void MasterOptions::setSysExEnabled(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_SysExEnabled, newValue, nullptr);
}

const uint8 MasterOptions::spilloverEnabled() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_SpilloverEnabled);
}

void MasterOptions::setSpilloverEnabled(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_SpilloverEnabled, newValue, nullptr);
}

const uint8 MasterOptions::midiEchoEnabled() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_MIDIechoEnabled);
}

void MasterOptions::setMIDIechoEnabled(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_MIDIechoEnabled, newValue, nullptr);
}

const uint8 MasterOptions::midiMonoEnabled() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_MIDImonoEnabled);
}

void MasterOptions::setMIDImonoEnabled(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_MIDImonoEnabled, newValue, nullptr);
}

const uint8 MasterOptions::activeSensingEnabled() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_ActiveSensingEnabled);
}

void MasterOptions::setActiveSensingEnabled(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_ActiveSensingEnabled, newValue, nullptr);
}

const uint8 MasterOptions::localControlEnabled() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_LocalControlEnabled);
}

void MasterOptions::setLocalControlEnabled(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_LocalControlEnabled, newValue, nullptr);
}

const uint8 MasterOptions::pedal1ControllerNumber() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_Pedal1ControllerNumber);
}

void MasterOptions::setPedal1ControllerNumber(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_Pedal1ControllerNumber, newValue, nullptr);
}

const uint8 MasterOptions::pedal2ControllerNumber() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_Pedal2ControllerNumber);
}

void MasterOptions::setPedal2ControllerNumber(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_Pedal2ControllerNumber, newValue, nullptr);
}

const uint8 MasterOptions::lever2ControllerNumber() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_Lever2ControllerNumber);
}

void MasterOptions::setLever2ControllerNumber(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_Lever2ControllerNumber, newValue, nullptr);
}

const uint8 MasterOptions::lever3ControllerNumber() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_Lever3ControllerNumber);
}

void MasterOptions::setLever3ControllerNumber(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_Lever3ControllerNumber, newValue, nullptr);
}

const uint8 MasterOptions::vibratoSpeed() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_VibratoSpeed);
}

void MasterOptions::setVibratoSpeed(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_VibratoSpeed, newValue, nullptr);
}

const uint8 MasterOptions::vibratoWaveType() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_VibratoWaveType);
}

void MasterOptions::setVibratoWaveType(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_VibratoWaveType, newValue, nullptr);
}

const uint8 MasterOptions::vibratoAmplitude() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_VibratoAmplitude);
}

void MasterOptions::setVibratoAmplitude(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_VibratoAmplitude, newValue, nullptr);
}

const uint8 MasterOptions::vibratoSpeedModSource() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_VibratoSpeedModSource);
}

void MasterOptions::setVibratoSpeedModSource(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_VibratoSpeedModSource, newValue, nullptr);
}

const uint8 MasterOptions::vibratoSpeedModAmount() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_VibratoSpeedModAmount);
}

void MasterOptions::setVibratoSpeedModAmount(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_VibratoSpeedModAmount, newValue, nullptr);
}

const uint8 MasterOptions::vibratoAmplitudeModSource() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_VibratoAmplitudeModSource);
}

void MasterOptions::setVibratoAmplitudeModSource(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_VibratoAmplitudeModSource, newValue, nullptr);
}

const uint8 MasterOptions::vibratoAmplitudeModAmount() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_VibratoAmplitudeModAmount);
}

void MasterOptions::setVibratoAmplitudeModAmount(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_VibratoAmplitudeModAmount, newValue, nullptr);
}

const uint8 MasterOptions::masterTune() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_Tune);
}

void MasterOptions::setMasterTune(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_Tune, newValue, nullptr);
}

const uint8 MasterOptions::splitStereoEnabled() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_SplitStereoEnabled);
}

void MasterOptions::setSplitStereoEnabled(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_SplitStereoEnabled, newValue, nullptr);
}

const uint8 MasterOptions::voicesMapEnabled() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_VoicesMapEnabled);
}

void MasterOptions::setVoicesMapEnabled(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_VoicesMapEnabled, newValue, nullptr);
}

const uint8 MasterOptions::voicesMapEchoEnabled() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_VoicesMapEchoEnabled);
}

void MasterOptions::setVoicesMapEchoEnabled(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_VoicesMapEchoEnabled, newValue, nullptr);
}

const uint8 MasterOptions::displayBrightness() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_DisplayBrightness);
}

void MasterOptions::setDisplayBrightness(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_DisplayBrightness, newValue, nullptr);
}

const uint8 MasterOptions::squickEnabled() {
	return (uint8)(int)masterOptionsTree.getProperty(ID::master_SQUICKenabled);
}

void MasterOptions::setSQUICKenabled(uint8 newValue) {
	masterOptionsTree.setProperty(ID::master_SQUICKenabled, newValue, nullptr);
}

const uint8 MasterOptions::voicesMapInVoiceForProgramNumber(uint8 programNumber) {
	return (uint8)(int)masterOptionsTree.getProperty("master_VoicesMapIn_" + (String)programNumber);
}

void MasterOptions::setVoicesMapInVoiceForProgramNumber(uint8 newValue, uint8 programNumber) {
	masterOptionsTree.setProperty("master_VoicesMapIn_" + (String)programNumber, newValue, nullptr);
}

const uint8 MasterOptions::voicesMapOutVoiceForProgramNumber(uint8 programNumber) {
	return (uint8)(int)masterOptionsTree.getProperty("master_VoicesMapOut_" + (String)programNumber);
}

void MasterOptions::setVoicesMapOutVoiceForProgramNumber(uint8 newValue, uint8 programNumber) {
	masterOptionsTree.setProperty("master_VoicesMapOut_" + (String)programNumber, newValue, nullptr);
}

void MasterOptions::resetVoicesMap() {
	for (int i = 0; i != voices::numberOfSlotsInBank; ++i) {
		Identifier inPropertyID{ "master_VoicesMapIn_" + (String)i };
		masterOptionsTree.setProperty(inPropertyID, (uint8)i, nullptr);
		Identifier outPropertyID{ "master_VoicesMapOut_" + (String)i };
		masterOptionsTree.setProperty(outPropertyID, (uint8)i, nullptr);
	}
}
