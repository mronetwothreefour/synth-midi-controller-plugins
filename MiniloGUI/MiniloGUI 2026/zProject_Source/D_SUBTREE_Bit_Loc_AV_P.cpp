#include "D_SUBTREE_Bit_Loc_AV_P.h"

#include "C_ENUM_P.h"
#include "C_ID_P.h"

using namespace ENUM;

using AVP = Aux_Voice_Param;

ValueTree Subtree_Bit_Loc_AV_P::build()
{

	return { 
		ID::subtree_bit_locations, {}, {
			ValueTree{ String{ (int)AVP::amp_mod_by_velo_amt },
				{
					{ "bit_0", "byte_37__bit_0" },
					{ "bit_1", "byte_37__bit_1" },
					{ "bit_2", "byte_37__bit_2" },
					{ "bit_3", "byte_37__bit_3" },
					{ "bit_4", "byte_37__bit_4" },
					{ "bit_5", "byte_37__bit_5" },
					{ "bit_6", "byte_37__bit_6" },
				}
			},
		// AVP::current_voice_name is plugin-only
		ValueTree{ String{ (int)AVP::flex_slider_bend_range_neg },
				{
					{ "bit_0", "byte_75__bit_4" },
					{ "bit_1", "byte_75__bit_5" },
					{ "bit_2", "byte_75__bit_6" },
					{ "bit_3", "byte_71__bit_3" },
				}
			},
			ValueTree{ String{ (int)AVP::flex_slider_bend_range_pos },
				{
					{ "bit_0", "byte_75__bit_0" },
					{ "bit_1", "byte_75__bit_1" },
					{ "bit_2", "byte_75__bit_2" },
					{ "bit_3", "byte_75__bit_3" },
				}
			},
			ValueTree{ String{ (int)AVP::flex_slider_range },
				{
					{ "bit_0", "byte_86__bit_0" },
					{ "bit_1", "byte_86__bit_1" },
					{ "bit_2", "byte_86__bit_2" },
					{ "bit_3", "byte_86__bit_3" },
					{ "bit_4", "byte_86__bit_4" },
					{ "bit_5", "byte_86__bit_5" },
					{ "bit_6", "byte_86__bit_6" },
					{ "bit_7", "byte_79__bit_6" },
				}
			},
			ValueTree{ String{ (int)AVP::flex_slider_target }, 
				{
					{ "bit_0", "byte_82__bit_0" },
					{ "bit_1", "byte_82__bit_1" },
					{ "bit_2", "byte_82__bit_2" },
					{ "bit_3", "byte_82__bit_3" },
					{ "bit_4", "byte_82__bit_4" },
					{ "bit_5", "byte_82__bit_5" },
					{ "bit_6", "byte_82__bit_6" },
				}
			},
			ValueTree{ String{ (int)AVP::keyboard_octave },
				{
					{ "bit_0", "byte_83__bit_0" },
					{ "bit_1", "byte_83__bit_1" },
					{ "bit_2", "byte_83__bit_2" },
				}
			},
			ValueTree{ String{ (int)AVP::lfo_sync_bpm_on },
				{
					{ "bit_0", "byte_78__bit_1" },
				}
			},
			ValueTree{ String{ (int)AVP::lfo_sync_key_on },
				{
					{ "bit_0", "byte_78__bit_0" },
				}
			},
			ValueTree{ String{ (int)AVP::lfo_sync_voice_on },
				{
					{ "bit_0", "byte_78__bit_02" },
				}
			},
			ValueTree{ String{ (int)AVP::microtune_scale },
				{
					{ "bit_0", "byte_89__bit_0" },
					{ "bit_1", "byte_89__bit_1" },
					{ "bit_2", "byte_89__bit_2" },
					{ "bit_3", "byte_89__bit_3" },
					{ "bit_4", "byte_89__bit_4" },
					{ "bit_5", "byte_89__bit_5" },
					{ "bit_6", "byte_89__bit_6" },
					{ "bit_7", "byte_87__bit_1" },
				}
			},
			ValueTree{ String{ (int)AVP::pgm_fine_tune },
				{
					{ "bit_0", "byte_88__bit_0" },
					{ "bit_1", "byte_88__bit_1" },
					{ "bit_2", "byte_88__bit_2" },
					{ "bit_3", "byte_88__bit_3" },
					{ "bit_4", "byte_88__bit_4" },
					{ "bit_5", "byte_88__bit_5" },
					{ "bit_6", "byte_88__bit_6" },
				}
			},
			ValueTree{ String{ (int)AVP::pgm_level },
				{
					{ "bit_0", "byte_81__bit_0" },
					{ "bit_1", "byte_81__bit_1" },
					{ "bit_2", "byte_81__bit_2" },
					{ "bit_3", "byte_81__bit_3" },
					{ "bit_4", "byte_81__bit_4" },
					{ "bit_5", "byte_81__bit_5" },
					{ "bit_6", "byte_81__bit_6" },
				}
			},
			ValueTree{ String{ (int)AVP::pgm_transpose },
				{
					{ "bit_0", "byte_92__bit_0" },
					{ "bit_1", "byte_92__bit_1" },
					{ "bit_2", "byte_92__bit_2" },
					{ "bit_3", "byte_92__bit_3" },
					{ "bit_4", "byte_92__bit_4" },
				}
			},
			ValueTree{ String{ (int)AVP::porta_mode_on },
				{
					{ "bit_0", "byte_78__bit_3" },
				}
			},
			ValueTree{ String{ (int)AVP::porta_sync_bpm_on },
				{
					{ "bit_0", "byte_78__bit_4" },
				}
			},
			ValueTree{ String{ (int)AVP::porta_time },
				{
					{ "bit_0", "byte_69__bit_0" },
					{ "bit_1", "byte_69__bit_1" },
					{ "bit_2", "byte_69__bit_2" },
					{ "bit_3", "byte_69__bit_3" },
					{ "bit_4", "byte_69__bit_4" },
					{ "bit_5", "byte_69__bit_5" },
					{ "bit_6", "byte_69__bit_6" },
					{ "bit_7", "byte_63__bit_5" },
				}
			},
			ValueTree{ String{ (int)AVP::scale_key },
				{
					{ "bit_0", "byte_90__bit_0" },
					{ "bit_1", "byte_90__bit_1" },
					{ "bit_2", "byte_90__bit_2" },
					{ "bit_3", "byte_90__bit_3" },
					{ "bit_4", "byte_90__bit_4" },
				}
			},
			ValueTree{ String{ (int)AVP::voice_mode },
				{
					{ "bit_0", "byte_73__bit_0" },
					{ "bit_1", "byte_73__bit_1" },
					{ "bit_2", "byte_73__bit_2" },
				}
			},
		}
	};
}
