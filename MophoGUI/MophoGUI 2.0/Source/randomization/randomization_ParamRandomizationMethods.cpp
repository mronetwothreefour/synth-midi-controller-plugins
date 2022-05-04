#include "randomization_ParamRandomizationMethods.h"

#include "randomization_Constants.h"
#include "../midi/midi_EditBufferDataMessage.h"
#include "../params/params_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_RandomizationOptions.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../widgets_ControlsForParameters/widget_ControlTypes.h"

using namespace constants;



ParamRandomizationMethods::ParamRandomizationMethods(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
}

void ParamRandomizationMethods::randomizeAllUnlockedParameters() {
	auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
	auto& info{ InfoForExposedParameters::get() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (randomizationOptions->transmissionMethodIsSysEx()) {
		for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
			voiceTransmissionOptions->setParamChangeEchoesAreBlocked();
			auto paramID{ info.IDfor(param) };
			auto paramIndex{ info.indexForParamID(paramID.toString()) };
			if (paramID != ID::arpegOnOff && paramID != ID::sequencerOnOff) {
				if (randomizationOptions->paramIsUnlocked(param)) {
					auto randomizationOptionsType{ info.randomizationOptionsTypeFor(param) };
					auto newValue{ pickRandomValueForParam(paramIndex) };
					if (randomizationOptionsType == RandomizationOptionsType::sequencerTrackStep && newValue == params::seqStepValueForRepeat) {
						auto paramIDforPreviousStep{ info.IDfor(paramIndex - (uint8)1) };
						auto previousStepValue{ exposedParams->getParameter(paramIDforPreviousStep)->getValue() };
						exposedParams->getParameter(paramID)->setValueNotifyingHost(previousStepValue);
					}
					else {
						auto newNormalizedValue{ (float)newValue / (float)info.maxValueFor(param) };
						auto paramPtr{ exposedParams->getParameter(paramID) };
						if (paramPtr != nullptr)
							paramPtr->setValueNotifyingHost(newNormalizedValue);
					}
				}
			}
		}
		randomizeArpAndSeqOnOffParametersAfterDelay(0);
		EditBufferDataMessage::addEditBufferDataMessageToOutgoingMidiBuffers(exposedParams, unexposedParams->outgoingMidiBuffers_get());
		voiceTransmissionOptions->setParamChangeEchoesAreNotBlocked();
	}
	else {
		auto delayInMS{ 0 };
		for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
			auto paramID{ info.IDfor(param) };
			auto paramIndex{ info.indexForParamID(paramID.toString()) };
			if (paramID != ID::arpegOnOff && paramID != ID::sequencerOnOff) {
				if (randomizationOptions->paramIsUnlocked(param)) {
					auto randomizationOptionsType{ info.randomizationOptionsTypeFor(param) };
					auto newValue{ pickRandomValueForParam(paramIndex) };
					if (randomizationOptionsType == RandomizationOptionsType::sequencerTrackStep && newValue == params::seqStepValueForRepeat) {
						auto paramIDforPreviousStep{ info.IDfor(paramIndex - (uint8)1) };
						auto previousStepValue{ exposedParams->getParameter(paramIDforPreviousStep)->getValue() };
						auto paramPtr{ exposedParams->getParameter(paramID) };
						if (paramPtr != nullptr)
							paramPtr->setValueNotifyingHost(previousStepValue);
					}
					else {
						auto newNormalizedValue{ (float)newValue / (float)info.maxValueFor(param) };
						updateParamWithNewNormalizedValueAfterDelay(paramID.toString(), newNormalizedValue, delayInMS);
					}
					delayInMS += 50;
				}
			}
		}
		randomizeArpAndSeqOnOffParametersAfterDelay(delayInMS);
	}
}

