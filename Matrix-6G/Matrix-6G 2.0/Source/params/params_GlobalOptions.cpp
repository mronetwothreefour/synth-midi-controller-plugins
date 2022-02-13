#include "params_GlobalOptions.h"

#include "params_Identifiers.h"
#include "../master/master_Constants.h"
#include "../voices/voices_Constants.h"

using namespace constants;




GlobalOptions::GlobalOptions() :
	globalOptionsTree{ ID::global_Options }
{
	fillGlobalOptionsTreeWithProperties();
}

void GlobalOptions::fillGlobalOptionsTreeWithProperties() {
	globalOptionsTree.setProperty(ID::global_BasicChannel, (uint8)1, nullptr);
	globalOptionsTree.setProperty(ID::global_OmniModeEnabled, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_ControllersEnabled, (uint8)1, nullptr);
	globalOptionsTree.setProperty(ID::global_VoiceChangesEnabled, (uint8)1, nullptr);
	globalOptionsTree.setProperty(ID::global_SysExEnabled, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_LocalControlEnabled, (uint8)1, nullptr);
	globalOptionsTree.setProperty(ID::global_Pedal1ControllerNumber, (uint8)4, nullptr);
	globalOptionsTree.setProperty(ID::global_Pedal2ControllerNumber, (uint8)64, nullptr);
	globalOptionsTree.setProperty(ID::global_Lever2ControllerNumber, (uint8)1, nullptr);
	globalOptionsTree.setProperty(ID::global_Lever3ControllerNumber, (uint8)2, nullptr);
	globalOptionsTree.setProperty(ID::global_SpilloverEnabled, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_MIDIechoEnabled, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_MIDImonoEnabled, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_VibratoSpeed, (uint8)30, nullptr);
	globalOptionsTree.setProperty(ID::global_VibratoWaveType, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_VibratoAmplitude, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_VibratoSpeedModSource, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_VibratoSpeedModAmount, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_VibratoAmplitudeModSource, (uint8)1, nullptr);
	globalOptionsTree.setProperty(ID::global_VibratoAmplitudeModAmount, (uint8)63, nullptr);
	globalOptionsTree.setProperty(ID::global_Tune, (uint8)63, nullptr);
	globalOptionsTree.setProperty(ID::global_SplitStereoEnabled, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_VoicesMapEnabled, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_VoicesMapEchoEnabled, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_DisplayBrightness, (uint8)27, nullptr);
	globalOptionsTree.setProperty(ID::global_SQUICKenabled, (uint8)0, nullptr);
	resetVoicesMap();
}

void GlobalOptions::resetAllOptionsToDefaults() {
	fillGlobalOptionsTreeWithProperties();
}

void GlobalOptions::addListener(ValueTree::Listener* listener) {
	globalOptionsTree.addListener(listener);
}

void GlobalOptions::removeListener(ValueTree::Listener* listener) {
	globalOptionsTree.removeListener(listener);
}

const uint8 GlobalOptions::basicChannel() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_BasicChannel);
}

void GlobalOptions::setBasicChannel(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_BasicChannel, newValue, nullptr);
}

const uint8 GlobalOptions::omniModeEnabled() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_OmniModeEnabled);
}

void GlobalOptions::setOmniModeEnabled(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_OmniModeEnabled, newValue, nullptr);
}

const uint8 GlobalOptions::controllersEnabled() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_ControllersEnabled);
}

void GlobalOptions::setControllersEnabled(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_ControllersEnabled, newValue, nullptr);
}

const uint8 GlobalOptions::voiceChangesEnabled() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_VoiceChangesEnabled);
}

void GlobalOptions::setVoiceChangesEnabled(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_VoiceChangesEnabled, newValue, nullptr);
}

const uint8 GlobalOptions::sysExEnabled() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_SysExEnabled);
}

void GlobalOptions::setSysExEnabled(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_SysExEnabled, newValue, nullptr);
}

const uint8 GlobalOptions::spilloverEnabled() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_SpilloverEnabled);
}

void GlobalOptions::setSpilloverEnabled(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_SpilloverEnabled, newValue, nullptr);
}

const uint8 GlobalOptions::midiEchoEnabled() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_MIDIechoEnabled);
}

void GlobalOptions::setMIDIechoEnabled(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_MIDIechoEnabled, newValue, nullptr);
}

const uint8 GlobalOptions::midiMonoEnabled() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_MIDImonoEnabled);
}

void GlobalOptions::setMIDImonoEnabled(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_MIDImonoEnabled, newValue, nullptr);
}

const uint8 GlobalOptions::activeSensingEnabled() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_ActiveSensingEnabled);
}

void GlobalOptions::setActiveSensingEnabled(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_ActiveSensingEnabled, newValue, nullptr);
}

const uint8 GlobalOptions::localControlEnabled() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_LocalControlEnabled);
}

void GlobalOptions::setLocalControlEnabled(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_LocalControlEnabled, newValue, nullptr);
}

const uint8 GlobalOptions::pedal1ControllerNumber() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_Pedal1ControllerNumber);
}

