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

String GlobalParamChoiceName::buildFor_MIDI_ClockSource(int choiceNum, bool verbose) {
    jassert(choiceNum < 4);
    if (choiceNum == 0)
        return verbose ? "Use Internal, Don" + GUI::apostrophe + "t Transmit" : "Internal";
    if (choiceNum == 1)
        return verbose ? "Use Internal, Transmit" : "MIDI Out";
    if (choiceNum == 2)
        return verbose ? "Use Incoming, Don" + GUI::apostrophe + "t Re-Transmit" : "MIDI In";
    if (choiceNum == 3)
        return verbose ? "Use Incoming, Re-Transmit" : "MIDI In/Out";
    else
        return "range error";
}

String GlobalParamChoiceName::buildFor_ParamChangeSendType(int choiceNum) {
    jassert(choiceNum < 3);
    if (choiceNum == 0)
        return "NRPN";
    if (choiceNum == 1)
        return "CC";
    if (choiceNum == 2)
        return "Off";
    else return "range error";
}

String GlobalParamChoiceName::buildFor_PedalMode(int choiceNum) {
    jassert(choiceNum < 2);
    if (choiceNum == 0)
        return "Normal";
    if (choiceNum == 1)
        return "Arpeggiator Latch";
    else
        return "range error";
}

String GlobalParamChoiceName::buildFor_VoiceChange(int choiceNum) {
    jassert(choiceNum < 2);
    if (choiceNum == 0)
        return "Disabled";
    if (choiceNum == 1)
        return "Enabled";
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
