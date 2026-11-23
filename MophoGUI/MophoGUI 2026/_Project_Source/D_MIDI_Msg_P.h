#pragma once

#include <JuceHeader.h>

class Data_Hub;

namespace MIDI
{

	struct Msg
	{
	public: static MidiMessage dump_global();
	public: static MidiMessage dump_pgm(const uint8 bnk_num, const uint8 pgm_num,
										Data_Hub* hub);
	public: static MidiMessage dump_pgm_buffer(Data_Hub* hub);
	public: static MidiMessage dump_request_global();
	public: static MidiMessage dump_request_pgm(const uint8 bnk_num, const uint8 pgm_num);
	public: static MidiMessage dump_request_pgm_buffer();
	public: static MidiBuffer nrpn_param_change(const uint8 chan, const int nrpn_id,
												const int new_val);
	};

}