#pragma once

#include <JuceHeader.h>

namespace ID
{

		static const String avp_amp_mod_by_velo_amt{ "avp_amp_mod_by_velo_amt" };
		static const String avp_fine_tune{ "avp_fine_tune" };
		static const String avp_flex_sli_bend_neg{ "avp_flex_sli_bend_neg" };
		static const String avp_flex_sli_bend_pos{ "avp_flex_sli_bend_pos" };
		static const String avp_flex_sli_range{ "avp_flex_sli_range" };
		static const String avp_flex_sli_target{ "avp_flex_sli_target" };
		static const String avp_keyboard_octave{ "avp_keyboard_octave" };
		static const String avp_level{ "avp_level" };
		static const String avp_lfo_sync_bpm_on{ "avp_lfo_sync_bpm_on" };
		static const String avp_lfo_sync_key_on{ "avp_lfo_sync_key_on" };
		static const String avp_lfo_sync_voice_on{ "avp_lfo_sync_voice_on" };
		static const String avp_microtune_scale{ "avp_microtune_scale" };
		static const String avp_name{ "avp_name" };
		static const String avp_porta_mode_on{ "avp_porta_mode_on" };
		static const String avp_porta_sync_bpm_on{ "avp_porta_sync_bpm_on" };
		static const String avp_porta_time{ "avp_porta_time" };
		static const String avp_scale_key{ "avp_scale_key" };
		static const String avp_transpose{ "avp_transpose" };
		static const String avp_voice_mode{ "avp_voice_mode" };

		static const String tree_aux_voice{ "tree_aux_voice" };
		static const String xml_state_aux_voice{ "xml_state_aux_voice" };

		static const StringArray aux_voice_params{
			avp_amp_mod_by_velo_amt,
			avp_fine_tune,
			avp_flex_sli_bend_neg,
			avp_flex_sli_bend_pos,
			avp_flex_sli_range,
			avp_flex_sli_target,
			avp_keyboard_octave,
			avp_level,
			avp_lfo_sync_bpm_on,
			avp_lfo_sync_key_on,
			avp_lfo_sync_voice_on,
			avp_microtune_scale,
			avp_name,
			avp_porta_mode_on,
			avp_porta_sync_bpm_on,
			avp_porta_time,
			avp_scale_key,
			avp_transpose,
			avp_voice_mode
		};

}