void ParamRandomizationMethods::randomizeParameter(String paramID) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(paramID) };
	auto newValue{ pickRandomValueForParam(paramIndex) };
	auto randomizationOptionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	if (randomizationOptionsType == RandomizationOptionsType::sequencerTrackStep && newValue == params::seqStepValueForRepeat) {
		auto paramIDforPreviousStep{ info.IDfor(paramIndex - (uint8)1) };
		auto previousStepValue{ exposedParams->getParameter(paramIDforPreviousStep)->getValue() };
		auto paramPtr{ exposedParams->getParameter(paramID) };
		if (paramPtr != nullptr)
			paramPtr->setValueNotifyingHost(previousStepValue);
	}
	else {
		auto maxValue{ info.maxValueFor(paramIndex) };
		auto newNormalizedValue{ (float)newValue / (float)maxValue };
		auto paramPtr{ exposedParams->getParameter(paramID) };
		if (paramPtr != nullptr)
			paramPtr->setValueNotifyingHost(newNormalizedValue);
	}
}

uint8 ParamRandomizationMethods::pickRandomValueForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto onlyOneValueIsAllowed{ randomizationOptions->onlyOneValueIsAllowedForParam(paramIndex) };
	if (onlyOneValueIsAllowed)
		return randomizationOptions->onlyAllowedValueForParam(paramIndex);
	auto randomizationOptionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	switch (randomizationOptionsType)
	{
	case RandomizationOptionsType::none: {
		auto paramID{ info.IDfor(paramIndex).toString() };
		auto numberOfSteps{ info.numberOfStepsFor(paramIndex) };
		if (paramID.startsWith("nameChar"))
			numberOfSteps -= params::offsetForSpecialASCIIchars;
		Random rndmNumGenerator{};
		auto newValue{ (int)floor(rndmNumGenerator.nextFloat() * numberOfSteps) };
		if (paramID.startsWith("nameChar"))
			newValue += params::offsetForSpecialASCIIchars;
		return (uint8)newValue;
	}
	case RandomizationOptionsType::pitch:
		return pickRandomPitchForParam(paramIndex);
	case RandomizationOptionsType::valueRange:
		return pickRandomValueFromRangeForParam(paramIndex);
	case RandomizationOptionsType::oscShape:
		return pickRandomOscShapeAndPulseWidthForParam(paramIndex);
	case RandomizationOptionsType::comboBoxes:
		return pickRandomComboBoxItemForParam(paramIndex);
	case RandomizationOptionsType::lpfFreq:
		return pickRandomLPFfreq();
	case RandomizationOptionsType::lfoFreq:
		return pickRandomLFOfreqForParam(paramIndex);
	case RandomizationOptionsType::sequencerTrackStep:
		return pickRandomSeqStepValueForParam(paramIndex);
	case RandomizationOptionsType::toggles: {
		auto repeatValuesAreNotAllowed{ randomizationOptions->repeatValuesAreNotAllowedForParam(paramIndex) };
		if (repeatValuesAreNotAllowed) {
			auto paramID{ info.IDfor(paramIndex).toString() };
			auto currentValue{ roundToInt(exposedParams->getParameter(paramID)->getValue()) };
			return uint8(1.0f - currentValue);
		}
		else {
			Random rndmNumGenerator{};
			auto newValue{ (int)floor(rndmNumGenerator.nextFloat() * 2) };
			return (uint8)newValue;
		}
	}
	default:
		return (uint8)255;
	}
}

