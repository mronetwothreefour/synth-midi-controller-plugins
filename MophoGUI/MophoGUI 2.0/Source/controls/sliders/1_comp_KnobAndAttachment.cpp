#include "1_comp_KnobAndAttachment.h"

#include "../../constants/constants_GUI_Bounds.h"
#include "../../constants/constants_Identifiers.h"
#include "../../exposedParameters/ep_singleton_InfoForExposedParameters.h"

using namespace mophoConstants;



KnobAndAttachment::KnobAndAttachment(
	uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	slider{ unexposedParams },
	tooltipsUpdater{ paramIndex, slider, exposedParams, unexposedParams }
{
	auto& info{ InfoForExposedParameters::get() };
	addAndMakeVisible(slider);
	slider.setMouseDragSensitivity(info.mouseDragSensitivityFor(paramIndex));
	slider.setComponentID(ID::component_Knob.toString());
	setSize(GUI::knob_diameter, GUI::knob_diameter);
}

void KnobAndAttachment::attachToExposedParameter() {
	attachment.reset(new SliderAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(paramIndex).toString(), slider));
}

void KnobAndAttachment::deleteAttachment() {
	attachment = nullptr;
}
