#pragma once

#include <JuceHeader.h>

#include "c_XYWH_p.h"
#include "D_SUBTREE_Choices_Exp_P.h"
#include "D_SUBTREE_Exposed_Info_P.h"
#include "D_TREE_Exposed_Info_B.h"

using Track = Seq_Track;
using Step = Seq_Track_Step;

class Tree_Exposed_Info_P :
	public Tree_Exposed_Info_B
{
//==============================================================================
public: Tree_Exposed_Info_P();

public: const Identifier id_for(Track track, Step step) const;
public: const Ctrl_Type ctrl_type_for(const int param_index) const;
public: const Knob_Editor_Type knob_editor_type_for(const int param_index) const;
public: const int nrpn_for(const int param_index) const;
public: const int param_index_for(const int nrpn) const;
public: Point<int> red_toggle_center_for(int param_index) const;
public: const int packed_bits_byte_index_for(const int param_index) const;
public: const int packed_bits_mask_for(const int param_index) const;
public: const int byte_index_for(const int param_index) const;
public: const Track seq_track_for(const int param_index) const;
public: const Step seq_track_step_for(const int param_index) const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Tree_Exposed_Info_P)
};