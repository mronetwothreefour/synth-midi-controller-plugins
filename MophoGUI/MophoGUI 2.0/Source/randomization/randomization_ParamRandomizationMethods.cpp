#include "randomization_ParamRandomizationMethods.h"

#include "randomization_Constants.h"
#include "../midi/midi_EditBufferDataMessage.h"
#include "../params/params_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../widgets_ControlsForParameters/widget_ControlTypes.h"

using namespace constants;



void ParamRandomizationMethods::randomizeUnlockedParameters(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
	voiceTransmissionOptions->setParamChangeEchoesAreBlocked();
	auto& info{ InfoForExposedParameters::get() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
		auto paramID{ info.IDfor(param) };
		auto paramIndex{ info.indexForParamID(paramID.toString()) };
		if (paramID != ID::arpegOnOff && paramID != ID::sequencerOnOff) {
			if (randomizationOptions->paramIsUnlocked(param)) {
				auto randomizationOptionsType{ info.randomizationOptionsTypeFor(param) };
				auto newValue{ (uint8)0 };
				if (randomizationOptionsType == RandomizationOptionsType::none)
					newValue = pickRandomValueForParam(paramIndex);
				if (randomizationOptionsType == RandomizationOptionsType::pitch)
					newValue = pickRandomPitchForParam(paramIndex, unexposedParams);
				if (randomizationOptionsType == RandomizationOptionsType::valueRange)
					pickRandomValueFromRangeForParam(paramIndex, unexposedParams);
				if (randomizationOptionsType == RandomizationOptionsType::oscShape)
					newValue = pickRandomOscShapeAndPulseWidthForParam(paramIndex, unexposedParams);
				if (randomizationOptionsType == RandomizationOptionsType::comboBoxes)
					newValue = pickRandomComboBoxItemForParam(paramIndex, unexposedParams);
				if (randomizationOptionsType == RandomizationOptionsType::lpfFreq)
					newValue = pickRandomLPFfreq(unexposedParams);
				if (randomizationOptionsType == RandomizationOptionsType::lfoFreq)
					newValue = pickRandomLFOfreqForParam(paramIndex, unexposedParams);
				if (randomizationOptionsType == RandomizationOptionsType::sequencerTrackStep)
					newValue = pickRandomSeqStepValueForParam(paramIndex, unexposedParams);
				if (randomizationOptionsType == RandomizationOptionsType::sequencerTrackStep && newValue == params::seqStepValueForRepeat) {
					auto paramIDforPreviousStep{ info.IDfor(paramIndex - (uint8)1) };
					auto previousStepValue{ exposedParams->getParameter(paramIDforPreviousStep)->getValue() };
					exposedParams->getParameter(paramID)->setValueNotifyingHost(previousStepValue);
				}
				else {
					auto maxValue{ (float)info.maxValueFor(paramIndex) };
					auto newNormalizedValue{ newValue / maxValue };
					exposedParams->getParameter(paramID)->setValueNotifyingHost(newNormalizedValue);
				}
			}
		}
	}
	randomizeArpAndSeqOnOffParameters(exposedParams, unexposedParams);
	EditBufferDataMessage::addEditBufferDataMessageToOutgoingMidiBuffers(exposedParams, unexposedParams->outgoingMidiBuffers_get());
	voiceTransmissionOptions->setParamChangeEchoesAreNotBlocked();
}

uint8 ParamRandomizationMethods::pickRandomValueForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto numberOfSteps{ info.numberOfStepsFor(paramIndex) };
	Random rndmNumGenerator{};
	auto newValue{ (int)floor(rndmNumGenerator.nextFloat() * numberOfSteps) };
	return (uint8)newValue;
}

uint8 ParamRandomizationMethods::pickRandomPitchForParam(uint8 paramIndex, UnexposedParameters* unexposedParams) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto& info{ InfoForExposedParameters::get() };
	auto maxPitch{ uint8(info.maxValueFor(paramIndex)) };
	Array<uint8> allowedPitches;
	for (uint8 pitch = 0; pitch <= maxPitch; ++pitch) {
		auto pitchIsAllowed{ randomizationOptions->pitchIsAllowedForParam(pitch, paramIndex) };
		if (pitchIsAllowed)
			allowedPitches.add(pitch);
	}
	auto numberOfAllowedPitches{ allowedPitches.size() };
	if (numberOfAllowedPitches == 0) {
		return maxPitch;
	}
	else {
		Random rndmNumGenerator{};
		auto newPitchIndex{ (int)floor(rndmNumGenerator.nextFloat() * numberOfAllowedPitches) };
		return allowedPitches[newPitchIndex];
	}
}

