#include "rndm_4_gui_layer_Randomization.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using Step = SeqTrackStepNum;
using Track = SeqTrackNum;
using Type = AllowedChoicesType;

GUI_Layer_Randomization::GUI_Layer_Randomization(ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	state{ exposedParams->state.get() },
	exposedParams{ exposedParams },
	info{ exposedParams->info.get() },
	randomization{ exposedParams->randomization.get() },
	btn_Close{ tooltips },
	transmitType{ randomization, tooltips },
	allowedChoicesLayers{ exposedParams, tooltips },
	lockStateButtons_All{ LockStateGroup::all, exposedParams->randomization.get(), tooltips },
	lockStateButtons_Osc{ LockStateGroup::osc, exposedParams->randomization.get(), tooltips },
	lockStateButtons_LPF{ LockStateGroup::lpf, exposedParams->randomization.get(), tooltips },
	lockStateButtons_VCA{ LockStateGroup::vca, exposedParams->randomization.get(), tooltips },
	lockStateButtons_LFO_1{ LockStateGroup::lfo_1, exposedParams->randomization.get(), tooltips },
	lockStateButtons_LFO_2{ LockStateGroup::lfo_2, exposedParams->randomization.get(), tooltips },
	lockStateButtons_LFO_3{ LockStateGroup::lfo_3, exposedParams->randomization.get(), tooltips },
	lockStateButtons_LFO_4{ LockStateGroup::lfo_4, exposedParams->randomization.get(), tooltips },
	lockStateButtons_Env_3{ LockStateGroup::env_3, exposedParams->randomization.get(), tooltips },
	lockStateButtons_Modulators{ LockStateGroup::modulators, exposedParams->randomization.get(), tooltips },
	lockStateButtons_MIDI_Controllers{ LockStateGroup::midiControllers, exposedParams->randomization.get(), tooltips },
	lockStateButtons_PushIt{ LockStateGroup::pushIt, exposedParams->randomization.get(), tooltips },
	lockStateButtons_KnobAssign{ LockStateGroup::knobAssign, exposedParams->randomization.get(), tooltips },
	lockStateButtons_SeqTrack_1{ LockStateGroup::seqTrack_1, exposedParams->randomization.get(), tooltips },
	lockStateButtons_SeqTrack_2{ LockStateGroup::seqTrack_2, exposedParams->randomization.get(), tooltips },
	lockStateButtons_SeqTrack_3{ LockStateGroup::seqTrack_3, exposedParams->randomization.get(), tooltips },
	lockStateButtons_SeqTrack_4{ LockStateGroup::seqTrack_4, exposedParams->randomization.get(), tooltips },
	lockStateButtons_VoiceNamerChars{ LockStateGroup::voiceNameChars, exposedParams->randomization.get(), tooltips }
{
	setInterceptsMouseClicks(false, true);

	btn_Close.setTopLeftPosition(1208, 16);
	addAndMakeVisible(btn_Close);

	transmitType.setTopLeftPosition(1138, 81);
	addAndMakeVisible(transmitType);

	auto shouldShowDescriptions{ tooltips->shouldShowDescription() };
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		paramLockToggles[paramIndex].reset(new LockToggleForParam{ paramIndex, exposedParams, });
		paramLockToggles[paramIndex]->addListener(this);
		paramLockToggles[paramIndex]->addMouseListener(this, false);
		auto controlCenterPoint{ info->centerPointFor(paramIndex) };
		if (info->allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::binary)
			controlCenterPoint = info->redToggleCenterPointFor(paramIndex);
		paramLockToggles[paramIndex]->setCentrePosition(controlCenterPoint);
		addAndMakeVisible(paramLockToggles[paramIndex].get());
		if (shouldShowDescriptions) {
			String tip{ "" };
			tip += "Click to lock/unlock the parameter.\n";
			tip += "Right-click to specify the choices\n";
			tip += "allowed when randomly generating\n";
			if (info->allowedChoicesTypeFor(paramIndex) == Type::seqTrackStep) {
				tip += "a new setting for all the steps in\n";
				tip += "the sequencer track. ALT+right-click\n";
				tip += "to target a specific step.\n";
			}
			else
				tip += "a new setting for the parameter.";
			paramLockToggles[paramIndex]->setTooltip(tip);
		}
	}

	lockStateButtons_All.setTopLeftPosition(1009, 78);
	lockStateButtons_Osc.setTopLeftPosition(113, 10);
	lockStateButtons_LPF.setTopLeftPosition(40, 149);	
	lockStateButtons_VCA.setTopLeftPosition(47, 307);
	auto lfoLockStateButtons_y{ 475 };
	lockStateButtons_LFO_1.setTopLeftPosition(437, lfoLockStateButtons_y);
	lockStateButtons_LFO_2.setTopLeftPosition(592, lfoLockStateButtons_y);
	lockStateButtons_LFO_3.setTopLeftPosition(747, lfoLockStateButtons_y);
	lockStateButtons_LFO_4.setTopLeftPosition(902, lfoLockStateButtons_y);
	lockStateButtons_Env_3.setTopLeftPosition(101, 465);
	auto modAnd_MIDI_LockStateButtons_y{ 149 };
	lockStateButtons_Modulators.setTopLeftPosition(507, modAnd_MIDI_LockStateButtons_y);
	lockStateButtons_MIDI_Controllers.setTopLeftPosition(752, modAnd_MIDI_LockStateButtons_y);
	auto pushItAndKnobAssignLockStateButtons_y{ 484 };
	lockStateButtons_PushIt.setTopLeftPosition(1232, pushItAndKnobAssignLockStateButtons_y);
	lockStateButtons_KnobAssign.setTopLeftPosition(1107, pushItAndKnobAssignLockStateButtons_y);
	auto seqTrackLockStateButtons_x{ 872 };
	lockStateButtons_SeqTrack_1.setTopLeftPosition(seqTrackLockStateButtons_x, 159);
	lockStateButtons_SeqTrack_2.setTopLeftPosition(seqTrackLockStateButtons_x, 242);
	lockStateButtons_SeqTrack_3.setTopLeftPosition(seqTrackLockStateButtons_x, 325);
	lockStateButtons_SeqTrack_4.setTopLeftPosition(seqTrackLockStateButtons_x, 408);
	lockStateButtons_VoiceNamerChars.setTopLeftPosition(705, 10);

	addAndMakeVisible(lockStateButtons_All);
	addAndMakeVisible(lockStateButtons_Osc);
	addAndMakeVisible(lockStateButtons_LPF);
	addAndMakeVisible(lockStateButtons_VCA);
	addAndMakeVisible(lockStateButtons_LFO_1);
	addAndMakeVisible(lockStateButtons_LFO_2);
	addAndMakeVisible(lockStateButtons_LFO_3);
	addAndMakeVisible(lockStateButtons_LFO_4);
	addAndMakeVisible(lockStateButtons_Env_3);
	addAndMakeVisible(lockStateButtons_Modulators);
	addAndMakeVisible(lockStateButtons_MIDI_Controllers);
	addAndMakeVisible(lockStateButtons_PushIt);
	addAndMakeVisible(lockStateButtons_KnobAssign);
	addAndMakeVisible(lockStateButtons_SeqTrack_1);
	addAndMakeVisible(lockStateButtons_SeqTrack_2);
	addAndMakeVisible(lockStateButtons_SeqTrack_3);
	addAndMakeVisible(lockStateButtons_SeqTrack_4);
	addAndMakeVisible(lockStateButtons_VoiceNamerChars);

	btn_RandomizeAllUnlocked.setComponentID(ID::btn_Randomize.toString());
	btn_RandomizeAllUnlocked.onClick = [exposedParams] { exposedParams->randomize->randomizeAllUnlockedParameters(); };
	btn_RandomizeAllUnlocked.addShortcut(KeyPress{ 'd', ModifierKeys::ctrlModifier, 0 });
	if (shouldShowDescriptions)
		btn_RandomizeAllUnlocked.setTooltip("Click to generate random settings\nfor all unlocked parameters.\nShortcut key: CTRL+D");
	btn_RandomizeAllUnlocked.setBounds(1051, 77, GUI::btn_Randomize_w, GUI::redButton_h);
	addAndMakeVisible(btn_RandomizeAllUnlocked);

	allowedChoicesLayers.setTopLeftPosition(0, 0);
	addAndMakeVisible(allowedChoicesLayers);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_Randomization::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_Randomization_png, BinaryData::bkgrnd_Randomization_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void GUI_Layer_Randomization::mouseDown(const MouseEvent& event) {
	if (event.mods == ModifierKeys::rightButtonModifier || event.mods == ModifierKeys::altModifier + ModifierKeys::rightButtonModifier) {
		toggleWasRightClicked = true;
		auto toggleID{ event.eventComponent->getComponentID() };
		auto paramIndex{ (uint8)toggleID.fromFirstOccurrenceOf("Param_", false, false).getIntValue() };
		auto allowedChoicesType{ info->allowedChoicesTypeFor(paramIndex) };
		switch (allowedChoicesType)
		{
		case MophoConstants::AllowedChoicesType::standard:
			allowedChoicesLayers.showAllowedChoicesLayerForStandardParam(paramIndex);
			break;
		case MophoConstants::AllowedChoicesType::oscShape:
			allowedChoicesLayers.showAllowedChoicesLayerForOscShapeParam(paramIndex);
			break;
		case MophoConstants::AllowedChoicesType::binary:
			allowedChoicesLayers.showAllowedChoicesLayerForBinaryParam(paramIndex);
			break;
		case MophoConstants::AllowedChoicesType::lfoFreq:
			allowedChoicesLayers.showAllowedChoicesLayerForLFO_FreqParam(paramIndex);
			break;
		case MophoConstants::AllowedChoicesType::seqTrackStep: {
				auto track{ info->seqTrackFor(paramIndex) };
				if (event.mods == ModifierKeys::altModifier + ModifierKeys::rightButtonModifier) {
					auto clickedStep{ info->seqTrackStepFor(paramIndex) };
					randomization->setTargetStepForSeqTrack(clickedStep, track);
				}
				else
					randomization->setTargetStepForSeqTrack(Step::all, track);
				auto trackDestParamID{ info->IDfor(uint8(100 + (int)track)) };
				auto paramPtr{ exposedParams->state->getParameter(trackDestParamID) };
				if (paramPtr != nullptr) {
					auto trackDest{ paramPtr->convertFrom0to1(paramPtr->getValue()) };
					auto destIsPitched{ trackDest > 0.0f && trackDest < 4.0f };
					allowedChoicesLayers.showAllowedChoicesLayerForSeqTrack(track, destIsPitched);
				}
			}
			break;
		case MophoConstants::AllowedChoicesType::voiceNameChar:
			allowedChoicesLayers.showAllowedChoicesLayerForVoiceNameCharParam(paramIndex);
			break;
		default:
			break;
		}
	}
}

void GUI_Layer_Randomization::buttonClicked(Button* button) {
	auto paramIndex{ (uint8)button->getComponentID().fromFirstOccurrenceOf("Param_", false, false).getIntValue() };
	if (toggleWasRightClicked) {
		randomization->setParamIsLocked(paramIndex, false);
		paramLockToggles[paramIndex]->setToggleState(false, dontSendNotification);
		if (paramIndex == EP::indexForArpegOnOff) {
			if (state->getParameter(ID::ep_100_SeqOnOff)->getValue() == 1.0f) {
				randomization->setParamIsLocked(EP::indexForSeqOnOff, false);
				paramLockToggles[EP::indexForSeqOnOff]->setToggleState(false, dontSendNotification);
			}
		}
		if (paramIndex == EP::indexForSeqOnOff) {
			if (state->getParameter(ID::ep_098_ArpegOnOff)->getValue() == 1.0f) {
				randomization->setParamIsLocked(EP::indexForArpegOnOff, false);
				paramLockToggles[EP::indexForArpegOnOff]->setToggleState(false, dontSendNotification);
			}
		}
		toggleWasRightClicked = false;
	}
	else {
		auto paramID{ info->IDfor(paramIndex) };
		auto shouldBeLocked{ button->getToggleState() };
		if (paramID == ID::ep_098_ArpegOnOff || paramID == ID::ep_100_SeqOnOff) {
			if (shouldBeLocked) {
				randomization->setParamIsLocked(paramIndex, true);
				if (paramID == ID::ep_098_ArpegOnOff && state->getParameter(ID::ep_098_ArpegOnOff)->getValue() == 1.0f) {
					randomization->setParamIsLocked(EP::indexForSeqOnOff, true);
					paramLockToggles[EP::indexForSeqOnOff]->setToggleState(true, dontSendNotification);
				}
				if (paramID == ID::ep_100_SeqOnOff && state->getParameter(ID::ep_100_SeqOnOff)->getValue() == 1.0f) {
					randomization->setParamIsLocked(EP::indexForArpegOnOff, true);
					paramLockToggles[EP::indexForArpegOnOff]->setToggleState(true, dontSendNotification);
				}
			}
			else {
				if (paramID == ID::ep_098_ArpegOnOff) {
					auto seqIsLockedOn{ randomization->paramIsLocked(100) && state->getParameter(ID::ep_100_SeqOnOff)->getValue() == 1.0f };
					if (seqIsLockedOn == false)
						randomization->setParamIsLocked(paramIndex, false);
					else
						paramLockToggles[paramIndex]->setToggleState(true, dontSendNotification);
				}
				else {
					auto arpegIsLockedOn{ randomization->paramIsLocked(98) && state->getParameter(ID::ep_098_ArpegOnOff)->getValue() == 1.0f };
					if (arpegIsLockedOn == false)
						randomization->setParamIsLocked(paramIndex, false);
					else
						paramLockToggles[paramIndex]->setToggleState(true, dontSendNotification);
				}
			}
		}
		else {
			randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
		}
	}
}

GUI_Layer_Randomization::~GUI_Layer_Randomization() {
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		paramLockToggles[paramIndex]->removeListener(this);
		paramLockToggles[paramIndex]->removeMouseListener(this);
		paramLockToggles[paramIndex] = nullptr;
	}
}
