#include "widget_ButtonForClearingSequencerTrack.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonForClearingSequencerTrack::ButtonForClearingSequencerTrack(int trackNum, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	trackNum{ trackNum },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Clear.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForClearingSequencerTrack::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Sets all steps in sequencer\n";
		if (trackNum == 1)
			buttonTooltip += "track 1 to 127 (" + GUI::openQuote + "rest" + GUI::closeQuote + ")";
		else
			buttonTooltip += "track " + (String)trackNum + " to 0 (C0)";
	}
	return buttonTooltip;
}

void ButtonForClearingSequencerTrack::onClickMethod() {
	sequencerStep = 1;
	startTimer(10);
}

void ButtonForClearingSequencerTrack::timerCallback() {
	stopTimer();
	if (sequencerStep > 0 && sequencerStep < 17) {
		clearSequencerStep(sequencerStep);
		if (sequencerStep < 16) {
			++sequencerStep;
			startTimer(10);
		}
		else
			sequencerStep = 0;
	}
}

void ButtonForClearingSequencerTrack::clearSequencerStep(int step) {
	auto clearedValue{ trackNum == 1 ? 1.0f : 0.0f };
	auto param{ exposedParams->getParameter("seqTrack" + (String)trackNum + "Step" + (String)step) };
	if (param != nullptr)
		param->setValueNotifyingHost(clearedValue);
}

