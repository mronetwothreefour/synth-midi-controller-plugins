#include "gui_Layer_Controls.h"

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_UnexposedParameters_Facade.h"



ControlsLayer::ControlsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	ControlsForExposedParameters(unexposedParams),
	unexposedParams{ unexposedParams }
{
    setInterceptsMouseClicks(false, true);
	rebuildControls(unexposedParams);
    for (uint8 param = 0; param != paramOutOfRange(); ++param) {
        auto control{ controlFor(param) };
        addAndMakeVisible(control);
        control->attachToExposedParameter(exposedParams);
        auto& info{ InfoForExposedParameters::get() };
        control->setCentrePosition(info.controlCenterPointFor(param));
    }
}

ControlsLayer::~ControlsLayer() {
    for (uint8 param = 0; param != paramOutOfRange(); ++param) {
        auto control{ controlFor(param) };
        control->deleteAttachment();
    }
    clearControls();
}

