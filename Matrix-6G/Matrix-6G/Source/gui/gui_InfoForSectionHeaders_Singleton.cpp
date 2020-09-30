#include "gui_InfoForSectionHeaders_Singleton.h"



InfoForSectionHeaders::InfoForSectionHeaders() {
	fillAllInfoContainers();
}

void InfoForSectionHeaders::fillAllInfoContainers() {
	static const auto blueBar_h{ 14 };
	static const auto topRow_y1{ 20 };
	static const auto topRow_y2{ topRow_y1 + blueBar_h };
	static const auto envRow_y1{ 408 };
	static const auto envRow_y2{ envRow_y1 + blueBar_h };
	static const auto column1Start_x{ 20 };
	static const auto column2Start_x{ 242 };
	static const auto column2End_x{ 412 };
	static const auto column3Start_x{ 430 };
	static const auto column3End_x{ 580 };
	static const auto column4Start_x{ 596 };
	static const auto column4End_x{ 822 };
	static const auto column5Start_x{ 840 };
	static const auto column5End_x{ 990 };
	static const auto column6Start_x{ 1006 };
	static const auto column6End_x{ 1232 };

	headerStrings.add("OSCILLATOR");
	startPoints.add(Point<int>(column1Start_x, topRow_y1));
	endPoints.add(Point<int>(226, topRow_y2));

	headerStrings.add("VCF");
	startPoints.add(Point<int>(column2Start_x, topRow_y1));
	endPoints.add(Point<int>(column2End_x, topRow_y2));

	headerStrings.add("VCA");
	static const auto vca_y{ 243 };
	startPoints.add(Point<int>(column2Start_x, vca_y));
	endPoints.add(Point<int>(column2End_x, vca_y + blueBar_h));

	headerStrings.add("VCF FM");
	startPoints.add(Point<int>(column3Start_x, topRow_y1));
	endPoints.add(Point<int>(column3End_x, topRow_y2));

	headerStrings.add("PORTAMENTO");
	static const auto portamento_y{ 160 };
	startPoints.add(Point<int>(column3Start_x, portamento_y));
	endPoints.add(Point<int>(column3End_x, portamento_y + blueBar_h));

	headerStrings.add("VOICE ASSIGN");
	static const auto voiceAssign_y{ 328 };
	startPoints.add(Point<int>(column3Start_x, voiceAssign_y));
	endPoints.add(Point<int>(column3End_x, voiceAssign_y + blueBar_h));

	headerStrings.add("LFO");
	startPoints.add(Point<int>(column4Start_x, topRow_y1));
	endPoints.add(Point<int>(column4End_x, topRow_y2));

	headerStrings.add("RAMP");
	startPoints.add(Point<int>(column5Start_x, topRow_y1));
	endPoints.add(Point<int>(column5End_x, topRow_y2));

	headerStrings.add("TRACKING");
	static const auto tracking_y{ 132 };
	startPoints.add(Point<int>(column5Start_x, tracking_y));
	endPoints.add(Point<int>(column5End_x, tracking_y + blueBar_h));

	headerStrings.add("PATCH NAME");
	startPoints.add(Point<int>(column5Start_x, voiceAssign_y));
	endPoints.add(Point<int>(column5End_x, voiceAssign_y + blueBar_h));

	headerStrings.add("ENVELOPE 1");
	startPoints.add(Point<int>(column1Start_x, envRow_y1));
	endPoints.add(Point<int>(170, envRow_y2));

	headerStrings.add("ENVELOPE 2");
	startPoints.add(Point<int>(column3Start_x, envRow_y1));
	endPoints.add(Point<int>(column3End_x, envRow_y2));

	headerStrings.add("ENVELOPE 3");
	startPoints.add(Point<int>(column5Start_x, envRow_y1));
	endPoints.add(Point<int>(column5End_x, envRow_y2));

	headerStrings.add("MATRIX MOD");
	startPoints.add(Point<int>(column6Start_x, topRow_y1));
	endPoints.add(Point<int>(column6End_x, topRow_y2));
}

InfoForSectionHeaders& InfoForSectionHeaders::get() noexcept {
	static InfoForSectionHeaders headersInfo;
	return headersInfo;
}

int InfoForSectionHeaders::headerOutOfRange() const noexcept {
	return headerStrings.size();
}

String InfoForSectionHeaders::textFor(int headerNumber) {
	return headerStrings[headerNumber];
}

Point<int> InfoForSectionHeaders::startPointFor(int headerNumber) {
	return startPoints[headerNumber];
}

Point<int> InfoForSectionHeaders::endPointFor(int headerNumber) {
	return endPoints[headerNumber];
}
