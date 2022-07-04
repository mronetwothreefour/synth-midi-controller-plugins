#pragma once

#include <JuceHeader.h>

#include "ep_tree_InfoForExposedParameters.h"


class UnexposedParameters;

class ExposedParameters
{
public:
	InfoForExposedParameters info;
	UndoManager undoManager;
	AudioProcessorValueTreeState state;

	ExposedParameters() = delete;

	explicit ExposedParameters(AudioProcessor* processor);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParameters)
};