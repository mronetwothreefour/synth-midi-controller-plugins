#include "H_00-P_Build_Tree.h"

#include "H_99-B_Misc.h"

ValueTree Build_Tree::exposed_parameter(Identifier id, String name, Ctrl_Type ctrl, 
										Knob_Display_Type display, uint8 nrpn, 
										uint8 choice_count, uint8 init_choice,
										int ctrl_center_x, int ctrl_center_y, int ctrl_w, 
										int ctrl_h, String description, 
										ValueTree curt_choice_names, ValueTree choice_names)
{
	ValueTree tree_ep{ id,
		{
			{ ID::ep_p_name, name },
			{ ID::ep_p_ctrl_type, (int)ctrl },
			{ ID::ep_p_knob_display_type, (int)display },
			{ ID::ep_p_nrpn, nrpn },
			{ ID::ep_p_choice_count, choice_count },
			{ ID::ep_p_init_choice, init_choice },
			{ ID::ep_p_ctrl_center_x, ctrl_center_x },
			{ ID::ep_p_ctrl_center_y, ctrl_center_y },
			{ ID::ep_p_ctrl_width, ctrl_w },
			{ ID::ep_p_ctrl_height, ctrl_h },
			{ ID::ep_p_description, description },
		},
		{ curt_choice_names, choice_names }
	};
	return tree_ep;
}

String Build_Tree::convert_int_to_seq_step_pitch_name(const int i) {
	auto note{ i % 24 };
	auto octave{ String(i / 24) };
	switch (note)
	{
	case 0: return "C" + octave;
	case 1: return "C" + octave + "+";
	case 2: return "C#" + octave;
	case 3: return "C#" + octave + "+";
	case 4: return "D" + octave;
	case 5: return "D" + octave + "+";
	case 6: return "D#" + octave;
	case 7: return "D#" + octave + "+";
	case 8: return "E" + octave;
	case 9: return "E" + octave + "+";
	case 10: return "F" + octave;
	case 11: return "F" + octave + "+";
	case 12: return "F#" + octave;
	case 13: return "F#" + octave + "+";
	case 14: return "G" + octave;
	case 15: return "G" + octave + "+";
	case 16: return "G#" + octave;
	case 17: return "G#" + octave + "+";
	case 18: return "A" + octave;
	case 19: return "A" + octave + "+";
	case 20: return "A#" + octave;
	case 21: return "A#" + octave + "+";
	case 22: return "B" + octave;
	case 23: return "B" + octave + "+";
	default: return "";
	}
}

