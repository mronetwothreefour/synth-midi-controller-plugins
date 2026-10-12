#include "D_BUILD_Choices_For_P.h"

#include "D_CONVERT_P.h"

using namespace BUILD;

const StringArray Choices_For::avp_flex_sli_bend_limit(const bool pos) {
    StringArray list;
    String s{ pos ? "+" : "-" };
    for (int i = 0; i < 12; ++i) {
        s += String{ i + 1 };
        auto n = s + "__" + s + " semitone" + (i > 0 ? "s" : "");
        list.add(n);
    }
    return list;
}

const StringArray Choices_For::avp_flex_sli_range() {
    StringArray list;
    for (int i = -100; i < 101; ++i) {
        String n{ (i > 0 ? "+" : "") + String{ i + 1 } + "%" };
        list.add(n);
    }
    return list;
}

const StringArray Choices_For::avp_flex_sli_target() {
    return {
        "pitch bend",
        "gate time",
        "osc 1 pitch__oscillator 1 pitch",
        "osc 1 shape__oscillator 1 shape",
        "osc 2 pitch__oscillator 2 pitch",
        "osc 2 shape__oscillator 2 shape",
        "osc 2 x-mod depth__oscillator 2 cross-modulation depth",
        "osc 2 pitch EG int__oscillator 2 pitch EG intensity",
        "osc 1 level__oscillator 1 level",
        "osc 2 level__oscillator 2 level",
        "noise level",
        "lpf cutoff__lpf cutoff frequency",
        "lpf resonance",
        "LPF EG intensity",
        "VCA EG attack",
        "VCA EG decay",
        "VCA EG sustain",
        "VCA EG release",
        "EG attack",
        "EG decay",
        "EG sustain",
        "EG release",
        "LFO rate",
        "LFO intensity",
        "delay HPF cutoff__delay HPF cutoff frequency",
        "delay time",
        "delay feedback",
        "portamento time",
        "voice mode depth"
    };
}

const StringArray Choices_For::avp_microtune_scale() {
    return {
        "equal temp__equal temperament",
        "pure major",
        "pure minor",
        "pythagorean",
        "Werckmeister",
        "Kirnberger",
        "Slendro",
        "Pelog",
        "ionian",
        "dorian",
        "aeolian",
        "major penta__major pentatonic",
        "minor penta__minor pentatonic",
        "reverse",
        "AFX 1__Aphex Twin 1",
        "AFX 2__Aphex Twin 2",
        "AFX 3__Aphex Twin 3",
        "AFX 4__Aphex Twin 4",
        "AFX 5__Aphex Twin 5",
        "AFX 6__Aphex Twin 6",
        "DC 1__dorian concept 1",
        "DC 2__dorian concept 2",
        "DC 3__dorian concept 3",
        "user scale 1",
        "user scale 2",
        "user scale 3",
        "user scale 4",
        "user scale 5",
        "user scale 6",
        "user octave 1",
        "user octave 2",
        "user octave 3",
        "user octave 4",
        "user octave 5",
        "user octave 6"
    };
}

const StringArray Choices_For::avp_porta_mode_on() {
    return { "auto", "on" };
}

const StringArray Choices_For::avp_porta_time() {
    StringArray list;
    list.add("OFF__off");
    for (int i = 1; i < 128; ++i)
        list.add((String)i);
    return list;
}

const StringArray Choices_For::avp_scale_key() {
    StringArray list;
    for (int i = 0; i < 25; ++i)
        list.add(CONVERT::int_to_pitch(i));
    return list;
}

const StringArray Choices_For::avp_transpose() {
    StringArray list;
    for (auto i = -12; i < 12; ++i) {
        if (i >= -1 && i <= 1) {
            list.add(i == -1 ? "-1__-1 semitone" : i == 0 ? "0__no transpose" : "+1__+1 semitone");
            continue;
        }
        auto n = (i > 0 ? "+" : "") + (String)i;
        list.add(n + "__" + n + " semitones");
    }
    return list;
}

const StringArray Choices_For::avp_voice_mode() {
    return {
        "POLY",
        "DUO",
        "UNISON",
        "MONO",
        "CHORD",
        "DELAY",
        "ARP",
        "SIDECHAIN"
    };
}

const StringArray Choices_For::exp_delay_routing() {
	return { "bypass", "pre-filter", "post-filter" };
}

const StringArray Choices_For::exp_lfo_eg_mod() {
	return { "off", "rate", "intensity" };
}

