#pragma once

#include "D_X_G_Audio_Processor_P.h"
#include "D_X_G_Data_User_P.h"
//#include "G_LAYER_Exp_Ctrls_P.h"
//#include "G_LOOK_AND_FEEL_P.h"

class Editor_A :
    public AudioProcessorEditor,
    public Data_User,
    public ValueTree::Listener
{
protected: Audio_Processor& processor;
//protected: Layer_Exposed_Controls_P layer_exp_ctrls;
//protected: Look_And_Feel_P l_a_f;
protected: TooltipWindow tip_win;

//==============================================================================
public: Editor_A(Audio_Processor& processor, Data_Hub* hub);

public: void paint(Graphics& g) override;
public: void modifierKeysChanged(const ModifierKeys& mods) override;
public: void valueTreePropertyChanged(ValueTree& parent_tree, const Identifier& property_id) override;
public: ~Editor_A() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Editor_A)
};