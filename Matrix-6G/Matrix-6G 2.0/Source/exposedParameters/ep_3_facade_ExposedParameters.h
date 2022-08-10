#pragma once

#include <JuceHeader.h>

#include "ep_1_tree_InfoForExposedParameters.h"
#include "ep_2_build_ExposedParamsLayout.h"

using Layout = ExposedParametersLayout;
using State = AudioProcessorValueTreeState;

class UnexposedParameters;

class ExposedParameters
{
public:
	std::unique_ptr <InfoForExposedParameters> info;
	std::unique_ptr<State> state;
	//std::unique_ptr <Randomization> randomization;
	//std::unique_ptr<Randomize> randomize;
	UndoManager undoManager;

	ExposedParameters() = delete;

	ExposedParameters(AudioProcessor* processor, UnexposedParameters* /*unexposedParams*/) :
		info{ new InfoForExposedParameters },
		state{ new State{ *processor, &undoManager, "exposedParams", Layout::build(info.get()) } }/*,
		randomization{ new Randomization{ info.get() } },
		randomize{ new Randomize{ this, unexposedParams } }*/
	{
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParameters)
};