#include "params_RandomizationOptions.h"

#include "params_Constants.h"
#include "params_Identifiers.h"
#include "params_ExposedParamsInfo_Singleton.h"
#include "../randomization/randomization_Constants.h"

using namespace constants;



RandomizationOptions::RandomizationOptions() :
	transmissionOptionsTree{ ID::randomization_TransmissionOptions },
	paramLocksTree{ ID::randomization_ParamLocks },
	allowedValuesTrees{ ID::randomization_AllowedValues},
	allowedPitchesTree{ ID::randomization_AllowedPitches },
	allowedValueRangesTree{ ID::randomization_AllowedValueRanges },
	allowedOscShapesTree{ ID::randomization_AllowedOscShapes },
	allowedComboBoxItemsTree{ ID::randomization_AllowedComboBoxItems },
	allowedFrequencyTypesTree{ ID::randomization_AllowedFrequencyTypes },
	lpfFreqOptionsTree{ ID::randomization_LPFfreqOptions },
	repeatValuesOptionsTree{ ID::randomization_RepeatValuesOptions },
	seqTrackOptionsTree{ ID::randomization_SeqTrackOptions }
{
	fillAllRandomizationOptionsTreesWithProperties();
}

void RandomizationOptions::fillAllRandomizationOptionsTreesWithProperties() {
	setTransmissionMethodIsSysEx();
	for (uint8 param = 0; param != params::numberOfExposedParams; ++param) {
		setParamIsUnlocked(param);
		auto& info{ InfoForExposedParameters::get() };
		auto optionsType{ info.randomizationOptionsTypeFor(param) };
		if (optionsType == RandomizationOptionsType::allowedValues) {
			auto numberOfSteps{ info.numberOfStepsFor(param) };
			for (uint8 val = 0; val != numberOfSteps; ++val)
				setValueIsAllowedForParam(val, param);
			checkNumberOfAllowedValuesForParam(param);
		}
		if (optionsType == RandomizationOptionsType::valueRange) {
			setMinValueAllowedForParam((uint8)0, param);
			setMaxValueAllowedForParam(info.maxValueFor(param), param);
		}
		if (optionsType == RandomizationOptionsType::oscShape) {
			setOscShapeIsAllowedForParam((uint8)OscWaveShape::off, param);
			setOscShapeIsAllowedForParam((uint8)OscWaveShape::sawtooth, param);
			setOscShapeIsAllowedForParam((uint8)OscWaveShape::triangle, param);
			setOscShapeIsAllowedForParam((uint8)OscWaveShape::sawTriMix, param);
			setOscShapeIsAllowedForParam((uint8)OscWaveShape::pulse, param);
			for (auto pulseWidth = 0; pulseWidth != 100; ++pulseWidth)
				setPulseWidthIsAllowedForParam(pulseWidth, param);
			setMinPulseWidthAllowedForParam((uint8)0, param); // todo: delete
			setMaxPulseWidthAllowedForParam(params::maxPulseWidth, param);; // todo: delete
		}
		if (optionsType == RandomizationOptionsType::comboBoxes) {
			auto numberOfItems{ info.numberOfStepsFor(param) };
			for (auto itemNum = 0; itemNum != numberOfItems; ++itemNum)
				setComboBoxItemIsAllowedForParam(itemNum, param);
		}
		if (optionsType == RandomizationOptionsType::lpfFreq) {
			setRandomizationModeForLPFfreqToValueRange();
			setMinValueAllowedForParam((uint8)0, param);
			setMaxValueAllowedForParam(info.maxValueFor(param), param);
			for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum)
				setNoteIsAllowedForParam(noteNum, param);
			for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLPFfreq; ++octaveNum)
				setOctaveIsAllowedForParam(octaveNum, param);
			setHighestOctaveIsNotOnlyOneAllowedForParam(param);
		}
		if (optionsType == RandomizationOptionsType::allowedLFOfrequencies) {
			setUnsyncedFreqAreAllowedForParam(param);
			setPitchedFreqAreAllowedForParam(param);
			setSyncedFreqAreAllowedForParam(param);
			for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum)
				setNoteIsAllowedForParam(noteNum, param);
			for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOfreqAndSeqSteps; ++octaveNum)
				setOctaveIsAllowedForParam(octaveNum, param);
			setHighestOctaveIsNotOnlyOneAllowedForParam(param);
			setMinUnsyncedFreqForParam((uint8)0, param);
			setMaxUnsyncedFreqForParam(params::maxUnsyncedLFOfreq, param);
			for (auto syncedFreqNum = 0; syncedFreqNum != randomization::numberOfSyncedFreqForLFOs; ++syncedFreqNum)
				setSyncedFreqIsAllowedForParam(syncedFreqNum, param);
		}
		if (optionsType == RandomizationOptionsType::allowedSeqTrackStepValues) {
			auto paramName{ info.IDfor(param).toString() };
			if (paramName.fromFirstOccurrenceOf("Track", false, false).upToFirstOccurrenceOf("Step", false, false) == "1")
				setProbabilityOfRestForParam(0.10f, param);
			setProbabilityOfRepeatValueForParam(0.0f, param);
			setProbabilityOfResetForParam(0.0f, param);
			setMinValueAllowedForParam((uint8)0, param);
			setMaxValueAllowedForParam(params::maxValueForSeqTrackStep, param);
			for (auto noteNum = 0; noteNum != randomization::numberOfNotesAndBentNotes; ++noteNum)
				setNoteIsAllowedForParam(noteNum, param);
			for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOfreqAndSeqSteps; ++octaveNum)
				setOctaveIsAllowedForParam(octaveNum, param);
			setHighestOctaveIsNotOnlyOneAllowedForParam(param);
		}
		if (optionsType != RandomizationOptionsType::none) {
			if (optionsType == RandomizationOptionsType::toggles)
				setRepeatValuesAreAllowedForParam(param);
			else
				setRepeatValuesAreNotAllowedForParam(param);
		}
		setMoreThanOneValueIsAllowedForParam_z(param);
	}
	for (auto trackNum = 1; trackNum != 5; ++trackNum) {
		setEditModeForSeqTrackToAllSteps(trackNum);
		setStepSelectedForEditingInSeqTrack(1, trackNum);
		if (trackNum == 1)
			setProbabilityOfRestForAllStepsInSeqTrack1(0.10f);
		setProbabilityOfRepeatForAllStepsInSeqTrack(0.0f, trackNum);
		setProbabilityOfResetForAllStepsInSeqTrack(0.0f, trackNum);
		setMinValueForAllStepsInSeqTrack((uint8)0, trackNum);
		setMaxValueForAllStepsInSeqTrack(params::maxValueForSeqTrackStep, trackNum);
		for (auto noteNum = 0; noteNum != randomization::numberOfNotesAndBentNotes; ++noteNum)
			setNoteIsAllowedForAllStepsInSeqTrack(noteNum, trackNum);
		for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOfreqAndSeqSteps; ++octaveNum)
			setOctaveIsAllowedForAllStepsInSeqTrack(octaveNum, trackNum);
		setHighestOctaveIsNotOnlyOneAllowedForAllStepsInSeqTrack(trackNum);
		setMoreThanOneValueIsAllowedForAllStepsInSeqTrack(trackNum);
		setRepeatValuesAreNotAllowedForAllStepsInSeqTrack(trackNum);
	}
}

const bool RandomizationOptions::transmissionMethodIsNRPN() {
	return (bool)transmissionOptionsTree.getProperty("transmissionMethodIsNRPN");
}

const bool RandomizationOptions::transmissionMethodIsSysEx() {
	return (bool)transmissionOptionsTree.getProperty("transmissionMethodIsSysEx");
}

void RandomizationOptions::setTransmissionMethodIsNRPN() {
	transmissionOptionsTree.setProperty("transmissionMethodIsNRPN", (bool)true, nullptr);
	transmissionOptionsTree.setProperty("transmissionMethodIsSysEx", (bool)false, nullptr);
}

void RandomizationOptions::setTransmissionMethodIsSysEx() {
	transmissionOptionsTree.setProperty("transmissionMethodIsNRPN", (bool)false, nullptr);
	transmissionOptionsTree.setProperty("transmissionMethodIsSysEx", (bool)true, nullptr);
}

const bool RandomizationOptions::paramIsLocked(uint8 paramIndex) {
	jassert(paramIndex < params::numberOfExposedParams);
	return (bool)paramLocksTree.getProperty("param" + String(paramIndex) + "_IsLocked");
}

const bool RandomizationOptions::paramIsUnlocked(uint8 paramIndex) {
	jassert(paramIndex < params::numberOfExposedParams);
	return !(bool)paramLocksTree.getProperty("param" + String(paramIndex) + "_IsLocked");
}

void RandomizationOptions::setParamIsLocked(uint8 paramIndex) {
	jassert(paramIndex < params::numberOfExposedParams);
	paramLocksTree.setProperty("param" + String(paramIndex) + "_IsLocked", (bool)true, nullptr);
}

void RandomizationOptions::setParamIsUnlocked(uint8 paramIndex) {
	jassert(paramIndex < params::numberOfExposedParams);
	paramLocksTree.setProperty("param" + String(paramIndex) + "_IsLocked", (bool)false, nullptr);
}

const bool RandomizationOptions::valueIsAllowedForParam(uint8 value, uint8 paramIndex) {
	jassert(paramIndex < params::numberOfExposedParams);
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	jassert(value < info.numberOfStepsFor(paramIndex));
	auto propertyID{ "value_" + (String)value + "_IsAllowed"};
	auto paramTree{ allowedValuesTrees.getOrCreateChildWithName(paramID, nullptr) };
	return paramTree.hasProperty(propertyID);
}

