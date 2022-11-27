#pragma once

#include <JuceHeader.h>

struct MainWindowButtonDescription
{
	static String buildForActivateQuickEdit();
	static String buildForShowGlobalParamsLayer();
	static String buildForShowRandomizationLayer();
	static String buildForShowSplitsLayer();
	static String buildForShowVoicesBanksLayer();
	static String buildForPull();
	static String buildForPush();
};