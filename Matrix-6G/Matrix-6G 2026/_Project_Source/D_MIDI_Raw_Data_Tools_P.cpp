#include "D_MIDI_Raw_Data_Tools_P.h"

#include "C_GET_P.h"
#include "C_MIDI_P.h"
#include "C_MISC_P.h"
#include "D_X_G_Data_Hub_P.h"

using namespace MIDI;

const bool Raw_Data_Tools::is_relevant_sysex(const MidiMessage& msg) {
	if (msg.isSysEx()) {
		auto d = msg.getSysExData();
		return d[1] == id_maker && d[2] == id_device;
	}
	return false;
}

const bool MIDI::Raw_Data_Tools::is_valid_pgm_hex_string(const String& hex_string) {
	return hex_string.length() == MIDI::pgm_hex_string_length;
}

void MIDI::Raw_Data_Tools::apply_raw_pgm_data_to_gui(const int pgm_num, const uint8* pgm_data, 
													 Data_Hub* hub) 
{
	auto& app_p = hub->get_app_params();
	app_p.set_current_pgm_num(pgm_num);
    String pgm_name{ "" };
    for (auto byte = 0; byte < MISC::pgm_name_length * 2; byte += 2) {
        auto ls_byte_val{ (uint8)pgm_data[byte] };
        auto ms_byte_val{ (uint8)pgm_data[byte + 1] };
        auto stored_ascii_val{ uint8(ls_byte_val + (ms_byte_val * 16)) };
        restore_bit_7_to_ascii_value(stored_ascii_val);
        pgm_name += convert_stored_ascii_val_to_string(stored_ascii_val);
    }
    app_p.set_current_pgm_name(pgm_name);
    apply_raw_pgm_data_to_exp(pgm_data + MIDI::first_exp_data_byte, hub);
    apply_raw_pgm_data_to_mmod(pgm_data + MIDI::first_mmod_data_byte, hub);
}

void MIDI::Raw_Data_Tools::apply_raw_pgm_data_to_exp(const uint8* pgm_data, Data_Hub* hub) {

}

void MIDI::Raw_Data_Tools::apply_raw_pgm_data_to_mmod(const uint8* pgm_data, Data_Hub* hub) {
}

void MIDI::Raw_Data_Tools::remove_bit_7_from_ascii_value(uint8& value) {
    value %= 64;
}

void MIDI::Raw_Data_Tools::restore_bit_7_to_ascii_value(uint8& value) {
    if (value < 32 && value != MIDI::stored_ascii_val_for_bar)
        value += 64;
}

const String MIDI::Raw_Data_Tools::convert_stored_ascii_val_to_string(const uint8& value) {
    if (value == MIDI::stored_ascii_val_for_bar)
        return "|";
    auto v{ value };
    restore_bit_7_to_ascii_value(v);
    return std::string(1, v);
}
