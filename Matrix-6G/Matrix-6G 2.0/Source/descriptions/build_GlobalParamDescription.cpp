#include "build_GlobalParamDescription.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

String GlobalParamDescription::buildForActiveSensing() {
    String descriptionString{ "" };
    descriptionString += "When set to on, the hardware will monitor the MIDI\n";
    descriptionString += "connections to external devices and confirm that\n";
    descriptionString += "they are intact. If a connection is broken, an " + GUI::openQuote + "all\n";
    descriptionString += "notes off" + GUI::closeQuote + " command is initiated to prevent notes\n";
    descriptionString += "from being locked on. NOTE: Individual Master\n";
    descriptionString += "options are not immediately updated on the hard-\n";
    descriptionString += "ware. Click the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForBasicChannel() {
    String descriptionString{ "" };
    descriptionString += "Sets the MIDI channel that the hardware\n";
    descriptionString += "will use to receive and transmit messages\n";
    descriptionString += "(notes, patch changes, and controllers).\n";
    descriptionString += "NOTE: Individual Master options are not\n";
    descriptionString += "immediately updated on the hardware.\n";
    descriptionString += "Click the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForControllerNumForLever_2() {
    String descriptionString{ "" };
    descriptionString += "Selects the MIDI controller number that Lever 2\n";
    descriptionString += "will use to transmit and receive. " + GUI::openQuote + "Lever 2" + GUI::closeQuote + " is equi-\n";
    descriptionString += "valent to the modulation wheel found on most\n";
    descriptionString += "MIDI keyboard controllers. Range: 0 to 121.\n";
    descriptionString += "NOTE: Individual Master options are not immedi-\n";
    descriptionString += "ately updated on the hardware. Click the PUSH\n";
    descriptionString += "button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForControllerNumForLever_3() {
    String descriptionString{ "" };
    descriptionString += "The modulation wheel on Oberheim keyboard controllers\n";
    descriptionString += "(" + GUI::openQuote + "Lever 2" + GUI::closeQuote + ") was bi-directional, like a pitch bend wheel.\n";
    descriptionString += GUI::openQuote + "Lever 3" + GUI::closeQuote + " modulation increased as Lever 2 was pushed\n";
    descriptionString += "away from the player. This option selects the MIDI\n";
    descriptionString += "controller channel that Lever 3 will use to transmit\n";
    descriptionString += "and receive. Range: 0 to 121. NOTE: Individual Master\n";
    descriptionString += "options are not immediately updated on the hardware.\n";
    descriptionString += "Click the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForControllerNumForPedal(int pedalNum) {
    jassert(pedalNum == 1 || pedalNum == 2);
    String descriptionString{ "" };
    descriptionString += "Selects the MIDI controller number that Pedal " + (String)pedalNum + "\n";
    descriptionString += "will transmit and receive on. Range: 0 to 121.\n";
    descriptionString += "NOTE: Individual Master options are not immedi-\n";
    descriptionString += "ately updated on the hardware. Click the PUSH\n";
    descriptionString += "button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForControllers() {
    String descriptionString{ "" };
    descriptionString += "When set to on, the hardware will respond to incoming\n";
    descriptionString += "MIDI controller messages, as well as to the pedal inputs\n";
    descriptionString += "on the hardware" + GUI::apostrophe + "s rear panel (if Local Control is also on).\n";
    descriptionString += "When set to off, the hardware will only respond to MIDI\n";
    descriptionString += "note messages. NOTE: Individual Master options are not\n";
    descriptionString += "immediately updated on the hardware. Click the PUSH\n";
    descriptionString += "button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForCurrentValueTooltip() {
    String descriptionString{ "" };
    descriptionString += "When enabled, a tooltip with a verbose\n";
    descriptionString += "version of the current value will appear\n";
    descriptionString += "if the mouse hovers over a control for\n";
    descriptionString += "the amount of time specified below.\n";
    descriptionString += "NOTE: Changes to the tooltip options\n";
    descriptionString += "are updated immediately.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForDescriptionTooltip() {
    String descriptionString{ "" };
    descriptionString += "When enabled, a descriptive tooltip will appear if the mouse\n";
    descriptionString += "hovers over a control for the amount of time specified below.\n";
    descriptionString += "NOTE: Changes to the tooltip options are updated immediately.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForDisplayBrightness() {
    String descriptionString{ "" };
    descriptionString += "Sets the brightness of the display\n";
    descriptionString += "on the front panel of the hardware.\n";
    descriptionString += "Range: 1 (dimmest) to 31 (brightest).\n";
    descriptionString += "NOTE: Individual Master options are not\n";
    descriptionString += "immediately updated on the hardware.\n";
    descriptionString += "Click the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForGlobalTune() {
    String descriptionString{ "" };
    descriptionString += "Tunes all audio output from the hardware\n";
    descriptionString += "up or down. Range: -63 to +63, which represents\n";
    descriptionString += " +/- one quarter tone. NOTE: Individual Master\n";
    descriptionString += "options are not immediately updated on the hardware.\n";
    descriptionString += "Click the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForLocalControl() {
    String descriptionString{ "" };
    descriptionString += "When set to on, the hardware responds to the two pedal\n";
    descriptionString += "inputs on the back panel in addition to pedal messages\n";
    descriptionString += "coming in via MIDI. When set to off, the back panel\n";
    descriptionString += "pedal inputs are disabled. NOTE: Individual Master\n";
    descriptionString += "options are not immediately updated on the hardware.\n";
    descriptionString += "Click the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForOmniMode() {
    String descriptionString{ "" };
    descriptionString += "When Omni Mode is on, the hardware will respond to\n";
    descriptionString += "MIDI messages (notes, patch changes, and controllers)\n";
    descriptionString += "coming in on all 16 MIDI channels. When Omni Mode is\n";
    descriptionString += "off, the hardware will only respond to MIDI messages\n";
    descriptionString += "coming on the Basic Channel (above). NOTE: Individual\n";
    descriptionString += "Master options are not immediately updated on the\n";
    descriptionString += "hardware. Click the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForPushButton() {
    String descriptionString{ "" };
    descriptionString += "Push all the current Master\n";
    descriptionString += "settings to the hardware.";
    return descriptionString;
}

