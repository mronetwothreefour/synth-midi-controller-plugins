#pragma once

#include <JuceHeader.h>

#include "d_Tree__Exposed_Info_b.h"
#include "c_XYWH_p.h"
#include "d_Sub_Tree_Choices__Exp_p.h"

using namespace ENUM;

using Track = Seq_Track;
using Step = Seq_Track_Step;

class Exposed_Parameter_Info :
	public Base_Exposed_Parameter_Info
{
//==============================================================================
public: Exposed_Parameter_Info();

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
public: const Choice_Menu_Type choice_menu_type_for(const uint8 param_index) const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exposed_Parameter_Info)
};