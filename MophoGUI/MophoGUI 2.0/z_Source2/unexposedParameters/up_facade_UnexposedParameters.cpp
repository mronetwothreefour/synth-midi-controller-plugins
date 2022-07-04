#include "up_facade_UnexposedParameters.h"

#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;



UnexposedParameters::UnexposedParameters() :
	globalOptions{ new GlobalOptions{} },
	outgoingMidiBuffers{ new OutgoingMidiBuffers{} },
	tooltipsOptions{ new TooltipsOptions{} },
	undoManager{ new UndoManager{} },
	voicesBanks{ new VoicesBanks{} },
	voiceTransmissionOptions{ new VoiceTransmissionOptions{} }
{
}

void UnexposedParameters::createRandomizationOptions(ExposedParameters* exposedParams) {
	randomizationOptions.reset(new RandomizationOptions{ exposedParams });
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

RandomizationOptions* UnexposedParameters::getRandomizationOptions() {
	return randomizationOptions.get();
}

TooltipsOptions* UnexposedParameters::getTooltipsOptions() {
	return tooltipsOptions.get();
}

UndoManager* UnexposedParameters::getUndoManager() {
	return undoManager.get();
}

VoicesBanks* UnexposedParameters::getVoicesBanks() {
	return voicesBanks.get();
}

VoiceTransmissionOptions* UnexposedParameters::getVoiceTransmissionOptions() {
	return voiceTransmissionOptions.get();
}

XmlElement UnexposedParameters::getStateXml() {
	XmlElement unexposedParamsStateXml{ ID::state_UnexposedParams };

	auto randomizationOptionsStateXml{ randomizationOptions->getStateXml() };
	if (randomizationOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(randomizationOptionsStateXml);

	auto tooltipOptionsStateXml{ tooltipsOptions->getStateXml() };
	if (tooltipOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(tooltipOptionsStateXml);

	auto voicesBanksStateXml{ voicesBanks->getStateXml() };
	if (voicesBanksStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(voicesBanksStateXml);

	auto voiceTxOptionsStateXml{ voiceTransmissionOptions->getStateXml() };
	if (voiceTxOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(voiceTxOptionsStateXml);

	return unexposedParamsStateXml;
}

void UnexposedParameters::replaceState(const ValueTree& newState) {
	auto randomizationOptionsState{ newState.getChildWithName(ID::state_RandomizationOptions) };
	if (randomizationOptionsState.isValid())
		randomizationOptions->replaceState(randomizationOptionsState);

	auto tooltipOptionsState{ newState.getChildWithName(ID::state_TooltipsOptions) };
	if (tooltipOptionsState.isValid())
		tooltipsOptions->replaceState(tooltipOptionsState);

	auto voicesBanksState{ newState.getChildWithName(ID::state_VoicesBanks) };
	if (voicesBanksState.isValid())
		voicesBanks->replaceState(voicesBanksState);

	auto voiceTxOptionsState{ newState.getChildWithName(ID::state_VoiceTxOptions) };
	if (voiceTxOptionsState.isValid())
		voiceTransmissionOptions->replaceState(voiceTxOptionsState);
}

UnexposedParameters::~UnexposedParameters() {
	voiceTransmissionOptions = nullptr;
	voicesBanks = nullptr;
	undoManager = nullptr;
	tooltipsOptions = nullptr;
	randomizationOptions = nullptr;
	outgoingMidiBuffers = nullptr;
	globalOptions = nullptr;
}
