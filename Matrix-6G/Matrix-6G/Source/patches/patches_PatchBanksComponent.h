#pragma once

#include <JuceHeader.h>

#include "patches_PatchBanks.h"
#include "patches_TabbedComponentForPatchBanks.h"
#include "../widgets_ComboBox/widget_patches_ComboBoxForSelectingPatchBank.h"
#include "../widgets_Label/widget_EditableLabel.h"



class PatchBankTransmissionComponent;
class UnexposedParameters;

class PatchBanksComponent :
    public Component,
    public Button::Listener,
    public ComboBox::Listener,
    public Label::Listener
{
    TabbedComponentForPatchBanks tabbedComponent;
    UnexposedParameters* unexposedParams;
    ComboBoxForSelectingPatchBank comboBox_ForSelectingBank;
    EditableLabel label_txTime;
    TextButton button_ForClosingPatchBanks;
    std::unique_ptr<PatchBankTransmissionComponent> pushEntireBankComponent;
    std::unique_ptr<PatchBankTransmissionComponent> pullEntireBankComponent;
    std::unique_ptr<FileBrowserComponent> fileBrowser;

public:
    PatchBanksComponent() = delete;

    PatchBanksComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    void buttonClicked(Button* button) override;
    void comboBoxChanged(ComboBox* comboBox) override;

private:
    void showPushEntireBankComponentForBank(PatchBank bank);
    void showPullEntireBankComponentForBank(PatchBank bank);
    void hideThisComponent();

public:
    ~PatchBanksComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatchBanksComponent)
};