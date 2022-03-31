#include "randomization_ParamRandomizationMethods.h"

#include "../midi/midi_EditBufferDataMessage.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



void ParamRandomizationMethods::randomizeUnlockedParameters(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
	voiceTransmissionOptions->setParamChangeEchoesAreBlocked();
	auto& info{ InfoForExposedParameters::get() };
	auto arpegOnOffIndex{ info.indexForParamID("arpegOnOff") };
	auto sequencerOnOffIndex{ info.indexForParamID("sequencerOnOff") };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
		if (param != arpegOnOffIndex && param != sequencerOnOffIndex) {
			if (randomizationOptions->paramIsLocked(param) == false) {
				auto paramID{ info.IDfor(param) };
				Random rndmNumGenerator{};
				if (paramID == ID::osc1_Pitch || paramID == ID::osc2_Pitch)
					randomizeOscPitchParameter(paramID, exposedParams, unexposedParams);
				else if (paramID == ID::osc1_Shape || paramID == ID::osc2_Shape)
					randomizeOscShapeParameter(paramID, exposedParams);
				else
					randomizeParameter(paramID, exposedParams);
			}
		}
	}
	randomizeArpAndSeqOnOffParameters(exposedParams, unexposedParams);
	EditBufferDataMessage::addEditBufferDataMessageToOutgoingMidiBuffers(exposedParams, unexposedParams->outgoingMidiBuffers_get());
	voiceTransmissionOptions->setParamChangeEchoesAreNotBlocked();
}

void ParamRandomizationMethods::randomizeParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams) {
	Random rndmNumGenerator{};
	auto newNormalizedValue{ rndmNumGenerator.nextFloat() };
	exposedParams->getParameter(paramID)->setValueNotifyingHost(newNormalizedValue);
}

void ParamRandomizationMethods::randomizeOscPitchParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	auto& info{ InfoForExposedParameters::get() };
	auto oscNum{ paramID.toString().contains("1") ? 1 : 2 };
	auto paramIndex{ info.indexForParamID(paramID.toString()) };
	auto pitchOutOfRange{ uint8(info.maxValueFor(paramIndex) + 1) };
	Array<float> allowedPitchesStoredAsNormalizedValues;
	float newNormalizedValue{ 0.0f };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (randomizationOptions->onlyOctave10_IsAllowedForOscillator(oscNum))
		newNormalizedValue = 1.0f;
	else {
		for (uint8 pitch = 0; pitch != pitchOutOfRange; ++pitch) {
			auto pitchIsAllowed{ randomizationOptions->pitchIsAllowedForOscillator(pitch, oscNum) };
			if (pitchIsAllowed) {
				auto normalizedValue{ pitch / (float)info.maxValueFor(paramIndex) };
				allowedPitchesStoredAsNormalizedValues.add(normalizedValue);
			}
		}
		auto numberOfAllowedPitches{ allowedPitchesStoredAsNormalizedValues.size() };
		Random rndmNumGenerator{};
		auto newFloat{ rndmNumGenerator.nextFloat() };
		auto newPitchIndex{ (int)floor(newFloat * numberOfAllowedPitches) };
		newNormalizedValue = allowedPitchesStoredAsNormalizedValues[newPitchIndex];
	}
	exposedParams->getParameter(paramID)->setValueNotifyingHost(newNormalizedValue);
}

void ParamRandomizationMethods::randomizeOscShapeParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams) {
	Random rndmNumGenerator{};
	auto newFloat{ rndmNumGenerator.nextFloat() };
	auto numberOfShapeOptions{ 5 };
	auto newShape{ (int)floor(newFloat * numberOfShapeOptions) };
	if (newShape != 4) {
		auto newNormalizedValue{ newShape / 103.0f };
		exposedParams->getParameter(paramID)->setValueNotifyingHost(newNormalizedValue);
	}
	else {
		auto newPulseWidth{ floor(rndmNumGenerator.nextFloat() * 100.0f) };
		auto newNormalizedValue{ (newShape + newPulseWidth) / 103.0f };
		exposedParams->getParameter(paramID)->setValueNotifyingHost(newNormalizedValue);
	}
}

void ParamRandomizationMethods::randomizeLFOfreqParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams) {
}

void ParamRandomizationMethods::randomizeSeqStepParameter(Identifier paramID, AudioProcessorValueTreeState* exposedParams)
{
}

void ParamRandomizationMethods::randomizeArpAndSeqOnOffParameters(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto& info{ InfoForExposedParameters::get() };
	auto arpegOnOffIndex{ info.indexForParamID("arpegOnOff") };
	auto sequencerOnOffIndex{ info.indexForParamID("sequencerOnOff") };
	Random rndmNumGenerator{};
	auto newNormalizedValue{ rndmNumGenerator.nextFloat() };
	if (randomizationOptions->paramIsLocked(arpegOnOffIndex) == false && randomizationOptions->paramIsLocked(sequencerOnOffIndex) == false) {
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
	if (randomizationOptions->paramIsLocked(arpegOnOffIndex) == false && randomizationOptions->paramIsLocked(sequencerOnOffIndex) == true) {
		auto arpOnOffOption{ std::round(newNormalizedValue) };
		exposedParams->getParameter("arpegOnOff")->setValueNotifyingHost(arpOnOffOption);
	}
	if (randomizationOptions->paramIsLocked(arpegOnOffIndex) == true && randomizationOptions->paramIsLocked(sequencerOnOffIndex) == false) {
		auto seqOnOffOption{ std::round(newNormalizedValue) };
		exposedParams->getParameter("sequencerOnOff")->setValueNotifyingHost(seqOnOffOption);
	}
}
