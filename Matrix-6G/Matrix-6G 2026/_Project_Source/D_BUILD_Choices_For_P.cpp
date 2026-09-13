#include "D_BUILD_Choices_For_P.h"

#include <JuceHeader.h>

using namespace BUILD;

const std::vector<std::string> Choices_For::exp_env_mode() {
	std::vector<std::string> list;
	list.push_back("NORMAL__normal");
	list.push_back("DADR__delay | attack | decay | release");
	list.push_back("FREE__free run");
	list.push_back("BOTH__both DADR & free run");
	return list;
}

const std::vector<std::string> Choices_For::exp_env_trig_mode() {
	std::vector<std::string> list;
	list.push_back("STRIG__single trigger");
	list.push_back("SRESET__single trigger reset");
	list.push_back("MTRIG__multiple trigger");
	list.push_back("MRESET__multiple trigger reset");
	list.push_back("XTRIG__external single trigger");
	list.push_back("XRESET__external single trigger reset");
	list.push_back("XMTRIG__external multiple trigger");
	list.push_back("XMRST__external multiple trigger reset");
	return list;
}

const std::vector<std::string> Choices_For::exp_env_lfo_1_trig() {
	std::vector<std::string> list;
	list.push_back("NORMAL__normal (no LFO 1 trigger)");
	list.push_back("G-LFO1__gated LFO 1 trigger");
	list.push_back("LFO 1__LFO 1 trigger");
	return list;
}

const std::vector<std::string> Choices_For::exp_keyboard_mode() {
	std::vector<std::string> list;
	list.push_back("REASGN__reassign");
	list.push_back("ROTATE__rotate");
	list.push_back("UNISON__unison");
	list.push_back("REAROB__reassign rob");
	return list;
}

const std::vector<std::string> Choices_For::exp_lever_ctrl() {
	std::vector<std::string> list;
	list.push_back("OFF__off");
	list.push_back("BEND__pitch bend by lever 1");
	list.push_back("VIB__vibrato by lever 2");
	list.push_back("BOTH__modulated by both levers");
	return list;
}

const std::vector<std::string> Choices_For::exp_lfo_trig_mode() {
	std::vector<std::string> list;
	list.push_back("OFF__off (free running)");
	list.push_back("STRIG__single trigger");
	list.push_back("MTRIG__multiple trigger");
	list.push_back("XTRIG__external single trigger");
	return list;
}

const std::vector<std::string> Choices_For::exp_lfo_wave_type() {
	std::vector<std::string> list;
	list.push_back("TRI__triangle");
	list.push_back("UPSAW__up (rising) sawtooth");
	list.push_back("DNSAW__down (falling) sawtooth");
	list.push_back("SQUAR__square");
	list.push_back("RANDM__random");
	list.push_back("NOISE__noise");
	list.push_back("SAMPL__sampled");
	return list;
}

const std::vector<std::string> Choices_For::exp_osc_1_key_track() {
	std::vector<std::string> list;
	list.push_back("KEYBD__normal key tracking");
	list.push_back("PORTA__key tracking with portamento");
	return list;
}

const std::vector<std::string> Choices_For::exp_osc_1_sync() {
	std::vector<std::string> list;
	list.push_back("OFF__off (0)");
	list.push_back("SOFT__soft sync (1)");
	list.push_back("MED__medium sync (2)");
	list.push_back("HARD__hard sync (3)");
	return list;
}

const std::vector<std::string> Choices_For::exp_osc_2_and_vcf_key_track() {
	std::vector<std::string> list;
	list.push_back("OFF__key tracking is off");
	list.push_back("PORTA__key tracking with portamento");
	list.push_back("KEYBD__normal key tracking");
	return list;
}

const std::vector<std::string> Choices_For::exp_osc_lever_control() {
	std::vector<std::string> list;
	list.push_back("OFF__off");
	list.push_back("BEND__pitch bend by lever 1");
	list.push_back("VIB__vibrato by lever 2");
	list.push_back("BOTH__modulated by both levers");
	return list;
}

const std::vector<std::string> Choices_For::exp_osc_type(const int o) {
	std::vector<std::string> list;
	list.push_back("OFF__off");
	list.push_back("PULSE__pulse");
	list.push_back("WAVE__wave (saw / triangle)");
	list.push_back("BOTH__both");
	if (o == 2)
		list.push_back("NOISE__noise");
	return list;
}

const std::vector<std::string> Choices_For::exp_porta_mode() {
	std::vector<std::string> list;
	list.push_back("LINEAR__linear");
	list.push_back("CONST__constant time");
	list.push_back("EXPO__exponential");
	return list;
}

const std::vector<std::string> Choices_For::exp_ramp_trig() {
	std::vector<std::string> list;
	list.push_back("STRIG__single trigger");
	list.push_back("MTRIG__multiple trigger");
	list.push_back("XTRIG__external single trigger");
	list.push_back("GATEX__gated external single trigger");
	return list;
}

