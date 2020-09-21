MophoGUI was programmed in Microsoft Visual Studio 2019 using the Juce 6 Framework.
The Visual Studio solution file can be found in \Builds\VisualStudio2019\MophoGUI.sln
The project's C++ files are stored in the Source folder.

Proper functioning of this plugin required a few unofficial modifications
to the Juce Framework code, specifically to line 91 of juce_PopupMenu.cpp and
to lines 548 & 549 of juce_VST3Common.h. You can see these changes in my
fork off of the Juce repo at https://github.com/mronetwothreefour/JUCE

The build configurations make use of the preprocessor definition
HOST_DOES_NOT_ADD_F0_AND_F7. This needs to be true for the plugin to work
properly in Reaper, and false for the plugin to work properly in Juce's
AudioPluginHost. Either version will function properly in Cubase. These
are the only hosts known to be compatible with MophoGUI.vst3 at this time.

=============================================================================
 THE CODE FOR MOPHOGUI IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL
 WARRANTIES, WHETHER EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND
 FITNESS FOR PURPOSE, ARE DISCLAIMED.
=============================================================================

The code in the Source folder of this project is open-source and you are free 
to use it however you see fit under the GPL v3 license. However, please credit
Mister 1-2-3-4 Programming if you make use of substantial chunks of this code
in your own project(s), and do not redistribute it without permission. Also, 
if you find this code useful, please consider making a donation to support
further development at https://programming.mr1234.com/


