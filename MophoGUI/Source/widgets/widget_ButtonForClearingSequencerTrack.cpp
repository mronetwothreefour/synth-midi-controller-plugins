#include "widget_ButtonForClearingSequencerTrack.h"


ButtonForClearingSequencerTrack::ButtonForClearingSequencerTrack(int trackNum, AudioProcessorValueTreeState* exposedParams) :
	TextButton{ "CLEAR" },
	trackNum{ trackNum },
	exposedParams{ exposedParams }
{
	jassert(trackNum > 0 && trackNum < 5);
	String tipString;
	tipString = "Sets all steps in sequencer\n";
	if (trackNum == 1)
		tipString += "track 1 to 127 (\"rest\")";
	else
		tipString += "track " + (String)trackNum + " to 0 (C0)";
	setTooltip(tipString);
	onClick = [this] { clearSequencerTrack(); };
}

void ButtonForClearingSequencerTrack::clearSequencerTrack() {
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

ButtonForClearingSequencerTrack::~ButtonForClearingSequencerTrack() {
}
