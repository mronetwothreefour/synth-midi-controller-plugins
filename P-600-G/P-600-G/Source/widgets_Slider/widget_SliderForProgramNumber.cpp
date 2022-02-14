#include "widget_SliderForProgramNumber.h"

#include "../gui/gui_Constants.h"
#include "../guiRenderers/guiRenderer_LCDNumber.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../pgmData/pgmData_Constants.h"

using namespace::constants;



SliderForProgramNumber::SliderForProgramNumber(UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelModForProgramNumber{ unexposedParams },
	unexposedParams{ unexposedParams },
	parameterID{ ID::voiceTx_CurrentVoiceNumber }
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
	auto currentValue{ getValue() };
	jassert(currentValue < pgmData::numberOfSlotsInPgmDataBank);
	String currentValueString{ roundToInt(currentValue) };
	currentValueString = currentValueString.paddedLeft('0', 2);
	LCDnumberRenderer::paintValueStringInComponent(g, currentValueString);
}

SliderForProgramNumber::~SliderForProgramNumber() {
	auto pgmDataOptions{ unexposedParams->programDataOptions_get() };
	pgmDataOptions->removeListener(this);
}
