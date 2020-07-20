#pragma once

#include <JuceHeader.h>

#include "core_PluginProcessor.h"
#include "guiControls/ControlsForExposedParameters_Singleton.h"
#include "helpers/helper_CustomColors.h"
#include "helpers/helper_Fonts.h"
#include "helpers/helper_Identifiers.h"
#include "helpers/helper_InfoForMainWindowLabels_Singleton.h"
#include "helpers/helper_MophoLookAndFeel.h"
#include "widgets/widget_Logo.h"

class PluginEditor : 
    public AudioProcessorEditor,
    public ValueTree::Listener,
    public Timer
{
    PluginProcessor& processor;
    std::unique_ptr<MophoLookAndFeel> mophoLaF;
    std::unique_ptr<MainWindowDivision_Logo> widget_Logo;
    TooltipWindow tooltipWindow;

public:
    PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams);
    ~PluginEditor();

    void paint(Graphics& g) override;
    void resized() override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
    void timerCallback() override {}

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