uint8 ParamRandomizationMethods::pickRandomPitchForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto maxPitch{ uint8(info.maxValueFor(paramIndex)) };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto repeatValuesAreNotAllowed{ randomizationOptions->repeatValuesAreNotAllowedForParam(paramIndex) };
	Array<uint8> allowedPitches;
	if (repeatValuesAreNotAllowed) {
		auto paramID{ info.IDfor(paramIndex) };
		auto currentNormalizedValue{ exposedParams->getParameter(paramID)->getValue() };
		auto currentPitch{ (uint8)roundToInt(maxPitch * currentNormalizedValue) };
		for (uint8 pitch = 0; pitch <= maxPitch; ++pitch) {
			if (pitch != currentPitch) {
				auto pitchIsAllowed{ randomizationOptions->pitchIsAllowedForParam(pitch, paramIndex) };
				if (pitchIsAllowed)
					allowedPitches.add(pitch);
			}
		}
	}
	else {
		for (uint8 pitch = 0; pitch <= maxPitch; ++pitch) {
			auto pitchIsAllowed{ randomizationOptions->pitchIsAllowedForParam(pitch, paramIndex) };
			if (pitchIsAllowed)
				allowedPitches.add(pitch);
		}
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

uint8 ParamRandomizationMethods::pickRandomValueFromRangeForParam(uint8 paramIndex) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto minValueAllowed{ randomizationOptions->minValueAllowedForParam(paramIndex) };
	auto maxValueAllowed{ randomizationOptions->maxValueAllowedForParam(paramIndex) };
	auto repeatValuesAreNotAllowed{ randomizationOptions->repeatValuesAreNotAllowedForParam(paramIndex) };
	Array<uint8> allowedValues;
	if (repeatValuesAreNotAllowed) {
		auto& info{ InfoForExposedParameters::get() };
		auto paramID{ info.IDfor(paramIndex) };
		auto currentNormalizedValue{ exposedParams->getParameter(paramID)->getValue() };
		auto maxValue{ info.maxValueFor(paramIndex) };
		auto currentValue{ (uint8)roundToInt(maxValue * currentNormalizedValue) };
		for (auto val = minValueAllowed; val <= maxValueAllowed; ++val) {
			if (val != currentValue)
				allowedValues.add(val);
		}
	}
	else {
		for (auto val = minValueAllowed; val <= maxValueAllowed; ++val)
			allowedValues.add(val);
	}
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	auto numberOfValueOptions{ allowedValues.size() };
	auto newValueIndex{ (int)floor(newFloat * numberOfValueOptions) };
	return allowedValues[newValueIndex];
}

uint8 ParamRandomizationMethods::pickRandomOscShapeAndPulseWidthForParam(uint8 paramIndex) {
	auto newShape{ pickRandomOscShapeIndexForParameter(paramIndex) };
	if (newShape != (int)OscWaveShape::pulse)
		return newShape;
	else {
		auto newPulseWidth{ pickRandomPulseWidthForParam(paramIndex) };
		return newShape + newPulseWidth;
	}
}

uint8 ParamRandomizationMethods::pickRandomOscShapeIndexForParameter(uint8 paramIndex) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto repeatValuesAreNotAllowed{ randomizationOptions->repeatValuesAreNotAllowedForParam(paramIndex) };
	Array<uint8> allowedShapeIndices;
	if (repeatValuesAreNotAllowed) {
		auto& info{ InfoForExposedParameters::get() };
		auto paramID{ info.IDfor(paramIndex) };
		auto currentNormalizedValue{ exposedParams->getParameter(paramID)->getValue() };
		auto maxValue{ info.maxValueFor(paramIndex) };
		auto currentShape{ (uint8)roundToInt(maxValue * currentNormalizedValue) };
		if (currentShape > (uint8)OscWaveShape::pulse)
			currentShape = (uint8)OscWaveShape::pulse;
		for (auto shapeIndex = (uint8)OscWaveShape::off; shapeIndex <= (uint8)OscWaveShape::pulse; ++shapeIndex) {
			if (shapeIndex != currentShape) {
				if (randomizationOptions->oscShapeIsAllowedForParam(shapeIndex, paramIndex))
					allowedShapeIndices.add(shapeIndex);
			}
		}
	}
	else {
		for (auto shapeIndex = (uint8)OscWaveShape::off; shapeIndex <= (uint8)OscWaveShape::pulse; ++shapeIndex) {
			if (randomizationOptions->oscShapeIsAllowedForParam(shapeIndex, paramIndex))
				allowedShapeIndices.add(shapeIndex);
		}
	}
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	auto numberOfShapeIndices{ allowedShapeIndices.size() };
	if (numberOfShapeIndices == 0)
		return (uint8)OscWaveShape::pulse;
	else {
		auto newShapeIndex{ (int)floor(newFloat * numberOfShapeIndices) };
		return allowedShapeIndices[newShapeIndex];
	}
}

