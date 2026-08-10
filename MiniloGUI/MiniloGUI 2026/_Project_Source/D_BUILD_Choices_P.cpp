#include "D_BUILD_Choices_P.h"

const StringArray Build_Choices::delay_routing() {
	return { "bypass", "pre-filter", "post-filter" };
}

const StringArray Build_Choices::lfo_eg_mod() {
	return { "off", "rate", "intensity" };
}

const StringArray Build_Choices::lfo_rate() {
	StringArray list;
    String n{ "$|%__unsynced: $|\nsynced: 1 cycle lasts & beat" };
    for (int i = 0; i < 1024; ++i) {
        n.replace("$", (String)i);
        if (i < 64)
            list.add(n.replace("%", "1:4(0)").replace("&", "4") + "s");
        if (i >= 64 && i < 128)
            list.add(n.replace("%", "1:2(1)").replace("&", "2") + "s");
        if (i >= 128 && i < 192)
            list.add(n.replace("%", "1:1(2)").replace("&", "1"));
        if (i >= 192 && i < 256)
            list.add(n.replace("%", "4:3(3)").replace("&", "3/4"));
        if (i >= 256 && i < 320)
            list.add(n.replace("%", "2:1(4)").replace("&", "1/2"));
        if (i >= 320 && i < 384)
            list.add(n.replace("%", "8:3(5)").replace("&", "3/8"));
        if (i >= 384 && i < 448)
            list.add(n.replace("%", "3:1(6)").replace("&", "1/3"));
        if (i >= 448 && i < 512)
            list.add(n.replace("%", "4:1(7)").replace("&", "1/4"));
        if (i >= 512 && i < 576)
            list.add(n.replace("%", "16:3(8)").replace("&", "3/16"));
        if (i >= 576 && i < 640)
            list.add(n.replace("%", "6:1(9)").replace("&", "1/6"));
        if (i >= 640 && i < 704)
            list.add(n.replace("%", "8:1(10)").replace("&", "1/8"));
        if (i >= 704 && i < 768)
            list.add(n.replace("%", "12:1(11)").replace("&", "1/12"));
        if (i >= 768 && i < 832)
            list.add(n.replace("%", "16:1(12)").replace("&", "1/16"));
        if (i >= 832 && i < 896)
            list.add(n.replace("%", "24:1(13)").replace("&", "1/24"));
        if (i >= 896 && i < 960)
            list.add(n.replace("%", "32:1(14)").replace("&", "1/32"));
        if (i >= 960 && i < 1024)
            list.add(n.replace("%", "64:1(15)").replace("&", "1/64"));
    }
    return list;
}

const StringArray Build_Choices::lfo_target() {
	return { "LPF cutoff frequency", "VCO 1 & 2 shape", "VCO 1 & 2 pitch" };
}

const StringArray Build_Choices::lpf_eg_int() {
	StringArray list;
    String n{ "_%" };
    for (int i = 0; i < 1024; ++i) {
        if (i < 12)
            list.add(n.replace("_","-100"));
        if (i >= 12 && i < 492) {
            auto v{ roundToInt(floor(pow(492.0f - i, 2.0f) * 0.0004322268f)) };
            list.add(n.replace("_", "-" + (String)v));
        }
        if (i >= 492 && i < 533)
            list.add(n.replace("_","0"));
        if (i >= 533 && i < 1013) {
            auto v{ roundToInt(floor(pow(i - 532.0f, 2.0f) * 0.0004322268f)) };
            list.add(n.replace("_", "-" + (String)v));
        }
        if (i >= 1013)
            list.add(n.replace("_","+100"));
    }
	return list;
}

const StringArray Build_Choices::lpf_type() {
	return { "2-pole (12 dB / octave)", "4-pole (24 dB / octave)" };
}

