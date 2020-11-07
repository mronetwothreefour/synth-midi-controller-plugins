#pragma once

#include <JuceHeader.h>
#include "../widgets_Button/widget_ButtonAndLabelForEditingPgmName.h"
#include "../widgets_Button/widget_ButtonForSendingProgramEditBufferDump.h"
#include "../widgets_Button/widget_ButtonForSendingProgramEditBufferDumpRequest.h"
#include "../widgets_Button/widget_ButtonForShowingProgramBanksComponent.h"


class ProgramBanksComponent;
class UnexposedParameters;

class ButtonsLayer :
	public Component
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	ButtonAndLabelForEditingPgmName button_ForEditingPgmName;
	ButtonForSendingProgramEditBufferDump button_ForSendingProgramEditBufferDump;
	ButtonForSendingProgramEditBufferDumpRequest button_ForSendingProgramEditBufferDumpRequest;
	ButtonForShowingProgramBanksComponent button_ForShowingProgramBanksComponent;
	std::unique_ptr<ProgramBanksComponent> programBanksComponent;

public:
	ButtonsLayer() = delete;

	ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void showProgramBanksComponent();

public:
	void resized() override;
	~ButtonsLayer();

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonsLayer)
};