#include "gui_layer_ExposedParamControls.h"

#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"

using Info = InfoForExposedParameters;



GUI_Layer_ExposedParamControls::GUI_Layer_ExposedParamControls(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	ExposedParamControlsServer{ exposedParams, unexposedParams }
{
    rebuildControlsVector();
    for (uint8 paramIndex = 0; paramIndex != paramIndexOutOfRange(); ++paramIndex) {
        auto controlPtr{ controlPtrFor(paramIndex) };
        addAndMakeVisible(controlPtr);
        controlPtr->attachControlToExposedParameter();
        controlPtr->setCentrePosition(Info::get().centerPointFor(paramIndex));
    }
}

GUI_Layer_ExposedParamControls::~GUI_Layer_ExposedParamControls() {
    for (uint8 param = 0; param != paramIndexOutOfRange(); ++param) {
        auto controlPtr{ controlPtrFor(param) };
        controlPtr->deleteAttachmentBeforeControlToPreventMemLeak();
    }
    clearControlsVector();
}
