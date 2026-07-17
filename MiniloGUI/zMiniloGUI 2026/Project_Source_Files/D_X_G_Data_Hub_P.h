#pragma once

#include <JuceHeader.h>

#include "D_TREE_Additional_Voice_P.h"
#include "D_X_G_Data_Hub_B.h"

class Data_Hub_P :
	public Data_Hub_B
{
private: Tree_Additional_Voice_P additional_voice_params;

//==============================================================================
public: explicit Data_Hub_P(AudioProcessor* processor);

public: Tree_Additional_Voice_P& get_additional_voice_params();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Data_Hub_P)

};