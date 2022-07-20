#include "rndm_4_gui_layer_Randomization.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using Step = SeqTrackStepNum;
using Track = SeqTrackNum;
using Type = AllowedChoicesType;



GUI_Layer_Randomization::GUI_Layer_Randomization(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	state{ exposedParams->state.get() },
	exposedParams{ exposedParams },
	info{ exposedParams->info.get() },
	randomization{ exposedParams->randomization.get() },
	button_Close{ unexposedParams },
	transmitType{ randomization, unexposedParams },
	allowedChoicesLayers{ exposedParams, unexposedParams },
	lockStateButtons_All{ LockStateGroup::all, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_Osc{ LockStateGroup::osc, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_LPF{ LockStateGroup::lpf, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_VCA{ LockStateGroup::vca, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_LFO_1{ LockStateGroup::lfo_1, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_LFO_2{ LockStateGroup::lfo_2, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_LFO_3{ LockStateGroup::lfo_3, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_LFO_4{ LockStateGroup::lfo_4, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_Env_3{ LockStateGroup::env_3, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_Modulators{ LockStateGroup::modulators, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_MIDI_Controllers{ LockStateGroup::midiControllers, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_PushIt{ LockStateGroup::pushIt, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_KnobAssign{ LockStateGroup::knobAssign, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_SeqTrack_1{ LockStateGroup::seqTrack_1, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_SeqTrack_2{ LockStateGroup::seqTrack_2, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_SeqTrack_3{ LockStateGroup::seqTrack_3, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_SeqTrack_4{ LockStateGroup::seqTrack_4, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() },
	lockStateButtons_VoiceNamerChars{ LockStateGroup::voiceNameChars, exposedParams->randomization.get(), unexposedParams->getTooltipsOptions() }
{
	setInterceptsMouseClicks(false, true);

	button_Close.setTopLeftPosition(1208, 16);
	addAndMakeVisible(button_Close);

	transmitType.setTopLeftPosition(1138, 81);
	addAndMakeVisible(transmitType);

	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		paramLockToggles[paramIndex].reset(new LockToggleForParam{ paramIndex, exposedParams, });
		paramLockToggles[paramIndex]->addListener(this);
		paramLockToggles[paramIndex]->addMouseListener(this, false);
		paramLockToggles[paramIndex]->setCentrePosition(info->centerPointFor(paramIndex));
		addAndMakeVisible(paramLockToggles[paramIndex].get());
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
	if (event.mods == ModifierKeys::rightButtonModifier) {
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
				auto trackNum{ info->seqTrackNum_For(paramIndex) };
				if (randomization->targetStepForSeqTrack(Track{ trackNum }) != Step::all) {
					auto clickedStep{ info->seqTrackStepNum_For(paramIndex) };
					randomization->setTargetStepForSeqTrack(Step{ clickedStep }, Track{ trackNum });
				}
				auto trackDestParamID{ info->IDfor(uint8(100 + trackNum)) };
				auto paramPtr{ exposedParams->state->getParameter(trackDestParamID) };
				if (paramPtr != nullptr) {
					auto trackDest{ paramPtr->convertFrom0to1(paramPtr->getValue()) };
					auto destIsPitched{ trackDest > 0.0f && trackDest < 4.0f };
					allowedChoicesLayers.showAllowedChoicesLayerForSeqTrack(Track{ trackNum }, destIsPitched);
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
