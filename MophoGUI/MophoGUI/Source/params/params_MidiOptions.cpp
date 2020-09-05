#include "params_MidiOptions.h"

#include "params_Identifiers.h"
#include "../global/global_ParameterReceiveType.h"



MidiOptions::MidiOptions() :
	midiOptionsTree{ ID::midi_Options }
{
	fillMidiOptionsTreeWithProperties();
}

void MidiOptions::fillMidiOptionsTreeWithProperties() {
	midiOptionsTree.setProperty(ID::midi_Clock, (uint8)0, nullptr);
	midiOptionsTree.setProperty(ID::midi_ControllersOn, (bool)true, nullptr);
	midiOptionsTree.setProperty(ID::midi_HardwareReceiveChannel, (uint8)0, nullptr);
	midiOptionsTree.setProperty(ID::midi_PedalModeArpLatch, (bool)false, nullptr);
	midiOptionsTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)false, nullptr);
	midiOptionsTree.setProperty(ID::midi_ParameterReceiveType, (uint8)0, nullptr);
	midiOptionsTree.setProperty(ID::midi_ParameterSendType, (uint8)0, nullptr);
	midiOptionsTree.setProperty(ID::midi_ProgramTransmitTime, 300, nullptr);
	midiOptionsTree.setProperty(ID::midi_ProgramChangeOn, (bool)false, nullptr);
	midiOptionsTree.setProperty(ID::midi_SysExOn, (bool)false, nullptr);
	midiOptionsTree.setProperty(ID::midi_TransmitChannel, (uint8)0, nullptr);
}

void MidiOptions::resetMidiOptionsToDefaults() {
	fillMidiOptionsTreeWithProperties();
}

void MidiOptions::addListener(ValueTree::Listener* listener) {
	midiOptionsTree.addListener(listener);
}

void MidiOptions::removeListener(ValueTree::Listener* listener) {
	midiOptionsTree.removeListener(listener);
}

uint8 MidiOptions::transmitChannel() {
	return (uint8)(int)midiOptionsTree.getProperty(ID::midi_TransmitChannel);
}

void MidiOptions::setTransmitChannel(uint8 newChannel) {
	midiOptionsTree.setProperty(ID::midi_TransmitChannel, newChannel, nullptr);
}

uint8 MidiOptions::hardwareReceiveChannel() {
	return (uint8)(int)midiOptionsTree.getProperty(ID::midi_HardwareReceiveChannel);
}

void MidiOptions::setHardwareReceiveChannel(uint8 newChannel) {
	midiOptionsTree.setProperty(ID::midi_HardwareReceiveChannel, newChannel, nullptr);
}

uint8 MidiOptions::clockType() {
	return (uint8)(int)midiOptionsTree.getProperty(ID::midi_Clock);
}

void MidiOptions::setClockType(uint8 newType) {
	midiOptionsTree.setProperty(ID::midi_Clock, newType, nullptr);
}

uint8 MidiOptions::parameterSendType() {
	return (uint8)(int)midiOptionsTree.getProperty(ID::midi_ParameterSendType);
}

void MidiOptions::setParameterSendType(uint8 newType) {
	midiOptionsTree.setProperty(ID::midi_ParameterSendType, newType, nullptr);
}

uint8 MidiOptions::parameterReceiveType() {
	return (uint8)(int)midiOptionsTree.getProperty(ID::midi_ParameterReceiveType);
}

void MidiOptions::setParameterReceiveType(uint8 newType) {
	midiOptionsTree.setProperty(ID::midi_ParameterReceiveType, newType, nullptr);
}

bool MidiOptions::controllersAreOn() {
	return (bool)midiOptionsTree.getProperty(ID::midi_ControllersOn);
}

void MidiOptions::setControllersOn() {
	midiOptionsTree.setProperty(ID::midi_ControllersOn, (bool)true, nullptr);
}

void MidiOptions::setControllersOff() {
	midiOptionsTree.setProperty(ID::midi_ControllersOn, (bool)false, nullptr);
}

bool MidiOptions::hardwareIsSetToReceiveNRPNcontrollers() {
	auto receiveTypeIsAll{ parameterReceiveType() == (uint8)ParameterReceiveType::all };
	auto receiveTypeIsNRPN{ parameterReceiveType() == (uint8)ParameterReceiveType::nrpnOnly };
	auto nrpnReceiveIsOn{ receiveTypeIsAll || receiveTypeIsNRPN };
	return (nrpnReceiveIsOn && controllersAreOn());
}

bool MidiOptions::hardwareIsNotSetToReceiveNRPNcontrollers() {
	auto receiveTypeIsNotAll{ parameterReceiveType() != (uint8)ParameterReceiveType::all };
	auto receiveTypeIsNotNRPN{ parameterReceiveType() != (uint8)ParameterReceiveType::nrpnOnly };
	auto nrpnReceiveIsOff{ receiveTypeIsNotAll && receiveTypeIsNotNRPN };
	auto controllersAreOff{ !controllersAreOn() };
	return (nrpnReceiveIsOff || controllersAreOff);
}

bool MidiOptions::sysExIsOn() {
	return (bool)midiOptionsTree.getProperty(ID::midi_SysExOn);
}

void MidiOptions::setSysExOn() {
	midiOptionsTree.setProperty(ID::midi_SysExOn, (bool)true, nullptr);
}

void MidiOptions::setSysExOff() {
	midiOptionsTree.setProperty(ID::midi_SysExOn, (bool)false, nullptr);
}

bool MidiOptions::pedalModeIsArpLatch() {
	return (bool)midiOptionsTree.getProperty(ID::midi_PedalModeArpLatch);
}

void MidiOptions::setPedalModeToArpLatch() {
	midiOptionsTree.setProperty(ID::midi_PedalModeArpLatch, (bool)true, nullptr);
}

void MidiOptions::setPedalModeToNormal() {
	midiOptionsTree.setProperty(ID::midi_PedalModeArpLatch, (bool)false, nullptr);
}

bool MidiOptions::programChangeIsOn() {
	return (bool)midiOptionsTree.getProperty(ID::midi_ProgramChangeOn);
}

void MidiOptions::setProgramChangeOn() {
	midiOptionsTree.setProperty(ID::midi_ProgramChangeOn, (bool)true, nullptr);
}

void MidiOptions::setProgramChangeOff() {
	midiOptionsTree.setProperty(ID::midi_ProgramChangeOn, (bool)false, nullptr);
}

bool MidiOptions::paramChangeEchosAreNotBlocked() {
	return !(bool)midiOptionsTree.getProperty(ID::midi_ParamChangeEchosAreBlocked);
}

void MidiOptions::setParamChangeEchosAreBlocked() {
	midiOptionsTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)true, nullptr);
}

void MidiOptions::setParamChangeEchosAreNotBlocked() {
	midiOptionsTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)false, nullptr);
}

int MidiOptions::programTransmitTime() {
	return (int)midiOptionsTree.getProperty(ID::midi_ProgramTransmitTime);
}

void MidiOptions::setProgramTransmitTime(int timeInMilliseconds) {
	midiOptionsTree.setProperty(ID::midi_ProgramTransmitTime, timeInMilliseconds, nullptr);
}

MidiOptions::~MidiOptions() {
}
