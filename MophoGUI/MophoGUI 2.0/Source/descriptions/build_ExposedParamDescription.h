#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;

struct ExposedParamDescription
{
	static String buildForArpegMode();
	static String buildForArpegOnOff();
	static String buildForBendRange();
	static String buildForClockDivision();
	static String buildForClockTempo();
	static String buildForEnvAttack(const EnvelopeType envType);
	static String buildForEnvDecay(const EnvelopeType envType);
	static String buildForEnvDelay(const EnvelopeType envType);
	static String buildForEnvRelease(const EnvelopeType envType);
	static String buildForEnvSustain(const EnvelopeType envType);
	static String buildForEnvVelAmount(const EnvelopeType envType);
	static String buildForEnv_3_Amount();
	static String buildForEnv_3_Repeat();
	static String buildForExtInLevel();
	static String buildForGlideMode();
	static String buildForKnobAssign(const int knobNum);
	static String buildForModAmount();
	static String buildForNoiseLevel();
	static String buildForNotePriority();
	static String buildForOscFine(const int oscNum);
	static String buildForOscGlide(const int oscNum);
	static String buildForOscKeyTrack(const int oscNum);
	static String buildForOscMix();
	static String buildForOscPitch(const int oscNum);
	static String buildForOscShape(const int oscNum);
	static String buildForOscSlop();
	static String buildForOscSubLevel(const int oscNum);
	static String buildForOscSync();
	static String buildForPushItMode();
	static String buildForPushItPitch();
	static String buildForPushItVelocity();
	static String buildForSeqOnOff();
	static String buildForSeqTrackDestination(const int trackNum);
	static String buildForSeqTrackStep(const int trackNum, int stepNum);
	static String buildForSeqTrigMode();
	static String buildForVoiceNameChar(const int charNum);
	static String buildForVoiceVolume();
	static String buildFor_LFO_Amount(const int lfoNum);
	static String buildFor_LFO_Freq(const int lfoNum);
	static String buildFor_LFO_KeySync(const int lfoNum);
	static String buildFor_LFO_Shape(const int lfoNum);
	static String buildFor_LPF_EnvAmount();
	static String buildFor_LPF_FM_Amount();
	static String buildFor_LPF_Freq();
	static String buildFor_LPF_KeyAmount();
	static String buildFor_LPF_Reso();
	static String buildFor_LPF_Type();
	static String buildFor_MIDI_BreathAmount();
	static String buildFor_MIDI_ModWheelAmount();
	static String buildFor_MIDI_PedalAmount();
	static String buildFor_MIDI_PressureAmount();
	static String buildFor_MIDI_VelocityAmount();
	static String buildFor_VCA_EnvAmount();
	static String buildFor_VCA_Level();

private:
	static String buildEnvNameString(const EnvelopeType envType);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamDescription)
};