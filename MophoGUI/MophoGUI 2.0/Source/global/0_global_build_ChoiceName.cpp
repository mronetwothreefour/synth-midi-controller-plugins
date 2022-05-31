#include "0_global_build_ChoiceName.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace MophoConstants;



String GlobalParamChoiceName::buildFor_GlobalTranspose(int choiceNum, bool verbose) {
    jassert(choiceNum > -1 && choiceNum < 25);
    if (choiceNum < 11)
        return (String)(choiceNum - 12) + (verbose ? " semitones" : "");
    if (choiceNum == 11)
        return verbose ? "-1 semitone" : "-1";
    if (choiceNum == 12)
        return verbose ? "No Transpose" : "0";
    if (choiceNum == 13)
        return verbose ? "+1 semitone" : "+1";
    if (choiceNum > 13 && choiceNum < 25)
        return "+" + (String)(choiceNum - 12) + (verbose ? " semitones" : "");
    else
        return verbose ? "range error" : "err";
}

String GlobalParamChoiceName::buildFor_HardwareReceiveChannel(int choiceNum, bool verbose) {
    jassert(choiceNum < 17);
    if (choiceNum == 0)
        return verbose ? "All Channels" : "ALL";
    if (choiceNum > 0 && choiceNum < 17)
        return verbose ? "Channel " + (String)choiceNum : (String)choiceNum;
    else
        return verbose ? "range error" : "err";
}

String GlobalParamChoiceName::buildFor_MIDI_ClockSource(MIDI_ClockSource sourceType, bool verbose) {
    switch (sourceType)
    {
    case MIDI_ClockSource::internalClock:
        return verbose ? "Use Internal, Don" + GUI::apostrophe + "t Transmit" : "Internal";
    case MIDI_ClockSource::internalClock_Send:
        return verbose ? "Use Internal, Transmit" : "MIDI Out";
    case MIDI_ClockSource::externalClock:
        return verbose ? "Use Incoming, Don" + GUI::apostrophe + "t Re-Transmit" : "MIDI In";
    case MIDI_ClockSource::externalClock_Resend:
        return verbose ? "Use Incoming, Re-Transmit" : "MIDI In/Out";
    default:
        return "range error";
    }
}

String GlobalParamChoiceName::buildFor_MIDI_Controllers(bool areOn) {
    if (areOn)
        return "MIDI CONTROLLERS : ON";
    else
        return "MIDI CONTROLLERS : OFF ( ! )";
}

String GlobalParamChoiceName::buildFor_ParamChangeReceiveType(ParamChangeReceiveType receiveType) {
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

String GlobalParamChoiceName::buildFor_ParamChangeSendType(ParamChangeSendType sendType) {
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

String GlobalParamChoiceName::buildFor_PedalMode(bool isArpLatch) {
    if (isArpLatch)
        return "Arpeggiator Latch";
    else
        return "Normal";
}

String GlobalParamChoiceName::buildFor_SysEx(bool isOn) {
    if (isOn)
        return "SYSTEM EXCLUSIVE : ON";
    else
        return "SYSTEM EXCLUSIVE : OFF ( ! )";
}

String GlobalParamChoiceName::buildFor_VoiceChange(bool isEnabled) {
    if (isEnabled)
        return "Enabled";
    else
        return "Disabled";
}

String GlobalParamChoiceName::buildFor_AudioOutput(bool isStereo) {
    if (isStereo)
        return "AUDIO OUTPUT : STEREO";
    else
        return "AUDIO OUTPUT : MONO";
}

String GlobalParamChoiceName::buildFor_HardwareOutputBalance(int choiceNum) {
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

String GlobalParamChoiceName::buildFor_GlobalFineTune(int choiceNum, bool verbose) {
    jassert(choiceNum < 101);
    if (choiceNum < 49)
        return (String)(choiceNum - 50) + (verbose ? " cents" : "");
    if (choiceNum == 49)
        return verbose ? "-1 cent" : "-1";
    if (choiceNum == 50)
        return verbose ? "No Detune" : "0";
    if (choiceNum == 51)
        return verbose ? "+1 cent" : "+1";
    if (choiceNum > 51 && choiceNum < 101)
        return "+" + (String)(choiceNum - 50) + (verbose ? " cents" : "");
    else
        return verbose ? "range error" : "err";
}
