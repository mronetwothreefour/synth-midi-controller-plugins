#include "H_00-P_Build_Tree.h"

using ICT = Input_Choice_Type;

ValueTree Build_Tree::exposed_parameter(Identifier id, uint8 number, String name, 
										Ctrl_Type ctrl, uint8 byte_index, Range_Type range, 
										Slider_Display_Type display, uint8 choice_count, 
										uint8 init_choice, int ctrl_center_x, 
										int ctrl_center_y, int ctrl_w, String description, 
										ValueTree curt_choice_names, ValueTree choice_names)
{
	ValueTree tree_ep{ id, 
		{
			{ ID::ep_p_number, number },
			{ ID::ep_p_name, name },
			{ ID::ep_p_ctrl_type, (int)ctrl },
			{ ID::ep_p_byte_index, byte_index },
			{ ID::ep_p_range_type, (int)range },
			{ ID::ep_p_slider_display_type, (int)display },
			{ ID::ep_p_choice_count, choice_count },
			{ ID::ep_p_init_choice, init_choice },
			{ ID::ep_p_ctrl_center_x, ctrl_center_x },
			{ ID::ep_p_ctrl_center_y, ctrl_center_y },
			{ ID::ep_p_ctrl_width, ctrl_w },
			{ ID::ep_p_description, description },
		}, 
		{ curt_choice_names, choice_names } 
	};
	return tree_ep;
}