uint8 ParamRandomizationMethods::pickRandomPulseWidthForParam(uint8 paramIndex) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto minWidthAllowed{ randomizationOptions->minPulseWidthAllowedForParam(paramIndex) };
	auto maxWidthAllowed{ randomizationOptions->maxPulseWidthAllowedForParam(paramIndex) };
	auto repeatValuesAreNotAllowed{ randomizationOptions->repeatValuesAreNotAllowedForParam(paramIndex) };
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex) };
	auto currentNormalizedValue{ exposedParams->getParameter(paramID)->getValue() };
	auto maxValue{ info.maxValueFor(paramIndex) };
	auto currentShape{ (uint8)roundToInt(maxValue * currentNormalizedValue) };
	Array<uint8> allowedWidths;
	if (repeatValuesAreNotAllowed && currentShape >= (uint8)OscWaveShape::pulse) {
		auto currentWidth{ uint8(currentShape - (uint8)OscWaveShape::pulse) };
		for (auto width = minWidthAllowed; width <= maxWidthAllowed; ++width) {
			if (width != currentWidth)
				allowedWidths.add(width);
		}
	}
	else {
		for (auto width = minWidthAllowed; width <= maxWidthAllowed; ++width)
			allowedWidths.add(width);
	}
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	auto numberOfWidthOptions{ allowedWidths.size() };
	auto newWidthIndex{ (int)floor(newFloat * numberOfWidthOptions) };
	return allowedWidths[newWidthIndex];
}

uint8 ParamRandomizationMethods::pickRandomComboBoxItemForParam(uint8 paramIndex) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	Array<uint8> allowedItems;
	auto& info{ InfoForExposedParameters::get() };
	auto numberOfItems{ info.numberOfStepsFor(paramIndex) };
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

uint8 ParamRandomizationMethods::pickRandomLPFfreq() {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	uint8 newFreq{ 0 };
	auto paramIndex{ InfoForExposedParameters::get().indexForParamID(ID::lpfFreq.toString()) };
	auto modeIsValueRange{ randomizationOptions->randomizationModeForLPFfreqIsValueRange() };
	if (modeIsValueRange) {
		newFreq = pickRandomValueFromRangeForParam(paramIndex);
	}
	else
		newFreq = pickRandomPitchForParam(paramIndex);
	return newFreq;
}

uint8 ParamRandomizationMethods::pickRandomLFOfreqForParam(uint8 paramIndex) {
	auto categoryForNewFreq{ pickRandomFreqCategoryForParam(paramIndex) };
	uint8 newFreq{ 0 };
	if (categoryForNewFreq == LFOfreqCategory::unsynced)
		newFreq = pickRandomUnsyncedLFOfreqForParam(paramIndex);
	if (categoryForNewFreq == LFOfreqCategory::pitched)
		newFreq = pickRandomPitchedLFOfreqForParam(paramIndex);
	if (categoryForNewFreq == LFOfreqCategory::synced) {
		newFreq = pickRandomSyncedLFOfreqForParam(paramIndex);
	}
	return newFreq;
}

