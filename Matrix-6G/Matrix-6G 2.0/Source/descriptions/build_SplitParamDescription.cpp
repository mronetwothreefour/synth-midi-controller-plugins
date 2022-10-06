#include "build_SplitParamDescription.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace Matrix_6G_Constants;

String SplitParamDescription::buildForZoneLimit(bool isLowerZone) {
    String descriptionString{ "" };
    if (isLowerZone) {
        descriptionString += "The lower zone extends from this note\n";
        descriptionString += "down to C 0 (MIDI note number 0).\n";
    }
    else {
        descriptionString += "The upper zone extends from this note\n";
        descriptionString += "up to G 10 (MIDI note number 127).\n";
    }
    descriptionString += "The lower and upper zones can overlap,\n";
    descriptionString += "making it possible to play two patches\n";
    descriptionString += "at the same time. Range: C0 to G10.\n";
    descriptionString += "NOTE: Changes made to split parameters\n";
    descriptionString += "are not sent to the hardware until you\n";
    descriptionString += "SAVE the split in one of the storage\n";
    descriptionString += "bank slots below.\n";
    return descriptionString;
}

String SplitParamDescription::buildForZoneTranspose(bool isLowerZone) {
    String zoneName{ isLowerZone ? "lower" : "upper" };
    String descriptionString{ "" };
    descriptionString += "Raises or lowers the pitch of all notes\n";
    descriptionString += "in the " + zoneName + " zone in semitone increments.\n";
    descriptionString += "Range: -36 (lowered by 3 octaves) to\n";
    descriptionString += "+24 (raised by 2 octaves).\n";
    descriptionString += "NOTE: Changes made to split parame-\n";
    descriptionString += "ters are not sent to the hardware\n";
    descriptionString += "until you SAVE the split in one of\n";
    descriptionString += "the storage bank slots below.\n";
    return descriptionString;
}

String SplitParamDescription::buildForZoneVoiceNum(bool isLowerZone) {
    String descriptionString{ "" };
    descriptionString += "Selects which patch will be played by the\n";
    if (isLowerZone) {
        descriptionString += "lower zone (the left side of the keyboard).\n";
    }
    else {
        descriptionString += "upper zone (the right side of the keyboard).\n";
    }
    descriptionString += "Range: 0 to 99. NOTE: Changes made to\n";
    descriptionString += "split parameters are not sent to the hard-\n";
    descriptionString += "ware until you SAVE the split in one of\n";
    descriptionString += "the storage bank slots below.\n";
    return descriptionString;
}

String SplitParamDescription::buildForZoneVolumeBalance() {
    String descriptionString{ "" };
    descriptionString += "Sets the loudness of the lower and upper zones\n";
    descriptionString += "relative to one another. Range: -31 to +31.\n";
    descriptionString += "At 0, the zones have equal loudness. At -31,\n";
    descriptionString += "the lower zone is at full volume and the upper\n";
    descriptionString += "zone is barely heard. At +31, the reverse is true.\n";
    descriptionString += "NOTE: Changes made to split parameters are not\n";
    descriptionString += "sent to the hardware until you SAVE the split in\n";
    descriptionString += "one of the storage bank slots below.\n";
    return descriptionString;
}
