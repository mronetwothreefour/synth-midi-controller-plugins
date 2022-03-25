#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

struct ParamRandomizationMethods {
	static void randomizeUnlockedParameters(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	static void randomizeParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams);
	static void randomizeOscPitchParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	static void randomizeOscShapeParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams);
	static void randomizeLFOfreqParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams);
	static void randomizeSeqStepParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams);
	static void randomizeArpAndSeqOnOffParameters(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
};