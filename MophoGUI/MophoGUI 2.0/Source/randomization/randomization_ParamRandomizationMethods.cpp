#include "randomization_ParamRandomizationMethods.h"

#include "randomization_Constants.h"
#include "../midi/midi_EditBufferDataMessage.h"
#include "../params/params_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



void ParamRandomizationMethods::randomizeUnlockedParameters(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
	voiceTransmissionOptions->setParamChangeEchoesAreBlocked();
	auto& info{ InfoForExposedParameters::get() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
		auto paramID{ info.IDfor(param) };
		if (paramID != ID::arpegOnOff && paramID != ID::sequencerOnOff) {
			if (randomizationOptions->paramIsUnlocked(param)) {
				auto randomizationOptionsType{ info.randomizationOptionsTypeFor(param) };
				if (randomizationOptionsType == RandomizationOptionsType::none)
					randomizeParameter(paramID, exposedParams);
				if (randomizationOptionsType == RandomizationOptionsType::pitch)
					randomizePitchParameter(paramID, exposedParams, unexposedParams);
				if (randomizationOptionsType == RandomizationOptionsType::valueRange)
					randomizeValueRangeParameter(paramID, exposedParams, unexposedParams);
				if (randomizationOptionsType == RandomizationOptionsType::oscShape)
					randomizeOscShapeParameter(paramID, exposedParams, unexposedParams);
				//else if (paramID.toString().startsWith("lfo") && paramID.toString().endsWith("Freq"))
				//	randomizeLFOfreqParameter(paramID, exposedParams, unexposedParams);
			}
		}
	}
	randomizeArpAndSeqOnOffParameters(exposedParams, unexposedParams);
	EditBufferDataMessage::addEditBufferDataMessageToOutgoingMidiBuffers(exposedParams, unexposedParams->outgoingMidiBuffers_get());
	voiceTransmissionOptions->setParamChangeEchoesAreNotBlocked();
}

void ParamRandomizationMethods::randomizeParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(paramID.toString()) };
	auto numberOfStepsFor{ info.numberOfStepsFor(paramIndex) };
	Random rndmNumGenerator{};
	auto newValue{ floor(rndmNumGenerator.nextFloat() * numberOfStepsFor) };
	auto newNormalizedValue{ newValue / info.maxValueFor(paramIndex) };
	exposedParams->getParameter(paramID)->setValueNotifyingHost(newNormalizedValue);
}

void ParamRandomizationMethods::randomizePitchParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(paramID.toString()) };
	auto pitchOutOfRange{ uint8(info.numberOfStepsFor(paramIndex)) };
	Array<float> allowedPitchesStoredAsNormalizedValues;
	float newNormalizedValue{ 0.0f };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (randomizationOptions->onlyHighestOctaveIsAllowedForParam(paramIndex))
		newNormalizedValue = 1.0f;
	else {
		for (uint8 pitch = 0; pitch != pitchOutOfRange; ++pitch) {
			auto pitchIsAllowed{ randomizationOptions->pitchIsAllowedForParam(pitch, paramIndex) };
			if (pitchIsAllowed) {
				auto normalizedValue{ pitch / (float)info.maxValueFor(paramIndex) };
				allowedPitchesStoredAsNormalizedValues.add(normalizedValue);
			}
		}
		auto numberOfAllowedPitches{ allowedPitchesStoredAsNormalizedValues.size() };
		Random rndmNumGenerator{};
		auto newPitchIndex{ (int)floor(rndmNumGenerator.nextFloat() * numberOfAllowedPitches) };
		newNormalizedValue = allowedPitchesStoredAsNormalizedValues[newPitchIndex];
	}
	exposedParams->getParameter(paramID)->setValueNotifyingHost(newNormalizedValue);
}

void ParamRandomizationMethods::randomizeValueRangeParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(paramID.toString()) };
	auto newValue{ pickRandomValueFromRangeForParam(paramIndex, unexposedParams) };
	auto maxValue{ (float)info.maxValueFor(paramIndex) };
	auto newNormalizedValue{ newValue / maxValue };
	exposedParams->getParameter(paramID)->setValueNotifyingHost(newNormalizedValue);
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

