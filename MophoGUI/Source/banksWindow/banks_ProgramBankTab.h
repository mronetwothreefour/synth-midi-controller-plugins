#pragma once

#include <JuceHeader.h>

#include "../core_PluginProcessor.h"
#include "banks_ProgramSlotsWidget.h"



class ProgramBankTab :
    public Component,
    public Timer,
    public ApplicationCommandTarget,
    public Label::Listener
{
    uint8 bank;
    ProgramSlotsWidget programSlots;
    PluginProcessor& processor;
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
    void labelTextChanged(Label* label) override;
    void editorShown(Label* label, TextEditor& editor) override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBankTab)
};
