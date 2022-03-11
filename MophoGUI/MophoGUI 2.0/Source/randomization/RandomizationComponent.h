#pragma once

#include <JuceHeader.h>

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForRandomizingUnlockedParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllParameters.h"



class UnexposedParameters;

class RandomizationComponent :
	public Component,
	private Timer
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	ButtonForLockingAllParameters button_ForLockingAllParameters;
	ButtonForUnlockingAllParameters button_ForUnlockingAllParameters;
	ButtonForRandomizingUnlockedParameters button_ForRandomizingUnlockedParameters;
	TextButton button_ForClosingRandomizationComponent;
	ToggleButton paramLockToggleButtons[InfoForExposedParameters::numberOfExposedParameters];

public:
	RandomizationComponent() = delete;

	RandomizationComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void setUpParamLockToggleButton(uint8 param);
	void paint(Graphics& g) override;
	void resized() override;
	void lockAllParameters();
	void unlockAllParameters();
	void lockAllVoiceNameCharacters();
	void unlockAlVoicelNameCharacters();
	void lockAllStepsInSeqTrack(int trackNum);
	void unlockAllStepsInSeqTrack(int trackNum);
	void randomizeUnlockedParameters();
	void hideThisComponent();

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationComponent)
};