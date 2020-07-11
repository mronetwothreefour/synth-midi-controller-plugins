#include "helper_InfoForMainWindowLabels_Singleton.h"

InfoForMainWindowLabels::InfoForMainWindowLabels() {
	fillAllInfoContainers();
}

void InfoForMainWindowLabels::fillAllInfoContainers() {
	auto knobLabel_w{ 44 };
	auto ctrlLabel_h{ 14 };

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

	auto oscCtrlLabelsRow1_y{ 73 };

	labelTexts.add("PITCH");
	centerPoints.add(Point<int>(48, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("FINE");
	centerPoints.add(Point<int>(93, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SHAPE");
	centerPoints.add(Point<int>(138, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("GLIDE");
	centerPoints.add(Point<int>(183, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SUB");
	centerPoints.add(Point<int>(228, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(Point<int>(273, 65));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("TRACK");
	centerPoints.add(Point<int>(273, 74));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	auto oscCtrlLabelsRow2_y{ 133 };

	labelTexts.add("PITCH");
	centerPoints.add(Point<int>(48, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("FINE");
	centerPoints.add(Point<int>(93, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SHAPE");
	centerPoints.add(Point<int>(138, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("GLIDE");
	centerPoints.add(Point<int>(183, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SUB");
	centerPoints.add(Point<int>(228, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(Point<int>(273, 125));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("TRACK");
	centerPoints.add(Point<int>(273, 134));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("GLIDE MODE");
	centerPoints.add(Point<int>(500, 93));
	widths.add(124);
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

