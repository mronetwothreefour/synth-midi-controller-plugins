#include "global_0_gui_layer_CommError_Base.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../midi/midi_1_GlobalParametersDataRequest.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



GUI_Layer_CommError_Base::GUI_Layer_CommError_Base(UnexposedParameters* unexposedParams) :
	global{ unexposedParams->getGlobalOptions() },
	outgoingMIDI{ unexposedParams->getOutgoingMidiBuffers() },
	button_Close{ unexposedParams },
	button_RequestGlobalParamsDump{ "" }
{
	addAndMakeVisible(button_Close);

	button_RequestGlobalParamsDump.setComponentID(ID::button_Retry.toString());
	button_RequestGlobalParamsDump.onClick = [this] { requestGlobalParamsDump(); };
	button_RequestGlobalParamsDump.addShortcut(KeyPress(KeyPress::returnKey));
	button_RequestGlobalParamsDump.setSize(50, GUI::redButton_h);
	addAndMakeVisible(button_RequestGlobalParamsDump);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_CommError_Base::requestGlobalParamsDump() {
	GlobalParametersDataRequest::addToOutgoingMidiBuffers(outgoingMIDI);
	callAfterDelay(300, [this] { checkHardwareSettings(); });
}

void GUI_Layer_CommError_Base::timerCallback() {
}
