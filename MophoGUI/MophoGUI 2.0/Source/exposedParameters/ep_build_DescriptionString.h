#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;



struct DescriptionString
{
	static String buildFor_BendRange();
	static String buildFor_EnvAttack(EnvelopeType envType);
	static String buildFor_EnvDecay(EnvelopeType envType);
	static String buildFor_EnvDelay(EnvelopeType envType);
	static String buildFor_EnvRelease(EnvelopeType envType);
	static String buildFor_EnvSustain(EnvelopeType envType);
	static String buildFor_ExtInLevel();
	static String buildFor_GlideMode();
	static String buildFor_LPF_EnvAmount();
	static String buildFor_LPF_FM_Amount();
	static String buildFor_LPF_Freq();
	static String buildFor_LPF_KeyAmount();
	static String buildFor_LPF_Reso();
	static String buildFor_LPF_Type();
	static String buildFor_LPF_VelAmount();
	static String buildFor_NoiseLevel();
	static String buildFor_NotePriority();
	static String buildFor_OscFine(int oscNum);
	static String buildFor_OscGlide(int oscNum);
	static String buildFor_OscKeyTrack(int oscNum);
	static String buildFor_OscMix();
	static String buildFor_OscPitch(int oscNum);
	static String buildFor_OscShape(int oscNum);
	static String buildFor_OscSlop();
	static String buildFor_OscSubLevel(int oscNum);
	static String buildFor_OscSync();

private:
	static String buildEnvNameString(EnvelopeType envType);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DescriptionString)
};