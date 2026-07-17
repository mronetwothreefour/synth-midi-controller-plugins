#include "params_ExposedParametersListener.h"

#include "params_ExposedParamsInfo_Singleton.h"
#include "params_UnexposedParameters_Facade.h"
#include "../midi/midi_Constants.h"
#include "../midi/midi_VoiceDataMessage.h"

using namespace constants;




ExposedParametersListener::ExposedParametersListener(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
		exposedParams->addParameterListener(info.IDfor(param), this);
}

void ExposedParametersListener::parameterChanged(const String& /*parameterID*/, float /*newValue*/) {
	auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
	if (voiceTransmissionOptions->paramChangeEchoesAreNotBlocked()) {
		VoiceDataMessage::addVoiceDataMessageForCurrentExposedParamsSettingsToOutgoingMidiBuffers(exposedParams, unexposedParams);
		auto voiceSlot{ voiceTransmissionOptions->currentVoiceNumber() };
		auto transmitTime{ voiceTransmissionOptions->voiceTransmitTime() };
		callAfterDelay(transmitTime, [this, voiceSlot]
			{
				auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
				outgoingBuffers->addProgramChangeMessage(MIDI::channel, voiceSlot);
			}
		);
	}
}

void ExposedParametersListener::timerCallback() {
}

ExposedParametersListener::~ExposedParametersListener() {
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
		exposedParams->removeParameterListener(info.IDfor(param), this);

}
