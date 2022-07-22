#pragma once

#include <JuceHeader.h>

#include "ep_1_tree_InfoForExposedParameters.h"
#include "ep_2_build_ExposedParamsLayout.h"

using Layout = ExposedParametersLayout;
using State = AudioProcessorValueTreeState;

class ExposedParameters
{
public:
	std::unique_ptr <InfoForExposedParameters> info;
	std::unique_ptr<AudioProcessorValueTreeState> state;
	UndoManager undoManager;

	ExposedParameters() = delete;

	explicit ExposedParameters(AudioProcessor* processor) :
		info{ new InfoForExposedParameters },
		state{ new State{ *processor, &undoManager, "exposedParams", Layout::build(info.get()) } }
	{
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParameters)
};