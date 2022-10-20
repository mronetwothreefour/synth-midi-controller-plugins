#include "build_GlobalParamDescription.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

String GlobalParamDescription::buildForVoiceMapInVoice(uint8 mapSlotNum) {
    String descriptionString{ "" };
    descriptionString += "When the Patch Map is enabled, a MIDI program change\n";
    descriptionString += "message calling program " + (String)mapSlotNum + " will load the patch selected\n";
    descriptionString += "here into the hardware instead. NOTE: Changes to the\n";
    descriptionString += "Patch Map will not be updated on the hardware until\n";
    descriptionString += "the PUSH button in the Master window is clicked.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForVoiceMapOutVoice(uint8 mapSlotNum) {
    String descriptionString{ "" };
    descriptionString += "When the Patch Map and Patch Map Echo are both enabled\n";
    descriptionString += "and a MIDI program change message calling program " + (String)mapSlotNum + " is\n";
    descriptionString += "received, the hardware will send out a new program change\n";
    descriptionString += "message to downstream devices calling this program instead.\n";
    descriptionString += "NOTE: Changes to the Patch Map will not be updated on the\n";
    descriptionString += "hardware until the PUSH button in the Master window is clicked.\n";
    return descriptionString;
}
