#include "global_1_gui_layer_CommError_NRPN.h"

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



GUI_Layer_CommError_NRPN::GUI_Layer_CommError_NRPN(UnexposedParameters* unexposedParams) :
	GUI_Layer_CommError_Base{ unexposedParams }
{
	button_Close.setTopLeftPosition(820, 212);
	button_RequestGlobalParamsDump.setTopLeftPosition(611, 387);
}

void GUI_Layer_CommError_NRPN::checkHardwareSettings() {
	if (global->hardwareIsSetToReceiveNRPNcontrollers())
		button_Close.triggerClick();
}

void GUI_Layer_CommError_NRPN::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_CommError_NRPN_png, BinaryData::bkgrnd_CommError_NRPN_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 396, 205);
}
