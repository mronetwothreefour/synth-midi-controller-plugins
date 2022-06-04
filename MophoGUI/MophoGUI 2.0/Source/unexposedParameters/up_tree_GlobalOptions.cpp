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
    setVoiceChangesAreDisabled();
    setParamChangeSendType(ParamChangeSendType::nrpn);
    setParamChangeReceiveType(ParamChangeReceiveType::all);
    setControllersAreEnabled();
    setSysExIsDisabled();
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
    return (bool)globalOptionsTree.getProperty(ID::global_PedalMode) == arpLatchPedalMode;
}

void GlobalOptions::setPedalModeToArpLatch() {
    globalOptionsTree.setProperty(ID::global_PedalMode, arpLatchPedalMode, nullptr);
}

void GlobalOptions::setPedalModeToNormal() {
    globalOptionsTree.setProperty(ID::global_PedalMode, normalPedalMode, nullptr);
}

const bool GlobalOptions::voiceChangesAreEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_VoiceChanges) == enabled;
}

void GlobalOptions::setVoiceChangesAreEnabled() {
    globalOptionsTree.setProperty(ID::global_VoiceChanges, enabled, nullptr);
}

void GlobalOptions::setVoiceChangesAreDisabled() {
    globalOptionsTree.setProperty(ID::global_VoiceChanges, disabled, nullptr);
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

const bool GlobalOptions::controllersAreEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_Controllers) == enabled;
}

const bool GlobalOptions::controllersAreDisabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_Controllers) == disabled;
}

void GlobalOptions::setControllersAreEnabled() {
    globalOptionsTree.setProperty(ID::global_Controllers, enabled, nullptr);
}

void GlobalOptions::setControllersAreDisabled() {
    globalOptionsTree.setProperty(ID::global_Controllers, disabled, nullptr);
}

const bool GlobalOptions::hardwareIsSetToReceiveNRPNcontrollers() {
    auto receiveTypeIsAll{ paramChangeReceiveType() == ParamChangeReceiveType::all };
    auto receiveTypeIsNRPN{ paramChangeReceiveType() == ParamChangeReceiveType::nrpnOnly };
    auto nrpnReceiveIsOn{ receiveTypeIsAll || receiveTypeIsNRPN };
    return (nrpnReceiveIsOn && controllersAreEnabled());
}

const bool GlobalOptions::hardwareIsNotSetToReceiveNRPNcontrollers() {
    return hardwareIsSetToReceiveNRPNcontrollers() == false;
}

const bool GlobalOptions::sysExIsEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_SysEx) == enabled;
}

const bool GlobalOptions::sysExIsDisabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_SysEx) == disabled;
}

void GlobalOptions::setSysExIsEnabled() {
    globalOptionsTree.setProperty(ID::global_SysEx, enabled, nullptr);
}

void GlobalOptions::setSysExIsDisabled() {
    globalOptionsTree.setProperty(ID::global_SysEx, disabled, nullptr);
}

bool GlobalOptions::hardwareOutputIsStereo() {
    return (bool)globalOptionsTree.getProperty(ID::global_HardwareOutput) == stereo;
}

void GlobalOptions::setHardwareOutputToStereo() {
    globalOptionsTree.setProperty(ID::global_HardwareOutput, stereo, nullptr);
}

void GlobalOptions::setHardwareOutputToMono() {
    globalOptionsTree.setProperty(ID::global_HardwareOutput, mono, nullptr);
}

const uint8 GlobalOptions::hardwareOutputBalance() {
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_HardwareOutputBalance);
}

void GlobalOptions::setHardwareOutputBalance(uint8 newBalance) {
    globalOptionsTree.setProperty(ID::global_HardwareOutputBalance, newBalance, nullptr);
}
