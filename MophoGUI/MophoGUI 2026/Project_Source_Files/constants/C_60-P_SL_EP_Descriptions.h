#pragma once

namespace SL
{

    constexpr auto arpeg_mode_description = u8R"(
Sets the order in which the arpeggiator plays notes.
‘Assign’ modes play notes in the order they were struck.)";

    constexpr auto arpeg_on_off_description = u8R"(
Turns the Mopho’s arpeggiator on and off.
Turning it on will turn off the sequencer.)";

    constexpr auto bend_range_description = u8R"(
Sets the maximum amount (in semitones) by which pitch wheel
messages can raise or lower the pitches of the oscillators.
Range: 0 (no pitch bend) to +/-12 semitones.)";

    constexpr auto clock_division_description = u8R"(
Sets the rate at which the sequencer and
arpeggiator advance, relative to the tempo.)";

    constexpr auto clock_tempo_description = u8R"(
Sets the tempo (in beats per minute)
for the sequencer and the arpeggiator.
Range: 30 to 250 BPM.)";

    constexpr auto env_3_amt_description = u8R"(
Sets the degree to which envelope 3
modulates the destination parameter.
Negative values invert the envelope.
Range: -127 to +127.)";

    constexpr auto env_3_repeat_description = u8R"(
When repeat is on, envelope 3 loops through
its delay, attack, decay, and sustain stages
for as long as the envelope is gated on.)";

    constexpr auto env_attack_description = u8R"(
Sets the length of _envelope name_’s attack stage
(the amount of time it takes for the envelope’s
level to rise from minimum to maximum).
Range: 0 (instantaneous) to 127 (longest time).)";

    constexpr auto env_decay_description = u8R"(
Sets the length of _envelope name_’s decay stage
(the amount of time it takes for the envelope’s
level to fall from maximum to the sustain level).
Range: 0 (instantaneous) to 127 (longest time).)";

    constexpr auto env_delay_description = u8R"(
Sets the length of _envelope name_’s delay stage
(the amount of time that passes after the envelope
is triggered before its attack stage begins).
Range: 0 (instantaneous) to 127 (longest time).)";

    constexpr auto env_release_description = u8R"(
Sets the length of _envelope name_’s release stage
(the amount of time it takes to fall from the sustain level
down to minimum once the envelope is gated off).
Range: 0 (instantaneous) to 127 (longest time).)";

    constexpr auto env_sustain_description = u8R"(
Sets _envelope name_’s sustain level
(after the decay stage completes, the envelope
holds at this level until it is gated off).
Range: 0 (minimum) to 127 (maximum).)";

    constexpr auto env_vel_amt_description = u8R"(
Sets the degree to which MIDI note velocity
modulates the amplitude of _envelope name_.
Range: 0 to 127.)";

    constexpr auto ext_in_level_description = u8R"(
Sets the level of external audio input
sent into the low-pass filter. When
nothing is connected to the audio
input jack, this controls the level of
feedback from the left audio output.
Range: 0 to 127.)";

    constexpr auto glide_mode_description = u8R"(
Fixed Rate: The actual glide time depends on the size of the note interval.
Fixed Time: The glide time is constant, regardless of the interval size.
The ‘Auto’ modes only apply glide when a note is played legato
(i.e. a new note is triggered before the previous note is released).)";

    constexpr auto knob_assign_description = u8R"(
Selects a target parameter for
assignable hardware knob _.)";

    constexpr auto lfo_amt_description = u8R"(
Sets the degree to which LFO _
modulates the destination parameter.
Range: 0 to 127.)";

    constexpr auto lfo_freq_description = u8R"(
Sets LFO _’s cycling speed. Range: 0 to 166.
At 0, 1 cycle lasts 30 seconds. At 89, the frequency is 8 Hz.
From 90 to 150, LFO _ has a pitched frequency, increasing
in semitone steps from C 0 (8.2 Hz) up to C 5 (261.6 Hz).
Above 150, LFO _ is synced with the step sequencer,
displayed as [number of LFO cycles] : [length in steps].)";

    constexpr auto lfo_key_sync_description = u8R"(
When on, LFO _’s cycle will reset
each time a new note is played.)";

    constexpr auto lfo_shape_description = u8R"(
