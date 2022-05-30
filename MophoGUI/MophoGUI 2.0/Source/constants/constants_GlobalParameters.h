#pragma once

#include <JuceHeader.h>



namespace MophoConstants
{
	namespace GP
	{
        const uint16 nrpnType_GlobalTranspose{ 384 };
        const uint16 nrpnType_GlobalFineTune{ 385 };
        const uint16 nrpnType_GlobalMidiChannel{ 386 };
        const uint16 nrpnType_MidiClock{ 388 };
        const uint16 nrpnType_ParameterSendType{ 390 };
        const uint16 nrpnType_VoiceChange{ 392 };
        const uint16 nrpnType_PedalMode{ 396 };

        const int numberOfChoicesForGlobalTranspose{ 25 };
    }
}