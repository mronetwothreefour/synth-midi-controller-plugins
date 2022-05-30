#include "0_global_build_ChoiceName.h"



String GlobalParamChoiceName::buildFor_GlobalTranspose(int choiceNum, bool verbose) {
    jassert(choiceNum > -1 && choiceNum < 25);
    if (verbose) {
        if (choiceNum < 11)
            return (String)(choiceNum - 12) + " semitones";
        if (choiceNum == 11)
            return "-1 semitone";
        if (choiceNum == 12)
            return "No Transpose";
        if (choiceNum == 13)
            return "+1 semitone";
        if (choiceNum > 13 && choiceNum < 25)
            return "+" + (String)(choiceNum - 12) + " semitones";
        else
            return "range error";
    }
    else {
        if (choiceNum < 13)
            return (String)(choiceNum - 12);
        if (choiceNum > 12 && choiceNum < 25)
            return "+" + (String)(choiceNum - 12);
        else
            return "err";
    }
}

String GlobalParamChoiceName::buildFor_HardwareReceiveChannel(int choiceNum, bool verbose) {
    jassert(choiceNum < 17);
    if (verbose) {
        if (choiceNum == 0)
            return "All Channels";
        if (choiceNum > 0 && choiceNum < 17)
            return "Channel " + (String)choiceNum;
        else
            return "range error";
    }
    else {
        if (choiceNum == 0)
            return "ALL";
        if (choiceNum > 0 && choiceNum < 17)
            return (String)choiceNum;
        else return
            "err";
    }
}

String GlobalParamChoiceName::buildFor_GlobalFineTune(int choiceNum, bool verbose) {
    jassert(choiceNum < 101);
    if (verbose) {
        if (choiceNum < 49)
            return (String)(choiceNum - 50) + " cents";
        if (choiceNum == 49)
            return "-1 cent";
        if (choiceNum == 50)
            return "No Detune";
        if (choiceNum == 51)
            return "+1 cent";
        if (choiceNum > 51 && choiceNum < 101)
            return "+" + (String)(choiceNum - 50) + " cents";
        else
            return "range error";
    }
    else {
        if (choiceNum < 51)
            return (String)(choiceNum - 50);
        if (choiceNum > 50 && choiceNum < 101)
            return "+" + (String)(choiceNum - 50);
        else
            return "err";
    }
}
