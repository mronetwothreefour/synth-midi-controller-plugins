#include "params_UnexposedParameters_Facade.h"

#include "params_Identifiers.h"



UnexposedParameters::UnexposedParameters() :
	outgoingMidiBuffers{ new OutgoingMidiBuffers() },
	voicesBank{ new VoicesBank() },
	voiceTransmissionOptions{ new VoiceTransmissionOptions(this) },
	tooltipOptions{ new TooltipOptions() },
	undoManager{ new UndoManager() }
{
}

Array<MidiBuffer, CriticalSection>* UnexposedParameters::aggregatedOutgoingBuffers_get() {
	return outgoingMidiBuffers->aggregatedOutgoingBuffers_get();
}

OutgoingMidiBuffers* UnexposedParameters::outgoingMidiBuffers_get() {
	return outgoingMidiBuffers.get();
}

TooltipOptions* UnexposedParameters::tooltipOptions_get() {
	return tooltipOptions.get();
}

UndoManager* UnexposedParameters::undoManager_get() {
	return undoManager.get();
}

VoicesBank* UnexposedParameters::voicesBank_get() {
	return voicesBank.get();
}

VoiceTransmissionOptions* UnexposedParameters::voiceTransmissionOptions_get() {
	return voiceTransmissionOptions.get();
}

XmlElement UnexposedParameters::getStateXml() {
	XmlElement unexposedParamsStateXml{ ID::state_UnexposedParams };
	auto tooltipOptionsStateXml{ tooltipOptions->getStateXml() };
	if (tooltipOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(tooltipOptionsStateXml);
	auto voicesBankStateXml{ voicesBank->getStateXml() };
	if (voicesBankStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(voicesBankStateXml);
	auto voiceTransmissionOptionsStateXml{ voiceTransmissionOptions->getStateXml() };
	if (voiceTransmissionOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(voiceTransmissionOptionsStateXml);
	return unexposedParamsStateXml;
}

void UnexposedParameters::replaceState(const ValueTree& newState) {
	auto voicesBankState{ newState.getChildWithName(ID::state_VoicesBank) };
	voicesBank->replaceState(voicesBankState);
	auto tooltipOptionsState{ newState.getChildWithName(ID::state_TooltipOptions) };
	tooltipOptions->replaceState(tooltipOptionsState);
	auto voiceTransmissionOptionsState{ newState.getChildWithName(ID::state_VoiceTransmissionOptions) };
	voiceTransmissionOptions->replaceState(voiceTransmissionOptionsState);
}

UnexposedParameters::~UnexposedParameters() {
	undoManager = nullptr;
	tooltipOptions = nullptr;
	voicesBank = nullptr;
	voiceTransmissionOptions = nullptr;
	outgoingMidiBuffers = nullptr;
}
