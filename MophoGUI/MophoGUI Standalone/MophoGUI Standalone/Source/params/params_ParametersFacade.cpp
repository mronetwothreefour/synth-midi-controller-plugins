#include "params_ParametersFacade.h"


#include "params_Identifiers.h"



ParametersFacade::ParametersFacade() :
	globalAudioOptions{ new GlobalAudioOptions() },
	midiOptions{ new MidiOptions() },
	//outgoingMidiBuffers{ new OutgoingMidiBuffers() },
	//pluginProgramBanks{ new ProgramBanks() },
	tooltipOptions{ new TooltipOptions() },
	undoManager{ new UndoManager() }
{
}

//Array<MidiBuffer, CriticalSection>* ParametersFacade::aggregatedOutgoingBuffers_get() {
//	return outgoingMidiBuffers->aggregatedOutgoingBuffers_get();
//}

GlobalAudioOptions* ParametersFacade::globalAudioOptions_get() {
	return globalAudioOptions.get();
}

MidiOptions* ParametersFacade::midiOptions_get() {
	return midiOptions.get();
}

//OutgoingMidiBuffers* ParametersFacade::outgoingMidiBuffers_get() {
//	return outgoingMidiBuffers.get();
//}
//
//ProgramBanks* ParametersFacade::programBanks_get() {
//	return pluginProgramBanks.get();
//}

TooltipOptions* ParametersFacade::tooltipOptions_get() {
	return tooltipOptions.get();
}

UndoManager* ParametersFacade::undoManager_get() {
	return undoManager.get();
}

XmlElement ParametersFacade::getStateXml() {
	XmlElement unexposedParamsStateXml{ ID::state_UnexposedParams };
	//auto pluginProgramBanksStateXml{ pluginProgramBanks->getStateXml() };
	//if (pluginProgramBanksStateXml != nullptr)
	//	unexposedParamsStateXml.addChildElement(pluginProgramBanksStateXml);
	auto tooltipOptionsStateXml{ tooltipOptions->getStateXml() };
	if (tooltipOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(tooltipOptionsStateXml);
	return unexposedParamsStateXml;
}

void ParametersFacade::replaceState(const ValueTree& newState) {
	auto pluginProgramBanksState{ newState.getChildWithName(ID::state_ProgramBanks) };
	//pluginProgramBanks->replaceState(pluginProgramBanksState);
	auto tooltipOptionsState{ newState.getChildWithName(ID::state_TooltipOptions) };
	tooltipOptions->replaceState(tooltipOptionsState);
}

ParametersFacade::~ParametersFacade() {
	undoManager = nullptr;
	tooltipOptions = nullptr;
	//outgoingMidiBuffers = nullptr;
	midiOptions = nullptr;
	globalAudioOptions = nullptr;
}