ValueTree Build_Tree::choice_names_arpeg_mode(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", "1 octave up", nullptr);
	tree.setProperty("choice_1", "1 octave down", nullptr);
	tree.setProperty("choice_2", "1 octave up & down", nullptr);
	tree.setProperty("choice_3", "1 octave assign", nullptr);
	tree.setProperty("choice_4", "1 octave random", nullptr);
	tree.setProperty("choice_5", "2 octaves up", nullptr);
	tree.setProperty("choice_6", "2 octaves down", nullptr);
	tree.setProperty("choice_7", "2 octaves up & down", nullptr);
	tree.setProperty("choice_8", "2 octaves assign", nullptr);
	tree.setProperty("choice_9", "2 octaves random", nullptr);
	tree.setProperty("choice_10", "3 octaves up", nullptr);
	tree.setProperty("choice_11", "3 octaves down", nullptr);
	tree.setProperty("choice_12", "3 octaves up & down", nullptr);
	tree.setProperty("choice_13", "3 octaves assign", nullptr);
	tree.setProperty("choice_14", "3 octaves random", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_bend_range(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0",  curt ? "0" : "no bend", nullptr);;
	tree.setProperty("choice_1",  "+/-1"  + curt ? "" : " semitone", nullptr);
	tree.setProperty("choice_2",  "+/-2"  + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_3",  "+/-3"  + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_4",  "+/-4"  + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_5",  "+/-5"  + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_6",  "+/-6"  + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_7",  "+/-7"  + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_8",  "+/-8"  + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_9",  "+/-9"  + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_10", "+/-10" + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_11", "+/-11" + curt ? "" : " semitones", nullptr);
	tree.setProperty("choice_12", "+/-12" + curt ? "" : " semitones", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_clock_div(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0",  curt ? "half note" : "half note (BPM / 2)", nullptr);
	tree.setProperty("choice_1",  curt ? "quarter note" : "quarter note (BPM x 1)", nullptr);
	tree.setProperty("choice_2",  curt ? "8th note" : "8th note (BPM x 2)", nullptr);
	tree.setProperty("choice_3",  curt ? "8th note, 1/2 swing" : "8th note, 1/2 swing (BPM x 2)", nullptr);
	tree.setProperty("choice_4",  curt ? "8th note, full swing" : "8th note, full swing (BPM x 2)", nullptr);
	tree.setProperty("choice_5",  curt ? "8th note triplets" : "8th note triplets (BPM x 3)", nullptr);
	tree.setProperty("choice_6",  curt ? "16th note" : "16th note (BPM x 4)", nullptr);
	tree.setProperty("choice_7",  curt ? "16th note, 1/2 swing" : "16th note, 1/2 swing (BPM x 4)", nullptr);
	tree.setProperty("choice_8",  curt ? "16th note, full swing" : "16th note, full swing (BPM x 4)", nullptr);
	tree.setProperty("choice_9",  curt ? "16th note triplets" : "16th note triplets (BPM x 6)", nullptr);
	tree.setProperty("choice_10", curt ? "32nd note" : "32nd note (BPM x 8)", nullptr);
	tree.setProperty("choice_11", curt ? "32nd note triplets" : "32nd note triplets (BPM x 12)", nullptr);
	tree.setProperty("choice_12", curt ? "64th note triplets" : "64th note triplets (BPM x 24)", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_clock_tempo(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	for (auto choice = 0; choice < EP::choice_count_clock_tempo; ++choice) {
		auto name{ String(choice + EP::clock_tempo_offset) };
		name += curt ? "" : " BPM";
		tree.setProperty("choice_" + (String)choice, name, nullptr);
	}
	return tree;
}

ValueTree Build_Tree::choice_names_glide_mode(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", "Fixed Rate", nullptr);;
	tree.setProperty("choice_1", "Fixed Rate Auto", nullptr);
	tree.setProperty("choice_2", "Fixed Time", nullptr);
	tree.setProperty("choice_3", "Fixed Time Auto", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_knob_assign(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	String choice_{ "choice_" };
	for (int osc = 1; osc < 3; ++osc) {
		String o{ osc };
		tree.setProperty(choice_ + (osc == 1 ? "0" : "_6"),  "oscillator " + o + " pitch", nullptr);
		tree.setProperty(choice_ + (osc == 1 ? "1" : "_7"),  "oscillator " + o + " fine tune", nullptr);
		tree.setProperty(choice_ + (osc == 1 ? "2" : "_8"),  "oscillator " + o + " wave shape", nullptr);
		tree.setProperty(choice_ + (osc == 1 ? "3" : "_9"),  "oscillator " + o + " glide rate", nullptr);
		tree.setProperty(choice_ + (osc == 1 ? "4" : "_10"), "oscillator " + o + " key track", nullptr);
		tree.setProperty(choice_ + (osc == 1 ? "5" : "_11"), "sub-oscillator " + o + " level", nullptr);
	}
	tree.setProperty(choice_ + "12", "hard sync oscillators", nullptr);
	tree.setProperty(choice_ + "13", "glide mode", nullptr);
	tree.setProperty(choice_ + "14", "oscillator slop", nullptr);
	tree.setProperty(choice_ + "15", "pitch bend range", nullptr);
	tree.setProperty(choice_ + "16", "keyed note priority", nullptr);
	tree.setProperty(choice_ + "17", "oscillators 1 & 2 mix", nullptr);
	tree.setProperty(choice_ + "18", "noise level", nullptr);
	tree.setProperty(choice_ + "19", "external audio " + curt ? "in level" : "input level", nullptr);
	tree.setProperty(choice_ + "20", "LPF cutoff frequency", nullptr);
	tree.setProperty(choice_ + "21", "LPF resonance", nullptr);
	tree.setProperty(choice_ + "22", "LPF keyboard amount", nullptr);
	tree.setProperty(choice_ + "23", "LPF freq. mod. amount", nullptr);
	tree.setProperty(choice_ + "24", "LPF 2- or 4-pole select", nullptr);
	tree.setProperty(choice_ + "25", "LPF envelope amount", nullptr);
	tree.setProperty(choice_ + "26", curt ? "LPF env. vel. amt." : "LPF envelope velocity amount", nullptr);
	tree.setProperty(choice_ + "27", "LPF envelope delay", nullptr);
	tree.setProperty(choice_ + "28", "LPF envelope attack", nullptr);
	tree.setProperty(choice_ + "29", "LPF envelope decay", nullptr);
	tree.setProperty(choice_ + "30", "LPF envelope sustain", nullptr);
	tree.setProperty(choice_ + "31", "LPF envelope release", nullptr);
	tree.setProperty(choice_ + "32", "VCA initial level", nullptr);
	tree.setProperty(choice_ + "33", "VCA envelope amount", nullptr);
	tree.setProperty(choice_ + "34", curt ? "VCA env. vel. amt." : "VCA envelope velocity amount", nullptr);
	tree.setProperty(choice_ + "35", "VCA Envelope Delay", nullptr);
	tree.setProperty(choice_ + "36", "VCA Envelope Attack", nullptr);
	tree.setProperty(choice_ + "37", "VCA Envelope Decay", nullptr);
	tree.setProperty(choice_ + "38", "VCA Envelope Sustain", nullptr);
	tree.setProperty(choice_ + "39", "VCA Envelope Release", nullptr);
	tree.setProperty(choice_ + "40", "Voice Volume", nullptr);
	for (int lfo = 0; lfo < 4; ++lfo) {
		String l{ lfo + 1 };
		tree.setProperty(choice_ + String{ 41 + lfo * 5 }, "LFO " + l + " frequency", nullptr);
		tree.setProperty(choice_ + String{ 42 + lfo * 5 }, "LFO " + l + " wave shape", nullptr);
		tree.setProperty(choice_ + String{ 43 + lfo * 5 }, "LFO " + l + " amount", nullptr);
		tree.setProperty(
			choice_ + String{ 44 + lfo * 5 },
			"LFO " + l + (curt ? " mod." : " modulation") + " destination", nullptr);
		tree.setProperty(choice_ + String{ 45 + lfo * 5 }, "LFO " + l + " key sync", nullptr);
	}
	tree.setProperty(choice_ + "61", "env. 3 " + String{ curt ? " mod." : " modulation" } + " destination", nullptr);
	tree.setProperty(choice_ + "62", "envelope 3 amount", nullptr);
	tree.setProperty(choice_ + "63", "env. 3 velocity amount", nullptr);
	tree.setProperty(choice_ + "64", "envelope 3 delay", nullptr);
	tree.setProperty(choice_ + "65", "envelope 3 attack", nullptr);
	tree.setProperty(choice_ + "66", "envelope 3 decay", nullptr);
	tree.setProperty(choice_ + "67", "envelope 3 sustain", nullptr);
	tree.setProperty(choice_ + "68", "envelope 3 release", nullptr);
	tree.setProperty(choice_ + "69", "envelope 3 repeat", nullptr);
	for (int mod = 0; mod != 4; ++mod) {
		String m{ mod + 1 };
		tree.setProperty(choice_ + String{ 70 + mod * 3 }, "modulator " + m + " source", nullptr);
		tree.setProperty(choice_ + String{ 71 + mod * 3 }, "modulator " + m + " amount", nullptr);
		tree.setProperty(choice_ + String{ 72 + mod * 3 }, "modulator " + m + " destination", nullptr);
	}
	tree.setProperty(choice_ + "82", "modulation wheel " + curt ? "amt." : "amount", nullptr);
	tree.setProperty(choice_ + "83", "modulation wheel " + curt ? "dest." : "destination", nullptr);
	tree.setProperty(choice_ + "84", "pressure " + String{ curt ? "" : "(aftertouch) " } + "amount", nullptr);
	tree.setProperty(choice_ + "85", "pressure " + String{ curt ? "" : "(aftertouch) " } + "destination", nullptr);
	tree.setProperty(choice_ + "86", "breath " + String{ curt ? "" : "controller " } + "amount", nullptr);
	tree.setProperty(choice_ + "87", "breath " + String{ curt ? "" : "controller " } + "destination", nullptr);
	tree.setProperty(choice_ + "88", String{ curt ? "" : "note " } + "velocity amount", nullptr);
	tree.setProperty(choice_ + "89", String{ curt ? "" : "note " } + "velocity destination", nullptr);
	tree.setProperty(choice_ + "90", "foot pedal amount", nullptr);
	tree.setProperty(choice_ + "91", "foot pedal destination", nullptr);
	tree.setProperty(choice_ + "92", "Push It! switch pitch", nullptr);
	tree.setProperty(choice_ + "93", "Push It! switch velocity", nullptr);
	tree.setProperty(choice_ + "94", "Push It! switch mode", nullptr);
	tree.setProperty(choice_ + "95", "clock tempo (BPM)", nullptr);
	tree.setProperty(choice_ + "96", "clock division", nullptr);
	tree.setProperty(choice_ + "97", "arpeggiator mode", nullptr);
	tree.setProperty(choice_ + "98", "arpeggiator on / off", nullptr);
	tree.setProperty(choice_ + "99", "sequencer trigger mode", nullptr);
	tree.setProperty(choice_ + "100", "sequencer on / off", nullptr);
	for (int track = 1; track < 5; ++track) {
		String t{ track };
		tree.setProperty( choice_ + "10" + t, "sequencer track " + t + (curt ? " dest." : " destination"), nullptr);
	}
	for (int track = 0; track < 4; ++track) {
		for (int step = 0; step < 16; ++step)
			tree.setProperty(
				choice_ + String{ 105 + track * 16 + step },
				String{ curt ? "seq." : "sequencer" } + " track " + String{ track + 1 } + " step " + String{ step + 1 },
				nullptr);
	}
	return tree;
}

ValueTree Build_Tree::choice_names_lfo_freq(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	for (int n = 0; n < EP::first_lfo_pitched_freq_choice; ++n)
		tree.setProperty("choice_" + (String)n, curt ? (String)n : "un-synced " + (String)n, nullptr);
	for (auto n = EP::first_lfo_pitched_freq_choice; n < EP::first_lfo_synced_freq_choice; ++n) {
		auto pitch{ Int_To_Pitch_Name::convert(n - EP::first_lfo_pitched_freq_choice) };
		auto name{ curt ? pitch : (String)n + " (pitch freq. " + pitch + ")" };
		tree.setProperty("choice_" + (String)n, name, nullptr);
	}
	tree.setProperty("choice_151", curt ? "1:32" : "synced 151 : 1 LFO cycle lasts 32 steps", nullptr);
	tree.setProperty("choice_152", curt ? "1:16" : "synced 152 : 1 LFO cycle lasts 16 steps", nullptr);
	tree.setProperty("choice_153", curt ? "1:8" : "synced 153 : 1 LFO cycle lasts 8 steps", nullptr);
	tree.setProperty("choice_154", curt ? "1:6" : "synced 154 : 1 LFO cycle lasts 6 steps", nullptr);
	tree.setProperty("choice_155", curt ? "1:4" : "synced 155 : 1 LFO cycle lasts 4 steps", nullptr);
	tree.setProperty("choice_156", curt ? "1:3" : "synced 156 : 1 LFO cycle lasts 3 steps", nullptr);
	tree.setProperty("choice_157", curt ? "1:2" : "synced 157 : 1 LFO cycle lasts 2 steps", nullptr);
	tree.setProperty("choice_158", curt ? "1:1.5" : "synced 158 : 1 LFO cycle lasts 1.5 steps", nullptr);
	tree.setProperty("choice_159", curt ? "1:1" : "synced 159 : 1 LFO cycle lasts 1 step", nullptr);
	tree.setProperty("choice_160", curt ? "3:2" : "synced 160 : 1 LFO cycle lasts 2/3 step", nullptr);
	tree.setProperty("choice_161", curt ? "2:1" : "synced 161 : 1 LFO cycle lasts 1/2 step", nullptr);
	tree.setProperty("choice_162", curt ? "3:1" : "synced 162 : 1 LFO cycle lasts 1/3 step", nullptr);
	tree.setProperty("choice_163", curt ? "4:1" : "synced 163 : 1 LFO cycle lasts 1/4 step", nullptr);
	tree.setProperty("choice_164", curt ? "6:1" : "synced 164 : 1 LFO cycle lasts 1/6 step", nullptr);
	tree.setProperty("choice_165", curt ? "8:1" : "synced 165 : 1 LFO cycle lasts 1/8 step", nullptr);
	tree.setProperty("choice_166", curt ? "16:1" : "synced 166 : 1 LFO cycle lasts 1/16 step", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_lfo_shape(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", "triangle", nullptr);
	tree.setProperty("choice_1", "reverse sawtooth", nullptr);
	tree.setProperty("choice_2", "sawtooth", nullptr);
	tree.setProperty("choice_3", "pulse (square)", nullptr);
	tree.setProperty("choice_4", "random", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_lpf_freq(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	for (uint8 num = 0; num < EP::choice_count_lpf_freq; ++num) {
		String n{ num };
		auto pitch{ Int_To_Pitch_Name::convert(num) };
		auto name{ curt ? pitch : n + " (pitch freq. " + pitch + ")" };
		tree.setProperty("choice_" + n, name, nullptr);
	}
	return tree;
}

ValueTree Build_Tree::choice_names_lpf_type(const bool curt)
{
	return ValueTree();
}

ValueTree Build_Tree::choice_names_mod_dest(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	String choice_{ "choice_" };
	tree.setProperty(choice_ + "0", "off", nullptr);
	tree.setProperty(choice_ + "1", "oscillator 1 pitch", nullptr);
	tree.setProperty(choice_ + "2", "oscillator 2 pitch", nullptr);
	tree.setProperty(choice_ + "3", "oscillator 1 & 2 pitch", nullptr);
	tree.setProperty(choice_ + "4", "oscillator mix", nullptr);
	tree.setProperty(choice_ + "5", "noise level", nullptr);
	tree.setProperty(choice_ + "6", "oscillator 1 pulse width", nullptr);
	tree.setProperty(choice_ + "7", "oscillator 2 pulse width", nullptr);
	tree.setProperty(choice_ + "8", "oscillator 1 & 2 PW", nullptr);
	tree.setProperty(choice_ + "9", "LPF cutoff frequency", nullptr);
	tree.setProperty(choice_ + "10", "LPF resonance", nullptr);
	tree.setProperty(choice_ + "11", "LPF FM amount", nullptr);
	tree.setProperty(choice_ + "12", "VCA level", nullptr);
	tree.setProperty(choice_ + "13", "output panning", nullptr);
	for (int n = 14; n < 18; ++n)
		tree.setProperty(choice_ + (String)n, "LFO " + String{ n - 13 } + " frequency", nullptr);
	tree.setProperty(choice_ + "18", "All LFO Frequencies", nullptr);
	for (int n = 19; n < 23; ++n)
		tree.setProperty(choice_ + (String)n, "LFO " + String{ n - 18 } + " amount", nullptr);
	tree.setProperty(choice_ + "23", "all LFO amounts", nullptr);
	tree.setProperty(choice_ + "24", "LPF envelope amount", nullptr);
	tree.setProperty(choice_ + "25", "VCA envelope amount", nullptr);
	tree.setProperty(choice_ + "26", "envelope 3 amount", nullptr);
	tree.setProperty(choice_ + "27", "all envelope amounts", nullptr);
	tree.setProperty(choice_ + "28", "LPF envelope attack", nullptr);
	tree.setProperty(choice_ + "29", "VCA envelope attack", nullptr);
	tree.setProperty(choice_ + "30", "envelope 3 attack", nullptr);
	tree.setProperty(choice_ + "31", "all envelope attacks", nullptr);
	tree.setProperty(choice_ + "32", "LPF envelope decay", nullptr);
	tree.setProperty(choice_ + "33", "VCA envelope decay", nullptr);
	tree.setProperty(choice_ + "34", "envelope 3 decay", nullptr);
	tree.setProperty(choice_ + "35", "all envelope decays", nullptr);
	tree.setProperty(choice_ + "36", "LPF envelope release", nullptr);
	tree.setProperty(choice_ + "37", "VCA envelope release", nullptr);
	tree.setProperty(choice_ + "38", "envelope 3 release", nullptr);
	tree.setProperty(choice_ + "39", "all envelope releases", nullptr);
	for (int n = 40; n < 44; ++n)
		tree.setProperty(choice_ + (String)n, "modulator " + String{ n - 39 } + " amount", nullptr);
	tree.setProperty(choice_ + "44", "external audio " + String{ curt ? "in level" : "input level" }, nullptr);
	tree.setProperty(choice_ + "45", String{ curt ? "sub-osc." : "sub-oscillator" } + " 1 level", nullptr);
	tree.setProperty(choice_ + "46", String{ curt ? "sub-osc." : "sub-oscillator" } + " 2 level", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_mod_src(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", "Off", nullptr);
	for (auto n = 1; n < 5; ++n)
		tree.setProperty("choice_" + (String)n, "sequencer track " + (String)n, nullptr);
	for (auto n = 5; n < 9; ++n)
		tree.setProperty("choice_" + (String)n, "LFO " + String(n - 4), nullptr);
	tree.setProperty("choice_9", "LPF envelope", nullptr);
	tree.setProperty("choice_10", "VCA envelope", nullptr);
	tree.setProperty("choice_11", "envelope 3", nullptr);
	tree.setProperty("choice_12", "pitch bend", nullptr);
	tree.setProperty("choice_13", "mod wheel", nullptr);
	tree.setProperty("choice_14", "pressure (aftertouch)", nullptr);
	tree.setProperty("choice_15", "MIDI breath", nullptr);
	tree.setProperty("choice_16", "MIDI foot pedal", nullptr);
	tree.setProperty("choice_17", "MIDI expression", nullptr);
	tree.setProperty("choice_18", "velocity", nullptr);
	tree.setProperty("choice_19", "note number", nullptr);
	tree.setProperty("choice_20", "noise", nullptr);
	tree.setProperty("choice_21", "audio in env. follower", nullptr);
	tree.setProperty("choice_22", "audio in peak hold", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_note_priority(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "low note" : "low note has priority", nullptr);
	tree.setProperty("choice_1", curt ? "low note (re-trigger)" : "low note has priority (re-trigger)", nullptr);
	tree.setProperty("choice_2", curt ? "high note" : "high note has priority", nullptr);
	tree.setProperty("choice_3", curt ? "high note (re-trigger)" : "high note has priority (re-trigger)", nullptr);
	tree.setProperty("choice_4", curt ? "last note" : "last note hit has priority", nullptr);
	tree.setProperty("choice_5", curt ? "last note (re-trigger)" : "last note hit has priority (re-trigger)", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_osc_fine(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	for (auto choice = 0; choice < 101; ++choice) {
		if (curt) {
			auto name = (choice > EP::choice_count_osc_fine ? "+" : "") + String{ choice - 50 };
			tree.setProperty("choice_" + (String)choice, name, nullptr);
		}
		else {
			String name{ "" };
			if (choice < 49)
				name = String{ choice - 50 } + " cents";
			if (choice == 49)
				name = "-1 cent";
			if (choice == 50)
				name = "no detune";
			if (choice == 51)
				name = "+1 cent";
			if (choice > 51)
				name = "+" + String{ choice - 50 } + " cents";
			tree.setProperty("choice_" + (String)choice, name, nullptr);
		}
	}
	return tree;
}

ValueTree Build_Tree::choice_names_osc_shape(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "OFF" : "oscillator off", nullptr);
	tree.setProperty("choice_1", curt ? "SAW" : "sawtooth", nullptr);
	tree.setProperty("choice_2", curt ? "TRI" : "triangle", nullptr);
	tree.setProperty("choice_3", curt ? "S/T" : "sawtooth / triangle mix", nullptr);
	for (int choice = 4; choice < EP::choice_count_osc_shape; ++choice) {
		if (choice == 54)
			tree.setProperty("choice_54", curt ? "SQR" : "square (pulse: width 50)", nullptr);
		else {
			auto pw = String{ choice - 4 };
			tree.setProperty("choice_" + (String)choice, curt ? "PW " + pw : 
				"pulse: width " + pw, nullptr);
		}
	}
	return tree;
}

ValueTree Build_Tree::choice_names_push_it_mode(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", "normal", nullptr);
	tree.setProperty("choice_1", "toggle", nullptr);
	tree.setProperty("choice_2", "audio in", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_seq_track_step(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	for (int n = 0; n < 126; ++n)
		tree.setProperty(
			"choice_" + (String)n,
			curt ? convert_int_to_seq_step_pitch_name(n) :
			(String)n + " (" + convert_int_to_seq_step_pitch_name(n) + ")",
			nullptr);
	tree.setProperty("choice_126", curt ? "<" : "reset sequence", nullptr);
	tree.setProperty("choice_127", curt ? "." : "rest", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_seq_tracks_2_and_4_dest(const bool track_2, const bool curt) {
	auto tree{ choice_names_mod_dest(curt) };
	String name{ curt ? "seq." : "sequencer" };
	name += " track " + String{ track_2 ? 1 : 3 } + " slew";
	tree.setProperty("choice_47", name, nullptr);
	return ValueTree();
}

ValueTree Build_Tree::choice_names_seq_trig_mode(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", "normal", nullptr);
	tree.setProperty("choice_1", "normal, no reset", nullptr);
	tree.setProperty("choice_2", "no gate", nullptr);
	tree.setProperty("choice_3", "no gate, no reset", nullptr);
	tree.setProperty("choice_4", "key step", nullptr);
	tree.setProperty("choice_5", "audio input", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_voice_name_char(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	for (int n = 0; n < 32; ++n)
		tree.setProperty("choice_" + (String)n, "ASCII control character " + (String)n, nullptr);
	tree.setProperty("choice_32", curt ? " " : "space", nullptr);
	for (int n = 33; n < EP::choice_count_voice_name_char; ++n) {
		String name{ std::string(1, (char)n) };
		if (n == 92)
			name = curt ? (String)u8R"(¥)" : "yen symbol";
		if (n == 126)
			name = curt ? "->" : "right arrow";
		if (n == 127)
			name = curt ? "<-" : "left arrow";
		tree.setProperty("choice_" + (String)n, name, nullptr);
	}
	return tree;
}
