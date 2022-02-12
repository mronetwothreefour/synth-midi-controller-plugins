#pragma once

#include <JuceHeader.h>

#include "../widgets_Button/widget_ButtonForClearingSequencerTrack.h"
#include "../widgets_Button/widget_ButtonAndLabelForEditingVoiceName.h"
#include "../widgets_Button/widget_ButtonForPerformingRedo.h"
#include "../widgets_Button/widget_ButtonForPerformingUndo.h"
#include "../widgets_Button/widget_ButtonForSendingEditBufferDataMessage.h"
#include "../widgets_Button/widget_ButtonForSendingEditBufferDataMessageRequest.h"
#include "../widgets_Button/widget_ButtonForShowingVoicesBanksComponent.h"
#include "../widgets_Button/widget_ButtonForShowingGlobalParametersComponent.h"


class GlobalParametersComponent;
class VoicesBanksComponent;
class NRPNisOffWarningComponent;
class SysExIsOffWarningComponent;
class UnexposedParameters;

class ButtonsLayer :
	public Component,
	private Timer
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	ButtonAndLabelForEditingVoiceName button_ForEditingVoiceName;
	ButtonForSendingEditBufferDataMessage button_ForSendingEditBufferDataMessage;
	ButtonForSendingEditBufferDataMessageRequest button_ForSendingEditBufferDataMessageRequest;
	ButtonForShowingVoicesBanksComponent button_ForShowingVoicesBanksComponent;
	ButtonForShowingGlobalParametersComponent button_ForShowingGlobalParametersComponent;
	ButtonForPerformingRedo button_ForPerformingRedo;
	ButtonForPerformingUndo button_ForPerformingUndo;
	ButtonForClearingSequencerTrack button_ForClearingSequencerTrack1;
	ButtonForClearingSequencerTrack button_ForClearingSequencerTrack2;
	ButtonForClearingSequencerTrack button_ForClearingSequencerTrack3;
	ButtonForClearingSequencerTrack button_ForClearingSequencerTrack4;
	HyperlinkButton button_ForGoingToWebSite;
	std::unique_ptr<VoicesBanksComponent> voicesBanksComponent;
	std::unique_ptr<GlobalParametersComponent> globalParamsComponent;
	std::unique_ptr<SysExIsOffWarningComponent> sysExIsOffWarningComponent;
	std::unique_ptr<NRPNisOffWarningComponent> nrpnIsOffWarningComponent;

public:
	ButtonsLayer() = delete;

	ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void showVoicesBanksComponent();
	void prepareToShowGlobalParametersComponent();
	void showSysExIsOffWarningComponent();
	void showNRPNisOffWarningComponent();
	void showGlobalParametersComponent();
	void timerCallback() override;

public:
	void resized() override;
	~ButtonsLayer();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonsLayer)
};