#include "D_BUILD_Choices_For_P.h"

#include "D_CONVERT_P.h"
#include "C_MISC_P.h"

using namespace BUILD;
using namespace MISC;

const StringArray Choices_For::exp_arp_mode() {
    StringArray list;
    list.add("1 octave up");
    list.add("1 octave down");
    list.add("1 octave up & down");
    list.add("1 octave assign");
    list.add("1 octave random");
    list.add("2 octaves up");
    list.add("2 octaves down");
    list.add("2 octaves up & down");
    list.add("2 octaves assign");
    list.add("2 octaves random");
    list.add("3 octaves up");
    list.add("3 octaves down");
    list.add("3 octaves up & down");
    list.add("3 octaves assign");
    list.add("3 octaves random");
    return list;
}

const StringArray Choices_For::exp_bend_range() {
    StringArray list;
    list.add("0__no bend");
    list.add("+/-1__+ / -1 semitone");
    list.add("+/-2__+ / -2 semitones");
    list.add("+/-3__+ / -3 semitones");
    list.add("+/-4__+ / -4 semitones");
    list.add("+/-5__+ / -5 semitones");
    list.add("+/-6__+ / -6 semitones");
    list.add("+/-7__+ / -7 semitones");
    list.add("+/-8__+ / -8 semitones");
    list.add("+/-9__+ / -9 semitones");
    list.add("+/-10__+ / -10 semitones");
    list.add("+/-11__+ / -11 semitones");
    list.add("+/-12__+ / -12 semitones");
    return list;
}

const StringArray Choices_For::exp_clock_div() {
    StringArray list;
    list.add("half note__half note (BPM / 2)");
    list.add("quarter note__quarter note (BPM x 1)");
    list.add("8th note__8th note (BPM x 2)");
    list.add("8th note, 1/2 swing__8th note, 1/2 swing (BPM x 2)");
    list.add("8th note, full swing__8th note, full swing (BPM x 2)");
    list.add("8th note triplets__8th note triplets (BPM x 3)");
    list.add("16th note__16th note (BPM x 4)");
    list.add("16th note, 1/2 swing__16th note, 1/2 swing (BPM x 4)");
    list.add("16th note, full swing__16th note, full swing (BPM x 4)");
    list.add("16th note triplets__16th note triplets (BPM x 6)");
    list.add("32nd note__32nd note (BPM x 8)");
    list.add("32nd note triplets__32nd note triplets (BPM x 12)");
    list.add("64th note triplets__64th note triplets (BPM x 24)");
    return list;
}

const StringArray Choices_For::exp_clock_tempo() {
    StringArray list;
    for (auto i = 30; i < 251; ++i) {
        String n{ i };
        list.add(n + "__" + n + " BPM");
    }
    return list;
}

const StringArray Choices_For::exp_flex_knob() {
    StringArray list;
    for (int i = 1; i < 3; ++i) {
        String osc{ "oscillator " + (String)i };
        list.add(osc + " pitch");
        list.add(osc + " fine tune");
        list.add(osc + " wave shape");
        list.add(osc + " glide rate");
        list.add(osc + " key track");
        list.add("sub-" + osc + " level");
    }
    list.add("hard sync oscillators");
    list.add("glide mode");
    list.add("oscillator slop");
    list.add("pitch bend range");
    list.add("keyed note priority");
    list.add("oscillators 1 & 2 mix");
    list.add("noise level");
    list.add("external audio in level__external audio input level");
    list.add("LPF cutoff frequency");
    list.add("LPF resonance");
    list.add("LPF keyboard amount");
    list.add("LPF freq. mod. amount");
    list.add("LPF 2- or 4-pole select");
    list.add("LPF envelope amount");
    list.add("LPF env. vel. amt.__LPF envelope velocity amount");
    list.add("LPF envelope delay");
    list.add("LPF envelope attack");
    list.add("LPF envelope decay");
    list.add("LPF envelope sustain");
    list.add("LPF envelope release");
    list.add("VCA initial level");
    list.add("VCA envelope amount");
    list.add("VCA env. vel. amt.__VCA envelope velocity amount");
    list.add("VCA Envelope Delay");
    list.add("VCA Envelope Attack");
    list.add("VCA Envelope Decay");
    list.add("VCA Envelope Sustain");
    list.add("VCA Envelope Release");
    list.add("Voice Volume");
    for (int i = 1; i < 5; ++i) {
        String lfo{ "LFO " + (String)i };
        list.add(lfo + " frequency");
        list.add(lfo + " wave shape");
        list.add(lfo + " amount");
        list.add(lfo + " mod. destination__" + lfo + " modulation destination");
        list.add(lfo + " key sync");
    }
    list.add("env. 3 mod. destination__env. 3 modulation destination");
    list.add("envelope 3 amount");
    list.add("env. 3 velocity amount");
    list.add("envelope 3 delay");
    list.add("envelope 3 attack");
    list.add("envelope 3 decay");
    list.add("envelope 3 sustain");
    list.add("envelope 3 release");
    list.add("envelope 3 repeat");
    for (int i = 1; i < 5; ++i) {
        String mod{ "modulator " + (String)i };
        list.add(mod + " source");
        list.add(mod + " amount");
        list.add(mod + " destination");
    }
    list.add("modulation wheel amt.__modulation wheel amount");
    list.add("modulation wheel dest.__modulation wheel destination");
    list.add("pressure amount__pressure (aftertouch) amount");
    list.add("pressure destination__pressure (aftertouch) destination");
    list.add("breath amount__breath controller amount");
    list.add("breath destination__breath controller destination");
    list.add("velocity amount__note velocity amount");
    list.add("velocity destination__note velocity destination");
    list.add("foot pedal amount");
    list.add("foot pedal destination");
    list.add("Push It! switch pitch");
    list.add("Push It! switch velocity");
    list.add("Push It! switch mode");
    list.add("clock tempo (BPM)");
    list.add("clock division");
    list.add("arpeggiator mode");
    list.add("arpeggiator on / off");
    list.add("sequencer trigger mode");
    list.add("sequencer on / off");
    for (int i = 1; i < 5; ++i) {
        String trk{ "sequencer track " + (String)i };
        list.add(trk + " dest.__" + trk + " destination");
    }
    for (int t = 1; t < 5; ++t) {
        for (int s = 1; s < 17; ++s) {
            String trk_stp{ "track " + (String)t + " step " + (String)s };
            list.add("seq. " + trk_stp +"__sequencer " + trk_stp);
        }
    }
    return list;
}