void RandomizationOptions::setValueIsAllowedForParam(uint8 value, uint8 paramIndex) {
	jassert(paramIndex < params::numberOfExposedParams);
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto paramTree{ allowedValuesTrees.getOrCreateChildWithName(paramID, nullptr) };
	jassert(value < info.numberOfStepsFor(paramIndex));
	auto propertyID{ "value_" + (String)value + "_IsAllowed" };
	if (!paramTree.hasProperty(propertyID))
		paramTree.setProperty(propertyID, value, nullptr);
}

void RandomizationOptions::setValueIsNotAllowedForParam(uint8 value, uint8 paramIndex) {
	jassert(paramIndex < params::numberOfExposedParams);
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto paramTree{ allowedValuesTrees.getOrCreateChildWithName(paramID, nullptr) };
	jassert(value < info.numberOfStepsFor(paramIndex));
	auto propertyID{ "value_" + (String)value + "_IsAllowed" };
	if (paramTree.hasProperty(propertyID))
		paramTree.removeProperty(propertyID, nullptr);
}

const bool RandomizationOptions::onlyOneValueIsAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < params::numberOfExposedParams);
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	return (bool)repeatValuesOptionsTree.getProperty(ID::randomization_OnlyOneValueIsAllowedFor_.toString() + paramID);
}

const bool RandomizationOptions::moreThanOneValueIsAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < params::numberOfExposedParams);
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	return (bool)repeatValuesOptionsTree.getProperty(ID::randomization_MoreThanOneValueIsAllowedFor_.toString() + paramID);
}

const bool RandomizationOptions::noValueIsAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < params::numberOfExposedParams);
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	return (bool)repeatValuesOptionsTree.getProperty(ID::randomization_NoValueIsAllowedFor_.toString() + paramID);
}

const uint8 RandomizationOptions::onlyValueAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < params::numberOfExposedParams);
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto paramTree{ allowedValuesTrees.getOrCreateChildWithName(paramID, nullptr) };
	auto value{ paramTree.getNumProperties() == 1 ? (int)paramTree[0] : 255 };
	return (uint8)value;
}

void RandomizationOptions::checkNumberOfAllowedValuesForParam(uint8 paramIndex) {
	jassert(paramIndex < params::numberOfExposedParams);
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto paramTree{ allowedValuesTrees.getOrCreateChildWithName(paramID, nullptr) };
	auto numberOfAllowedValues{ paramTree.getNumProperties() };
	if (numberOfAllowedValues == 1) {
		setOnlyOneValueIsAllowedForParam(paramIndex);
		return;
	}
	if (numberOfAllowedValues > 1) {
		setMoreThanOneValueIsAllowedForParam(paramIndex);
		return;
	}
	setNoValueIsAllowedForParam(paramIndex);
}

void RandomizationOptions::setOnlyOneValueIsAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < params::numberOfExposedParams);
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	repeatValuesOptionsTree.setProperty(ID::randomization_OnlyOneValueIsAllowedFor_.toString() + paramID, (bool)true, nullptr);
	repeatValuesOptionsTree.setProperty(ID::randomization_MoreThanOneValueIsAllowedFor_.toString() + paramID, (bool)false, nullptr);
	repeatValuesOptionsTree.setProperty(ID::randomization_NoValueIsAllowedFor_.toString() + paramID, (bool)false, nullptr);
}

void RandomizationOptions::setMoreThanOneValueIsAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < params::numberOfExposedParams);
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	repeatValuesOptionsTree.setProperty(ID::randomization_OnlyOneValueIsAllowedFor_.toString() + paramID, (bool)false, nullptr);
	repeatValuesOptionsTree.setProperty(ID::randomization_MoreThanOneValueIsAllowedFor_.toString() + paramID, (bool)true, nullptr);
	repeatValuesOptionsTree.setProperty(ID::randomization_NoValueIsAllowedFor_.toString() + paramID, (bool)false, nullptr);
}

void RandomizationOptions::setNoValueIsAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < params::numberOfExposedParams);
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	repeatValuesOptionsTree.setProperty(ID::randomization_OnlyOneValueIsAllowedFor_.toString() + paramID, (bool)false, nullptr);
	repeatValuesOptionsTree.setProperty(ID::randomization_MoreThanOneValueIsAllowedFor_.toString() + paramID, (bool)false, nullptr);
	repeatValuesOptionsTree.setProperty(ID::randomization_NoValueIsAllowedFor_.toString() + paramID, (bool)true, nullptr);
}

void RandomizationOptions::addListenerToAllowedPitchesTree(ValueTree::Listener* listener) {
	allowedPitchesTree.addListener(listener);
}

void RandomizationOptions::removeListenerFromAllowedPitchesTree(ValueTree::Listener* listener) {
	allowedPitchesTree.removeListener(listener);
}

const bool RandomizationOptions::noteIsAllowedForParam(int noteNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedValues ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::allowedLFOfrequencies ||
		optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	jassert(optionsType == RandomizationOptionsType::allowedSeqTrackStepValues ?
		noteNum < randomization::numberOfNotesAndBentNotes : noteNum < randomization::numberOfNotes);
	auto paramID{ info.IDfor(paramIndex).toString() };
	return (bool)allowedPitchesTree.getProperty("note" + String(noteNum) + "_IsAllowedFor_" + paramID);
}

void RandomizationOptions::setNoteIsAllowedForParam(int noteNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedValues ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::allowedLFOfrequencies ||
		optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	jassert(optionsType == RandomizationOptionsType::allowedSeqTrackStepValues ?
		noteNum < randomization::numberOfNotesAndBentNotes : noteNum < randomization::numberOfNotes);
	auto paramID{ info.IDfor(paramIndex).toString() };
	allowedPitchesTree.setProperty("note" + String(noteNum) + "_IsAllowedFor_" + paramID, (bool)true, nullptr);
}

void RandomizationOptions::setNoteIsNotAllowedForParam(int noteNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedValues ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::allowedLFOfrequencies ||
		optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	jassert(optionsType == RandomizationOptionsType::allowedSeqTrackStepValues ?
		noteNum < randomization::numberOfNotesAndBentNotes : noteNum < randomization::numberOfNotes);
	auto paramID{ info.IDfor(paramIndex).toString() };
	allowedPitchesTree.setProperty("note" + String(noteNum) + "_IsAllowedFor_" + paramID, (bool)false, nullptr);
}

const bool RandomizationOptions::noNoteIsAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedValues ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::allowedLFOfrequencies ||
		optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	auto numberOfNotes{ optionsType == RandomizationOptionsType::allowedSeqTrackStepValues ? 
		randomization::numberOfNotesAndBentNotes : randomization::numberOfNotes };
	auto atLeastOneNoteIsAllowed{ (bool)false };
	auto noNoteIsAllowed{ (bool)true };
	for (auto noteNum = 0; noteNum != numberOfNotes; ++noteNum) {
		if (noteIsAllowedForParam(noteNum, paramIndex))
			return atLeastOneNoteIsAllowed;
	}
	return noNoteIsAllowed;
}

const bool RandomizationOptions::octaveIsAllowedForParam(int octaveNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert((optionsType == RandomizationOptionsType::allowedValues && octaveNum < randomization::numberOfOctaves) ||
		(optionsType == RandomizationOptionsType::lpfFreq && octaveNum < randomization::numberOfOctavesForLPFfreq) ||
		(optionsType == RandomizationOptionsType::allowedLFOfrequencies && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps) ||
		(optionsType == RandomizationOptionsType::allowedSeqTrackStepValues && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps));
	auto paramID{ info.IDfor(paramIndex).toString() };
	return (bool)allowedPitchesTree.getProperty("octave" + String(octaveNum) + "_IsAllowedFor_" + paramID);
}

void RandomizationOptions::setOctaveIsAllowedForParam(int octaveNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert((optionsType == RandomizationOptionsType::allowedValues && octaveNum < randomization::numberOfOctaves) ||
		(optionsType == RandomizationOptionsType::lpfFreq && octaveNum < randomization::numberOfOctavesForLPFfreq) ||
		(optionsType == RandomizationOptionsType::allowedLFOfrequencies && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps) ||
		(optionsType == RandomizationOptionsType::allowedSeqTrackStepValues && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps));
	auto paramID{ info.IDfor(paramIndex).toString() };
	allowedPitchesTree.setProperty("octave" + String(octaveNum) + "_IsAllowedFor_" + paramID, (bool)true, nullptr);
}

void RandomizationOptions::setOctaveIsNotAllowedForParam(int octaveNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert((optionsType == RandomizationOptionsType::allowedValues && octaveNum < randomization::numberOfOctaves) ||
		(optionsType == RandomizationOptionsType::lpfFreq && octaveNum < randomization::numberOfOctavesForLPFfreq) ||
		(optionsType == RandomizationOptionsType::allowedLFOfrequencies && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps) ||
		(optionsType == RandomizationOptionsType::allowedSeqTrackStepValues && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps));
	auto paramID{ info.IDfor(paramIndex).toString() };
	allowedPitchesTree.setProperty("octave" + String(octaveNum) + "_IsAllowedFor_" + paramID, (bool)false, nullptr);
}