uint8 ParamRandomizationMethods::pickRandomValueFromRangeForParam(uint8 paramIndex, UnexposedParameters* unexposedParams) {
	Array<uint8> allowedValues;
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto minValueAllowed{ randomizationOptions->minValueAllowedForParam(paramIndex) };
	auto maxValueAllowed{ randomizationOptions->maxValueAllowedForParam(paramIndex) };
	for (auto val = minValueAllowed; val <= maxValueAllowed; ++val)
		allowedValues.add(val);
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	auto numberOfValueOptions{ allowedValues.size() };
	auto newValueIndex{ (int)floor(newFloat * numberOfValueOptions) };
	return allowedValues[newValueIndex];
}

uint8 ParamRandomizationMethods::pickRandomOscShapeAndPulseWidthForParam(uint8 paramIndex, UnexposedParameters* unexposedParams) {
	auto newShape{ pickRandomOscShapeIndexForParameter(paramIndex, unexposedParams) };
	if (newShape != (int)OscWaveShape::pulse)
		return newShape;
	else {
		auto newPulseWidth{ pickRandomPulseWidthForParam(paramIndex, unexposedParams) };
		return newShape + newPulseWidth;
	}
}

uint8 ParamRandomizationMethods::pickRandomOscShapeIndexForParameter(uint8 paramIndex, UnexposedParameters* unexposedParams) {
	Array<uint8> allowedShapeIndices;
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	for (auto shapeIndex = (uint8)OscWaveShape::off; shapeIndex <= (uint8)OscWaveShape::pulse; ++shapeIndex) {
		if (randomizationOptions->oscShapeIsAllowedForParam(shapeIndex, paramIndex))
			allowedShapeIndices.add(shapeIndex);
	}
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	auto numberOfShapeIndices{ allowedShapeIndices.size() };
	auto newShapeIndex{ (int)floor(newFloat * numberOfShapeIndices) };
	return allowedShapeIndices[newShapeIndex];
}

uint8 ParamRandomizationMethods::pickRandomPulseWidthForParam(uint8 paramIndex, UnexposedParameters* unexposedParams) {
	Array<uint8> allowedWidths;
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto minWidthAllowed{ randomizationOptions->minPulseWidthAllowedForParam(paramIndex) };
	auto maxWidthAllowed{ randomizationOptions->maxPulseWidthAllowedForParam(paramIndex) };
	for (auto width = minWidthAllowed; width <= maxWidthAllowed; ++width)
		allowedWidths.add(width);
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	auto numberOfWidthOptions{ allowedWidths.size() };
	auto newWidthIndex{ (int)floor(newFloat * numberOfWidthOptions) };
	return allowedWidths[newWidthIndex];
}

uint8 ParamRandomizationMethods::pickRandomComboBoxItemForParam(uint8 paramIndex, UnexposedParameters* unexposedParams) {
	Array<uint8> allowedItems;
	auto& info{ InfoForExposedParameters::get() };
	auto numberOfItems{ info.numberOfStepsFor(paramIndex) };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	for (auto item = 0; item < numberOfItems; ++item) {
		auto itemIsAllowed{ randomizationOptions->comboBoxItemIsAllowedForParam(item, paramIndex) };
		if (itemIsAllowed)
			allowedItems.add((uint8)item);
	}
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	auto numberOfAllowedItems{ allowedItems.size() };
	auto newItemIndex{ (int)floor(newFloat * numberOfAllowedItems) };
	return allowedItems[newItemIndex];
}

uint8 ParamRandomizationMethods::pickRandomLPFfreq(UnexposedParameters* unexposedParams) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	uint8 newFreq{ 0 };
	auto paramIndex{ InfoForExposedParameters::get().indexForParamID(ID::lpfFreq.toString()) };
	auto modeIsValueRange{ randomizationOptions->randomizationModeForLPFfreqIsValueRange() };
	if (modeIsValueRange) {
		newFreq = pickRandomValueFromRangeForParam(paramIndex, unexposedParams);
	}
	else
		newFreq = pickRandomPitchForParam(paramIndex, unexposedParams);
	return newFreq;
}

