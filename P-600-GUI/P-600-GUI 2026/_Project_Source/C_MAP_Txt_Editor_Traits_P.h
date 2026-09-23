
#include <string>
#include <tuple>
#include <unordered_map>

#include "C_ID_Main_P.h"
#include "C_MISC_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace MISC;
using namespace std;

namespace MAP
{

	static const unordered_map<string, tuple<string, int, string>> txt_editor_traits{
		{ exp_osc_a_pitch, txt_editor_traits_osc_pitch },
		{ exp_osc_a_pulse_w, txt_editor_traits_u_7_bit },
		{ exp_osc_b_pitch, txt_editor_traits_osc_pitch },
		{ exp_osc_b_fine, txt_editor_traits_u_7_bit },
		{ exp_osc_b_pulse_w, txt_editor_traits_u_7_bit },
		{ exp_mixer, txt_editor_traits_u_6_bit },
		{ exp_glide, txt_editor_traits_u_4_bit },
		{ exp_filter_cutoff, txt_editor_traits_u_7_bit },
		{ exp_filter_reso, txt_editor_traits_u_6_bit },
		{ exp_filter_env_amt, txt_editor_traits_u_4_bit },
		{ exp_filter_env_attack, txt_editor_traits_u_4_bit },
		{ exp_filter_env_decay, txt_editor_traits_u_4_bit },
		{ exp_filter_env_sustain, txt_editor_traits_u_4_bit },
		{ exp_filter_env_release, txt_editor_traits_u_4_bit },
		{ exp_amp_env_attack, txt_editor_traits_u_4_bit },
		{ exp_amp_env_decay, txt_editor_traits_u_4_bit },
		{ exp_amp_env_sustain, txt_editor_traits_u_4_bit },
		{ exp_amp_env_release, txt_editor_traits_u_4_bit },
		{ exp_p_mod_amt_filter_env, txt_editor_traits_u_4_bit },
		{ exp_p_mod_amt_osc_b, txt_editor_traits_u_7_bit },
		{ exp_lfo_freq, txt_editor_traits_u_4_bit },
		{ exp_lfo_init_amt, txt_editor_traits_u_5_bit },
	};

}
