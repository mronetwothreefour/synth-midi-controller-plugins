#include "D_MIDI_Raw_Data_Tools_P.h"

#include "C_GET_P.h"
#include "C_ID_Main_P.h"
#include "C_MIDI_P.h"
#include "C_MISC_P.h"
#include "D_CONVERT_P.h"
#include "D_X_G_Data_Hub_P.h"

using namespace MIDI;
using namespace MISC;

const bool Raw_Data_Tools::is_relevant_sysex(const MidiMessage& msg) {
	if (msg.isSysEx()) {
		auto d = msg.getSysExData();
		return d[0] == id_maker && d[1] == id_device;
	}
	return false;
}

const bool Raw_Data_Tools::is_valid_pgm_hex_string(const String& hex) {
	return hex.initialSectionContainingOnly(allowed_chars_hex).length() == pgm_hex_string_length;
}

void Raw_Data_Tools::apply_raw_data_to_current_pgm(const uint8* pgm_data, Data_Hub* hub) {
    auto& app_p = hub->get_app_params();
    app_p.set_exp_tx_allowed(false);
    auto state = hub->get_exposed_params_state();
    for (int param_index = 0; param_index < ID::exp_params.size(); ++param_index) {
        auto param_id = ID::exp_params[param_index];
        if (!String{ param_id }.contains("unassigned")) {
            auto ls_byte = GET::ls_byte_for(param_index);
            auto ms_bit_pack_byte = GET::ms_bit_pack_byte_for(param_index);
            auto ms_bit_mask = GET::ms_bit_mask_for(param_index);
            auto new_val = pgm_data[ls_byte];
            new_val += 128 * (pgm_data[ms_bit_pack_byte] & ms_bit_mask);
            if (param_id == ID::exp_clock_tempo)
                new_val -= clock_tempo_offset;
            auto param = state->getParameter(param_id);
            param->setValueNotifyingHost(param->convertTo0to1(new_val));
        }
    }
    app_p.set_exp_tx_allowed(true);
}

const vector<uint8> Raw_Data_Tools::extract_raw_data_from_current_pgm(Data_Hub* hub) {
    std::vector<uint8> pgm_data;
    for (int i = 0; i < 229; ++i)
        pgm_data.push_back((uint8)0);
    auto state = hub->get_exposed_params_state();
    for (int param_index = 0; param_index < ID::exp_params.size(); ++param_index) {
        auto param_id = ID::exp_params[param_index];
        if (!String{ param_id }.contains("unassigned")) {
            auto param = state->getParameterAsValue(param_id);
            auto v = (uint8)(int)param.getValue();
            if (param_id == ID::exp_clock_tempo)
                v += clock_tempo_offset;
            auto ms_bit_pack_byte = GET::ms_bit_pack_byte_for(param_index);
            auto ls_byte = GET::ls_byte_for(param_index);
            if (v > 127)
                pgm_data[ms_bit_pack_byte] += GET::ms_bit_mask_for(param_index);
            pgm_data[ls_byte] = v % 128;
        }
    }
    return pgm_data;
}
