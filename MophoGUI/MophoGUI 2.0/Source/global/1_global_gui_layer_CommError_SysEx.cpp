#include "1_global_gui_layer_CommError_SysEx.h"

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



GUI_Layer_CommError_SysEx::GUI_Layer_CommError_SysEx(UnexposedParameters* unexposedParams) :
	GUI_Layer_CommError_Base{ unexposedParams }
{
	resized();
}

void GUI_Layer_CommError_SysEx::checkHardwareSettings() {
	auto globalOptions{ unexposedParams->getGlobalOptions() };
	if (globalOptions->sysExIsEnabled())
		button_Close.triggerClick();
}

void GUI_Layer_CommError_SysEx::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_CommError_SysEx_png, BinaryData::bkgrnd_CommError_SysEx_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 386, 143);
}

void GUI_Layer_CommError_SysEx::resized() {
	button_Close.setTopLeftPosition(830, 150);
	button_RequestGlobalParamsDump.setTopLeftPosition(611, 449);
}
