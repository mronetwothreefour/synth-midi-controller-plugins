#include "gui_build_ButtonDescriptionString.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace MophoConstants;



String ButtonDescriptionString::buildFor_EditBufferRead() {
    String descriptionString{ "" };
    descriptionString += "Requests a program edit buffer dump from the Mopho\n";
    descriptionString += "hardware and applies it to the plugin GUI.";
    return descriptionString;
}

String ButtonDescriptionString::buildFor_EditBufferWrite() {
    String descriptionString{ "" };
    descriptionString += "Writes the plugin" + GUI::apostrophe + "s current program settings\n";
    descriptionString += "into the Mopho hardware" + GUI::apostrophe + "s program edit buffer.";
    return descriptionString;
}

String ButtonDescriptionString::buildFor_Hyperlink() {
    return "Click to go to programming.mr1234.com";
}

String ButtonDescriptionString::buildFor_Redo() {
    String descriptionString{ "" };
    descriptionString += "Click this button (or type Ctrl+Shift+Z) to\n";
    descriptionString += "redo a previously undone parameter change.";
    return descriptionString;
}

String ButtonDescriptionString::buildFor_Undo() {
    String descriptionString{ "" };
    descriptionString += "Click this button (or type Ctrl+Z) to\n";
    descriptionString += "undo the previous parameter change.";
    return descriptionString;
}
