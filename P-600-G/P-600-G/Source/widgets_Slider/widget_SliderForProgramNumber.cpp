#include "widget_SliderForProgramNumber.h"

#include "../gui/gui_Constants.h"
#include "../guiRenderers/guiRenderer_LCDNumber.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace::constants;



SliderForProgramNumber::SliderForProgramNumber(UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelModForProgramNumber{ unexposedParams },
	unexposedParams{ unexposedParams },
	parameterID{ ID::pgmData_CurrentProgramNumber }
{
	auto pgmDataOptions{ unexposedParams->programDataOptions_get() };
	pgmDataOptions->addListener(this);
	setRange(0.0, 99.0, 1.0);
	auto paramValue{ pgmDataOptions->currentProgramNumber() };
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
	auto pgmDataOptions{ unexposedParams->programDataOptions_get() };
	pgmDataOptions->removeListener(this);
}