void ParamRandomizationMethods::randomizeOscShapeParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams, UnexposedParameters * unexposedParams) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(paramID.toString()) };
	auto maxValue{ (float)info.maxValueFor(paramIndex) };
	auto newShape{ pickRandomOscShapeForParameter(paramIndex, unexposedParams) };
	if (newShape != OscWaveShape::pulse) {
		auto newNormalizedValue{ (float)newShape / maxValue };
		exposedParams->getParameter(paramID)->setValueNotifyingHost(newNormalizedValue);
	}
	else {
		auto newPulseWidth{ pickRandomPulseWidthForParam(paramIndex, unexposedParams) };
		auto newNormalizedValue{ ((float)newShape + newPulseWidth) / maxValue };
		exposedParams->getParameter(paramID)->setValueNotifyingHost(newNormalizedValue);
	}
}

OscWaveShape ParamRandomizationMethods::pickRandomOscShapeForParameter(uint8 paramIndex, UnexposedParameters* unexposedParams) {
	Array<OscWaveShape> allowedShapes;
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (randomizationOptions->oscShapeIsAllowedForParam(OscWaveShape::off, paramIndex))
		allowedShapes.add(OscWaveShape::off);
	if (randomizationOptions->oscShapeIsAllowedForParam(OscWaveShape::sawtooth, paramIndex))
		allowedShapes.add(OscWaveShape::sawtooth);
	if (randomizationOptions->oscShapeIsAllowedForParam(OscWaveShape::triangle, paramIndex))
		allowedShapes.add(OscWaveShape::triangle);
	if (randomizationOptions->oscShapeIsAllowedForParam(OscWaveShape::sawTriMix, paramIndex))
		allowedShapes.add(OscWaveShape::sawTriMix);
	if (randomizationOptions->oscShapeIsAllowedForParam(OscWaveShape::pulse, paramIndex))
		allowedShapes.add(OscWaveShape::pulse);
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	auto numberOfShapeOptions{ allowedShapes.size() };
	auto newShapeIndex{ (int)floor(newFloat * numberOfShapeOptions) };
	return allowedShapes[newShapeIndex];
}

float ParamRandomizationMethods::pickRandomPulseWidthForParam(uint8 paramIndex, UnexposedParameters* unexposedParams) {
	Array<float> allowedWidths;
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto minWidthAllowed{ randomizationOptions->minPulseWidthAllowedForParam(paramIndex) };
	auto maxWidthAllowed{ randomizationOptions->maxPulseWidthAllowedForParam(paramIndex) };
	for (auto width = minWidthAllowed; width <= maxWidthAllowed; ++width)
		allowedWidths.add((float)width);
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	auto numberOfWidthOptions{ allowedWidths.size() };
	auto newWidthIndex{ (int)floor(newFloat * numberOfWidthOptions) };
	return allowedWidths[newWidthIndex];
}

//void ParamRandomizationMethods::randomizeLFOfreqParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	//auto lfoNum{ paramID.toString().fromFirstOccurrenceOf("lfo", false, false).getIntValue() };
	//auto categoryForNewFreq{ randomlyPickFreqCategoryForLFO(lfoNum, unexposedParams) };
	//auto& info{ InfoForExposedParameters::get() };
	//auto paramIndex{ info.indexForParamID(paramID.toString()) };
	//auto maxParamValue{ info.maxValueFor(paramIndex) };
	//auto newNormalizedValue{ 0.0f };
	//if (categoryForNewFreq == lfoFreqCategory::unsynced) {
	//	auto newFreq{ randomlyPickUnsyncedFreqForLFO(lfoNum, unexposedParams) };
	//	newNormalizedValue = (float)newFreq / maxParamValue;
	//}
	//if (categoryForNewFreq == lfoFreqCategory::pitched) {
	//	auto newFreq{ randomlyPickPitchedFreqForLFO(lfoNum, unexposedParams) + params::firstPitchedLFOfreq };
	//	newNormalizedValue = (float)newFreq / maxParamValue;
	//}
	//if (categoryForNewFreq == lfoFreqCategory::synced) {
	//	auto newFreq{ randomlyPickSyncedFreqForLFO(lfoNum, unexposedParams) + params::firstSyncedLFOfreq };
	//	newNormalizedValue = (float)newFreq / maxParamValue;
	//}
	//exposedParams->getParameter(paramID)->setValueNotifyingHost(newNormalizedValue);
//}

