#pragma once

#include <JuceHeader.h>

class Data_Hub;

namespace MIDI
{

	struct Raw_Data_Tools
	{
	public: static const bool is_relevant_sysex(const MidiMessage& msg);
	public: static const bool is_valid_pgm_hex_string(const String& hex_string);
	public: static void apply_raw_pgm_data_to_gui(const int pgm_num, const uint8* pgm_data,
												   Data_Hub* hub);
	private: static void apply_raw_pgm_data_to_exp(const uint8* pgm_data, Data_Hub* hub);
	private: static void apply_raw_pgm_data_to_mmod(const uint8* pgm_data, Data_Hub* hub);
	private: static void remove_bit_7_from_ascii_value(uint8& value);
	private: static void restore_bit_7_to_ascii_value(uint8& value);
	private: static const String convert_stored_ascii_val_to_string(const uint8& value);
	};

}
