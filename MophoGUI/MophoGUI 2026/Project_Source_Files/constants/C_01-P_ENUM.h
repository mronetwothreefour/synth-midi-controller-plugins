#pragma once

namespace ENUM
{

	const enum class Choice_Menu_Type {
		error = -1,
		standard,
		osc_shape,
		binary,
		lfo_freq,
		seq_step,
		voice_name_char
	};

	constexpr enum class Ctrl_Type {
		error = -1,
		dummy,
		knob,
		knob_pitch,
		knob_osc_shape,
		toggle,
		cbox,
		seq_step,
		voice_name_char
	};

	constexpr enum class Knob_Display_Type {
		error = -1,
		none,
		tempo,
		lfo_freq,
		lpf_freq,
		osc_fine,
		osc_pitch,
		osc_shape,
		osc_slop,
		pitch_bend,
		signed_8_bit,
		unsigned_7_bit
	};

	constexpr enum class Seq_Track {
		error = -1, none, one, two, three, four
	};

	constexpr enum class Seq_Track_Step {
		error = -1, none, one, two, three, four, five, six, seven, eight,
		nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, all
	};

}
