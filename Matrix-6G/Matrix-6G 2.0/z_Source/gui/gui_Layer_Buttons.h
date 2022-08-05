#pragma once

#include <JuceHeader.h>

#include "../widgets_Button/widget_ButtonForActivatingQuickEdit.h"
#include "../widgets_Button/widget_ButtonForPerformingRedo.h"
#include "../widgets_Button/widget_ButtonForPerformingUndo.h"
#include "../widgets_Button/widget_ButtonForPullingVoiceFromHardwareStorageSlot.h"
#include "../widgets_Button/widget_ButtonForPushingVoiceToHardwareStorageSlot.h"
#include "../widgets_Button/widget_ButtonForShowingGlobalOptionsComponent.h"
#include "../widgets_Button/widget_ButtonForShowingVoicesBanksComponent.h"
#include "../widgets_Button/widget_ButtonForShowingSplitsComponent.h"



class GlobalOptionsComponent;
class VoicesBanksComponent;
class SplitsComponent;
class SysExIsOffWarningComponent;
class UnexposedParameters;

class ButtonsLayer :
	public Component,
	private Timer
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	ButtonForActivatingQuickEdit button_ForActivatingQuickEdit;
	ButtonForPerformingUndo button_ForPerformingUndo;
	ButtonForPerformingRedo button_ForPerformingRedo;
	ButtonForPullingVoiceFromHardwareStorageSlot button_ForPullingVoiceFromHardware;
	ButtonForPushingVoiceToHardwareStorageSlot button_ForPushingVoiceToHardware;
	ButtonForShowingVoicesBanksComponent button_ForShowingVoicesBanksComponent;
	ButtonForShowingSplitsComponent button_ForShowingSplitsComponent;
	ButtonForShowingGlobalOptionsComponent button_ForShowingGlobalOptionsComponent;
	HyperlinkButton button_ForGoingToWebSite;
	std::unique_ptr<VoicesBanksComponent> voicesBanksComponent;
	std::unique_ptr<SplitsComponent> splitsComponent;
	std::unique_ptr<GlobalOptionsComponent> globalOptionsComponent;
	std::unique_ptr<SysExIsOffWarningComponent> sysExIsOffWarningComponent;

public:
	ButtonsLayer() = delete;

	ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void showVoicesBanksComponent();
	void showSplitsComponent();
	void prepareToShowGlobalOptionsComponent();
	void showSysExIsOffWarningComponent();
	void showGlobalOptionsComponent();
	void timerCallback() override;

public:
	void resized() override;
	~ButtonsLayer();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonsLayer)
};