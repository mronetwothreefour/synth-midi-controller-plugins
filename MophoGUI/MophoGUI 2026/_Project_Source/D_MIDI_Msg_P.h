#pragma once

#include <JuceHeader.h>

namespace MIDI
{

	struct Msg
	{
	public: static MidiBuffer nrpn_param_change(const uint8 chan, const int nrpn_id, const int new_val);
	public: static MidiMessage request_global();
	public: static MidiMessage request_pgm(const uint8 bank_num, const uint8 slot_num);
	public: static MidiMessage request_pgm_buffer();
	};

}