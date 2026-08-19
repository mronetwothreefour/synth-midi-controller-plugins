#include "D_TREE_Aux_Voice_Params_P.h"

#include "C_GET_P.h"
#include "C_ID_Aux_Voice_P.h"

using namespace TREE;

Aux_Voice_Params::Aux_Voice_Params(UndoManager* u_m) :
	tree{ ID::tree_aux_voice },
	u_m{ u_m }
{
	for (auto& id : ID::aux_voice_params) {
		auto init_choice = GET::init_choice_for(id);
		tree.setProperty(id, init_choice == -1 ? "Init Program" : (String)init_choice, nullptr);
	}
}

const int TREE::Aux_Voice_Params::amp_mod_by_velo_amt()
{
	return 0;
}

void TREE::Aux_Voice_Params::set_amp_mod_by_velo_amt(const int new_setting)
{
}

const String TREE::Aux_Voice_Params::name()
{
	return String();
}

void TREE::Aux_Voice_Params::set_name(const String new_setting)
{
}

const int TREE::Aux_Voice_Params::flex_sli_bend_limit(const bool pos_limit)
{
	return 0;
}

void TREE::Aux_Voice_Params::set_flex_sli_bend_limit(const bool pos_limit, const int new_setting)
{
}

const int TREE::Aux_Voice_Params::flex_sli_range()
{
	return 0;
}

void TREE::Aux_Voice_Params::set_flex_sli_range(const int new_setting)
{
}

const int TREE::Aux_Voice_Params::flex_sli_target()
{
	return 0;
}

void TREE::Aux_Voice_Params::set_flex_sli_target(const int new_setting)
{
}

const int TREE::Aux_Voice_Params::keyboard_octave()
{
	return 0;
}

void TREE::Aux_Voice_Params::set_keyboard_octave(const int new_setting)
{
}

const bool TREE::Aux_Voice_Params::lfo_sync_bpm_on()
{
	return false;
}

void TREE::Aux_Voice_Params::set_lfo_sync_bpm_on(const bool should_be_on)
{
}

const bool TREE::Aux_Voice_Params::lfo_sync_key_on()
{
	return false;
}

void TREE::Aux_Voice_Params::set_lfo_sync_key_on(const bool should_be_on)
{
}

const bool TREE::Aux_Voice_Params::lfo_sync_voice_on()
{
	return false;
}

void TREE::Aux_Voice_Params::set_lfo_sync_voice_on(const bool should_be_on)
{
}

const int TREE::Aux_Voice_Params::microtune_scale()
{
	return 0;
}

void TREE::Aux_Voice_Params::set_microtune_scale(const int new_setting)
{
}

int TREE::Aux_Voice_Params::microtune_scale_hardware_index(const int scale)
{
	return 0;
}

const int TREE::Aux_Voice_Params::fine_tune()
{
	return 0;
}

void TREE::Aux_Voice_Params::set_fine_tune(const int new_setting)
{
}

const int TREE::Aux_Voice_Params::level()
{
	return 0;
}

void TREE::Aux_Voice_Params::set_level(const int new_setting)
{
}

const int TREE::Aux_Voice_Params::transpose()
{
	return 0;
}

void TREE::Aux_Voice_Params::set_transpose(const int new_setting)
{
}

const bool TREE::Aux_Voice_Params::porta_mode_on()
{
	return false;
}

void TREE::Aux_Voice_Params::set_porta_mode_on(const bool should_be_on)
{
}

const bool TREE::Aux_Voice_Params::porta_sync_bpm_on()
{
	return false;
}

void TREE::Aux_Voice_Params::set_porta_sync_bpm_on(const bool should_be_on)
{
}

const int TREE::Aux_Voice_Params::porta_time()
{
	return 0;
}

void TREE::Aux_Voice_Params::set_porta_time(const int new_setting)
{
}

const int TREE::Aux_Voice_Params::scale_key()
{
	return 0;
}

void TREE::Aux_Voice_Params::set_scale_key(const int new_setting)
{
}

const int TREE::Aux_Voice_Params::voice_mode()
{
	return 0;
}

void TREE::Aux_Voice_Params::set_voice_mode(const int new_setting)
{
}

Value TREE::Aux_Voice_Params::get_param_as_value(const String& param_id)
{
	return Value();
}

std::unique_ptr<XmlElement> TREE::Aux_Voice_Params::get_state()
{
	return std::unique_ptr<XmlElement>();
}

void TREE::Aux_Voice_Params::replace_state(const ValueTree& new_state)
{
}
