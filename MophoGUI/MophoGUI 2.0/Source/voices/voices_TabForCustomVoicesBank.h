#pragma once

#include <JuceHeader.h>

#include "voices_VoicesBanks.h"
#include "voices_VoiceSlotsWidget.h"
#include "../widgets_Button/widget_banks_ButtonForLoadingSelectedProgram.h"
#include "../widgets_Button/widget_banks_ButtonForPullingEntireBankFromHardware.h"
#include "../widgets_Button/widget_banks_ButtonForPullingSelectedProgramFromHardware.h"
#include "../widgets_Button/widget_banks_ButtonForPushingEntireBankToHardware.h"
#include "../widgets_Button/widget_banks_ButtonForPushingSelectedProgramToHardware.h"
#include "../widgets_Button/widget_banks_ButtonForSavingProgramInSelectedSlot.h"



class UnexposedParameters;

class TabForCustomProgramBank :
    public Component,
    private Timer,
    public ApplicationCommandTarget
{
    ProgramBank bank;
    ProgramSlotsWidget programSlots;
    UnexposedParameters* unexposedParams;
    ButtonForLoadingSelectedProgram button_ForLoadingSelectedProgram;
    ButtonForSavingProgramInSelectedSlot button_ForSavingProgramInSelectedSlot;
    ButtonForPullingEntireBankFromHardware button_ForPullingEntireBankFromHardware;
    ButtonForPullingSelectedProgramFromHardware button_ForPullingSelectedProgramFromHardware;
    ButtonForPushingEntireBankToHardware button_ForPushingEntireBankToHardware;
    ButtonForPushingSelectedProgramToHardware button_ForPushingSelectedProgramToHardware;
    ApplicationCommandManager commandManager;
    String& programCopyBuffer;

public:
    enum commandChoices {
        copyProgram = 1,
        pasteProgram
    };

    TabForCustomProgramBank() = delete;

    TabForCustomProgramBank(ProgramBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer);
    void paint(Graphics& g) override;
    void resized() override;
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& commands) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;
    void addListenerToPullEntireBankButton(Button::Listener* listener);
    void addListenerToPushEntireBankButton(Button::Listener* listener);
    void removeListenerFromPullEntireBankButton(Button::Listener* listener);
    void removeListenerFromPushEntireBankButton(Button::Listener* listener);

private:
    void timerCallback() override;

public:
    ~TabForCustomProgramBank();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabForCustomProgramBank)
};
