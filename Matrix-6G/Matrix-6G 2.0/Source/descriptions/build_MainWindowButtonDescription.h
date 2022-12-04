#pragma once

#include <JuceHeader.h>

struct MainWindowButtonDescription
{
	static String buildForActivateQuickEdit();
	static String buildForHyperlink();
	static String buildForPull();
	static String buildForPush();
	static String buildForRedo();
	static String buildForShowGlobalParamsLayer();
	static String buildForShowRandomizationLayer();
	static String buildForShowSplitsLayer();
	static String buildForShowVoicesBanksLayer();
	static String buildForUndo();
};