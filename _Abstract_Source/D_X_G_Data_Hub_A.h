#pragma once

#include <JuceHeader.h>

using State = AudioProcessorValueTreeState;

class Data_Hub_A
{
//protected: Tree_App_Options_P app_options;
protected: std::unique_ptr<UndoManager> undo_mngr;
protected: std::unique_ptr<State> exposed_param_state;
protected: float scale_factor;

//==============================================================================
public: explicit Data_Hub_A(AudioProcessor* processor);

//public: Tree_App_Options_P& get_app_options();
public: UndoManager* get_undo_mngr();
public: State* get_exposed_params_state();
public: float& get_scale_factor();
public: ~Data_Hub_A();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Data_Hub_A)
};
