#include "rndm_3_gui_layer_Randomization.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

GUI_Layer_Randomization::GUI_Layer_Randomization(
	ExposedParameters* exposedParams, TooltipsOptions* tooltips, Outgoing_MIDI_Buffers* outgoingBuffers) :
	state{ exposedParams->state.get() },
	exposedParams{ exposedParams },
	info{ exposedParams->info.get() },
	randomization{ exposedParams->randomization.get() },
	btn_Exit{ tooltips },
	tooltips{ tooltips },
	outgoingBuffers{ outgoingBuffers },
	lockStateButtons_All{ LockStateGroup::all, exposedParams->randomization.get(), tooltips },
	lockStateButtons_Osc_A{ LockStateGroup::osc_A, exposedParams->randomization.get(), tooltips },
	lockStateButtons_Osc_B{ LockStateGroup::osc_B, exposedParams->randomization.get(), tooltips },
	lockStateButtons_Filter{ LockStateGroup::filter, exposedParams->randomization.get(), tooltips },
	lockStateButtons_Amp{ LockStateGroup::amp, exposedParams->randomization.get(), tooltips },
	lockStateButtons_PolyMod{ LockStateGroup::polyMod, exposedParams->randomization.get(), tooltips },
	lockStateButtons_LFO{ LockStateGroup::lfo, exposedParams->randomization.get(), tooltips }
{
	setInterceptsMouseClicks(false, true);

	auto topButtonsRow_y{ 40 };
	lockStateButtons_All.setTopLeftPosition(815, topButtonsRow_y);
	addAndMakeVisible(lockStateButtons_All);

	auto shouldShowDescriptions{ tooltips->shouldShowDescription() };
	btn_RandomizeAllUnlocked.setComponentID(ID::btn_Randomize.toString());
	btn_RandomizeAllUnlocked.onClick = [exposedParams] { exposedParams->randomize->randomizeAllUnlockedParameters(); };
	btn_RandomizeAllUnlocked.addShortcut(KeyPress{ 'd', ModifierKeys::ctrlModifier, 0 });
	if (shouldShowDescriptions)
		btn_RandomizeAllUnlocked.setTooltip("Click to generate random settings\nfor all unlocked parameters.\nShortcut key: CTRL+D");
	btn_RandomizeAllUnlocked.setBounds(915, topButtonsRow_y, GUI::buttons_w, GUI::buttons_h);
	addAndMakeVisible(btn_RandomizeAllUnlocked);

	btn_Exit.setTopLeftPosition(965, topButtonsRow_y);
	addAndMakeVisible(btn_Exit);

	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		lockTogglesForParams[paramIndex].reset(new LockToggleForParam{ paramIndex, exposedParams });
		lockTogglesForParams[paramIndex]->addListener(this);
		lockTogglesForParams[paramIndex]->addMouseListener(this, false);
		auto controlCenterPoint{ info->centerPointFor(paramIndex) };
		lockTogglesForParams[paramIndex]->setCentrePosition(controlCenterPoint);
		addAndMakeVisible(lockTogglesForParams[paramIndex].get());
		if (shouldShowDescriptions) {
			String tip{ "" };
			tip += "Click to lock/unlock the parameter.\n";
			tip += "Right-click to specify the choices\n";
			tip += "allowed when randomly generating\n";
			tip += "a new setting for the parameter.";
			lockTogglesForParams[paramIndex]->setTooltip(tip);
		}
	}

	lockStateButtons_Osc_A.setTopLeftPosition(482, 118);
	lockStateButtons_Osc_B.setTopLeftPosition(482, 256);
	lockStateButtons_Filter.setTopLeftPosition(1076, 17);
	lockStateButtons_Amp.setTopLeftPosition(1076, 256);
	lockStateButtons_PolyMod.setTopLeftPosition(17, 118);
	lockStateButtons_LFO.setTopLeftPosition(17, 256);

	addAndMakeVisible(lockStateButtons_Osc_A);
	addAndMakeVisible(lockStateButtons_Osc_B);
	addAndMakeVisible(lockStateButtons_Filter);
	addAndMakeVisible(lockStateButtons_Amp);
	addAndMakeVisible(lockStateButtons_PolyMod);
	addAndMakeVisible(lockStateButtons_LFO);

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
		auto controlType{ info->controlTypeFor(paramIndex) };
		switch (controlType)
		{
		case P_600_G_Constants::ControlType::knob:
			allowedChoices_Numeric.reset(new GUI_Layer_AllowedChoices_Numeric{ paramIndex, exposedParams, tooltips });
			if (allowedChoices_Numeric != nullptr) {
				allowedChoices_Numeric->setTopLeftPosition(0, 0);
				addAndMakeVisible(allowedChoices_Numeric.get());
			}
			break;
		case P_600_G_Constants::ControlType::knobForPitch:
			allowedChoices_OscPitch.reset(new GUI_Layer_AllowedChoices_OscPitch{ paramIndex, exposedParams, tooltips });
			if (allowedChoices_OscPitch != nullptr) {
				allowedChoices_OscPitch->setTopLeftPosition(0, 0);
				addAndMakeVisible(allowedChoices_OscPitch.get());
			}
			break;
		case P_600_G_Constants::ControlType::twoPoleSwitch:
			allowedChoices_Binary.reset(new GUI_Layer_AllowedChoices_Binary{ paramIndex, exposedParams, tooltips });
			if (allowedChoices_Binary != nullptr) {
				allowedChoices_Binary->setTopLeftPosition(0, 0);
				addAndMakeVisible(allowedChoices_Binary.get());
			}
			break;
		case P_600_G_Constants::ControlType::threePoleSwitch:
			allowedChoices_FilterKeyTrack.reset(new GUI_Layer_AllowedChoices_FilterKeyTrack{ exposedParams, tooltips });
			if (allowedChoices_FilterKeyTrack != nullptr) {
				allowedChoices_FilterKeyTrack->setTopLeftPosition(0, 0);
				addAndMakeVisible(allowedChoices_FilterKeyTrack.get());
			}
			break;
		default:
			break;
		}
	}
}

void GUI_Layer_Randomization::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	if (buttonID.startsWith("comp_ToggleLock_")) {
		auto paramIndex{ (uint8)button->getComponentID().fromFirstOccurrenceOf("Param_", false, false).getIntValue() };
		if (toggleWasRightClicked) {
			randomization->setParamIsLocked(paramIndex, false);
			lockTogglesForParams[paramIndex]->setToggleState(false, dontSendNotification);
			toggleWasRightClicked = false;
		}
		else {
			auto paramID{ info->IDfor(paramIndex) };
			auto shouldBeLocked{ button->getToggleState() };
			randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
		}
	}
}

GUI_Layer_Randomization::~GUI_Layer_Randomization() {
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		lockTogglesForParams[paramIndex]->removeListener(this);
		lockTogglesForParams[paramIndex]->removeMouseListener(this);
		lockTogglesForParams[paramIndex] = nullptr;
	}
	allowedChoices_Binary = nullptr;
	allowedChoices_FilterKeyTrack = nullptr;
	allowedChoices_Numeric = nullptr;
	allowedChoices_OscPitch = nullptr;
}