const bool RandomizationOptions::noOctaveIsAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedValues ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::allowedLFOfrequencies ||
		optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	int numberOfOctaves{ randomization::numberOfOctaves };
	if (optionsType == RandomizationOptionsType::lpfFreq)
		numberOfOctaves = randomization::numberOfOctavesForLPFfreq;
	if (optionsType == RandomizationOptionsType::allowedLFOfrequencies || optionsType == RandomizationOptionsType::allowedSeqTrackStepValues)
		numberOfOctaves = randomization::numberOfOctavesForLFOfreqAndSeqSteps;
	auto atLeastOneOctaveIsAllowed{ (bool)false };
	auto noOctaveIsAllowed{ (bool)true };
	for (auto octaveNum = 0; octaveNum != numberOfOctaves; ++octaveNum) {
		if (octaveIsAllowedForParam(octaveNum, paramIndex))
			return atLeastOneOctaveIsAllowed;
	}
	return noOctaveIsAllowed;
}

const bool RandomizationOptions::pitchIsAllowedForParam(int pitchNum, uint8 paramIndex) {
	jassert(pitchNum > -1);
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert((optionsType == RandomizationOptionsType::allowedValues && pitchNum < randomization::numberOfPitchesForOscillators) ||
		(optionsType == RandomizationOptionsType::lpfFreq && pitchNum < randomization::numberOfPitchedFreqForLPF) ||
		(optionsType == RandomizationOptionsType::allowedLFOfrequencies && pitchNum < randomization::numberOfPitchedFreqForLFOs) ||
		(optionsType == RandomizationOptionsType::allowedSeqTrackStepValues && pitchNum < randomization::numberOfPitchesForSeqSteps));
	auto numberOfNotes{ optionsType == RandomizationOptionsType::allowedSeqTrackStepValues ?
		randomization::numberOfNotesAndBentNotes : randomization::numberOfNotes };
	auto noteIsAllowed{ noteIsAllowedForParam(pitchNum % numberOfNotes, paramIndex) };
	auto octaveIsAllowed{ octaveIsAllowedForParam(pitchNum / numberOfNotes, paramIndex) };
	return noteIsAllowed && octaveIsAllowed;
}

void RandomizationOptions::checkIfOnlyOneValueIsAllowedForPitchParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedValues);
	Array<uint8> allowedPitches;
	for (auto pitchNum = (uint8)0; pitchNum != randomization::numberOfPitchesForOscillators; ++pitchNum) {
		if (pitchIsAllowedForParam(pitchNum, paramIndex))
			allowedPitches.add(pitchNum);
	}
	if (allowedPitches.size() == 1)
		setValueIsOnlyOneAllowedForParam_z(allowedPitches[0], paramIndex);
	else
		setMoreThanOneValueIsAllowedForParam_z(paramIndex);
}

void RandomizationOptions::checkIfHighestOctaveIsOnlyOneAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedValues ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::allowedLFOfrequencies ||
		optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	int numberOfOctaves{ randomization::numberOfOctaves };
	if (optionsType == RandomizationOptionsType::lpfFreq)
		numberOfOctaves = randomization::numberOfOctavesForLPFfreq;
	if (optionsType == RandomizationOptionsType::allowedLFOfrequencies || optionsType == RandomizationOptionsType::allowedSeqTrackStepValues)
		numberOfOctaves = randomization::numberOfOctavesForLFOfreqAndSeqSteps;
	Array<int> allowedOctaves;
	for (auto octaveNum = 0; octaveNum != numberOfOctaves; ++octaveNum) {
		if (octaveIsAllowedForParam(octaveNum, paramIndex))
			allowedOctaves.add(octaveNum);
	}
	if (allowedOctaves.size() == 1 && allowedOctaves[0] == (numberOfOctaves - 1))
		setHighestOctaveIsOnlyOneAllowedForParam(paramIndex);
	else
		setHighestOctaveIsNotOnlyOneAllowedForParam(paramIndex);
}

const bool RandomizationOptions::highestOctaveIsOnlyOneAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedValues ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::allowedLFOfrequencies ||
		optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto highestOctaveIsOnlyOneAllowed{ (bool)allowedPitchesTree.getProperty(ID::randomization_HighestOctaveIsOnlyOneAllowedFor_.toString() + paramID)};
	return highestOctaveIsOnlyOneAllowed;
}

void RandomizationOptions::setHighestOctaveIsOnlyOneAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedValues ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::allowedLFOfrequencies ||
		optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	auto paramID{ info.IDfor(paramIndex).toString() };
	allowedPitchesTree.setProperty(ID::randomization_HighestOctaveIsOnlyOneAllowedFor_.toString() + paramID, (bool)true, nullptr);
}

void RandomizationOptions::setHighestOctaveIsNotOnlyOneAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedValues ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::allowedLFOfrequencies ||
		optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	auto paramID{ info.IDfor(paramIndex).toString() };
	allowedPitchesTree.setProperty(ID::randomization_HighestOctaveIsOnlyOneAllowedFor_.toString() + paramID, (bool)false, nullptr);
}

void RandomizationOptions::checkIfHighestOctaveIsOnlyOneAllowedForAllStepsInSeqTrack(int trackNum) {
	int numberOfOctaves{ randomization::numberOfOctavesForLFOfreqAndSeqSteps };
	Array<int> allowedOctaves;
	for (auto octaveNum = 0; octaveNum != numberOfOctaves; ++octaveNum) {
		if (octaveIsAllowedForAllStepsInSeqTrack(octaveNum, trackNum))
			allowedOctaves.add(octaveNum);
	}
	if (allowedOctaves.size() == 1 && allowedOctaves[0] == (numberOfOctaves - 1))
		setHighestOctaveIsOnlyOneAllowedForAllStepsInSeqTrack(trackNum);
	else
		setHighestOctaveIsNotOnlyOneAllowedForAllStepsInSeqTrack(trackNum);
}

const bool RandomizationOptions::highestOctaveIsOnlyOneAllowedForAllStepsInSeqTrack(int trackNum) {
	auto highestOctaveIsOnlyOneAllowed{ (bool)allowedPitchesTree.getProperty(ID::randomization_HighestOctaveIsOnlyOneAllowedFor_.toString() + "AllStepsInSeqTrack" + (String)trackNum) };
	return highestOctaveIsOnlyOneAllowed;
}

void RandomizationOptions::setHighestOctaveIsOnlyOneAllowedForAllStepsInSeqTrack(int trackNum) {
	allowedPitchesTree.setProperty(ID::randomization_HighestOctaveIsOnlyOneAllowedFor_.toString() + "AllStepsInSeqTrack" + (String)trackNum, (bool)true, nullptr);
}

void RandomizationOptions::setHighestOctaveIsNotOnlyOneAllowedForAllStepsInSeqTrack(int trackNum) {
	allowedPitchesTree.setProperty(ID::randomization_HighestOctaveIsOnlyOneAllowedFor_.toString() + "AllStepsInSeqTrack" + (String)trackNum, (bool)false, nullptr);
}

const uint8 RandomizationOptions::minValueAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::valueRange || 
		optionsType == RandomizationOptionsType::lpfFreq || 
		optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	auto paramID(info.IDfor(paramIndex).toString());
	int minValueAllowed{ allowedValueRangesTree.getProperty("minValueAllowedFor_" + paramID) };
	return (uint8)minValueAllowed;
}

void RandomizationOptions::setMinValueAllowedForParam(uint8 newMin, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::valueRange ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	auto maxValue{ info.maxValueFor(paramIndex) };
	jassert(newMin <= maxValue);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedValueRangesTree.setProperty("minValueAllowedFor_" + paramID, newMin, nullptr);
}

const uint8 RandomizationOptions::maxValueAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::valueRange ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	auto paramID(info.IDfor(paramIndex).toString());
	int maxValueAllowed{ allowedValueRangesTree.getProperty("maxValueAllowedFor_" + paramID) };
	return (uint8)maxValueAllowed;
}

void RandomizationOptions::setMaxValueAllowedForParam(uint8 newMax, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::valueRange ||
		optionsType == RandomizationOptionsType::lpfFreq ||
		optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	auto maxValue{ info.maxValueFor(paramIndex) };
	jassert(newMax <= maxValue);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedValueRangesTree.setProperty("maxValueAllowedFor_" + paramID, newMax, nullptr);
}

const bool RandomizationOptions::oscShapeIsAllowedForParam(int shapeIndex, uint8 paramIndex) {
	jassert(shapeIndex >= (int)OscWaveShape::off && shapeIndex <= (int)OscWaveShape::pulse);
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::oscShape);
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto propertyID{ "shape_" + (String)shapeIndex + "_IsAllowed" };
	auto paramTree{ allowedValuesTrees.getOrCreateChildWithName(paramID, nullptr).getOrCreateChildWithName("allowedShapes", nullptr)};
	return paramTree.hasProperty(propertyID);
}

void RandomizationOptions::setOscShapeIsAllowedForParam(int shapeIndex, uint8 paramIndex) {
	jassert(shapeIndex >= (int)OscWaveShape::off && shapeIndex <= (int)OscWaveShape::pulse);
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::oscShape);
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto propertyID{ "shape_" + (String)shapeIndex + "_IsAllowed" };
	auto paramTree{ allowedValuesTrees.getOrCreateChildWithName(paramID, nullptr).getOrCreateChildWithName("allowedShapes", nullptr) };
	if (!paramTree.hasProperty(propertyID))
		paramTree.setProperty(propertyID, shapeIndex, nullptr);
}

void RandomizationOptions::setOscShapeIsNotAllowedForParam(int shapeIndex, uint8 paramIndex) {
	jassert(shapeIndex >= (int)OscWaveShape::off && shapeIndex <= (int)OscWaveShape::pulse);
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::oscShape);
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto propertyID{ "shape_" + (String)shapeIndex + "_IsAllowed" };
	auto paramTree{ allowedValuesTrees.getOrCreateChildWithName(paramID, nullptr).getOrCreateChildWithName("allowedShapes", nullptr) };
	if (paramTree.hasProperty(propertyID))
		paramTree.removeProperty(propertyID, nullptr);
}

