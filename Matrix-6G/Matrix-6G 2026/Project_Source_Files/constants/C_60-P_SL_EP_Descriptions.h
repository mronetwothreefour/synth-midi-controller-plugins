#pragma once

namespace SL
{

    constexpr auto env_amp_description = u8R"(
Sets the maximum output level of envelope _, which determines
the degree to which the envelope modulates its destination(s).
Range: 0 (no modulation) to 63 (maximum modulation).)";

    constexpr auto env_attack_description = u8R"(
Sets the length of envelope _’s attack
stage (the amount of time it takes to
rise from minimum to maximum level).
Range: 0 (instantaneous) to 63 (longest).)";

    constexpr auto env_decay_description = u8R"(
Sets the length of envelope _’s decay stage
(the amount of time it takes to drop from the
maximum level to the sustain level).
Range: 0 (instantaneous) to 63 (longest).)";

    constexpr auto env_delay_description = u8R"(
Sets the length of envelope _’s delay stage
(the amount of time, after the envelope is
triggered, before the attack stage begins).
Range: 0 (instantaneous) to 63 (longest).)";

    constexpr auto env_lfo_1_trig_description = u8R"(
Selects whether and how envelope _’s cycle is triggered by LFO 1.
• NORMAL: The envelope’s cycle is not triggered by LFO 1.
• G-LFO1 (gated LFO 1 trigger): one or more notes must be gated
on before LFO 1 will periodically trigger the envelope’s cycle.
• LFO 1: The envelope’s cycle is periodically triggered by LFO 1.
Note: The LFO 1 retrigger point parameter sets the exact point
in LFO 1’s cycle where the envelope’s cycle gets triggered.)";

    constexpr auto env_mode_description = u8R"(
Selects how envelope _ will proceed through its cycle when triggered.
• NORMAL: When a note is gated on and the envelope is triggered, the cycle will
run through the delay, attack, and decay stages, then hold at the sustain level.
Gating off the note will immediately trigger the release stage, even if the 
sustain stage has not yet been reached.
• DADR (delay | attack | decay | release): The release stage begins immediately
after the decay stage, whether or not the voice is still gated on. Gating off
the voice before the other stages complete will also start the release stage.
• FREE (free run): The envelope will completely run through the delay, attack,
decay, and release stages, whether or not the note is kept gated on. Keeping
the note gated on will hold the sustain level normally.
• BOTH (DADR plus free run): Like free run mode, except the release stage 
begins immediately after the decay stage, even if the note is still gated on.)";

    constexpr auto env_release_description = u8R"(
Sets the length of envelope _’s release
stage (the amount of time it takes to drop
from the sustain level to the minimum level).
Range: 0 (instantaneous) to 63 (longest).)";

    constexpr auto env_sustain_description = u8R"(
Sets envelope _’s sustain level. After the
decay stage completes, output will remain
at this level until the voice is gated off. 
Range: 0 (minimum) to 63 (maximum).)";

    constexpr auto env_trig_mode_description = u8R"(
Selects how envelope _’s cycle gets triggered and how it proceeds.
• STRIG (single trigger) (unison mode only): The cycle will start for a
voice only if it is not already playing. Legato playing will not re-trigger
the cycle. If the envelope is re-triggered before its cycle completes, it
will continue from the point it was previously at in its cycle.
• SRESET (single trigger reset): Like single trigger mode except that, if
the envelope is re-triggered before its cycle completes, the cycle restarts.
• MTRIG (multiple trigger): New notes will always re-trigger the envelope,
and it will continue from the point it was previously at in its cycle.
• MRESET: (multiple trigger reset): New notes will always re-trigger
the envelope and restart it from the beginning of its cycle.
The ‘X’ modes behave like their counterparts above, but the cycle trigger is
an external DC pulse (typically from a footswitch) sent into the PEDAL 2 jack:
• XTRIG (external single trigger) | • XRESET (external single trigger reset)
• XMTRIG (external multiple trigger) | • XMRST (external multiple trigger reset))";

    constexpr auto env_velo_amt_description = u8R"(
Sets whether and to what degree note
velocity modulates envelope _’s amplitude.
Range: -63 to +63. 0 is no modulation.
Negative values invert the velocity response.
Note: Negative values cannot be transmitted to
individual parameters via quick patch edit. Send
the entire patch using the PUSH button instead.)";

    constexpr auto keyboard_mode_description = u8R"(
