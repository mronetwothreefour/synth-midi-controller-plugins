#include "gui_Layer_VoiceNumber.h"

#include "gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;




VoiceNumberLayer::VoiceNumberLayer(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	slider_ForVoiceNumber{ unexposedParams }
{
	setInterceptsMouseClicks(false, true);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);

	slider_ForVoiceNumber.addListener(this);
	slider_ForVoiceNumber.setTooltip(generateVoiceNumberTooltipString());
	addAndMakeVisible(slider_ForVoiceNumber);

	setSize(GUI::editor_w, GUI::editor_h);
}

void VoiceNumberLayer::resized() {
	slider_ForVoiceNumber.setBounds(GUI::bounds_VoiceNumberSlider);
}

void VoiceNumberLayer::sliderValueChanged(Slider* slider) {
	if (slider == &slider_ForVoiceNumber) {
		auto currentKnobValue{ (uint8)roundToInt(slider->getValue()) };
		auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
		voiceTransmissionOptions->setCurrentVoiceNumber(currentKnobValue);
	}
}

String VoiceNumberLayer::generateVoiceNumberTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		tooltipText += "Selects which program storage slot\n";
		tooltipText += "on the hardware is the target of the\n";
		tooltipText += "Push and Pull buttons to the right.\n";
		tooltipText += "Hold down the SHIFT key when using\n";
		tooltipText += "the mouse wheel to increment by 10.\n";
		tooltipText += "Range: 0 to 99.";
	}
	return tooltipText;
}

void VoiceNumberLayer::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == ID::tooltips_ShouldShowDescriptions) {
		slider_ForVoiceNumber.setTooltip(generateVoiceNumberTooltipString());
	}
}

VoiceNumberLayer::~VoiceNumberLayer() {
	auto currentPatchOptions{ unexposedParams->voiceTransmissionOptions_get() };
	currentPatchOptions->removeListener(this);
	slider_ForVoiceNumber.removeListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
}
