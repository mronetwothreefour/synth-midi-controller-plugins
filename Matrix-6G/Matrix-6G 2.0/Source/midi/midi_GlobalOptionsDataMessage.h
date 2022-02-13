#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;
class UnexposedParameters;

struct GlobalOptionsDataMessage
{
	static void addDataMessageForGlobalOptionsToOutgoingMidiBuffers(UnexposedParameters* unexposedParams);
	static void addRequestForGlobalOptionsDataToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers);

private:
	static std::vector<uint8> createSysExMessageFromCurrentGlobalOptions(UnexposedParameters* unexposedParams);
};