const StringArray Choices_For::exp_glide_mode() {
    StringArray list;
    list.add("fixed rate");
    list.add("fixed rate auto");
    list.add("fixed time");
    list.add("fixed time auto");
    return list;
}

const StringArray Choices_For::exp_lfo_freq() {
    StringArray list;
    for (int i = 1; i < lfo_1st_pitch_freq; ++i) {
        String n{ i };
        list.add(n + "__un-synced " + n);
    }
    for (int i = lfo_1st_pitch_freq; i < lfo_1st_sync_freq; ++i) {
        String n{ i };
        auto pitch = CONVERT::int_to_pitch(i - lfo_1st_pitch_freq);
        list.add(pitch + "__" + n + " (pitch freq. " + pitch + ")");
    }
    list.add("1:32__synced 151 : 1 LFO cycle lasts 32 steps");
    list.add("1:16__synced 152 : 1 LFO cycle lasts 16 steps");
    list.add("1:8__synced 153 : 1 LFO cycle lasts 8 steps");
    list.add("1:6__synced 154 : 1 LFO cycle lasts 6 steps");
    list.add("1:4__synced 155 : 1 LFO cycle lasts 4 steps");
    list.add("1:3__synced 156 : 1 LFO cycle lasts 3 steps");
    list.add("1:2__synced 157 : 1 LFO cycle lasts 2 steps");
    list.add("1:1.5__synced 158 : 1 LFO cycle lasts 1.5 steps");
    list.add("1:1__synced 159 : 1 LFO cycle lasts 1 step");
    list.add("3:2__synced 160 : 1 LFO cycle lasts 2/3 step");
    list.add("2:1__synced 161 : 1 LFO cycle lasts 1/2 step");
    list.add("3:1__synced 162 : 1 LFO cycle lasts 1/3 step");
    list.add("4:1__synced 163 : 1 LFO cycle lasts 1/4 step");
    list.add("6:1__synced 164 : 1 LFO cycle lasts 1/6 step");
    list.add("8:1__synced 165 : 1 LFO cycle lasts 1/8 step");
    list.add("16:1__synced 166 : 1 LFO cycle lasts 1/16 step");
    return list;
}

const StringArray Choices_For::exp_lfo_shape() {
    StringArray list;
    list.add("triangle");
    list.add("reverse sawtooth");
    list.add("sawtooth");
    list.add("pulse (square)");
    list.add("random");
    return list;
}

const StringArray Choices_For::exp_lpf_freq() {
    StringArray list;
    for (int i = 0; i < 165; ++i) {
        String n{ i };
        auto p{ CONVERT::int_to_pitch(i) };
        list.add(p + "__" + n + " (pitch freq. " + p + ")");
    }
    return list;
}

const StringArray Choices_For::exp_lpf_type() {
    return { "2-Pole", "4-Pole" };
}

