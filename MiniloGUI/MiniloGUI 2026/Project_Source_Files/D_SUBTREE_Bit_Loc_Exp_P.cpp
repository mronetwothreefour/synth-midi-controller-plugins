#include "D_SUBTREE_Bit_Loc_Exp_P.h"

ValueTree Subtree_Bit_Loc_Exp::delay_feedback() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_70__bit_6" },
        { "bit_1", "byte_63__bit_6" },
        { "bit_2", "byte_58__bit_0" },
        { "bit_3", "byte_58__bit_1" },
        { "bit_4", "byte_58__bit_2" },
        { "bit_5", "byte_58__bit_3" },
        { "bit_6", "byte_58__bit_4" },
        { "bit_7", "byte_58__bit_5" },
        { "bit_8", "byte_58__bit_6" },
        { "bit_9", "byte_55__bit_2" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::delay_hpf_freq() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_70__bit_2" },
        { "bit_1", "byte_70__bit_3" },
        { "bit_2", "byte_56__bit_0" },
        { "bit_3", "byte_56__bit_1" },
        { "bit_4", "byte_56__bit_2" },
        { "bit_5", "byte_56__bit_3" },
        { "bit_6", "byte_56__bit_4" },
        { "bit_7", "byte_56__bit_5" },
        { "bit_8", "byte_56__bit_6" },
        { "bit_9", "byte_55__bit_0" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::delay_routing() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_68__bit_6" },
        { "bit_1", "byte_63__bit_4" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::delay_time() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_70__bit_4" },
        { "bit_1", "byte_70__bit_5" },
        { "bit_2", "byte_57__bit_0" },
        { "bit_3", "byte_57__bit_1" },
        { "bit_4", "byte_57__bit_2" },
        { "bit_5", "byte_57__bit_3" },
        { "bit_6", "byte_57__bit_4" },
        { "bit_7", "byte_57__bit_5" },
        { "bit_8", "byte_57__bit_6" },
        { "bit_9", "byte_55__bit_1" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::env_attack(const bool vca) {
    return {
        ID::tree_bit_locations, {
        { "bit_0", vca ? "byte_65__bit_0" : "byte_66__bit_0" },
        { "bit_1", vca ? "byte_65__bit_1" : "byte_66__bit_1" },
        { "bit_2", vca ? "byte_38__bit_0" : "byte_43__bit_0" },
        { "bit_3", vca ? "byte_38__bit_1" : "byte_43__bit_1" },
        { "bit_4", vca ? "byte_38__bit_2" : "byte_43__bit_2" },
        { "bit_5", vca ? "byte_38__bit_3" : "byte_43__bit_3" },
        { "bit_6", vca ? "byte_38__bit_4" : "byte_43__bit_4" },
        { "bit_7", vca ? "byte_38__bit_5" : "byte_43__bit_5" },
        { "bit_8", vca ? "byte_38__bit_6" : "byte_43__bit_6" },
        { "bit_9", vca ? "byte_31__bit_6" : "byte_39__bit_3" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::env_decay(const bool vca) {
    return {
        ID::tree_bit_locations, {
        { "bit_0", vca ? "byte_65__bit_2" : "byte_66__bit_2" },
        { "bit_1", vca ? "byte_65__bit_3" : "byte_66__bit_3" },
        { "bit_2", vca ? "byte_40__bit_0" : "byte_44__bit_0" },
        { "bit_3", vca ? "byte_40__bit_1" : "byte_44__bit_1" },
        { "bit_4", vca ? "byte_40__bit_2" : "byte_44__bit_2" },
        { "bit_5", vca ? "byte_40__bit_3" : "byte_44__bit_3" },
        { "bit_6", vca ? "byte_40__bit_4" : "byte_44__bit_4" },
        { "bit_7", vca ? "byte_40__bit_5" : "byte_44__bit_5" },
        { "bit_8", vca ? "byte_40__bit_6" : "byte_44__bit_6" },
        { "bit_9", vca ? "byte_39__bit_0" : "byte_39__bit_4" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::env_release(const bool vca) {
    return {
        ID::tree_bit_locations, {
        { "bit_0", vca ? "byte_65__bit_6" : "byte_66__bit_6" },
        { "bit_1", vca ? "byte_63__bit_1" : "byte_63__bit_2" },
        { "bit_2", vca ? "byte_42__bit_0" : "byte_46__bit_0" },
        { "bit_3", vca ? "byte_42__bit_1" : "byte_46__bit_1" },
        { "bit_4", vca ? "byte_42__bit_2" : "byte_46__bit_2" },
        { "bit_5", vca ? "byte_42__bit_3" : "byte_46__bit_3" },
        { "bit_6", vca ? "byte_42__bit_4" : "byte_46__bit_4" },
        { "bit_7", vca ? "byte_42__bit_5" : "byte_46__bit_5" },
        { "bit_8", vca ? "byte_42__bit_6" : "byte_46__bit_6" },
        { "bit_9", vca ? "byte_39__bit_2" : "byte_39__bit_6" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::env_sustain(const bool vca) {
    return {
        ID::tree_bit_locations, {
        { "bit_0", vca ? "byte_65__bit_4" : "byte_66__bit_4" },
        { "bit_1", vca ? "byte_65__bit_5" : "byte_66__bit_5" },
        { "bit_2", vca ? "byte_41__bit_0" : "byte_45__bit_0" },
        { "bit_3", vca ? "byte_41__bit_1" : "byte_45__bit_1" },
        { "bit_4", vca ? "byte_41__bit_2" : "byte_45__bit_2" },
        { "bit_5", vca ? "byte_41__bit_3" : "byte_45__bit_3" },
        { "bit_6", vca ? "byte_41__bit_4" : "byte_45__bit_4" },
        { "bit_7", vca ? "byte_41__bit_5" : "byte_45__bit_5" },
        { "bit_8", vca ? "byte_41__bit_6" : "byte_45__bit_6" },
        { "bit_9", vca ? "byte_39__bit_1" : "byte_39__bit_5" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::level_knob(const int k) {
    return {
        ID::tree_bit_locations, {
        { "bit_0", k == 1 ? "byte_61__bit_4" : k == 2 ? "byte_61__bit_6" : "byte_62__bit_2" },
        { "bit_1", k == 1 ? "byte_61__bit_5" : k == 2 ? "byte_55__bit_5" : "byte_62__bit_3" },
        { "bit_2", k == 1 ? "byte_29__bit_0" : k == 2 ? "byte_30__bit_0" : "byte_32__bit_0" },
        { "bit_3", k == 1 ? "byte_29__bit_1" : k == 2 ? "byte_30__bit_1" : "byte_32__bit_1" },
        { "bit_4", k == 1 ? "byte_29__bit_2" : k == 2 ? "byte_30__bit_2" : "byte_32__bit_2" },
        { "bit_5", k == 1 ? "byte_29__bit_3" : k == 2 ? "byte_30__bit_3" : "byte_32__bit_3" },
        { "bit_6", k == 1 ? "byte_29__bit_4" : k == 2 ? "byte_30__bit_4" : "byte_32__bit_4" },
        { "bit_7", k == 1 ? "byte_29__bit_5" : k == 2 ? "byte_30__bit_5" : "byte_32__bit_5" },
        { "bit_8", k == 1 ? "byte_29__bit_6" : k == 2 ? "byte_30__bit_6" : "byte_32__bit_6" },
        { "bit_9", k == 1 ? "byte_23__bit_5" : k == 2 ? "byte_23__bit_6" : "byte_31__bit_0" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::lfo_eg_mod() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_67__bit_6" },
        { "bit_1", "byte_63__bit_3" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::lfo_int() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_67__bit_2" },
        { "bit_1", "byte_67__bit_3" },
        { "bit_2", "byte_39__bit_0" },
        { "bit_3", "byte_39__bit_1" },
        { "bit_4", "byte_39__bit_2" },
        { "bit_5", "byte_39__bit_3" },
        { "bit_6", "byte_39__bit_4" },
        { "bit_7", "byte_39__bit_5" },
        { "bit_8", "byte_39__bit_6" },
        { "bit_9", "byte_47__bit_1" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::lfo_rate() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_67__bit_0" },
        { "bit_1", "byte_67__bit_1" },
        { "bit_2", "byte_48__bit_0" },
        { "bit_3", "byte_48__bit_1" },
        { "bit_4", "byte_48__bit_2" },
        { "bit_5", "byte_48__bit_3" },
        { "bit_6", "byte_48__bit_4" },
        { "bit_7", "byte_48__bit_5" },
        { "bit_8", "byte_48__bit_6" },
        { "bit_9", "byte_47__bit_0" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::lfo_target() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_67__bit_4" },
        { "bit_1", "byte_67__bit_5" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::lfo_wave() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_68__bit_0" },
        { "bit_1", "byte_68__bit_1" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::lpf_eg_int() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_64__bit_0" },
        { "bit_1", "byte_64__bit_1" },
        { "bit_2", "byte_35__bit_0" },
        { "bit_3", "byte_35__bit_1" },
        { "bit_4", "byte_35__bit_2" },
        { "bit_5", "byte_35__bit_3" },
        { "bit_6", "byte_35__bit_4" },
        { "bit_7", "byte_35__bit_5" },
        { "bit_8", "byte_35__bit_6" },
        { "bit_9", "byte_31__bit_3" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::lpf_freq() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_62__bit_4" },
        { "bit_1", "byte_62__bit_5" },
        { "bit_2", "byte_33__bit_0" },
        { "bit_3", "byte_33__bit_1" },
        { "bit_4", "byte_33__bit_2" },
        { "bit_5", "byte_33__bit_3" },
        { "bit_6", "byte_33__bit_4" },
        { "bit_7", "byte_33__bit_5" },
        { "bit_8", "byte_33__bit_6" },
        { "bit_9", "byte_31__bit_1" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::lpf_key_track() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_64__bit_4" },
        { "bit_1", "byte_64__bit_5" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::lpf_reso() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_62__bit_6" },
        { "bit_1", "byte_55__bit_6" },
        { "bit_2", "byte_34__bit_0" },
        { "bit_3", "byte_34__bit_1" },
        { "bit_4", "byte_34__bit_2" },
        { "bit_5", "byte_34__bit_3" },
        { "bit_6", "byte_34__bit_4" },
        { "bit_7", "byte_34__bit_5" },
        { "bit_8", "byte_34__bit_6" },
        { "bit_9", "byte_31__bit_2" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::lpf_type() {
    return { ID::tree_bit_locations, { { "bit_0", "byte_64__bit_6" } } };
}

ValueTree Subtree_Bit_Loc_Exp::lpf_velo_amt() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_64__bit_2" },
        { "bit_1", "byte_64__bit_3" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::osc_2_pitch_eg_int() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_61__bit_2" },
        { "bit_1", "byte_61__bit_3" },
        { "bit_2", "byte_28__bit_0" },
        { "bit_3", "byte_28__bit_1" },
        { "bit_4", "byte_28__bit_2" },
        { "bit_5", "byte_28__bit_3" },
        { "bit_6", "byte_28__bit_4" },
        { "bit_7", "byte_28__bit_5" },
        { "bit_8", "byte_28__bit_6" },
        { "bit_9", "byte_23__bit_4" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::osc_2_ring_mod() {
    return { ID::tree_bit_locations, { { "bit_0", "byte_62__bit_1" } } };
}

ValueTree Subtree_Bit_Loc_Exp::osc_2_sync() {
    return { ID::tree_bit_locations, { { "bit_0", "byte_62__bit_0" } } };
}

ValueTree Subtree_Bit_Loc_Exp::osc_2_x_mod_depth() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_61__bit_0" },
        { "bit_1", "byte_61__bit_1" },
        { "bit_2", "byte_27__bit_0" },
        { "bit_3", "byte_27__bit_1" },
        { "bit_4", "byte_27__bit_2" },
        { "bit_5", "byte_27__bit_3" },
        { "bit_6", "byte_27__bit_4" },
        { "bit_7", "byte_27__bit_5" },
        { "bit_8", "byte_27__bit_6" },
        { "bit_9", "byte_23__bit_3" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::osc_octave(const int o) {
    return {
        ID::tree_bit_locations, {
        { "bit_0", o == 1 ? "byte_59__bit_4" : "byte_60__bit_4" },
        { "bit_1", o == 1 ? "byte_59__bit_5" : "byte_60__bit_5" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::osc_pitch_fine(const int o) {
    return {
        ID::tree_bit_locations, {
        { "bit_0", o == 1 ? "byte_59__bit_0" : "byte_60__bit_0" },
        { "bit_1", o == 1 ? "byte_59__bit_1" : "byte_60__bit_1" },
        { "bit_2", o == 1 ? "byte_22__bit_0" : "byte_25__bit_0" },
        { "bit_3", o == 1 ? "byte_22__bit_1" : "byte_25__bit_1" },
        { "bit_4", o == 1 ? "byte_22__bit_2" : "byte_25__bit_2" },
        { "bit_5", o == 1 ? "byte_22__bit_3" : "byte_25__bit_3" },
        { "bit_6", o == 1 ? "byte_22__bit_4" : "byte_25__bit_4" },
        { "bit_7", o == 1 ? "byte_22__bit_5" : "byte_25__bit_5" },
        { "bit_8", o == 1 ? "byte_22__bit_6" : "byte_25__bit_6" },
        { "bit_9", o == 1 ? "byte_15__bit_6" : "byte_23__bit_1" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::osc_shape(const int o) {
    return {
        ID::tree_bit_locations, {
        { "bit_0", o == 1 ? "byte_59__bit_2" : "byte_60__bit_2" },
        { "bit_1", o == 1 ? "byte_59__bit_3" : "byte_60__bit_3" },
        { "bit_2", o == 1 ? "byte_24__bit_0" : "byte_26__bit_0" },
        { "bit_3", o == 1 ? "byte_24__bit_1" : "byte_26__bit_1" },
        { "bit_4", o == 1 ? "byte_24__bit_2" : "byte_26__bit_2" },
        { "bit_5", o == 1 ? "byte_24__bit_3" : "byte_26__bit_3" },
        { "bit_6", o == 1 ? "byte_24__bit_4" : "byte_26__bit_4" },
        { "bit_7", o == 1 ? "byte_24__bit_5" : "byte_26__bit_5" },
        { "bit_8", o == 1 ? "byte_24__bit_6" : "byte_26__bit_6" },
        { "bit_9", o == 1 ? "byte_23__bit_0" : "byte_23__bit_2" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::osc_wave(const int o) {
    return {
        ID::tree_bit_locations, {
        { "bit_0", o == 1 ? "byte_59__bit_6" : "byte_60__bit_6" },
        { "bit_1", o == 1 ? "byte_55__bit_3" : "byte_55__bit_4" } }
    };
}

ValueTree Subtree_Bit_Loc_Exp::voice_mode_depth() {
    return {
        ID::tree_bit_locations, {
        { "bit_0", "byte_73__bit_4" },
        { "bit_1", "byte_73__bit_5" },
        { "bit_2", "byte_80__bit_0" },
        { "bit_3", "byte_80__bit_1" },
        { "bit_4", "byte_80__bit_2" },
        { "bit_5", "byte_80__bit_3" },
        { "bit_6", "byte_80__bit_4" },
        { "bit_7", "byte_80__bit_5" },
        { "bit_8", "byte_80__bit_6" },
        { "bit_9", "byte_79__bit_0" } }
    };
}