void RandomizationOptions::setOscShapeIsTheOnlyAllowedForParam(int shapeIndex, uint8 paramIndex) {
	jassert(shapeIndex >= (int)OscWaveShape::off && shapeIndex <= (int)OscWaveShape::pulse);
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::oscShape);
	for (auto shape = (int)OscWaveShape::off; shape <= (int)OscWaveShape::pulse; ++shape) {
		if (shape == shapeIndex)
			setOscShapeIsAllowedForParam(shape, paramIndex);
		else
			setOscShapeIsNotAllowedForParam(shape, paramIndex);
	}
}

const bool RandomizationOptions::noOscShapeIsAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::oscShape);
	auto atLeastOneOscShapeIsAllowed{ (bool)false };
	auto noOscShapeIsAllowed{ (bool)true };
	for (auto shape = (int)OscWaveShape::off; shape <= (int)OscWaveShape::pulse; ++shape) {
		if (oscShapeIsAllowedForParam(shape, paramIndex))
			return atLeastOneOscShapeIsAllowed;
	}
	return noOscShapeIsAllowed;
}

const bool RandomizationOptions::pulseWidthIsAllowedForParam(int pulseWidth, uint8 paramIndex) {
	jassert(pulseWidth > -1 && pulseWidth < 100);
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::oscShape);
	auto paramID(info.IDfor(paramIndex).toString());
	auto propertyID{ "pulseWidth_" + (String)pulseWidth + "_IsAllowed" };
	auto paramTree{ allowedValuesTrees.getOrCreateChildWithName(paramID, nullptr).getOrCreateChildWithName("allowedPulseWidths", nullptr) };
	return paramTree.hasProperty(propertyID);
}

void RandomizationOptions::setPulseWidthIsAllowedForParam(int pulseWidth, uint8 paramIndex) {
	jassert(pulseWidth > -1 && pulseWidth < 100);
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::oscShape);
	auto paramID(info.IDfor(paramIndex).toString());
	auto propertyID{ "pulseWidth_" + (String)pulseWidth + "_IsAllowed" };
	auto paramTree{ allowedValuesTrees.getOrCreateChildWithName(paramID, nullptr).getOrCreateChildWithName("allowedPulseWidths", nullptr) };
	if (!paramTree.hasProperty(propertyID))
		paramTree.setProperty(propertyID, pulseWidth + 4, nullptr);
}

void RandomizationOptions::setPulseWidthIsNotAllowedForParam(int pulseWidth, uint8 paramIndex) {
	jassert(pulseWidth > -1 && pulseWidth < 100);
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::oscShape);
	auto paramID(info.IDfor(paramIndex).toString());
	auto propertyID{ "pulseWidth_" + (String)pulseWidth + "_IsAllowed" };
	auto paramTree{ allowedValuesTrees.getOrCreateChildWithName(paramID, nullptr).getOrCreateChildWithName("allowedPulseWidths", nullptr) };
	if (paramTree.hasProperty(propertyID))
		paramTree.removeProperty(propertyID, nullptr);
}

const bool RandomizationOptions::noPulseWidthIsAllowedForParam(uint8 /*paramIndex*/)
{
	return false;
}

const uint8 RandomizationOptions::minPulseWidthAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::oscShape);
	auto paramID(info.IDfor(paramIndex).toString());
	int minPulseWidthAllowed{ allowedOscShapesTree.getProperty("minPulseWidthAllowedFor_" + paramID) };
	return (uint8)minPulseWidthAllowed;
}

void RandomizationOptions::setMinPulseWidthAllowedForParam(uint8 newMin, uint8 paramIndex) {
	jassert(newMin <= params::maxPulseWidth);
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::oscShape);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedOscShapesTree.setProperty("minPulseWidthAllowedFor_" + paramID, newMin, nullptr);
}

const uint8 RandomizationOptions::maxPulseWidthAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::oscShape);
	auto paramID(info.IDfor(paramIndex).toString());
	int maxPulseWidthAllowed{ allowedOscShapesTree.getProperty("maxPulseWidthAllowedFor_" + paramID) };
	return (uint8)maxPulseWidthAllowed;
}

void RandomizationOptions::setMaxPulseWidthAllowedForParam(uint8 newMax, uint8 paramIndex) {
	jassert(newMax <= params::maxPulseWidth);
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::oscShape);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedOscShapesTree.setProperty("maxPulseWidthAllowedFor_" + paramID, newMax, nullptr);
}

void RandomizationOptions::checkIfOnlyOneValueIsAllowedForOscShapeParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::oscShape);
	Array<uint8> allowedShapes;
	for (auto shape = (int)OscWaveShape::off; shape <= (int)OscWaveShape::pulse; ++shape) {
		if (oscShapeIsAllowedForParam(shape, paramIndex))
			allowedShapes.add((uint8)shape);
	}
	if (allowedShapes.size() == 1) {
		if (allowedShapes[0] != (int)OscWaveShape::pulse)
			setValueIsOnlyOneAllowedForParam_z(allowedShapes[0], paramIndex);
		else {
			auto minPulseWidth{ minPulseWidthAllowedForParam(paramIndex) };
			auto maxPulseWidth{ maxPulseWidthAllowedForParam(paramIndex) };
			if (minPulseWidth == maxPulseWidth)
				setValueIsOnlyOneAllowedForParam_z(allowedShapes[0] + minPulseWidth, paramIndex);
			else
				setMoreThanOneValueIsAllowedForParam_z(paramIndex);
		}
	}
	else
		setMoreThanOneValueIsAllowedForParam_z(paramIndex);
}

const bool RandomizationOptions::comboBoxItemIsAllowedForParam(int itemNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::comboBoxes);
	jassert(itemNum < info.numberOfStepsFor(paramIndex));
	auto paramID(info.IDfor(paramIndex).toString());
	return (bool)allowedComboBoxItemsTree.getProperty("comboBoxItem" + (String)itemNum + "_IsAllowedFor_" + paramID);
}

void RandomizationOptions::setComboBoxItemIsAllowedForParam(int itemNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::comboBoxes);
	jassert(itemNum < info.numberOfStepsFor(paramIndex));
	auto paramID(info.IDfor(paramIndex).toString());
	allowedComboBoxItemsTree.setProperty("comboBoxItem" + (String)itemNum + "_IsAllowedFor_" + paramID, (bool)true, nullptr);
}

void RandomizationOptions::setComboBoxItemIsNotAllowedForParam(int itemNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::comboBoxes);
	jassert(itemNum < info.numberOfStepsFor(paramIndex));
	auto paramID(info.IDfor(paramIndex).toString());
	allowedComboBoxItemsTree.setProperty("comboBoxItem" + (String)itemNum + "_IsAllowedFor_" + paramID, (bool)false, nullptr);
}

const bool RandomizationOptions::noComboBoxItemIsAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::comboBoxes);
	auto atLeastOneItemIsAllowed{ (bool)false };
	auto noItemIsAllowed{ (bool)true };
	for (auto item = 0; item != info.numberOfStepsFor(paramIndex); ++item) {
		if (comboBoxItemIsAllowedForParam(item, paramIndex))
			return atLeastOneItemIsAllowed;
	}
	return noItemIsAllowed;
}

void RandomizationOptions::addListenerToLPFfreqOptionsTree(ValueTree::Listener* listener) {
	lpfFreqOptionsTree.addListener(listener);
}

void RandomizationOptions::removeListenerFromLPFfreqOptionsTree(ValueTree::Listener* listener) {
	lpfFreqOptionsTree.removeListener(listener);
}

const bool RandomizationOptions::randomizationModeForLPFfreqIsPitches() {
	return lpfFreqOptionsTree.getProperty("randomizationModeIsPitches");
}

const bool RandomizationOptions::randomizationModeForLPFfreqIsValueRange() {
	return lpfFreqOptionsTree.getProperty("randomizationModeIsValueRange");
}

void RandomizationOptions::setRandomizationModeForLPFfreqToPitches() {
	lpfFreqOptionsTree.setProperty("randomizationModeIsPitches", (bool)true, nullptr);
	lpfFreqOptionsTree.setProperty("randomizationModeIsValueRange", (bool)false, nullptr);
}

void RandomizationOptions::setRandomizationModeForLPFfreqToValueRange() {
	lpfFreqOptionsTree.setProperty("randomizationModeIsPitches", (bool)false, nullptr);
	lpfFreqOptionsTree.setProperty("randomizationModeIsValueRange", (bool)true, nullptr);
}

void RandomizationOptions::checkIfOnlyOneValueIsAllowedForLPFfreqParam() {
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(ID::lpfFreq.toString()) };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lpfFreq);
	if (randomizationModeForLPFfreqIsValueRange()) {
		auto minValue{ minValueAllowedForParam(paramIndex) };
		auto maxValue{ maxValueAllowedForParam(paramIndex) };
		if (minValue == maxValue) {
			setValueIsOnlyOneAllowedForParam_z(minValue, paramIndex);
		}
		else
			setMoreThanOneValueIsAllowedForParam_z(paramIndex);
	}
	if (randomizationModeForLPFfreqIsPitches()) {
		Array<uint8> allowedFrequencies;
		for (uint8 freq = 0; freq != (uint8)randomization::numberOfPitchedFreqForLPF; ++freq) {
			if (pitchIsAllowedForParam(freq, paramIndex)) {
				allowedFrequencies.add(freq);
			}
		}
		if (allowedFrequencies.size() == 1)
			setValueIsOnlyOneAllowedForParam_z(allowedFrequencies[0], paramIndex);
		else
			setMoreThanOneValueIsAllowedForParam_z(paramIndex);
	}
}

