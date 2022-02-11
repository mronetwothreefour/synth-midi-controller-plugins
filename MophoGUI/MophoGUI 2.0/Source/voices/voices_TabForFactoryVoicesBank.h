#pragma once

#include <JuceHeader.h>

#include "voices_VoicesBanks.h"
#include "voices_VoiceSlotsWidget.h"
#include "../widgets_Button/widget_banks_ButtonForLoadingSelectedProgram.h"
#include "../widgets_Button/widget_banks_ButtonForPushingEntireBankToHardware.h"
#include "../widgets_Button/widget_banks_ButtonForPushingSelectedProgramToHardware.h"



class UnexposedParameters;

class TabForFactoryProgramBank :
    public Component,
    public ApplicationCommandTarget
{
    ProgramBank bank;
    ProgramSlotsWidget programSlots;
    UnexposedParameters* unexposedParams;
    ButtonForLoadingSelectedProgram button_ForLoadingSelectedProgram;
    ButtonForPushingEntireBankToHardware button_ForPushingEntireBankToHardware;
    ButtonForPushingSelectedProgramToHardware button_ForPushingSelectedProgramToHardware;
    ApplicationCommandManager commandManager;
    String& programCopyBuffer;

public:
    enum commandChoices {
        copyProgram = 1
    };

    TabForFactoryProgramBank() = delete;

    TabForFactoryProgramBank(ProgramBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer);
    void paint(Graphics& g) override;
    void resized() override;
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& commands) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;
    void addListenerToPushEntireBankButton(Button::Listener* listener);
    void removeListenerFromPushEntireBankButton(Button::Listener* listener);
    ~TabForFactoryProgramBank();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabForFactoryProgramBank)
};
