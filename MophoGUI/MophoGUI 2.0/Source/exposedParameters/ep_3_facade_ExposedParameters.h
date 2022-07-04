#pragma once

#include <JuceHeader.h>

#include "ep_1_tree_InfoForExposedParameters.h"
#include "ep_2_build_ExposedParamsLayout.h"
#include "ep_2_func_ExposedParamsRandomizationMethods.h"
#include "ep_2_tree_ExposedParamsRandomizationOptions.h"

using Layout = ExposedParametersLayout;
using Randomize = ExposedParamsRandomizationMethods;
using Randomization = ExposedParamsRandomizationOptions;
using State = AudioProcessorValueTreeState;


class ExposedParameters
{
public:
	std::unique_ptr<AudioProcessorValueTreeState> state;
	std::unique_ptr<Randomize> randomize;
	std::unique_ptr <ExposedParamsRandomizationOptions> randomization;
	std::unique_ptr <InfoForExposedParameters> info;
	UndoManager undoManager;

	ExposedParameters() = delete;

	explicit ExposedParameters(AudioProcessor* processor) :
		info{ new InfoForExposedParameters }
	{
		state.reset(new State{ *processor, &undoManager, "exposedParams", Layout::build(info.get()) });
		randomize.reset(new Randomize{ this });
		randomization.reset(new Randomization{ info.get() });
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParameters)
};