Selects how notes get assigned to the device’s six available voices.
• REASGN (reassign): Once a note is assigned to a specific voice,
it will be reassigned to that same voice every time it is played.
• ROTATE (rotate): The device cycles through the six voices,
assigning each newly played note to the next available voice.
• UNISON (monophonic unison): Each note triggers all six voices and
only one note can be played at a time. If multiple notes are played
together, only the lowest note will be heard.
• REAROB (reassign rob): Like reassign mode, but if all six
voices are sounding and a new note is played, the new note will
‘rob’ a voice from one of the notes that are already playing.)";

    constexpr auto lfo_1_pressure_amt_description = u8R"(
Sets whether and to what degree keyboard
pressure (aftertouch) modulates the speed of
LFO 1. Range: -63 to +63. 0 is no modulation.
Negative values invert the pressure response.
Note: Negative values cannot be transmitted to
individual parameters via quick patch edit. Send
the entire patch using the PUSH button instead.)";

    constexpr auto lfo_2_key_track_amt_description = u8R"(
Sets whether and to what degree keyboard position
modulates the speed of LFO 2. Range: -63 to +63.
0 is no modulation. Negative values invert the
key position response. Note: Negative values
cannot be transmitted to individual parameters
via quick patch edit. Send the entire patch
using the PUSH button instead.)";

    constexpr auto lfo_amp_description = u8R"(
Sets the degree to which LFO _ modulates its destination(s).
Range: 0 (no modulation) to 63 (maximum modulation).)";

    constexpr auto lfo_lag_description = u8R"(
The lag processor, which smooths pitch transitions for portamento,
can also be used to smooth the transitions in LFO _’s wave cycle.
The effect will be most apparent on a square wave cycle.)";

    constexpr auto lfo_ramp_amt_description = u8R"(
Sets whether and to what degree
ramp _ modulates LFO _’s amplitude.
Range: -63 to +63. 0 is no modulation.
Negative values invert the ramp.
Note: Negative values cannot be
transmitted to individual parameters
via quick patch edit. Send the entire
patch using the PUSH button instead.)";

    constexpr auto lfo_retrig_point_description = u8R"(
When LFO _ is set (above) to be triggered by the keyboard or by an
external source, this moves the starting point in the LFO’s cycle.
Range: 0 (beginning of the cycle) to 63 (the cycle’s half-way point).)";

    constexpr auto lfo_sample_source_description = u8R"(
Selects the modulation source that LFO _ will
periodically sample to calculate its output value
(when its wave type (above) is set to sample).)";

    constexpr auto lfo_speed_description = u8R"(
Sets the cycle rate of low-frequency oscillator _.
Range: 0 (slowest) to 63 (fastest).)";

    constexpr auto lfo_trig_mode_description = u8R"(
Selects the type of trigger that will start LFO _’s wave cycle.
• OFF: The LFO is not triggered and cycles freely.
• STRIG (single): A new note triggers the LFO only when no other
notes are currently held down (only active in unison mode).
• MTRIG (multiple): The LFO is triggered with every new note played.
• XTRIG (external): An external signal (e.g. a footswitch) triggers the LFO.)";

    constexpr auto lfo_wave_type_description = u8R"(
Selects the type of modulation signal that LFO _ generates.
• TRI (triangle): A periodic wave that steadily rises and falls
between its minimum and maximum values.
• UPSAW (up or rising sawtooth): A periodic wave that rises steadily
to the maximum value then abruptly returns to the minimum value.
• DNSAW (down or falling sawtooth): A periodic wave that falls steadily
to the minimum value then abruptly returns to the maximum value.
• SQUAR (square): A periodic wave that switches abruptly between
the minimum and maximum values.
• RANDM (random): An aperiodic wave that outputs a series of random values.
• NOISE (noise): A much faster version of the random waveform.
• SAMPL (sampled): The LFO’s waveform is created by periodically sampling
the value of another modulation source. Select the sample source below.
The sampling rate is determined by the LFO’s speed setting (above).)";

    constexpr auto osc_1_sync_description = u8R"(
Selects whether and to what degree oscillator 1’s
waveform is synchronized with oscillator 2’s.)";

    constexpr auto osc_2_detune_description = u8R"(
Slightly lowers or raises oscillator 2’s pitch.
Range -31 to +31 (-/+ ~25 cents). 0 is no detune.
Note: Negative values cannot be transmitted to
individual parameters via quick patch edit. Send 
the entire patch using the PUSH button instead.)";

    constexpr auto osc_balance_description = u8R"(
