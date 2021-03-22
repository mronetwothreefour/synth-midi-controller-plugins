#pragma once

#include <JuceHeader.h>

#include "../widgets_Button/widget_master_ButtonForPullingMasterOptionsFromHardware.h"



class UnexposedParameters;

class MasterOptionsComponent :
    public Component
{
    UnexposedParameters* unexposedParams;
    TextButton button_ForClosingMasterOptionsComponent;
    ButtonForPullingMasterOptionsFromHardware button_ForPullingMasterOptionsFromHardware;

public:
    MasterOptionsComponent() = delete;

    explicit MasterOptionsComponent(UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void resized() override;

private:
    void hideThisComponent();

public:
    ~MasterOptionsComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MasterOptionsComponent)
};