#include "rndm_1_comp_GroupLockStateButtons.h"

#include "rndm_0_func_GroupLockStateMethods.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_2_tree_ExposedParamsRandomizationOptions.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using Lock = GroupLockStateMethods;

GroupLockStateButtons::GroupLockStateButtons(LockStateGroup group, ExposedParamsRandomizationOptions* randomization, TooltipsOptions* tooltips) :
	btn_Lock{ "" },
	btn_Unlock{ "" }
{
	btn_Lock.setComponentID(group == LockStateGroup::all ? ID::btn_GroupLock_All.toString() : ID::btn_GroupLock.toString());
	btn_Unlock.setComponentID(group == LockStateGroup::all ? ID::btn_GroupUnlock_All.toString() : ID::btn_GroupUnlock.toString());

	auto shouldShow{ tooltips->shouldShowDescription() };
	switch (group)
	{
	case LockStateGroup::all:
		btn_Lock.onClick = [this, randomization] { Lock::allParams(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allParams(randomization, false); };
		btn_Lock.addShortcut(KeyPress{ 'a', ModifierKeys::ctrlModifier, 0 });
		btn_Unlock.addShortcut(KeyPress{ 'u', ModifierKeys::ctrlModifier, 0 });
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls.\nShortcut key: CTRL+A" : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls.\nShortcut key: CTRL+U" : "");
		break;
	case LockStateGroup::osc_A:
		btn_Lock.onClick = [this, randomization] { Lock::allOsc_A_Params(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allOsc_A_Params(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls\nrelated to oscillator A." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls\nrelated to oscillator A." : "");
		break;
	case LockStateGroup::osc_B:
		btn_Lock.onClick = [this, randomization] { Lock::allOsc_B_Params(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allOsc_B_Params(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls\nrelated to oscillator B." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls\nrelated to oscillator B." : "");
		break;
	case LockStateGroup::filter:
		btn_Lock.onClick = [this, randomization] { Lock::allFilterParams(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allFilterParams(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related\nto the low-pass filter." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related\nto the low-pass filter." : "");
		break;
	case LockStateGroup::amp:
		btn_Lock.onClick = [this, randomization] { Lock::allAmpParams(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allAmpParams(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related\nto the amplifier envelope." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related\nto the amplifier envelope." : "");
		break;
	case LockStateGroup::polyMod:
		btn_Lock.onClick = [this, randomization] { Lock::allPolyModParams(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allPolyModParams(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls\nrelated to poly-mod." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls\nrelated to poly-mod." : "");
		break;
	case LockStateGroup::lfo:
		btn_Lock.onClick = [this, randomization] { Lock::all_LFO_Params(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::all_LFO_Params(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related\nto the low-frequency oscillator." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related\nto the low-frequency oscillator." : "");
		break;
	default:
		break;
	}

	auto buttons_h{ group == LockStateGroup::all ? GUI::buttons_h : 20 };
	auto buttons_w{ group == LockStateGroup::all ? GUI::buttons_w : 14 };
	btn_Lock.setBounds(0, 0, buttons_w, buttons_h);
	btn_Unlock.setBounds(group == LockStateGroup::all ? 50 : 16, 0, buttons_w, buttons_h);

	addAndMakeVisible(btn_Lock);
	addAndMakeVisible(btn_Unlock);

	setSize(group == LockStateGroup::all ? 90 : 30, buttons_h);
}
