#include "H_00-P_Build_Tree.h"

ValueTree Build_Tree::exposed_parameter(Identifier id, String name, Ctrl_Type ctrl,
										Knob_Display_Type display, uint8 cc_num, 
										uint16 choice_count, uint16 init_choice,
										int ctrl_center_x, int ctrl_center_y, int ctrl_w,
										int ctrl_h, String description, ValueTree bit_locations,
										ValueTree curt_choice_names, ValueTree choice_names)
{
	ValueTree tree_ep{ id,
		{
			{ ID::ep_p_name, name },
			{ ID::ep_p_ctrl_type, (int)ctrl },
			{ ID::ep_p_knob_display_type, (int)display },
			{ ID::ep_p_cc_num, cc_num },
			{ ID::ep_p_choice_count, choice_count },
			{ ID::ep_p_init_choice, init_choice },
			{ ID::ep_p_ctrl_center_x, ctrl_center_x },
			{ ID::ep_p_ctrl_center_y, ctrl_center_y },
			{ ID::ep_p_ctrl_width, ctrl_w },
			{ ID::ep_p_ctrl_height, ctrl_h },
			{ ID::ep_p_description, description },
		},
		{ bit_locations, curt_choice_names, choice_names }
	};
	return tree_ep;
}

ValueTree Build_Tree::choice_names_0_50_100(const bool curt) {
    ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
    tree.setProperty("choice_0","0%", nullptr);
    tree.setProperty("choice_1","50%", nullptr);
    tree.setProperty("choice_2","100%", nullptr);
    return tree;
}

ValueTree Build_Tree::choice_names_delay_routing(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "byp" : "bypass", nullptr);
	tree.setProperty("choice_1", curt ? "pre" : "pre-filter", nullptr);
	tree.setProperty("choice_2", curt ? "post" : "post-filter", nullptr);
	return tree;
}

ValueTree Build_Tree::choice_names_lfo_eg_mod(const bool curt) {
    ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
    tree.setProperty("choice_0", "Off", nullptr);
    tree.setProperty("choice_1", "Rate", nullptr);
    tree.setProperty("choice_2", "Intensity", nullptr);
    return tree;
}

