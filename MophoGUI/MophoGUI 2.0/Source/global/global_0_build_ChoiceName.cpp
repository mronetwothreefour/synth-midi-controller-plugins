#include "global_0_build_ChoiceName.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace MophoConstants;

String GlobalParamChoiceName::buildForAudioOutput(const bool isMono) {
    if (isMono)
        return "AUDIO OUTPUT : MONO";
    else
        return "AUDIO OUTPUT : STEREO";
}

String GlobalParamChoiceName::buildForGlobalFineTune(const int choiceNum, const ChoiceNameType type) {
    jassert(choiceNum < 101);
    if (choiceNum < 49)
        return (String)(choiceNum - 50) + (type == ChoiceNameType::verbose ? " cents" : "");
    if (choiceNum == 49)
        return type == ChoiceNameType::verbose ? "-1 cent" : "-1";
    if (choiceNum == 50)
        return type == ChoiceNameType::verbose ? "No Detune" : "0";
    if (choiceNum == 51)
        return type == ChoiceNameType::verbose ? "+1 cent" : "+1";
    if (choiceNum > 51 && choiceNum < 101)
        return "+" + (String)(choiceNum - 50) + (type == ChoiceNameType::verbose ? " cents" : "");
    else
        return type == ChoiceNameType::verbose ? "range error" : "err";
}

String GlobalParamChoiceName::buildForGlobalTranspose(const int choiceNum, const ChoiceNameType type) {
    jassert(choiceNum > -1 && choiceNum < 25);
    if (choiceNum < 11)
        return (String)(choiceNum - 12) + (type == ChoiceNameType::verbose ? " semitones" : "");
    if (choiceNum == 11)
        return type == ChoiceNameType::verbose ? "-1 semitone" : "-1";
    if (choiceNum == 12)
        return type == ChoiceNameType::verbose ? "No Transpose" : "0";
    if (choiceNum == 13)
        return type == ChoiceNameType::verbose ? "+1 semitone" : "+1";
    if (choiceNum > 13 && choiceNum < 25)
        return "+" + (String)(choiceNum - 12) + (type == ChoiceNameType::verbose ? " semitones" : "");
    else
        return type == ChoiceNameType::verbose ? "range error" : "err";
}

String GlobalParamChoiceName::buildForHardwareOutputBalance(const int choiceNum) {
    jassert(choiceNum < 15);
    if (choiceNum < 7)
        return "BALANCE TWEAK : " + (String)(choiceNum - 7);
    if (choiceNum == 7)
        return "BALANCE TWEAK : NONE";
    if (choiceNum > 7 && choiceNum < 15)
        return "BALANCE TWEAK : +" + (String)(choiceNum - 7);
    else
        return "range error";
}

String GlobalParamChoiceName::buildForHardwareReceiveChannel(const int choiceNum, const ChoiceNameType type) {
    jassert(choiceNum < 17);
    if (choiceNum == 0)
        return type == ChoiceNameType::verbose ? "All Channels" : "ALL";
    if (choiceNum > 0 && choiceNum < 17)
        return type == ChoiceNameType::verbose ? "Channel " + (String)choiceNum : (String)choiceNum;
    else
        return type == ChoiceNameType::verbose ? "range error" : "err";
}

String GlobalParamChoiceName::buildForMIDI_ClockSource(const MIDI_ClockSource sourceType, const ChoiceNameType type) {
    switch (sourceType)
    {
    case MIDI_ClockSource::internalClock:
        return type == ChoiceNameType::verbose ? "Use Internal, Don" + GUI::apostrophe + "t Transmit" : "Internal";
    case MIDI_ClockSource::internalClock_Send:
        return type == ChoiceNameType::verbose ? "Use Internal, Transmit" : "MIDI Out";
    case MIDI_ClockSource::externalClock:
        return type == ChoiceNameType::verbose ? "Use Incoming, Don" + GUI::apostrophe + "t Re-Transmit" : "MIDI In";
    case MIDI_ClockSource::externalClock_Resend:
        return type == ChoiceNameType::verbose ? "Use Incoming, Re-Transmit" : "MIDI In/Out";
    default:
        return "range error";
    }
}

String GlobalParamChoiceName::buildForMIDI_Controllers(const bool areEnabled) {
    if (areEnabled)
        return "MIDI CONTROLLERS : ON";
    else
        return "MIDI CONTROLLERS : OFF ( ! )";
}

String GlobalParamChoiceName::buildForParamChangeReceiveType(const ParamChangeReceiveType receiveType) {
    switch (receiveType)
    {
    case ParamChangeReceiveType::all:
        return "PARAMETER RECEIVE : ALL";
    case ParamChangeReceiveType::nrpnOnly:
        return "PARAMETER RECEIVE : NRPN ONLY";
    case ParamChangeReceiveType::ccOnly:
        return "PARAMETER RECEIVE : CC ONLY ( ! )";
    case ParamChangeReceiveType::off:
        return "PARAMETER RECEIVE : OFF ( ! )";
    default:
        return "range error";
    }
}

String GlobalParamChoiceName::buildForParamChangeSendType(const ParamChangeSendType sendType) {
    switch (sendType)
    {
    case ParamChangeSendType::nrpn:
        return "NRPN";
    case ParamChangeSendType::cc:
        return "CC";
    case ParamChangeSendType::off:
        return "Off";
    default:
        return "range error";
    }
}

String GlobalParamChoiceName::buildForPedalMode(const bool isArpLatch) {
    if (isArpLatch)
        return "Arpeggiator Latch";
    else
        return "Normal";
}

String GlobalParamChoiceName::buildForSysEx(const bool isOn) {
    if (isOn)
        return "SYSTEM EXCLUSIVE : ON";
    else
        return "SYSTEM EXCLUSIVE : OFF ( ! )";
}

String GlobalParamChoiceName::buildForVoiceChanges(const bool isEnabled) {
    if (isEnabled)
        return "Enabled";
    else
        return "Disabled";
}
