#pragma once

#include "D_X_G_Data_Hub_A.h"

class Data_Hub :
	public Data_Hub_A
{

//==============================================================================
public: explicit Data_Hub(AudioProcessor* processor);

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Data_Hub)
};