const StringArray Build_Choices::osc_2_pitch_eg_int() {
	StringArray list;
    String n{ "$__$ cents" };
    for (int i = 0; i < 5; ++i)
        list.add(n.replace("$", "-4800"));
    auto c = -4800;
    for (int i = 0; i < 357; ++i) {
        c += (i % 2 == 1 ? 13 : 12);
        list.add(n.replace("$", (String)c));
    }
    for (int i = 357; i < 477; ++i) {
        c += (i % 8 == 5 ? 4 : 3);
        list.add(n.replace("$", (String)c));
    }
    list.add(n.replace("$", "-23"));
    list.add(n.replace("$", "-21"));
    list.add(n.replace("$", "-20"));
    list.add(n.replace("$", "-18"));
    list.add(n.replace("$", "-17"));
    list.add(n.replace("$", "-15"));
    list.add(n.replace("$", "-14"));
    list.add(n.replace("$", "-12"));
    list.add(n.replace("$", "-10"));
    list.add(n.replace("$", "-9"));
    list.add(n.replace("$", "-7"));
    list.add(n.replace("$", "-5"));
    list.add(n.replace("$", "-4"));
    list.add(n.replace("$", "-3"));
    list.add(n.replace("$", "-1"));
    for (int i = 492; i < 531; ++i)
        list.add(n.replace("$", "0"));
    list.add(n.replace("$", "+1"));
    list.add(n.replace("$", "+2"));
    list.add(n.replace("$", "+3"));
    list.add(n.replace("$", "+4"));
    list.add(n.replace("$", "+5"));
    list.add(n.replace("$", "+7"));
    list.add(n.replace("$", "+8"));
    list.add(n.replace("$", "+10"));
    list.add(n.replace("$", "+11"));
    list.add(n.replace("$", "+13"));
    list.add(n.replace("$", "+15"));
    list.add(n.replace("$", "+16"));
    list.add(n.replace("$", "+18"));
    list.add(n.replace("$", "+19"));
    list.add(n.replace("$", "+21"));
    list.add(n.replace("$", "+22"));
    list.add(n.replace("$", "+24"));
    list.add(n.replace("$", "+25"));
    c = 25;
    n = n.replace("$", "+$");
    for (int i = 549; i < 669; ++i) {
        c += (i % 8 == 5 ? 4 : 3);
        list.add(n.replace("$", (String)c));
    }
    for (int i = 669; i < 1020; ++i) {
        c += (i % 2 == 1 ? 13 : 12);
        list.add(n.replace("$", (String)c));
    }
    for (int i = 1020; i < 1024; ++i)
        list.add(n.replace("$", "+4800"));
    return list;
}

const StringArray Build_Choices::osc_and_lfo_wave() {
	return { "square", "triangle", "sawtooth" };
}

const StringArray Build_Choices::osc_octave() {
	return { "16'", "8'", "4'", "2'" };
}