const StringArray Choices_For::exp_mod_dest() {
    StringArray list;
    list.add("off");
    list.add("oscillator 1 pitch");
    list.add("oscillator 2 pitch");
    list.add("oscillator 1 & 2 pitch");
    list.add("oscillator mix");
    list.add("noise level");
    list.add("oscillator 1 pulse width");
    list.add("oscillator 2 pulse width");
    list.add("oscillator 1 & 2 PW__oscillator 1 & 2 pulse width");
    list.add("LPF cutoff frequency");
    list.add("LPF resonance");
    list.add("LPF FM amount");
    list.add("VCA level");
    list.add("output panning");
    for (int i = 1; i < 4; ++i)
        list.add("LFO " + (String)i + " frequency");
    list.add("all LFO frequencies");
    for (int i = 1; i < 4; ++i)
        list.add("LFO " + (String)i + " amount");
    list.add("all LFO amounts");
    list.add("LPF envelope amount");
    list.add("VCA envelope amount");
    list.add("envelope 3 amount");
    list.add("all envelope amounts");
    list.add("LPF envelope attack");
    list.add("VCA envelope attack");
    list.add("envelope 3 attack");
    list.add("all envelope attacks");
    list.add("LPF envelope decay");
    list.add("VCA envelope decay");
    list.add("envelope 3 decay");
    list.add("all envelope decays");
    list.add("LPF envelope release");
    list.add("VCA envelope release");
    list.add("envelope 3 release");
    list.add("all envelope releases");
    for (int i = 1; i < 4; ++i)
        list.add("modulator " + (String)i + " amount");
    list.add("external audio in level__external audio input level");
    list.add("sub-osc. 1 level__sub-oscillator 1 level");
    list.add("sub-osc. 2 level__sub-oscillator 2 level");
    return list;
}

const StringArray Choices_For::exp_mod_src() {
    StringArray list;
    list.add("off");
    for (int i = 1; i < 4; ++i)
        list.add("sequencer track " + (String)i);
    for (int i = 1; i < 4; ++i)
        list.add("LFO " + (String)i);
    list.add("LPF envelope");
    list.add("VCA envelope");
    list.add("envelope 3");
    list.add("pitch bend");
    list.add("mod wheel");
    list.add("pressure (aftertouch)");
    list.add("MIDI breath");
    list.add("MIDI foot pedal");
    list.add("MIDI expression");
    list.add("velocity");
    list.add("note number");
    list.add("noise");
    list.add("audio in env. follower");
    list.add("audio in peak hold");
    return list;
}

const StringArray Choices_For::exp_note_priority() {
    StringArray list;
    list.add("low note__low note has priority");
    list.add("low note (re-trigger)__low note has priority (re-trigger)");
    list.add("high note__high note has priority");
    list.add("high note (re-trigger)__high note has priority (re-trigger)");
    list.add("last note__last note hit has priority");
    list.add("last note (re-trigger)__last note hit has priority (re-trigger)");
    return list;
}

const StringArray Choices_For::exp_osc_shape() {
    StringArray list;
    list.add("OFF__oscillator off");
    list.add("SAW__sawtooth");
    list.add("TRI__triangle");
    list.add("S/T__sawtooth / triangle mix");
    for (int i = 0; i < 100; ++i) {
        if (i == 50)
            list.add("SQR__square (pulse: width 50)");
        else {
            auto p = (String)i;
            list.add("PW " + p + "__pulse: width " + p);
        }
    }
    return list;
}

const StringArray Choices_For::exp_push_it_mode() {
    StringArray list;
    list.add("normal");
    list.add("toggle");
    list.add("audio in");
    return list;
}

const StringArray Choices_For::exp_seq_track_2_4_dest(const bool trk_2) {
    StringArray list{ exp_mod_dest() };
    String t{ trk_2 ? 1 : 3 };
    list.add("seq. track " + t + " slew__sequencer track " + t + " slew");
    return list;
}

const StringArray Choices_For::exp_seq_track_step() {
    StringArray list;
    for (int i = 0; i < 126; ++i) {
        auto p = CONVERT::int_to_seq_step_pitch(i);
        list.add(p + "__" + (String)i + " (" + p + ")");
    }
    list.add("<__reset sequence");
    list.add(".__rest");
    return list;
}

const StringArray Choices_For::exp_seq_trig_mode() {
    StringArray list;
    list.add("normal");
    list.add("normal, no reset");
    list.add("no gate");
    list.add("no gate, no reset");
    list.add("key step");
    list.add("audio input");
    return list;
}

const StringArray Choices_For::exp_voice_name_char() {
    StringArray list;
    for (int i = 0; i < 32; ++i)
        list.add(" __ASCII control character " + (String)i);
    list.add(" __space");
    for (int i = 33; i < 128; ++i) {
        String n{ std::string(1, (char)i) };
        if (i == 92)
            n = "\\__yen symbol";
        if (i == 126)
            n = "->__right arrow";
        if (i == 127)
            n = "<-__left arrow";
        list.add(n);
    }
    return list;
}
