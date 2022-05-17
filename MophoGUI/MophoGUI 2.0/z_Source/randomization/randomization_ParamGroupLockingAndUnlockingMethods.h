#pragma once

#include <JuceHeader.h>



class RandomizationComponent;

struct ParamGroupLockingAndUnlockingMethods {
	static void lockOrUnlockAllParameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked);
	static void lockOrUnlockAllOscillatorParameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked);
	static void lockOrUnlockAllLPFparameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked);
	static void lockOrUnlockAllVCAparameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked);
	static void lockOrUnlockAllEnv3Parameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked);
	static void lockOrUnlockAllModulatorParameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked);
	static void lockOrUnlockAllLFOparameters(int lfoNum, RandomizationComponent* randomizationComponent, bool shouldBeLocked);
	static void lockOrUnlockAllMIDIcontrollerParameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked);
	static void lockOrUnlockAllSeqTrackParameters(int trackNum, RandomizationComponent* randomizationComponent, bool shouldBeLocked);
	static void lockOrUnlockAllKnobAssignParameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked);
	static void lockOrUnlockAllPushItParameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked);
	static void lockOrUnlockAllVoiceNameCharacters(RandomizationComponent* randomizationComponent, bool shouldBeLocked);
};