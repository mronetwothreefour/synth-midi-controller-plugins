#include "D_BUILD_Choices_For_P.h"

using namespace BUILD;

const StringArray Choices_For::exp_env_mode() {
	StringArray list;
	list.add("NORMAL__normal");
	list.add("DADR__delay | attack | decay | release");
	list.add("FREE__free run");
	list.add("BOTH__both DADR & free run");
	return list;
}

const StringArray Choices_For::exp_env_trig_mode() {
	StringArray list;
	list.add("STRIG__single trigger");
	list.add("SRESET__single trigger reset");
	list.add("MTRIG__multiple trigger");
	list.add("MRESET__multiple trigger reset");
	list.add("XTRIG__external single trigger");
	list.add("XRESET__external single trigger reset");
	list.add("XMTRIG__external multiple trigger");
	list.add("XMRST__external multiple trigger reset");
	return list;
}

const StringArray Choices_For::exp_env_lfo_1_trig() {
	StringArray list;
	list.add("NORMAL__normal (no LFO 1 trigger)");
	list.add("G-LFO1__gated LFO 1 trigger");
	list.add("LFO 1__LFO 1 trigger");
	return list;
}

const StringArray Choices_For::exp_keyboard_mode() {
	StringArray list;
	list.add("REASGN__reassign");
	list.add("ROTATE__rotate");
	list.add("UNISON__unison");
	list.add("REAROB__reassign rob");
	return list;
}

const StringArray Choices_For::exp_lever_ctrl() {
	StringArray list;
	list.add("OFF__off");
	list.add("BEND__pitch bend by lever 1");
	list.add("VIB__vibrato by lever 2");
	list.add("BOTH__modulated by both levers");
	return list;
}

const StringArray Choices_For::exp_lfo_trig_mode() {
	StringArray list;
	list.add("OFF__off (free running)");
	list.add("STRIG__single trigger");
	list.add("MTRIG__multiple trigger");
	list.add("XTRIG__external single trigger");
	return list;
}

const StringArray Choices_For::exp_lfo_wave_type() {
	StringArray list;
	list.add("TRI__triangle");
	list.add("UPSAW__up (rising) sawtooth");
	list.add("DNSAW__down (falling) sawtooth");
	list.add("SQUAR__square");
	list.add("RANDM__random");
	list.add("NOISE__noise");
	list.add("SAMPL__sampled");
	return list;
}

const StringArray Choices_For::exp_osc_1_key_track() {
	StringArray list;
	list.add("KEYBD__normal key tracking");
	list.add("PORTA__key tracking with portamento");
	return list;
}

const StringArray Choices_For::exp_osc_1_sync() {
	StringArray list;
	list.add("OFF__off (0)");
	list.add("SOFT__soft sync (1)");
	list.add("MED__medium sync (2)");
	list.add("HARD__hard sync (3)");
	return list;
}

const StringArray Choices_For::exp_osc_2_and_vcf_key_track() {
	StringArray list;
	list.add("OFF__key tracking is off");
	list.add("PORTA__key tracking with portamento");
	list.add("KEYBD__normal key tracking");
	return list;
}

const StringArray Choices_For::exp_osc_lever_control() {
	StringArray list;
	list.add("OFF__off");
	list.add("BEND__pitch bend by lever 1");
	list.add("VIB__vibrato by lever 2");
	list.add("BOTH__modulated by both levers");
	return list;
}

const StringArray Choices_For::exp_osc_type(const int o) {
	StringArray list;
	list.add("OFF__off");
	list.add("PULSE__pulse");
	list.add("WAVE__wave (saw / triangle)");
	list.add("BOTH__both");
	if (o == 2)
		list.add("NOISE__noise");
	return list;
}

const StringArray Choices_For::exp_porta_mode() {
	StringArray list;
	list.add("LINEAR__linear");
	list.add("CONST__constant time");
	list.add("EXPO__exponential");
	return list;
}

const StringArray Choices_For::exp_ramp_trig() {
	StringArray list;
	list.add("STRIG__single trigger");
	list.add("MTRIG__multiple trigger");
	list.add("XTRIG__external single trigger");
	list.add("GATEX__gated external single trigger");
	return list;
}

