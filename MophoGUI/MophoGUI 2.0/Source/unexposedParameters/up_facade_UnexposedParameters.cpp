#include "up_facade_UnexposedParameters.h"

#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;



UnexposedParameters::UnexposedParameters() :
	globalOptions{ new GlobalOptions{} },
	outgoingMidiBuffers{ new OutgoingMidiBuffers{} },
	tooltipsOptions{ new TooltipsOptions{} },
	//voicesBanks{ new VoicesBanks{} },
	voiceTransmissionOptions{ new VoiceTransmissionOptions{} }
{
}

Array<MidiBuffer, CriticalSection>* UnexposedParameters::getBundledOutgoingBuffers() {
	return outgoingMidiBuffers->getBundledOutgoingBuffers();
}

GlobalOptions* UnexposedParameters::getGlobalOptions() {
	return globalOptions.get();
}

OutgoingMidiBuffers* UnexposedParameters::getOutgoingMidiBuffers() {
	return outgoingMidiBuffers.get();
}

TooltipsOptions* UnexposedParameters::getTooltipsOptions() {
	return tooltipsOptions.get();
}

//VoicesBanks* UnexposedParameters::getVoicesBanks() {
//	return voicesBanks.get();
//}

VoiceTransmissionOptions* UnexposedParameters::getVoiceTransmissionOptions() {
	return voiceTransmissionOptions.get();
}

XmlElement UnexposedParameters::getStateXml() {
	XmlElement unexposedParamsStateXml{ ID::state_UnexposedParams };

	auto tooltipOptionsStateXml{ tooltipsOptions->getStateXml() };
	if (tooltipOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(tooltipOptionsStateXml);

	//auto voicesBanksStateXml{ voicesBanks->getStateXml() };
	//if (voicesBanksStateXml != nullptr)
	//	unexposedParamsStateXml.addChildElement(voicesBanksStateXml);

	auto voiceTxOptionsStateXml{ voiceTransmissionOptions->getStateXml() };
	if (voiceTxOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(voiceTxOptionsStateXml);

	return unexposedParamsStateXml;
}

void UnexposedParameters::replaceState(const ValueTree& newState) {
	auto tooltipOptionsState{ newState.getChildWithName(ID::state_TooltipsOptions) };
	if (tooltipOptionsState.isValid())
		tooltipsOptions->replaceState(tooltipOptionsState);

	//auto voicesBanksState{ newState.getChildWithName(ID::state_VoicesBanks) };
	//if (voicesBanksState.isValid())
	//	voicesBanks->replaceState(voicesBanksState);

	auto voiceTxOptionsState{ newState.getChildWithName(ID::state_VoiceTxOptions) };
	if (voiceTxOptionsState.isValid())
		voiceTransmissionOptions->replaceState(voiceTxOptionsState);
}

UnexposedParameters::~UnexposedParameters() {
	voiceTransmissionOptions = nullptr;
	//voicesBanks = nullptr;
	tooltipsOptions = nullptr;
	outgoingMidiBuffers = nullptr;
	globalOptions = nullptr;
}
