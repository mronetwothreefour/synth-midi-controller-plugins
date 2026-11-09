#pragma once

#include <JuceHeader.h>

namespace MIDI
{

	struct Msg
	{
	public: static MidiMessage request_global();
	public: static MidiMessage request_pgm(const uint8 bank_num, const uint8 slot_num);
	public: static MidiMessage request_pgm_buffer();
	};

}