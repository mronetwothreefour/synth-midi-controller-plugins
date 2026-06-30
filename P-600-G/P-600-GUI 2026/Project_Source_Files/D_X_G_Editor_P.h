#pragma once

#include <JuceHeader.h>

#include "D_X_G_Editor_B.h"
#include "G_WIDG_Slider_Exp_P.h"

class Editor_P :
    public Editor_B
{
private: std::unique_ptr<Slider_Exposed_P> knob;
private: std::unique_ptr<Slider_Exposed_P> switch_slider;

//==============================================================================
public: Editor_P(Audio_Processor_P& processor, Data_Hub_P* hub);

public: void resized() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Editor_P)
};