const std::vector<std::string> Choices_For::input_source(const bool for_lfo, const bool for_mmod) {
	std::vector<std::string> list;
	list.push_back("NONE__none");
	list.push_back(std::string{ for_lfo ? "ENV1" : "ENV 1" } + "__envelope 1");
	list.push_back(std::string{ for_lfo ? "ENV2" : "ENV 2" } + "__envelope 2");
	list.push_back(std::string{ for_lfo ? "ENV3" : "ENV 3" } + "__envelope 3");
	list.push_back(std::string{ for_lfo ? "LFO1" : "LFO 1" } + "__LFO 1");
	list.push_back(std::string{ for_lfo ? "LFO2" : "LFO 2" } + "__LFO 2");
	list.push_back(std::string{ for_lfo ? "VIB" : "VIBRATO" } + "__vibrato LFO");
	list.push_back(std::string{ for_lfo ? "RAMP1" : "RAMP 1" } + "__ramp generator 1");
	list.push_back(std::string{ for_lfo ? "RAMP2" : "RAMP 2" } + "__ramp generator 2");
	list.push_back(std::string{ for_lfo ? "KEYB" : for_mmod ? "KEYBD" : "KEYBOARD" } + "__keyboard scaling");
	list.push_back(std::string{ for_lfo ? "PORT" : "PORTA" } + "__portamento speed");
	list.push_back(std::string{ for_lfo ? "TRAK" : for_mmod ? "TRACK" : "TRACKING" } + "__tracking generator");
	list.push_back("GATE__keyboard note gate");
	list.push_back(std::string{ for_lfo ? "VEL" : for_mmod ? "VELO" : "VELOCITY" } + "__keyboard note velocity");
	list.push_back(std::string{ for_lfo ? "RVEL" : for_mmod ? "R VELO" : "REL VELO" } + "__keyboard release velocity");
	list.push_back(std::string{ for_lfo ? "PRES" : for_mmod ? "PRESS" : "PRESSURE" } + "__keyboard pressure (aftertouch)");
	list.push_back(std::string{ for_lfo ? "PED1" : "PEDAL 1" } + "__pedal 1");
	list.push_back(std::string{ for_lfo ? "PED2" : "PEDAL 2" } + "__pedal 2");
	list.push_back(std::string{ for_lfo ? "LEV1" : "LEVER 1" } + "__lever 1 ");
	list.push_back(std::string{ for_lfo ? "LEV2" : "LEVER 2" } + "__lever 2");
	list.push_back(std::string{ for_lfo ? "LEV3" : "LEVER 3" } + "__lever 3 (lever 2 reverse)");
	return list;
}

const std::vector<std::string> BUILD::Choices_For::mmod_destination() {
	std::vector<std::string> list;
	list.push_back("NONE__none");
	list.push_back("OSC1 FQ__oscillator 1 frequency");
	list.push_back("OSC1 PW__oscillator 1 pulse width");
	list.push_back("OSC1 W__oscillator 1 saw/tri wave shape");
	list.push_back("OSC2 FQ__oscillator 2 frequency");
	list.push_back("OSC2 PW__oscillator 2 pulse width");
	list.push_back("OSC2 W__oscillator 2 saw/tri wave shape");
	list.push_back("OSC MIX__oscillator mix (balance)");
	list.push_back("VCF FM__VCF FM amount");
	list.push_back("VCF FM__VCF FQ cutoff frequency");
	list.push_back("VCF RES__VCF resonance");
	list.push_back("VCA1LVL__VCA 1 level");
	list.push_back("VCA2LVL__VCA 2 level");
	list.push_back("ENV1DEL__envelope 1 delay");
	list.push_back("ENV1ATK__envelope 1 attack");
	list.push_back("ENV1DEC__envelope 1 decay");
	list.push_back("ENV1REL__envelope 1 release");
	list.push_back("ENV1AMP__envelope 1 amplitude");
	list.push_back("ENV2DEL__envelope 2 delay");
	list.push_back("ENV2ATK__envelope 2 attack");
	list.push_back("ENV2DEC__envelope 2 decay");
	list.push_back("ENV2REL__envelope 2 release");
	list.push_back("ENV2AMP__envelope 2 amplitude");
	list.push_back("ENV3DEL__envelope 3 delay");
	list.push_back("ENV3ATK__envelope 3 attack");
	list.push_back("ENV3DEC__envelope 3 decay");
	list.push_back("ENV3REL__envelope 3 release");
	list.push_back("ENV3AMP__envelope 3 amplitude");
	list.push_back("LFO1SPD__LFO 1 speed");
	list.push_back("LFO1AMP__LFO 1 amplitude");
	list.push_back("LFO2SPD__LFO 2 speed");
	list.push_back("LFO2AMP__LFO 2 amplitude");
	list.push_back("PORTA__portamento time");
	return list;
}

const std::vector<std::string> Choices_For::off_on_p() {
	return { "OFF__off", "ON__on" };
}