void GlobalOptions::setPedal1ControllerNumber(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_Pedal1ControllerNumber, newValue, nullptr);
}

const uint8 GlobalOptions::pedal2ControllerNumber() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_Pedal2ControllerNumber);
}

void GlobalOptions::setPedal2ControllerNumber(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_Pedal2ControllerNumber, newValue, nullptr);
}

const uint8 GlobalOptions::lever2ControllerNumber() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_Lever2ControllerNumber);
}

void GlobalOptions::setLever2ControllerNumber(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_Lever2ControllerNumber, newValue, nullptr);
}

const uint8 GlobalOptions::lever3ControllerNumber() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_Lever3ControllerNumber);
}

void GlobalOptions::setLever3ControllerNumber(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_Lever3ControllerNumber, newValue, nullptr);
}

const uint8 GlobalOptions::vibratoSpeed() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_VibratoSpeed);
}

void GlobalOptions::setVibratoSpeed(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_VibratoSpeed, newValue, nullptr);
}

const uint8 GlobalOptions::vibratoWaveType() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_VibratoWaveType);
}

void GlobalOptions::setVibratoWaveType(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_VibratoWaveType, newValue, nullptr);
}

const uint8 GlobalOptions::vibratoAmplitude() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_VibratoAmplitude);
}

void GlobalOptions::setVibratoAmplitude(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_VibratoAmplitude, newValue, nullptr);
}

const uint8 GlobalOptions::vibratoSpeedModSource() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_VibratoSpeedModSource);
}

void GlobalOptions::setVibratoSpeedModSource(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_VibratoSpeedModSource, newValue, nullptr);
}

const uint8 GlobalOptions::vibratoSpeedModAmount() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_VibratoSpeedModAmount);
}

void GlobalOptions::setVibratoSpeedModAmount(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_VibratoSpeedModAmount, newValue, nullptr);
}

const uint8 GlobalOptions::vibratoAmplitudeModSource() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_VibratoAmplitudeModSource);
}

void GlobalOptions::setVibratoAmplitudeModSource(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_VibratoAmplitudeModSource, newValue, nullptr);
}

const uint8 GlobalOptions::vibratoAmplitudeModAmount() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_VibratoAmplitudeModAmount);
}

void GlobalOptions::setVibratoAmplitudeModAmount(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_VibratoAmplitudeModAmount, newValue, nullptr);
}

const uint8 GlobalOptions::globalTune() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_Tune);
}

void GlobalOptions::setGlobalTune(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_Tune, newValue, nullptr);
}

const uint8 GlobalOptions::splitStereoEnabled() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_SplitStereoEnabled);
}

void GlobalOptions::setSplitStereoEnabled(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_SplitStereoEnabled, newValue, nullptr);
}

const uint8 GlobalOptions::voicesMapEnabled() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_VoicesMapEnabled);
}

void GlobalOptions::setVoicesMapEnabled(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_VoicesMapEnabled, newValue, nullptr);
}

const uint8 GlobalOptions::voicesMapEchoEnabled() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_VoicesMapEchoEnabled);
}

void GlobalOptions::setVoicesMapEchoEnabled(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_VoicesMapEchoEnabled, newValue, nullptr);
}

const uint8 GlobalOptions::displayBrightness() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_DisplayBrightness);
}

void GlobalOptions::setDisplayBrightness(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_DisplayBrightness, newValue, nullptr);
}

const uint8 GlobalOptions::squickEnabled() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_SQUICKenabled);
}

void GlobalOptions::setSQUICKenabled(uint8 newValue) {
	globalOptionsTree.setProperty(ID::global_SQUICKenabled, newValue, nullptr);
}

const uint8 GlobalOptions::voicesMapInVoiceForProgramNumber(uint8 programNumber) {
	return (uint8)(int)globalOptionsTree.getProperty("global_VoicesMapIn_" + (String)programNumber);
}

void GlobalOptions::setVoicesMapInVoiceForProgramNumber(uint8 newValue, uint8 programNumber) {
	globalOptionsTree.setProperty("global_VoicesMapIn_" + (String)programNumber, newValue, nullptr);
}

const uint8 GlobalOptions::voicesMapOutVoiceForProgramNumber(uint8 programNumber) {
	return (uint8)(int)globalOptionsTree.getProperty("global_VoicesMapOut_" + (String)programNumber);
}

void GlobalOptions::setVoicesMapOutVoiceForProgramNumber(uint8 newValue, uint8 programNumber) {
	globalOptionsTree.setProperty("global_VoicesMapOut_" + (String)programNumber, newValue, nullptr);
}

void GlobalOptions::resetVoicesMap() {
	for (int i = 0; i != voices::numberOfSlotsInBank; ++i) {
		Identifier inPropertyID{ "global_VoicesMapIn_" + (String)i };
		globalOptionsTree.setProperty(inPropertyID, (uint8)i, nullptr);
		Identifier outPropertyID{ "global_VoicesMapOut_" + (String)i };
		globalOptionsTree.setProperty(outPropertyID, (uint8)i, nullptr);
	}
}
