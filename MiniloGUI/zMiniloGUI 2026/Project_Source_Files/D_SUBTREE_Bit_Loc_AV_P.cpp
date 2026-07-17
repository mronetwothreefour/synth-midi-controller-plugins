#include "D_SUBTREE_Bit_Loc_AV_P.h"

ValueTree Subtree_Bit_Loc_AV_P::build()
{

	return { 
		ID::subtree_bit_locations, {}, {
			ValueTree{ ID::avp_00_voice_mode, 
				{
					{ "bit_0", "byte_73__bit_0" },
					{ "bit_1", "byte_73__bit_1" },
					{ "bit_2", "byte_73__bit_2" },
				}
			},
			ValueTree{ ID::avp_01_keyboard_octave, 
				{
					{ "bit_0", "byte_83__bit_0" },
					{ "bit_1", "byte_83__bit_1" },
					{ "bit_2", "byte_83__bit_2" },
				}
			},
			ValueTree{ ID::avp_02_slider_target, 
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
			ValueTree{ ID::avp_03_slider_range, 
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
			ValueTree{ ID::avp_04_slider_range_pitch_bend_pos, 
				{
					{ "bit_0", "byte_75__bit_0" },
					{ "bit_1", "byte_75__bit_1" },
					{ "bit_2", "byte_75__bit_2" },
					{ "bit_3", "byte_75__bit_3" },
				}
			},
			ValueTree{ ID::avp_05_slider_range_pitch_bend_neg, 
				{
					{ "bit_0", "byte_75__bit_4" },
					{ "bit_1", "byte_75__bit_5" },
					{ "bit_2", "byte_75__bit_6" },
					{ "bit_3", "byte_71__bit_3" },
				}
			},
			ValueTree{ ID::avp_06_lfo_sync_bpm_on, 
				{
					{ "bit_0", "byte_78__bit_1" },
				}
			},
			ValueTree{ ID::avp_07_lfo_sync_key_on, 
				{
					{ "bit_0", "byte_78__bit_0" },
				}
			},
			ValueTree{ ID::avp_08_lfo_sync_voice_on, 
				{
					{ "bit_0", "byte_78__bit_02" },
				}
			},
			ValueTree{ ID::avp_09_porta_time,
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
			ValueTree{ ID::avp_10_porta_mode_on,
				{
					{ "bit_0", "byte_78__bit_3" },
				}
			},
			ValueTree{ ID::avp_11_porta_sync_bpm_on,
				{
					{ "bit_0", "byte_78__bit_4" },
				}
			},
			ValueTree{ ID::avp_12_amp_mod_by_velo_amt,
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
			ValueTree{ ID::avp_13_pgm_level,
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
			ValueTree{ ID::avp_14_microtune_scale,
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
			ValueTree{ ID::avp_15_scale_key,
				{
					{ "bit_0", "byte_90__bit_0" },
					{ "bit_1", "byte_90__bit_1" },
					{ "bit_2", "byte_90__bit_2" },
					{ "bit_3", "byte_90__bit_3" },
					{ "bit_4", "byte_90__bit_4" },
				}
			},
			ValueTree{ ID::avp_16_pgm_fine_tune,
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
			ValueTree{ ID::avp_17_pgm_transpose,
				{
					{ "bit_0", "byte_92__bit_0" },
					{ "bit_1", "byte_92__bit_1" },
					{ "bit_2", "byte_92__bit_2" },
					{ "bit_3", "byte_92__bit_3" },
					{ "bit_4", "byte_92__bit_4" },
				}
			},
		}
	};
}