Selects LFO _’s wave shape.)";

    constexpr auto lpf_env_amt_description = u8R"(
Sets the degree to which the LPF envelope
modulates the filter’s cutoff frequency.
Negative values invert the envelope.
Range: -127 to +127.)";

    constexpr auto lpf_fm_amt_description = u8R"(
Sets the degree to which oscillator 1 modulates
the low-pass filter’s cutoff frequency. This is
useful for generating bell-like sounds.
Range: 0 to 127.)";

    constexpr auto lpf_freq_description = u8R"(
Sets the base cutoff frequency for the low-pass filter
(in semitone steps). Range: 0 (C 0) to 164 (G# 13).
Hold down the SHIFT key when using the mouse wheel to
increment the frequency by one octave (12 semitones).)";

    constexpr auto lpf_key_amt_description = u8R"(
Sets the amount by which keyboard (MIDI) notes
will shift the low-pass filter’s cutoff frequency.
Range: 0 to 127. At 64, cutoff is shifted by one
semitone for each note. At 32, cutoff is shifted
by one half-semitone for each note.)";

    constexpr auto lpf_reso_description = u8R"(
Sets the resonance level of the low-pass
filter. When in 4-pole mode, high resonance
will cause the filter to self-oscillate.
Range: 0 to 127.)";

    constexpr auto lpf_type_description = u8R"(
Switches the low-pass filter type between 2-Pole and 4-Pole.
When set to 4-pole, the filter has a steeper cutoff frequency
slope and more pronounced resonance.)";

    constexpr auto midi_breath_amt_description = u8R"(
Sets the degree to which MIDI breath controller
messages (CC#2) modulate the destination
parameter. Negative values invert the modulation.
Range: -127 to +127.)";

    constexpr auto midi_mod_wheel_amt_description = u8R"(
Sets the degree to which MIDI modulation wheel controller
messages (CC#1) modulate the destination parameter.
Negative values invert the modulation.
Range: -127 to +127.)";

    constexpr auto midi_pedal_amt_description = u8R"(
Sets the degree to which MIDI foot pedal controller
messages (CC#4) modulate the destination parameter.
Negative values invert the modulation.
Range: -127 to +127.)";

    constexpr auto midi_pressure_amt_description = u8R"(
Sets the degree to which MIDI channel pressure
(aftertouch) messages modulate the destination
parameter. Negative values invert the modulation.
Range: -127 to +127.)";

    constexpr auto midi_velocity_amt_description = u8R"(
Sets the degree to which MIDI note velocity
messages modulate the destination parameter.
Negative values invert the modulation.
Range: -127 to +127.)";

    constexpr auto mod_amt_description = u8R"(
Sets the degree to which the selected source
modulates the selected destination parameter.
Negative values invert the modulation.
Range: -127 to +127.)";

    constexpr auto noise_level_description = u8R"(
Sets the level of white noise
sent into the low-pass filter.
Range: 0 to 127.)";

    constexpr auto note_priority_description = u8R"(
Selects which note is given priority when multiple
notes are played, and whether the envelopes are
re-triggered when a note is played legato (before
the previous note has been released).)";

    constexpr auto osc_fine_description = u8R"(
Fine tunes oscillator _’s base pitch.
Range: -50 cents to +50 cents.
0 = no detuning (centered).)";

    constexpr auto osc_glide_description = u8R"(
Sets oscillator _’s glide (portamento) rate.
Range: 0 (instantaneous) to 127 (very slow)";

    constexpr auto osc_key_track_description = u8R"(
Turns keyboard tracking for oscillator _
on or off. When turned off, the oscillator
always produces its base pitch, ignoring
the pitch of incoming MIDI note messages.)";

    constexpr auto osc_mix_description = u8R"(
Controls the level balance between oscillators 1 & 2.
Range: 0 to 127. At 0, only oscillator 1 is heard.
At 127, only oscillator 2 is heard. At 64, an equal
mix of the two oscillators is heard.)";

    constexpr auto osc_pitch_description = u8R"(
Sets oscillator _’s base pitch in semitone steps.
Range: C 0 (8 Hz) to C 10 (8.2 KHz). Middle C is C 5.
Hold down the SHIFT key when using the mouse wheel to
increment the pitch by one octave (12 semitones).)";

    constexpr auto osc_shape_description = u8R"(
