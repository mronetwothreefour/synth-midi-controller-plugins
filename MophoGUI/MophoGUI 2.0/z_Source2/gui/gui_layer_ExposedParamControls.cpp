#include "gui_layer_ExposedParamControls.h"

#include "../exposedParameters/ep_facade_ExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



GUI_Layer_ExposedParamControls::GUI_Layer_ExposedParamControls(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	ExposedParamControlsServer{ exposedParams, unexposedParams }
{
    rebuildControlsVector();
    for (uint8 paramIndex = 0; paramIndex != paramIndexOutOfRange(); ++paramIndex) {
        auto controlPtr{ controlPtrFor(paramIndex) };
        addAndMakeVisible(controlPtr);
        controlPtr->attachControlToExposedParameter();
        controlPtr->setCentrePosition(exposedParams->info.centerPointFor(paramIndex));
    }
}

GUI_Layer_ExposedParamControls::~GUI_Layer_ExposedParamControls() {
    for (uint8 param = 0; param != paramIndexOutOfRange(); ++param) {
        auto controlPtr{ controlPtrFor(param) };
        controlPtr->deleteAttachmentBeforeControlToPreventMemLeak();
    }
    clearControlsVector();
}
