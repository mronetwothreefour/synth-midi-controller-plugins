#pragma once

#include <JuceHeader.h>

#include "banks_ProgramSlotsWidget.h"
#include "../widgets_Button/widget_banks_ButtonForLoadingSelectedProgram.h"
#include "../widgets_Button/widget_banks_ButtonForPullingEntireBankFromHardware.h"
#include "../widgets_Button/widget_banks_ButtonForPullingSelectedProgramFromHardware.h"
#include "../widgets_Button/widget_banks_ButtonForPushingEntireBankToHardware.h"
#include "../widgets_Button/widget_banks_ButtonForPushingSelectedProgramToHardware.h"
#include "../widgets_Button/widget_banks_ButtonForSavingProgramInSelectedSlot.h"



class BankTransmissionComponent;
class UnexposedParameters;

class ProgramBankTab :
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
    ButtonForPushingEntireBankToHardware button_ForPushingEntireBankToHardware;
    ButtonForPullingEntireBankFromHardware button_ForPullingEntireBankFromHardware;
    std::unique_ptr<BankTransmissionComponent> pushEntireBankComponent;
    std::unique_ptr<BankTransmissionComponent> pullEntireBankComponent;
    ApplicationCommandManager commandManager;
    String& programCopyBuffer;

public:
    enum commandChoices {
        copyProgram = 1,
        pasteProgram
    };

    ProgramBankTab() = delete;

    ProgramBankTab(uint8 bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer);

private:
    void showPushEntireBankComponent();
    void showPullEntireBankComponent();

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
    void updateProgramSlotText(uint8 selectedSlot);
    void timerCallback() override;

public:
    ~ProgramBankTab();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBankTab)
};
