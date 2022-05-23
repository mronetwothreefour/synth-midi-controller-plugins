#pragma once

#include <JuceHeader.h>

#include "2_comp_ExposedParamControl.h"



class UnexposedParameters;

class ExposedParamControlsServer
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	std::vector<std::unique_ptr<ExposedParamControl>> controlsVector;

public:
	ExposedParamControlsServer() = delete;

	explicit ExposedParamControlsServer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void fillControlsVector();

public:
	ExposedParamControl* controlPtrFor(uint8 paramIndex) const;
	int paramIndexOutOfRange() const;
	void clearControlsVector();
	void rebuildControlsVector();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamControlsServer)
};