//lfoFreqCategory ParamRandomizationMethods::randomlyPickFreqCategoryForLFO(int lfoNum, UnexposedParameters* unexposedParams) {
	//Array<lfoFreqCategory> allowedFreqCategories;
	//auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	//if (randomizationOptions->unsyncedFreqAreAllowedForLFO(lfoNum))
	//	allowedFreqCategories.add(lfoFreqCategory::unsynced);
	//if (randomizationOptions->pitchedFreqAreAllowedForLFO(lfoNum))
	//	allowedFreqCategories.add(lfoFreqCategory::pitched);
	//if (randomizationOptions->syncedFreqAreAllowedForLFO(lfoNum))
	//	allowedFreqCategories.add(lfoFreqCategory::synced);
	//auto numberOfAllowedCategories{ allowedFreqCategories.size() };
	//Random rndmNumGeneratorForCategory{};
	//auto newCategoryFloat{ rndmNumGeneratorForCategory.nextFloat() };
	//auto categoryIndex{ (int)floor(newCategoryFloat * numberOfAllowedCategories) };
	//return allowedFreqCategories[categoryIndex];
//}

//uint8 ParamRandomizationMethods::randomlyPickUnsyncedFreqForLFO(int lfoNum, UnexposedParameters* unexposedParams) {
	//auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	//auto minUnsyncedFreq{ randomizationOptions->minUnsyncedFreqForLFO(lfoNum) };
	//auto maxUnsyncedFreq{ randomizationOptions->maxUnsyncedFreqForLFO(lfoNum) };
	//Array<uint8> allowedUnsyncedFreq;
	//for (uint8 freq = minUnsyncedFreq; freq <= maxUnsyncedFreq; ++freq)
	//	allowedUnsyncedFreq.add(freq);
	//auto numberOfAllowedFreq{ allowedUnsyncedFreq.size() };
	//Random rndmNumGenerator{};
	//auto newFloat{ rndmNumGenerator.nextFloat() };
	//auto newFreqIndex{ (int)floor(newFloat * numberOfAllowedFreq) };
	//return allowedUnsyncedFreq[newFreqIndex];
//}

//uint8 ParamRandomizationMethods::randomlyPickPitchedFreqForLFO(int lfoNum, UnexposedParameters* unexposedParams) {
	//auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	//if (randomizationOptions->onlyOctave5_IsAllowedForLFO(lfoNum))
	//	return randomization::numberOfPitchedFreqForLFOs - 1;
	//else {
	//	Array<uint8> allowedPitchedFreq;
	//	for (uint8 freq = 0; freq != randomization::numberOfPitchedFreqForLFOs; ++freq) {
	//		auto pitchedFreqIsAllowed{ randomizationOptions->pitchIsAllowedForLFO(freq, lfoNum) };
	//		if (pitchedFreqIsAllowed)
	//			allowedPitchedFreq.add(freq);
	//	}
	//	auto numberOfAllowedPitchedFreq{ allowedPitchedFreq.size() };
	//	Random rndmNumGenerator{};
	//	auto newFloat{ rndmNumGenerator.nextFloat() };
	//	auto newPitchedFreqIndex{ (int)floor(newFloat * numberOfAllowedPitchedFreq) };
	//	return allowedPitchedFreq[newPitchedFreqIndex];
	//}
//}

//uint8 ParamRandomizationMethods::randomlyPickSyncedFreqForLFO(int lfoNum, UnexposedParameters* unexposedParams) {
	//auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	//Array<uint8> allowedSyncedFreq;
	//for (uint8 freq = 0; freq != randomization::numberOfSyncedFreqForLFOs; ++freq) {
	//	auto syncedFreqIsAllowed{ randomizationOptions->syncedFreqIsAllowedForLFO(freq, lfoNum) };
	//	if (syncedFreqIsAllowed)
	//		allowedSyncedFreq.add(freq);
	//}
	//auto numberOfAllowedSyncedFreq{ allowedSyncedFreq.size() };
	//Random rndmNumGenerator{};
	//auto newFloat{ rndmNumGenerator.nextFloat() };
	//auto newSyncedFreqIndex{ (int)floor(newFloat * numberOfAllowedSyncedFreq) };
	//return allowedSyncedFreq[newSyncedFreqIndex];
//}

//void ParamRandomizationMethods::randomizeSeqStepParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams)
//{
//}

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