Selects oscillator _’s wave shape.
Hold down a number on the keyboard and
click the knob to jump directly to a wave shape:
0 = Off;  1 = Sawtooth;  2 = Triangle;
3 = Sawtooth / Triangle Mixture;
4 = Square (a Pulse with width 50).)";

    constexpr auto osc_slop_description = u8R"(
Introduces a subtle amount of random oscillator
pitch drift for a ‘vintage analog’ sound.
Range: 0 to 5.)";

    constexpr auto osc_sub_level_description = u8R"(
Sets the level of sub-oscillator _,
which generates a square wave pitched
one octave lower than oscillator _.
Range: 0 to 127.)";

    constexpr auto osc_sync_description = u8R"(
Turns hard oscillator sync on or off. When
turned on, every time oscillator 2 resets
it forces oscillator 1 to reset as well.)";

    constexpr auto push_it_mode_description = u8R"(
Sets the operating mode for the Mopho’s Push It! switch.
Normal: The selected note is gated on when the switch is
pressed and gated off when the switch is released.
Toggle: The selected note is gated on when the switch is
pressed and remains on until the switch is pressed again.
Audio In: The selected note is gated on for as long as the
external audio input level is above a certain threshold.)";

    constexpr auto push_it_pitch_description = u8R"(
Sets the note that plays when the Push It! switch is pressed.
Range: C 0 (8.2 Hz) to C 10 (8.4 KHz). Middle C is C 5.
Hold down the SHIFT key when using the mouse wheel to
increment the pitch by one octave (12 semitones).)";

    constexpr auto push_it_velocity_description = u8R"(
Sets the velocity of the note that plays
when the Push It! switch is pressed.
Range: 0 to 127.)";

    constexpr auto seq_on_off_description = u8R"(
Turns the Mopho’s internal sequencer on and off.
Turning this on will turn off the arpeggiator.)";

    constexpr auto seq_track_dest_description = u8R"(
Selects the target parameter for
modulation by sequencer track _.)";

    constexpr auto seq_track_step_description_1 = u8R"(
Sets the value that sequencer track _’s destination parameter has at step %,
Range: 0 to 125. If the target is an oscillator pitch, the range is C0 to D5+.
A ‘+’ indicates that the pitch is a quarter-tone higher than the displayed note.
Reset (126): Resets the sequence back to step 1. CTRL-click a step to set it to reset.
)";

    constexpr auto seq_track_step_description_2 = u8R"(
Rest (127): The step produces no output. ALT-click a step to make it a rest.
Rests are only available for the steps in sequencer track 1.
)";

    constexpr auto seq_track_step_description_3 = u8R"(
When the track destination is an oscillator pitch, holding down the
SHIFT key while turning the mouse wheel will increment a step’s value 
by 24 (equivalent to one octave including the ‘bent’ pitches).
Otherwise, the value will increment by 10.)";

    constexpr auto seq_trig_mode_description = u8R"(
Normal: New notes reset the sequencer to the first step.
The envelopes are re-triggered with each step.
Normal, No Reset: New notes do not reset the sequencer to the
first step. The envelopes are re-triggered with each step.
No Gate: New notes reset the sequencer to the first step. New
notes re-trigger the envelopes, but sequencer steps do not.
No Gate, No Reset: New notes do not reset the sequencer to the
first step. Sequencer steps do not re-trigger the envelopes.
Key Step: Each new note advances the sequencer one step.
Audio Input: The sequencer advances one step every time the
external audio input level surpasses a certain threshold.)";

    constexpr auto vca_env_amt_description = u8R"(
Sets the degree to which the VCA envelope
modulates the voltage-controlled ampifier’s level.
Range: 0 to 127.)";

    constexpr auto vca_level_description = u8R"(
Sets the voltage-controlled amplifier’s baseline level. Turn this
up for droning sounds or when processing external audio input.
When this level is set to 127, the VCA envelope has no effect.
Range: 0 to 127.)";

    constexpr auto voice_name_char_description = u8R"(
To change character _ of the program’s name,
click-and-drag the character or hover over
it and turn the mouse wheel. Click the edit
button above to type in the entire name.)";

    constexpr auto voice_volume_description = u8R"(
Sets the overall gain of the current program.
Range: 0 to 127.)";

}