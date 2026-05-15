#include "H_10-P_Describe_Exp_Param.h"

#include "C_12-B_FONT.h"
#include "C_60-P_SL_EP_Descriptions.h"

using namespace FONT;

String Describe_Exp_Param::from_string_literal(const char8_t* sl) {
    String s{ sl };
    s = s.trimCharactersAtStart("\n");
    return s;
}

String Describe_Exp_Param::env_amp(const String e) {
    return from_string_literal(SL::env_amp_description).replaceCharacters("_", e);
}

String Describe_Exp_Param::env_attack(const String e) {
    return from_string_literal(SL::env_attack_description).replaceCharacters("_", e);
}

String Describe_Exp_Param::env_decay(const String e) {
    return from_string_literal(SL::env_decay_description).replaceCharacters("_", e);
}

String Describe_Exp_Param::env_delay(const String e) {
    return from_string_literal(SL::env_delay_description).replaceCharacters("_", e);
}

String Describe_Exp_Param::env_lfo_1_trig(const String e) {
    return from_string_literal(SL::env_lfo_1_trig_description).replaceCharacters("_", e);
}

String Describe_Exp_Param::env_mode(const String e) {
    return from_string_literal(SL::env_mode_description).replaceCharacters("_", e);
}

String Describe_Exp_Param::env_release(const String e) {
    return from_string_literal(SL::env_release_description).replaceCharacters("_", e);
}

String Describe_Exp_Param::env_sustain(const String e) {
    return from_string_literal(SL::env_sustain_description).replaceCharacters("_", e);
}

String Describe_Exp_Param::env_trig_mode(const String e) {
    return from_string_literal(SL::env_trig_mode_description).replaceCharacters("_", e);
}

String Describe_Exp_Param::env_velo_amt(const String e) {
    return from_string_literal(SL::env_velo_amt_description).replaceCharacters("_", e);
}

String Describe_Exp_Param::keyboard_mode() {
    return from_string_literal(SL::keyboard_mode_description);
}

String Describe_Exp_Param::lfo_1_pressure_amt() {
    return from_string_literal(SL::lfo_1_pressure_amt_description);
}

String Describe_Exp_Param::lfo_2_key_track_amt() {
    return from_string_literal(SL::lfo_2_key_track_amt_description);
}

String Describe_Exp_Param::lfo_amp(const int lfo) {
    return from_string_literal(SL::lfo_amp_description).replaceCharacters("_", (String)lfo);
}

String Describe_Exp_Param::lfo_lag(const int lfo) {
    return from_string_literal(SL::lfo_lag_description).replaceCharacters("_", (String)lfo);
}

String Describe_Exp_Param::lfo_ramp_amt(const int lfo) {
    return from_string_literal(SL::lfo_ramp_amt_description).replaceCharacters("_", (String)lfo);
}

String Describe_Exp_Param::lfo_retrig_point(const int lfo) {
    return from_string_literal(SL::lfo_retrig_point_description).replaceCharacters("_", (String)lfo);
}

String Describe_Exp_Param::lfo_sample_source(const int lfo) {
    return from_string_literal(SL::lfo_sample_source_description).replaceCharacters("_", (String)lfo);
}

String Describe_Exp_Param::lfo_speed(const int lfo) {
    return from_string_literal(SL::lfo_speed_description).replaceCharacters("_", (String)lfo);
}

String Describe_Exp_Param::lfo_trig_mode(const int lfo) {
    return from_string_literal(SL::lfo_trig_mode_description).replaceCharacters("_", (String)lfo);
}

String Describe_Exp_Param::lfo_wave_type(const int lfo) {
    return from_string_literal(SL::lfo_wave_type_description).replaceCharacters("_", (String)lfo);
}

String Describe_Exp_Param::osc_1_sync() {
    return from_string_literal(SL::osc_1_sync_description);
}

String Describe_Exp_Param::osc_2_detune() {
    return from_string_literal(SL::osc_2_detune_description);
}

String Describe_Exp_Param::osc_balance() {
    return from_string_literal(SL::osc_balance_description);
}

String Describe_Exp_Param::osc_key_click() {
    return from_string_literal(SL::osc_key_click_description);
}

String Describe_Exp_Param::osc_key_track(const int o) {
    if(o == 1)
        return from_string_literal(SL::osc_1_key_track_description);
    return from_string_literal(SL::osc_2_key_track_description);
}

String Describe_Exp_Param::osc_lever_control(const int o) {
    return from_string_literal(SL::osc_lever_control_description).replaceCharacters("_", (String)o);
}

String Describe_Exp_Param::osc_lfo_1_fm(const int o) {
    return from_string_literal(SL::osc_lfo_1_fm_description).replaceCharacters("_", (String)o);
}

String Describe_Exp_Param::osc_lfo_2_pwm(const int o) {
    return from_string_literal(SL::osc_lfo_2_pwm_description).replaceCharacters("_", (String)o);
}

String Describe_Exp_Param::osc_pitch(const int o) {
    return from_string_literal(SL::osc_pitch_description).replaceCharacters("_", (String)o);
}

String Describe_Exp_Param::osc_pulse_w(const int o) {
    return from_string_literal(SL::osc_pulse_w_description).replaceCharacters("_", (String)o);
}

String Describe_Exp_Param::osc_saw_tri(const int o) {
    return from_string_literal(SL::osc_saw_tri_description).replaceCharacters("_", (String)o);
}

String Describe_Exp_Param::osc_type(const int o) {
    String s{ from_string_literal(SL::osc_type_description).replaceCharacters("_", (String)o) };
    if (o == 1)
        s = s.upToLastOccurrenceOf("\n", false, false);
    return s;
}

