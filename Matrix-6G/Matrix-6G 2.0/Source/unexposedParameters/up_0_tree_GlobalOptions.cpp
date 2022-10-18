#include "up_0_tree_GlobalOptions.h"

#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"

GlobalOptions::GlobalOptions() :
    globalOptionsTree{ ID::tree_GlobalOptions }
{
    resetAllOptionsToDefaults();
}

void GlobalOptions::resetAllOptionsToDefaults() {
    setBasicChannel((uint8)1);
    setOmniModeIsEnabled(false);
    setControllersAreEnabled(true);
    setVoiceChangesAreEnabled(true);
    setSysExIsEnabled(false);
    setSpilloverIsEnabled(false);
    set_MIDI_EchoIsEnabled(false);
    set_MIDI_MonoIsEnabled(false);
    setActiveSensingIsEnabled(false);
    setLocalControIsEnabled(true);
    setPedal_1_ControllerNumber((uint8)4);
    setPedal_2_ControllerNumber((uint8)64);
    setLever_2_ControllerNumber((uint8)1);
    setLever_3_ControllerNumber((uint8)2);
    setVibratoSpeed((uint8)30);
    setVibratoWaveType(VibratoWaveType::triangle);
    setVibratoAmplitude((uint8)0);
    setVibratoSpeedModSource(VibratoModSource::off);
    setVibratoSpeedModAmount((uint8)0);
    setVibratoAmpModSource(VibratoModSource::lever_2);
    setVibratoAmpModAmount((uint8)63);
    setGlobalTune((uint8)63);
    setSplitStereoIsEnabled(false);
    setVoiceMapIsEnabled(false);
    setVoiceMapEchoIsEnabled(false);
    setDisplayBrightness((uint8)27);
    set_SQUICK_IsEnabled(false);
    resetVoiceMap();
}

const uint8 GlobalOptions::basicChannel() {
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_BasicChannel);
}

void GlobalOptions::setBasicChannel(const uint8 newChannel) {
    globalOptionsTree.setProperty(ID::global_BasicChannel, newChannel, nullptr);
}

const bool GlobalOptions::omniModeIsEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_OmniModeIsEnabled) == true;
}

void GlobalOptions::setOmniModeIsEnabled(const bool shouldBeEnabled) {
    globalOptionsTree.setProperty(ID::global_OmniModeIsEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
}

const bool GlobalOptions::controllersAreEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_ControllersAreEnabled) == true;
}

void GlobalOptions::setControllersAreEnabled(const bool shouldBeEnabled) {
    globalOptionsTree.setProperty(ID::global_ControllersAreEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
}

const bool GlobalOptions::voiceChangesAreEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_VoiceChangesAreEnabled) == true;
}

void GlobalOptions::setVoiceChangesAreEnabled(const bool shouldBeEnabled) {
    globalOptionsTree.setProperty(ID::global_VoiceChangesAreEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
}

const bool GlobalOptions::sysExIsEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_SysExIsEnabled) == true;
}

void GlobalOptions::setSysExIsEnabled(const bool shouldBeEnabled) {
    globalOptionsTree.setProperty(ID::global_SysExIsEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
}

const bool GlobalOptions::spilloverIsEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_SpilloverIsEnabled) == true;
}

void GlobalOptions::setSpilloverIsEnabled(const bool shouldBeEnabled) {
    globalOptionsTree.setProperty(ID::global_SpilloverIsEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
}

const bool GlobalOptions::midiEchoIsEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_MIDI_EchoIsEnabled) == true;
}

void GlobalOptions::set_MIDI_EchoIsEnabled(const bool shouldBeEnabled) {
    globalOptionsTree.setProperty(ID::global_MIDI_EchoIsEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
}

const bool GlobalOptions::midiMonoIsEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_MIDI_MonoIsEnabled) == true;
}

void GlobalOptions::set_MIDI_MonoIsEnabled(const bool shouldBeEnabled) {
    globalOptionsTree.setProperty(ID::global_MIDI_MonoIsEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
}

const bool GlobalOptions::activeSensingIsEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_ActiveSensingIsEnabled) == true;
}

