#pragma once

#include <JuceHeader.h>

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllEnv3Parameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllKnobAssignParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllLFOparameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllLPFparameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllMIDIcontrollerParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllModulatorParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllOscParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllPushItParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllSeqTrackParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllVCAparameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForLockingAllVoiceNameChars.h"
#include "../widgets_Button/widget_Randomization_ButtonForRandomizingUnlockedParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForShowingOscOptions.h"
#include "../widgets_Button/widget_Randomization_ButtonForShowingLFOoptions.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllEnv3Parameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllKnobAssignParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllLFOparameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllLPFparameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllMIDIcontrollerParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllModulatorParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllOscParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllPushItParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllSeqTrackParameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllVCAparameters.h"
#include "../widgets_Button/widget_Randomization_ButtonForUnlockingAllVoiceNameChars.h"



class LFOfreqRandomizationOptionsComponent;
class OscillatorRandomizationOptionsComponent;
class RandomizationOptionsComponent_ValueRange;
class UnexposedParameters;

class RandomizationComponent :
	public Component,
	public Button::Listener
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	ButtonForLockingAllParameters button_ForLockingAllParameters;
	ButtonForUnlockingAllParameters button_ForUnlockingAllParameters;
	ButtonForLockingAllOscParameters button_ForLockingAllOscParameters;
	ButtonForUnlockingAllOscParameters button_ForUnlockingAllOscParameters;
	ButtonForShowingOscRandomizationOptions button_ForShowingOscRandomizationOptions;
	ButtonForLockingAllLPFparameters button_ForLockingAllLPFparameters;
	ButtonForUnlockingAllLPFparameters button_ForUnlockingAllLPFparameters;
	ButtonForLockingAllVCAparameters button_ForLockingAllVCAparameters;
	ButtonForUnlockingAllVCAparameters button_ForUnlockingAllVCAparameters;
	ButtonForLockingAllEnv3Parameters button_ForLockingAllEnv3Parameters;
	ButtonForUnlockingAllEnv3Parameters button_ForUnlockingAllEnv3Parameters;
	ButtonForLockingAllModulatorParameters button_ForLockingAllModulatorParams;
	ButtonForUnlockingAllModulatorParameters button_ForUnlockingAllModulatorParams;
	ButtonForLockingAllMIDIcontrollerParameters button_ForLockingAllMIDIcontrollerParams;
	ButtonForUnlockingAllMIDIcontrollerParameters button_ForUnlockingAllMIDIcontrollerParams;
	ButtonForLockingAllLFOparameters button_ForLockingAllLFO1parameters;
	ButtonForUnlockingAllLFOparameters button_ForUnlockingAllLFO1parameters;
	ButtonForLockingAllLFOparameters button_ForLockingAllLFO2parameters;
	ButtonForUnlockingAllLFOparameters button_ForUnlockingAllLFO2parameters;
	ButtonForLockingAllLFOparameters button_ForLockingAllLFO3parameters;
	ButtonForUnlockingAllLFOparameters button_ForUnlockingAllLFO3parameters;
	ButtonForLockingAllLFOparameters button_ForLockingAllLFO4parameters;
	ButtonForShowingLFOrandomizationOptions button_ForForShowingRandomizationOptionsForLFO1;
	ButtonForShowingLFOrandomizationOptions button_ForForShowingRandomizationOptionsForLFO2;
	ButtonForShowingLFOrandomizationOptions button_ForForShowingRandomizationOptionsForLFO3;
	ButtonForShowingLFOrandomizationOptions button_ForForShowingRandomizationOptionsForLFO4;
	ButtonForUnlockingAllLFOparameters button_ForUnlockingAllLFO4parameters;
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
	ButtonForLockingAllKnobAssignParameters button_ForLockingAllKnobAssignParams;
	ButtonForUnlockingAllKnobAssignParameters button_ForUnlockingAllKnobAssignParams;
	ButtonForLockingAllPushItParameters button_ForLockingAllPushItParams;
	ButtonForUnlockingAllPushItParameters button_ForUnlockingAllPushItParams;
	ButtonForRandomizingUnlockedParameters button_ForRandomizingUnlockedParameters;
	TextButton button_ForClosingRandomizationComponent;
	std::unique_ptr<OscillatorRandomizationOptionsComponent> oscillatorOptionsComponent;
	std::unique_ptr<LFOfreqRandomizationOptionsComponent> lfoOptionsComponent;
	std::unique_ptr<RandomizationOptionsComponent_ValueRange> randomizationOptionsComponent_ValueRange;

public:
	ToggleButton paramLockToggleButtons[InfoForExposedParameters::numberOfExposedParameters];

	RandomizationComponent() = delete;

	RandomizationComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void setUpParamLockToggleButton(uint8 param);
	void paint(Graphics& g) override;
	void resized() override;
	void buttonClicked(Button* button) override;
	void showOscillatorOptionsComponent();
	void showOptionsComponentForLFO(int lfoNum);
	void showRandomizationOptionsComponent_ValueRangeForParam(uint8 paramIndex);
	void hideThisComponent();
	~RandomizationComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationComponent)
};