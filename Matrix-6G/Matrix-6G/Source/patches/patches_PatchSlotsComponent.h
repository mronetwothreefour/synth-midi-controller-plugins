#pragma once

#include <JuceHeader.h>

#include "patches_PatchBanks.h"



class UnexposedParameters;

class PatchSlotsComponent :
    public Component,
    public ValueTree::Listener,
    private Timer
{
    ToggleButton patchSlotButtons[100];
    const PatchBank bank;
    AudioProcessorValueTreeState* exposedParams;
    UnexposedParameters* unexposedParams;

public:
    uint8 selectedSlot;

    PatchSlotsComponent() = delete;

    PatchSlotsComponent(PatchBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void setUpPatchSlotToggleButton(uint8 slot);
    void setTooltipForPatchSlotToggleButton(uint8 slot);
    void setTextForPatchSlotToggleButton(uint8 slot);
    void storeCurrentPatchSettingsInSelectedSlot();
    void loadPatchFromSelectedSlot();
    void applyNameOfPatchInRawDataVectorToGUI(std::vector<uint8>& patchDataVector);
    void applyExposedParamSettingsInRawDataVectorToGUI(std::vector<uint8>& patchDataVector);
    void applyMatrixModSettingsInRawDataVectorToGUI(std::vector<uint8>& patchDataVector);
    void pullSelectedPatchFromHardware();
    void pushSelectedPatchToHardware();
    void resized() override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;

private:
    void timerCallback() override;

public:
    ~PatchSlotsComponent();

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatchSlotsComponent)
};