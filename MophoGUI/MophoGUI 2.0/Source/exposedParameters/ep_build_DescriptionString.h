#pragma once

#include <JuceHeader.h>



struct DescriptionString
{
	static String buildFor_BendRange();
	static String buildFor_ExtInLevel();
	static String buildFor_GlideMode();
	static String buildFor_LPF_Freq();
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
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DescriptionString)
};