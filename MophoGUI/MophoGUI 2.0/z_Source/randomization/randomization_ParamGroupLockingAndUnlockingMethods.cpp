#include "randomization_ParamGroupLockingAndUnlockingMethods.h"

#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../randomization/RandomizationComponent.h"

using namespace constants;




void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllParameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	for (uint8 paramIndex = 0; paramIndex != params::numberOfExposedParams; ++paramIndex) {
		randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	}
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllOscillatorParameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(ID::osc1_Pitch.toString()) };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::osc1_Fine.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::osc1_Shape.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::osc1_Glide.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::osc1_KeyTrack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::osc1_SubLevel.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::osc2_Pitch.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::osc2_Fine.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::osc2_Shape.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::osc2_Glide.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::osc2_KeyTrack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::osc2_SubLevel.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::oscSync.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::oscSlop.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::oscMix.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::noiseLevel.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllLPFparameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(ID::lpfFreq.toString()) };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::lpfReso.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::lpfKeyAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::lpfFMamount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::lpfType.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::lpfEnvAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::lpfVelAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::lpfDelay.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::lpfAttack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::lpfDecay.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::lpfSustain.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::lpfRelease.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllVCAparameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(ID::vcaLevel.toString()) };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::vcaEnvAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::vcaVelAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::vcaDelay.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::vcaAttack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::vcaDecay.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::vcaSustain.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::vcaRelease.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::voiceVolume.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllEnv3Parameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(ID::env3Destination.toString()) };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::env3Amount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::env3VelAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::env3Delay.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::env3Attack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::env3Decay.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::env3Sustain.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::env3Release.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::env3Repeat.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllModulatorParameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	for (auto i = 0; i != 4; ++i) {
		auto paramIndex{ info.indexForParamID("mod" + (String)(i + 1) + "Source") };
		randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
		paramIndex = info.indexForParamID("mod" + (String)(i + 1) + "Amount");
		randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
		paramIndex = info.indexForParamID("mod" + (String)(i + 1) + "Destination");
		randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	}
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllLFOparameters(int lfoNum, RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID("lfo" + (String)lfoNum + "Freq") };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID("lfo" + (String)lfoNum + "Shape");
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID("lfo" + (String)lfoNum + "Amount");
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID("lfo" + (String)lfoNum + "Destination");
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID("lfo" + (String)lfoNum + "KeySync");
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllMIDIcontrollerParameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(ID::modWheelAmount.toString()) };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::modWheelDest.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::pressureAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::pressureDest.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::breathAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::breathDest.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::velocityAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::velocityDest.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::footPedalAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::footPedalDest.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllSeqTrackParameters(int trackNum, RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	uint8 destParamIndex{ 0 };
	switch (trackNum)
	{
	case 1:
		destParamIndex = info.indexForParamID(ID::seqTrack1Dest.toString());
		break;
	case 2:
		destParamIndex = info.indexForParamID(ID::seqTrack2Dest.toString());
		break;
	case 3:
		destParamIndex = info.indexForParamID(ID::seqTrack3Dest.toString());
		break;
	case 4:
		destParamIndex = info.indexForParamID(ID::seqTrack4Dest.toString());
		break;
	default:
		break;
	}
	randomizationComponent->paramLockToggleButtons[destParamIndex].setToggleState(shouldBeLocked, sendNotification);
	for (auto step = 1; step != 17; ++step) {
		auto stepParamIndex{ info.indexForParamID("seqTrack" + (String)trackNum + "Step" + (String)step) };
		randomizationComponent->paramLockToggleButtons[stepParamIndex].setToggleState(shouldBeLocked, sendNotification);
	}
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllKnobAssignParameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	for (auto knobNum = 1; knobNum != 5; ++knobNum) {
		auto paramIndex{ info.indexForParamID("assignKnob" + (String)knobNum) };
		randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	}
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllPushItParameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(ID::pushItPitch.toString()) };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::pushItVelocity.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	paramIndex = info.indexForParamID(ID::pushItMode.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllVoiceNameCharacters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	for (auto charNum = 0; charNum != 16; ++charNum) {
		auto charNumString{ (String)(charNum + 1) };
		auto paramIndex{ info.indexForParamID("nameChar" + charNumString) };
		randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, sendNotification);
	}
}