const StringArray Choices_For::exp_lfo_rate() {
	StringArray list;
    String n{ "$|%__unsynced: $|synced: 1 cycle lasts # beat" };
    for (int i = 0; i < 1024; ++i) {
        n = n.replace("$", (String)i);
        if (i < 64)
            list.add(n.replace("%", "1:4(0)").replace("#", "4") + "s");
        if (i >= 64 && i < 128)
            list.add(n.replace("%", "1:2(1)").replace("#", "2") + "s");
        if (i >= 128 && i < 192)
            list.add(n.replace("%", "1:1(2)").replace("#", "1"));
        if (i >= 192 && i < 256)
            list.add(n.replace("%", "4:3(3)").replace("#", "3/4"));
        if (i >= 256 && i < 320)
            list.add(n.replace("%", "2:1(4)").replace("#", "1/2"));
        if (i >= 320 && i < 384)
            list.add(n.replace("%", "8:3(5)").replace("#", "3/8"));
        if (i >= 384 && i < 448)
            list.add(n.replace("%", "3:1(6)").replace("#", "1/3"));
        if (i >= 448 && i < 512)
            list.add(n.replace("%", "4:1(7)").replace("#", "1/4"));
        if (i >= 512 && i < 576)
            list.add(n.replace("%", "16:3(8)").replace("#", "3/16"));
        if (i >= 576 && i < 640)
            list.add(n.replace("%", "6:1(9)").replace("#", "1/6"));
        if (i >= 640 && i < 704)
            list.add(n.replace("%", "8:1(10)").replace("#", "1/8"));
        if (i >= 704 && i < 768)
            list.add(n.replace("%", "12:1(11)").replace("#", "1/12"));
        if (i >= 768 && i < 832)
            list.add(n.replace("%", "16:1(12)").replace("#", "1/16"));
        if (i >= 832 && i < 896)
            list.add(n.replace("%", "24:1(13)").replace("#", "1/24"));
        if (i >= 896 && i < 960)
            list.add(n.replace("%", "32:1(14)").replace("#", "1/32"));
        if (i >= 960 && i < 1024)
            list.add(n.replace("%", "64:1(15)").replace("#", "1/64"));
    }
    return list;
}

const StringArray Choices_For::exp_lfo_target() {
	return { "LPF cutoff frequency", "VCO 1 & 2 shape", "VCO 1 & 2 pitch" };
}

