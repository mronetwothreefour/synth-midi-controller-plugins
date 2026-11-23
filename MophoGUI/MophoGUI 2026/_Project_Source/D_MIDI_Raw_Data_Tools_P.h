#pragma once

#include <JuceHeader.h>

class Data_Hub;

using namespace std;

namespace MIDI
{

	struct Raw_Data_Tools
	{
	public: static const bool is_relevant_sysex(const MidiMessage& msg);
	public: static const bool is_valid_pgm_hex_string(const String& hex_string);

	private: static void apply_raw_pgm_data_to_app(const uint8* pgm_data, Data_Hub* hub);

	public: static const vector<uint8> extract_raw_pgm_data_from_app(Data_Hub* hub);
	};

}
