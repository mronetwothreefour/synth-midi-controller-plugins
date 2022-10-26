#include "global_3_gui_layer_CommError.h"

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;

GUI_Layer_CommError::GUI_Layer_CommError(UnexposedParameters* unexposedParams) :
	global{ unexposedParams->getGlobalOptions() },
	outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() },
	btn_Close{ BorderColor::orange, unexposedParams },
	btn_RequestGlobalParamsDump{ "" }
{
	btn_Close.setTopLeftPosition(857, 119);
	addAndMakeVisible(btn_Close);

	btn_RequestGlobalParamsDump.setComponentID(ID::btn_Retry.toString());
	btn_RequestGlobalParamsDump.onClick = [this] { requestGlobalParamsDump(); };
	btn_RequestGlobalParamsDump.addShortcut(KeyPress(KeyPress::returnKey));
	btn_RequestGlobalParamsDump.setBounds(606, 432, 40, GUI::control_h);
	addAndMakeVisible(btn_RequestGlobalParamsDump);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_CommError::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_NoSysExWarning_png, BinaryData::bkgrnd_NoSysExWarning_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 377, 119);
}

void GUI_Layer_CommError::requestGlobalParamsDump() {
	SysExMessages::addRequestForGlobalDataToOutgoingBuffers(outgoingBuffers);
	callAfterDelay(300, [this] { 
		if (global->sysExIsEnabled())
			btn_Close.triggerClick();
	});
}

void GUI_Layer_CommError::timerCallback() {
}
