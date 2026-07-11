#pragma once

namespace ENUM
{

	constexpr enum class Ctrl_Type {
		error = -1,
		knob,
		knob_pitch,
		knob_osc_shape,
		toggle,
		cbox,
		seq_step,
		seq_step_track_1,
		voice_name_char
	};

	constexpr enum class Slider_Display_Type {
		error = -1,
		none,
		bend_range,
		clock_tempo,
		lfo_freq,
		lpf_freq,
		osc_fine,
		osc_pitch,
		osc_shape,
		osc_slop,
		seq_step,
		seq_step_track_1,
		signed_8_bit,
		unsigned_7_bit,
		voice_name_char
	};

	constexpr enum class Seq_Track {
		error = -1, none, one, two, three, four
	};

	constexpr enum class Seq_Track_Step {
		error = -1, none, one, two, three, four, five, six, seven, eight,
		nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, all
	};

}
