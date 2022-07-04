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
    setPedalModeIsArpLatch(false);
    setVoiceChangesAreEnabled(false);
    setParamChangeSendType(ParamChangeSendType::nrpn);
    setParamChangeReceiveType(ParamChangeReceiveType::all);
    setControllersAreEnabled(true);
    setSysExIsEnabled(false);
    setHardwareOutputIsMono(false);
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
    return (bool)globalOptionsTree.getProperty(ID::global_PedalModeIsArpLatch) == true;
}

void GlobalOptions::setPedalModeIsArpLatch(bool shouldBeArpLatch) {
    globalOptionsTree.setProperty(ID::global_PedalModeIsArpLatch, shouldBeArpLatch ? (bool)true : (bool)false, nullptr);
}

const bool GlobalOptions::voiceChangesAreEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_VoiceChangesAreEnabled) == true;
}

void GlobalOptions::setVoiceChangesAreEnabled(bool shouldBeEnabled) {
    globalOptionsTree.setProperty(ID::global_VoiceChangesAreEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
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
    return (bool)globalOptionsTree.getProperty(ID::global_ControllersAreEnabled) == true;
}

void GlobalOptions::setControllersAreEnabled(bool shouldBeEnabled) {
    globalOptionsTree.setProperty(ID::global_ControllersAreEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
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
    return (bool)globalOptionsTree.getProperty(ID::global_SysExIsEnabled) == true;
}

void GlobalOptions::setSysExIsEnabled(bool shouldBeEnabled) {
    globalOptionsTree.setProperty(ID::global_SysExIsEnabled, shouldBeEnabled ? true : false, nullptr);
}

bool GlobalOptions::hardwareOutputIsMono() {
    return (bool)globalOptionsTree.getProperty(ID::global_HardwareOutputIsMono) == true;
}

void GlobalOptions::setHardwareOutputIsMono(bool shouldBeMono) {
    globalOptionsTree.setProperty(ID::global_HardwareOutputIsMono, shouldBeMono ? true : false, nullptr);
}

const uint8 GlobalOptions::hardwareOutputBalance() {
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_HardwareOutputBalance);
}

void GlobalOptions::setHardwareOutputBalance(uint8 newBalance) {
    globalOptionsTree.setProperty(ID::global_HardwareOutputBalance, newBalance, nullptr);
}
