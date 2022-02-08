#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;
class UnexposedParameters;

struct MasterOptionsDataMessage
{
	static void addDataMessageForMasterOptionsToOutgoingMidiBuffers(UnexposedParameters* unexposedParams);
	static void addRequestForMasterOptionsDataToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers);

private:
	static std::vector<uint8> createSysExMessageFromCurrentMasterOptions(UnexposedParameters* unexposedParams);
};