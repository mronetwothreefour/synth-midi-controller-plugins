#pragma once

#include <JuceHeader.h>

#include "../guiRenderers/guiRenderer_ForKnobWaveShapes.h"



enum class lfoFreqCategory {
	unsynced = 0,
	pitched,
	synced
};

class UnexposedParameters;

struct ParamRandomizationMethods {
	static void randomizeUnlockedParameters(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	static void randomizeParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams);
	static void randomizePitchParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	static void randomizeValueRangeParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	static uint8 pickRandomValueFromRangeForParam(uint8 paramIndex, UnexposedParameters* unexposedParams);
	static void randomizeOscShapeParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams, UnexposedParameters * unexposedParams);
	static OscWaveShape pickRandomOscShapeForParameter(uint8 paramIndex, UnexposedParameters* unexposedParams);
	static float pickRandomPulseWidthForParam(uint8 paramIndex, UnexposedParameters* unexposedParams);
	//static void randomizeLFOfreqParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	//static lfoFreqCategory randomlyPickFreqCategoryForLFO(int lfoNum, UnexposedParameters* unexposedParams);
	//static uint8 randomlyPickUnsyncedFreqForLFO(int lfoNum, UnexposedParameters* unexposedParams);
	//static uint8 randomlyPickPitchedFreqForLFO(int lfoNum, UnexposedParameters* unexposedParams);
	//static uint8 randomlyPickSyncedFreqForLFO(int lfoNum, UnexposedParameters* unexposedParams);
	//static void randomizeSeqStepParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	static void randomizeArpAndSeqOnOffParameters(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
};