const bool RandomizationOptions::pitchedFreqAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	return (bool)allowedFrequencyTypesTree.getProperty("pitchedFreqAreAllowedFor_" + paramID);
}

const bool RandomizationOptions::pitchedFreqAreNotAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	return (bool)allowedFrequencyTypesTree.getProperty("pitchedFreqAreNotAllowedFor_" + paramID);
}

void RandomizationOptions::setPitchedFreqAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("pitchedFreqAreAllowedFor_" + paramID, (bool)true, nullptr);
	allowedFrequencyTypesTree.setProperty("pitchedFreqAreNotAllowedFor_" + paramID, (bool)false, nullptr);
}

void RandomizationOptions::setPitchedFreqAreNotAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("pitchedFreqAreAllowedFor_" + paramID, (bool)false, nullptr);
	allowedFrequencyTypesTree.setProperty("pitchedFreqAreNotAllowedFor_" + paramID, (bool)true, nullptr);
}

const bool RandomizationOptions::moreThanOnePitchedFreqIsAllowedForParam(uint8 paramIndex) {
	auto atLeastOnePitchedFreqIsAllowed{ (bool)false };
	auto onlyOnePitchedFreqIsAllowed{ (bool)false };
	auto moreThanOnePitchedFreqIsAllowed{ (bool)true };
	for (uint8 freq = 0; freq != randomization::numberOfPitchedFreqForLFOs; ++freq) {
		if (pitchIsAllowedForParam(freq, paramIndex)) {
			if (atLeastOnePitchedFreqIsAllowed)
				return moreThanOnePitchedFreqIsAllowed;
			else atLeastOnePitchedFreqIsAllowed = true;
		}
	}
	return onlyOnePitchedFreqIsAllowed;
}

const bool RandomizationOptions::unsyncedFreqAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	return (bool)allowedFrequencyTypesTree.getProperty("unsyncedFreqAreAllowedFor_" + paramID);
}

const bool RandomizationOptions::unsyncedFreqAreNotAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	return (bool)allowedFrequencyTypesTree.getProperty("unsyncedFreqAreNotAllowedFor_" + paramID);
}

void RandomizationOptions::setUnsyncedFreqAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("unsyncedFreqAreAllowedFor_" + paramID, (bool)true, nullptr);
	allowedFrequencyTypesTree.setProperty("unsyncedFreqAreNotAllowedFor_" + paramID, (bool)false, nullptr);
}

void RandomizationOptions::setUnsyncedFreqAreNotAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("unsyncedFreqAreAllowedFor_" + paramID, (bool)false, nullptr);
	allowedFrequencyTypesTree.setProperty("unsyncedFreqAreNotAllowedFor_" + paramID, (bool)true, nullptr);
}

const uint8 RandomizationOptions::minUnsyncedFreqForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	int minFreq{ allowedFrequencyTypesTree.getProperty("minUnsyncedFreqFor_" + paramID) };
	return (uint8)minFreq;
}

void RandomizationOptions::setMinUnsyncedFreqForParam(uint8 newMin, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	jassert(newMin <= params::maxUnsyncedLFOfreq);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("minUnsyncedFreqFor_" + paramID, newMin, nullptr);
}

const uint8 RandomizationOptions::maxUnsyncedFreqForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	int maxFreq{ allowedFrequencyTypesTree.getProperty("maxUnsyncedFreqFor_" + paramID) };
	return (uint8)maxFreq;
}

void RandomizationOptions::setMaxUnsyncedFreqForParam(uint8 newMax, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	jassert(newMax <= params::maxUnsyncedLFOfreq);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("maxUnsyncedFreqFor_" + paramID, newMax, nullptr);
}

const bool RandomizationOptions::moreThanOneUnsyncedFreqIsAllowedForParam(uint8 paramIndex) {
	auto onlyOneUnsyncedFreqIsAllowed{ (bool)false };
	auto moreThanOneUnsyncedFreqIsAllowed{ (bool)true };
	auto minUnsyncedFreq{ minUnsyncedFreqForParam(paramIndex) };
	auto maxUnsyncedFreq{ maxUnsyncedFreqForParam(paramIndex) };
	if (minUnsyncedFreq == maxUnsyncedFreq)
		return onlyOneUnsyncedFreqIsAllowed;
	else
		return moreThanOneUnsyncedFreqIsAllowed;
}

const bool RandomizationOptions::syncedFreqAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	return (bool)allowedFrequencyTypesTree.getProperty("syncedFreqAreAllowedFor_" + paramID);
}

const bool RandomizationOptions::syncedFreqAreNotAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	return (bool)allowedFrequencyTypesTree.getProperty("syncedFreqAreNotAllowedFor_" + paramID);
}

void RandomizationOptions::setSyncedFreqAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("syncedFreqAreAllowedFor_" + paramID, (bool)true, nullptr);
	allowedFrequencyTypesTree.setProperty("syncedFreqAreNotAllowedFor_" + paramID, (bool)false, nullptr);
}

void RandomizationOptions::setSyncedFreqAreNotAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("syncedFreqAreAllowedFor_" + paramID, (bool)false, nullptr);
	allowedFrequencyTypesTree.setProperty("syncedFreqAreNotAllowedFor_" + paramID, (bool)true, nullptr);
}

const bool RandomizationOptions::syncedFreqIsAllowedForParam(int syncedFreqNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	return (bool)allowedFrequencyTypesTree.getProperty("syncedFreq" + (String)syncedFreqNum + "_IsAllowedFor_" + paramID);
}

void RandomizationOptions::setSyncedFreqIsAllowedForParam(int syncedFreqNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("syncedFreq" + (String)syncedFreqNum + "_IsAllowedFor_" + paramID, (bool)true, nullptr);
}

void RandomizationOptions::setSyncedFreqIsNotAllowedForParam(int syncedFreqNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto paramID(info.IDfor(paramIndex).toString());
	allowedFrequencyTypesTree.setProperty("syncedFreq" + (String)syncedFreqNum + "_IsAllowedFor_" + paramID, (bool)false, nullptr);
}

const bool RandomizationOptions::noSyncedFreqAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	auto atLeastOneSyncedFreqIsAllowed{ (bool)false };
	auto noSyncedFreqIsAllowed{ (bool)true };
	for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
		if (syncedFreqIsAllowedForParam(freqNum, paramIndex))
			return atLeastOneSyncedFreqIsAllowed;
	}
	return noSyncedFreqIsAllowed;
}

const bool RandomizationOptions::moreThanOneSyncedFreqIsAllowedForParam(uint8 paramIndex) {
	auto atLeastOneSyncedFreqIsAllowed{ (bool)false };
	auto onlyOneSyncedFreqIsAllowed{ (bool)false };
	auto moreThanOneSyncedFreqIsAllowed{ (bool)true };
	for (uint8 freq = 0; freq != randomization::numberOfSyncedFreqForLFOs; ++freq) {
		if (syncedFreqIsAllowedForParam(freq, paramIndex)) {
			if (atLeastOneSyncedFreqIsAllowed)
				return moreThanOneSyncedFreqIsAllowed;
			else atLeastOneSyncedFreqIsAllowed = true;
		}
	}
	return onlyOneSyncedFreqIsAllowed;
}

const bool RandomizationOptions::noFreqAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	if (pitchedFreqAreAllowedForParam(paramIndex) || syncedFreqAreAllowedForParam(paramIndex) || unsyncedFreqAreAllowedForParam(paramIndex))
		return false;
	else
		return true;
}

void RandomizationOptions::checkIfOnlyOneValueIsAllowedForLFOfreqParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedLFOfrequencies);
	Array<uint8> allowedFrequencies;
	if (unsyncedFreqAreAllowedForParam(paramIndex)) {
		auto minUnsyncedFreq{ minUnsyncedFreqForParam(paramIndex) };
		auto maxUnsyncedFreq{ maxUnsyncedFreqForParam(paramIndex) };
		for (auto freq = minUnsyncedFreq; freq <= maxUnsyncedFreq; ++freq)
			allowedFrequencies.add(freq);
		if (allowedFrequencies.size() > 1) {
			setMoreThanOneValueIsAllowedForParam_z(paramIndex);
			return;
		}
	}
	if (pitchedFreqAreAllowedForParam(paramIndex)) {
		if (allowedFrequencies.size() > 0) {
			setMoreThanOneValueIsAllowedForParam_z(paramIndex);
			return;
		}
		for (uint8 freq = 0; freq != (uint8)randomization::numberOfPitchedFreqForLFOs; ++freq) {
			if (pitchIsAllowedForParam(freq, paramIndex)) {
				auto freqWithOffset{ uint8(freq + params::firstPitchedLFOfreq) };
				allowedFrequencies.add(freqWithOffset);
			}
		}
		if (allowedFrequencies.size() > 1) {
			setMoreThanOneValueIsAllowedForParam_z(paramIndex);
			return;
		}
	}
	if (syncedFreqAreAllowedForParam(paramIndex)) {
		if (allowedFrequencies.size() > 0) {
			setMoreThanOneValueIsAllowedForParam_z(paramIndex);
			return;
		}
		for (uint8 freq = 0; freq != (uint8)randomization::numberOfSyncedFreqForLFOs; ++freq) {
			if (syncedFreqIsAllowedForParam(freq, paramIndex)) {
				auto freqWithOffset{ uint8(freq + params::firstSyncedLFOfreq) };
				allowedFrequencies.add(freqWithOffset);
			}
		}
	}
	if (allowedFrequencies.size() == 1)
		setValueIsOnlyOneAllowedForParam_z(allowedFrequencies[0], paramIndex);
	else
		setMoreThanOneValueIsAllowedForParam_z(paramIndex);
}