uint8 ParamRandomizationMethods::pickRandomLFOfreqForParam(uint8 paramIndex, UnexposedParameters* unexposedParams) {
	auto categoryForNewFreq{ pickRandomFreqCategoryForParam(paramIndex, unexposedParams) };
	uint8 newFreq{ 0 };
	if (categoryForNewFreq == LFOfreqCategory::unsynced)
		newFreq = pickRandomUnsyncedLFOfreqForParam(paramIndex, unexposedParams);
	if (categoryForNewFreq == LFOfreqCategory::pitched)
		newFreq = pickRandomPitchedLFOfreqForParam(paramIndex, unexposedParams);
	if (categoryForNewFreq == LFOfreqCategory::synced) {
		newFreq = pickRandomSyncedLFOfreqForParam(paramIndex, unexposedParams);
	}
	return newFreq;
}

LFOfreqCategory ParamRandomizationMethods::pickRandomFreqCategoryForParam(uint8 paramIndex, UnexposedParameters* unexposedParams) {
	Array<LFOfreqCategory> allowedFreqCategories;
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (randomizationOptions->unsyncedFreqAreAllowedForParam(paramIndex))
		allowedFreqCategories.add(LFOfreqCategory::unsynced);
	if (randomizationOptions->pitchedFreqAreAllowedForParam(paramIndex))
		allowedFreqCategories.add(LFOfreqCategory::pitched);
	if (randomizationOptions->syncedFreqAreAllowedForParam(paramIndex))
		allowedFreqCategories.add(LFOfreqCategory::synced);
	auto numberOfAllowedCategories{ allowedFreqCategories.size() };
	Random rndmNumGeneratorForCategory{};
	auto newCategoryFloat{ rndmNumGeneratorForCategory.nextFloat() };
	auto categoryIndex{ (int)floor(newCategoryFloat * numberOfAllowedCategories) };
	return allowedFreqCategories[categoryIndex];
}

uint8 ParamRandomizationMethods::pickRandomUnsyncedLFOfreqForParam(uint8 paramIndex, UnexposedParameters* unexposedParams) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto minUnsyncedFreq{ randomizationOptions->minUnsyncedFreqForParam(paramIndex) };
	auto maxUnsyncedFreq{ randomizationOptions->maxUnsyncedFreqForParam(paramIndex) };
	Array<uint8> allowedUnsyncedFreq;
	for (uint8 freq = minUnsyncedFreq; freq <= maxUnsyncedFreq; ++freq)
		allowedUnsyncedFreq.add(freq);
	auto numberOfAllowedFreq{ allowedUnsyncedFreq.size() };
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	auto newFreqIndex{ (int)floor(newFloat * numberOfAllowedFreq) };
	return allowedUnsyncedFreq[newFreqIndex];
}

uint8 ParamRandomizationMethods::pickRandomPitchedLFOfreqForParam(uint8 paramIndex, UnexposedParameters* unexposedParams) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	Array<uint8> allowedPitchedFreq;
	for (uint8 freq = 0; freq != (uint8)randomization::numberOfPitchedFreqForLFOs; ++freq) {
		auto pitchedFreqIsAllowed{ randomizationOptions->pitchIsAllowedForParam(freq, paramIndex) };
		if (pitchedFreqIsAllowed)
			allowedPitchedFreq.add(freq);
	}
	auto numberOfAllowedPitchedFreq{ allowedPitchedFreq.size() };
	auto newPitchedFreq{ (uint8)0 };
	if (numberOfAllowedPitchedFreq == 0)
		newPitchedFreq = uint8(randomization::numberOfPitchedFreqForLFOs - 1);
	else {
		Random rndmNumGenerator{};
		auto newFloat{ rndmNumGenerator.nextFloat() };
		auto newPitchedFreqIndex{ (int)floor(newFloat * numberOfAllowedPitchedFreq) };
		newPitchedFreq = allowedPitchedFreq[newPitchedFreqIndex];
	}
	auto newFreqWithOffset{ uint8(newPitchedFreq + params::firstPitchedLFOfreq) };
	return newFreqWithOffset;
}

uint8 ParamRandomizationMethods::pickRandomSyncedLFOfreqForParam(uint8 paramIndex, UnexposedParameters* unexposedParams) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	Array<uint8> allowedSyncedFreq;
	for (uint8 freq = 0; freq != (uint8)randomization::numberOfSyncedFreqForLFOs; ++freq) {
		auto syncedFreqIsAllowed{ randomizationOptions->syncedFreqIsAllowedForParam(freq, paramIndex) };
		if (syncedFreqIsAllowed)
			allowedSyncedFreq.add(freq);
	}
	auto numberOfAllowedSyncedFreq{ allowedSyncedFreq.size() };
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	auto newSyncedFreqIndex{ (int)floor(newFloat * numberOfAllowedSyncedFreq) };
	auto newSyncedFreq{ allowedSyncedFreq[newSyncedFreqIndex] };
	auto newSyncedFreqWithOffset{ uint8(newSyncedFreq + params::firstSyncedLFOfreq) };
	return newSyncedFreqWithOffset;
}

