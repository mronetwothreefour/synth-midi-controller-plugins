#pragma once

#include <JuceHeader.h>

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllLFOparameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllLPFparameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllOscParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllSeqTrackParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllVCAparameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllVoiceNameChars.h"
#include "../widgets_Button/widget_Randomization_ButtonForRandomizingUnlockedParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllLFOparameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllLPFparameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllOscParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllSeqTrackParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllVCAparameters.h"
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
	ButtonForLockingAllLPFparameters button_ForLockingAllLPFparameters;
	ButtonForUnlockingAllLPFparameters button_ForUnlockingAllLPFparameters;
	ButtonForLockingAllVCAparameters button_ForLockingAllVCAparameters;
	ButtonForLockingAllLFOparameters button_ForLockingAllLFO1parameters;
	ButtonForUnlockingAllLFOparameters button_ForUnlockingAllLFO1parameters;
	ButtonForLockingAllLFOparameters button_ForLockingAllLFO2parameters;
	ButtonForUnlockingAllLFOparameters button_ForUnlockingAllLFO2parameters;
	ButtonForLockingAllLFOparameters button_ForLockingAllLFO3parameters;
	ButtonForUnlockingAllLFOparameters button_ForUnlockingAllLFO3parameters;
	ButtonForLockingAllLFOparameters button_ForLockingAllLFO4parameters;
	ButtonForUnlockingAllLFOparameters button_ForUnlockingAllLFO4parameters;
	ButtonForUnlockingAllVCAparameters button_ForUnlockingAllVCAparameters;
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