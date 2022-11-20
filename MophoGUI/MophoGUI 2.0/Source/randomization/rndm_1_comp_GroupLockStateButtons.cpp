#include "rndm_1_comp_GroupLockStateButtons.h"

#include "rndm_0_func_GroupLockStateMethods.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_2_tree_ExposedParamsRandomizationOptions.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using Lock = GroupLockStateMethods;
using Track = SeqTrackNum;

GroupLockStateButtons::GroupLockStateButtons(LockStateGroup group, ExposedParamsRandomizationOptions* randomization, TooltipsOptions* tooltips) :
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
	case LockStateGroup::lpf:
		btn_Lock.onClick = [this, randomization] { Lock::all_LPF_Params(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::all_LPF_Params(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related\nto the low-pass filter." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related\nto the low-pass filter." : "");
		break;
	case LockStateGroup::vca:
		btn_Lock.onClick = [this, randomization] { Lock::all_VCA_Params(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::all_VCA_Params(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related to the VCA." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related to the VCA." : "");
		break;
	case LockStateGroup::lfo_1:
		btn_Lock.onClick = [this, randomization] { Lock::all_LFO_Params(1, randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::all_LFO_Params(1, randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related to LFO 1." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related to LFO 1." : "");
		break;
	case LockStateGroup::lfo_2:
		btn_Lock.onClick = [this, randomization] { Lock::all_LFO_Params(2, randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::all_LFO_Params(2, randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related to LFO 2." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related to LFO 2." : "");
		break;
	case LockStateGroup::lfo_3:
		btn_Lock.onClick = [this, randomization] { Lock::all_LFO_Params(3, randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::all_LFO_Params(3, randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related to LFO 3." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related to LFO 3." : "");
		break;
	case LockStateGroup::lfo_4:
		btn_Lock.onClick = [this, randomization] { Lock::all_LFO_Params(4, randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::all_LFO_Params(4, randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related to LFO 4." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related to LFO 4." : "");
		break;
	case LockStateGroup::env_3:
		btn_Lock.onClick = [this, randomization] { Lock::allEnv_3_Params(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allEnv_3_Params(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls\nrelated to envelope 3." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls\nrelated to envelope 3." : "");
		break;
	case LockStateGroup::modulators:
		btn_Lock.onClick = [this, randomization] { Lock::allModulatorParams(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allModulatorParams(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls\nrelated to the modulators." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls\nrelated to the modulators." : "");
		break;
	case LockStateGroup::midiControllers:
		btn_Lock.onClick = [this, randomization] { Lock::all_MIDI_ControllerParams(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::all_MIDI_ControllerParams(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls\nrelated to MIDI controllers." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls\nrelated to MIDI controllers." : "");
		break;
	case LockStateGroup::pushIt:
		btn_Lock.onClick = [this, randomization] { Lock::allPushItParams(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allPushItParams(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls\nrelated to the Push It! switch." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls\nrelated to the Push It! switch." : "");
		break;
	case LockStateGroup::knobAssign:
		btn_Lock.onClick = [this, randomization] { Lock::allKnobAssignParams(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allKnobAssignParams(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the knob assign controls." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the knob assign controls." : "");
		break;
	case LockStateGroup::seqTrack_1:
		btn_Lock.onClick = [this, randomization] { Lock::allSeqTrackParams(Track::one, randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allSeqTrackParams(Track::one, randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related\nto sequencer track 1." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related\nto sequencer track 1." : "");
		break;
	case LockStateGroup::seqTrack_2:
		btn_Lock.onClick = [this, randomization] { Lock::allSeqTrackParams(Track::two, randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allSeqTrackParams(Track::two, randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related\nto sequencer track 2." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related\nto sequencer track 2." : "");
		break;
	case LockStateGroup::seqTrack_3:
		btn_Lock.onClick = [this, randomization] { Lock::allSeqTrackParams(Track::three, randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allSeqTrackParams(Track::three, randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related\nto sequencer track 3." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related\nto sequencer track 3." : "");
		break;
	case LockStateGroup::seqTrack_4:
		btn_Lock.onClick = [this, randomization] { Lock::allSeqTrackParams(Track::four, randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allSeqTrackParams(Track::four, randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the controls related\nto sequencer track 4." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the controls related\nto sequencer track 4." : "");
		break;
	case LockStateGroup::voiceNameChars:
		btn_Lock.onClick = [this, randomization] { Lock::allVoiceNameChars(randomization, true); };
		btn_Unlock.onClick = [this, randomization] { Lock::allVoiceNameChars(randomization, false); };
		btn_Lock.setTooltip(shouldShow ? "Lock all the program name characters." : "");
		btn_Unlock.setTooltip(shouldShow ? "Unlock all the program name characters." : "");
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