uint8 ParamRandomizationMethods::pickRandomSeqStepValueForParam(uint8 paramIndex, UnexposedParameters* unexposedParams) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString()};
	auto trackNum{ paramID.fromFirstOccurrenceOf("seqTrack", false, false).upToFirstOccurrenceOf("Step", false, false).getIntValue() };
	auto stepNum{ paramID.fromFirstOccurrenceOf("Step", false, false).getIntValue() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (trackNum == 1) {
		auto stepIsRest{ randomlyDecideIfStepInSeqTrack1IsRest(paramIndex, unexposedParams) };
		if (stepIsRest)
			return params::seqStepValueForRest;
	}
	auto  trackDestinationIsPitch{ randomizationOptions->trackDestinationIsAnOscPitchParameter(trackNum) };
	if (stepNum != 1) {
		auto stepIsRepeat{ randomlyDecideIfStepInSeqTrackIsRepeatValue(paramIndex, trackNum, unexposedParams) };
		if (stepIsRepeat)
			return params::seqStepValueForRepeat;
		auto stepIsReset{ randomlyDecideIfStepInSeqTrackIsReset(paramIndex, trackNum, unexposedParams) };
		if (stepIsReset)
			return params::seqStepValueForReset;
	}
	auto trackDestinationIsOscPitch{ randomizationOptions->trackDestinationIsAnOscPitchParameter(trackNum) };
	if (trackDestinationIsOscPitch) {
		auto newPitch{ pickRandomPitchForStepParamInTrack(paramIndex, trackNum, unexposedParams) };
		return newPitch;
	}
	else {
		auto newValue{ pickRandomValueFromRangeForStepParamInTrack(paramIndex, trackNum, unexposedParams) };
		return newValue;
	}
}

bool ParamRandomizationMethods::randomlyDecideIfStepInSeqTrack1IsRest(uint8 paramIndex, UnexposedParameters* unexposedParams) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	float probabilityOfRest{ 0.0f };
	auto trackEditModeIsAllSteps{ randomizationOptions->editModeForSeqTrackIsAllSteps(1) };
	if (trackEditModeIsAllSteps)
		probabilityOfRest = randomizationOptions->probabilityOfRestForAllStepsInSeqTrack1();
	else
		probabilityOfRest = randomizationOptions->probabilityOfRestForParam(paramIndex);
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	if (newFloat < probabilityOfRest)
		return true;
	else
		return false;
}

bool ParamRandomizationMethods::randomlyDecideIfStepInSeqTrackIsRepeatValue(uint8 paramIndex, int trackNum, UnexposedParameters* unexposedParams) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	float probabilityOfRepeat{ 0.0f };
	auto trackEditModeIsAllSteps{ randomizationOptions->editModeForSeqTrackIsAllSteps(trackNum) };
	if (trackEditModeIsAllSteps)
		probabilityOfRepeat = randomizationOptions->probabilityOfRepeatValueForAllStepsInSeqTrack(trackNum);
	else
		probabilityOfRepeat = randomizationOptions->probabilityOfRepeatValueForParam(paramIndex);
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	if (newFloat < probabilityOfRepeat)
		return true;
	else
		return false;
}

bool ParamRandomizationMethods::randomlyDecideIfStepInSeqTrackIsReset(uint8 paramIndex, int trackNum, UnexposedParameters* unexposedParams) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	float probabilityOfReset{ 0.0f };
	auto trackEditModeIsAllSteps{ randomizationOptions->editModeForSeqTrackIsAllSteps(trackNum) };
	if (trackEditModeIsAllSteps)
		probabilityOfReset = randomizationOptions->probabilityOfResetForAllStepsInSeqTrack(trackNum);
	else
		probabilityOfReset = randomizationOptions->probabilityOfResetForParam(paramIndex);
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	if (newFloat < probabilityOfReset)
		return true;
	else
		return false;
}

