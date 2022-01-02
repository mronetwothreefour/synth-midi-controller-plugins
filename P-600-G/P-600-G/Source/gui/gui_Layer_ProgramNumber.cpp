#include "gui_Layer_ProgramNumber.h"

#include "gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;




ProgramNumberLayer::ProgramNumberLayer(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	slider_ForProgramNumber{ unexposedParams }
{
	setInterceptsMouseClicks(false, true);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);

	slider_ForProgramNumber.addListener(this);
	slider_ForProgramNumber.setTooltip(generateProgramNumberTooltipString());
	addAndMakeVisible(slider_ForProgramNumber);

	setSize(GUI::editor_w, GUI::editor_h);
}

void ProgramNumberLayer::resized() {
	slider_ForProgramNumber.setBounds(GUI::bounds_ProgramNumberSlider);
}

void ProgramNumberLayer::sliderValueChanged(Slider* slider) {
	if (slider == &slider_ForProgramNumber) {
		auto currentKnobValue{ (uint8)roundToInt(slider->getValue()) };
		auto currentProgramOptions{ unexposedParams->currentProgramOptions_get() };
		currentProgramOptions->setCurrentProgramNumber(currentKnobValue);
	}
}

String ProgramNumberLayer::generateProgramNumberTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects which program storage slot\n";
		tooltipText += "on the hardware is the target of the\n";
		tooltipText += "Push and Pull buttons to the right.\n";
		tooltipText += "Range: 0 to 99.";
	}
	return tooltipText;
}

void ProgramNumberLayer::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == ID::tooltips_ShouldShowDescription) {
		slider_ForProgramNumber.setTooltip(generateProgramNumberTooltipString());
	}
}

ProgramNumberLayer::~ProgramNumberLayer() {
	auto currentPatchOptions{ unexposedParams->currentProgramOptions_get() };
	currentPatchOptions->removeListener(this);
	slider_ForProgramNumber.removeListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
}
