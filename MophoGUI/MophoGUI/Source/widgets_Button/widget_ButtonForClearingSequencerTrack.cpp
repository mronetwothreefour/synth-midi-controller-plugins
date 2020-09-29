#include "widget_ButtonForClearingSequencerTrack.h"

#include "../params/params_UnexposedParameters_Facade.h"



ButtonForClearingSequencerTrack::ButtonForClearingSequencerTrack(int trackNum, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ "CLEAR", unexposedParams },
	trackNum{ trackNum },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
	setTooltip(createButtonTooltipString());
}

const String ButtonForClearingSequencerTrack::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Sets all steps in sequencer\n";
		if (trackNum == 1)
			buttonTooltip += "track 1 to 127 (\"rest\")";
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
	auto param{ exposedParams->getParameter("track" + (String)trackNum + "Step" + (String)step) };
	auto clearedValue{ trackNum == 1 ? 1.0f : 0.0f };
	param->setValueNotifyingHost(clearedValue);
}

