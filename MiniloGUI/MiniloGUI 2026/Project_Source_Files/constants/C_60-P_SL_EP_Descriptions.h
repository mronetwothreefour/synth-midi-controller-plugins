#pragma once

namespace SL
{

    constexpr auto delay_feedback_description = u8R"(
Sets the amount of
delay regeneration.
Transmits on CC #31.
Range: 0 to 1023.)";

    constexpr auto delay_routing_description = u8R"(
Selects how the HPF and delay are applied to
the original output audio. Transmits on CC #88.
Choices: • Bypass (HPF and delay are not applied)
• Pre-Filter (HPF is applied only to the delay audio)
• Post-Filter (HPF is applied to both the original
output audio and the delay audio).)";

    constexpr auto delay_time_description = u8R"(
Sets the delay time.
Transmits on CC #30.
Range: 0 (shortest)
1023 (longest).)";

    constexpr auto delay_hpf_freq_description = u8R"(
Sets the cutoff frequency for the
delay’s high-pass filter. Frequencies
below the cutoff will be attenuated.
Transmits on CC #29. Range: 0 to 1023.)";

    constexpr auto env_attack_description = u8R"(
Sets the length of the _ envelope’s attack stage
(the amount of time it takes for the envelope’s
level to rise from minimum to maximum).
Transmits on CC #%%. Range: 0 to 1023.)";

    constexpr auto env_decay_description = u8R"(
Sets the length of the _ envelope’s decay stage
(the amount of time it takes for the envelope’s
level to fall from maximum to the sustain level).
Transmits on CC #%%. Range: 0 to 1023.)";

    constexpr auto env_release_description = u8R"(
Sets the length of the _ envelope’s release stage
(the amount of time it takes to fall from the sustain
level down to minimum once the envelope is gated off).
Transmits on CC #%%. Range: 0 to 1023.)";

    constexpr auto env_sustain_description = u8R"(
Sets the _ envelope’s sustain level (once the
decay stage completes, the envelope holds
at this level until it is gated off).
Transmits on CC #%%. Range: 0 to 1023.)";

    constexpr auto key_track_description = u8R"(
Key tracking allows the pitch of the notes played on the
keyboard to change the LPF cutoff frequency. As you go
up the keyboard, the cutoff frequency is raised, more
upper harmonics are let through, and the notes sound
brighter. Transmits on CC #83. Choices: 0%, 50%, 100%.
• 0%: the cutoff frequency does not change.
• 50%: the cutoff frequency changes by 1/2 semitone
for every semitone step on the keyboard.
• 100%: the cutoff frequency changes by one semitone
for every semitone step on the keyboard.)";

    constexpr auto level_knob_description = u8R"(
Sets the output level of _target_name.
Transmits on CC #%%. Range: 0 to 1023.)";

    constexpr auto lfo_eg_mod_description = u8R"(
Selects the LFO parameter targeted
for modulation by the envelope
generator. Transmits on CC #57.
Choices: off, rate, intensity.)";

    constexpr auto lfo_int_description = u8R"(
Sets the depth of the modulation pro-
duced by the low-frequency oscillator.
Transmits on CC #26. Range: 0 to 1023.)";

    constexpr auto lfo_rate_description = u8R"(
Sets the speed of the LFO.
Note: the available settings
depend on whether LFO
BPM sync is on or off.
Transmits on CC #24.
Range: Unsynced: 0 to 1023;
Synced: 4 beats to 1/64 beat.)";

    constexpr auto lfo_target_description = u8R"(
Selects the parameter targeted for
modulation by the low-frequency
oscillator. Transmits on CC #56.
Choices: LPF cutoff frequency,
VCO 1 & 2 shape, VCO 1 & 2 pitch.)";

    constexpr auto lfo_wave_description = u8R"(
Selects the LFO’s waveform.
Transmits on CC #58.
Choices: square, triangle,
sawtooth.)";

    constexpr auto lpf_eg_int_description = u8R"(
Sets the degree to which the
envelope generator modulates the
filter’s cutoff frequency over time.
Negative values invert the envelope.
Transmits on CC #45.
Range: -100% to +100%.)";

    constexpr auto lpf_freq_description = u8R"(
Sets the cutoff frequency for the
low-pass filter. Frequencies above
the cutoff point will be attenuated.
Transmits on CC #43. Range: 0 to 1023.)";

    constexpr auto lpf_reso_description = u8R"(
Sets the resonance level for the low-pass filter.
Increasing resonance will add boost to freq-
uencies at or near the filter’s cutoff point.
Transmits on CC #44. Range: 0 to 1023.)";

    constexpr auto lpf_type_description = u8R"(
Switches the low-pass filter type between 2-Pole and 4-Pole.
When set to 4-pole, the filter has a steeper cutoff frequency
slope and more pronounced resonance. Transmits on CC #84.)";

    constexpr auto lpf_vel_amt_description = u8R"(
Selects the degree to which the velocity
of notes played on the keyboard shifts the
filter’s cutoff frequency (i.e. the harder a key
is struck, the more the cutoff frequency is
raised and the brighter the note sounds).
Choices: 0%, 50%, 100%. Transmits on CC #82.)";

    constexpr auto osc_2_pitch_eg_int_description = u8R"(
Sets the maximum amount (in cents) by which the envelope
generator will change the pitch of oscillator 2 over time.
For example, at 1200 cents the pitch will be raised by 1 octave
when the envelope reaches its peak amplitude. At -1200 cents,
the pitch will be lowered by 1 octave. Key modifiers for inc-
rementing with the mouse wheel: SHIFT = 10 cent increments;
CTRL = 100 cent increments; ALT = restrict to exact semitones
only (i.e. 100, 200, 300, ... ). Transmits on CC #42.
Range: -4800 to +4800 cents (-4 to +4 octaves).)";

    constexpr auto osc_2_x_mod_depth_description = u8R"(
Sets the degree to which
oscillator 2’s pitch is
modulated by oscillator 1.
Transmits on CC #41.
Range: 0 to 1023.)";

    constexpr auto osc_octave_description = u8R"(
Sets the root octave of oscillator _.
Transmits on CC #%%.
Range: 16' (lowest) to 2' (highest).)";

    constexpr auto osc_pitch_fine_description = u8R"(
Fine tunes the pitch of oscillator _
in increments of 1 cent (.01 semitone).
Key modifiers for incrementing with the
mouse wheel: SHIFT = 10 cent increments;
CTRL = 100 cent increments; ALT = restrict
to exact semitones (i.e. 100, 200, 300, ... ).
Transmits on CC #%%. Range: -1200 to +1200.)";

    constexpr auto osc_2_ring_mod_description = u8R"(
When turned on, oscillator 1 will
ring modulate oscillator 2. Useful
for generating bell-like timbres.
Transmits on CC #81.)";

    constexpr auto osc_2_sync_description = u8R"(
Turns hard oscillator sync on or off. When
turned on, every time oscillator 1 resets
it forces oscillator 2 to reset as well.
Transmits on CC #80.)";

    constexpr auto osc_shape_description = u8R"(
Modifies oscillator _’s base waveform:
• Adds complexity to triangle / sawtooth waves.
• Changes the pulse width of square waves.
Transmits on CC #%%. Range: 0 to 1023.)";

    constexpr auto osc_wave_description = u8R"(
Selects oscillator _’s base waveform.
Transmits on CC #%%.
Choices: square, triangle, sawtooth.)";

    constexpr auto voice_mode_depth_description = u8R"(
Controls a specific parameter
unique to each voice mode.
Transmits on CC #27.
The range of choices depends
on which mode is active.)";

}