uint8 ParamRandomizationMethods::pickRandomPitchForStepParamInTrack(uint8 paramIndex, int trackNum, UnexposedParameters* unexposedParams) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto& info{ InfoForExposedParameters::get() };
	auto maxPitch{ params::maxValueForSeqTrackStep };
	auto trackEditModeIsAllSteps{ randomizationOptions->editModeForSeqTrackIsAllSteps(trackNum) };
	Array<uint8> allowedPitches;
	for (uint8 pitch = 0; pitch <= maxPitch; ++pitch) {
		auto pitchIsAllowed{ (bool)false };
		if (trackEditModeIsAllSteps)
			pitchIsAllowed = randomizationOptions->pitchIsAllowedForAllStepsInSeqTrack(pitch, trackNum);
		else
			pitchIsAllowed = randomizationOptions->pitchIsAllowedForParam(pitch, paramIndex);
		if (pitchIsAllowed)
			allowedPitches.add(pitch);
	}
	auto numberOfAllowedPitches{ allowedPitches.size() };
	if (numberOfAllowedPitches == 0) {
		return maxPitch;
	}
	else {
		Random rndmNumGenerator{};
		auto newPitchIndex{ (int)floor(rndmNumGenerator.nextFloat() * numberOfAllowedPitches) };
		return allowedPitches[newPitchIndex];
	}
}

uint8 ParamRandomizationMethods::pickRandomValueFromRangeForStepParamInTrack(uint8 paramIndex, int trackNum, UnexposedParameters* unexposedParams) {
	Array<uint8> allowedValues;
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto trackEditModeIsAllSteps{ randomizationOptions->editModeForSeqTrackIsAllSteps(trackNum) };
	auto minValueAllowed{ (uint8)0 };
	auto maxValueAllowed{ params::maxValueForSeqTrackStep };
	if (trackEditModeIsAllSteps) {
		minValueAllowed = randomizationOptions->minValueForAllStepsInSeqTrack(trackNum);
		maxValueAllowed = randomizationOptions->maxValueForAllStepsInSeqTrack(trackNum);
	}
	else {
		minValueAllowed = randomizationOptions->minValueAllowedForParam(paramIndex);
		maxValueAllowed = randomizationOptions->maxValueAllowedForParam(paramIndex);
	}
	for (auto val = minValueAllowed; val <= maxValueAllowed; ++val)
		allowedValues.add(val);
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	auto numberOfValueOptions{ allowedValues.size() };
	auto newValueIndex{ (int)floor(newFloat * numberOfValueOptions) };
	return allowedValues[newValueIndex];
}

void ParamRandomizationMethods::randomizeArpAndSeqOnOffParameters(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto& info{ InfoForExposedParameters::get() };
	auto arpegOnOffIndex{ info.indexForParamID("arpegOnOff") };
	auto sequencerOnOffIndex{ info.indexForParamID("sequencerOnOff") };
	Random rndmNumGenerator{};
	auto newNormalizedValue{ rndmNumGenerator.nextFloat() };
	if (randomizationOptions->paramIsUnlocked(arpegOnOffIndex) && randomizationOptions->paramIsUnlocked(sequencerOnOffIndex)) {
		auto arpSeqOnOffOption{ (int)std::floor(newNormalizedValue * 3) };
		switch (arpSeqOnOffOption) {
		case 0: {
			exposedParams->getParameter("arpegOnOff")->setValueNotifyingHost(0.0);
			exposedParams->getParameter("sequencerOnOff")->setValueNotifyingHost(0.0);
			break;
		}
		case 1: {
			exposedParams->getParameter("arpegOnOff")->setValueNotifyingHost(1.0);
			exposedParams->getParameter("sequencerOnOff")->setValueNotifyingHost(0.0);
			break;
		}
		case 2: {
			exposedParams->getParameter("arpegOnOff")->setValueNotifyingHost(0.0);
			exposedParams->getParameter("sequencerOnOff")->setValueNotifyingHost(1.0);
			break;
		}
		default:
			break;
		}
	}
	if (randomizationOptions->paramIsUnlocked(arpegOnOffIndex) && randomizationOptions->paramIsLocked(sequencerOnOffIndex)) {
		auto arpOnOffOption{ std::round(newNormalizedValue) };
		exposedParams->getParameter("arpegOnOff")->setValueNotifyingHost(arpOnOffOption);
	}
	if (randomizationOptions->paramIsLocked(arpegOnOffIndex) && randomizationOptions->paramIsUnlocked(sequencerOnOffIndex)) {
		auto seqOnOffOption{ std::round(newNormalizedValue) };
		exposedParams->getParameter("sequencerOnOff")->setValueNotifyingHost(seqOnOffOption);
	}
}
