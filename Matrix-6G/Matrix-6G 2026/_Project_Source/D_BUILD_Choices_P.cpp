#include "D_BUILD_Choices_P.h"

StringArray Build_Choices::env_mode() {
	StringArray list;
	list.add("NORMAL^normal");
	list.add("DADR^delay | attack | decay | release");
	list.add("FREE^free run");
	list.add("BOTH^both DADR & free run");
	return list;
}

StringArray Build_Choices::env_trig_mode() {
	StringArray list;
	list.add("STRIG^single trigger");
	list.add("SRESET^single trigger reset");
	list.add("MTRIG^multiple trigger");
	list.add("MRESET^multiple trigger reset");
	list.add("XTRIG^external single trigger");
	list.add("XRESET^external single trigger reset");
	list.add("XMTRIG^external multiple trigger");
	list.add("XMRST^external multiple trigger reset");
	return list;
}

StringArray Build_Choices::env_lfo_1_trig() {
	StringArray list;
	list.add("NORMAL^normal (no LFO 1 trigger)");
	list.add("G-LFO1^gated LFO 1 trigger");
	list.add("LFO 1^LFO 1 trigger");
	return list;
}

StringArray Build_Choices::keyboard_mode() {
	StringArray list;
	list.add("REASGN^reassign");
	list.add("ROTATE^rotate");
	list.add("UNISON^unison");
	list.add("REAROB^reassign rob");
	return list;
}

StringArray Build_Choices::lever_ctrl() {
	StringArray list;
	list.add("OFF^off");
	list.add("BEND^pitch bend by lever 1");
	list.add("VIB^vibrato by lever 2");
	list.add("BOTH^modulated by both levers");
	return list;
}

StringArray Build_Choices::lfo_trig_mode() {
	StringArray list;
	list.add("OFF^off (free running)");
	list.add("STRIG^single trigger");
	list.add("MTRIG^multiple trigger");
	list.add("XTRIG^external single trigger");
	return list;
}

StringArray Build_Choices::lfo_wave_type() {
	StringArray list;
	list.add("TRI^triangle");
	list.add("UPSAW^up (rising) sawtooth");
	list.add("DNSAW^down (falling) sawtooth");
	list.add("SQUAR^square");
	list.add("RANDM^random");
	list.add("NOISE^noise");
	list.add("SAMPL^sampled");
	return list;
}

StringArray Build_Choices::input_source(bool for_lfo) {
	StringArray list;
	list.add("NONE^none");
	list.add(String{ for_lfo ? "ENV1" : "ENV 1" } + "^envelope 1");
	list.add(String{ for_lfo ? "ENV2" : "ENV 2" } + "^envelope 2");
	list.add(String{ for_lfo ? "ENV3" : "ENV 3" } + "^envelope 3");
	list.add(String{ for_lfo ? "LFO1" : "LFO 1" } + "^LFO 1");
	list.add(String{ for_lfo ? "LFO2" : "LFO 2" } + "^LFO 2");
	list.add(String{ for_lfo ? "VIB" : "VIBRATO" } + "^vibrato LFO");
	list.add(String{ for_lfo ? "RAMP1" : "RAMP 1" } + "^ramp generator 1");
	list.add(String{ for_lfo ? "RAMP2" : "RAMP 2" } + "^ramp generator 2");
	list.add(String{ for_lfo ? "KEYB" : "KEYBOARD" } + "^keyboard scaling");
	list.add(String{ for_lfo ? "PORT" : "PORTA" } + "^portamento speed");
	list.add(String{ for_lfo ? "TRAK" : "TRACKING" } + "^tracking generator");
	list.add("GATE^keyboard note gate");
	list.add(String{ for_lfo ? "VEL" : "VELOCITY" } + "^keyboard note velocity");
	list.add(String{ for_lfo ? "RVEL" : "REL VELO" } + "^keyboard release velocity");
	list.add(String{ for_lfo ? "PRES" : "PRESSURE" } + "^keyboard pressure (aftertouch)");
	list.add(String{ for_lfo ? "PED1" : "PEDAL 1" } + "^pedal 1");
	list.add(String{ for_lfo ? "PED2" : "PEDAL 2" } + "^pedal 2");
	list.add(String{ for_lfo ? "LEV1" : "LEVER 1" } + "^lever 1 ");
	list.add(String{ for_lfo ? "LEV2" : "LEVER 2" } + "^lever 2");
	list.add(String{ for_lfo ? "LEV3" : "LEVER 3" } + "^lever 3 (lever 2 reverse)");
	return list;
}

StringArray Build_Choices::off_on_matrix() {
	return { "OFF^off", "ON^on" };
}

StringArray Build_Choices::osc_1_key_track() {
	StringArray list;
	list.add("KEYBD^normal key tracking");
	list.add("PORTA^key tracking with portamento");
	return list;
}

StringArray Build_Choices::osc_1_sync() {
	StringArray list;
	list.add("OFF^off (0)");
	list.add("SOFT^soft sync (1)");
	list.add("MED^medium sync (2)");
	list.add("HARD^hard sync (3)");
	return list;
}

StringArray Build_Choices::osc_2_and_vcf_key_track() {
	StringArray list;
	list.add("OFF^key tracking is off");
	list.add("PORTA^key tracking with portamento");
	list.add("KEYBD^normal key tracking");
}

StringArray Build_Choices::osc_lever_control() {
	StringArray list;
	list.add("OFF^off");
	list.add("BEND^pitch bend by lever 1");
	list.add("VIB^vibrato by lever 2");
	list.add("BOTH^modulated by both levers");
	return list;
}

StringArray Build_Choices::osc_type(const int o) {
	StringArray list;
	list.add("OFF^off");
	list.add("PULSE^pulse");
	list.add("WAVE^wave (saw / triangle)");
	list.add("BOTH^both");
	if (o == 2)
		list.add("NOISE^noise");
	return list;
}

StringArray Build_Choices::porta_mode() {
	StringArray list;
	list.add("LINEAR^linear");
	list.add("CONST^constant time");
	list.add("EXPO^exponential");
	return list;
}

StringArray Build_Choices::ramp_trig() {
	StringArray list;
	list.add("STRIG^single trigger");
	list.add("MTRIG^multiple trigger");
	list.add("XTRIG^external single trigger");
	list.add("GATEX^gated external single trigger");
	return list;
}
