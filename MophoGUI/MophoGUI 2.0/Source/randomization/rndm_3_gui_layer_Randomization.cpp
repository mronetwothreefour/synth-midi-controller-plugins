#include "rndm_3_gui_layer_Randomization.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using Info = InfoForExposedParameters;



GUI_Layer_Randomization::GUI_Layer_Randomization(
	ExposedParameters* exposedParams, UnexposedParameters* unexposedParams, ParamRandomizationMethods* randomize) :
	exposedParams{ exposedParams },
	randomization{ unexposedParams->getRandomizationOptions() },
	randomize{ randomize },
	button_Close{ unexposedParams },
	transmitType{ unexposedParams }
{
	button_Close.setTopLeftPosition(1208, 16);
	addAndMakeVisible(button_Close);

	transmitType.setTopLeftPosition(1138, 81);
	addAndMakeVisible(transmitType);

	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		paramLockToggles[paramIndex].reset(new LockToggleForParam{ paramIndex, unexposedParams });
		paramLockToggles[paramIndex]->addListener(this);
		paramLockToggles[paramIndex]->addMouseListener(this, false);
		paramLockToggles[paramIndex]->setCentrePosition(Info::get().centerPointFor(paramIndex));
		addAndMakeVisible(paramLockToggles[paramIndex].get());
	}

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
		// todo: show allowed choices layer
	}
}

void GUI_Layer_Randomization::buttonClicked(Button* button) {
	auto paramIndex{ (uint8)button->getComponentID().fromFirstOccurrenceOf("Param_", false, false).getIntValue()};
	if (toggleWasRightClicked) {
		randomization->setParamIsLocked(paramIndex, false);
		paramLockToggles[paramIndex]->setToggleState(false, dontSendNotification);
		if (paramIndex == EP::indexForArpegOnOff) {
			if (exposedParams->getParameter(ID::ep_100_SeqOnOff)->getValue() == 1.0f) {
				randomization->setParamIsLocked(EP::indexForSeqOnOff, false);
				paramLockToggles[EP::indexForSeqOnOff]->setToggleState(false, dontSendNotification);
			}
		}
		if (paramIndex == EP::indexForSeqOnOff) {
			if (exposedParams->getParameter(ID::ep_098_ArpegOnOff)->getValue() == 1.0f) {
				randomization->setParamIsLocked(EP::indexForArpegOnOff, false);
				paramLockToggles[EP::indexForArpegOnOff]->setToggleState(false, dontSendNotification);
			}
		}
		toggleWasRightClicked = false;
	}
	else {
		auto paramID{ Info::get().IDfor(paramIndex) };
		auto shouldBeLocked{ button->getToggleState() };
		if (paramID == ID::ep_098_ArpegOnOff || paramID == ID::ep_100_SeqOnOff) {
			if (shouldBeLocked) {
				randomization->setParamIsLocked(paramIndex, true);
				if (paramID == ID::ep_098_ArpegOnOff && exposedParams->getParameter(ID::ep_098_ArpegOnOff)->getValue() == 1.0f) {
					randomization->setParamIsLocked(EP::indexForSeqOnOff, true);
					paramLockToggles[EP::indexForSeqOnOff]->setToggleState(true, dontSendNotification);
				}
				if (paramID == ID::ep_100_SeqOnOff && exposedParams->getParameter(ID::ep_100_SeqOnOff)->getValue() == 1.0f) {
					randomization->setParamIsLocked(EP::indexForArpegOnOff, true);
					paramLockToggles[EP::indexForArpegOnOff]->setToggleState(true, dontSendNotification);
				}
			}
			else {
				if (paramID == ID::ep_098_ArpegOnOff) {
					auto seqIsLockedOn{ randomization->paramIsLocked(100) && exposedParams->getParameter(ID::ep_100_SeqOnOff)->getValue() == 1.0f };
					if (seqIsLockedOn == false)
						randomization->setParamIsLocked(paramIndex, false);
					else
						paramLockToggles[paramIndex]->setToggleState(true, dontSendNotification);
				}
				else {
					auto arpegIsLockedOn{ randomization->paramIsLocked(98) && exposedParams->getParameter(ID::ep_098_ArpegOnOff)->getValue() == 1.0f };
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
