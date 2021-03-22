#pragma once

#include <JuceHeader.h>

#include "../widgets_Button/widget_ButtonForActivatingQuickPatchEdit.h"
#include "../widgets_Button/widget_ButtonForPullingPatchFromHardwareStorageSlot.h"
#include "../widgets_Button/widget_ButtonForPushingPatchToHardwareStorageSlot.h"
#include "../widgets_Button/widget_ButtonForShowingMasterOptionsComponent.h"
#include "../widgets_Button/widget_ButtonForShowingPatchBanksComponent.h"
#include "../widgets_Button/widget_ButtonForShowingSplitsComponent.h"



class MasterOptionsComponent;
class PatchBanksComponent;
class SplitsComponent;
class UnexposedParameters;

class ButtonsLayer :
	public Component
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	ButtonForActivatingQuickPatchEdit button_ForActivatingQuickPatchEdit;
	ButtonForPullingPatchFromHardwareStorageSlot button_ForPullingPatchFromHardware;
	ButtonForPushingPatchToHardwareStorageSlot button_ForPushingPatchToHardware;
	ButtonForShowingPatchBanksComponent button_ForShowingPatchBanksComponent;
	ButtonForShowingSplitsComponent button_ForShowingSplitsComponent;
	ButtonForShowingMasterOptionsComponent button_ForShowingMasterOptionsComponent;
	std::unique_ptr<PatchBanksComponent> patchBanksComponent;
	std::unique_ptr<SplitsComponent> splitsComponent;
	std::unique_ptr<MasterOptionsComponent> masterOptionsComponent;

public:
	ButtonsLayer() = delete;

	ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void showPatchBanksComponent();
	void showSplitsComponent();
	void showMasterOptionsComponent();

public:
	void resized() override;
	~ButtonsLayer();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonsLayer)
};