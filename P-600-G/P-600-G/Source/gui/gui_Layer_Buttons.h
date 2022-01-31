#pragma once

#include <JuceHeader.h>

#include "../widgets_Button/widget_ButtonForPerformingRedo.h"
#include "../widgets_Button/widget_ButtonForPerformingUndo.h"
#include "../widgets_Button/widget_ButtonForPullingProgramFromHardwareStorageSlot.h"
#include "../widgets_Button/widget_ButtonForPushingProgramToHardwareStorageSlot.h"
#include "../widgets_Button/widget_ButtonForShowingProgramBankComponent.h"
#include "../widgets_Button/widget_ButtonForShowingRandomizeComponent.h"
#include "../widgets_Button/widget_ButtonForShowingTipsComponent.h"



class UnexposedParameters;
class ProgramDataBankComponent;
class TooltipOptionsComponent;

class ButtonsLayer :
	public Component,
	private Timer
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	ButtonForPerformingRedo button_ForPerformingRedo;
	ButtonForPerformingUndo button_ForPerformingUndo;
	ButtonForPullingProgramFromHardwareStorageSlot button_ForPullingProgramFromHardware;
	ButtonForPushingProgramToHardwareStorageSlot button_ForPushingProgramToHardware;
	ButtonForShowingProgramBankComponent button_ForShowingProgramBankComponent;
	ButtonForShowingRandomizeComponent button_ForShowingRandomizeComponent;
	ButtonForShowingTipsComponent button_ForShowingTipsComponent;
	std::unique_ptr<ProgramDataBankComponent> pgmDataBankComponent;
	std::unique_ptr<TooltipOptionsComponent> tooltipOptionsComponent;

public:
	ButtonsLayer() = delete;

	ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void showProgramDataBankComponent();
	void showTooltipOptionsComponent();
	void timerCallback() override;

public:
	void resized() override;
	~ButtonsLayer();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonsLayer)
};