#pragma once

#include <JuceHeader.h>



struct MainWindowButtonDescription
{
	static String buildForClearSeqTrack(int trackNum);
	static String buildForEditBufferRead();
	static String buildForEditBufferWrite();
	static String buildForHyperlink();
	static String buildForRedo();
	static String buildForShowGlobalParamsLayer();
	static String buildForShowRandomizationLayer();
	static String buildForShowVoiceNameEditor();
	static String buildForShowVoicesBanksLayer();
	static String buildForUndo();
	static String buildForVoiceNameEditor();
};