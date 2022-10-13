#pragma once

#include <JuceHeader.h>

#include "splits_0_tree_SplitsBank.h"
#include "splits_1_comp_ComboBoxForSplitParam.h"
#include "splits_1_comp_SliderForSplitParam.h"
#include "splits_2_comp_SplitSlots.h"
#include "splits_3_comp_SplitsWindowButtons.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

using namespace Matrix_6G_Constants;

class ExposedParameters;
class GUI_Layer_SplitsBankTransmit;
class UnexposedParameters;

class GUI_Layer_Splits :
    public Component,
    public Value::Listener,
    public ApplicationCommandTarget
{
    UnexposedParameters* unexposedParams;
    SplitSlots splitSlots;
    SplitsBank* splitsBank;
    Label splitNameEditor;
    ButtonForHidingLayer btn_Close;
    ComboBoxForSplitParameter comboBox_ZoneVoiceAssignment;
    LinearSliderForSplitZoneVolumeBalance slider_ZoneVolumeBalance;
    RotarySliderForSplitParameter slider_LowerZoneLimit;
    RotarySliderForSplitParameter slider_LowerZoneVoiceNum;
    RotarySliderForSplitParameter slider_LowerZoneTranspose;
    ComboBoxForSplitParameter comboBox_LowerZone_MIDI_IsEnabled;
    RotarySliderForSplitParameter slider_UpperZoneLimit;
    RotarySliderForSplitParameter slider_UpperZoneVoiceNum;
    RotarySliderForSplitParameter slider_UpperZoneTranspose;
    ComboBoxForSplitParameter comboBox_UpperZone_MIDI_IsEnabled;
    ButtonForLoadingSelectedSplit btn_LoadSelected;
    ButtonForSavingSplitIntoSelectedSlot btn_SaveIntoSelected;
    ButtonForPullingSelectedSplitFromHardware btn_PullSelected;;
    ButtonForPushingEntireSplitsBankToHardware btn_PushBank;
    ButtonForPullingEntireSplitsBankFromHardware btn_PullBank;
    std::unique_ptr<GUI_Layer_SplitsBankTransmit> pushBankLayer;
    std::unique_ptr<GUI_Layer_SplitsBankTransmit> pullBankLayer;
    ApplicationCommandManager commandManager;
    String splitCopyBuffer;
    Value splitNameAsValue;

public:
    enum commandChoices {
        copyVoice = 1,
        pasteVoice
    };

    GUI_Layer_Splits() = delete;

    GUI_Layer_Splits(UnexposedParameters* unexposedParams, UndoManager* undoManager);
    void paint(Graphics& g) override;
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& commands) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;
    void valueChanged(Value& value) override;

private:
    void showPushBankLayer();
    void showPullBankLayer();

public:
    ~GUI_Layer_Splits();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_Splits)
};