const StringArray Choices_For::exp_lpf_eg_int() {
	StringArray list;
    add_duplicate_strings_to_list("-100%", 14, list);
    auto v = -100;
    for (int c = 14; c < 49; c += 5) { // -99 to -86
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 2, list);
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 3, list);
    }
    for (int c = 49; c < 55; c += 3) { // -85 & -84
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 3, list);
    }
    for (int c = 55; c < 65; c += 5) { // -83 to -80
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 2, list);
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 3, list);
    }
    for (int c = 65; c < 87; c += 11) { // -79 to -72
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 3, list);
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 2, list);
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 3, list);
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 3, list);
    }
    for (int c = 87; c < 126; c += 3) { // -71 to -59
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 3, list);
    }
    v = -58;
    add_duplicate_strings_to_list((String)v + "%", 4, list); // c 126 to 129
    for (int c = 130; c < 142; c += 3) { // -57 to -54
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 3, list);
    }
    for (int c = 142; c < 163; c += 7) { // -53 to -48
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 4, list); // c 126 to 129
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 3, list);
    }
    for (int c = 163; c < 185; c += 11) { // -47 to -42
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 3, list);
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 4, list); // c 126 to 129
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 4, list); // c 126 to 129
    }
    for (int c = 185; c < 205; c += 4) { // -41 to -37
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 4, list);
    }
    v = -36;
    add_duplicate_strings_to_list((String)v + "%", 3, list); // c 205 to 207
    for (int c = 208; c < 220; c += 4) { // -35 to -33
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 4, list);
    }
    for (int c = 220; c < 248; c += 14) { // -32 to -27
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 5, list);
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 5, list);
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 4, list);
    }
    for (int c = 248; c < 278; c += 5) { // -26 to -21
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 5, list);
    }
    v = -20;
    add_duplicate_strings_to_list((String)v + "%", 6, list); // c 278 to 283
    v = -19;
    add_duplicate_strings_to_list((String)v + "%", 5, list); // c 284 to 288
    for (int c = 289; c < 313; c += 6) { // -18 to -15
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 6, list);
    }
    for (int c = 313; c < 341; c += 7) { // -14 to -11
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 7, list);
    }
    for (int c = 341; c < 357; c += 8) { // -10 & -9
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 8, list);
    }
    for (int c = 357; c < 375; c += 9) { // -8 & -7
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 9, list);
    }
    for (int c = 375; c < 397; c += 11) { // -6 & -5
        v += 1;
        add_duplicate_strings_to_list((String)v + "%", 11, list);
    }
    add_duplicate_strings_to_list("-4%", 12, list); // c 397 to 408
    add_duplicate_strings_to_list("-3%", 15, list); // c 409 to 423
    add_duplicate_strings_to_list("-2%", 21, list); // c 424 to 444
    add_duplicate_strings_to_list("-1%", 41, list); // c 445 to 485
    add_duplicate_strings_to_list("0%", 55, list); // c 486 to 540
    add_duplicate_strings_to_list("+1%", 40, list); // c 541 to 580
    add_duplicate_strings_to_list("+2%", 22, list); // c 581 to 602
    add_duplicate_strings_to_list("+3%", 14, list); // c 603 to 616
    add_duplicate_strings_to_list("+4%", 13, list); // c 617 to 629
    add_duplicate_strings_to_list("+5%", 11, list); // c 630 to 640
    v = 5;
    for (int c = 641; c < 661; c += 10) { // 6 & 7
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 10, list);
    }
    v = 8;
    add_duplicate_strings_to_list("+" + (String)v + "%", 9, list); // c 661 to 669
    for (int c = 670; c < 686; c += 8) { // 9 & 10
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 8, list);
    }
    for (int c = 686; c < 714; c += 7) { // 11 to 14
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 7, list);
    }
    for (int c = 714; c < 738; c += 6) { // 15 to 18
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 6, list);
    }
    v = 19;
    add_duplicate_strings_to_list("+" + (String)v + "%", 5, list); // c 738 to 742
    v = 20;
    add_duplicate_strings_to_list("+" + (String)v + "%", 6, list); // c 743 to 748
    for (int c = 749; c < 779; c += 5) { // 21 to 26
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 5, list);
    }
    v = 27;
    add_duplicate_strings_to_list("+" + (String)v + "%", 4, list); // c 779 to 782
    for (int c = 783; c < 793; c += 5) { // 28 & 29
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 5, list);
    }
    for (int c = 793; c < 801; c += 4) { // 30 & 31
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 4, list);
    }
    v = 32;
    add_duplicate_strings_to_list("+" + (String)v + "%", 5, list); // c 801 to 805
    for (int c = 806; c < 842; c += 4) { // 33 to 41
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 4, list);
    }
    v = 42;
    add_duplicate_strings_to_list("+" + (String)v + "%", 3, list); // c 842 to 844
    for (int c = 845; c < 853; c += 4) { // 43 & 44
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 4, list);
    }
    for (int c = 853; c < 859; c += 3) { // 45 & 46
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 3, list);
    }
    for (int c = 859; c < 867; c += 4) { // 47 & 48
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 4, list);
    }
    v = 49;
    add_duplicate_strings_to_list("+" + (String)v + "%", 3, list); // c 867 to 869
    for (int c = 870; c < 890; c += 10) { // 50 to 55
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 4, list);
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 3, list);
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 3, list);
    }
    v = 56;
    add_duplicate_strings_to_list("+" + (String)v + "%", 3, list); // c 890 to 892
    v = 57;
    add_duplicate_strings_to_list("+" + (String)v + "%", 4, list); // c 893 to 896
    for (int c = 897; c < 945; c += 3) { // 58 to 73
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 3, list);
    }
    for (int c = 945; c < 961; c += 8) { // 74 to 79
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 2, list);
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 3, list);
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 3, list);
    }
    for (int c = 961; c < 985; c += 8) { // 80 to 88
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 3, list);
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 2, list);
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 3, list);
    }
    for (int c = 985; c < 1010; c += 5) { // 89 to 98
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 2, list);
        v += 1;
        add_duplicate_strings_to_list("+" + (String)v + "%", 3, list);
    }
    add_duplicate_strings_to_list("+99% ", 2, list); // c 1010 & 1011
    add_duplicate_strings_to_list("+100% ", 12, list); // c 1012 & 1023
    return list;
}

const StringArray Choices_For::exp_lpf_type() {
	return { "2-pole (12 dB / octave)", "4-pole (24 dB / octave)" };
}

