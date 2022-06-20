#pragma once

#include <JuceHeader.h>

#include "voices_6_comp_TabbedComponentForAllVoicesBanks.h"
#include "../constants/constants_Enum.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"



class GUI_Layer_BankTransmit;
class GUI_Layer_Export_Voice;
class GUI_Layer_Export_VoicesBank;
class GUI_Layer_Import_Voice;
class GUI_Layer_Import_VoicesBank;
class UnexposedParameters;
class VoiceTransmissionOptions;

class GUI_Layer_VoicesBanks :
    public Component,
    public Label::Listener,
    public Button::Listener
{
    TabbedComponentForAllVoicesBanks voicesBanksTabs;
    UnexposedParameters* unexposedParams;
    VoiceTransmissionOptions* voiceTransmit;
    ButtonForHidingLayer button_Close;
    std::unique_ptr<GUI_Layer_Export_Voice> exportVoiceLayer;
    std::unique_ptr<GUI_Layer_Import_Voice> importVoiceLayer;
    std::unique_ptr<GUI_Layer_BankTransmit> pushBankLayer;
    std::unique_ptr<GUI_Layer_BankTransmit> pullBankLayer;
    std::unique_ptr<GUI_Layer_Export_VoicesBank> exportBankLayer;
    std::unique_ptr<GUI_Layer_Import_VoicesBank> importBankLayer;
    Label label_txTimeEditor;

public:
    GUI_Layer_VoicesBanks() = delete;

    GUI_Layer_VoicesBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    void buttonClicked(Button* button) override;

private:
    void showExportVoiceLayerForBank(VoicesBank bank);
    void showImportVoiceLayerForBank(VoicesBank bank);
    void showPushBankLayerForBank(VoicesBank bank);
    void showPullBankLayerForBank(VoicesBank bank);
    void showExportBankLayerForBank(VoicesBank bank);
    void showImportBankLayerForBank(VoicesBank bank);

public:
    ~GUI_Layer_VoicesBanks();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_VoicesBanks)
};