#pragma once

#include <JuceHeader.h>

#include "banks_ButtonForLoadingSelectedProgram.h"
#include "banks_ButtonForSavingProgramInSelectedSlot.h"
#include "banks_ButtonForPushingSelectedProgramToHardware.h"
#include "banks_ProgramSlotsWidget.h"



class ProgramBankTab :
    public Component,
    public Timer,
    public ApplicationCommandTarget
{
    uint8 bank;
    ProgramSlotsWidget programSlots;
    ButtonForLoadingSelectedProgram button_ForLoadingSelectedProgram;
    ButtonForSavingProgramInSelectedSlot button_ForSavingProgramInSelectedSlot;
    ButtonForPushingSelectedProgramToHardware button_ForPushingSelectedProgramToHardware;

    ApplicationCommandManager commandManager;

public:
    enum commandChoices {
        copyProgram = 1,
        pasteProgram
    };

    ProgramBankTab(uint8 bank, AudioProcessorValueTreeState* exposedParams);
    ~ProgramBankTab();

    void paint(Graphics& g) override;
    void resized() override;
    void timerCallback() override;
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& commands) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBankTab)
};
