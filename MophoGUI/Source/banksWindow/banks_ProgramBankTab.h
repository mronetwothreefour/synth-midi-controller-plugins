#pragma once

#include <JuceHeader.h>

#include "banks_ButtonForLoadingSelectedProgram.h"
#include "banks_ButtonForSavingProgramInSelectedSlot.h"
#include "banks_ButtonForPullingSelectedProgramFromHardware.h"
#include "banks_ButtonForPushingSelectedProgramToHardware.h"
#include "banks_ProgramSlotsWidget.h"
#include "../midiTools/midi_OutgoingMidiBuffers.h"



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
    ButtonForPullingSelectedProgramFromHardware button_ForPullingSelectedProgramFromHardware;
    ApplicationCommandManager commandManager;
    String& programCopyBuffer;

public:
    enum commandChoices {
        copyProgram = 1,
        pasteProgram
    };

    ProgramBankTab() = delete;

    ProgramBankTab(uint8 bank, AudioProcessorValueTreeState* exposedParams, OutgoingMidiBuffers* outgoingBuffers, String& programCopyBuffer);
    ~ProgramBankTab();

    void paint(Graphics& g) override;
    void resized() override;
    void timerCallback() override;
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& commands) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;

private:
    void updateProgramSlotTextAfterDelay(uint8 selectedSlot);

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBankTab)
};
