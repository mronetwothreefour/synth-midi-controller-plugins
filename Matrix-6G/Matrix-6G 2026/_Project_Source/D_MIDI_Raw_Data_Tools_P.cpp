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

void Raw_Data_Tools::apply_raw_pgm_data_to_app(const int pgm_num, const uint8* pgm_data, 
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
    auto& mmod_p = hub->get_matrix_mod_params();
    for (int mod_num = 0; mod_num < 10; ++mod_num) {
        auto mod = "mmod_" + String{ mod_num };
        auto first_byte = mod_num * 6;

        auto src_ls_byte_val{ pgm_data[first_byte] };
        auto src_ms_byte_val{ pgm_data[first_byte + 1] * 16 };
        auto src_val{ src_ls_byte_val + src_ms_byte_val };
        mmod_p.set_param(mod + "_src", (uint8)src_val);

        auto amt_ls_byte_val{ pgm_data[first_byte + 2] };
        auto amt_ms_byte_val{ pgm_data[first_byte + 3] * 16 };
        auto amt_val{ uint8(amt_ls_byte_val + amt_ms_byte_val) };
        CONVERT::signed_val_from_device_to_app_format(true, amt_val);
        mmod_p.set_param(mod + "_amt", amt_val);

        auto dst_ls_byte_val{ pgm_data[first_byte + 4] };
        auto dst_ms_byte_val{ pgm_data[first_byte + 5] * 16 };
        auto dst_val{ dst_ls_byte_val + dst_ms_byte_val };
        mmod_p.set_param(mod + "_dst", (uint8)dst_val);
    }
}

const vector<uint8> MIDI::Raw_Data_Tools::extract_raw_pgm_data_from_app(Data_Hub* hub) {
    std::vector<uint8> pgm_data;
    uint8 checksum{ 0 };
    auto curr_pgm_name{ hub->get_app_params().current_pgm_name() };
    add_name_to_raw_data(true, curr_pgm_name, pgm_data, checksum);
    add_exp_to_raw_pgm_data(hub, pgm_data, checksum);
    add_mmod_to_raw_pgm_data(hub, pgm_data, checksum);
    for (auto i = pgm_data.size(); i < MIDI::data_size_pgm; ++i)
        pgm_data.push_back((uint8)0);
    pgm_data.push_back(checksum % (uint8)128);
    return pgm_data;
}

void Raw_Data_Tools::add_exp_to_raw_pgm_data(Data_Hub* hub, std::vector<uint8>& pgm_data,
                                             uint8& checksum)
{
    std::vector<uint8> exp_data;
    for (auto i = 0; i < data_size_exp; ++i)
        exp_data.push_back((uint8)0);
    for (auto& param_id : ID::exp_params) {
        auto param = hub->get_exposed_params_state()->getParameterAsValue(param_id);
        auto v = (uint8)roundToInt(param.getValue());
        auto ls_byte = GET::byte_index_for(param_id) * 2;
        auto ms_byte = ls_byte + 1;
        if (GET::range_is_s_6_bit_for(param_id))
            CONVERT::signed_val_from_app_to_device_format(false, v);
        if (GET::range_is_s_7_bit_for(param_id))
            CONVERT::signed_val_from_app_to_device_format(true, v);
        exp_data[ls_byte] = uint8(v % 16);
        exp_data[ms_byte] = uint8(v / 16);
        checksum += v;
    }
    for (auto byte : exp_data)
        pgm_data.push_back(byte);
}

void Raw_Data_Tools::add_mmod_to_raw_pgm_data(Data_Hub* hub, std::vector<uint8>& pgm_data,
                                              uint8& checksum)
{
    auto& mmod_p = hub->get_matrix_mod_params();
    for (auto mod_num = 0; mod_num < 10; ++mod_num) {
        auto mod = "mmod_" + String{ mod_num };
        
        auto src_val = (uint8)mmod_p.current_setting_for(mod + "_src");
        pgm_data.push_back(src_val % 16);
        pgm_data.push_back(src_val / 16);
        checksum += src_val;

        auto amt_val = (uint8)mmod_p.current_setting_for(mod + "_amt");
        CONVERT::signed_val_from_app_to_device_format(true, amt_val);
        pgm_data.push_back(amt_val % 16);
        pgm_data.push_back(amt_val / 16);
        checksum += amt_val;

        auto dst_val = (uint8)mmod_p.current_setting_for(mod + "_dst");
        pgm_data.push_back(dst_val % 16);
        pgm_data.push_back(dst_val / 16);
        checksum += dst_val;
    }
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

void Raw_Data_Tools::add_name_to_raw_data(bool for_pgm, String& name, vector<uint8>& data, 
                                          uint8& checksum)
{
    for (auto i = 0; i < (for_pgm ? 8 : 6); ++i) {
        auto ascii_val{ (uint8)name[i] };
        remove_bit_7_from_ascii_value(ascii_val);
        data.push_back(ascii_val % 16);
        data.push_back(ascii_val / 16);
        checksum += ascii_val;
    }
}