const StringArray Choices_For::exp_osc_2_pitch_eg_int() {
	StringArray list;
    String n{ "$__$ cents" };
    add_duplicate_strings_to_list(n.replace("$", "-4800"), 5, list); // 0 to 4
    auto c = -4800;
    for (int i = 5; i < 357; ++i) {
        c += 12 + (i % 2);
        list.add(n.replace("$", (String)c));
    }
    for (int i = 357; i < 477; ++i) {
        c += (i % 8 == 5 ? 4 : 3);
        list.add(n.replace("$", (String)c));
    }
    list.add(n.replace("$", "-23")); // 477
    list.add(n.replace("$", "-21")); // 478
    list.add(n.replace("$", "-20")); // 479
    list.add(n.replace("$", "-18")); // 480
    list.add(n.replace("$", "-17")); // 481
    list.add(n.replace("$", "-15")); // 482
    list.add(n.replace("$", "-14")); // 483
    list.add(n.replace("$", "-12")); // 484
    list.add(n.replace("$", "-10")); // 485
    list.add(n.replace("$", "-9"));  // 486
    list.add(n.replace("$", "-7"));  // 487
    list.add(n.replace("$", "-5"));  // 488
    list.add(n.replace("$", "-4"));  // 489
    list.add(n.replace("$", "-3"));  // 490
    list.add(n.replace("$", "-1"));  // 491
    add_duplicate_strings_to_list(n.replace("$", "0"), 39, list); // 492 to 530
    list.add(n.replace("$", "+1"));  // 531
    list.add(n.replace("$", "+2"));  // 532
    list.add(n.replace("$", "+3"));  // 533
    list.add(n.replace("$", "+4"));  // 534
    list.add(n.replace("$", "+5"));  // 535
    list.add(n.replace("$", "+7"));  // 536
    list.add(n.replace("$", "+8"));  // 537
    list.add(n.replace("$", "+10")); // 538
    list.add(n.replace("$", "+11")); // 539
    list.add(n.replace("$", "+13")); // 540
    list.add(n.replace("$", "+15")); // 541
    list.add(n.replace("$", "+16")); // 542
    list.add(n.replace("$", "+18")); // 543
    list.add(n.replace("$", "+19")); // 544
    list.add(n.replace("$", "+21")); // 545
    list.add(n.replace("$", "+22")); // 546
    list.add(n.replace("$", "+24")); // 547
    list.add(n.replace("$", "+25")); // 548
    c = 25;
    n = n.replace("$", "+$");
    for (int i = 549; i < 669; ++i) {
        c += (i % 8 == 5 ? 4 : 3);
        list.add(n.replace("$", (String)c));
    }
    for (int i = 669; i < 1020; ++i) {
        c += 12 + (i % 2);
        list.add(n.replace("$", (String)c));
    }
    add_duplicate_strings_to_list(n.replace("$", "4800"), 4, list); // 1020 to 1023
    return list;
}

const StringArray Choices_For::exp_osc_and_lfo_wave() {
	return { "square", "triangle", "sawtooth" };
}

const StringArray Choices_For::exp_osc_octave() {
	return { "16'", "8'", "4'", "2'" };
}