const StringArray Choices_For::input_source(const bool for_lfo, const bool for_mmod) {
	StringArray list;
	list.add("NONE__none");
	list.add(String{ for_lfo ? "ENV1" : "ENV 1" } + "__envelope 1");
	list.add(String{ for_lfo ? "ENV2" : "ENV 2" } + "__envelope 2");
	list.add(String{ for_lfo ? "ENV3" : "ENV 3" } + "__envelope 3");
	list.add(String{ for_lfo ? "LFO1" : "LFO 1" } + "__LFO 1");
	list.add(String{ for_lfo ? "LFO2" : "LFO 2" } + "__LFO 2");
	list.add(String{ for_lfo ? "VIB" : "VIBRATO" } + "__vibrato LFO");
	list.add(String{ for_lfo ? "RAMP1" : "RAMP 1" } + "__ramp generator 1");
	list.add(String{ for_lfo ? "RAMP2" : "RAMP 2" } + "__ramp generator 2");
	list.add(String{ for_lfo ? "KEYB" : for_mmod ? "KEYBD" : "KEYBOARD" } + "__keyboard scaling");
	list.add(String{ for_lfo ? "PORT" : "PORTA" } + "__portamento speed");
	list.add(String{ for_lfo ? "TRAK" : for_mmod ? "TRACK" : "TRACKING" } + "__tracking generator");
	list.add("GATE__keyboard note gate");
	list.add(String{ for_lfo ? "VEL" : for_mmod ? "VELO" : "VELOCITY" } + "__keyboard note velocity");
	list.add(String{ for_lfo ? "RVEL" : for_mmod ? "R VELO" : "REL VELO" } + "__keyboard release velocity");
	list.add(String{ for_lfo ? "PRES" : for_mmod ? "PRESS" : "PRESSURE" } + "__keyboard pressure (aftertouch)");
	list.add(String{ for_lfo ? "PED1" : "PEDAL 1" } + "__pedal 1");
	list.add(String{ for_lfo ? "PED2" : "PEDAL 2" } + "__pedal 2");
	list.add(String{ for_lfo ? "LEV1" : "LEVER 1" } + "__lever 1 ");
	list.add(String{ for_lfo ? "LEV2" : "LEVER 2" } + "__lever 2");
	list.add(String{ for_lfo ? "LEV3" : "LEVER 3" } + "__lever 3 (lever 2 reverse)");
	return list;
}

const StringArray BUILD::Choices_For::mmod_destination() {
	StringArray list;
	list.add("NONE__none");
	list.add("OSC1 FQ__oscillator 1 frequency");
	list.add("OSC1 PW__oscillator 1 pulse width");
	list.add("OSC1 W__oscillator 1 saw/tri wave shape");
	list.add("OSC2 FQ__oscillator 2 frequency");
	list.add("OSC2 PW__oscillator 2 pulse width");
	list.add("OSC2 W__oscillator 2 saw/tri wave shape");
	list.add("OSC MIX__oscillator mix (balance)");
	list.add("VCF FM__VCF FM amount");
	list.add("VCF FM__VCF FQ cutoff frequency");
	list.add("VCF RES__VCF resonance");
	list.add("VCA1LVL__VCA 1 level");
	list.add("VCA2LVL__VCA 2 level");
	list.add("ENV1DEL__envelope 1 delay");
	list.add("ENV1ATK__envelope 1 attack");
	list.add("ENV1DEC__envelope 1 decay");
	list.add("ENV1REL__envelope 1 release");
	list.add("ENV1AMP__envelope 1 amplitude");
	list.add("ENV2DEL__envelope 2 delay");
	list.add("ENV2ATK__envelope 2 attack");
	list.add("ENV2DEC__envelope 2 decay");
	list.add("ENV2REL__envelope 2 release");
	list.add("ENV2AMP__envelope 2 amplitude");
	list.add("ENV3DEL__envelope 3 delay");
	list.add("ENV3ATK__envelope 3 attack");
	list.add("ENV3DEC__envelope 3 decay");
	list.add("ENV3REL__envelope 3 release");
	list.add("ENV3AMP__envelope 3 amplitude");
	list.add("LFO1SPD__LFO 1 speed");
	list.add("LFO1AMP__LFO 1 amplitude");
	list.add("LFO2SPD__LFO 2 speed");
	list.add("LFO2AMP__LFO 2 amplitude");
	list.add("PORTA__portamento time");
	return list;
}

const StringArray Choices_For::off_on_p() {
	return { "OFF__off", "ON__on" };
}
