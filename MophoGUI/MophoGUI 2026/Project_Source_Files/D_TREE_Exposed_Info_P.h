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
public: const Ctrl_Type ctrl_type_for(const uint8 param_index) const;
public: const Knob_Display_Type knob_display_type_for(const uint8 param_index) const;
public: const uint8 nrpn_for(const uint8 param_index) const;
public: const uint8 param_index_for(const uint8 nrpn) const;
public: Point<int> red_toggle_center_for(uint8 param_index) const;
public: const uint16 packed_bits_byte_index_for(const uint8 param_index) const;
public: const uint8 packed_bits_mask_for(const uint8 param_index) const;
public: const uint16 byte_index_for(const uint8 param_index) const;
public: const Track seq_track_for(const uint8 param_index) const;
public: const Step seq_track_step_for(const uint8 param_index) const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Tree_Exposed_Info_P)
};