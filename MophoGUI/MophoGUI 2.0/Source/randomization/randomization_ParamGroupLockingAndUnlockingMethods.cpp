#include "randomization_ParamGroupLockingAndUnlockingMethods.h"

#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../randomization/RandomizationComponent.h"

using namespace constants;




void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllParameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
		randomizationComponent->paramLockToggleButtons[param].setToggleState(shouldBeLocked, dontSendNotification);
	}
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllOscillatorParameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(ID::osc1_Pitch.toString()) };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::osc1_Fine.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::osc1_Shape.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::osc1_Glide.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::osc1_KeyTrack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::osc1_SubLevel.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::osc2_Pitch.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::osc2_Fine.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::osc2_Shape.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::osc2_Glide.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::osc2_KeyTrack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::osc2_SubLevel.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::oscSync.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::oscSlop.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::oscMix.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::noiseLevel.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllLPFparameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(ID::lpfFreq.toString()) };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::lpfReso.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::lpfKeyAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::lpfFMamount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::lpfType.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::lpfEnvAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::lpfVelAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::lpfDelay.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::lpfAttack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::lpfDecay.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::lpfSustain.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::lpfRelease.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllVCAparameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(ID::vcaLevel.toString()) };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::vcaEnvAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::vcaVelAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::vcaDelay.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::vcaAttack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::vcaDecay.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::vcaSustain.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::vcaRelease.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::voiceVolume.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllEnv3Parameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(ID::env3Destination.toString()) };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::env3Amount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::env3VelAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::env3Delay.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::env3Attack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::env3Decay.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::env3Sustain.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::env3Release.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::env3Repeat.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllLFOparameters(int lfoNum, RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID("lfo" + (String)lfoNum + "Freq") };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID("lfo" + (String)lfoNum + "Shape");
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID("lfo" + (String)lfoNum + "Amount");
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID("lfo" + (String)lfoNum + "Destination");
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID("lfo" + (String)lfoNum + "KeySync");
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllSeqTrackParameters(int trackNum, RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	uint8 destParamIndex{ 0 };
	switch (trackNum)
	{
	case 1:
		destParamIndex = info.indexForParamID(ID::SeqTrack1Dest.toString());
		break;
	case 2:
		destParamIndex = info.indexForParamID(ID::SeqTrack2Dest.toString());
		break;
	case 3:
		destParamIndex = info.indexForParamID(ID::SeqTrack3Dest.toString());
		break;
	case 4:
		destParamIndex = info.indexForParamID(ID::SeqTrack4Dest.toString());
		break;
	default:
		break;
	}
	randomizationComponent->paramLockToggleButtons[destParamIndex].setToggleState(shouldBeLocked, dontSendNotification);
	for (auto step = 1; step != 17; ++step) {
		auto stepParamIndex{ info.indexForParamID("seqTrack" + (String)trackNum + "Step" + (String)step) };
		randomizationComponent->paramLockToggleButtons[stepParamIndex].setToggleState(shouldBeLocked, dontSendNotification);
	}
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllVoiceNameCharacters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	for (auto charNum = 0; charNum != 16; ++charNum) {
		auto charNumString{ (String)(charNum + 1) };
		auto paramIndex{ info.indexForParamID("nameChar" + charNumString) };
		randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	}
}

