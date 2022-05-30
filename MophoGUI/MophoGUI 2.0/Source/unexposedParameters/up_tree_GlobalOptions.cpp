#include "up_tree_GlobalOptions.h"

#include "../constants/constants_Identifiers.h"



GlobalOptions::GlobalOptions() :
    globalOptionsTree{ ID::global_Options }
{
    resetAllOptionsToDefaults();
}

void GlobalOptions::resetAllOptionsToDefaults() {
    setGlobalTranspose((uint8)12);
    setGlobalFineTune((uint8)50);
    setTransmitChannel((uint8)0);
    setHardwareReceiveChannel((uint8)0);
    setMIDI_ClockSource(MIDI_ClockSource::internalClock);
    setPedalModeToNormal();
    setVoiceChangeDisabled();
    setParamChangeSendType(ParamChangeSendType::nrpn);
    setParamChangeReceiveType(ParamChangeReceiveType::all);
    setControllersOn();
    setSysExOff();
    setHardwareOutputToStereo();
    setHardwareOutputBalance((uint8)7);
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

const MIDI_ClockSource GlobalOptions::midiClockSource() {
    auto currentValue{ (int)globalOptionsTree.getProperty(ID::global_MIDI_ClockSource) };
    auto clockSource{ (MIDI_ClockSource)currentValue };
    return clockSource;
}

void GlobalOptions::setMIDI_ClockSource(MIDI_ClockSource newSource) {
    globalOptionsTree.setProperty(ID::global_MIDI_ClockSource, (int)newSource, nullptr);
}

const bool GlobalOptions::pedalModeIsArpLatch() {
    return (bool)globalOptionsTree.getProperty(ID::global_PedalModeIsArpLatch);
}

void GlobalOptions::setPedalModeToArpLatch() {
    globalOptionsTree.setProperty(ID::global_PedalModeIsArpLatch, (bool)true, nullptr);
}

void GlobalOptions::setPedalModeToNormal() {
    globalOptionsTree.setProperty(ID::global_PedalModeIsArpLatch, (bool)false, nullptr);
}

const bool GlobalOptions::voiceChangeIsEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_VoiceChangeIsEnabled);
}

void GlobalOptions::setVoiceChangeEnabled() {
    globalOptionsTree.setProperty(ID::global_VoiceChangeIsEnabled, (bool)true, nullptr);
}

void GlobalOptions::setVoiceChangeDisabled() {
    globalOptionsTree.setProperty(ID::global_VoiceChangeIsEnabled, (bool)false, nullptr);
}

const ParamChangeSendType GlobalOptions::paramChangeSendType() {
    auto currentValue{ (int)globalOptionsTree.getProperty(ID::global_ParamChangeSendType) };
    auto sendType{ (ParamChangeSendType)currentValue };
    return sendType;
}

void GlobalOptions::setParamChangeSendType(ParamChangeSendType newSendType) {
    globalOptionsTree.setProperty(ID::global_ParamChangeSendType, (int)newSendType, nullptr);
}

const ParamChangeReceiveType GlobalOptions::paramChangeReceiveType() {
    auto currentValue{ (int)globalOptionsTree.getProperty(ID::global_ParamChangeReceiveType) };
    auto receiveType{ (ParamChangeReceiveType)currentValue };
    return receiveType;
}

void GlobalOptions::setParamChangeReceiveType(ParamChangeReceiveType newReceiveType) {
    globalOptionsTree.setProperty(ID::global_ParamChangeReceiveType, (int)newReceiveType, nullptr);
}

const bool GlobalOptions::controllersAreOn() {
    return (bool)globalOptionsTree.getProperty(ID::global_ControllersAreOn);
}

const bool GlobalOptions::controllersAreOff() {
    return !(bool)globalOptionsTree.getProperty(ID::global_ControllersAreOn);
}

void GlobalOptions::setControllersOn() {
    globalOptionsTree.setProperty(ID::global_ControllersAreOn, (bool)true, nullptr);
}

void GlobalOptions::setControllersOff() {
    globalOptionsTree.setProperty(ID::global_ControllersAreOn, (bool)false, nullptr);
}

const bool GlobalOptions::hardwareIsSetToReceiveNRPNcontrollers() {
    auto receiveTypeIsAll{ paramChangeReceiveType() == ParamChangeReceiveType::all };
    auto receiveTypeIsNRPN{ paramChangeReceiveType() == ParamChangeReceiveType::nrpnOnly };
    auto nrpnReceiveIsOn{ receiveTypeIsAll || receiveTypeIsNRPN };
    return (nrpnReceiveIsOn && controllersAreOn());
}

const bool GlobalOptions::hardwareIsNotSetToReceiveNRPNcontrollers() {
    return !hardwareIsSetToReceiveNRPNcontrollers();
}

const bool GlobalOptions::sysExIsOn() {
    return (bool)globalOptionsTree.getProperty(ID::global_SysExIsOn);
}

const bool GlobalOptions::sysExIsOff() {
    return !(bool)globalOptionsTree.getProperty(ID::global_SysExIsOn);
}

void GlobalOptions::setSysExOn() {
    globalOptionsTree.setProperty(ID::global_SysExIsOn, (bool)true, nullptr);
}

void GlobalOptions::setSysExOff() {
    globalOptionsTree.setProperty(ID::global_SysExIsOn, (bool)false, nullptr);
}

bool GlobalOptions::hardwareOutputIsStereo() {
    return (bool)globalOptionsTree.getProperty(ID::global_HardwareOutputIsStereo);
}

void GlobalOptions::setHardwareOutputToStereo() {
    globalOptionsTree.setProperty(ID::global_HardwareOutputIsStereo, (bool)true, nullptr);
}

void GlobalOptions::setHardwareOutputToMono() {
    globalOptionsTree.setProperty(ID::global_HardwareOutputIsStereo, (bool)false, nullptr);
}

const uint8 GlobalOptions::hardwareOutputBalance() {
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_HardwareOutputBalance);
}

void GlobalOptions::setHardwareOutputBalance(uint8 newBalance) {
    globalOptionsTree.setProperty(ID::global_HardwareOutputBalance, newBalance, nullptr);
}