LFOfreqCategory ParamRandomizationMethods::pickRandomFreqCategoryForParam(uint8 paramIndex) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto repeatValuesAreNotAllowed{ randomizationOptions->repeatValuesAreNotAllowedForParam(paramIndex) };
	Array<LFOfreqCategory> allowedFreqCategories;
	if (repeatValuesAreNotAllowed) {
		auto& info{ InfoForExposedParameters::get() };
		auto paramID{ info.IDfor(paramIndex) };
		auto currentNormalizedValue{ exposedParams->getParameter(paramID)->getValue() };
		auto maxValue{ info.maxValueFor(paramIndex) };
		auto currentValue{ (uint8)roundToInt(maxValue * currentNormalizedValue) };
		auto currentCategory{ LFOfreqCategory::unsynced };
		if (currentValue >= params::firstPitchedLFOfreq && currentValue < params::firstSyncedLFOfreq)
			currentCategory = LFOfreqCategory::pitched;
		if (currentValue >= params::firstSyncedLFOfreq)
			currentCategory = LFOfreqCategory::synced;
		if (randomizationOptions->unsyncedFreqAreAllowedForParam(paramIndex)) {
			if (currentCategory != LFOfreqCategory::unsynced ||
				(currentCategory == LFOfreqCategory::unsynced && randomizationOptions->moreThanOneUnsyncedFreqIsAllowedForParam(paramIndex)))
				allowedFreqCategories.add(LFOfreqCategory::unsynced);
		}
		if (randomizationOptions->pitchedFreqAreAllowedForParam(paramIndex)) {
			if (currentCategory != LFOfreqCategory::pitched ||
				(currentCategory == LFOfreqCategory::pitched && randomizationOptions->moreThanOnePitchedFreqIsAllowedForParam(paramIndex)))
				allowedFreqCategories.add(LFOfreqCategory::pitched);
		}
		if (randomizationOptions->syncedFreqAreAllowedForParam(paramIndex)) {
			if (currentCategory != LFOfreqCategory::synced ||
				(currentCategory == LFOfreqCategory::synced && randomizationOptions->moreThanOneSyncedFreqIsAllowedForParam(paramIndex)))
				allowedFreqCategories.add(LFOfreqCategory::synced);
		}
	}
	else {
		if (randomizationOptions->unsyncedFreqAreAllowedForParam(paramIndex))
			allowedFreqCategories.add(LFOfreqCategory::unsynced);
		if (randomizationOptions->pitchedFreqAreAllowedForParam(paramIndex))
			allowedFreqCategories.add(LFOfreqCategory::pitched);
		if (randomizationOptions->syncedFreqAreAllowedForParam(paramIndex))
			allowedFreqCategories.add(LFOfreqCategory::synced);
	}
	auto numberOfAllowedCategories{ allowedFreqCategories.size() };
	Random rndmNumGeneratorForCategory{};
	auto newCategoryFloat{ rndmNumGeneratorForCategory.nextFloat() };
	auto categoryIndex{ (int)floor(newCategoryFloat * numberOfAllowedCategories) };
	return allowedFreqCategories[categoryIndex];
}

uint8 ParamRandomizationMethods::pickRandomUnsyncedLFOfreqForParam(uint8 paramIndex) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto minUnsyncedFreq{ randomizationOptions->minUnsyncedFreqForParam(paramIndex) };
	auto maxUnsyncedFreq{ randomizationOptions->maxUnsyncedFreqForParam(paramIndex) };
	auto repeatValuesAreNotAllowed{ randomizationOptions->repeatValuesAreNotAllowedForParam(paramIndex) };
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex) };
	auto currentNormalizedValue{ exposedParams->getParameter(paramID)->getValue() };
	auto maxValue{ info.maxValueFor(paramIndex) };
	auto currentFreq{ (uint8)roundToInt(maxValue * currentNormalizedValue) };
	Array<uint8> allowedUnsyncedFreq;
	if (repeatValuesAreNotAllowed && currentFreq >= minUnsyncedFreq && currentFreq <= maxUnsyncedFreq) {
		for (uint8 freq = minUnsyncedFreq; freq <= maxUnsyncedFreq; ++freq) {
			if (freq != currentFreq)
				allowedUnsyncedFreq.add(freq);
		}
	}
	else {
		for (uint8 freq = minUnsyncedFreq; freq <= maxUnsyncedFreq; ++freq)
			allowedUnsyncedFreq.add(freq);
	}
	auto numberOfAllowedFreq{ allowedUnsyncedFreq.size() };
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	auto newFreqIndex{ (int)floor(newFloat * numberOfAllowedFreq) };
	return allowedUnsyncedFreq[newFreqIndex];
}

