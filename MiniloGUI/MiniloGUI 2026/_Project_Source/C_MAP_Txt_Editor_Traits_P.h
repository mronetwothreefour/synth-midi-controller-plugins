
#include <string>
#include <tuple>
#include <unordered_map>

#include "C_ID_Main_P.h"
#include "C_MISC_P.h"
#include "C_SL_Tip_Widget_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace MISC;
using namespace std;

using Tip = Tip_For;

namespace MAP
{

	static const unordered_map<string, tuple<string, int, string>> txt_editor_traits{
		{ ID::avp_amp_mod_by_velo_amt, txt_editor_traits_u_7_bit },
		{ ID::avp_fine_tune, { allowed_chars_s_int, 3, Tip::txt_editor_s_int(50) } },
		{ ID::avp_flex_sli_bend_neg, txt_editor_traits_flex_sli_bend },
		{ ID::avp_flex_sli_bend_pos, txt_editor_traits_flex_sli_bend },
		{ ID::avp_flex_sli_range, { allowed_chars_s_int, 4, Tip::txt_editor_s_int(100) } },
		{ ID::avp_level, { allowed_chars_s_int, 3, Tip::txt_editor_s_int(25) } },
		{ ID::avp_porta_time, { allowed_chars_porta_time, 3, Tip::from_SL(SL::knob_txt_edit_porta_time_tip) } },
		{ ID::avp_scale_key, { allowed_chars_u_int, 2, Tip::txt_editor_u_int(24) } },
		{ ID::avp_transpose, { allowed_chars_s_int, 3, Tip::txt_editor_s_int(12) } },

		{ ID::exp_osc_1_pitch_fine, txt_editor_traits_osc_pitch_fine },
		{ ID::exp_osc_1_shape, txt_editor_traits_u_10_bit },
		{ ID::exp_osc_2_pitch_fine, txt_editor_traits_osc_pitch_fine },
		{ ID::exp_osc_2_shape, txt_editor_traits_u_10_bit },
		{ ID::exp_osc_2_xmod_depth, txt_editor_traits_u_10_bit },
		{ ID::exp_osc_2_pitch_eg_int, { allowed_chars_s_int, 5, Tip::txt_editor_s_int(4800) } },
		{ ID::exp_mix_osc_1, txt_editor_traits_u_10_bit },
		{ ID::exp_mix_osc_2, txt_editor_traits_u_10_bit },
		{ ID::exp_mix_noise, txt_editor_traits_u_10_bit },
		{ ID::exp_lpf_freq, txt_editor_traits_u_10_bit },
		{ ID::exp_lpf_reso, txt_editor_traits_u_10_bit },
		{ ID::exp_lpf_eg_int, { allowed_chars_s_int, 4, Tip::txt_editor_s_int(100) } },
		{ ID::exp_vca_env_attack, txt_editor_traits_u_10_bit },
		{ ID::exp_vca_env_decay, txt_editor_traits_u_10_bit },
		{ ID::exp_vca_env_sustain, txt_editor_traits_u_10_bit },
		{ ID::exp_vca_env_release, txt_editor_traits_u_10_bit },
		{ ID::exp_env_attack, txt_editor_traits_u_10_bit },
		{ ID::exp_env_decay, txt_editor_traits_u_10_bit },
		{ ID::exp_env_sustain, txt_editor_traits_u_10_bit },
		{ ID::exp_env_release, txt_editor_traits_u_10_bit },
		{ ID::exp_lfo_int, txt_editor_traits_u_10_bit },
		{ ID::exp_delay_hpf_freq, txt_editor_traits_u_10_bit },
		{ ID::exp_delay_time, txt_editor_traits_u_10_bit },
		{ ID::exp_delay_feedback, txt_editor_traits_u_10_bit },
	};

}
