#pragma once

namespace ENUM
{

	constexpr enum class Ctrl_Type {
		error = -1,
		dummy,
		knob_osc_pitch_fine,
		knob_voice_mode_depth,
		knob_lfo_rate,
		knob_lpf_freq,
		switch_2_pole,
		switch_3_pole,
		switch_osc_octave
	};

	constexpr enum class Knob_Display_Type {
		error = -1,
		none,
		osc_pitch_fine,
		lfo_rate,
		osc_2_pitch_eg_int,
		unsigned_10_bit,
		voice_mode_depth
	};

}
