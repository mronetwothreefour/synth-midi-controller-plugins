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
	button_Close{ unexposedParams }
{
	button_Close.setTopLeftPosition(1208, 16);
	addAndMakeVisible(button_Close);

	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		paramLockToggles[paramIndex].reset(new LockToggleForParam{ paramIndex, unexposedParams });
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
	auto eventComponentID{ event.eventComponent->getComponentID() };
	auto paramIndex{ (uint8)eventComponentID.fromFirstOccurrenceOf("Param_", false, false).getIntValue() };
	if (event.mods == ModifierKeys::rightButtonModifier) {

	}
	else {
		auto paramID{ Info::get().IDfor(paramIndex) };
		auto shouldBeLocked{ paramLockToggles[paramIndex]->getToggleState() };
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
		if (paramID == ID::ep_098_ArpegOnOff || paramID == ID::ep_100_SeqOnOff) {
			if (exposedParams->getParameter(paramID)->getValue() == 1.0f) {
				if (paramID == ID::ep_098_ArpegOnOff)
					randomization->setParamIsLocked((uint8)100, shouldBeLocked ? true : false);
				else
					randomization->setParamIsLocked((uint8)98, shouldBeLocked ? true : false);
			}
		}
	}
}

GUI_Layer_Randomization::~GUI_Layer_Randomization() {
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		paramLockToggles[paramIndex]->removeMouseListener(this);
		paramLockToggles[paramIndex] = nullptr;
	}
}
