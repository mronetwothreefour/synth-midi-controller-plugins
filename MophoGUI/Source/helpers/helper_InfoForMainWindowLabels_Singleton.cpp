#include "helper_InfoForMainWindowLabels_Singleton.h"

InfoForMainWindowLabels::InfoForMainWindowLabels() {
	fillAllInfoContainers();
}

void InfoForMainWindowLabels::fillAllInfoContainers() {
	const auto ctrlLabel_h{ 14 };

	const auto knobLabel_w{ 44 };
	const auto horizGapBtwnLabels{ 1 };
	const auto labelsCol1_x{ 48 };
	const auto labelsCol2_x{ labelsCol1_x + knobLabel_w + horizGapBtwnLabels };
	const auto labelsCol3_x{ labelsCol2_x + knobLabel_w + horizGapBtwnLabels };
	const auto labelsCol4_x{ labelsCol3_x + knobLabel_w + horizGapBtwnLabels };
	const auto labelsCol5_x{ labelsCol4_x + knobLabel_w + horizGapBtwnLabels };
	const auto labelsCol6_x{ labelsCol5_x + knobLabel_w + horizGapBtwnLabels };
	const auto labelsCol7_x{ labelsCol6_x + knobLabel_w + horizGapBtwnLabels };
	const auto labelsCol8_x{ labelsCol7_x + knobLabel_w + horizGapBtwnLabels };
	const auto labelsCol9_x{ labelsCol8_x + knobLabel_w + horizGapBtwnLabels };
	const auto oscCtrlLabelsRow1_y{ 73 };
	const auto oscCtrlLabelsRow2_y{ 133 };
	const auto lpfCtrlLabelsRow1_y{ 176 };
	const auto lpfCtrlLabelsRow2_y{ 238 };
	const auto lpfCtrlLabelsRow3_y{ 290 };

	labelTexts.add("OSCILLATORS");
	centerPoints.add(Point<int>(67, 19));
	widths.add(104);
	heights.add(20);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("HARD SYNC");
	centerPoints.add(Point<int>(231, 22));
	widths.add(62);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centredRight);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("1");
	centerPoints.add(Point<int>(23, 48));
	widths.add(16);
	heights.add(26);
	justificationFlags.add(Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForOscNumLabels);

	labelTexts.add("2");
	centerPoints.add(Point<int>(23, 108));
	widths.add(16);
	heights.add(26);
	justificationFlags.add(Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForOscNumLabels);

	labelTexts.add("PITCH");
	centerPoints.add(Point<int>(labelsCol1_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("FINE");
	centerPoints.add(Point<int>(labelsCol2_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SHAPE");
	centerPoints.add(Point<int>(labelsCol3_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("GLIDE");
	centerPoints.add(Point<int>(labelsCol4_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SUB");
	centerPoints.add(Point<int>(labelsCol5_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(Point<int>(labelsCol6_x, 65));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("TRACK");
	centerPoints.add(Point<int>(labelsCol6_x, 74));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("PITCH");
	centerPoints.add(Point<int>(labelsCol1_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("FINE");
	centerPoints.add(Point<int>(labelsCol2_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SHAPE");
	centerPoints.add(Point<int>(labelsCol3_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("GLIDE");
	centerPoints.add(Point<int>(labelsCol4_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SUB");
	centerPoints.add(Point<int>(labelsCol5_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(Point<int>(labelsCol6_x, 125));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("TRACK");
	centerPoints.add(Point<int>(labelsCol6_x, 134));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SLOP");
	centerPoints.add(Point<int>(labelsCol7_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("MIX");
	centerPoints.add(Point<int>(labelsCol8_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("1");
	centerPoints.add(Point<int>(347, 68));
	widths.add(10);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForOscMix1and2Labels);
	labelTexts.add("2");
	centerPoints.add(Point<int>(379, 68));
	widths.add(10);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForOscMix1and2Labels);

	labelTexts.add("BEND");
	centerPoints.add(Point<int>(labelsCol9_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("NOISE");
	centerPoints.add(Point<int>(labelsCol7_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("EXT IN");
	centerPoints.add(Point<int>(labelsCol8_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("GLIDE MODE");
	centerPoints.add(Point<int>(500, 53));
	widths.add(124);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("NOTE PRIORITY");
	centerPoints.add(Point<int>(500, 93));
	widths.add(124);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("LPF");
	centerPoints.add(Point<int>(30, 161));
	widths.add(30);
	heights.add(20);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("4-POLE");
	centerPoints.add(Point<int>(labelsCol2_x, lpfCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("FREQ");
	centerPoints.add(Point<int>(labelsCol1_x, lpfCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("RESO");
	centerPoints.add(Point<int>(labelsCol2_x, lpfCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(Point<int>(labelsCol3_x, lpfCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("FM");
	centerPoints.add(Point<int>(labelsCol3_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
}

InfoForMainWindowLabels::~InfoForMainWindowLabels() {
}

InfoForMainWindowLabels& InfoForMainWindowLabels::get() noexcept {
	static InfoForMainWindowLabels labelsInfo;
	return labelsInfo;
}

int InfoForMainWindowLabels::labelOutOfRange() const noexcept {
	return labelTexts.size();
}

String InfoForMainWindowLabels::textFor(uint16 labelIndex) const {
	return labelTexts[labelIndex];
}

Point<int> InfoForMainWindowLabels::centerPointFor(uint16 labelIndex) const {
	return centerPoints[labelIndex];
}

int InfoForMainWindowLabels::widthFor(uint16 labelIndex) const {
	return widths[labelIndex];
}

int InfoForMainWindowLabels::heightFor(uint16 labelIndex) const {
	return heights[labelIndex];
}

int InfoForMainWindowLabels::justificationFlagFor(uint16 labelIndex) const {
	return justificationFlags[labelIndex];
}

float InfoForMainWindowLabels::fontSizeFor(uint16 labelIndex) const {
	return fontSizes[labelIndex];
}

