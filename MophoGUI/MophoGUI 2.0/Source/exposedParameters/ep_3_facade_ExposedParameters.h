#pragma once

#include <JuceHeader.h>

#include "ep_1_tree_InfoForExposedParameters.h"
#include "ep_2_build_ExposedParamsLayout.h"
#include "ep_2_tree_ExposedParamsRandomizationOptions.h"

using Layout = ExposedParametersLayout;
using Randomization = ExposedParamsRandomizationOptions;
using State = AudioProcessorValueTreeState;

class ExposedParameters
{
public:
	std::unique_ptr <InfoForExposedParameters> info;
	std::unique_ptr<State> state;
	std::unique_ptr <Randomization> randomization;
	UndoManager undoManager;

	ExposedParameters() = delete;

	explicit ExposedParameters(AudioProcessor* processor) :
		info{ new InfoForExposedParameters },
		state{ new State{ *processor, &undoManager, "exposedParams", Layout::build(info.get()) } },
		randomization{ new Randomization{ info.get() } }
	{
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParameters)
};