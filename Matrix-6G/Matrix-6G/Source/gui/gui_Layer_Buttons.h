#pragma once

#include <JuceHeader.h>

#include "../widgets_Button/widget_ButtonForActivatingQuickPatchEdit.h"
#include "../widgets_Button/widget_ButtonForPullingPatchFromHardwareStorageSlot.h"
#include "../widgets_Button/widget_ButtonForPushingPatchToHardwareStorageSlot.h"
#include "../widgets_Button/widget_ButtonForShowingPatchBanksComponent.h"



class PatchBanksComponent;
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
	std::unique_ptr<PatchBanksComponent> patchBanksComponent;

public:
	ButtonsLayer() = delete;

	ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void showPatchBanksComponent();

public:
	void resized() override;
	~ButtonsLayer();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonsLayer)
};