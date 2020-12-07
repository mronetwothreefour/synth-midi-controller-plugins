#pragma once

#include <JuceHeader.h>

#include "banks_ProgramSlotsWidget.h"
#include "../widgets_Button/widget_banks_ButtonForLoadingSelectedProgram.h"
#include "../widgets_Button/widget_banks_ButtonForPullingSelectedProgramFromHardware.h"
#include "../widgets_Button/widget_banks_ButtonForPushingSelectedProgramToHardware.h"
#include "../widgets_Button/widget_banks_ButtonForSavingProgramInSelectedSlot.h"



class UnexposedParameters;

class TabForFactoryProgramBank :
    public Component,
    public ApplicationCommandTarget
{
    uint8 bank;
    ProgramSlotsWidget programSlots;
    UnexposedParameters* unexposedParams;
    ButtonForLoadingSelectedProgram button_ForLoadingSelectedProgram;
    ButtonForPushingSelectedProgramToHardware button_ForPushingSelectedProgramToHardware;
    ApplicationCommandManager commandManager;
    String& programCopyBuffer;

public:
    enum commandChoices {
        copyProgram = 1
    };

    TabForFactoryProgramBank() = delete;

    TabForFactoryProgramBank(uint8 bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer);

public:
    void paint(Graphics& g) override;
    void resized() override;
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& commands) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;
    ~TabForFactoryProgramBank();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabForFactoryProgramBank)
};