void GlobalOptions::setActiveSensingIsEnabled(const bool shouldBeEnabled) {
    globalOptionsTree.setProperty(ID::global_ActiveSensingIsEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
}

const bool GlobalOptions::localControlIsEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_LocalControIsEnabled) == true;
}

void GlobalOptions::setLocalControIsEnabled(const bool shouldBeEnabled) {
    globalOptionsTree.setProperty(ID::global_LocalControIsEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
}

const uint8 GlobalOptions::pedal_1_ControllerNumber() {
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_Pedal_1_ControllerNumber);
}

void GlobalOptions::setPedal_1_ControllerNumber(const uint8 newControllerNum) {
    jassert(newControllerNum < 122);
    globalOptionsTree.setProperty(ID::global_Pedal_1_ControllerNumber, newControllerNum, nullptr);
}

const uint8 GlobalOptions::pedal_2_ControllerNumber() {
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_Pedal_2_ControllerNumber);
}

void GlobalOptions::setPedal_2_ControllerNumber(const uint8 newControllerNum) {
    jassert(newControllerNum < 122);
    globalOptionsTree.setProperty(ID::global_Pedal_2_ControllerNumber, newControllerNum, nullptr);
}

const uint8 GlobalOptions::lever_2_ControllerNumber() {
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_Lever_2_ControllerNumber);
}

void GlobalOptions::setLever_2_ControllerNumber(const uint8 newControllerNum) {
    jassert(newControllerNum < 122);
    globalOptionsTree.setProperty(ID::global_Lever_2_ControllerNumber, newControllerNum, nullptr);
}

const uint8 GlobalOptions::lever_3_ControllerNumber() {
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_Lever_3_ControllerNumber);
}

void GlobalOptions::setLever_3_ControllerNumber(const uint8 newControllerNum) {
    jassert(newControllerNum < 122);
    globalOptionsTree.setProperty(ID::global_Lever_3_ControllerNumber, newControllerNum, nullptr);
}

const uint8 GlobalOptions::vibratoSpeed() {
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_VibratoSpeed);
}

void GlobalOptions::setVibratoSpeed(const uint8 newSpeed) {
    jassert(newSpeed < 64);
    globalOptionsTree.setProperty(ID::global_VibratoSpeed, newSpeed, nullptr);
}

const VibratoWaveType GlobalOptions::vibratoWaveType() {
    return VibratoWaveType{ (int)globalOptionsTree.getProperty(ID::global_VibratoWaveType) };
}

void GlobalOptions::setVibratoWaveType(const VibratoWaveType newWaveType) {
    globalOptionsTree.setProperty(ID::global_VibratoWaveType, (int)newWaveType, nullptr);
}

const uint8 GlobalOptions::vibratoAmplitude() {
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_VibratoAmplitude);
}

void GlobalOptions::setVibratoAmplitude(const uint8 newAmplitude) {
    jassert(newAmplitude < 64);
    globalOptionsTree.setProperty(ID::global_VibratoAmplitude, newAmplitude, nullptr);
}

const VibratoModSource GlobalOptions::vibratoSpeedModSource() {
    return VibratoModSource{ (int)globalOptionsTree.getProperty(ID::global_VibratoSpeedModSource) };
}

void GlobalOptions::setVibratoSpeedModSource(const VibratoModSource newSource) {
    globalOptionsTree.setProperty(ID::global_VibratoSpeedModSource, (int)newSource, nullptr);
}

const uint8 GlobalOptions::vibratoSpeedModAmount() {
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_VibratoSpeedModAmount);
}

void GlobalOptions::setVibratoSpeedModAmount(const uint8 newAmount) {
    jassert(newAmount < 64);
    globalOptionsTree.setProperty(ID::global_VibratoSpeedModAmount, newAmount, nullptr);
}

const VibratoModSource GlobalOptions::vibratoAmpModSource() {
    return VibratoModSource{ (int)globalOptionsTree.getProperty(ID::global_VibratoAmpModSource) };
}

