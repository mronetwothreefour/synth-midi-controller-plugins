#pragma once

#include <JuceHeader.h>

#include "patches_PatchBanks.h"
#include "patches_TabbedComponentForPatchBanks.h"
#include "../widgets_ComboBox/widget_patches_ComboBoxForSelectingPatchBank.h"
#include "../widgets_Label/widget_EditableLabel.h"



class VoicesBankTransmissionComponent;
class UnexposedParameters;

class VoicesBanksComponent :
    public Component,
    public Button::Listener,
    public ComboBox::Listener,
    public Label::Listener
{
    TabbedComponentForVoicesBanks tabbedComponent;
    UnexposedParameters* unexposedParams;
    ComboBoxForSelectingVoicesBank comboBox_ForSelectingBank;
    EditableLabel label_txTime;
    TextButton button_ForClosingVoicesBanks;
    std::unique_ptr<VoicesBankTransmissionComponent> pushEntireBankComponent;
    std::unique_ptr<VoicesBankTransmissionComponent> pullEntireBankComponent;

public:
    VoicesBanksComponent() = delete;

    VoicesBanksComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    void buttonClicked(Button* button) override;
    void comboBoxChanged(ComboBox* comboBox) override;

private:
    void showPushEntireBankComponentForBank(VoicesBank bank);
    void showPullEntireBankComponentForBank(VoicesBank bank);
    void hideThisComponent();

public:
    ~VoicesBanksComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoicesBanksComponent)
};