String Describe_Exp_Param::porta_legato() {
    return from_string_literal(SL::porta_legato_description);
}

String Describe_Exp_Param::porta_mode() {
    return from_string_literal(SL::porta_mode_description);
}

String Describe_Exp_Param::porta_rate() {
    return from_string_literal(SL::porta_rate_description);
}

String Describe_Exp_Param::porta_velo() {
    return from_string_literal(SL::porta_velo_description);
}

String Describe_Exp_Param::ramp_rate(const int ramp) {
    String s{ "" };
    s += "Sets the amount of time it takes for\n";;
    s += "Ramp " + (String)ramp + " to complete its control cycle.\n";
    s += "Range: 0 (instantaneous) to 63 (longest).";
    return s;
}

String Describe_Exp_Param::ramp_trig(const int ramp) {
    String s{ "" };
    s += "Selects the type of trigger that will start ramp " + (String)ramp + apostrophe + "s control cycle.\n";
    s += "STRIG: Single - A new note triggers the ramp only when no other\n";
    s += "notes are currently held down (only active in unison mode).\n";
    s += "MTRIG: Multiple - the ramp is triggered with every new note played.\n";
    s += "XTRIG: External - an external signal (e.g. a footswitch) triggers the ramp.\n";
    s += "GATEX: Gated External - an external signal triggers the ramp only when\n";
    s += "there are one or more notes being played.";
    return s;
}

String Describe_Exp_Param::track_input() {
    String s{ "" };
    s += "Selects the modulation source which\n";
    s += "will be shaped by the tracking generator.";
    return s;
}

String Describe_Exp_Param::track_point(const int point, int init_choice) {
    String s{ "" };
    s += "Tracking Point " + (String)point + "\n";
    s += "Range: 0 to 63.\n";
    s += "Linear output value: " + (String)init_choice + ".";
    return s;
}

String Describe_Exp_Param::vca_1_velo_amt() {
    String s{ "" };
    s += "Sets whether and to what degree note velocity\n";
    s += "modulates the output level of VCA 1.\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the velocity response.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::vca_1_volume() {
    String s{ "" };
    s += "Sets the initial output level of the\n";
    s += "first-stage voltage-controlled amplifier.\n";
    s += "Range: 0 (silence) to 63 (maximum).";
    return s;
}

String Describe_Exp_Param::vca_2_env_2_amt() {
    String s{ "" };
    s += "Sets whether and to what degree envelope 2\n";
    s += "modulates the output level of the second-\n";
    s += "stage voltage-controlled amplifier.\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the envelope.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::vcf_env_1_amt() {
    String s{ "" };
    s += "Sets whether and to what degree envelope 1\n";
    s += "modulates the VCF" + apostrophe + "s cutoff frequency.\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the envelope.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::vcf_fm_env_3_amt() {
    String s{ "" };
    s += "Sets whether and to what degree envelope 3\n";
    s += "modulates the amount of VCF FM by oscillator 1.\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the envelope.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::vcf_fm_osc_1_amt() {
    String s{ "" };
    s += "Sets whether and to what degree oscillator 1\n";
    s += "modulates the VCF" + apostrophe + "s cutoff frequency.\n";
    s += "Range: 0 (no modulation) to 63 (maximum).";
    return s;
}

String Describe_Exp_Param::vcf_fm_pressure_amt() {
    String s{ "" };
    s += "Sets whether and to what degree keyboard\n";
    s += "pressure (aftertouch) modulates the\n";
    s += "amount of VCF FM by oscillator 1.\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the pressure response.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::vcf_freq() {
    String s{ "" };
    s += "Sets the base cutoff frequency of\n";
    s += "the voltage-controlled filter.\n";
    s += "Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::vcf_key_track() {
    String s{ "" };
    s += "Selects how the VCF" + apostrophe + "s cutoff frequency responds to incoming pitch\n";
    s += "change messages (e.g. notes played on a keyboard controller).\n";
    s += "OFF: Note key changes have no effect on the VCF" + apostrophe + "s cutoff frequency.\n";
    s += "PORTA: Tracking is active, but transitions between cutoff frequencies are\n";
    s += "smoothed according to the settings in the portamento (aka " + open_quote + "glide" + close_quote + ") section.\n";
    s += "KEYBD: The VCF" + apostrophe + "s cutoff frequency tracks note key changes, rising as\n";
    s += "higher notes are played and dropping as lower notes are played.";
    return s;
}

String Describe_Exp_Param::vcf_lever_ctrl() {
    String s{ "" };
    s += "Selects which of the performance " + open_quote + "levers" + close_quote + "\n";
    s += "(wheel-type controllers) modulate the VCF frequency.\n";
    s += "OFF: VCF frequency is not modulated by either lever.\n";
    s += "BEND: VCF frequency is modulated by lever 1 (pitch wheel).\n";
    s += "VIB: VCF frequency vibrato is modulated by lever 2 (mod wheel).\n";
    s += "BOTH: VCF frequency is modulated by both levers.";
    return s;
}

String Describe_Exp_Param::vcf_pressure_amt() {
    String s{ "" };
    s += "Sets whether and to what degree keyboard pressure \n";
    s += "(aftertouch) modulates the VCF" + apostrophe + "s cutoff frequency.\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the pressure response.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::vcf_reso() {
    String s{ "" };
    s += "Sets the resonance level of\n";
    s += "the voltage-controlled filter.\n";
    s += "Range: 0 to 63. At 63, the/n";
    s += "filter will self-oscillate.";
    return s;
}
