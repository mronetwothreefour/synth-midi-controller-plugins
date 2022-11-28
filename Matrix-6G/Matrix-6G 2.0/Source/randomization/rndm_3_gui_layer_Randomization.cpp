#include "rndm_3_gui_layer_Randomization.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using MM_Type = MatrixModParamType;

GUI_Layer_Randomization::GUI_Layer_Randomization(
	ExposedParameters* exposedParams, TooltipsOptions* tooltips, Outgoing_MIDI_Buffers* outgoingBuffers) :
	state{ exposedParams->state.get() },
	exposedParams{ exposedParams },
	info{ exposedParams->info.get() },
	randomization{ exposedParams->randomization.get() },
	btn_Close{ BorderColor::orange, tooltips, outgoingBuffers },
	tooltips{ tooltips },
	outgoingBuffers{ outgoingBuffers },
	transmitMethod{ randomization, tooltips },
	lockStateButtons_All{ LockStateGroup::all, exposedParams->randomization.get(), tooltips },
	lockStateButtons_Osc{ LockStateGroup::osc, exposedParams->randomization.get(), tooltips },
	lockStateButtons_VCF{ LockStateGroup::vcf, exposedParams->randomization.get(), tooltips },
	lockStateButtons_VCA{ LockStateGroup::vca, exposedParams->randomization.get(), tooltips },
	lockStateButtons_VCF_FM{ LockStateGroup::vcf_FM, exposedParams->randomization.get(), tooltips },
	lockStateButtons_Portamento{ LockStateGroup::porta, exposedParams->randomization.get(), tooltips },
	lockStateButtons_LFO{ LockStateGroup::lfo, exposedParams->randomization.get(), tooltips },
	lockStateButtons_Ramp{ LockStateGroup::ramp, exposedParams->randomization.get(), tooltips },
	lockStateButtons_Tracking{ LockStateGroup::tracking, exposedParams->randomization.get(), tooltips },
	lockStateButtons_Envelope_1{ LockStateGroup::env_1, exposedParams->randomization.get(), tooltips },
	lockStateButtons_Envelope_2{ LockStateGroup::env_2, exposedParams->randomization.get(), tooltips },
	lockStateButtons_Envelope_3{ LockStateGroup::env_3, exposedParams->randomization.get(), tooltips },
	lockStateButtons_MatrixMod{ LockStateGroup::matrixMod, exposedParams->randomization.get(), tooltips }
{
	setInterceptsMouseClicks(false, true);

	btn_Close.setTopRightPosition(990, 309);
	addAndMakeVisible(btn_Close);

	transmitMethod.setTopLeftPosition(905, 354);
	addAndMakeVisible(transmitMethod);

	auto shouldShowDescriptions{ tooltips->shouldShowDescription() };
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		lockToggles_ExposedParams[paramIndex].reset(new LockToggle_ExposedParam{ paramIndex, exposedParams });
		lockToggles_ExposedParams[paramIndex]->addListener(this);
		lockToggles_ExposedParams[paramIndex]->addMouseListener(this, false);
		auto controlCenterPoint{ info->centerPointFor(paramIndex) };
		lockToggles_ExposedParams[paramIndex]->setCentrePosition(controlCenterPoint);
		addAndMakeVisible(lockToggles_ExposedParams[paramIndex].get());
		if (shouldShowDescriptions) {
			String tip{ "" };
			tip += "Click to lock/unlock the parameter.\n";
			tip += "Right-click to specify the choices\n";
			tip += "allowed when randomly generating\n";
			tip += "a new setting for the parameter.";
			lockToggles_ExposedParams[paramIndex]->setTooltip(tip);
		}
	}

	for (auto mmParamNum = 0; mmParamNum != MMOD::numberOfModulators * 3; ++mmParamNum) {
		auto modNum{ mmParamNum / 3 };
		auto paramType{ MM_Type{ mmParamNum % 3 } };
		lockToggles_MatrixModParams[mmParamNum].reset(new LockToggle_MatrixModParam{ modNum, paramType, exposedParams });
		lockToggles_MatrixModParams[mmParamNum]->addListener(this);
		lockToggles_MatrixModParams[mmParamNum]->addMouseListener(this, false);
		auto toggle_x{ paramType == MM_Type::source ? 1016 : paramType == MM_Type::amount ? 1104 : 1150 };
		auto toggle_y{ 59 + modNum * GUI::vertDistBtwnRows };
		lockToggles_MatrixModParams[mmParamNum]->setTopLeftPosition(toggle_x, toggle_y);
		addAndMakeVisible(lockToggles_MatrixModParams[mmParamNum].get());
		if (shouldShowDescriptions) {
			String tip{ "" };
			tip += "Click to lock/unlock the parameter. Right-\n";
			tip += "click to specify the choices allowed when\n";
			tip += "randomly generating a new setting for the\n";
			tip += "parameter. NOTE: When the transmit message\n";
			tip += "type is set to QUICK, Matrix Mod parameters\n";
			tip += "cannot be randomized.";
			lockToggles_MatrixModParams[mmParamNum]->setTooltip(tip);
		}
	}

	auto allParamsButtons_y{ 354 };
	lockStateButtons_All.setTopLeftPosition(681, allParamsButtons_y);
	auto topRowLockButtons_y{ 17 };
	lockStateButtons_Osc.setTopLeftPosition(125, topRowLockButtons_y);
	lockStateButtons_VCF.setTopLeftPosition(292, topRowLockButtons_y);
	lockStateButtons_VCA.setTopLeftPosition(293, 240);
	lockStateButtons_VCF_FM.setTopLeftPosition(503, topRowLockButtons_y);
	lockStateButtons_Portamento.setTopLeftPosition(543, 157);
	lockStateButtons_LFO.setTopLeftPosition(644, topRowLockButtons_y);
	lockStateButtons_Ramp.setTopLeftPosition(902, topRowLockButtons_y);
	lockStateButtons_Tracking.setTopLeftPosition(930, 129);
	auto envelopeLockButtons_y{ 405 };
	lockStateButtons_Envelope_1.setTopLeftPosition(121, envelopeLockButtons_y);
	lockStateButtons_Envelope_2.setTopLeftPosition(533, envelopeLockButtons_y);
	lockStateButtons_Envelope_3.setTopLeftPosition(943, envelopeLockButtons_y);
	lockStateButtons_MatrixMod.setTopLeftPosition(1114, topRowLockButtons_y);

	addAndMakeVisible(lockStateButtons_All);
	addAndMakeVisible(lockStateButtons_Osc);
	addAndMakeVisible(lockStateButtons_VCF);
	addAndMakeVisible(lockStateButtons_VCA);
	addAndMakeVisible(lockStateButtons_VCF_FM);
	addAndMakeVisible(lockStateButtons_Portamento);
	addAndMakeVisible(lockStateButtons_LFO);
	addAndMakeVisible(lockStateButtons_Ramp);
	addAndMakeVisible(lockStateButtons_Tracking);
	addAndMakeVisible(lockStateButtons_Envelope_1);
	addAndMakeVisible(lockStateButtons_Envelope_2);
	addAndMakeVisible(lockStateButtons_Envelope_3);
	addAndMakeVisible(lockStateButtons_MatrixMod);

	btn_RandomizeAllUnlocked.setComponentID(ID::btn_Randomize.toString());
	btn_RandomizeAllUnlocked.onClick = [exposedParams] { exposedParams->randomize->randomizeAllUnlockedParameters(); };
	btn_RandomizeAllUnlocked.addShortcut(KeyPress{ 'd', ModifierKeys::ctrlModifier, 0 });
	if (shouldShowDescriptions)
		btn_RandomizeAllUnlocked.setTooltip("Click to generate random settings\nfor all unlocked parameters.\nShortcut key: CTRL+D");
	btn_RandomizeAllUnlocked.setBounds(787, allParamsButtons_y, GUI::btn_Randomize_w, GUI::control_h);
	addAndMakeVisible(btn_RandomizeAllUnlocked);

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
		if (toggleID.startsWith(ID::comp_ToggleLockExposedParam_.toString())) {
			auto paramIndex{ (uint8)toggleID.fromFirstOccurrenceOf("Param_", false, false).getIntValue() };
			allowedChoices_ExposedParam.reset(new GUI_Layer_AllowedChoices_ExposedParam{ paramIndex, exposedParams, tooltips, outgoingBuffers });
			if (allowedChoices_ExposedParam != nullptr) {
				addAndMakeVisible(allowedChoices_ExposedParam.get());
				allowedChoices_ExposedParam->setTopLeftPosition(0, 0);
			}
		}
		if (toggleID.startsWith("comp_ToggleLockMatrixMod_") && randomization->transmitMethodIsQuickEdit() == false) {
			auto modNum{ toggleID.fromLastOccurrenceOf("Mod_", false, false).getIntValue() };
			auto paramType{ toggleID.contains("Src") ? MM_Type::source : toggleID.contains("Amt") ? MM_Type::amount : MM_Type::destination };
			allowedChoices_MatrixModParam.reset(new GUI_Layer_AllowedChoices_MatrixModParam{ modNum, paramType, exposedParams, tooltips, outgoingBuffers });
			if (allowedChoices_MatrixModParam != nullptr) {
				addAndMakeVisible(allowedChoices_MatrixModParam.get());
				allowedChoices_MatrixModParam->setTopLeftPosition(0, 0);
			}
		}
	}
}

