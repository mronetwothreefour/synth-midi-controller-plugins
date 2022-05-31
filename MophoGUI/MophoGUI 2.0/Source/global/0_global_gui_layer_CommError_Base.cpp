#include "0_global_gui_layer_CommError_Base.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../midi/1_midi_GlobalParametersDataRequest.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



GUI_Layer_CommError_Base::GUI_Layer_CommError_Base(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_Close{ unexposedParams },
	button_RequestGlobalParamsDump{ "" }
{
	addAndMakeVisible(button_Close);

	button_RequestGlobalParamsDump.setComponentID(ID::button_Retry.toString());
	button_RequestGlobalParamsDump.onClick = [this] { requestGlobalParamsDump(); };
	button_RequestGlobalParamsDump.addShortcut(KeyPress(KeyPress::returnKey));
	addAndMakeVisible(button_RequestGlobalParamsDump);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_CommError_Base::requestGlobalParamsDump() {
	auto outgoingMidiBuffers{ unexposedParams->getOutgoingMidiBuffers() };
	GlobalParametersDataRequest::addToOutgoingMidiBuffers(outgoingMidiBuffers);
	callAfterDelay(300, [this] { checkHardwareSettings(); });
}

void GUI_Layer_CommError_Base::timerCallback() {
}
