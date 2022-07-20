#include "rndm_1_comp_GroupLockStateButtons.h"

#include "rndm_0_func_GroupLockStateMethods.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_2_tree_ExposedParamsRandomizationOptions.h"
#include "../unexposedParameters/up_tree_TooltipsOptions.h"

using Lock = GroupLockStateMethods;
using Track = SeqTrackNum;



GroupLockStateButtons::GroupLockStateButtons(LockStateGroup group, ExposedParamsRandomizationOptions* randomization, TooltipsOptions* tooltips) :
	button_Lock{ "" },
	button_Unlock{ "" }
{
	button_Lock.setComponentID(ID::button_GroupLock.toString());
	button_Unlock.setComponentID(ID::button_GroupUnlock.toString());

	auto shouldShow{ tooltips->shouldShowDescriptions() };
	switch (group)
	{
	case MophoConstants::LockStateGroup::all:
		button_Lock.onClick = [this, randomization] { Lock::allParams(randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::allParams(randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the controls." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the controls." : "");
		break;
	case MophoConstants::LockStateGroup::osc:
		button_Lock.onClick = [this, randomization] { Lock::allOscParams(randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::allOscParams(randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the controls related\nto the oscillators." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the controls related\nto the oscillators." : "");
		break;
	case MophoConstants::LockStateGroup::lpf:
		button_Lock.onClick = [this, randomization] { Lock::all_LPF_Params(randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::all_LPF_Params(randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the controls related\nto the low-pass filter." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the controls related\nto the low-pass filter." : "");
		break;
	case MophoConstants::LockStateGroup::vca:
		button_Lock.onClick = [this, randomization] { Lock::all_VCA_Params(randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::all_VCA_Params(randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the controls related to the VCA." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the controls related to the VCA." : "");
		break;
	case MophoConstants::LockStateGroup::lfo_1:
		button_Lock.onClick = [this, randomization] { Lock::all_LFO_Params(1, randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::all_LFO_Params(1, randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the controls related to LFO 1." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the controls related to LFO 1." : "");
		break;
	case MophoConstants::LockStateGroup::lfo_2:
		button_Lock.onClick = [this, randomization] { Lock::all_LFO_Params(2, randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::all_LFO_Params(2, randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the controls related to LFO 2." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the controls related to LFO 2." : "");
		break;
	case MophoConstants::LockStateGroup::lfo_3:
		button_Lock.onClick = [this, randomization] { Lock::all_LFO_Params(3, randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::all_LFO_Params(3, randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the controls related to LFO 3." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the controls related to LFO 3." : "");
		break;
	case MophoConstants::LockStateGroup::lfo_4:
		button_Lock.onClick = [this, randomization] { Lock::all_LFO_Params(4, randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::all_LFO_Params(4, randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the controls related to LFO 4." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the controls related to LFO 4." : "");
		break;
	case MophoConstants::LockStateGroup::env_3:
		button_Lock.onClick = [this, randomization] { Lock::allEnv_3_Params(randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::allEnv_3_Params(randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the controls\nrelated to envelope 3." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the controls\nrelated to envelope 3." : "");
		break;
	case MophoConstants::LockStateGroup::modulators:
		button_Lock.onClick = [this, randomization] { Lock::allModulatorParams(randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::allModulatorParams(randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the controls\nrelated to the modulators." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the controls\nrelated to the modulators." : "");
		break;
	case MophoConstants::LockStateGroup::midiControllers:
		button_Lock.onClick = [this, randomization] { Lock::all_MIDI_ControllerParams(randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::all_MIDI_ControllerParams(randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the controls\nrelated to MIDI controllers." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the controls\nrelated to MIDI controllers." : "");
		break;
	case MophoConstants::LockStateGroup::pushIt:
		button_Lock.onClick = [this, randomization] { Lock::allPushItParams(randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::allPushItParams(randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the controls\nrelated to the Push It! switch." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the controls\nrelated to the Push It! switch." : "");
		break;
	case MophoConstants::LockStateGroup::knobAssign:
		button_Lock.onClick = [this, randomization] { Lock::allKnobAssignParams(randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::allKnobAssignParams(randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the knob assign controls." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the knob assign controls." : "");
		break;
	case MophoConstants::LockStateGroup::seqTrack_1:
		button_Lock.onClick = [this, randomization] { Lock::allSeqTrackParams(Track::one, randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::allSeqTrackParams(Track::one, randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the controls related\nto sequencer track 1." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the controls related\nto sequencer track 1." : "");
		break;
	case MophoConstants::LockStateGroup::seqTrack_2:
		button_Lock.onClick = [this, randomization] { Lock::allSeqTrackParams(Track::two, randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::allSeqTrackParams(Track::two, randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the controls related\nto sequencer track 2." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the controls related\nto sequencer track 2." : "");
		break;
	case MophoConstants::LockStateGroup::seqTrack_3:
		button_Lock.onClick = [this, randomization] { Lock::allSeqTrackParams(Track::three, randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::allSeqTrackParams(Track::three, randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the controls related\nto sequencer track 3." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the controls related\nto sequencer track 3." : "");
		break;
	case MophoConstants::LockStateGroup::seqTrack_4:
		button_Lock.onClick = [this, randomization] { Lock::allSeqTrackParams(Track::four, randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::allSeqTrackParams(Track::four, randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the controls related\nto sequencer track 4." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the controls related\nto sequencer track 4." : "");
		break;
	case MophoConstants::LockStateGroup::voiceNameChars:
		button_Lock.onClick = [this, randomization] { Lock::allVoiceNameChars(randomization, true); };
		button_Unlock.onClick = [this, randomization] { Lock::allVoiceNameChars(randomization, false); };
		button_Lock.setTooltip(shouldShow ? "Lock all the program name characters." : "");
		button_Unlock.setTooltip(shouldShow ? "Unlock all the program name characters." : "");
		break;
	default:
		break;
	}

	button_Lock.setBounds(0, 0, 14, 20);
	button_Unlock.setBounds(17, 0, 14, 20);

	addAndMakeVisible(button_Lock);
	addAndMakeVisible(button_Unlock);

	setSize(31, 20);
}
