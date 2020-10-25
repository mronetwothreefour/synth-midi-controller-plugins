#include "gui_Layer_ExposedParamControls.h"

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_UnexposedParameters_Facade.h"



ExposedParamsControlsLayer::ExposedParamsControlsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	ControlsForExposedParameters(unexposedParams),
	unexposedParams{ unexposedParams }
{
    rebuildControls(unexposedParams);
    for (uint8 param = 0; param != paramOutOfRange(); ++param) {
        auto control{ controlFor(param) };
        addAndMakeVisible(control);
        control->attachToExposedParameter(exposedParams);
        auto& info{ InfoForExposedParameters::get() };
        control->setCentrePosition(info.controlCenterPointFor(param));
    }
}

ExposedParamsControlsLayer::~ExposedParamsControlsLayer() {
    for (uint8 param = 0; param != paramOutOfRange(); ++param) {
        auto control{ controlFor(param) };
        control->deleteAttachment();
    }
    clearControls();
}
