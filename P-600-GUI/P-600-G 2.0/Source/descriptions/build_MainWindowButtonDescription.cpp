#include "build_MainWindowButtonDescription.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace P_600_G_Constants;

String MainWindowButtonDescription::buildForHyperlink() {
    return "Click to go to programming.mr1234.com";
}

String MainWindowButtonDescription::buildForPull() {
    String descriptionString{ "" };
    descriptionString += "Pull the data from a program storage slot in\n";
    descriptionString += "the Prophet-600 hardware (specified by the\n";
    descriptionString += "program number control to the left) and apply\n";
    descriptionString += "it to the plugin GUI. Shortcut key: CTRL+[";
    return descriptionString;
}

String MainWindowButtonDescription::buildForPush() {
    String descriptionString{ "" };
    descriptionString += "Sends the current program settings to the\n";
    descriptionString += "hardware storage slot specified by the program\n";
    descriptionString += "number control to the left. NOTE: This overwrites\n";
    descriptionString += "the data that is currently stored in the slot and\n";
    descriptionString += "cannot be undone. Shortcut key: CTRL+]";
    return descriptionString;
}

String MainWindowButtonDescription::buildForRandomize() {
    String descriptionString{ "" };
    descriptionString += "Click to randomize the program settings. Right-click to open an\n";
    descriptionString += "options window where you can define which parameters get randomized\n";
    descriptionString += "and what choices are allowed for each of them. Right-click any program\n";
    descriptionString += "parameter control to generate a random setting for that parameter.\n";
    descriptionString += "Shortcut keys: CTRL+D to randomize, CTRL+ALT+D to show the options.";
    return descriptionString;
}

String MainWindowButtonDescription::buildForRedo() {
    String descriptionString{ "" };
    descriptionString += "Click this button to redo a pre-\n";
    descriptionString += "viously undone parameter change.\n";
    descriptionString += "Shortcut key: CTRL+SHIFT+Z";
    return descriptionString;
}

String MainWindowButtonDescription::buildForShowTooltipsOptionsLayer() {
    String descriptionString{ "" };
    descriptionString += "Opens a window where you can\n";
    descriptionString += "set display options for control";
    descriptionString += "tooltips. Shortcut key: CTRL+T";
    return descriptionString;
}

String MainWindowButtonDescription::buildForUndo() {
    String descriptionString{ "" };
    descriptionString += "Click this button to undo the previous\n";
    descriptionString += "parameter change. Shortcut key: CTRL+Z";
    return descriptionString;
}

String MainWindowButtonDescription::buildForShowVoicesBankLayer() {
    String descriptionString{ "" };
    descriptionString += "Opens a window where you can manage\n";
    descriptionString += "the program presets storage bank.\n";
    descriptionString += "Shortcut key: CTRL+B";
    return descriptionString;
}
