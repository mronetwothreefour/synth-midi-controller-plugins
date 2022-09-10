#include "build_MainWindowButtonDescription.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace Matrix_6G_Constants;

String MainWindowButtonDescription::buildForActivateQuickEdit() {
    String descriptionString{ "" };
    descriptionString += "The Matrix must be set to Quick Patch Edit mode in order\n";
    descriptionString += "for it to respond to remote parameter changes. Click this\n";
    descriptionString += "button before making any edits in the GUI (the hardware" + GUI::apostrophe + "s\n";
    descriptionString += "front panel display should switch to PATCH EDIT).";
    return descriptionString;
}

String MainWindowButtonDescription::buildForPull() {
    String descriptionString{ "" };
    descriptionString += "Pull the data from the selected patch storage slot in\n";
    descriptionString += "the Matrix-6R hardware and apply it to the plugin GUI.";
    return descriptionString;
}

String MainWindowButtonDescription::buildForPush() {
    String descriptionString{ "" };
    descriptionString += "Sends a dump of the current patch data to the hardware\n";
    descriptionString += "storage slot specified by the patch number control to\n";
    descriptionString += "the right, NOTE: This overwrites the data that is cur-\n";
    descriptionString += "rently stored in the slot and cannot be undone.";
    return descriptionString;
}