Sets the relative levels of the two oscillators.
Range: 0 to 63. At 63, only oscillator 1 is heard.
At 0, only oscillator 2 is heard. 31 is an equal mix.)";

    constexpr auto osc_key_click_description = u8R"(
Adds percussive punch to
the start of the sound.)";

    constexpr auto osc_1_key_track_description = u8R"(
Selects how oscillator 1 responds to incoming pitch change
messages (such as notes played on a keyboard controller).
• KEYBD: Oscillater 1’s pitch tracks note key changes normally.
• PORTA: Tracking is active, but transitions between pitches are
smoothed according to the settings in the Portamento section.)";

    constexpr auto osc_2_key_track_description = u8R"(
Selects how oscillator 2 responds to incoming pitch change
messages (such as notes played on a keyboard controller).
• OFF: Oscillater 2’s pitch will not change as notes are played.
• PORTA: Tracking is active, but transitions between pitches are
smoothed according to the settings in the Portamento section.
• KEYBD: Oscillator 2’s pitch tracks note key changes normally.)";

    constexpr auto osc_lever_control_description = u8R"(
Selects which of the performance ‘levers’
(wheel-type controllers) modulate oscillator _.
OFF: Oscillator _ is not modulated by either lever.
BEND: Pitch bend is modulated by lever 1 (pitch wheel).
VIB: Vibrato amount is modulated by lever 2 (mod wheel).
BOTH: Oscillator _ is modulated by both levers.)";

    constexpr auto osc_lfo_1_fm_description = u8R"(
Sets whether and to what degree LFO 1
modulates the pitch of oscillator _.
Range: -63 to +63. 0 is no modulation.
Negative values invert the LFO waveform.
Note: Negative values cannot be
transmitted to individual parameters
via quick patch edit. Send the entire
patch using the PUSH button instead.)";

    constexpr auto osc_lfo_2_pwm_description = u8R"(
Sets whether and to what degree LFO 2
modulates the pulse width of oscillator _.
Range: -63 to +63. 0 is no modulation.
Negative values invert the LFO waveform.
Note: Negative values cannot be
transmitted to individual parameters
via quick patch edit. Send the entire
patch using the PUSH button instead.)";

    constexpr auto osc_pitch_description = u8R"(
Sets oscillator _’s base pitch in semitone steps.
Range: 0 (C 0) to 63 (D# 5). Hold down the
SHIFT key when using the mouse wheel to incre-
ment the pitch by one octave (12 semitones).)";

    constexpr auto osc_pulse_w_description = u8R"(
Sets the width of oscillator _’s
wave when its type is set to pulse.
Range: 0 (very wide) to 63 (very narrow).
A value of 31 produces a square wave.)";

    constexpr auto osc_saw_tri_description = u8R"(
Sets the shape of oscillator _
when its type is set to wave.
Range: 0 (sawtooth) to 63 (triangle).
Intermediate values produce
blends of these two shapes.)";

    constexpr auto osc_type_description = u8R"(
Selects oscillator _’s wave type.
• OFF: The oscillator produces no sound.
• PULSE: Set the width of the pulse below.
• WAVE: Set the shape of the wave below.
• BOTH: A blend of pulse and wave.
• NOISE: White noise (oscillator 2 only).)";

    constexpr auto porta_legato_description = u8R"(
When legato is on, portamento will only be active
when a new note is played prior to releasing the
previous note. This behavior is only active when
the keyboard mode is set to unison.)";

    constexpr auto porta_mode_description = u8R"(
Selects how the portamento transition rate is calculated.
LINEAR: The time it takes to transition between two pitches
is proportional to the distance between them.
CONSTANT: The time it takes to transition between two pitches
is the same regardless of the distance between them.
EXPO (exponential): The transition between pitches starts out
fast, then slows down as it approaches the destination pitch.)";

    constexpr auto porta_rate_description = u8R"(
Adjusts the amount of time it takes to transition
from the origin pitch to the destination pitch.
Range: 0 (instantaneous) to 63 (longest).)";

    constexpr auto porta_velo_description = u8R"(
Sets whether and to what degree note
velocity modulates the portamento rate.
Range: -63 to +63. 0 is no modulation.
Negative values invert the velocity response.
Note: Negative values cannot be transmitted to
individual parameters via quick patch edit. Send
the entire patch using the PUSH button instead.)";

}