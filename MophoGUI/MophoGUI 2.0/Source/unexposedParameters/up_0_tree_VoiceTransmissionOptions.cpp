#include "up_0_tree_VoiceTransmissionOptions.h"

#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;

VoiceTransmissionOptions::VoiceTransmissionOptions() :
	voiceTransmissionOptionsTree{ ID::voiceTx_Options }
{
	transmitParamChanges();
	setVoiceTransmitTime(300);
}

const bool VoiceTransmissionOptions::paramChangesShouldBeTransmitted() {
	return (bool)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_TransmitParamChanges) == true;
}

void VoiceTransmissionOptions::dontTransmitParamChanges() {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_TransmitParamChanges, (bool)false, nullptr);
}

void VoiceTransmissionOptions::transmitParamChanges() {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_TransmitParamChanges, (bool)true, nullptr);
}

const int VoiceTransmissionOptions::voiceTransmitTime() {
	return (int)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_Time);
}

void VoiceTransmissionOptions::setVoiceTransmitTime(const int timeInMilliseconds) {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_Time, timeInMilliseconds, nullptr);
}

std::unique_ptr<XmlElement> VoiceTransmissionOptions::getStateXml() {
	std::unique_ptr<XmlElement> voiceTransmissionOptionsTreeStateXml{ new XmlElement(ID::state_VoiceTxOptions) };
	if (voiceTransmissionOptionsTreeStateXml != nullptr) {
		voiceTransmissionOptionsTreeStateXml->setAttribute(ID::voiceTx_Time, voiceTransmitTime());
	}
	return voiceTransmissionOptionsTreeStateXml;
}

void VoiceTransmissionOptions::replaceState(const ValueTree& newState) {
	auto voiceTransmitTime{ newState.getProperty(ID::voiceTx_Time) };
	if (!voiceTransmitTime.isVoid())
		voiceTransmissionOptionsTree.setProperty(ID::voiceTx_Time, voiceTransmitTime, nullptr);
}
