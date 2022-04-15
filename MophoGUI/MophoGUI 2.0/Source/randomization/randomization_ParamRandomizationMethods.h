#pragma once

#include <JuceHeader.h>

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
	static void randomizeOscPitchParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	static void randomizeOscShapeParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams);
	//static void randomizeLFOfreqParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	//static lfoFreqCategory randomlyPickFreqCategoryForLFO(int lfoNum, UnexposedParameters* unexposedParams);
	//static uint8 randomlyPickUnsyncedFreqForLFO(int lfoNum, UnexposedParameters* unexposedParams);
	//static uint8 randomlyPickPitchedFreqForLFO(int lfoNum, UnexposedParameters* unexposedParams);
	//static uint8 randomlyPickSyncedFreqForLFO(int lfoNum, UnexposedParameters* unexposedParams);
	//static void randomizeSeqStepParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	static void randomizeArpAndSeqOnOffParameters(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
};