const StringArray Build_Choices::osc_pitch_fine() {
	StringArray list;
    String n{ "$__$ cents" };
    for (int i = 0; i < 5; ++i)
        list.add(n.replace("$", "-1200"));
    auto c = -1200;
    for (int i = 0; i < 357; ++i) {
        c += (i % 8 == 5 ? 4 : 3);
        list.add(n.replace("$", (String)c));
    }
    for (int i = 357; i < 477; ++i) {
        if (i % 32 != 0 && i % 32 != 4 && i % 32 != 9 && i % 32 != 14 &&
            i % 32 != 18 && i % 32 != 23 && i % 32 != 27)
        {
            ++c;
        }
        list.add(n.replace("$", (String)c));
    }
    list.add(n.replace("$", "-5"));
    list.add(n.replace("$", "-5"));
    list.add(n.replace("$", "-5"));
    list.add(n.replace("$", "-4"));
    list.add(n.replace("$", "-4"));
    list.add(n.replace("$", "-3"));
    list.add(n.replace("$", "-3"));
    list.add(n.replace("$", "-3"));
    list.add(n.replace("$", "-2"));
    list.add(n.replace("$", "-2"));
    list.add(n.replace("$", "-1"));
    list.add(n.replace("$", "-1"));
    list.add(n.replace("$", "-1"));
    for (int i = 490; i < 533; ++i)
        list.add(n.replace("$", "0"));
    n = n.replace("$", "+$");
    list.add(n.replace("$", "1"));
    list.add(n.replace("$", "1"));
    list.add(n.replace("$", "2"));
    list.add(n.replace("$", "2"));
    list.add(n.replace("$", "2"));
    list.add(n.replace("$", "3"));
    list.add(n.replace("$", "3"));
    list.add(n.replace("$", "4"));
    list.add(n.replace("$", "4"));
    list.add(n.replace("$", "4"));
    list.add(n.replace("$", "5"));
    list.add(n.replace("$", "5"));
    list.add(n.replace("$", "6"));
    list.add(n.replace("$", "6"));
    list.add(n.replace("$", "6"));
    list.add(n.replace("$", "7"));
    list.add(n.replace("$", "8"));
    list.add(n.replace("$", "8"));
    list.add(n.replace("$", "9"));
    list.add(n.replace("$", "10"));
    c = 10;
    for (int i = 553; i < 669; ++i) {
        if (i % 32 != 1 && i % 32 != 5 && i % 32 != 10 && i % 32 != 15 &&
            i % 32 != 19 && i % 32 != 24 && i % 32 != 28)
        {
            ++c;
        }
        list.add(n.replace("$", (String)c));
    }
    for (int i = 669; i < 1020; ++i) {
        c += (i % 8 == 5 ? 4 : 3);
        list.add(n.replace("$", (String)c));
    }
    for (int i = 1020; i < 1024; ++i)
        list.add(n.replace("$", "+1200"));
    return list;
}

const StringArray Build_Choices::voice_mode_depth() {
	StringArray list;
    for (int i = 0; i < 1024; ++i) {
        auto n_curt{ choice_voice_mode_1_poly(i, true) };
        auto n{ choice_voice_mode_1_poly(i) };
        n_curt += choice_voice_mode_2_duo_3_unison(i, true);
        n += choice_voice_mode_2_duo_3_unison(i);
        n_curt += choice_voice_mode_4_mono(i, true);
        n += choice_voice_mode_4_mono(i);
        n_curt += choice_voice_mode_5_chord(i, true);
        n += choice_voice_mode_5_chord(i);
        n_curt += choice_voice_mode_6_delay(i, true);
        n += choice_voice_mode_6_delay(i);
        n_curt += choice_voice_mode_7_arp(i, true);
        n += choice_voice_mode_7_arp(i);
        n_curt += choice_voice_mode_8_sidechain(i, true);
        n += choice_voice_mode_8_sidechain(i);
        list.add(n_curt + "__" + n);
    }
    return list;
}

const StringArray Build_Choices::zero_50_100() {
	return { "0%", "50%", "100%" };
}

String Build_Choices::choice_voice_mode_1_poly(const int c, const bool curt) {
    String n{ curt ? "1:INV " : "1:inversion " };
    n += String{ c / 114 };
    return n;
}

String Build_Choices::choice_voice_mode_2_duo_3_unison(const int c, const bool curt) {
    String n{ curt ? "|2&3:" : "|2&3:detune " };
    auto detune{ std::clamp(c / 20, 0, 50) };
    n += (detune == 0 ? "" : "+") + (String)detune + (curt ? "C" : " cents");
    return n;
}

String Build_Choices::choice_voice_mode_4_mono(const int c, const bool curt) {
    String n{ curt ? "|4:" : "|4:sub " };
    n += (String)c;
    return n;
}

