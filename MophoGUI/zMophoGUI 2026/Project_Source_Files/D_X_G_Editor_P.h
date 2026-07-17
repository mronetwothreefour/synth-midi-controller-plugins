#pragma once

#include <JuceHeader.h>

#include "D_X_G_Editor_B.h"
#include "G_WIDG_Cbox_Exp_B.h"
#include "G_WIDG_Slider_Exp_P.h"
#include "G_WIDG_Toggle_Exp_P.h"

class Editor_P :
    public Editor_B
{
//==============================================================================
public: Editor_P(Audio_Processor_P& processor, Data_Hub_P* hub);

public: void resized() override;
public: ~Editor_P();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Editor_P)
};