String GlobalParamDescription::buildForShowVoiceMapButton() {
    String descriptionString{ "" };
    descriptionString += "When enabled, the Patch Map lets you easily customize which patch gets\n";
    descriptionString += "loaded when the hardware receives a program change message, without\n";
    descriptionString += "having to physically reorder the voices in the storage bank. For example,\n";
    descriptionString += "a program change message calling program 0 can be specified to load\n";
    descriptionString += "patch 23 instead, and to also load patch 57 on a second device further\n";
    descriptionString += "on in the MIDI chain. Click this button to open a window where you can\n";
    descriptionString += "edit the Patch Map. NOTE: The changes you make will not be immediately\n";
    descriptionString += "updated on the hardware. Click the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForSpillover() {
    String descriptionString{ "" };
    descriptionString += "This option is useful if you have two Matrix-6R units\n";
    descriptionString += "connected via MIDI. When on, the two units can behave\n";
    descriptionString += "as if they were a single unit with 12 voices. If you\n";
    descriptionString += "play more than 6 notes at once, the additional notes\n";
    descriptionString += "will be transmitted to the second unit on the Basic\n";
    descriptionString += "Channel + 2 (e.g. if the Basic Channel is 1, the surplus\n";
    descriptionString += "notes will spillover onto channel 3). NOTE: Individual\n";
    descriptionString += "Master options are not immediately updated on the\n";
    descriptionString += "hardware. Click the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForSplitStereo() {
    String descriptionString{ "" };
    descriptionString += "If this is enabled while playing in Split mode,\n";
    descriptionString += "the Lower Split Zone patch will be output from the\n";
    descriptionString += "Left/Mono jack on the back panel of the hardware,\n";
    descriptionString += "and the Upper Zone patch will be output from the\n";
    descriptionString += "Right jack (normally, audio is only output from\n";
    descriptionString += "the Left/Mono jack). NOTE: Individual Master op-\n";
    descriptionString += "tions are not immediately updated on the hardware.\n";
    descriptionString += "Click the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForSysEx() {
    String descriptionString{ "" };
    descriptionString += "When set to on, the hardware will respond to MIDI\n";
    descriptionString += "System Exclusive (SysEx) messages. IMPORTANT: This\n";
    descriptionString += "plugin uses SysEx to communicate with the hardware and\n";
    descriptionString += "it is imperative that this option be set to on. If it\n";
    descriptionString += "gets turned off, it can only be turned back on in the\n";
    descriptionString += "Master Edit page on the hardware itself (parameter 04).\n";
    return descriptionString;
}

