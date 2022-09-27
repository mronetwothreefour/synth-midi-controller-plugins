#include "build_MainWindowButtonDescription.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace P_600_G_Constants;

String MainWindowButtonDescription::buildForPull() {
    String descriptionString{ "" };
    descriptionString += "Pull the data from a program storage slot in\n";
    descriptionString += "the Prophet-600 hardware (specified by the\n";
    descriptionString += "program number control to the left) and apply\n";
    descriptionString += "it to the plugin GUI. Shortcut key: CTRL+P";
    return descriptionString;
}

String MainWindowButtonDescription::buildForPush() {
    String descriptionString{ "" };
    descriptionString += "Sends the current program settings to the\n";
    descriptionString += "hardware storage slot specified by the program\n";
    descriptionString += "number control to the left. NOTE: This overwrites\n";
    descriptionString += "the data that is currently stored in the slot and\n";
    descriptionString += "cannot be undone. Shortcut key: CTRL+ALT+P";
    return descriptionString;
}

String MainWindowButtonDescription::buildForShowVoicesBankLayer() {
    String descriptionString{ "" };
    descriptionString += "Opens a window where you can manage\n";
    descriptionString += "the program presets storage bank.\n";
    descriptionString += "Shortcut key: CTRL+B";
    return descriptionString;
}
