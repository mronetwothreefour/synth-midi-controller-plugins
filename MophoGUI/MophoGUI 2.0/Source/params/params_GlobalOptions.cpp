#include "params_GlobalOptions.h"

#include "params_Identifiers.h"
#include "../global/global_ParameterReceiveType.h"



GlobalOptions::GlobalOptions() :
	globalOptionsTree{ ID::global_Options }
{
	fillGlobalOptionsTreeWithProperties();
}

void GlobalOptions::fillGlobalOptionsTreeWithProperties() {
	globalOptionsTree.setProperty(ID::global_Transpose, (uint8)12, nullptr);
	globalOptionsTree.setProperty(ID::global_FineTune, (uint8)50, nullptr);
	globalOptionsTree.setProperty(ID::global_TransmitChannel, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_HardwareReceiveChannel, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_Clock, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_PedalModeArpLatch, (bool)false, nullptr);
	globalOptionsTree.setProperty(ID::global_VoiceChangeOn, (bool)false, nullptr);
	globalOptionsTree.setProperty(ID::global_ParameterSendType, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_ParameterReceiveType, (uint8)0, nullptr);
	globalOptionsTree.setProperty(ID::global_ControllersOn, (bool)true, nullptr);
	globalOptionsTree.setProperty(ID::global_SysExOn, (bool)false, nullptr);
	globalOptionsTree.setProperty(ID::global_HardwareOutputIsStereo, (bool)true, nullptr);
	globalOptionsTree.setProperty(ID::global_Balance, (uint8)7, nullptr);
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

const uint8 GlobalOptions::globalTranspose() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_Transpose);
}

void GlobalOptions::setGlobalTranspose(uint8 newTransposition) {
	globalOptionsTree.setProperty(ID::global_Transpose, newTransposition, nullptr);
}

const uint8 GlobalOptions::globalFineTune() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_FineTune);
}

void GlobalOptions::setGlobalFineTune(uint8 newFineTune) {
	globalOptionsTree.setProperty(ID::global_FineTune, newFineTune, nullptr);
}

const uint8 GlobalOptions::transmitChannel() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_TransmitChannel);
}

void GlobalOptions::setTransmitChannel(uint8 newChannel) {
	globalOptionsTree.setProperty(ID::global_TransmitChannel, newChannel, nullptr);
}

const uint8 GlobalOptions::hardwareReceiveChannel() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_HardwareReceiveChannel);
}

void GlobalOptions::setHardwareReceiveChannel(uint8 newChannel) {
	globalOptionsTree.setProperty(ID::global_HardwareReceiveChannel, newChannel, nullptr);
}

const uint8 GlobalOptions::clockType() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_Clock);
}

void GlobalOptions::setClockType(uint8 newType) {
	globalOptionsTree.setProperty(ID::global_Clock, newType, nullptr);
}

const bool GlobalOptions::pedalModeIsArpLatch() {
	return (bool)globalOptionsTree.getProperty(ID::global_PedalModeArpLatch);
}

void GlobalOptions::setPedalModeToArpLatch() {
	globalOptionsTree.setProperty(ID::global_PedalModeArpLatch, (bool)true, nullptr);
}

void GlobalOptions::setPedalModeToNormal() {
	globalOptionsTree.setProperty(ID::global_PedalModeArpLatch, (bool)false, nullptr);
}

const bool GlobalOptions::voiceChangeIsOn() {
	return (bool)globalOptionsTree.getProperty(ID::global_VoiceChangeOn);
}

void GlobalOptions::setVoiceChangeOn() {
	globalOptionsTree.setProperty(ID::global_VoiceChangeOn, (bool)true, nullptr);
}

void GlobalOptions::setVoiceChangeOff() {
	globalOptionsTree.setProperty(ID::global_VoiceChangeOn, (bool)false, nullptr);
}

const uint8 GlobalOptions::parameterSendType() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_ParameterSendType);
}

void GlobalOptions::setParameterSendType(uint8 newType) {
	globalOptionsTree.setProperty(ID::global_ParameterSendType, newType, nullptr);
}

const uint8 GlobalOptions::parameterReceiveType() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_ParameterReceiveType);
}

void GlobalOptions::setParameterReceiveType(uint8 newType) {
	globalOptionsTree.setProperty(ID::global_ParameterReceiveType, newType, nullptr);
}

const bool GlobalOptions::controllersAreOn() {
	return (bool)globalOptionsTree.getProperty(ID::global_ControllersOn);
}

const bool GlobalOptions::controllersAreOff() {
	return !(bool)globalOptionsTree.getProperty(ID::global_ControllersOn);
}

void GlobalOptions::setControllersOn() {
	globalOptionsTree.setProperty(ID::global_ControllersOn, (bool)true, nullptr);
}

void GlobalOptions::setControllersOff() {
	globalOptionsTree.setProperty(ID::global_ControllersOn, (bool)false, nullptr);
}

const bool GlobalOptions::hardwareIsSetToReceiveNRPNcontrollers() {
	auto receiveTypeIsAll{ parameterReceiveType() == (uint8)ParameterReceiveType::all };
	auto receiveTypeIsNRPN{ parameterReceiveType() == (uint8)ParameterReceiveType::nrpnOnly };
	auto nrpnReceiveIsOn{ receiveTypeIsAll || receiveTypeIsNRPN };
	return (nrpnReceiveIsOn && controllersAreOn());
}

const bool GlobalOptions::hardwareIsNotSetToReceiveNRPNcontrollers() {
	auto receiveTypeIsNotAll{ parameterReceiveType() != (uint8)ParameterReceiveType::all };
	auto receiveTypeIsNotNRPN{ parameterReceiveType() != (uint8)ParameterReceiveType::nrpnOnly };
	auto nrpnReceiveIsOff{ receiveTypeIsNotAll && receiveTypeIsNotNRPN };
	auto controllersAreOff{ !controllersAreOn() };
	return (nrpnReceiveIsOff || controllersAreOff);
}

const bool GlobalOptions::sysExIsOn() {
	return (bool)globalOptionsTree.getProperty(ID::global_SysExOn);
}

const bool GlobalOptions::sysExIsOff() {
	return !(bool)globalOptionsTree.getProperty(ID::global_SysExOn);
}

void GlobalOptions::setSysExOn() {
	globalOptionsTree.setProperty(ID::global_SysExOn, (bool)true, nullptr);
}

void GlobalOptions::setSysExOff() {
	globalOptionsTree.setProperty(ID::global_SysExOn, (bool)false, nullptr);
}

bool GlobalOptions::hardwareOutputIsStereo() {
	return (bool)globalOptionsTree.getProperty(ID::global_HardwareOutputIsStereo);
}

void GlobalOptions::setHardwareOutputStereo() {
	globalOptionsTree.setProperty(ID::global_HardwareOutputIsStereo, (bool)true, nullptr);
}

void GlobalOptions::setHardwareOutputMono() {
	globalOptionsTree.setProperty(ID::global_HardwareOutputIsStereo, (bool)false, nullptr);
}

const uint8 GlobalOptions::globalBalance() {
	return (uint8)(int)globalOptionsTree.getProperty(ID::global_Balance);
}

void GlobalOptions::setGlobalBalance(uint8 newBalance) {
	globalOptionsTree.setProperty(ID::global_Balance, newBalance, nullptr);
}