String GlobalParamDescription::buildForTooltipDelay() {
    String descriptionString{ "" };
    descriptionString += "Sets the amount of time (in milliseconds) the mouse cursor\n";
    descriptionString += "must hover over a control before a tooltip box is shown.\n";
    descriptionString += "Maximum delay: 5000 milliseconds. NOTE: Changes to \n";
    descriptionString += "the tooltip options are updated immediately.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForVibratoAmplitude() {
    String descriptionString{ "" };
    descriptionString += "Sets the degree of the vibrato modulation produced by LFO 3.\n";
    descriptionString += "Range: 0 (no modulation) to 63 (maximum modulation).\n";
    descriptionString += "NOTE: Individual Master options are not immediately updated\n";
    descriptionString += "on the hardware. Click the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForVibratoModAmount(bool isForSpeed) {
    String descriptionString{ "" };
    String modType{ isForSpeed ? "speed" : "amplitude" };
    descriptionString += "Sets the degree to which the selected source modulates the " + modType + "\n";
    descriptionString += "of low-frequency oscillator 3, which is dedicated to vibrato.\n";
    descriptionString += "Range: 0 (no modulation) to 63 (maximum modulation).\n";
    descriptionString += "NOTE: Individual Master options are not immediately updated\n";
    descriptionString += "on the hardware. Click the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForVibratoModSource(bool isForSpeed) {
    String descriptionString{ "" };
    String modType{ isForSpeed ? "speed" : "amplitude" };
    descriptionString += "Sets the source for modulating the\n";
    descriptionString += modType + " of low-frequency oscillator 3,\n";
    descriptionString += "which is dedicated to vibrato.\n";
    descriptionString += "Options: Off (no modulation), Lever 2,\n";
    descriptionString += "or Pedal 1. NOTE: Individual Master\n";
    descriptionString += "options are not immediately updated\n";
    descriptionString += "on the hardware. Click the PUSH button\n";
    descriptionString += "to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForVibratoSpeed() {
    String descriptionString{ "" };
    descriptionString += "Sets the cycle rate of low-frequency\n";
    descriptionString += "oscillator 3, which is dedicated to vibrato.\n";
    descriptionString += "Range: 0 (slowest) to 63 (fastest).\n";
    descriptionString += "NOTE: Individual Master options are not\n";
    descriptionString += "immediately updated on the hardware.\n";
    descriptionString += "Click the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForVibratoWaveType() {
    String descriptionString{ "" };
    descriptionString += "Sets the modulation wave type for low-frequency oscillator 3,\n";
    descriptionString += "which is dedicated to vibrato.\n";
    descriptionString += "TRI: Triangle - a periodic wave that steadily rises and falls between\n";
    descriptionString += "its minimum and maximum values.\n";
    descriptionString += "UPSAW: Up (positive) sawtooth - a periodic wave that rises steadily\n";
    descriptionString += "to the maximum value then abruptly falls to the minimum value.\n";
    descriptionString += "DNSAW: Down (negative) sawtooth - a periodic wave that falls steadily\n";
    descriptionString += "to the minimum value then abruptly rises to the maximum value.\n";
    descriptionString += "SQUAR: Square - a periodic wave that switches abruptly between the\n";
    descriptionString += "minimum and maximum values.\n";
    descriptionString += "RANDM: Random - an aperiodic wave that outputs a series of random values.\n";
    descriptionString += "NOISE: Noise - a much faster version of the random waveform.\n";
    descriptionString += "NOTE: Individual Master options are not immediately updated on the\n";
    descriptionString += "hardware. Click the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForVoiceChanges() {
    String descriptionString{ "" };
    descriptionString += "When set to on, incoming MIDI program change messages\n";
    descriptionString += "will switch the hardware to the specified patch number.\n";
    descriptionString += "It is recommended that this option be set to on for this\n";
    descriptionString += "plugin to operate properly. NOTE: Individual Master\n";
    descriptionString += "options are not immediately updated on the hardware.\n";
    descriptionString += "Click the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForVoiceMapInVoice(uint8 mapSlotNum) {
    String descriptionString{ "" };
    descriptionString += "When the Patch Map is enabled, a MIDI program change\n";
    descriptionString += "message calling program " + (String)mapSlotNum + " will load the patch selected\n";
    descriptionString += "here into the hardware instead. NOTE: Changes to the\n";
    descriptionString += "Patch Map will not be updated on the hardware until\n";
    descriptionString += "the PUSH button in the Master window is clicked.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForVoiceMapEcho() {
    String descriptionString{ "" };
    descriptionString += "When the Patch Map is enabled and this option is\n";
    descriptionString += "on, the hardware will send program changes to a\n";
    descriptionString += "device further on in the MIDI chain in accordance\n";
    descriptionString += "with the Patch Map settings. NOTE: Individual Master\n";
    descriptionString += "options are not immediately updated on the hardware.\n";
    descriptionString += "Click the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildForVoiceMap() {
    String descriptionString{ "" };
    descriptionString += "When enabled, incoming program change messages\n";
    descriptionString += "will load voices on the hardware according to\n";
    descriptionString += "the Patch Map. Click the EDIT button below to make\n";
    descriptionString += "changes to the Patch Map. NOTE: Individual Master\n";
    descriptionString += "options are not immediately updated on the hardware.\n";
    descriptionString += "Click the PUSH button to update all options.\n";
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

String GlobalParamDescription::buildFor_MIDI_Echo() {
    String descriptionString{ "" };
    descriptionString += "When set to on, patch changes and controller messages\n";
    descriptionString += "which come into the Matrix-6R are echoed through the MIDI\n";
    descriptionString += "Out port (normally they are only echoed via the MIDI Thru\n";
    descriptionString += "port). This allows for enhanced control of additional instru-\n";
    descriptionString += "ments further on in the MIDI chain. NOTE: Individual Master\n";
    descriptionString += "options are not immediately updated on the hardware. Click\n";
    descriptionString += "the PUSH button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildFor_MIDI_Mono() {
    String descriptionString{ "" };
    descriptionString += "When set to on, each of the six voices will be assigned a separate\n";
    descriptionString += "MIDI channel and will only respond to notes and controller messages\n";
    descriptionString += "coming in on that channel. Voice 1 is assigned to the Basic Channel\n";
    descriptionString += "and the subsequent voices increment the assigned channel by 1, e.g. if\n";
    descriptionString += "Voice 1 is assigned channel 1, voice 6 is assigned channel 6. Channel\n";
    descriptionString += "numbers higher than 16 wrap around to the start, e.g. if Voice 1 is\n";
    descriptionString += "assigned channel 12, voice 6 is assigned channel 1. This mode is\n";
    descriptionString += "especially useful with a MIDI guitar controller. NOTE: Individual Master\n";
    descriptionString += "options are not immediately updated on the hardware. Click the PUSH\n";
    descriptionString += "button to update all options.\n";
    return descriptionString;
}

String GlobalParamDescription::buildFor_SQUICK() {
    String descriptionString{ "" };
    descriptionString += "When editing parameters with the keypad on the hardware" + GUI::apostrophe + "s front panel,\n";
    descriptionString += "normally the numeral keys select the parameter number and the arrow\n";
    descriptionString += "keys change the parameter value. When SQUICK (" + GUI::openQuote + "Switch Quick" + GUI::closeQuote + ") is enabled,\n";
    descriptionString += "the arrow keys select the parameter number and the numeral keys change\n";
    descriptionString += "the parameter value. NOTE: Individual Master options are not immediately\n";
    descriptionString += "updated on the hardware. Click the PUSH button to update all options.\n";
    return descriptionString;
}
