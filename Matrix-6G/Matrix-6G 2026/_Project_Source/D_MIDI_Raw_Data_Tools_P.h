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

	public: static void apply_raw_pgm_data_to_app(const int pgm_num, const uint8* pgm_data,
												   Data_Hub* hub);
	private: static void apply_raw_pgm_data_to_exp(const uint8* pgm_data, Data_Hub* hub);
	private: static void apply_raw_pgm_data_to_mmod(const uint8* pgm_data, Data_Hub* hub);

	public: static const vector<uint8> extract_raw_pgm_data_from_app(Data_Hub* hub);
	private: static void add_exp_to_raw_pgm_data(Data_Hub* hub, std::vector<uint8>& pgm_data,
												 uint8& checksum);
	private: static void add_mmod_to_raw_pgm_data(Data_Hub* hub, std::vector<uint8>& pgm_data,
												  uint8& checksum);

	private: static void remove_bit_7_from_ascii_value(uint8& value);
	private: static void restore_bit_7_to_ascii_value(uint8& value);
	private: static const String convert_stored_ascii_val_to_string(const uint8& value);
	private: static void add_name_to_raw_data(bool for_pgm, String& name,
											  vector<uint8>& data, uint8& checksum);
	};

}
