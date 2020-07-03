#pragma once

#include <JuceHeader.h>

#include "core_PluginProcessor.h"
#include "guiControls/guiControl_WithExposedParamAttachment_DB.h"
#include "helpers/helper_CustomColors.h"
#include "helpers/helper_Fonts.h"
#include "helpers/helper_Identifiers.h"
#include "helpers/helper_MophoLookAndFeel.h"
#include "widgets/widget_Logo.h"
#include "parameters/parameters_SynthParameters.h"

class PluginEditor : public AudioProcessorEditor
{
    PluginProcessor& processor;
    std::unique_ptr<MophoLookAndFeel> mophoLaF;
    std::unique_ptr<MainWindowDivision_Logo> div_Logo;

public:
    PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams);
    ~PluginEditor();

    void paint(Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
