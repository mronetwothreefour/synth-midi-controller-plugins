#pragma once

#include <JuceHeader.h>



class RandomizationComponent;

struct ParamGroupLockingAndUnlockingMethods {
	static void lockAllOscillatorParameters(RandomizationComponent* randomizationComponent);
	static void unlockAllOscillatorParameters(RandomizationComponent* randomizationComponent);
	static void lockAllVoiceNameCharacters(RandomizationComponent* randomizationComponent);
	static void unlockAllVoiceNameCharacters(RandomizationComponent* randomizationComponent);
};