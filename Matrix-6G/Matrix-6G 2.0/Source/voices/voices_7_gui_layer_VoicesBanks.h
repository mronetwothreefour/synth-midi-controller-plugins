#pragma once

#include <JuceHeader.h>

#include "voices_6_comp_TabbedComponentForVoicesBanks.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Enum.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

class ExposedParameters;
class GUI_Layer_VoiceBankTransmit;
class GUI_Layer_Export_Voice;
class GUI_Layer_Export_VoicesBank;
class GUI_Layer_Import_Voice;
class GUI_Layer_Import_VoicesBank;
class UnexposedParameters;
class VoiceTransmissionOptions;

class GUI_Layer_VoicesBanks :
    public Component,
    public Button::Listener
{
    TabbedComponentForVoicesBanks voicesBanksTabs;
    UnexposedParameters* unexposedParams;
    VoiceTransmissionOptions* voiceTransmit;
    ButtonForHidingLayer btn_Close;
    Label lbl_txTimeEditor;
    ComboBox bankSelector;
    std::unique_ptr<GUI_Layer_Export_Voice> exportVoiceLayer;
    std::unique_ptr<GUI_Layer_Import_Voice> importVoiceLayer;
    std::unique_ptr<GUI_Layer_VoiceBankTransmit> pushBankLayer;
    std::unique_ptr<GUI_Layer_VoiceBankTransmit> pullBankLayer;
    std::unique_ptr<GUI_Layer_Export_VoicesBank> exportBankLayer;
    std::unique_ptr<GUI_Layer_Import_VoicesBank> importBankLayer;
    const Rectangle<int> borderBounds{ 402, 19, 448, 560 };
    const Rectangle<int> componentBounds{ borderBounds.reduced(GUI::borders_w)};

public:
    GUI_Layer_VoicesBanks() = delete;

    GUI_Layer_VoicesBanks(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
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