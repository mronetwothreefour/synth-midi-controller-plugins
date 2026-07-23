#pragma once

#include "D_TREE_Exposed_Info_P.h"

using State = AudioProcessorValueTreeState;

class Data_Hub_G
{
protected: const Tree_Exposed_Info_P exposed_info;
protected: std::unique_ptr<UndoManager> undo_mngr;
//protected: std::unique_ptr<State> exposed_state;
protected: float scale_factor;

//==============================================================================
public: explicit Data_Hub_G(AudioProcessor* processor);

public: const Tree_Exposed_Info_P& get_exposed_info();
public: UndoManager* get_undo_mngr();
//public: State* get_exposed_state();
public: float& get_scale_factor();
public: ~Data_Hub_G();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Data_Hub_G)
};