#pragma once

#include <JuceHeader.h>

#include "gui_matrixMod_Slot.h"



class UnexposedParameters;

class MatrixModLayer :
    public Component
{
    MatrixModSlot matrixModSlot_0;
    MatrixModSlot matrixModSlot_1;
    MatrixModSlot matrixModSlot_2;
    MatrixModSlot matrixModSlot_3;
    MatrixModSlot matrixModSlot_4;
    MatrixModSlot matrixModSlot_5;
    MatrixModSlot matrixModSlot_6;
    MatrixModSlot matrixModSlot_7;
    MatrixModSlot matrixModSlot_8;
    MatrixModSlot matrixModSlot_9;

public:
    MatrixModLayer() = delete;

    explicit MatrixModLayer(UnexposedParameters* unexposedParams);
    void resized() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MatrixModLayer)
};