void RandomizationOptions::addListenerToRepeatValuesOptionsTree(ValueTree::Listener* listener) {
	repeatValuesOptionsTree.addListener(listener);
}

void RandomizationOptions::removeListenerFromRepeatValuesOptionsTree(ValueTree::Listener* listener) {
	repeatValuesOptionsTree.removeListener(listener);
}

const bool RandomizationOptions::repeatValuesAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType != RandomizationOptionsType::none);
	auto paramID(info.IDfor(paramIndex).toString());
	return (bool)repeatValuesOptionsTree.getProperty("repeatValuesAreAllowedFor_" + paramID);
}

const bool RandomizationOptions::repeatValuesAreNotAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType != RandomizationOptionsType::none);
	auto paramID(info.IDfor(paramIndex).toString());
	return (bool)repeatValuesOptionsTree.getProperty("repeatValuesAreNotAllowedFor_" + paramID);
}

void RandomizationOptions::setRepeatValuesAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType != RandomizationOptionsType::none);
	auto paramID(info.IDfor(paramIndex).toString());
	repeatValuesOptionsTree.setProperty("repeatValuesAreAllowedFor_" + paramID, (bool)true, nullptr);
	repeatValuesOptionsTree.setProperty("repeatValuesAreNotAllowedFor_" + paramID, (bool)false, nullptr);
}

void RandomizationOptions::setRepeatValuesAreNotAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType != RandomizationOptionsType::none);
	auto paramID(info.IDfor(paramIndex).toString());
	repeatValuesOptionsTree.setProperty("repeatValuesAreAllowedFor_" + paramID, (bool)false, nullptr);
	repeatValuesOptionsTree.setProperty("repeatValuesAreNotAllowedFor_" + paramID, (bool)true, nullptr);
}

const bool RandomizationOptions::onlyOneValueIsAllowedForParam_z(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID(info.IDfor(paramIndex).toString());
	return (bool)repeatValuesOptionsTree.getProperty(ID::randomization_OnlyOneValueIsAllowedFor_.toString() + paramID);
}

const uint8 RandomizationOptions::onlyAllowedValueForParam_z(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID(info.IDfor(paramIndex).toString());
	auto onlyAllowedValue{ (int)repeatValuesOptionsTree.getProperty("onlyValueAllowedFor_" + paramID) };
	return (uint8)onlyAllowedValue;
}

void RandomizationOptions::setValueIsOnlyOneAllowedForParam_z(uint8 val, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID(info.IDfor(paramIndex).toString());
	repeatValuesOptionsTree.setProperty(ID::randomization_OnlyOneValueIsAllowedFor_.toString() + paramID, (bool)true, nullptr);
	repeatValuesOptionsTree.setProperty(ID::randomization_MoreThanOneValueIsAllowedFor_.toString() + paramID, (bool)false, nullptr);
	repeatValuesOptionsTree.setProperty("onlyValueAllowedFor_" + paramID, val, nullptr);
}

void RandomizationOptions::setMoreThanOneValueIsAllowedForParam_z(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID(info.IDfor(paramIndex).toString());
	repeatValuesOptionsTree.setProperty(ID::randomization_OnlyOneValueIsAllowedFor_.toString() + paramID, (bool)false, nullptr);
	repeatValuesOptionsTree.setProperty(ID::randomization_MoreThanOneValueIsAllowedFor_.toString() + paramID, (bool)true, nullptr);
	repeatValuesOptionsTree.setProperty("onlyValueAllowedFor_" + paramID, (uint8)255, nullptr);
}

const bool RandomizationOptions::repeatValuesAreAllowedForAllStepsInSeqTrack(int trackNum) {
	auto trackNumString{ (String)trackNum };
	return (bool)repeatValuesOptionsTree.getProperty("repeatValuesAreAllowedFor_AllStepsInSeqTrack" + trackNumString);
}

const bool RandomizationOptions::repeatValuesAreNotAllowedForAllStepsInSeqTrack(int trackNum) {
	auto trackNumString{ (String)trackNum };
	return (bool)repeatValuesOptionsTree.getProperty("repeatValuesAreNotAllowedFor_AllStepsInSeqTrack" + trackNumString);
}

void RandomizationOptions::setRepeatValuesAreAllowedForAllStepsInSeqTrack(int trackNum) {
	auto trackNumString{ (String)trackNum };
	repeatValuesOptionsTree.setProperty("repeatValuesAreAllowedFor_AllStepsInSeqTrack" + trackNumString, (bool)true, nullptr);
	repeatValuesOptionsTree.setProperty("repeatValuesAreNotAllowedFor_AllStepsInSeqTrack" + trackNumString, (bool)false, nullptr);
}

void RandomizationOptions::setRepeatValuesAreNotAllowedForAllStepsInSeqTrack(int trackNum) {
	auto trackNumString{ (String)trackNum };
	repeatValuesOptionsTree.setProperty("repeatValuesAreAllowedFor_AllStepsInSeqTrack" + trackNumString, (bool)false, nullptr);
	repeatValuesOptionsTree.setProperty("repeatValuesAreNotAllowedFor_AllStepsInSeqTrack" + trackNumString, (bool)true, nullptr);
}

const bool RandomizationOptions::onlyOneValueIsAllowedForAllStepsInSeqTrack(int trackNum) {
	auto trackNumString{ (String)trackNum };
	return (bool)repeatValuesOptionsTree.getProperty(ID::randomization_OnlyOneValueIsAllowedFor_.toString() + "AllStepsInSeqTrack" + trackNumString);
}

const uint8 RandomizationOptions::onlyAllowedValueForAllStepsInSeqTrack(int trackNum) {
	auto trackNumString{ (String)trackNum };
	auto onlyAllowedValue{ (int)repeatValuesOptionsTree.getProperty("onlyValueAllowedFor_AllStepsInSeqTrack" + trackNumString) };
	return (uint8)onlyAllowedValue;
}

void RandomizationOptions::setValueIsOnlyOneAllowedForAllStepsInSeqTrack(uint8 val, int trackNum) {
	auto trackNumString{ (String)trackNum };
	repeatValuesOptionsTree.setProperty(ID::randomization_OnlyOneValueIsAllowedFor_.toString() + "AllStepsInSeqTrack" + trackNumString, (bool)true, nullptr);
	repeatValuesOptionsTree.setProperty(ID::randomization_MoreThanOneValueIsAllowedFor_.toString() + "AllStepsInSeqTrack" + trackNumString, (bool)false, nullptr);
	repeatValuesOptionsTree.setProperty("onlyValueAllowedFor_AllStepsInSeqTrack" + trackNumString, val, nullptr);
}

void RandomizationOptions::setMoreThanOneValueIsAllowedForAllStepsInSeqTrack(int trackNum) {
	auto trackNumString{ (String)trackNum };
	repeatValuesOptionsTree.setProperty(ID::randomization_OnlyOneValueIsAllowedFor_.toString() + "AllStepsInSeqTrack" + trackNumString, (bool)false, nullptr);
	repeatValuesOptionsTree.setProperty(ID::randomization_MoreThanOneValueIsAllowedFor_.toString() + "AllStepsInSeqTrack" + trackNumString, (bool)true, nullptr);
}

void RandomizationOptions::addListenerToSeqTrackOptionsTree(ValueTree::Listener* listener) {
	seqTrackOptionsTree.addListener(listener);
}

void RandomizationOptions::removeListenerFromSeqTrackOptionsTree(ValueTree::Listener* listener) {
	seqTrackOptionsTree.removeListener(listener);
}

const bool RandomizationOptions::editModeForSeqTrackIsAllSteps(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	return !(bool)seqTrackOptionsTree.getProperty("editModeIsSelectedStepForSeqTrack" + (String)trackNum);
}

const bool RandomizationOptions::editModeForSeqTrackIsSelectedStep(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	return (bool)seqTrackOptionsTree.getProperty("editModeIsSelectedStepForSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setEditModeForSeqTrackToAllSteps(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("editModeIsSelectedStepForSeqTrack" + (String)trackNum, (bool)false, nullptr);
}

void RandomizationOptions::setEditModeForSeqTrackToSelectedStep(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("editModeIsSelectedStepForSeqTrack" + (String)trackNum, (bool)true, nullptr);
}

const int RandomizationOptions::stepSelectedForEditingInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	return (int)seqTrackOptionsTree.getProperty("stepSelectedForEditingInSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setStepSelectedForEditingInSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("stepSelectedForEditingInSeqTrack" + (String)trackNum, stepNum, nullptr);
}

const float RandomizationOptions::probabilityOfRestForAllStepsInSeqTrack1() {
	float probability{ seqTrackOptionsTree.getProperty("probabilityOfRestFor_AllStepsInSeqTrack1") };
	return probability;
}

void RandomizationOptions::setProbabilityOfRestForAllStepsInSeqTrack1(float newProb) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	seqTrackOptionsTree.setProperty("probabilityOfRestFor_AllStepsInSeqTrack1", newProb, nullptr);
}

const float RandomizationOptions::probabilityOfRestForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	auto paramName{ info.IDfor(paramIndex).toString() };
	if (paramName.fromFirstOccurrenceOf("Track", false, false).upToFirstOccurrenceOf("Step", false, false) == "1") {
		float probability{ seqTrackOptionsTree.getProperty("probabilityOfRestFor_" + paramName) };
		return probability;
	}
	else
		return 0.0f;
}

