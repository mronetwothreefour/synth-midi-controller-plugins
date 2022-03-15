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
	auto paramIndex{ info.indexForParamID(ID::param000_osc1_Pitch.toString()) };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param001_osc1_Fine.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param002_osc1_Shape.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param003_osc1_Glide.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param004_osc1_KeyTrack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param005_osc1_SubLevel.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param006_osc2_Pitch.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param007_osc2_Fine.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param008_osc2_Shape.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param009_osc2_Glide.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param010_osc2_KeyTrack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param011_osc2_SubLevel.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param012_oscSync.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param014_oscSlop.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param017_oscMix.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param018_noiseLevel.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllLPFparameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(ID::param020_lpfFreq.toString()) };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param021_lpfReso.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param022_lpfKeyAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param023_lpfFMamount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param024_lpfType.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param025_lpfEnvAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param026_lpfVelAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param027_lpfDelay.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param028_lpfAttack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param029_lpfDecay.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param030_lpfSustain.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param031_lpfRelease.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllVCAparameters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(ID::param032_vcaLevel.toString()) };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param033_vcaEnvAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param034_vcaVelAmount.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param035_vcaDelay.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param036_vcaAttack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param037_vcaDecay.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param038_vcaSustain.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param039_vcaRelease.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param040_voiceVolume.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllSeqTrackParameters(int trackNum, RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	uint8 destParamIndex{ 0 };
	switch (trackNum)
	{
	case 1:
		destParamIndex = info.indexForParamID(ID::param101_SeqTrack1Dest.toString());
		break;
	case 2:
		destParamIndex = info.indexForParamID(ID::param102_SeqTrack2Dest.toString());
		break;
	case 3:
		destParamIndex = info.indexForParamID(ID::param103_SeqTrack3Dest.toString());
		break;
	case 4:
		destParamIndex = info.indexForParamID(ID::param104_SeqTrack4Dest.toString());
		break;
	default:
		break;
	}
	randomizationComponent->paramLockToggleButtons[destParamIndex].setToggleState(shouldBeLocked, dontSendNotification);
	for (auto step = 1; step != 17; ++step) {
		auto paramNumString{ "param" + (String)(params::paramNumForSeqTrack1Step1 + ((trackNum - 1) * 16) + (step - 1)) };
		auto stepParamIndex{ info.indexForParamID(paramNumString + "_track" + (String)trackNum + "Step" + (String)step) };
		randomizationComponent->paramLockToggleButtons[stepParamIndex].setToggleState(shouldBeLocked, dontSendNotification);
	}
}

void ParamGroupLockingAndUnlockingMethods::lockOrUnlockAllVoiceNameCharacters(RandomizationComponent* randomizationComponent, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	for (auto charNum = 0; charNum != 16; ++charNum) {
		auto paramNumString{ "param" + (String)(params::paramNumFor1stNameChar + charNum) };
		auto charNumString{ (String)(charNum + 1) };
		auto paramIndex{ info.indexForParamID(paramNumString + "_nameChar" + charNumString) };
		randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(shouldBeLocked, dontSendNotification);
	}
}

