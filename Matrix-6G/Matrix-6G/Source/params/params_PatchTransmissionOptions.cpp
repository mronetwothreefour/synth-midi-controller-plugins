#include "params_PatchTransmissionOptions.h"

#include "params_Identifiers.h"



PatchTransmissionOptions::PatchTransmissionOptions() :
	patchTransmissionOptionsTree{ ID::midi_Options }
{
	fillPatchTransmissionOptionsTreeWithProperties();
}

void PatchTransmissionOptions::fillPatchTransmissionOptionsTreeWithProperties() {
	patchTransmissionOptionsTree.setProperty(ID::midi_IncomingPatchShouldBeSavedInCustomBankA, (bool)false, nullptr);
	patchTransmissionOptionsTree.setProperty(ID::midi_IncomingPatchShouldBeSavedInCustomBankB, (bool)false, nullptr);
	patchTransmissionOptionsTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)false, nullptr);
	patchTransmissionOptionsTree.setProperty(ID::midi_PatchTransmitTime, 300, nullptr);
}

void PatchTransmissionOptions::addListener(ValueTree::Listener* listener) {
	patchTransmissionOptionsTree.addListener(listener);
}

void PatchTransmissionOptions::removeListener(ValueTree::Listener* listener) {
	patchTransmissionOptionsTree.removeListener(listener);
}

bool PatchTransmissionOptions::incomingPatchShouldBeSavedInCustomBankA() {
	return (bool)patchTransmissionOptionsTree.getProperty(ID::midi_IncomingPatchShouldBeSavedInCustomBankA);
}

bool PatchTransmissionOptions::incomingPatchShouldBeSavedInCustomBankB() {
	return (bool)patchTransmissionOptionsTree.getProperty(ID::midi_IncomingPatchShouldBeSavedInCustomBankB);
}

void PatchTransmissionOptions::setIncomingPatchShouldBeSavedInCustomBankA() {
	patchTransmissionOptionsTree.setProperty(ID::midi_IncomingPatchShouldBeSavedInCustomBankA, (bool)true, nullptr);
}

void PatchTransmissionOptions::setIncomingPatchShouldBeSavedInCustomBankB() {
	patchTransmissionOptionsTree.setProperty(ID::midi_IncomingPatchShouldBeSavedInCustomBankB, (bool)true, nullptr);
}

void PatchTransmissionOptions::setIncomingPatchShouldNotBeSavedInCustomBank() {
	patchTransmissionOptionsTree.setProperty(ID::midi_IncomingPatchShouldBeSavedInCustomBankA, (bool)false, nullptr);
	patchTransmissionOptionsTree.setProperty(ID::midi_IncomingPatchShouldBeSavedInCustomBankB, (bool)false, nullptr);
}

bool PatchTransmissionOptions::paramChangeEchosAreNotBlocked() {
	return !(bool)patchTransmissionOptionsTree.getProperty(ID::midi_ParamChangeEchosAreBlocked);
}

void PatchTransmissionOptions::setParamChangeEchosAreBlocked() {
	patchTransmissionOptionsTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)true, nullptr);
}

void PatchTransmissionOptions::setParamChangeEchosAreNotBlocked() {
	patchTransmissionOptionsTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)false, nullptr);
}

const int PatchTransmissionOptions::patchTransmitTime() {
	return (int)patchTransmissionOptionsTree.getProperty(ID::midi_PatchTransmitTime);
}

void PatchTransmissionOptions::setPatchTransmitTime(int timeInMilliseconds) {
	patchTransmissionOptionsTree.setProperty(ID::midi_PatchTransmitTime, timeInMilliseconds, nullptr);
}

XmlElement* PatchTransmissionOptions::getStateXml() {
	std::unique_ptr<XmlElement> patchTransmissionOptionsTreeStateXml{ new XmlElement(ID::state_PatchTransmissionOptions) };
	auto patchTransmitTime{ (int)patchTransmissionOptionsTree.getProperty(ID::midi_PatchTransmitTime) };
	patchTransmissionOptionsTreeStateXml->setAttribute(ID::midi_PatchTransmitTime, patchTransmitTime);
	return patchTransmissionOptionsTreeStateXml.release();
}

void PatchTransmissionOptions::replaceState(const ValueTree& newState) {
	auto patchTransmitTime{ newState.getProperty(ID::midi_PatchTransmitTime) };
	patchTransmissionOptionsTree.setProperty(ID::midi_PatchTransmitTime, patchTransmitTime, nullptr);
}
