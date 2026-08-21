#pragma once

namespace SL
{

    constexpr auto amp_mod_by_velo_amt_tip = u8R"(
Sets the degree to which the program’s maximum
amplitude is modulated by keyboard velocity.
Range: 0 (no modulation) to 127 (full modulation).)";

    constexpr auto fine_tune_tip = u8R"(
Adjusts the program’s overall
tuning in one-cent increments.
Range: -50 to +50 cents.)";

    constexpr auto flex_sli_bend_neg_tip = u8R"(
Selects the maximum negative pitch
bend that can be applied by moving
the hardware slider to the left.
Range: 1 to 12 semitones.)";

    constexpr auto flex_sli_bend_pos_tip = u8R"(
Selects the maximum positive pitch
bend that can be applied by moving
the hardware slider to the right.
Range: 1 to 12 semitones.)";

    constexpr auto flex_sli_range_tip = u8R"(
Sets the degree to which the hardware
slider modulates the target parameter.
Range: -100% to +100% (negative values
invert the direction of the slider).)";

    constexpr auto flex_sli_target_tip = u8R"(
Selects which program parameter
the hardware slider modulates.)";

    constexpr auto keyboard_octave_tip = u8R"(
Transposes the pitch range
of the hardware keyboard.
Range: -2 to +2 octaves.)";

    constexpr auto level_tip = u8R"(
Adjusts the program’s overall volume
level relative to other programs.
Range: -25 to +25.)";

    constexpr auto lfo_sync_bpm_on_tip = u8R"(
When turned on, the LFO cycle will be synchronized
with the sequencer’s BPM tempo and the LFO rate
knob will display the number of beats per cycle.
When  turned off, the LFO rate knob will display
a value between 0 (slowest) and 1023 (fastest).)";

    constexpr auto lfo_sync_key_on_tip = u8R"(
When turned on, the LFO cycle resets with
each note-on message from the keyboard.)";

    constexpr auto lfo_sync_voice_on_tip = u8R"(
When turned on, all four voices
share the same LFO cycle.)";

    constexpr auto microtune_scale_tip = u8R"(
Selects the microtuning
scale for the program.)";

    constexpr auto porta_mode_on_tip = u8R"(
• Auto (Portamento is only applied to notes
that are played legato (i.e. without
releasing the previously played note)
• On (Portamento is always applied))";

    constexpr auto porta_time_tip = u8R"(
Selects whether portamento is applied and how long
the smooth transmission between pitches will take.
Range: Off; 0 (shortest) to 127 (longest).)";

    constexpr auto porta_sync_bpm_on_tip = u8R"(
When turned on, portamento time will be
synchronized to the sequencer’s BPM tempo.)";

    constexpr auto scale_key_tip = u8R"(
Selects the root note of the current
microtuning scale (this has no effect
on the equal temperament scale).
Range: C 0 to C 2 in semitone steps.)";

    constexpr auto transpose_tip = u8R"(
Adjusts the program’s overall
pitch in semitone increments.
Range: -12 to +12 semitones.)";

    constexpr auto voice_mode_tip = u8R"(
Determines how the synthesizer’s
four voices are combined and allocated.
• POLY: 4-note polyphony, one voice per note.
• DUO: 2-note polyphony, two voices per note.
• UNISON: Monophonic, 4 voices per note.
• MONO: Monophonic with 2 or 3 of the voices
pitched down 2 octaves as sub-oscillators.
• CHORD: The 4 voices play together as a chord.
• DELAY: Voices 2, 3, and 4 play in a delayed
sequence after voice 1 plays.
• ARP: Uses the arpeggiator to play up to 4 voices.
• SIDE CHAIN: Lowers the volume of the previously-
played voice when a new voice is played legato.)";

}

