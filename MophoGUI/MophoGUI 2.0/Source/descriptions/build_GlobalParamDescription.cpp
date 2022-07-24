#include "build_GlobalParamDescription.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace MophoConstants;

String GlobalParamDescription::buildForAudioOutput() {
    String descriptionString{ "" };
    descriptionString += "Shows whether the hardware is outputting audio in mono\n";
    descriptionString += "or in stereo. This option cannot be changed remotely and\n";
    descriptionString += "must be set within the hardware" + GUI::apostrophe + "s Global Parameters menus.";
    return descriptionString;
}

String GlobalParamDescription::buildForHardwareOutputBalance() {
    String descriptionString{ "" };
    descriptionString += "Applies a small adjustment to the balance of the hardware" + GUI::apostrophe + "s\n";
    descriptionString += "audio output jacks. This option cannot be changed remotely\n";
    descriptionString += "and must be set within the hardware" + GUI::apostrophe + "s Global Parameters menus.\n";
    descriptionString += "(This option was added in Mopho firmware version 1.4)\n";
    return descriptionString;
}

String GlobalParamDescription::buildForCurrentValueTooltip() {
    String descriptionString{ "" };
    descriptionString += "Selects whether hovering over a control with the mouse cursor will open\n";
    descriptionString += "a tooltip box showing a wordy version of the control" + GUI::apostrophe + "s current setting.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForDescriptionTooltip() {
    String descriptionString{ "" };
    descriptionString += "Selects whether hovering over a control with the mouse cursor will\n";
    descriptionString += "open a tooltip box showing a description of what the control does.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForGlobalFineTune() {
    String descriptionString{ "" };
    descriptionString += "All audio output from the hardware will\n";
    descriptionString += "be tuned up or down by this amount.\n";
    descriptionString += "Range: -50 to +50 cents.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForGlobalTranspose() {
    String descriptionString{ "" };
    descriptionString += "All audio output from the hardware will be\n";
    descriptionString += "transposed up or down by this amount.\n";
    descriptionString += "Range: -12 to +12 semitones.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForHardwareReceiveChannel() {
    String descriptionString{ "" };
    descriptionString += "Selects the channel on which the hardware\n";
    descriptionString += "sends and receives MIDI data. When set to\n";
    descriptionString += "All Channels, the hardware receives MIDI data\n";
    descriptionString += "on all channels and transmits on Channel 1.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForMIDI_ClockSource() {
    return "Selects the hardware" + GUI::apostrophe + "s MIDI clock source.\n";
}

String GlobalParamDescription::buildForMIDI_ControllersStatus() {
    String descriptionString{ "" };
    descriptionString += "Shows whether or not the hardware will respond to MIDI controller messages.\n";
    descriptionString += "WARNING: Controller messages are used to communicate with the hardware.\n";
    descriptionString += "It is essential that this be set to " + GUI::openQuote + "ON" + GUI::closeQuote + " for this plugin to function correctly.\n";
    descriptionString += "This option cannot be changed remotely and must be set within the\n";
    descriptionString += "hardware" + GUI::apostrophe + "s Global Parameters menus.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForParamChangeSendType() {
    String descriptionString{ "" };
    descriptionString += "Selects what type of MIDI messages the hardware\n";
    descriptionString += "transmits when the front panel controls are changed.\n";
    descriptionString += "Note: NRPNs are preferred, as many parameters have\n";
    descriptionString += "ranges that exceed the 7-bit range of CC messages.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForParamChangeReceiveType() {
    String descriptionString{ "" };
    descriptionString += "The type of MIDI parameter change messages recognized by the hardware.\n";
    descriptionString += "WARNING: This plugin transmits parameter changes using NRPN. It is\n";
    descriptionString += "essential that this be set to " + GUI::openQuote + "ALL" + GUI::closeQuote + " or " + GUI::openQuote + "NRPN ONLY" + GUI::closeQuote + " for the plugin to\n";
    descriptionString += "function correctly. This option cannot be changed remotely and must\n";
    descriptionString += "be set within the hardware" + GUI::apostrophe + "s Global Parameters menus.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForPedalMode() {
    String descriptionString{ "" };
    descriptionString += "When Arpeggiator Latch mode is selected and the arpeggiator is on,\n";
    descriptionString += "MIDI sustain pedal on messages (CC# 64) will latch the arpeggiated notes.\n";
    descriptionString += "When the arpeggiator is off, sustain pedal on messages will behave normally.\n";
    descriptionString += "(This option was added in Mopho firmware version 1.4)\n";
    return descriptionString;
}

String GlobalParamDescription::buildForSysExStatus() {
    String descriptionString{ "" };
    descriptionString += "Shows whether or not the hardware will transmit / receive\n";
    descriptionString += "MIDI system exclusive messages. WARNING: Program data is\n";
    descriptionString += "transferred between the plugin and the hardware via system\n";
    descriptionString += "exclusive messages. It is essential that this option\n";
    descriptionString += "be set to " + GUI::openQuote + "ON" + GUI::closeQuote + " for the plugin to function correctly.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForTooltipDelay() {
    String descriptionString{ "" };
    descriptionString += "Sets the amount of time (in milliseconds) the mouse cursor\n";
    descriptionString += "must hover over a control before a tooltip box is shown.\n";
    descriptionString += "Maximum delay: 5000 ms.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForVoiceChanges() {
    String descriptionString{ "" };
    descriptionString += "When enabled, the hardware will respond to incoming\n";
    descriptionString += "MIDI program change and bank change messages.\n";
    descriptionString += "(This option was added in Mopho firmware version 1.4)\n";
    return descriptionString;
}
