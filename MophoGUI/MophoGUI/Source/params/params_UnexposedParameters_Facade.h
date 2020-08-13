#pragma once

#include <JuceHeader.h>

#include "params_UnexposedTooltipOptions.h"



class UnexposedParameters
{
	std::unique_ptr<TooltipOptions> tooltipOptions;
	std::unique_ptr<UndoManager> undoManager;

public:
	UnexposedParameters();
	TooltipOptions* tooltipOptions_get();
	UndoManager* undoManager_get();
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};

