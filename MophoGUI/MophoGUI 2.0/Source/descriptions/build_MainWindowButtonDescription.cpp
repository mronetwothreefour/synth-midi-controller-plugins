#include "build_MainWindowButtonDescription.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace MophoConstants;



String MainWindowButtonDescription::buildForClearSeqTrack(int trackNum) {
    ++trackNum;
    String descriptionString{ "" };
    descriptionString += "Sets all steps in sequencer\n";
    if (trackNum == 1)
        descriptionString += "track 1 to 127 (" + GUI::openQuote + "rest" + GUI::closeQuote + ")";
    else
        descriptionString += "track " + (String)trackNum + " to 0 (C0)";
    return descriptionString;
}

String MainWindowButtonDescription::buildForEditBufferRead() {
    String descriptionString{ "" };
    descriptionString += "Requests a program edit buffer dump from the Mopho\n";
    descriptionString += "hardware and applies it to the plugin GUI.";
    return descriptionString;
}

String MainWindowButtonDescription::buildForEditBufferWrite() {
    String descriptionString{ "" };
    descriptionString += "Writes the plugin" + GUI::apostrophe + "s current program settings\n";
    descriptionString += "into the Mopho hardware" + GUI::apostrophe + "s program edit buffer.";
    return descriptionString;
}

String MainWindowButtonDescription::buildForHyperlink() {
    return "Click to go to programming.mr1234.com";
}

String MainWindowButtonDescription::buildForRedo() {
    String descriptionString{ "" };
    descriptionString += "Click this button (or type CTRL+SHIFT+z) to\n";
    descriptionString += "redo a previously undone parameter change.";
    return descriptionString;
}

String MainWindowButtonDescription::buildForShowGlobalParamsLayer() {
    String descriptionString{ "" };
    descriptionString += "Opens a window where you can change global settings\n";
    descriptionString += "for the hardware, as well as tooltip display options";
    return descriptionString;
}

String MainWindowButtonDescription::buildForShowRandomizationLayer() {
    String descriptionString{ "" };
    descriptionString += "Click to randomize the program settings. Right-click\n";
    descriptionString += "to open a dialog where you can define which parameters\n";
    descriptionString += "get randomized and what choices are allowed for each\n";
    descriptionString += "of them. Right-click any program parameter control to\n";
    descriptionString += "generate a random setting for that parameter.";
    return descriptionString;
}

String MainWindowButtonDescription::buildForShowVoiceNameEditor() {
    String descriptionString{ "" };
    descriptionString += "Opens an editor where you can\n";
    descriptionString += "type in a new program name.";
    return descriptionString;
}

String MainWindowButtonDescription::buildForShowVoicesBanksLayer() {
    String descriptionString{ "" };
    descriptionString += "Opens a window where you can manage the\n";
    descriptionString += "six storage banks for program presets.";
    return descriptionString;
}

String MainWindowButtonDescription::buildForUndo() {
    String descriptionString{ "" };
    descriptionString += "Click this button (or type CTRL+z) to\n";
    descriptionString += "undo the previous parameter change.";
    return descriptionString;
}

String MainWindowButtonDescription::buildForVoiceNameEditor() {
    String descriptionString{ "" };
    descriptionString += "Type in a new name for the program (max. 16 characters) and hit ENTER\n";
    descriptionString += "to apply it. Hit ESC to cancel. The Mopho" + GUI::apostrophe + "s hardware LCD characters use\n";
    descriptionString += "the basic ASCII character set, with a few exceptions: " + GUI::openQuote + "\\" + GUI::closeQuote + " becomes\n";
    descriptionString += "a yen sign and " + GUI::openQuote + "~" + GUI::closeQuote + " (tilde) becomes a right arrow. The " + GUI::openQuote + "delete" + GUI::closeQuote + " character\n";
    descriptionString += "becomes a left arrow; obviously, you can" + GUI::apostrophe + "t type that in the editor. However,\n";
    descriptionString += "you can access it by changing a character in the GUI" + GUI::apostrophe + "s name display with\n";
    descriptionString += "the mouse. The hardware name display will not update immediately -\n";
    descriptionString += "press the Program Mode button to see the new name.";
    return descriptionString;
}