ValueTree Build_Tree::choice_names_lfo_rate(const bool curt) {
    ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
    String name{ "" };
    for (int n = 0; n < 64; ++n) {
        name = curt ? (String)n + "|4(0)" : "unsynced: " + (String)n + " | synced: 4 beats";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    for (int n = 64; n < 128; ++n) {
        name = curt ? (String)n + "|2(1)" : "unsynced: " + (String)n + " | synced: 2 beats";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    for (int n = 128; n < 192; ++n) {
        name = curt ? (String)n + "|1(2)" : "unsynced: " + (String)n + " | synced: 1 beat";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    for (int n = 192; n < 256; ++n) {
        name = curt ? (String)n + "|3/4(3)" : "unsynced: " + (String)n + " | synced: 3/4 beat";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    for (int n = 256; n < 320; ++n) {
        name = curt ? (String)n + "|1/2(4)" : "unsynced: " + (String)n + " | synced: 1/2 beat";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    for (int n = 320; n < 384; ++n) {
        name = curt ? (String)n + "|3/8(5)" : "unsynced: " + (String)n + " | synced: 3/8 beat";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    for (int n = 384; n < 448; ++n) {
        name = curt ? (String)n + "|1/3(6)" : "unsynced: " + (String)n + " | synced: 1/3 beat";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    for (int n = 448; n < 512; ++n) {
        name = curt ? (String)n + "|1/4(7)" : "unsynced: " + (String)n + " | synced: 1/4 beat";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    for (int n = 512; n < 576; ++n) {
        name = curt ? (String)n + "|3/16(8)" : "unsynced: " + (String)n + " | synced: 3/16 beat";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    for (int n = 576; n < 640; ++n) {
        name = curt ? (String)n + "|1/6(9)" : "unsynced: " + (String)n + " | synced: 1/6 beat";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    for (int n = 640; n < 704; ++n) {
        name = curt ? (String)n + "|1/8(10)" : "unsynced: " + (String)n + " | synced: 1/8 beat";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    for (int n = 704; n < 768; ++n) {
        name = curt ? (String)n + "|1/12(11)" : "unsynced: " + (String)n + " | synced: 1/12 beat";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    for (int n = 768; n < 832; ++n) {
        name = curt ? (String)n + "|1/16(12)" : "unsynced: " + (String)n + " | synced: 1/16 beat";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    for (int n = 832; n < 896; ++n) {
        name = curt ? (String)n + "|1/24(13)" : "unsynced: " + (String)n + " | synced: 1/24 beat";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    for (int n = 896; n < 960; ++n) {
        name = curt ? (String)n + "|1/32(14)" : "unsynced: " + (String)n + " | synced: 1/32 beat";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    for (int n = 960; n < 1024; ++n) {
        name = curt ? (String)n + "|1/64(15)" : "unsynced: " + (String)n + " | synced: 1/64 beat";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    return tree;
}

ValueTree Build_Tree::choice_names_lfo_target(const bool curt) {
    ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
    tree.setProperty("choice_0", curt ? "LPF cutoff frequency" : "cut", nullptr);
    tree.setProperty("choice_1", curt ? "VCO 1 & 2 shape" : "shape", nullptr);
    tree.setProperty("choice_2", curt ? "VCO 1 & 2 pitch" : "pitch", nullptr);
    return tree;
}

ValueTree Build_Tree::choice_names_lpf_eg_int(const bool curt) {
    ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
    String name{ "" };
    name = "-100%";
    for (int n = 0; n < 12; ++n)
        tree.setProperty("choice_" + (String)n, name, nullptr);
    for (int n = 12; n < 492; ++n) {
        auto val{ roundToInt(floor(pow(492.0f - n, 2.0f) * 0.0004322268f)) };
        name = "-" + (String)val + "%";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    name = "0%";
    for (int n = 492; n < 533; ++n)
        tree.setProperty("choice_" + (String)n, name, nullptr);
    for (int n = 533; n < 1013; ++n) {
        auto val{ roundToInt(floor(pow(n - 532.0f, 2.0f) * 0.0004322268f)) };
        name = "+" + (String)val + "%";
        tree.setProperty("choice_" + (String)n, name, nullptr);
    }
    name = "+100%";
    for (int n = 1013; n < 1024; ++n)
        tree.setProperty("choice_" + (String)n, name, nullptr);
    return tree;
}

ValueTree Build_Tree::choice_names_lpf_type(const bool curt) {
    ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
    tree.setProperty("choice_0", "2-pole" + curt ? "" : " (12 dB / octave)", nullptr);
    tree.setProperty("choice_1", "4-pole" + curt ? "" : " (24 dB / octave)", nullptr);
    return tree;
}

ValueTree Build_Tree::choice_names_osc_2_pitch_eg_int(const bool curt) {
    ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
    String postfix{ curt ? "" : " cents" };

    auto val{ -4800 };
    for (int n = 0; n < 5; ++n)
        tree.setProperty("choice_" + (String)val , (String)val + postfix, nullptr);

    for (int n = 5; n < 357; ++n) {
        val += (n % 2 == 1 ? 13 : 12);
        tree.setProperty("choice_" + (String)n, (String)val + postfix, nullptr);
    }

    for (int n = 357; n < 477; ++n) {
        val += (n % 8 == 5 ? 4 : 3);
        tree.setProperty("choice_" + (String)n, (String)val + postfix, nullptr);
    }

    tree.setProperty("choice_477", "-23" + postfix, nullptr);
    tree.setProperty("choice_478", "-21" + postfix, nullptr);
    tree.setProperty("choice_479", "-20" + postfix, nullptr);
    tree.setProperty("choice_480", "-18" + postfix, nullptr);
    tree.setProperty("choice_481", "-17" + postfix, nullptr);
    tree.setProperty("choice_482", "-15" + postfix, nullptr);
    tree.setProperty("choice_483", "-14" + postfix, nullptr);
    tree.setProperty("choice_484", "-12" + postfix, nullptr);
    tree.setProperty("choice_485", "-10" + postfix, nullptr);
    tree.setProperty("choice_486", "-9" + postfix, nullptr);
    tree.setProperty("choice_487", "-7" + postfix, nullptr);
    tree.setProperty("choice_488", "-5" + postfix, nullptr);
    tree.setProperty("choice_489", "-4" + postfix, nullptr);
    tree.setProperty("choice_490", "-3" + postfix, nullptr);
    tree.setProperty("choice_491", "-1" + postfix, nullptr);

    for (int n = 492; n < 531; ++n)
        tree.setProperty("choice_" + (String)n, "0" + postfix, nullptr);

    tree.setProperty("choice_531", "+1" + postfix, nullptr);
    tree.setProperty("choice_532", "+2" + postfix, nullptr);
    tree.setProperty("choice_533", "+3" + postfix, nullptr);
    tree.setProperty("choice_534", "+4" + postfix, nullptr);
    tree.setProperty("choice_535", "+5" + postfix, nullptr);
    tree.setProperty("choice_536", "+7" + postfix, nullptr);
    tree.setProperty("choice_537", "+8" + postfix, nullptr);
    tree.setProperty("choice_538", "+10" + postfix, nullptr);
    tree.setProperty("choice_539", "+11" + postfix, nullptr);
    tree.setProperty("choice_540", "+13" + postfix, nullptr);
    tree.setProperty("choice_541", "+15" + postfix, nullptr);
    tree.setProperty("choice_542", "+16" + postfix, nullptr);
    tree.setProperty("choice_543", "+18" + postfix, nullptr);
    tree.setProperty("choice_544", "+19" + postfix, nullptr);
    tree.setProperty("choice_545", "+21" + postfix, nullptr);
    tree.setProperty("choice_546", "+22" + postfix, nullptr);
    tree.setProperty("choice_547", "+24" + postfix, nullptr);
    tree.setProperty("choice_548", "+25" + postfix, nullptr);

    val = 25;

    for (int n = 549; n < 669; ++n) {
        val += (n % 8 == 5 ? 4 : 3);
        tree.setProperty("choice_" + (String)n, "+" + (String)val + postfix, nullptr);
    }

    for (int n = 669; n < 1020; ++n) {
        val += (n % 2 == 1 ? 13 : 12);
        tree.setProperty("choice_" + (String)n, "+" + (String)val + postfix, nullptr);
    }

    for (int n = 1020; n < 1024; ++n)
        tree.setProperty("choice_" + (String)n, "+4800" + postfix, nullptr);

    return tree;
}

ValueTree Build_Tree::choice_names_osc_and_lfo_wave(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", curt ? "sqr" : "square", nullptr);
	tree.setProperty("choice_1", curt ? "tri" : "triangle", nullptr);
	tree.setProperty("choice_2", curt ? "saw" : "sawtooth", nullptr);
    return tree;
}

ValueTree Build_Tree::choice_names_osc_octave(const bool curt) {
	ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
	tree.setProperty("choice_0", "16'", nullptr);
	tree.setProperty("choice_1", "8'", nullptr);
	tree.setProperty("choice_2", "4'", nullptr);
	tree.setProperty("choice_4", "2'", nullptr);
    return tree;
}

ValueTree Build_Tree::choice_names_osc_pitch_fine(const bool curt) {
    ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
    String postfix{ curt ? "" : " cents" };

    auto val{ -1200 };
    for (int n = 0; n < 5; ++n)
        tree.setProperty("choice_" + (String)val, (String)val + postfix, nullptr);

    for (int n = 5; n < 357; ++n) {
        val += (n % 8 == 5 ? 4 : 3);
        tree.setProperty("choice_" + (String)n, (String)val + postfix, nullptr);
    }

    for (int n = 357; n < 477; ++n) {
        if (n % 32 != 0 && n % 32 != 4 && n % 32 != 9 && n % 32 != 14 &&
            n % 32 != 18 && n % 32 != 23 && n % 32 != 27)
        {
            ++val;
        }
        tree.setProperty("choice_" + (String)n, (String)val + postfix, nullptr);
    }

    tree.setProperty("choice_477", "-5" + postfix, nullptr);
    tree.setProperty("choice_478", "-5" + postfix, nullptr);
    tree.setProperty("choice_479", "-5" + postfix, nullptr);
    tree.setProperty("choice_480", "-4" + postfix, nullptr);
    tree.setProperty("choice_481", "-4" + postfix, nullptr);
    tree.setProperty("choice_482", "-3" + postfix, nullptr);
    tree.setProperty("choice_483", "-3" + postfix, nullptr);
    tree.setProperty("choice_484", "-3" + postfix, nullptr);
    tree.setProperty("choice_485", "-2" + postfix, nullptr);
    tree.setProperty("choice_486", "-2" + postfix, nullptr);
    tree.setProperty("choice_487", "-1" + postfix, nullptr);
    tree.setProperty("choice_488", "-1" + postfix, nullptr);
    tree.setProperty("choice_489", "-1" + postfix, nullptr);

    for (int n = 490; n < 533; ++n)
        tree.setProperty("choice_" + (String)n, "0" + postfix, nullptr);

    tree.setProperty("choice_533", "+1" + postfix, nullptr);
    tree.setProperty("choice_534", "+1" + postfix, nullptr);
    tree.setProperty("choice_535", "+2" + postfix, nullptr);
    tree.setProperty("choice_536", "+2" + postfix, nullptr);
    tree.setProperty("choice_537", "+2" + postfix, nullptr);
    tree.setProperty("choice_538", "+3" + postfix, nullptr);
    tree.setProperty("choice_539", "+3" + postfix, nullptr);
    tree.setProperty("choice_540", "+4" + postfix, nullptr);
    tree.setProperty("choice_541", "+4" + postfix, nullptr);
    tree.setProperty("choice_542", "+4" + postfix, nullptr);
    tree.setProperty("choice_543", "+5" + postfix, nullptr);
    tree.setProperty("choice_544", "+5" + postfix, nullptr);
    tree.setProperty("choice_545", "+6" + postfix, nullptr);
    tree.setProperty("choice_546", "+6" + postfix, nullptr);
    tree.setProperty("choice_547", "+6" + postfix, nullptr);
    tree.setProperty("choice_548", "+7" + postfix, nullptr);
    tree.setProperty("choice_549", "+8" + postfix, nullptr);
    tree.setProperty("choice_550", "+8" + postfix, nullptr);
    tree.setProperty("choice_551", "+9" + postfix, nullptr);

    val = 10;

    for (int n = 552; n < 669; ++n) {
        if (n % 32 != 1 && n % 32 != 5 && n % 32 != 10 && n % 32 != 15 &&
            n % 32 != 19 && n % 32 != 24 && n % 32 != 28)
        {
            ++val;
        }
        tree.setProperty("choice_" + (String)n, (String)val + postfix, nullptr);
    }

    for (int n = 669; n < 1020; ++n) {
        val += (n % 8 == 5 ? 4 : 3);
        tree.setProperty("choice_" + (String)n, "+" + (String)val + postfix, nullptr);
    }

    for (int n = 1020; n < 1024; ++n)
        tree.setProperty("choice_" + (String)n, "+1200" + postfix, nullptr);

    return tree;
}

ValueTree Build_Tree::choice_names_voice_mode_depth(const bool curt) {
    ValueTree tree{ curt ? ID::tree_param_choice_names_curt : ID::tree_param_choice_names };
    for (uint16 n = 0; n < EP::choice_count_unsigned_10_bit; ++n) {
        auto choiceName{ choice_name_voice_mode_1_poly(n, curt) };
        choiceName += choice_name_voice_mode_2_duo_3_unison(n, curt);
        choiceName += choice_name_voice_mode_4_mono(n, curt);
        choiceName += choice_name_voice_mode_5_chord(n, curt);
        choiceName += choice_name_voice_mode_6_delay(n, curt);
        choiceName += choice_name_voice_mode_7_arp(n, curt);
        choiceName += choice_name_voice_mode_8_sidechain(n, curt);
        tree.setProperty("choice_" + (String)n, choiceName, nullptr);
    }
    return tree;
}

String Build_Tree::choice_name_voice_mode_1_poly(const uint16 n, const bool curt) {
    String name{ curt ? "1:INV " : "1:inversion " };
    auto inv_num{ n / 114 };
    name += (String)inv_num;
    return name;
}

String Build_Tree::choice_name_voice_mode_2_duo_3_unison(const uint16 n, const bool curt) {
    String name{ curt ? "|2&3:" : "|2&3:detune " };
    auto detune_num{ n / 20 };
    if (detune_num > 50)
        detune_num = 50;
    name += (detune_num == 0 ? "" : "+") + (String)detune_num + (curt ? "C" : " cents");
    return name;
}

String Build_Tree::choice_name_voice_mode_4_mono(const uint16 n, const bool curt) {
    String name{ curt ? "|4:" : "|4:sub " };
    name += (String)n;
    return name;
}

String Build_Tree::choice_name_voice_mode_5_chord(const uint16 n, const bool curt) {
    String name{ "|5:" };
    auto chord_num{ n / 74 };
    switch (chord_num) {
    case 0: { name += curt ? "5th(0)" : "5th interval"; break; }
    case 1: { name += curt ? "sus2(1)" : "suspended 2nd chord"; break; }
    case 2: { name += curt ? "m(2)" : "minor chord"; break; }
    case 3: { name += curt ? "maj(3)" : "major chord"; break; }
    case 4: { name += curt ? "sus4(4)" : "suspended 4th chord"; break; }
    case 5: { name += curt ? "m7(5)" : "minor 7th chord"; break; }
    case 6: { name += curt ? "7th(6)" : "7th chord"; break; }
    case 7: { name += curt ? "7sus4(7)" : "7th/sus. 4th chord"; break; }
    case 8: { name += curt ? "maj7(8)" : "major 7th chord"; break; }
    case 9: { name += curt ? "aug(9)" : "augmented chord"; break; }
    case 10: { name += curt ? "dim(10)" : "diminished chord"; break; }
    case 11: { name += curt ? "m7b5(11)" : "minor 7th/flat 5th chord"; break; }
    case 12: { name += curt ? "mMaj7(12)" : "minor/major 7th chord"; break; }
    case 13: { name += curt ? "maj7b5(13)" : "major 7th/flat 5th chord"; break; }
    default: break;
    }
    return name;
}

String Build_Tree::choice_name_voice_mode_6_delay(const uint16 n, const bool curt) {
    String name{ "|6:" };
    if (n < 86) name += curt ? "1/192 beat delay" : "1/192(0)";
    if (n >= 86 && n < 171) name += curt ? "1/128(1)" : "1/128 beat delay";
    if (n >= 171 && n < 256) name += curt ? "1/64(2)" : "1/64 beat delay";
    if (n >= 256 && n < 342) name += curt ? "1/48(3)" : "1/48 beat delay";
    if (n >= 342 && n < 427) name += curt ? "1/32(4)" : "1/32 beat delay";
    if (n >= 427 && n < 512) name += curt ? "1/24(5)" : "1/24 beat delay";
    if (n >= 512 && n < 598) name += curt ? "1/16(6)" : "1/16 beat delay";
    if (n >= 598 && n < 683) name += curt ? "1/12(7)" : "1/12 beat delay";
    if (n >= 683 && n < 768) name += curt ? "1/8(8)" : "1/8 beat delay";
    if (n >= 768 && n < 854) name += curt ? "1/6(9)" : "1/6 beat delay";
    if (n >= 854 && n < 939) name += curt ? "3/16(10)" : "3/16 beat delay";
    if (n >= 939 && n < 1024) name += curt ? "1/4(11)" : "1/4 beat delay";
    return name;
}

String Build_Tree::choice_name_voice_mode_7_arp(const uint16 n, const bool curt) {
    String name{ "|7:" };
    if (n < 79) name += curt ? "man 1(0)" : "arpeggio: manual 1";
    if (n >= 79 && n < 158) name += curt ? "man 2(1)" : "arpeggio: manual 2";
    if (n >= 158 && n < 237) name += curt ? "rise1(2)" : "arpeggio: rise 1";
    if (n >= 237 && n < 316) name += curt ? "rise2(3)" : "arpeggio: rise 2";
    if (n >= 316 && n < 394) name += curt ? "fall 1(4)" : "arpeggio: fall 1";
    if (n >= 394 && n < 473) name += curt ? "fall 2(5)" : "arpeggio: fall 2";
    if (n >= 473 && n < 552) name += curt ? "R/F 1(6)" : "arpeggio: rise/fall 1";
    if (n >= 552 && n < 631) name += curt ? "R/F 2(7)" : "arpeggio: rise/fall 2";
    if (n >= 631 && n < 709) name += curt ? "poly1(8)" : "arpeggio: poly 1";
    if (n >= 709 && n < 788) name += curt ? "poly2(9)" : "arpeggio: poly 2";
    if (n >= 788 && n < 867) name += curt ? "rnd 1(10)" : "arpeggio: random 1";
    if (n >= 867 && n < 946) name += curt ? "rnd 2(11)" : "arpeggio: random 2";
    if (n >= 946 && n < 1024) name += curt ? "rnd 3(12)" : "arpeggio: random 3";
    return name;
}

String Build_Tree::choice_name_voice_mode_8_sidechain(const uint16 n, const bool curt) {
    String name{ curt ? "|8:" : "|8:sidechain " };
    name += (String)n;
    return name;
}
