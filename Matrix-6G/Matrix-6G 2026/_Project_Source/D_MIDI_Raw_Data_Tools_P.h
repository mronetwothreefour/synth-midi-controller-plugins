#pragma once

#include <JuceHeader.h>

namespace MIDI
{

	struct Raw_Data_Tools
	{
	public: static const bool is_relevant_sysex(const MidiMessage& msg);
	};

}