const StringArray Choices_For::exp_osc_pitch_fine() {
	StringArray list;
    String n{ "$__$ cents" };
    add_duplicate_strings_to_list(n.replace("$", "-1200"), 5, list); // 0 to 4
    auto c = -1200;
    for (int i = 5; i < 357; ++i) {
        c += (i % 8 == 5 ? 4 : 3);
        list.add(n.replace("$", (String)c));
    }
    for (int i = 357; i < 477; ++i) {
        auto j = i % 32;
        if (j != 0 && j != 4 && j != 9 && j != 14 && j != 18 && j != 23 && j != 27)
            ++c;
        list.add(n.replace("$", (String)c));
    }
    list.add(n.replace("$", "-5")); // 477
    list.add(n.replace("$", "-5")); // 478
    list.add(n.replace("$", "-5")); // 479
    list.add(n.replace("$", "-4")); // 480
    list.add(n.replace("$", "-4")); // 481
    list.add(n.replace("$", "-3")); // 482
    list.add(n.replace("$", "-3")); // 483
    list.add(n.replace("$", "-3")); // 484
    list.add(n.replace("$", "-2")); // 485
    list.add(n.replace("$", "-2")); // 486
    list.add(n.replace("$", "-1")); // 487
    list.add(n.replace("$", "-1")); // 488
    list.add(n.replace("$", "-1")); // 489
    add_duplicate_strings_to_list(n.replace("$", "0"), 43, list); // 490 to 532
    n = n.replace("$", "+$");
    list.add(n.replace("$", "1")); // 533
    list.add(n.replace("$", "1")); // 534
    list.add(n.replace("$", "2")); // 535
    list.add(n.replace("$", "2")); // 536
    list.add(n.replace("$", "2")); // 537
    list.add(n.replace("$", "3")); // 538
    list.add(n.replace("$", "3")); // 539
    list.add(n.replace("$", "4")); // 540
    list.add(n.replace("$", "4")); // 541
    list.add(n.replace("$", "4")); // 542
    list.add(n.replace("$", "5")); // 543
    list.add(n.replace("$", "5")); // 544
    list.add(n.replace("$", "6")); // 545
    list.add(n.replace("$", "6")); // 546
    list.add(n.replace("$", "6")); // 547
    list.add(n.replace("$", "7")); // 548
    list.add(n.replace("$", "8")); // 549
    list.add(n.replace("$", "8")); // 550
    list.add(n.replace("$", "9")); // 551
    list.add(n.replace("$", "10")); // 552
    c = 10;
    for (int i = 553; i < 669; ++i) {
        auto j = i % 32;
        if (j != 1 && j != 6 && j != 10 && j != 15 && j != 19 && j != 24 && j != 28)
            ++c;
        list.add(n.replace("$", (String)c));
    }
    for (int i = 669; i < 1020; ++i) {
        c += (i % 8 == 5 ? 4 : 3);
        list.add(n.replace("$", (String)c));
    }
    add_duplicate_strings_to_list(n.replace("$", "1200"), 4, list); // 1020 to 1023
    return list;
}

const StringArray Choices_For::exp_voice_mode_depth() {
	StringArray list;
    for (int i = 0; i < 1024; ++i) {
        auto n_curt{ exp_choice_voice_mode_0_poly(i, true) };
        auto n{ exp_choice_voice_mode_0_poly(i) };
        n_curt += exp_choice_voice_mode_1_duo_2_unison(i, true);
        n += exp_choice_voice_mode_1_duo_2_unison(i);
        n_curt += exp_choice_voice_mode_3_mono(i, true);
        n += exp_choice_voice_mode_3_mono(i);
        n_curt += exp_choice_voice_mode_4_chord(i, true);
        n += exp_choice_voice_mode_4_chord(i);
        n_curt += exp_choice_voice_mode_5_delay(i, true);
        n += exp_choice_voice_mode_5_delay(i);
        n_curt += exp_choice_voice_mode_6_arp(i, true);
        n += exp_choice_voice_mode_6_arp(i);
        n_curt += exp_choice_voice_mode_7_sidechain(i, true);
        n += exp_choice_voice_mode_7_sidechain(i);
        list.add(n_curt + "__" + n);
    }
    return list;
}

const StringArray Choices_For::exp_zero_50_100() {
	return { "0%", "50%", "100%" };
}

String Choices_For::exp_choice_voice_mode_0_poly(const int c, const bool curt) {
    String n{ curt ? "0:INV " : "1:inversion " };
    n += String{ c / 114 };
    return n;
}

String Choices_For::exp_choice_voice_mode_1_duo_2_unison(const int c, const bool curt) {
    String n{ curt ? "|1&2:" : "|2&3:detune " };
    auto detune{ std::clamp(c / 20, 0, 50) };
    n += (detune == 0 ? "" : "+") + (String)detune + (curt ? "C" : " cents");
    return n;
}

String Choices_For::exp_choice_voice_mode_3_mono(const int c, const bool curt) {
    String n{ curt ? "|3:" : "|4:sub " };
    n += (String)c;
    return n;
}

