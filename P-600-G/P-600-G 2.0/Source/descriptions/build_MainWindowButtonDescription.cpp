#include "build_MainWindowButtonDescription.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace P_600_G_Constants;

String MainWindowButtonDescription::buildForPull() {
    String descriptionString{ "" };
    descriptionString += "Pull the data from a program storage slot in the\n";
    descriptionString += "Prophet-600 hardware (specified by the program number\n";
    descriptionString += "control to the left) and apply it to the plugin GUI.";
    return descriptionString;
}

String MainWindowButtonDescription::buildForPush() {
    String descriptionString{ "" };
    descriptionString += "Sends the current program settings to the hardware\n";
    descriptionString += "storage slot specified by the program number control\n";
    descriptionString += "to the left. NOTE: This overwrites the data that is\n";
    descriptionString += "currently stored in the slot and cannot be undone.";
    return descriptionString;
}
