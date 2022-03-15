#include "randomization_ParamGroupLockingAndUnlockingMethods.h"

#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../randomization/RandomizationComponent.h"

using namespace constants;




void ParamGroupLockingAndUnlockingMethods::lockAllParameters(RandomizationComponent* randomizationComponent) {
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
		randomizationComponent->paramLockToggleButtons[param].setToggleState(true, dontSendNotification);
	}
}

void ParamGroupLockingAndUnlockingMethods::unlockAllParameters(RandomizationComponent* randomizationComponent) {
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
		randomizationComponent->paramLockToggleButtons[param].setToggleState(false, dontSendNotification);
	}
}

void ParamGroupLockingAndUnlockingMethods::lockAllOscillatorParameters(RandomizationComponent* randomizationComponent) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(ID::param000_osc1_Pitch.toString()) };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param001_osc1_Fine.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param002_osc1_Shape.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param003_osc1_Glide.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param004_osc1_KeyTrack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param005_osc1_SubLevel.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param006_osc2_Pitch.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param007_osc2_Fine.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param008_osc2_Shape.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param009_osc2_Glide.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param010_osc2_KeyTrack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param011_osc2_SubLevel.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param012_oscSync.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param014_oscSlop.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param017_oscMix.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param018_noiseLevel.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
}

void ParamGroupLockingAndUnlockingMethods::unlockAllOscillatorParameters(RandomizationComponent* randomizationComponent) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(ID::param000_osc1_Pitch.toString()) };
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param001_osc1_Fine.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param002_osc1_Shape.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param003_osc1_Glide.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param004_osc1_KeyTrack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param005_osc1_SubLevel.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param006_osc2_Pitch.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param007_osc2_Fine.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param008_osc2_Shape.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param009_osc2_Glide.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param010_osc2_KeyTrack.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param011_osc2_SubLevel.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param012_oscSync.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param014_oscSlop.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param017_oscMix.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	paramIndex = info.indexForParamID(ID::param018_noiseLevel.toString());
	randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
}

void ParamGroupLockingAndUnlockingMethods::lockAllSeqTrackParameters(int trackNum, RandomizationComponent* randomizationComponent) {
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
	randomizationComponent->paramLockToggleButtons[destParamIndex].setToggleState(true, dontSendNotification);
	for (auto step = 1; step != 17; ++step) {
		auto paramNumString{ "param" + (String)(params::paramNumForSeqTrack1Step1 + ((trackNum - 1) * 16) + (step - 1)) };
		auto stepParamIndex{ info.indexForParamID(paramNumString + "_track" + (String)trackNum + "Step" + (String)step) };
		randomizationComponent->paramLockToggleButtons[stepParamIndex].setToggleState(true, dontSendNotification);
	}
}

void ParamGroupLockingAndUnlockingMethods::unlockAllSeqTrackParameters(int trackNum, RandomizationComponent* randomizationComponent) {
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
	randomizationComponent->paramLockToggleButtons[destParamIndex].setToggleState(false, dontSendNotification);
	for (auto step = 1; step != 17; ++step) {
		auto paramNumString{ "param" + (String)(params::paramNumForSeqTrack1Step1 + ((trackNum - 1) * 16) + (step - 1)) };
		auto stepParamIndex{ info.indexForParamID(paramNumString + "_track" + (String)trackNum + "Step" + (String)step) };
		randomizationComponent->paramLockToggleButtons[stepParamIndex].setToggleState(false, dontSendNotification);
	}
}

void ParamGroupLockingAndUnlockingMethods::lockAllVoiceNameCharacters(RandomizationComponent* randomizationComponent) {
	auto& info{ InfoForExposedParameters::get() };
	for (auto charNum = 0; charNum != 16; ++charNum) {
		auto paramNumString{ "param" + (String)(params::paramNumFor1stNameChar + charNum) };
		auto charNumString{ (String)(charNum + 1) };
		auto paramIndex{ info.indexForParamID(paramNumString + "_nameChar" + charNumString) };
		randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	}
}

void ParamGroupLockingAndUnlockingMethods::unlockAllVoiceNameCharacters(RandomizationComponent* randomizationComponent) {
	auto& info{ InfoForExposedParameters::get() };
	for (auto charNum = 0; charNum != 16; ++charNum) {
		auto paramNumString{ "param" + (String)(params::paramNumFor1stNameChar + charNum) };
		auto charNumString{ (String)(charNum + 1) };
		auto paramIndex{ info.indexForParamID(paramNumString + "_nameChar" + charNumString) };
		randomizationComponent->paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	}
}
