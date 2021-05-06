#pragma once

#include <JuceHeader.h>

#include "../widgets_Button/widget_ButtonForActivatingQuickPatchEdit.h"
#include "../widgets_Button/widget_ButtonForPerformingRedo.h"
#include "../widgets_Button/widget_ButtonForPerformingUndo.h"
#include "../widgets_Button/widget_ButtonForPullingPatchFromHardwareStorageSlot.h"
#include "../widgets_Button/widget_ButtonForPushingPatchToHardwareStorageSlot.h"
#include "../widgets_Button/widget_ButtonForShowingMasterOptionsComponent.h"
#include "../widgets_Button/widget_ButtonForShowingPatchBanksComponent.h"
#include "../widgets_Button/widget_ButtonForShowingSplitsComponent.h"



class MasterOptionsComponent;
class PatchBanksComponent;
class SplitsComponent;
class SysExIsOffWarningComponent;
class UnexposedParameters;

class ButtonsLayer :
	public Component,
	private Timer
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	ButtonForActivatingQuickPatchEdit button_ForActivatingQuickPatchEdit;
	ButtonForPerformingUndo button_ForPerformingUndo;
	ButtonForPerformingRedo button_ForPerformingRedo;
	ButtonForPullingPatchFromHardwareStorageSlot button_ForPullingPatchFromHardware;
	ButtonForPushingPatchToHardwareStorageSlot button_ForPushingPatchToHardware;
	ButtonForShowingPatchBanksComponent button_ForShowingPatchBanksComponent;
	ButtonForShowingSplitsComponent button_ForShowingSplitsComponent;
	ButtonForShowingMasterOptionsComponent button_ForShowingMasterOptionsComponent;
	std::unique_ptr<PatchBanksComponent> patchBanksComponent;
	std::unique_ptr<SplitsComponent> splitsComponent;
	std::unique_ptr<MasterOptionsComponent> masterOptionsComponent;
	std::unique_ptr<SysExIsOffWarningComponent> sysExIsOffWarningComponent;

public:
	ButtonsLayer() = delete;

	ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void showPatchBanksComponent();
	void showSplitsComponent();
	void prepareToShowMasterOptionsComponent();
	void showSysExIsOffWarningComponent();
	void showMasterOptionsComponent();
	void timerCallback() override;

public:
	void resized() override;
	~ButtonsLayer();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonsLayer)
};