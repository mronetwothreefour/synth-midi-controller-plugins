#pragma once

#include <JuceHeader.h>

namespace MIDI
{

	struct Raw_Data_Tools
	{
	public: static const bool is_relevant_sysex(const MidiMessage& msg);
	//private: static void apply_raw_pgm_data_to_exp()
	};

}
