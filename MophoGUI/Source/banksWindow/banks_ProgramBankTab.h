#pragma once

#include <JuceHeader.h>

#include "banks_ProgramBanksButtons.h"
#include "banks_ProgramSlotsWidget.h"
#include "../core_PluginProcessor.h"
#include "../helpers/helper_CustomColors.h"
#include "../helpers/helper_Fonts.h"



class ProgramBankTab :
    public Component,
    public Timer,
    public ApplicationCommandTarget
{
    uint8 bank;
    PluginProcessor& processor;
    ProgramSlotsWidget programSlots;
    ButtonForLoadingSelectedProgram button_ForLoadingSelectedProgram;
    ButtonForSavingProgramInSelectedSlot button_ForSavingProgramInSelectedSlot;
    ApplicationCommandManager commandManager;

public:
    enum commandChoices {
        copyProgram = 1,
        pasteProgram
    };

    ProgramBankTab(uint8 bank, PluginProcessor& processor);
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
