#include "widget_KnobWithExposedParamAttacher.h"

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"



KnobWithExposedParamAttacher::KnobWithExposedParamAttacher(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	slider{ unexposedParams },
	tooltipSetter{ slider, paramIndex, unexposedParams }
{
	addAndMakeVisible(slider);
	slider.setMouseDragSensitivity(80 + InfoForExposedParameters::get().numberOfStepsFor(paramIndex) / 2);
	slider.setComponentID(ID::component_Knob.toString());
}

void KnobWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	attachment.reset(new SliderAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(paramIndex).toString(), slider));
}

void KnobWithExposedParamAttacher::deleteAttachment() {
	attachment = nullptr;
}