ValueTree Build_Tree::choice_names_env_mode(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "NORMAL" : "normal", nullptr);
	tree.setProperty("choice_1", curt ? "DADR" : "delay | attack | decay | release", nullptr);
	tree.setProperty("choice_2", curt ? "FREE" : "free run", nullptr);
	tree.setProperty("choice_3", curt ? "BOTH" : "both DADR & free run", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_env_trig_mode(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "STRIG" : "single trigger", nullptr);
	tree.setProperty("choice_1", curt ? "SRESET" : "single trigger reset", nullptr);
	tree.setProperty("choice_2", curt ? "MTRIG" : "multiple trigger", nullptr);
	tree.setProperty("choice_3", curt ? "MRESET" : "multiple trigger reset", nullptr);
	tree.setProperty("choice_4", curt ? "XTRIG" : "ext. single trigger", nullptr);
	tree.setProperty("choice_5", curt ? "XRESET" : "ext. single trigger reset", nullptr);
	tree.setProperty("choice_6", curt ? "XMTRIG" : "ext. multiple trigger", nullptr);
	tree.setProperty("choice_7", curt ? "XMRST" : "ext. multiple trigger reset", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_env_lfo_1_trig(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "NORMAL" : "normal (no LFO 1 trigger)", nullptr);
	tree.setProperty("choice_1", curt ? "G-LFO1" : "gated LFO 1 trigger", nullptr);
	tree.setProperty("choice_2", curt ? "LFO 1" : "LFO 1 trigger", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_keyboard_mode(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "REASGN" : "reassign", nullptr);
	tree.setProperty("choice_1", curt ? "ROTATE" : "rotate", nullptr);
	tree.setProperty("choice_2", curt ? "UNISON" : "unison", nullptr);
	tree.setProperty("choice_3", curt ? "REAROB" : "reassign rob", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_lever_ctrl(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "OFF" : "off", nullptr);
	tree.setProperty("choice_1", curt ? "BEND" : "pitch bend by lever 1", nullptr);
	tree.setProperty("choice_2", curt ? "VIB" : "vibrato by lever 2", nullptr);
	tree.setProperty("choice_3", curt ? "BOTH" : "modulated by both levers", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_lfo_trig_mode(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "OFF" : "off (free running)", nullptr);
	tree.setProperty("choice_1", curt ? "STRIG" : "single trigger", nullptr);
	tree.setProperty("choice_2", curt ? "MTRIG" : "multiple trigger", nullptr);
	tree.setProperty("choice_3", curt ? "XTRIG" : "external single trigger", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_lfo_wave_type(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "TRI" : "triangle", nullptr);
	tree.setProperty("choice_1", curt ? "UPSAW" : "up (rising) sawtooth", nullptr);
	tree.setProperty("choice_2", curt ? "DNSAW" : "down (falling) sawtooth", nullptr);
	tree.setProperty("choice_3", curt ? "SQUAR" : "square", nullptr);
	tree.setProperty("choice_4", curt ? "RANDM" : "random", nullptr);
	tree.setProperty("choice_5", curt ? "NOISE" : "noise", nullptr);
	tree.setProperty("choice_6", curt ? "SAMPL" : "sampled", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_input_source(Input_Choice_Type t, const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "NONE" : "none", nullptr);
	tree.setProperty("choice_1", curt ? t == ICT::lfo ? "ENV1" : "ENV 1" : "envelope 1", nullptr);
	tree.setProperty("choice_2", curt ? t == ICT::lfo ? "ENV2" : "ENV 2" : "envelope 2", nullptr);
	tree.setProperty("choice_3", curt ? t == ICT::lfo ? "ENV3" : "ENV 3" : "envelope 3", nullptr);
	tree.setProperty("choice_4", curt ? t == ICT::lfo ? "LFO1" : "LFO 1" : "LFO 1", nullptr);
	tree.setProperty("choice_5", curt ? t == ICT::lfo ? "LFO2" : "LFO 2" : "LFO 2", nullptr);
	tree.setProperty("choice_6", curt ? t == ICT::lfo ? "VIB" : "VIBRATO" : "vibrato LFO", nullptr);
	tree.setProperty("choice_7", curt ? t == ICT::lfo ? "RAMP1" : "RAMP 1" : "ramp generator 1", nullptr);
	tree.setProperty("choice_8", curt ? t == ICT::lfo ? "RAMP2" : "RAMP 2" : "ramp generator 2", nullptr);
	tree.setProperty("choice_9", curt ? t == ICT::lfo ? "KEYB" : t == ICT::mod ? "KEYBD" : "KEYBOARD" : "keyboard scaling", nullptr);
	tree.setProperty("choice_10", curt ? t == ICT::lfo ? "PORT" : "PORTA" : "portamento speed", nullptr);
	tree.setProperty("choice_11", curt ? t == ICT::lfo ? "TRAK" : t == ICT::mod ? "TRACK" : "TRACKING" : "tracking generator", nullptr);
	tree.setProperty("choice_12", curt ? "GATE" : "keyboard note gate", nullptr);
	tree.setProperty("choice_13", curt ? t == ICT::lfo ? "VEL" : t == ICT::mod ? "VELO" : "VELOCITY" : "keyboard note velocity", nullptr);
	tree.setProperty("choice_14", curt ? t == ICT::lfo ? "RVEL" : t == ICT::mod ? "R VELO" : "REL VELO" : "keyboard release velocity", nullptr);
	tree.setProperty("choice_15", curt ? t == ICT::lfo ? "PRES" : t == ICT::mod ? "PRESS" : "PRESSURE" : "keyboard pressure (aftertouch)", nullptr);
	tree.setProperty("choice_16", curt ? t == ICT::lfo ? "PED1" : "PEDAL 1" : "pedal 1", nullptr);
	tree.setProperty("choice_17", curt ? t == ICT::lfo ? "PED2" : "PEDAL 2" : "pedal 2", nullptr);
	tree.setProperty("choice_18", curt ? t == ICT::lfo ? "LEV1" : "LEVER 1" : "lever 1 ", nullptr);
	tree.setProperty("choice_19", curt ? t == ICT::lfo ? "LEV2" : "LEVER 2" : "lever 2", nullptr);
	tree.setProperty("choice_20", curt ? t == ICT::lfo ? "LEV3" : "LEVER 3" : "lever 3 (lever 2 reverse)", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_off_on_matrix(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "OFF" : "off", nullptr);
	tree.setProperty("choice_1", curt ? "ON" : "on", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_osc_1_key_track(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "KEYBD" : "normal key tracking", nullptr);
	tree.setProperty("choice_1", curt ? "PORTA" : "key tracking with portamento", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_osc_2_and_vcf_key_track(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "OFF" : "key tracking is off", nullptr);
	tree.setProperty("choice_1", curt ? "PORTA" : "key tracking with portamento", nullptr);
	tree.setProperty("choice_2", curt ? "KEYBD" : "normal key tracking", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_osc_lever_control(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "OFF" : "off", nullptr);
	tree.setProperty("choice_1", curt ? "BEND" : "pitch bend by lever 1", nullptr);
	tree.setProperty("choice_2", curt ? "VIB" : "vibrato by lever 2", nullptr);
	tree.setProperty("choice_3", curt ? "BOTH" : "modulated by both levers", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_osc_type(const int o, const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "OFF" : "off", nullptr);
	tree.setProperty("choice_1", curt ? "PULSE" : "pulse", nullptr);
	tree.setProperty("choice_2", curt ? "WAVE" : "wave (saw / triangle)", nullptr);
	tree.setProperty("choice_3", curt ? "BOTH" : "both", nullptr);
	if (o == 2)
		tree.setProperty("choice_4", curt ? "NOISE" : "noise", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_porta_mode(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "LINEAR" : "linear", nullptr);
	tree.setProperty("choice_1", curt ? "CONST" : "constant time", nullptr);
	tree.setProperty("choice_2", curt ? "EXPO" : "exponential", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_ramp_trig(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "STRIG" : "single trigger", nullptr);
	tree.setProperty("choice_1", curt ? "MTRIG" : "multiple trigger", nullptr);
	tree.setProperty("choice_2", curt ? "XTRIG" : "external single trigger", nullptr);
	tree.setProperty("choice_3", curt ? "GATEX" : "gated ext. single trigger", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_signed_6_bit_int(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	for (auto choice = 0; choice < 64; ++choice) {
		auto name{ (choice > 31 ? "+" : "") + String{ choice - 31 } };
		tree.setProperty("choice_" + (String)choice, name, nullptr);
	}
	return tree;
}

