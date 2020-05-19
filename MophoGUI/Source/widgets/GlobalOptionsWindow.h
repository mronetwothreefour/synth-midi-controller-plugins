#pragma once

#include <JuceHeader.h>

#include "../PluginProcessor.h"

#include "../helpers/CustomColors.h"
#include "../helpers/ValueConverters.h"
#include "../parameters/PrivateParameters.h"
#include "ButtonWidgets.h"
#include "KnobWidgets.h"
#include "MenuWidgets.h"

//==============================================================================
// The content component for the global options dialog window.
class GlobalOptionsComponent : public Component
{
public:
    GlobalOptionsComponent
    (
        PluginProcessor& p,
        PrivateParameters* privateParameters,
        ValueConverters* vc
    );

    //==============================================================================
    void paint(Graphics& g) override;

    void resized() override;

private:
    PluginProcessor& processor;

    PrivateParameters* privateParams;

    GlobalKnobWidget_MasterTranspose knob_Transpose;
    GlobalKnobWidget_MasterFineTune knob_FineTune;
    GlobalKnobWidget_MIDIchannel knob_MIDIchannel;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalOptionsComponent)
};

// Opens the global options component in a floating window
class GlobalOptionsWindow : public DialogWindow
{
public:
    GlobalOptionsWindow
    (
        PluginProcessor& p,
        PrivateParameters* privateParameters,
        ValueConverters* vc
    ) :
        DialogWindow{ "Global Options", Color::device, true, false }
    {
        contentComponent.reset(new GlobalOptionsComponent(p, privateParameters, vc));
        contentComponent->setVisible(true);
    }

    ~GlobalOptionsWindow()
    {
        contentComponent = nullptr;
    }

    std::unique_ptr<GlobalOptionsComponent> contentComponent;

private:

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalOptionsWindow)
};
