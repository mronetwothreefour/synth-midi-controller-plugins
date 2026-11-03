#pragma once

#include <JuceHeader.h>

namespace MIDI
{

	struct Msg
	{
	public: static MidiMessage dump_request_pgm(const uint8 pgm_num);
	};

}