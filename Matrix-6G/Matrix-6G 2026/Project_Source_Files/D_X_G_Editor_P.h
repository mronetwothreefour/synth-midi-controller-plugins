#pragma once

#include <JuceHeader.h>

#include "D_X_G_Editor_B.h"
#include "G_WIDG_Slider_Exposed_B.h"

class Editor_P :
    public Editor_B
{
private: std::unique_ptr<Slider_Exposed_B> knob;

//==============================================================================
public: Editor_P(Audio_Processor_P& processor, Data_Hub_P* hub);

public: void resized() override;
public: ~Editor_P();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Editor_P)
};
