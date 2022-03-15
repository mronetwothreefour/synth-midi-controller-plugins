#pragma once

#include <JuceHeader.h>

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllOscParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllSeqTrackParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllVoiceNameChars.h"
#include "../widgets_Button/widget_Randomization_ButtonForRandomizingUnlockedParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllOscParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllSeqTrackParameters.h"
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
	ButtonForLockingAllOscParameters button_ForLockingAllOscParameters;
	ButtonForUnlockingAllOscParameters button_ForUnlockingAllOscParameters;
	ButtonForLockingAllVoiceNameChars button_ForLockingAllVoiceNameChars;
	ButtonForUnlockingAllVoiceNameChars button_ForUnlockingAllVoiceNameChars;
	ButtonForLockingAllSeqTrackParameters button_ForLockingAllSeqTrack1Params;
	ButtonForUnlockingAllSeqTrackParameters button_ForUnlockingAllSeqTrack1Params;
	ButtonForLockingAllSeqTrackParameters button_ForLockingAllSeqTrack2Params;
	ButtonForUnlockingAllSeqTrackParameters button_ForUnlockingAllSeqTrack2Params;
	ButtonForLockingAllSeqTrackParameters button_ForLockingAllSeqTrack3Params;
	ButtonForUnlockingAllSeqTrackParameters button_ForUnlockingAllSeqTrack3Params;
	ButtonForLockingAllSeqTrackParameters button_ForLockingAllSeqTrack4Params;
	ButtonForUnlockingAllSeqTrackParameters button_ForUnlockingAllSeqTrack4Params;
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