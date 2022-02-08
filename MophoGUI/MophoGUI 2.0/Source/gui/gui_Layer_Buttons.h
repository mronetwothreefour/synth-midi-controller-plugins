#pragma once

#include <JuceHeader.h>

#include "../widgets_Button/widget_ButtonForClearingSequencerTrack.h"
#include "../widgets_Button/widget_ButtonAndLabelForEditingPgmName.h"
#include "../widgets_Button/widget_ButtonForPerformingRedo.h"
#include "../widgets_Button/widget_ButtonForPerformingUndo.h"
#include "../widgets_Button/widget_ButtonForSendingProgramEditBufferDump.h"
#include "../widgets_Button/widget_ButtonForSendingProgramEditBufferDumpRequest.h"
#include "../widgets_Button/widget_ButtonForShowingProgramBanksComponent.h"
#include "../widgets_Button/widget_ButtonForShowingGlobalParametersComponent.h"


class GlobalParametersComponent;
class ProgramBanksComponent;
class NRPNisOffWarningComponent;
class SysExIsOffWarningComponent;
class UnexposedParameters;

class ButtonsLayer :
	public Component,
	private Timer
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	ButtonAndLabelForEditingPgmName button_ForEditingPgmName;
	ButtonForSendingProgramEditBufferDump button_ForSendingProgramEditBufferDump;
	ButtonForSendingProgramEditBufferDumpRequest button_ForSendingProgramEditBufferDumpRequest;
	ButtonForShowingProgramBanksComponent button_ForShowingProgramBanksComponent;
	ButtonForShowingGlobalParametersComponent button_ForShowingGlobalParametersComponent;
	ButtonForPerformingRedo button_ForPerformingRedo;
	ButtonForPerformingUndo button_ForPerformingUndo;
	ButtonForClearingSequencerTrack button_ForClearingSequencerTrack1;
	ButtonForClearingSequencerTrack button_ForClearingSequencerTrack2;
	ButtonForClearingSequencerTrack button_ForClearingSequencerTrack3;
	ButtonForClearingSequencerTrack button_ForClearingSequencerTrack4;
	HyperlinkButton button_ForGoingToWebSite;
	std::unique_ptr<ProgramBanksComponent> programBanksComponent;
	std::unique_ptr<GlobalParametersComponent> globalParamsComponent;
	std::unique_ptr<SysExIsOffWarningComponent> sysExIsOffWarningComponent;
	std::unique_ptr<NRPNisOffWarningComponent> nrpnIsOffWarningComponent;

public:
	ButtonsLayer() = delete;

	ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void showProgramBanksComponent();
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