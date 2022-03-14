#pragma once

#include <JuceHeader.h>

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllStepsInSeqTrack.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllVoiceNameChars.h"
#include "../widgets_Button/widget_Randomization_ButtonForRandomizingUnlockedParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllStepsInSeqTrack.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllVoiceNameChars.h"



class UnexposedParameters;

class RandomizationComponent :
	public Component,
	public Button::Listener,
	private Timer
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	ButtonForLockingAllParameters button_ForLockingAllParameters;
	ButtonForUnlockingAllParameters button_ForUnlockingAllParameters;
	ButtonForLockingAllVoiceNameChars button_ForLockingAllVoiceNameChars;
	ButtonForUnlockingAllVoiceNameChars button_ForUnlockingAllVoiceNameChars;
	ButtonForLockingAllStepsInSeqTrack button_ForLockingAllStepsInSeqTrack1;
	ButtonForUnlockingAllStepsInSeqTrack button_ForUnlockingAllStepsInSeqTrack1;
	ButtonForLockingAllStepsInSeqTrack button_ForLockingAllStepsInSeqTrack2;
	ButtonForUnlockingAllStepsInSeqTrack button_ForUnlockingAllStepsInSeqTrack2;
	ButtonForLockingAllStepsInSeqTrack button_ForLockingAllStepsInSeqTrack3;
	ButtonForUnlockingAllStepsInSeqTrack button_ForUnlockingAllStepsInSeqTrack3;
	ButtonForLockingAllStepsInSeqTrack button_ForLockingAllStepsInSeqTrack4;
	ButtonForUnlockingAllStepsInSeqTrack button_ForUnlockingAllStepsInSeqTrack4;
	ButtonForRandomizingUnlockedParameters button_ForRandomizingUnlockedParameters;
	TextButton button_ForClosingRandomizationComponent;

public:
	ToggleButton paramLockToggleButtons[InfoForExposedParameters::numberOfExposedParameters];
	RandomizationComponent() = delete;

	RandomizationComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void setUpParamLockToggleButton(uint8 param);
	void paint(Graphics& g) override;
	void resized() override;
	void lockAllParameters();
	void unlockAllParameters();
	void lockAllStepsInSeqTrack(int trackNum);
	void unlockAllStepsInSeqTrack(int trackNum);
	void randomizeUnlockedParameters();
	void buttonClicked(Button* button) override;
	void hideThisComponent();

private:
	void timerCallback() override;


public:
	~RandomizationComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationComponent)
};