void RandomizationOptions::setProbabilityOfRestForParam(float newProb, uint8 paramIndex) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	auto paramName{ info.IDfor(paramIndex).toString() };
	jassert(paramName.fromFirstOccurrenceOf("Track", false, false).upToFirstOccurrenceOf("Step", false, false) == "1");
	seqTrackOptionsTree.setProperty("probabilityOfRestFor_" + paramName, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfRepeatValueForAllStepsInSeqTrack(int trackNum) {
	float probability{ seqTrackOptionsTree.getProperty("probabilityOfRepeatValueFor_AllStepsInSeqTrack" + (String)trackNum) };
	return probability;
}

void RandomizationOptions::setProbabilityOfRepeatForAllStepsInSeqTrack(float newProb, int trackNum) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	seqTrackOptionsTree.setProperty("probabilityOfRepeatValueFor_AllStepsInSeqTrack" + (String)trackNum, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfRepeatValueForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	auto paramName{ info.IDfor(paramIndex).toString() };
	float probability{ seqTrackOptionsTree.getProperty("probabilityOfRepeatValueFor_" + paramName) };
	return probability;
}

void RandomizationOptions::setProbabilityOfRepeatValueForParam(float newProb, uint8 paramIndex) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	auto paramName{ info.IDfor(paramIndex).toString() };
	seqTrackOptionsTree.setProperty("probabilityOfRepeatValueFor_" + paramName, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfResetForAllStepsInSeqTrack(int trackNum) {
	float probability{ seqTrackOptionsTree.getProperty("probabilityOfResetFor_AllStepsInSeqTrack" + (String)trackNum) };
	return probability;
}

void RandomizationOptions::setProbabilityOfResetForAllStepsInSeqTrack(float newProb, int trackNum) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	seqTrackOptionsTree.setProperty("probabilityOfResetFor_AllStepsInSeqTrack" + (String)trackNum, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfResetForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	auto paramName{ info.IDfor(paramIndex).toString() };
	float probability{ seqTrackOptionsTree.getProperty("probabilityOfResetFor_" + paramName) };
	return probability;
}

void RandomizationOptions::setProbabilityOfResetForParam(float newProb, uint8 paramIndex) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	auto paramName{ info.IDfor(paramIndex).toString() };
	seqTrackOptionsTree.setProperty("probabilityOfResetFor_" + paramName, newProb, nullptr);
}

const uint8 RandomizationOptions::minValueForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	int minValue{ seqTrackOptionsTree.getProperty("minValueFor_AllStepsInSeqTrack" + (String)trackNum) };
	return (uint8)minValue;
}

void RandomizationOptions::setMinValueForAllStepsInSeqTrack(uint8 newMin, int trackNum) {
	jassert(newMin <= params::maxValueForSeqTrackStep);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("minValueFor_AllStepsInSeqTrack" + (String)trackNum, newMin, nullptr);
}

const uint8 RandomizationOptions::maxValueForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	int maxValue{ seqTrackOptionsTree.getProperty("maxValueFor_AllStepsInSeqTrack" + (String)trackNum) };
	return (uint8)maxValue;
}

void RandomizationOptions::setMaxValueForAllStepsInSeqTrack(uint8 newMax, int trackNum) {
	jassert(newMax <= params::maxValueForSeqTrackStep);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("maxValueFor_AllStepsInSeqTrack" + (String)trackNum, newMax, nullptr);
}

const bool RandomizationOptions::pitchIsAllowedForAllStepsInSeqTrack(int pitchNum, int trackNum) {
	jassert(pitchNum > -1 && pitchNum < randomization::numberOfPitchesForSeqSteps);
	jassert(trackNum > 0 && trackNum < 5);
	auto noteIsAllowed{ noteIsAllowedForAllStepsInSeqTrack(pitchNum % (randomization::numberOfNotesAndBentNotes), trackNum) };
	auto octaveIsAllowed{ octaveIsAllowedForAllStepsInSeqTrack(pitchNum / (randomization::numberOfNotesAndBentNotes), trackNum) };
	return noteIsAllowed && octaveIsAllowed;
}

const bool RandomizationOptions::noteIsAllowedForAllStepsInSeqTrack(int noteNum, int trackNum) {
	jassert(noteNum > -1 && noteNum < (randomization::numberOfNotesAndBentNotes));
	jassert(trackNum > 0 && trackNum < 5);
	return (bool)seqTrackOptionsTree.getProperty("note" + String(noteNum) + "_IsAllowedFor_AllStepsInSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setNoteIsAllowedForAllStepsInSeqTrack(int noteNum, int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("note" + String(noteNum) + "_IsAllowedFor_AllStepsInSeqTrack" + (String)trackNum, (bool)true, nullptr);
}

void RandomizationOptions::setNoteIsNotAllowedForAllStepsInSeqTrack(int noteNum, int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("note" + String(noteNum) + "_IsAllowedFor_AllStepsInSeqTrack" + (String)trackNum, (bool)false, nullptr);
}

const bool RandomizationOptions::noNoteIsAllowedForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto atLeastOneNoteIsAllowed{ (bool)false };
	auto noNoteIsAllowed{ (bool)true };
	for (auto noteNum = 0; noteNum != randomization::numberOfNotesAndBentNotes; ++noteNum) {
		if (noteIsAllowedForAllStepsInSeqTrack(noteNum, trackNum))
			return atLeastOneNoteIsAllowed;
	}
	return noNoteIsAllowed;
}

const bool RandomizationOptions::octaveIsAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps);
	jassert(trackNum > 0 && trackNum < 5);
	return (bool)seqTrackOptionsTree.getProperty("octave" + String(octaveNum) + "_IsAllowedFor_AllStepsInSeqTrack" + (String)trackNum);
}

void RandomizationOptions::setOctaveIsAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("octave" + String(octaveNum) + "_IsAllowedFor_AllStepsInSeqTrack" + (String)trackNum, (bool)true, nullptr);
}

void RandomizationOptions::setOctaveIsNotAllowedForAllStepsInSeqTrack(int octaveNum, int trackNum) {
	jassert(octaveNum > -1 && octaveNum < randomization::numberOfOctavesForLFOfreqAndSeqSteps);
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("octave" + String(octaveNum) + "_IsAllowedFor_AllStepsInSeqTrack" + (String)trackNum, (bool)false, nullptr);
}

const bool RandomizationOptions::noOctaveIsAllowedForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto atLeastOneOctaveIsAllowed{ (bool)false };
	auto noOctaveIsAllowed{ (bool)true };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOfreqAndSeqSteps; ++octaveNum) {
		if (octaveIsAllowedForAllStepsInSeqTrack(octaveNum, trackNum))
			return atLeastOneOctaveIsAllowed;
	}
	return noOctaveIsAllowed;
}

const bool RandomizationOptions::trackDestinationIsAnOscPitchParameter(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	return (bool)seqTrackOptionsTree.getProperty("DestinationForTrack" + String(trackNum) + "_IsAnOscPitchParameter");
}

void RandomizationOptions::setTrackDestinationIsAnOscPitchParameter(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("DestinationForTrack" + String(trackNum) + "_IsAnOscPitchParameter", (bool)true, nullptr);
}

void RandomizationOptions::setTrackDestinationIsNotAnOscPitchParameter(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	seqTrackOptionsTree.setProperty("DestinationForTrack" + String(trackNum) + "_IsAnOscPitchParameter", (bool)false, nullptr);
}

void RandomizationOptions::checkIfOnlyOneValueIsAllowedForSeqStepParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::allowedSeqTrackStepValues);
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto trackNum{ paramID.fromFirstOccurrenceOf("Track", false, false).upToFirstOccurrenceOf("Step", false, false).getIntValue() };
	if (trackNum == 1) {
		if (probabilityOfRestForParam(paramIndex) == 1.0f) {
			setValueIsOnlyOneAllowedForParam_z(params::seqStepValueForRest, paramIndex);
			return;
		}
	}
	if (probabilityOfResetForParam(paramIndex) == 1.0f) {
		setValueIsOnlyOneAllowedForParam_z(params::seqStepValueForReset, paramIndex);
		return;
	}
	auto restsAreNotAllowed{ (bool)true };
	if (trackNum == 1 && probabilityOfRestForParam(paramIndex) > 0.0f)
		restsAreNotAllowed = false;
	auto resetsAreNotAllowed{ (bool)true };
	if (probabilityOfResetForParam(paramIndex) > 0.0f)
		resetsAreNotAllowed = false;
	if (restsAreNotAllowed && resetsAreNotAllowed) {
		if (trackDestinationIsAnOscPitchParameter(trackNum)) {
			Array<uint8> allowedPitches;
			for (uint8 pitch = 0; pitch != (uint8)randomization::numberOfPitchesForSeqSteps; ++pitch) {
				if (pitchIsAllowedForParam(pitch, paramIndex))
					allowedPitches.add(pitch);
			}
			if (allowedPitches.size() == 1)
				setValueIsOnlyOneAllowedForParam_z(allowedPitches[0], paramIndex);
			else
				setMoreThanOneValueIsAllowedForParam_z(paramIndex);
		}
		else {
			auto minValue{ minValueAllowedForParam(paramIndex) };
			auto maxValue{ maxValueAllowedForParam(paramIndex) };
			if (minValue == maxValue)
				setValueIsOnlyOneAllowedForParam_z(minValue, paramIndex);
			else
				setMoreThanOneValueIsAllowedForParam_z(paramIndex);
		}
	}
	else
		setMoreThanOneValueIsAllowedForParam_z(paramIndex);
}

