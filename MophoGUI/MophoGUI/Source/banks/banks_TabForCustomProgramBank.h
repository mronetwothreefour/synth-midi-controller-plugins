#pragma once

#include <JuceHeader.h>

#include "banks_ProgramSlotsWidget.h"
#include "../widgets_Button/widget_banks_ButtonForLoadingSelectedProgram.h"
#include "../widgets_Button/widget_banks_ButtonForPullingSelectedProgramFromHardware.h"
#include "../widgets_Button/widget_banks_ButtonForPushingSelectedProgramToHardware.h"
#include "../widgets_Button/widget_banks_ButtonForSavingProgramInSelectedSlot.h"



class UnexposedParameters;

class TabForCustomProgramBank :
    public Component,
    private Timer,
    public ApplicationCommandTarget
{
    uint8 bank;
    ProgramSlotsWidget programSlots;
    UnexposedParameters* unexposedParams;
    ButtonForLoadingSelectedProgram button_ForLoadingSelectedProgram;
    ButtonForSavingProgramInSelectedSlot button_ForSavingProgramInSelectedSlot;
    ButtonForPushingSelectedProgramToHardware button_ForPushingSelectedProgramToHardware;
    ButtonForPullingSelectedProgramFromHardware button_ForPullingSelectedProgramFromHardware;
    ApplicationCommandManager commandManager;
    String& programCopyBuffer;

public:
    enum commandChoices {
        copyProgram = 1,
        pasteProgram
    };

    TabForCustomProgramBank() = delete;

    TabForCustomProgramBank(uint8 bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer);

public:
    void paint(Graphics& g) override;
    void resized() override;
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& commands) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;

private:
    void updateProgramNameAfterDelay(const String& programDataHexString, uint8 selectedSlot);
    void storeNewProgramName(const String& programDataHexString, uint8 selectedSlot);

public:
    void updateCustomProgramSlotText(uint8 selectedSlot);

private:
    void timerCallback() override;

public:
    ~TabForCustomProgramBank();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabForCustomProgramBank)
};
