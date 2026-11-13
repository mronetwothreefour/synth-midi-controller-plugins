#include "D_MIDI_Raw_Data_Tools_P.h"

#include "C_GET_P.h"
#include "C_ID_Main_P.h"
#include "C_MIDI_P.h"
#include "C_MISC_P.h"
#include "D_CONVERT_P.h"
#include "D_X_G_Data_Hub_P.h"

using namespace MIDI;

const bool Raw_Data_Tools::is_relevant_sysex(const MidiMessage& msg) {
	if (msg.isSysEx()) {
		auto d = msg.getSysExData();
		return d[1] == id_maker && d[2] == id_device;
	}
	return false;
}

const bool Raw_Data_Tools::is_valid_pgm_hex_string(const String& hex_string) {
	return hex_string.length() == pgm_hex_string_length;
}

void Raw_Data_Tools::apply_raw_pgm_data_to_gui(const int pgm_num, const uint8* pgm_data, 
													 Data_Hub* hub) 
{
	auto& app_p = hub->get_app_params();
	app_p.set_current_pgm_num(pgm_num);
    String pgm_name{ "" };
    for (auto ls_byte = 0; ls_byte < MISC::pgm_name_length * 2; ls_byte += 2) {
        auto ls_byte_val{ (uint8)pgm_data[ls_byte] };
        auto ms_byte_val{ (uint8)pgm_data[ls_byte + 1] };
        auto stored_ascii_val{ uint8(ls_byte_val + (ms_byte_val * 16)) };
        restore_bit_7_to_ascii_value(stored_ascii_val);
        pgm_name += convert_stored_ascii_val_to_string(stored_ascii_val);
    }
    app_p.set_current_pgm_name(pgm_name);
    apply_raw_pgm_data_to_exp(pgm_data + first_exp_data_byte, hub);
    apply_raw_pgm_data_to_mmod(pgm_data + first_mmod_data_byte, hub);
}

void Raw_Data_Tools::apply_raw_pgm_data_to_exp(const uint8* pgm_data, Data_Hub* hub) {
    auto& app_p = hub->get_app_params();
    app_p.set_exp_tx_allowed(false);
    for (auto& param_id : ID::exp_params) {
        auto ls_byte{ GET::byte_index_for(param_id) * 2 };
        auto ls_byte_val{ pgm_data[ls_byte] };
        auto ms_byte_val{ pgm_data[ls_byte + 1] * 16 };
        auto new_val{ uint8(ls_byte_val + ms_byte_val) };
        if (GET::range_is_s_6_bit_for(param_id))
            CONVERT::signed_val_from_device_to_app_format(false, new_val);
        if (GET::range_is_s_7_bit_for(param_id))
            CONVERT::signed_val_from_device_to_app_format(true, new_val);
        auto param{ hub->get_exposed_params_state()->getParameter(param_id)};
        param->setValueNotifyingHost(param->convertTo0to1(new_val));
    }
    app_p.set_exp_tx_allowed(true);
}

void Raw_Data_Tools::apply_raw_pgm_data_to_mmod(const uint8* pgm_data, Data_Hub* hub) {
}

void Raw_Data_Tools::remove_bit_7_from_ascii_value(uint8& value) {
    value %= 64;
}

void Raw_Data_Tools::restore_bit_7_to_ascii_value(uint8& value) {
    if (value < 32 && value != stored_ascii_val_for_bar)
        value += 64;
}

const String Raw_Data_Tools::convert_stored_ascii_val_to_string(const uint8& value) {
    if (value == stored_ascii_val_for_bar)
        return "|";
    auto v{ value };
    restore_bit_7_to_ascii_value(v);
    return std::string(1, v);
}
