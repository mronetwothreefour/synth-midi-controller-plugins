#pragma once

#include <JuceHeader.h>

namespace TREE {

	class Aux_Voice_Params
	{
	private: ValueTree tree;
	private: UndoManager* u_m;

	//==============================================================================
	public: Aux_Voice_Params(UndoManager* u_m);

	public: const int amp_mod_by_velo_amt();
	public: void set_amp_mod_by_velo_amt(const int new_setting);

	public: const int fine_tune();
	public: void set_fine_tune(const int new_setting);

	public: const int flex_sli_bend_limit(const bool pos_limit);
	public: void set_flex_sli_bend_limit(const bool pos_limit, const int new_setting);

	public: const int flex_sli_range();
	public: void set_flex_sli_range(const int new_setting);

	public: const int flex_sli_target();
	public: void set_flex_sli_target(const int new_setting);

	public: const int keyboard_octave();
	public: void set_keyboard_octave(const int new_setting);

	public: const int level();
	public: void set_level(const int new_setting);

	public: const bool lfo_sync_bpm_on();
	public: void set_lfo_sync_bpm_on(const bool should_be_on);

	public: const bool lfo_sync_key_on();
	public: void set_lfo_sync_key_on(const bool should_be_on);

	public: const bool lfo_sync_voice_on();
	public: void set_lfo_sync_voice_on(const bool should_be_on);

	public: const int microtune_scale();
	public: void set_microtune_scale(const int new_setting);
	public: int microtune_scale_hardware_index(const int scale);

	public: const String name();
	public: void set_name(const String new_setting);

	public: const int transpose();
	public: void set_transpose(const int new_setting);

	public: const bool porta_mode_on();
	public: void set_porta_mode_on(const bool should_be_on);

	public: const bool porta_sync_bpm_on();
	public: void set_porta_sync_bpm_on(const bool should_be_on);

	public: const int porta_time();
	public: void set_porta_time(const int new_setting);

	public: const int scale_key();
	public: void set_scale_key(const int new_setting);

	public: const int voice_mode();
	public: void set_voice_mode(const int new_setting);

	public: Value get_param_as_value(const String& param_id);

	public: std::unique_ptr<XmlElement> get_current_state();
	public: void replace_state(const ValueTree& new_state);

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Aux_Voice_Params)
	};

}
