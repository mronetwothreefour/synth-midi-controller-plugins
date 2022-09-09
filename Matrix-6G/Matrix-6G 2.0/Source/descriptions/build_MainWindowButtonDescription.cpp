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