String Build_Choices::choice_voice_mode_5_chord(const int c, const bool curt) {
    String n{ "|5:" };
    if (c < 74) n += curt ? "5th(0)" : "5th interval";
    if (c >= 74 && c < 147) n += curt ? "sus2(1)" : "suspended 2nd chord";
    if (c >= 147 && c < 220) n += curt ? "m(2)" : "minor chord";
    if (c >= 220 && c < 293) n += curt ? "Maj(3)" : "major chord";
    if (c >= 293 && c < 366) n += curt ? "sus4(4)" : "suspended 4th chord";
    if (c >= 366 && c < 439) n += curt ? "m7(5)" : "minor 7th chord";
    if (c >= 439 && c < 512) n += curt ? "7th(6)" : "7th chord";
    if (c >= 512 && c < 586) n += curt ? "7sus4(7)" : "7th/sus. 4th chord";
    if (c >= 586 && c < 659) n += curt ? "Maj7(8)" : "major 7th chord";
    if (c >= 659 && c < 732) n += curt ? "aug(9)" : "augmented chord";
    if (c >= 732 && c < 805) n += curt ? "dim(10)" : "diminished chord";
    if (c >= 805 && c < 878) n += curt ? "m7b5(11)" : "minor 7th/flat 5th chord";
    if (c >= 878 && c < 951) n += curt ? "mM7(12)" : "minor/major 7th chord";
    if (c >= 951 && c < 1024) n += curt ? "M7b5(13)" : "major 7th/flat 5th chord";
    return n;
}

String Build_Choices::choice_voice_mode_6_delay(const int c, const bool curt) {
    String n{ "|6:" };
    if (c < 86) n += curt ? "1/192(0)" : "1/192 beat delay";
    if (c >= 86 && c < 171) n += curt ? "1/128(1)" : "1/128 beat delay";
    if (c >= 171 && c < 256) n += curt ? "1/64(2)" : "1/64 beat delay";
    if (c >= 256 && c < 342) n += curt ? "1/48(3)" : "1/48 beat delay";
    if (c >= 342 && c < 427) n += curt ? "1/32(4)" : "1/32 beat delay";
    if (c >= 427 && c < 512) n += curt ? "1/24(5)" : "1/24 beat delay";
    if (c >= 512 && c < 598) n += curt ? "1/16(6)" : "1/16 beat delay";
    if (c >= 598 && c < 683) n += curt ? "1/12(7)" : "1/12 beat delay";
    if (c >= 683 && c < 768) n += curt ? "1/8(8)" : "1/8 beat delay";
    if (c >= 768 && c < 854) n += curt ? "1/6(9)" : "1/6 beat delay";
    if (c >= 854 && c < 939) n += curt ? "3/16(10)" : "3/16 beat delay";
    if (c >= 939 && c < 1024) n += curt ? "1/4(11)" : "1/4 beat delay";
    return n;
}

String Build_Choices::choice_voice_mode_7_arp(const int c, const bool curt) {
    String n{ "|7:" };
    if (c < 79) n += curt ? "man 1(0)" : "arpeggio: manual 1";
    if (c >= 79 && c < 158) n += curt ? "man 2(1)" : "arpeggio: manual 2";
    if (c >= 158 && c < 237) n += curt ? "rise1(2)" : "arpeggio: rise 1";
    if (c >= 237 && c < 316) n += curt ? "rise2(3)" : "arpeggio: rise 2";
    if (c >= 316 && c < 394) n += curt ? "fall 1(4)" : "arpeggio: fall 1";
    if (c >= 394 && c < 473) n += curt ? "fall 2(5)" : "arpeggio: fall 2";
    if (c >= 473 && c < 552) n += curt ? "r/f 1(6)" : "arpeggio: rise/fall 1";
    if (c >= 552 && c < 631) n += curt ? "r/f 2(7)" : "arpeggio: rise/fall 2";
    if (c >= 631 && c < 709) n += curt ? "poly1(8)" : "arpeggio: poly 1";
    if (c >= 709 && c < 788) n += curt ? "poly2(9)" : "arpeggio: poly 2";
    if (c >= 788 && c < 867) n += curt ? "rnd 1(10)" : "arpeggio: random 1";
    if (c >= 867 && c < 946) n += curt ? "rnd 2(11)" : "arpeggio: random 2";
    if (c >= 946 && c < 1024) n += curt ? "rnd 3(12)" : "arpeggio: random 3";
    return n;
}

String Build_Choices::choice_voice_mode_8_sidechain(const int c, const bool curt) {
    String name{ curt ? "|8:" : "|8:sidechain " };
    name += (String)c;
    return name;
}

