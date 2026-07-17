#pragma once

#include <JuceHeader.h>

#include "../widgets_Button/widget_ButtonForPerformingRedo.h"
#include "../widgets_Button/widget_ButtonForPerformingUndo.h"
#include "../widgets_Button/widget_ButtonForPullingVoiceFromHardwareStorageSlot.h"
#include "../widgets_Button/widget_ButtonForPushingVoiceToHardwareStorageSlot.h"
#include "../widgets_Button/widget_ButtonForShowingRandomizeComponent.h"
#include "../widgets_Button/widget_ButtonForShowingTipsComponent.h"
#include "../widgets_Button/widget_ButtonForShowingVoicesBankComponent.h"



class VoicesBankComponent;
class RandomizationComponent;
class TooltipOptionsComponent;
class UnexposedParameters;

class ButtonsLayer :
	public Component,
	private Timer
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	ButtonForPerformingRedo button_ForPerformingRedo;
	ButtonForPerformingUndo button_ForPerformingUndo;
	ButtonForPullingVoiceFromHardwareStorageSlot button_ForPullingVoiceFromHardware;
	ButtonForPushingVoiceToHardwareStorageSlot button_ForPushingVoiceToHardware;
	ButtonForShowingRandomizeComponent button_ForShowingRandomizationComponent;
	ButtonForShowingTipsComponent button_ForShowingTipsComponent;
	ButtonForShowingVoicesBankComponent button_ForShowingVoicesBankComponent;
	HyperlinkButton button_ForGoingToWebSite;
	std::unique_ptr<TooltipOptionsComponent> tooltipOptionsComponent;
	std::unique_ptr<RandomizationComponent> randomizationComponent;
	std::unique_ptr<VoicesBankComponent> voicesBankComponent;

public:
	ButtonsLayer() = delete;

	ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void showTooltipOptionsComponent();
	void showRandomizationComponent();
	void showVoicesBankComponent();
	void timerCallback() override;

public:
	void resized() override;
	~ButtonsLayer();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonsLayer)
};