void GUI_Layer_Randomization::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	if (buttonID.startsWith(ID::comp_ToggleLockExposedParam_.toString())) {
		auto paramIndex{ (uint8)button->getComponentID().fromFirstOccurrenceOf("Param_", false, false).getIntValue() };
		if (toggleWasRightClicked) {
			randomization->setParamIsLocked(paramIndex, false);
			lockToggles_ExposedParams[paramIndex]->setToggleState(false, dontSendNotification);
			toggleWasRightClicked = false;
		}
		else {
			auto paramID{ info->IDfor(paramIndex) };
			auto shouldBeLocked{ button->getToggleState() };
			randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
		}
	}
	if (buttonID.startsWith("comp_ToggleLockMatrixMod_")) {
		auto modNum{ buttonID.fromLastOccurrenceOf("Mod_", false, false).getIntValue() };
		auto paramType{ buttonID.contains("Src") ? MM_Type::source : buttonID.contains("Amt") ? MM_Type::amount : MM_Type::destination };
		auto mmParamNum{ modNum * 3 + (int)paramType };
		if (randomization->transmitMethodIsQuickEdit() == false) {
			if (toggleWasRightClicked) {
				randomization->setMatrixModParamIsLocked(modNum, paramType, false);
				lockToggles_MatrixModParams[mmParamNum]->setToggleState(false, dontSendNotification);
				toggleWasRightClicked = false;
			}
			else {
				auto shouldBeLocked{ button->getToggleState() };
				randomization->setMatrixModParamIsLocked(modNum, paramType, shouldBeLocked ? true : false);
			}
		}
		else {
			randomization->setMatrixModParamIsLocked(modNum, paramType, true);
			lockToggles_MatrixModParams[mmParamNum]->setToggleState(true, dontSendNotification);
			toggleWasRightClicked = false;
		}
	}
}

GUI_Layer_Randomization::~GUI_Layer_Randomization() {
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		lockToggles_ExposedParams[paramIndex]->removeListener(this);
		lockToggles_ExposedParams[paramIndex]->removeMouseListener(this);
		lockToggles_ExposedParams[paramIndex] = nullptr;
	}
	for (auto mmParamNum = 0; mmParamNum != MMOD::numberOfModulators * 3; ++mmParamNum) {
		lockToggles_MatrixModParams[mmParamNum]->removeListener(this);
		lockToggles_MatrixModParams[mmParamNum]->removeMouseListener(this);
		lockToggles_MatrixModParams[mmParamNum] = nullptr;
	}
}
