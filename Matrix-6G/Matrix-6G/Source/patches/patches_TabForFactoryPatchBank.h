#pragma once

#include <JuceHeader.h>

#include "patches_PatchBanks.h"
#include "patches_PatchSlotsComponent.h"
#include "../widgets_Button/widget_patches_ButtonForLoadingSelectedPatch.h"
#include "../widgets_Button/widget_patches_ButtonForPushingEntireBankToHardware.h"



class UnexposedParameters;

class TabForFactoryProgramBank :
    public Component,
    public ApplicationCommandTarget
{
    PatchBank bank;
    PatchSlotsComponent patchSlots;
    UnexposedParameters* unexposedParams;
    ButtonForLoadingSelectedPatch button_ForLoadingSelectedProgram;
    ButtonForPushingEntireBankToHardware button_ForPushingEntireBankToHardware;
    ApplicationCommandManager commandManager;
    String& patchCopyBuffer;

public:
    enum commandChoices {
        copyProgram = 1
    };

    TabForFactoryProgramBank() = delete;

    TabForFactoryProgramBank(PatchBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer);
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
