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

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_Randomization::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_Randomization_png, BinaryData::bkgrnd_Randomization_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

GUI_Layer_Randomization::~GUI_Layer_Randomization()
{
}
