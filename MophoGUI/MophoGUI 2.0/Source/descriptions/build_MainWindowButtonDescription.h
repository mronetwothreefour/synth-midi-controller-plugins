#pragma once

#include <JuceHeader.h>



struct MainWindowButtonDescription
{
	static String buildFor_ClearSeqTrack(int trackNum);
	static String buildFor_EditBufferRead();
	static String buildFor_EditBufferWrite();
	static String buildFor_Hyperlink();
	static String buildFor_Redo();
	static String buildFor_ShowGlobalParamsLayer();
	static String buildFor_ShowVoiceNameEditor();
	static String buildFor_ShowVoicesBanksLayer();
	static String buildFor_Undo();
	static String buildFor_VoiceNameEditor();
};