void RandomizationOptions::checkIfOnlyOneValueIsAllowedForAllStepsInSeqTrack(int trackNum) {
	if (trackNum == 1 && probabilityOfRestForAllStepsInSeqTrack1() == 1.0f) {
		setValueIsOnlyOneAllowedForAllStepsInSeqTrack(params::seqStepValueForRest, trackNum);
		return;
	}
	if (probabilityOfResetForAllStepsInSeqTrack(trackNum) == 1.0f) {
		setValueIsOnlyOneAllowedForAllStepsInSeqTrack(params::seqStepValueForReset, trackNum);
		return;
	}
	auto restsAreNotAllowed{ (bool)true };
	if (trackNum == 1 && probabilityOfRestForAllStepsInSeqTrack1() > 0.0f)
		restsAreNotAllowed = false;
	auto resetsAreNotAllowed{ (bool)true };
	if (probabilityOfResetForAllStepsInSeqTrack(trackNum) > 0.0f)
		resetsAreNotAllowed = false;
	if (restsAreNotAllowed && resetsAreNotAllowed) {
		if (trackDestinationIsAnOscPitchParameter(trackNum)) {
			Array<uint8> allowedPitches;
			for (uint8 pitch = 0; pitch != (uint8)randomization::numberOfPitchesForSeqSteps; ++pitch) {
				if (pitchIsAllowedForAllStepsInSeqTrack(pitch, trackNum)) {
					allowedPitches.add(pitch);
				}
			}
			if (allowedPitches.size() == 1)
				setValueIsOnlyOneAllowedForAllStepsInSeqTrack(allowedPitches[0], trackNum);
			else
				setMoreThanOneValueIsAllowedForAllStepsInSeqTrack(trackNum);
		}
		else {
			auto minValue{ minValueForAllStepsInSeqTrack(trackNum) };
			auto maxValue{ maxValueForAllStepsInSeqTrack(trackNum) };
			if (minValue == maxValue)
				setValueIsOnlyOneAllowedForAllStepsInSeqTrack(minValue, trackNum);
			else
				setMoreThanOneValueIsAllowedForAllStepsInSeqTrack(trackNum);
		}
	}
	else
		setMoreThanOneValueIsAllowedForAllStepsInSeqTrack(trackNum);
}

XmlElement* RandomizationOptions::getStateXml() {
	std::unique_ptr<XmlElement> randomizationOptionsStateXml{ new XmlElement(ID::state_RandomizationOptions) };

	auto transmissionOptionsTreeStateXml{ transmissionOptionsTree.createXml() };
	if (transmissionOptionsTreeStateXml != nullptr) {
		transmissionOptionsTreeStateXml->setTagName(ID::randomization_TransmissionOptions);
		randomizationOptionsStateXml->addChildElement(transmissionOptionsTreeStateXml.release());
	}

	auto paramLocksTreeStateXml{ paramLocksTree.createXml() };
	if (paramLocksTreeStateXml != nullptr) {
		paramLocksTreeStateXml->setTagName(ID::randomization_ParamLocks);
		randomizationOptionsStateXml->addChildElement(paramLocksTreeStateXml.release());
	}

	auto allowedValuesTreesStateXml{ allowedValuesTrees.createXml() };
	if (allowedValuesTreesStateXml != nullptr) {
		allowedValuesTreesStateXml->setTagName(ID::randomization_AllowedValues);
		randomizationOptionsStateXml->addChildElement(allowedValuesTreesStateXml.release());
	}

	auto allowedPitchesTreeStateXml{ allowedPitchesTree.createXml() };
	if (allowedPitchesTreeStateXml != nullptr) {
		allowedPitchesTreeStateXml->setTagName(ID::randomization_AllowedPitches);
		randomizationOptionsStateXml->addChildElement(allowedPitchesTreeStateXml.release());
	}

	auto allowedValueRangesTreeStateXml{ allowedValueRangesTree.createXml() };
	if (allowedValueRangesTreeStateXml != nullptr) {
		allowedValueRangesTreeStateXml->setTagName(ID::randomization_AllowedValueRanges);
		randomizationOptionsStateXml->addChildElement(allowedValueRangesTreeStateXml.release());
	}

	auto allowedOscShapesTreeStateXml{ allowedOscShapesTree.createXml() };
	if (allowedOscShapesTreeStateXml != nullptr) {
		allowedOscShapesTreeStateXml->setTagName(ID::randomization_AllowedOscShapes);
		randomizationOptionsStateXml->addChildElement(allowedOscShapesTreeStateXml.release());
	}

	auto allowedComboBoxItemsTreeStateXml{ allowedComboBoxItemsTree.createXml() };
	if (allowedComboBoxItemsTreeStateXml != nullptr) {
		allowedComboBoxItemsTreeStateXml->setTagName(ID::randomization_AllowedComboBoxItems);
		randomizationOptionsStateXml->addChildElement(allowedComboBoxItemsTreeStateXml.release());
	}

	auto allowedFrequencyTypesTreeStateXml{ allowedFrequencyTypesTree.createXml() };
	if (allowedFrequencyTypesTreeStateXml != nullptr) {
		allowedFrequencyTypesTreeStateXml->setTagName(ID::randomization_AllowedFrequencyTypes);
		randomizationOptionsStateXml->addChildElement(allowedFrequencyTypesTreeStateXml.release());
	}

	auto lpfFreqOptionsTreeStateXml{ lpfFreqOptionsTree.createXml() };
	if (lpfFreqOptionsTreeStateXml != nullptr) {
		lpfFreqOptionsTreeStateXml->setTagName(ID::randomization_LPFfreqOptions);
		randomizationOptionsStateXml->addChildElement(lpfFreqOptionsTreeStateXml.release());
	}

	auto repeatValuesOptionsTreeStateXml{ repeatValuesOptionsTree.createXml() };
	if (repeatValuesOptionsTreeStateXml != nullptr) {
		repeatValuesOptionsTreeStateXml->setTagName(ID::randomization_RepeatValuesOptions);
		randomizationOptionsStateXml->addChildElement(repeatValuesOptionsTreeStateXml.release());
	}

	auto seqTrackOptionsTreeStateXml{ seqTrackOptionsTree.createXml() };
	if (seqTrackOptionsTreeStateXml != nullptr) {
		seqTrackOptionsTreeStateXml->setTagName(ID::randomization_SeqTrackOptions);
		randomizationOptionsStateXml->addChildElement(seqTrackOptionsTreeStateXml.release());
	}

	return randomizationOptionsStateXml.release();
}

void RandomizationOptions::replaceState(const ValueTree& newState) {
	if (newState.isValid()) {
		auto transmissionOptionsTreeState{ newState.getChildWithName(ID::randomization_TransmissionOptions) };
		if (transmissionOptionsTreeState.isValid())
			transmissionOptionsTree.copyPropertiesAndChildrenFrom(transmissionOptionsTreeState, nullptr);

		auto paramLocksTreeState{ newState.getChildWithName(ID::randomization_ParamLocks) };
		if (paramLocksTreeState.isValid())
			paramLocksTree.copyPropertiesAndChildrenFrom(paramLocksTreeState, nullptr);

		auto allowedValuesTreesState{ newState.getChildWithName(ID::randomization_AllowedValues) };
		if (allowedValuesTreesState.isValid())
			allowedValuesTrees.copyPropertiesAndChildrenFrom(allowedValuesTreesState, nullptr);

		auto allowedPitchesTreeState{ newState.getChildWithName(ID::randomization_AllowedPitches) };
		if (allowedPitchesTreeState.isValid())
			allowedPitchesTree.copyPropertiesAndChildrenFrom(allowedPitchesTreeState, nullptr);

		auto allowedOscShapesTreeState{ newState.getChildWithName(ID::randomization_AllowedOscShapes) };
		if (allowedOscShapesTreeState.isValid())
			allowedOscShapesTree.copyPropertiesAndChildrenFrom(allowedOscShapesTreeState, nullptr);

		auto allowedComboBoxItemsTreeState{ newState.getChildWithName(ID::randomization_AllowedComboBoxItems) };
		if (allowedComboBoxItemsTreeState.isValid())
			allowedComboBoxItemsTree.copyPropertiesAndChildrenFrom(allowedComboBoxItemsTreeState, nullptr);

		auto allowedValueRangesTreeState{ newState.getChildWithName(ID::randomization_AllowedValueRanges) };
		if (allowedValueRangesTreeState.isValid())
			allowedValueRangesTree.copyPropertiesAndChildrenFrom(allowedValueRangesTreeState, nullptr);

		auto allowedFrequencyTypesTreeState{ newState.getChildWithName(ID::randomization_AllowedFrequencyTypes) };
		if (allowedFrequencyTypesTreeState.isValid())
			allowedFrequencyTypesTree.copyPropertiesAndChildrenFrom(allowedFrequencyTypesTreeState, nullptr);

		auto lpfFreqOptionsTreeState{ newState.getChildWithName(ID::randomization_LPFfreqOptions) };
		if (lpfFreqOptionsTreeState.isValid())
			lpfFreqOptionsTree.copyPropertiesAndChildrenFrom(lpfFreqOptionsTreeState, nullptr);

		auto repeatValuesOptionsTreeState{ newState.getChildWithName(ID::randomization_RepeatValuesOptions) };
		if (repeatValuesOptionsTreeState.isValid())
			repeatValuesOptionsTree.copyPropertiesAndChildrenFrom(repeatValuesOptionsTreeState, nullptr);

		auto seqTrackOptionsTreeState{ newState.getChildWithName(ID::randomization_SeqTrackOptions) };
		if (seqTrackOptionsTreeState.isValid())
			seqTrackOptionsTree.copyPropertiesAndChildrenFrom(seqTrackOptionsTreeState, nullptr);
	}
}
