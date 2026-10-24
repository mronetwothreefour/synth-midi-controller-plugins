#pragma once

#include <JuceHeader.h>

namespace MIDI
{

	struct Msg
	{
	public: static MidiMessage dump_request_global();
	public: static MidiMessage dump_request_pgm(const uint8 pgm_num);
	public: static MidiMessage dump_request_split(const uint8 split_num);
	public: static MidiMessage quick_edit_enable();
	public: static MidiMessage quick_edit_param(const uint8 quick_num, const uint8 new_value);
	};

}