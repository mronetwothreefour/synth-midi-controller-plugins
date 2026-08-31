#include "D_BUILD_Init_Bounds_For_P.h"

#include "C_XYWH_P.h"

using namespace BUILD;
using namespace XYWH;

const int Init_Bounds_For::ctrl_row_y(const int r) {
    return ctrl_row_0_y + r * ctrl_row_h;
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_env(const int n, const int r) {
    auto x = env_ctrl_col_x + ((n - 1) * env_block_spacing);
    auto y = env_ctrl_row_0_y + r * ctrl_row_h;
    return { x, y, env_ctrl_w, ctrl_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_env_stage(const int e, const int s) {
    auto x = env_1_stage_0_x + (s * env_stage_spacing) + ((e - 1) * env_block_spacing);
    auto y = env_ctrl_row_0_y + 3 * ctrl_row_h;
    return { x, y, env_stage_ctrl_w, ctrl_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_lfo(const int n, const int r) {
    return { n == 1 ? lfo_col_1_x : lfo_col_2_x, ctrl_row_y(r), lfo_ctrl_w, ctrl_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_osc(const int n, const int r) {
    return { n == 1 ? osc_col_1_x : osc_col_2_x, ctrl_row_y(r), osc_ctrl_w, ctrl_h};
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_ramp(const int n, const int r) {
    return { n == 1 ? ramp_col_1_x : ramp_col_2_x, ctrl_row_y(r), ramp_ctrl_w, ctrl_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_osc_balance() {
    return { osc_col_1_x, ctrl_row_y(10), 126, ctrl_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_porta_key_mode(const int r) {
    return { porta_key_mode_col_x, ctrl_row_y(r), porta_key_mode_ctrl_w, ctrl_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_track_input() {
    return { track_input_x, track_input_y, track_input_w, ctrl_h };
}

const Rectangle<int> BUILD::Init_Bounds_For::exp_ctrl_track_pt(const int n) {
    return { track_pt_1_x + ((n - 1) * track_pt_spacing), track_pt_y, track_pt_w, ctrl_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_vcf_fm(const int r) {
    return { vcf_fm_col_x, ctrl_row_y(r), vcf_fm_ctrl_w, ctrl_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_vcf_vca(const int r) {
    return { vcf_vca_col_x, ctrl_row_y(r), vcf_vca_ctrl_w, ctrl_h };
}

const Rectangle<int> BUILD::Init_Bounds_For::mmod_ctrl_amt(const int n) {
    return { mmod_col_amt_x, ctrl_row_0_y + n * ctrl_row_h, mmod_ctrl_amt_w, ctrl_h };
}

const Rectangle<int> BUILD::Init_Bounds_For::mmod_ctrl_dst(const int n) {
    return { mmod_col_dest_x, ctrl_row_0_y + n * ctrl_row_h, mmod_ctrl_src_dest_w, ctrl_h };
}

const Rectangle<int> BUILD::Init_Bounds_For::mmod_ctrl_src(const int n) {
    return { mmod_col_src_x, ctrl_row_0_y + n * ctrl_row_h, mmod_ctrl_src_dest_w, ctrl_h };
}
