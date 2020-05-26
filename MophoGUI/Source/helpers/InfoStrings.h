#pragma once

#include <JuceHeader.h>

// Provides functionality for generating a description 
// of what a control does, used when creating tooltips
struct MophoParameterTooltipGenerator : MophoParameterValueConverter
{
	// Returns a description of what the specified
	// control does as well as its range (for knob controls)
	String getInfoString(int ctrlIndex) const noexcept
	{
		switch (ctrlIndex)
		{
		// buttons
		case MophoParameterIndex::oscSync:
			return "Turns oscillator sync on or off. When\nturned on, every time oscillator 2 resets\nit forces oscillator 1 to reset as well.";

		case MophoParameterIndex::osc1KeyTrack:
			return "Turns keyboard tracking for oscillator 1\non or off. When turned off, oscillator 1\nalways produces its base pitch, unaffected\nby the pitch of incoming MIDI notes.\n";

		case MophoParameterIndex::osc2KeyTrack:
			return "Turns keyboard tracking for oscillator 2\non or off. When turned off, oscillator 2\nalways produces its base pitch, unaffected\nby the pitch of incoming MIDI notes.\n";

		case MophoParameterIndex::env3Repeat:
			return "When repeat is on, envelope 3 loops through\nits delay, attack, decay, and sustain segments\nfor as long as the envelope is gated on.\n";

		case MophoParameterIndex::arpegOnOff:
			return "Turns the Mopho's arpeggiator on and off.\nTurning this on will turn off the sequencer.";

		case MophoParameterIndex::lpfType:
			return "Switches the low-pass filter type between 2-Pole and 4-Pole.\nWhen set to 4-pole, the filter has a steeper cutoff frequency\nslope and more pronounced resonance.";

		case MophoParameterIndex::lfo1KeySync:
			return "When on, LFO 1's cycle will re-start\neach time a new note is played.";

		case MophoParameterIndex::lfo2KeySync:
			return "When on, LFO 2's cycle will re-start\neach time a new note is played.";

		case MophoParameterIndex::lfo3KeySync:
			return "When on, LFO 3's cycle will re-start\neach time a new note is played.";

		case MophoParameterIndex::lfo4KeySync:
			return "When on, LFO 4's cycle will re-start\neach time a new note is played.";

		case MophoParameterIndex::sequencerOnOff:
			return "Turns the Mopho's sequencer on and off.\nTurning this on will turn off the arpeggiator.";

		// Knobs
		case MophoParameterIndex::osc1Pitch:
			return "Sets oscillator 1's base pitch in semitone steps.\nRange: C 0 (8 Hz) to C 10 (8 KHz). Middle C is C 5.";

		case MophoParameterIndex::osc1Fine:
			return "Fine tunes oscillator 1's base pitch.\nRange: -50 cents to +50 cents.\n0 = no detuning (centered).";

		case MophoParameterIndex::osc1Shape:
			return "Selects oscillator 1's wave shape.\nAvailable options: Off; Sawtooth; Triangle;\nSawtooth/Triangle Mix; Pulse (Width 0 to 99).\nA Pulse with width 50 is a square wave.";

		case MophoParameterIndex::osc1Glide:
			return "Sets oscillator 1's glide (portamento) rate.\nRange: 0 (fastest) to 127 (slowest)";

		case MophoParameterIndex::osc1SubLevel:
			return "Sets the level of sub-oscillator 1,\nwhich generates a square wave pitched\none octave below oscillator 1.\nRange: 0 to 127.";

		case MophoParameterIndex::osc2Pitch:
			return "Sets oscillator 2's base pitch in semitone steps.\nRange: C 0 (8 Hz) to C 10 (8 KHz). Middle C is C 5.";

		case MophoParameterIndex::osc2Fine:
			return "Fine tunes oscillator 2's base pitch.\nRange: -50 cents to +50 cents.\n0 = no detuning (centered).";

		case MophoParameterIndex::osc2Shape:
			return "Selects oscillator 2's wave shape.\nAvailable options: Off; Sawtooth; Triangle;\nSawtooth/Triangle Mix; Pulse (Width 0 to 99).\nA Pulse with width 50 is a square wave.";

		case MophoParameterIndex::osc2Glide:
			return "Sets oscillator 2's glide (portamento) rate.\nRange: 0 (fastest) to 127 (slowest)";

		case MophoParameterIndex::osc2SubLevel:
			return "Sets the level of sub-oscillator 2,\nwhich generates a square wave pitched\none octave below oscillator 2.\nRange: 0 to 127.";

		case MophoParameterIndex::oscSlop:
			return "Introduces subtle amounts of random oscillator\npitch drift for a \"vintage analog\" sound.\nRange: 0 to 5.";

		case MophoParameterIndex::oscMix:
			return "Controls the level balance between oscillators 1 & 2.\nRange: 0 to 127. At 0, only oscillator 1 is heard.\nAt 127, only oscillator 2 is heard. At 64, an equal\nmix of the two oscillators is heard.";

		case MophoParameterIndex::bendRange:
			return "Sets the maximum amount (in semitones) by which pitch wheel\nmessages can raise or lower the pitches of the oscillators.\nRange: 0 (no bend) to +/-12 semitones.";

		case MophoParameterIndex::noiseLevel:
			return "Sets the level of white noise\nsent into the low-pass filter.\nRange: 0 to 127.";

		case MophoParameterIndex::extInLevel:
			return "Sets the level of external audio\ninput sent into the low-pass filter.\nWhen nothing is connected to audio in,\nthis controls the level of feedback\nfrom the left audio output.\nRange: 0 to 127.";

		case MophoParameterIndex::lpfFreq:
			return "Sets the base cutoff frequency for the\nlow-pass filter (in semitone steps).\nRange: 0 (C 0) to 164 (G# 13).\n";

		case MophoParameterIndex::lpfReso:
			return "Sets the resonance level of the low-pass\nfilter. When in 4-pole mode, high settings\nwill cause the filter to self-oscillate.\nRange: 0 to 127.";

		case MophoParameterIndex::lpfEnvAmount:
			return "Sets the degree to which the LPF envelope\nmodulates the filter's cutoff frequency.\nNegative values invert the envelope.\nRange: -127 to +127.";

		case MophoParameterIndex::lpfVelAmount:
			return "Sets the degree to which MIDI note velocity modulates\nthe amplitude of the low-pass filter's envelope.\nRange: 0 to 127.";

		case MophoParameterIndex::lpfKeyAmount:
			return "Sets the amount by which keyboard (MIDI) notes\nwill shift the low-pass filter's cutoff frequency.\nRange: 0 to 127. At 64, cutoff is shifted by one\nsemitone for each note. At 32, cutoff is shifted\nby one half-semitone for each note.";

		case MophoParameterIndex::lpfFMamount:
			return "Sets the degree to which oscillator 1 modulates\nthe low-pass filter's cutoff frequency. This is\nuseful for generating bell-like sounds.\nRange: 0 to 127.";

		case MophoParameterIndex::lpfDelay:
			return "Sets the length of the LPF envelope's delay segment\n(the amount of time that passes after the envelope\nis triggered before its attack segment begins).\nRange: 0 to 127.";

		case MophoParameterIndex::lpfAttack:
			return "Sets the length of the LPF envelope's attack segment\n(the amount of time it takes for the envelope's\nlevel to rise from minimum to maximum).\nRange: 0 to 127.";

		case MophoParameterIndex::lpfDecay:
			return "Sets the length of the LPF envelope's decay segment\n(the amount of time it takes for the envelope's\nlevel to fall from maximum to the sustain level).\nRange: 0 to 127.";

		case MophoParameterIndex::lpfSustain:
			return "Sets the LPF envelope's sustain level (once the\ndecay segment completes, the envelope stays\nat this level until it is gated off).\nRange: 0 to 127.";

		case MophoParameterIndex::lpfRelease:
			return "Sets the length of the LPF envelope's release segment\n(the amount of time it takes to fall from the sustain\nlevel down to minimum once the envelope is gated off).\nRange: 0 to 127.";

		case MophoParameterIndex::vcaLevel:
			return "Sets the voltage-controlled amplifier's baseline level. Turn this\nup for droning sounds or when processing external audio input.\nWhen this level is set to 127, the VCA envelope has no effect.\nRange: 0 to 127.";

		case MophoParameterIndex::vcaEnvAmount:
			return "Sets the degree to which the VCA envelope\nmodulates the voltage-controlled ampifier's level.\nRange: 0 to 127.";

		case MophoParameterIndex::vcaVelAmount:
			return "Sets the degree to which MIDI note velocity modulates\nthe amplitude of the voltage-controlled ampifier's envelope.\nRange: 0 to 127.";

		case MophoParameterIndex::pgmVolume:
			return "Sets the overall gain of the current program.\nRange: 0 to 127.";

		case MophoParameterIndex::vcaDelay:
			return "Sets the length of the VCA envelope's delay segment\n(the amount of time that passes after the envelope\nis triggered before its attack segment begins).\nRange: 0 to 127.";

		case MophoParameterIndex::vcaAttack:
			return "Sets the length of the VCA envelope's attack segment\n(the amount of time it takes for the envelope's\nlevel to rise from minimum to maximum).\nRange: 0 to 127.";

		case MophoParameterIndex::vcaDecay:
			return "Sets the length of the VCA envelope's decay segment\n(the amount of time it takes for the envelope's\nlevel to fall from maximum to the sustain level).\nRange: 0 to 127.";

		case MophoParameterIndex::vcaSustain:
			return "Sets the VCA envelope's sustain level (once the\ndecay segment completes, the envelope stays\nat this level until it is gated off).\nRange: 0 to 127.";

		case MophoParameterIndex::vcaRelease:
			return "Sets the length of the VCA envelope's release segment\n(the amount of time it takes to fall from the sustain\nlevel down to minimum once the envelope is gated off).\nRange: 0 to 127.";

		case MophoParameterIndex::env3Amount:
			return "Sets the degree to which Envelope 3\nmodulates the destination parameter.\nNegative values invert the envelope.\nRange: -127 to +127.";

		case MophoParameterIndex::env3VelAmount:
			return "Sets the degree to which MIDI note velocity\nmodulates the amplitude of envelope 3.\nRange: 0 to 127.";

		case MophoParameterIndex::env3Delay:
			return "Sets the length of envelope 3's delay segment\n(the amount of time that passes after the envelope\nis triggered before its attack segment begins).\nRange: 0 to 127.";

		case MophoParameterIndex::env3Attack:
			return "Sets the length of envelope 3's attack segment\n(the amount of time it takes for the envelope's\nlevel to rise from minimum to maximum).\nRange: 0 to 127.";

		case MophoParameterIndex::env3Decay:
			return "Sets the length of envelope 3's decay segment\n(the amount of time it takes for the envelope's\nlevel to fall from maximum to the sustain level).\nRange: 0 to 127.";

		case MophoParameterIndex::env3Sustain:
			return "Sets envelope 3's sustain level (once the\ndecay segment completes, the envelope stays\nat this level until it is gated off).\nRange: 0 to 127.";

		case MophoParameterIndex::env3Release:
			return "Sets the length of envelope 3's release segment\n(the amount of time it takes to fall from the sustain\nlevel down to minimum once the envelope is gated off).\nRange: 0 to 127.";

		case MophoParameterIndex::mod1Amount:
			return "Sets the degree to which the selected source\nmodulates the selected destination parameter.\nNegative values invert the modulation.\nRange: -127 to +127.";

		case MophoParameterIndex::mod2Amount:
			return "Sets the degree to which the selected source\nmodulates the selected destination parameter.\nNegative values invert the modulation.\nRange: -127 to +127.";

		case MophoParameterIndex::mod3Amount:
			return "Sets the degree to which the selected source\nmodulates the selected destination parameter.\nNegative values invert the modulation.\nRange: -127 to +127.";

		case MophoParameterIndex::mod4Amount:
			return "Sets the degree to which the selected source\nmodulates the selected destination parameter.\nNegative values invert the modulation.\nRange: -127 to +127.";

		case MophoParameterIndex::modWheelAmount:
			return "Sets the degree to which MIDI modulation wheel\ncontroller messages (CC#1) modulate the destination parameter.\nNegative values invert the modulation.\nRange: -127 to +127.";

		case MophoParameterIndex::pressureAmount:
			return "Sets the degree to which MIDI channel pressure\n(aftertouch) messages modulate the destination parameter.\nNegative values invert the modulation.\nRange: -127 to +127.";

		case MophoParameterIndex::breathAmount:
			return "Sets the degree to which MIDI breath\ncontroller messages (CC#2) modulate the destination parameter.\nNegative values invert the modulation.\nRange: -127 to +127.";

		case MophoParameterIndex::velocityAmount:
			return "Sets the degree to which MIDI note\nvelocity messages modulate the destination parameter.\nNegative values invert the modulation.\nRange: -127 to +127.";

		case MophoParameterIndex::footPedalAmount:
			return "Sets the degree to which MIDI foot pedal\ncontroller messages (CC#4) modulate the destination parameter.\nNegative values invert the modulation.\nRange: -127 to +127.";

		case MophoParameterIndex::lfo1Amount:
			return "Sets the degree to which LFO 1\nmodulates the destination parameter.\nRange: 0 to 127.";

		case MophoParameterIndex::lfo1Freq:
			return "Sets LFO 1's cycle speed. Range: 0 to 166.\nAt 0, 1 cycle lasts 30 sec. At 89, the frequency is almost 8 Hz.\nFrom 90 to 150, LFO 1 has a pitched frequency, increasing\nin semitones steps from C 0 (8 Hz) up to C 5 (261 Hz).\nAbove 150, LFO 1 is synced with the step sequencer,\ndisplayed as [number of cycles] : [length in steps].\n";

		case MophoParameterIndex::lfo2Amount:
			return "Sets the degree to which LFO 2\nmodulates the destination parameter.\nRange: 0 to 127.";

		case MophoParameterIndex::lfo2Freq:
			return "Sets LFO 2's cycle speed. Range: 0 to 166.\nAt 0, 1 cycle lasts 30 sec. At 89, the frequency is almost 8 Hz.\nFrom 90 to 150, LFO 2 has a pitched frequency, increasing\nin semitones steps from C 0 (8 Hz) up to C 5 (261 Hz).\nAbove 150, LFO 2 is synced with the step sequencer,\ndisplayed as [number of cycles] : [length in steps].\n";

		case MophoParameterIndex::lfo3Amount:
			return "Sets the degree to which LFO 3\nmodulates the destination parameter.\nRange: 0 to 127.";

		case MophoParameterIndex::lfo3Freq:
			return "Sets LFO 3's cycle speed. Range: 0 to 166.\nAt 0, 1 cycle lasts 30 sec. At 89, the frequency is almost 8 Hz.\nFrom 90 to 150, LFO 3 has a pitched frequency, increasing\nin semitones steps from C 0 (8 Hz) up to C 5 (261 Hz).\nAbove 150, LFO 3 is synced with the step sequencer,\ndisplayed as [number of cycles] : [length in steps].\n";

		case MophoParameterIndex::lfo4Amount:
			return "Sets the degree to which LFO 4\nmodulates the destination parameter.\nRange: 0 to 127.";

		case MophoParameterIndex::lfo4Freq:
			return "Sets LFO 4's cycle speed. Range: 0 to 166.\nAt 0, 1 cycle lasts 30 sec. At 89, the frequency is almost 8 Hz.\nFrom 90 to 150, LFO 4 has a pitched frequency, increasing\nin semitones steps from C 0 (8 Hz) up to C 5 (261 Hz).\nAbove 150, LFO 4 is synced with the step sequencer,\ndisplayed as [number of cycles] : [length in steps].\n";

		case MophoParameterIndex::clockTempo:
			return "Sets the tempo for the sequencer and\nthe arpeggiator (in beats per minute).";

		case MophoParameterIndex::pushItPitch:
			return "Sets the note that plays when\nthe Push It! switch is pressed.";

		case MophoParameterIndex::pushItVelocity:
			return "Sets the velocity of the note that plays\nwhen the Push It! switch is pressed.";

		case MophoParameterIndex::nameChar1:
			return "To change character 1 of the program's name,\nclick-and-drag the character or hover over it and turn the mouse wheel.";

		case MophoParameterIndex::nameChar2:
			return "To change character 2 of the program's name,\nclick-and-drag the character or hover over it and turn the mouse wheel.";

		case MophoParameterIndex::nameChar3:
			return "To change character 3 of the program's name,\nclick-and-drag the character or hover over it and turn the mouse wheel.";

		case MophoParameterIndex::nameChar4:
			return "To change character 4 of the program's name,\nclick-and-drag the character or hover over it and turn the mouse wheel.";

		case MophoParameterIndex::nameChar5:
			return "To change character 5 of the program's name,\nclick-and-drag the character or hover over it and turn the mouse wheel.";

		case MophoParameterIndex::nameChar6:
			return "To change character 6 of the program's name,\nclick-and-drag the character or hover over it and turn the mouse wheel.";

		case MophoParameterIndex::nameChar7:
			return "To change character 7 of the program's name,\nclick-and-drag the character or hover over it and turn the mouse wheel.";

		case MophoParameterIndex::nameChar8:
			return "To change character 8 of the program's name,\nclick-and-drag the character or hover over it and turn the mouse wheel.";

		case MophoParameterIndex::nameChar9:
			return "To change character 9 of the program's name,\nclick-and-drag the character or hover over it and turn the mouse wheel.";

		case MophoParameterIndex::nameChar10:
			return "To change character 10 of the program's name,\nclick-and-drag the character or hover over it and turn the mouse wheel.";

		case MophoParameterIndex::nameChar11:
			return "To change character 11 of the program's name,\nclick-and-drag the character or hover over it and turn the mouse wheel.";

		case MophoParameterIndex::nameChar12:
			return "To change character 12 of the program's name,\nclick-and-drag the character or hover over it and turn the mouse wheel.";

		case MophoParameterIndex::nameChar13:
			return "To change character 13 of the program's name,\nclick-and-drag the character or hover over it and turn the mouse wheel.";

		case MophoParameterIndex::nameChar14:
			return "To change character 14 of the program's name,\nclick-and-drag the character or hover over it and turn the mouse wheel.";

		case MophoParameterIndex::nameChar15:
			return "To change character 15 of the program's name,\nclick-and-drag the character or hover over it and turn the mouse wheel.";

		case MophoParameterIndex::nameChar16:
			return "To change character 16 of the program's name,\nclick-and-drag the character or hover over it and turn the mouse wheel.";

		case MophoParameterIndex::track1Step1:
			return "Sets the value that sequencer track 1's destination parameter has at step 1,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 1).";

		case MophoParameterIndex::track1Step2:
			return "Sets the value that sequencer track 1's destination parameter has at step 2,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 1).";

		case MophoParameterIndex::track1Step3:
			return "Sets the value that sequencer track 1's destination parameter has at step 3,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 1).";

		case MophoParameterIndex::track1Step4:
			return "Sets the value that sequencer track 1's destination parameter has at step 4,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 1).";

		case MophoParameterIndex::track1Step5:
			return "Sets the value that sequencer track 1's destination parameter has at step 5,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 1).";

		case MophoParameterIndex::track1Step6:
			return "Sets the value that sequencer track 1's destination parameter has at step 6,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 1).";

		case MophoParameterIndex::track1Step7:
			return "Sets the value that sequencer track 1's destination parameter has at step 7,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 1).";

		case MophoParameterIndex::track1Step8:
			return "Sets the value that sequencer track 1's destination parameter has at step 8,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 1).";

		case MophoParameterIndex::track1Step9:
			return "Sets the value that sequencer track 1's destination parameter has at step 9,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 1).";

		case MophoParameterIndex::track1Step10:
			return "Sets the value that sequencer track 1's destination parameter has at step 10,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 1).";

		case MophoParameterIndex::track1Step11:
			return "Sets the value that sequencer track 1's destination parameter has at step 11,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 1).";

		case MophoParameterIndex::track1Step12:
			return "Sets the value that sequencer track 1's destination parameter has at step 12,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 1).";

		case MophoParameterIndex::track1Step13:
			return "Sets the value that sequencer track 1's destination parameter has at step 13,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 1).";

		case MophoParameterIndex::track1Step14:
			return "Sets the value that sequencer track 1's destination parameter has at step 14,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 1).";

		case MophoParameterIndex::track1Step15:
			return "Sets the value that sequencer track 1's destination parameter has at step 15,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 1).";

		case MophoParameterIndex::track1Step16:
			return "Sets the value that sequencer track 1's destination parameter has at step 16,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 1).";

		case MophoParameterIndex::track2Step1:
			return "Sets the value that sequencer track 2's destination parameter has at step 1,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track2Step2:
			return "Sets the value that sequencer track 2's destination parameter has at step 2,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track2Step3:
			return "Sets the value that sequencer track 2's destination parameter has at step 3,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track2Step4:
			return "Sets the value that sequencer track 2's destination parameter has at step 4,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track2Step5:
			return "Sets the value that sequencer track 2's destination parameter has at step 5,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track2Step6:
			return "Sets the value that sequencer track 2's destination parameter has at step 6,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track2Step7:
			return "Sets the value that sequencer track 2's destination parameter has at step 7,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track2Step8:
			return "Sets the value that sequencer track 2's destination parameter has at step 8,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track2Step9:
			return "Sets the value that sequencer track 2's destination parameter has at step 9,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track2Step10:
			return "Sets the value that sequencer track 2's destination parameter has at step 10,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track2Step11:
			return "Sets the value that sequencer track 2's destination parameter has at step 11,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track2Step12:
			return "Sets the value that sequencer track 2's destination parameter has at step 12,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track2Step13:
			return "Sets the value that sequencer track 2's destination parameter has at step 13,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track2Step14:
			return "Sets the value that sequencer track 2's destination parameter has at step 14,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track2Step15:
			return "Sets the value that sequencer track 2's destination parameter has at step 15,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track2Step16:
			return "Sets the value that sequencer track 2's destination parameter has at step 16,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track3Step1:
			return "Sets the value that sequencer track 3's destination parameter has at step 1,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track3Step2:
			return "Sets the value that sequencer track 3's destination parameter has at step 2,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track3Step3:
			return "Sets the value that sequencer track 3's destination parameter has at step 3,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track3Step4:
			return "Sets the value that sequencer track 3's destination parameter has at step 4,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track3Step5:
			return "Sets the value that sequencer track 3's destination parameter has at step 5,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track3Step6:
			return "Sets the value that sequencer track 3's destination parameter has at step 6,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track3Step7:
			return "Sets the value that sequencer track 3's destination parameter has at step 7,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track3Step8:
			return "Sets the value that sequencer track 3's destination parameter has at step 8,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track3Step9:
			return "Sets the value that sequencer track 3's destination parameter has at step 9,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track3Step10:
			return "Sets the value that sequencer track 3's destination parameter has at step 10,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track3Step11:
			return "Sets the value that sequencer track 3's destination parameter has at step 11,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track3Step12:
			return "Sets the value that sequencer track 3's destination parameter has at step 12,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track3Step13:
			return "Sets the value that sequencer track 3's destination parameter has at step 13,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track3Step14:
			return "Sets the value that sequencer track 3's destination parameter has at step 14,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track3Step15:
			return "Sets the value that sequencer track 3's destination parameter has at step 15,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track3Step16:
			return "Sets the value that sequencer track 3's destination parameter has at step 16,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track4Step1:
			return "Sets the value that sequencer track 4's destination parameter has at step 1,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track4Step2:
			return "Sets the value that sequencer track 4's destination parameter has at step 2,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track4Step3:
			return "Sets the value that sequencer track 4's destination parameter has at step 3,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track4Step4:
			return "Sets the value that sequencer track 4's destination parameter has at step 4,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track4Step5:
			return "Sets the value that sequencer track 4's destination parameter has at step 5,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track4Step6:
			return "Sets the value that sequencer track 4's destination parameter has at step 6,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track4Step7:
			return "Sets the value that sequencer track 4's destination parameter has at step 7,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track4Step8:
			return "Sets the value that sequencer track 4's destination parameter has at step 8,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track4Step9:
			return "Sets the value that sequencer track 4's destination parameter has at step 9,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track4Step10:
			return "Sets the value that sequencer track 4's destination parameter has at step 10,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track4Step11:
			return "Sets the value that sequencer track 4's destination parameter has at step 11,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track4Step12:
			return "Sets the value that sequencer track 4's destination parameter has at step 12,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track4Step13:
			return "Sets the value that sequencer track 4's destination parameter has at step 13,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track4Step14:
			return "Sets the value that sequencer track 4's destination parameter has at step 14,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track4Step15:
			return "Sets the value that sequencer track 4's destination parameter has at step 15,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";

		case MophoParameterIndex::track4Step16:
			return "Sets the value that sequencer track 4's destination parameter has at step 16,\nRange: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\nA \"+\" indicates that the pitch is a quarter tone higher than the displayed note.\nReset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.\nRest (127): The step produces no output. ALT-click a step to make it a rest\n(Rests are only available for the steps in sequencer track 4).";

		case MophoParameterIndex::masterTranspose:
			return "The base oscillator pitches for all programs.\nare raised or lowered by this amount.Range: -12 to +12 semitones.";

		case MophoParameterIndex::masterFineTune:
			return "The base oscillator pitches for all programs.\nare raised or lowered by this amount.\nRange: -50 to +50 cents.";

		case MophoParameterIndex::midiChannel:
			return "Sets the channel which the Mopho hardware\nuses to send and receive MIDI messages.\nRange: All Channels, Channel 1 to 16";

		default: return "error";
		}
	}

	String createTooltipString(int paramIndex, int paramType, const int& currentValue, const bool& shouldShowValueTip, const bool& shouldShowInfoTip) const noexcept
	{
		String tooltip{ "" };
		if (shouldShowValueTip)
			tooltip += "Current Value: " + convertIntToValueString(paramType, currentValue, true) + "\n";
		if (shouldShowInfoTip)
		{
			tooltip += getInfoString(paramIndex);
		}
		return tooltip;
	}
};