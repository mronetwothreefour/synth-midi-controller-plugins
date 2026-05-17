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
to exact semitones (i.e. 100, 200, 300, ...).
Transmits on CC #%%. Range: -1200 to +1200.)";

    constexpr auto osc_shape_description = u8R"(
Modifies oscillator _’s base waveform:
• Adds complexity to triangle / sawtooth waves.
• Changes the pulse width of square waves.
Transmits on CC #%%. Range: 0 to 1023.)";

    constexpr auto osc_wave_description = u8R"(
Selects oscillator _’s base waveform.
Transmits on CC #%%.
Choices: square, triangle, sawtooth.)";

}