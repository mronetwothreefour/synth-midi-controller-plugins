#pragma once

#include <JuceHeader.h>

#include "D_TREE_App_Params_P.h"

using namespace TREE;

using State = AudioProcessorValueTreeState;

class Data_Hub_A
{
protected: App_Params app_params;
protected: std::unique_ptr<UndoManager> undo_mngr;
protected: std::unique_ptr<State> exposed_param_state;

//==============================================================================
public: explicit Data_Hub_A(AudioProcessor* processor);

public: App_Params& get_app_params();
public: State* get_exposed_params_state();
public: UndoManager* get_undo_mngr();
public: ~Data_Hub_A();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Data_Hub_A)
};