uint8 ParamRandomizationMethods::pickRandomPitchedLFOfreqForParam(uint8 paramIndex) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto repeatValuesAreNotAllowed{ randomizationOptions->repeatValuesAreNotAllowedForParam(paramIndex) };
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex) };
	auto currentNormalizedValue{ exposedParams->getParameter(paramID)->getValue() };
	auto maxValue{ info.maxValueFor(paramIndex) };
	auto currentFreq{ (uint8)roundToInt(maxValue * currentNormalizedValue) };
	Array<uint8> allowedPitchedFreq;
	if (repeatValuesAreNotAllowed && currentFreq >= params::firstPitchedLFOfreq && currentFreq < params::firstSyncedLFOfreq) {
		auto currentPitchedFreq{ uint8(currentFreq - params::firstPitchedLFOfreq) };
		for (uint8 freq = 0; freq != (uint8)randomization::numberOfPitchedFreqForLFOs; ++freq) {
			auto pitchedFreqIsAllowed{ randomizationOptions->pitchIsAllowedForParam(freq, paramIndex) };
			if (pitchedFreqIsAllowed && freq != currentPitchedFreq)
				allowedPitchedFreq.add(freq);
		}
	}
	else {
		for (uint8 freq = 0; freq != (uint8)randomization::numberOfPitchedFreqForLFOs; ++freq) {
			auto pitchedFreqIsAllowed{ randomizationOptions->pitchIsAllowedForParam(freq, paramIndex) };
			if (pitchedFreqIsAllowed)
				allowedPitchedFreq.add(freq);
		}
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

uint8 ParamRandomizationMethods::pickRandomSyncedLFOfreqForParam(uint8 paramIndex) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto repeatValuesAreNotAllowed{ randomizationOptions->repeatValuesAreNotAllowedForParam(paramIndex) };
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex) };
	auto currentNormalizedValue{ exposedParams->getParameter(paramID)->getValue() };
	auto maxValue{ info.maxValueFor(paramIndex) };
	auto currentFreq{ (uint8)roundToInt(maxValue * currentNormalizedValue) };
	Array<uint8> allowedSyncedFreq;
	if (repeatValuesAreNotAllowed && currentFreq >= params::firstSyncedLFOfreq) {
		auto currentSyncedFreq{ uint8(currentFreq - params::firstSyncedLFOfreq) };
		for (uint8 freq = 0; freq != (uint8)randomization::numberOfSyncedFreqForLFOs; ++freq) {
			auto syncedFreqIsAllowed{ randomizationOptions->syncedFreqIsAllowedForParam(freq, paramIndex) };
			if (syncedFreqIsAllowed && freq != currentSyncedFreq)
				allowedSyncedFreq.add(freq);
		}
	}
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

uint8 ParamRandomizationMethods::pickRandomSeqStepValueForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString()};
	auto trackNum{ paramID.fromFirstOccurrenceOf("seqTrack", false, false).upToFirstOccurrenceOf("Step", false, false).getIntValue() };
	auto stepNum{ paramID.fromFirstOccurrenceOf("Step", false, false).getIntValue() };
	if (trackNum == 1) {
		auto stepIsRest{ randomlyDecideIfStepInSeqTrack1IsRest(paramIndex) };
		if (stepIsRest)
			return params::seqStepValueForRest;
	}
	if (stepNum != 1) {
		auto stepIsRepeat{ randomlyDecideIfStepInSeqTrackIsRepeatValue(paramIndex, trackNum) };
		if (stepIsRepeat)
			return params::seqStepValueForRepeat;
		auto stepIsReset{ randomlyDecideIfStepInSeqTrackIsReset(paramIndex, trackNum) };
		if (stepIsReset)
			return params::seqStepValueForReset;
	}
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto trackDestinationIsOscPitch{ randomizationOptions->trackDestinationIsAnOscPitchParameter(trackNum) };
	if (trackDestinationIsOscPitch) {
		auto newPitch{ pickRandomPitchForStepParamInTrack(paramIndex, trackNum) };
		return newPitch;
	}
	else {
		auto newValue{ pickRandomValueFromRangeForStepParamInTrack(paramIndex, trackNum) };
		return newValue;
	}
}

