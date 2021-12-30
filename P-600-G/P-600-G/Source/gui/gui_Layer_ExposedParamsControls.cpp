#include "gui_Layer_ExposedParamsControls.h"

ExposedParamsControlsLayer::ExposedParamsControlsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	ControlsForExposedParameters(unexposedParams)
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

ExposedParamsControlsLayer::~ExposedParamsControlsLayer() {
    for (uint8 param = 0; param != paramOutOfRange(); ++param) {
        auto control{ controlFor(param) };
        control->deleteAttachment();
    }
    clearControls();
}
