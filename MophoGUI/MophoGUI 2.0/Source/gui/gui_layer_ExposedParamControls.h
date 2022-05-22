#pragma once

#include <JuceHeader.h>

#include "../exposedParamControls/3_vector_ExposedParamControlsServer.h"



class UnexposedParameters;

class GUI_Layer_ExposedParamControls :
	public Component,
	private ExposedParamControlsServer
{
public:
	GUI_Layer_ExposedParamControls() = delete;

	GUI_Layer_ExposedParamControls(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	~GUI_Layer_ExposedParamControls() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_ExposedParamControls)
};