void GlobalOptions::setVibratoAmpModSource(const VibratoModSource newSource) {
    globalOptionsTree.setProperty(ID::global_VibratoAmpModSource, (int)newSource, nullptr);
}

const uint8 GlobalOptions::vibratoAmpModAmount() {
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_VibratoAmpModAmount);
}

void GlobalOptions::setVibratoAmpModAmount(const uint8 newAmount) {
    jassert(newAmount < 64);
    globalOptionsTree.setProperty(ID::global_VibratoAmpModAmount, newAmount, nullptr);
}

const uint8 GlobalOptions::globalTune() {
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_Tune);
}

void GlobalOptions::setGlobalTune(const uint8 newTune) {
    jassert(newTune < 127);
    globalOptionsTree.setProperty(ID::global_Tune, newTune, nullptr);
}

const bool GlobalOptions::splitStereoIsEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_SplitStereoIsEnabled) == true;
}

void GlobalOptions::setSplitStereoIsEnabled(const bool shouldBeEnabled) {
    globalOptionsTree.setProperty(ID::global_SplitStereoIsEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
}

const bool GlobalOptions::voiceMapIsEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_VoicesMapIsEnabled) == true;
}

void GlobalOptions::setVoiceMapIsEnabled(const bool shouldBeEnabled) {
    globalOptionsTree.setProperty(ID::global_VoicesMapIsEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
}

const bool GlobalOptions::voiceMapEchoIsEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_VoicesMapEchoIsEnabled) == true;
}

void GlobalOptions::setVoiceMapEchoIsEnabled(const bool shouldBeEnabled) {
    globalOptionsTree.setProperty(ID::global_VoicesMapEchoIsEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
}

const uint8 GlobalOptions::displayBrightness() {
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_DisplayBrightness);
}

void GlobalOptions::setDisplayBrightness(const uint8 newBrightness) {
    jassert(newBrightness > 0 && newBrightness < 32);
    globalOptionsTree.setProperty(ID::global_DisplayBrightness, newBrightness, nullptr);
}

const bool GlobalOptions::squickIsEnabled() {
    return (bool)globalOptionsTree.getProperty(ID::global_SQUICK_IsEnabled) == true;
}

void GlobalOptions::set_SQUICK_IsEnabled(const bool shouldBeEnabled) {
    globalOptionsTree.setProperty(ID::global_SQUICK_IsEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
}

const uint8 GlobalOptions::inVoiceForVoiceMapNumber(const uint8 mapNum) {
    jassert(mapNum < 100);
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_VoiceMapIn_.toString() + (String)mapNum);
}

void GlobalOptions::setInVoiceForVoiceMapNumber(const uint8 newInVoice, const uint8 mapNum) {
    jassert(newInVoice < 100 && mapNum < 100);
    globalOptionsTree.setProperty(ID::global_VoiceMapIn_.toString() + (String)mapNum, newInVoice, nullptr);
}

const uint8 GlobalOptions::outVoiceForVoiceMapNumber(const uint8 mapNum) {
    jassert(mapNum < 100);
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_VoiceMapOut_.toString() + (String)mapNum);
}

void GlobalOptions::setOutVoiceForVoiceMapNumber(const uint8 newOutVoice, const uint8 mapNum) {
    jassert(newOutVoice < 100 && mapNum < 100);
    globalOptionsTree.setProperty(ID::global_VoiceMapOut_.toString() + (String)mapNum, newOutVoice, nullptr);
}

void GlobalOptions::resetVoiceMap() {
    for (auto i = (uint8)0; i != VCS::numberOfSlotsInVoicesBank; ++i) {
        setInVoiceForVoiceMapNumber(i, i);
        setOutVoiceForVoiceMapNumber(i, i);
    }
}

Value GlobalOptions::getGobalParamAsValue(const Identifier paramID) {
    return globalOptionsTree.getPropertyAsValue(paramID, nullptr);
}