String Choices_For::exp_choice_voice_mode_4_chord(const int c, const bool curt) {
    String n{ "|" };
    if (c < 74) n += curt ? "4:5th(0)" : "5:5th interval";
    if (c >= 74 && c < 147) n += curt ? "4:sus2(1)" : "5:suspended 2nd chord";
    if (c >= 147 && c < 220) n += curt ? "4:m(2)" : "5:minor chord";
    if (c >= 220 && c < 293) n += curt ? "4:Maj(3)" : "5:major chord";
    if (c >= 293 && c < 366) n += curt ? "4:sus4(4)" : "5:suspended 4th chord";
    if (c >= 366 && c < 439) n += curt ? "4:m7(5)" : "5:minor 7th chord";
    if (c >= 439 && c < 512) n += curt ? "4:7th(6)" : "5:7th chord";
    if (c >= 512 && c < 586) n += curt ? "4:7sus4(7)" : "5:7th/sus. 4th chord";
    if (c >= 586 && c < 659) n += curt ? "4:Maj7(8)" : "5:major 7th chord";
    if (c >= 659 && c < 732) n += curt ? "4:aug(9)" : "5:augmented chord";
    if (c >= 732 && c < 805) n += curt ? "4:dim(10)" : "5:diminished chord";
    if (c >= 805 && c < 878) n += curt ? "4:m7b5(11)" : "5:minor 7th/flat 5th chord";
    if (c >= 878 && c < 951) n += curt ? "4:mM7(12)" : "5:minor/major 7th chord";
    if (c >= 951 && c < 1024) n += curt ? "4:M7b5(13)" : "5:major 7th/flat 5th chord";
    return n;
}

String Choices_For::exp_choice_voice_mode_5_delay(const int c, const bool curt) {
    String n{ "|" };
    if (c < 86) n += curt ? "5:1/192(0)" : "6:1/192 beat delay";
    if (c >= 86 && c < 171) n += curt ? "5:1/128(1)" : "6:1/128 beat delay";
    if (c >= 171 && c < 256) n += curt ? "5:1/64(2)" : "6:1/64 beat delay";
    if (c >= 256 && c < 342) n += curt ? "5:1/48(3)" : "6:1/48 beat delay";
    if (c >= 342 && c < 427) n += curt ? "5:1/32(4)" : "6:1/32 beat delay";
    if (c >= 427 && c < 512) n += curt ? "5:1/24(5)" : "6:1/24 beat delay";
    if (c >= 512 && c < 598) n += curt ? "5:1/16(6)" : "6:1/16 beat delay";
    if (c >= 598 && c < 683) n += curt ? "5:1/12(7)" : "6:1/12 beat delay";
    if (c >= 683 && c < 768) n += curt ? "5:1/8(8)" : "6:1/8 beat delay";
    if (c >= 768 && c < 854) n += curt ? "5:1/6(9)" : "6:1/6 beat delay";
    if (c >= 854 && c < 939) n += curt ? "5:3/16(10)" : "6:3/16 beat delay";
    if (c >= 939 && c < 1024) n += curt ? "5:1/4(11)" : "6:1/4 beat delay";
    return n;
}

String Choices_For::exp_choice_voice_mode_6_arp(const int c, const bool curt) {
    String n{ "|" };
    if (c < 79) n += curt ? "6:man 1(0)" : "7:arpeggio: manual 1";
    if (c >= 79 && c < 158) n += curt ? "6:man 2(1)" : "7:arpeggio: manual 2";
    if (c >= 158 && c < 237) n += curt ? "6:rise1(2)" : "7:arpeggio: rise 1";
    if (c >= 237 && c < 316) n += curt ? "6:rise2(3)" : "7:arpeggio: rise 2";
    if (c >= 316 && c < 394) n += curt ? "6:fall 1(4)" : "7:arpeggio: fall 1";
    if (c >= 394 && c < 473) n += curt ? "6:fall 2(5)" : "7:arpeggio: fall 2";
    if (c >= 473 && c < 552) n += curt ? "6:r/f 1(6)" : "7:arpeggio: rise/fall 1";
    if (c >= 552 && c < 631) n += curt ? "6:r/f 2(7)" : "7:arpeggio: rise/fall 2";
    if (c >= 631 && c < 709) n += curt ? "6:poly1(8)" : "7:arpeggio: poly 1";
    if (c >= 709 && c < 788) n += curt ? "6:poly2(9)" : "7:arpeggio: poly 2";
    if (c >= 788 && c < 867) n += curt ? "6:rnd 1(10)" : "7:arpeggio: random 1";
    if (c >= 867 && c < 946) n += curt ? "6:rnd 2(11)" : "7:arpeggio: random 2";
    if (c >= 946 && c < 1024) n += curt ? "6:rnd 3(12)" : "7:arpeggio: random 3";
    return n;
}

String Choices_For::exp_choice_voice_mode_7_sidechain(const int c, const bool curt) {
    String name{ curt ? "|7:" : "|8:sidechain " };
    name += (String)c;
    return name;
}