bool ParamRandomizationMethods::randomlyDecideIfStepInSeqTrack1IsRest(uint8 paramIndex) {
	float probabilityOfRest{ 0.0f };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
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

bool ParamRandomizationMethods::randomlyDecideIfStepInSeqTrackIsRepeatValue(uint8 paramIndex, int trackNum) {
	float probabilityOfRepeat{ 0.0f };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
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

bool ParamRandomizationMethods::randomlyDecideIfStepInSeqTrackIsReset(uint8 paramIndex, int trackNum) {
	float probabilityOfReset{ 0.0f };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
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

uint8 ParamRandomizationMethods::pickRandomPitchForStepParamInTrack(uint8 paramIndex, int trackNum) {
	auto maxPitch{ params::maxValueForSeqTrackStep };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
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

uint8 ParamRandomizationMethods::pickRandomValueFromRangeForStepParamInTrack(uint8 paramIndex, int trackNum) {
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

void ParamRandomizationMethods::randomizeArpAndSeqOnOffParametersAfterDelay(int delayInMs) {
	auto& info{ InfoForExposedParameters::get() };
	auto arpegOnOffIndex{ info.indexForParamID("arpegOnOff") };
	auto sequencerOnOffIndex{ info.indexForParamID("sequencerOnOff") };
	Random rndmNumGenerator{};
	auto newNormalizedValue{ rndmNumGenerator.nextFloat() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto transmissionMethodIsSysEx{ randomizationOptions->transmissionMethodIsSysEx() };
	auto seqDelay{ transmissionMethodIsSysEx ? 0 : 50 };
	if (randomizationOptions->paramIsUnlocked(arpegOnOffIndex) && randomizationOptions->paramIsUnlocked(sequencerOnOffIndex)) {
		auto arpSeqOnOffOption{ (int)std::floor(newNormalizedValue * 3) };
		switch (arpSeqOnOffOption) {
		case 0: {
			updateParamWithNewNormalizedValueAfterDelay("arpegOnOff", 0.0f, delayInMs);
			updateParamWithNewNormalizedValueAfterDelay("sequencerOnOff", 0.0f, delayInMs + seqDelay);
			break;
		}
		case 1: {
			updateParamWithNewNormalizedValueAfterDelay("arpegOnOff", 1.0f, delayInMs);
			updateParamWithNewNormalizedValueAfterDelay("sequencerOnOff", 0.0f, delayInMs + seqDelay);
			break;
		}
		case 2: {
			updateParamWithNewNormalizedValueAfterDelay("arpegOnOff", 0.0f, delayInMs);
			updateParamWithNewNormalizedValueAfterDelay("sequencerOnOff", 1.0f, delayInMs + seqDelay);
			break;
		}
		default:
			break;
		}
	}
	if (randomizationOptions->paramIsUnlocked(arpegOnOffIndex) && randomizationOptions->paramIsLocked(sequencerOnOffIndex)) {
		auto arpOnOffOption{ std::round(newNormalizedValue) };
		updateParamWithNewNormalizedValueAfterDelay("arpegOnOff", arpOnOffOption, delayInMs);
	}
	if (randomizationOptions->paramIsLocked(arpegOnOffIndex) && randomizationOptions->paramIsUnlocked(sequencerOnOffIndex)) {
		auto seqOnOffOption{ std::round(newNormalizedValue) };
		updateParamWithNewNormalizedValueAfterDelay("sequencerOnOff", seqOnOffOption, delayInMs);
	}
}

void ParamRandomizationMethods::updateParamWithNewNormalizedValueAfterDelay(String paramID, float newNormalizedValue, int delayInMs) {
	auto exposedParamsPtr{ exposedParams };
	callAfterDelay(delayInMs, [exposedParamsPtr, paramID, newNormalizedValue] {
		auto paramPtr{ exposedParamsPtr->getParameter(paramID) };
		if (paramPtr != nullptr)
			paramPtr->setValueNotifyingHost(newNormalizedValue);
		}
	);
}

void ParamRandomizationMethods::timerCallback() {
}
