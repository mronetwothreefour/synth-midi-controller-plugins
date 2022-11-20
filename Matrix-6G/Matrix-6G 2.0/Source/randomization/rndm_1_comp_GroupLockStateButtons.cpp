#include "rndm_1_comp_GroupLockStateButtons.h"

#include "rndm_0_func_GroupLockStateMethods.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_2_tree_ParamRandomizationOptions.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using Lock = GroupLockStateMethods;

GroupLockStateButtons::GroupLockStateButtons(LockStateGroup group, ParamRandomizationOptions* randomization, TooltipsOptions* tooltips) :
	btn_Lock{ "" },
	btn_Unlock{ "" }
{
	btn_Lock.setComponentID(ID::btn_GroupLock.toString());
	btn_Unlock.setComponentID(ID::btn_GroupUnlock.toString());

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
	case LockStateGroup::osc:
		btn_Lock.onClick = [this, randomization] { Lock::allOscParams(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allOscParams(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related\nto the oscillators." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related\nto the oscillators." : "");
		break;
	case LockStateGroup::vcf:
		btn_Lock.onClick = [this, randomization] { Lock::all_VCF_Params(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::all_VCF_Params(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related\nto the voltage-controlled filter." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related\nto the voltage-controlled filter." : "");
		break;
	case LockStateGroup::vca:
		btn_Lock.onClick = [this, randomization] { Lock::all_VCA_Params(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::all_VCA_Params(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related to the VCAs." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related to the VCAs." : "");
		break;
	case LockStateGroup::vcf_FM:
		btn_Lock.onClick = [this, randomization] { Lock::all_VCF_FM_Params(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::all_VCF_FM_Params(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related to VCF FM." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related to VCF FM." : "");
		break;
	case LockStateGroup::porta:
		btn_Lock.onClick = [this, randomization] { Lock::allPortamentoParams(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allPortamentoParams(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related to portamento." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related to portamento." : "");
		break;
	case LockStateGroup::lfo:
		btn_Lock.onClick = [this, randomization] { Lock::all_LFO_Params(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::all_LFO_Params(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related to the LFOs." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related to the LFOs." : "");
		break;
	case LockStateGroup::ramp:
		btn_Lock.onClick = [this, randomization] { Lock::allRampParams(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allRampParams(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related to the ramps." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related to the ramps." : "");
		break;
	case LockStateGroup::tracking:
		btn_Lock.onClick = [this, randomization] { Lock::allTrackingParams(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allTrackingParams(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related to the ramps." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related to the ramps." : "");
		break;
	case LockStateGroup::env_1:
		btn_Lock.onClick = [this, randomization] { Lock::allEnvelopeParams(1, randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allEnvelopeParams(1, randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls\nrelated to envelope 1." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls\nrelated to envelope 1." : "");
		break;
	case LockStateGroup::env_2:
		btn_Lock.onClick = [this, randomization] { Lock::allEnvelopeParams(2, randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allEnvelopeParams(2, randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls\nrelated to envelope 2." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls\nrelated to envelope 2." : "");
		break;
	case LockStateGroup::env_3:
		btn_Lock.onClick = [this, randomization] { Lock::allEnvelopeParams(3, randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allEnvelopeParams(3, randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls\nrelated to envelope 3." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls\nrelated to envelope 3." : "");
		break;
	case LockStateGroup::matrixMod:
		btn_Lock.onClick = [this, randomization] { Lock::allMatrixModParams(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allMatrixModParams(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls\nrelated to matrix modulation." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls\nrelated to matrix modulation." : "");
		break;
	default:
		break;
	}

	btn_Lock.setBounds(0, 0, 14, 20);
	btn_Unlock.setBounds(17, 0, 14, 20);

	addAndMakeVisible(btn_Lock);
	addAndMakeVisible(btn_Unlock);

	setSize(31, 20);
}
