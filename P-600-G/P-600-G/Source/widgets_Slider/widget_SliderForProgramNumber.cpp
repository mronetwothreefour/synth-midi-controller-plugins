#include "widget_SliderForProgramNumber.h"

#include "../gui/gui_Constants.h"
#include "../guiRenderers/guiRenderer_LCDNumber.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace::constants;



SliderForProgramNumber::SliderForProgramNumber(UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams },
	parameterID{ ID::currentProgram_Number }
{
	auto currentProgramOptions{ unexposedParams->currentProgramOptions_get() };
	currentProgramOptions->addListener(this);
	setRange(0.0, 99.0, 1.0);
	auto paramValue{ currentProgramOptions->currentProgramNumber() };
	setValue((double)paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, 0.0);
	setMouseDragSensitivity(160);
}

void SliderForProgramNumber::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), sendNotification);
	}
}

void SliderForProgramNumber::paint(Graphics& g) {
	LCDnumberRenderer::paintSliderValueWithLCDdigits(g, this, 2, GUI::programNumberInset_x, GUI::programNumberInset_y);
}

SliderForProgramNumber::~SliderForProgramNumber() {
	auto currentProgramOptions{ unexposedParams->currentProgramOptions_get() };
	currentProgramOptions->removeListener(this);
}
