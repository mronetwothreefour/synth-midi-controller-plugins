#pragma once

#include <JuceHeader.h>

#include "core_PluginProcessor.h"
#include "guiControls/ControlsForExposedParameters_Singleton.h"
#include "helpers/helper_CustomColors.h"
#include "helpers/helper_Fonts.h"
#include "helpers/helper_Identifiers.h"
#include "helpers/helper_InfoForMainWindowLabels_Singleton.h"
#include "helpers/helper_MophoLookAndFeel.h"
#include "widgets/widget_EnvelopeRenderer.h"
#include "widgets/widget_Logo.h"

class PluginEditor : 
    public AudioProcessorEditor,
    public ValueTree::Listener,
    public Label::Listener
{
    PluginProcessor& processor;
    std::unique_ptr<MophoLookAndFeel> mophoLaF;
    std::unique_ptr<MainWindowDivision_Logo> mophoguiLogo;
    std::unique_ptr<EnvelopeRenderer> envelopeRenderer_LPF;
    std::unique_ptr<EnvelopeRenderer> envelopeRenderer_VCA;
    std::unique_ptr<EnvelopeRenderer> envelopeRenderer_Env3;
    std::unique_ptr<Label>pgmNameEditor;
    std::unique_ptr<TextButton> button_EditPgmName;
    TooltipWindow tooltipWindow;

    String getPgmName();
    void showPgmNameEditor();

public:
    PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams);
    ~PluginEditor();

    void paint(Graphics& g) override;
    void resized() override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
    void labelTextChanged(Label* labelThatHasChanged) override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
