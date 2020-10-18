#include "gui_InfoForControlLabels_Singleton.h"



InfoForControlLabels::InfoForControlLabels() {
	fillAllInfoContainers();
}

void InfoForControlLabels::fillAllInfoContainers() {
	static const auto lightLabels_h{ 20 };
	static const auto lightLabelsVerticalSpacing{ 28 };
	static const auto row1_y1{ 59 };
	static const auto row1_y2{ row1_y1 + lightLabels_h };
	static const auto row2_y1{ row1_y1 + lightLabelsVerticalSpacing };
	static const auto row2_y2{ row2_y1 + lightLabels_h };
	static const auto row3_y1{ row2_y1 + lightLabelsVerticalSpacing };
	static const auto row3_y2{ row3_y1 + lightLabels_h };
	static const auto row4_y1{ row3_y1 + lightLabelsVerticalSpacing };
	static const auto row4_y2{ row4_y1 + lightLabels_h };
	static const auto row5_y1{ row4_y1 + lightLabelsVerticalSpacing };
	static const auto row5_y2{ row5_y1 + lightLabels_h };
	static const auto row6_y1{ row5_y1 + lightLabelsVerticalSpacing };
	static const auto row6_y2{ row6_y1 + lightLabels_h };
	static const auto row7_y1{ row6_y1 + lightLabelsVerticalSpacing };
	static const auto row7_y2{ row7_y1 + lightLabels_h };
	static const auto row8_y1{ row7_y1 + lightLabelsVerticalSpacing };
	static const auto row8_y2{ row8_y1 + lightLabels_h };
	static const auto row9_y1{ row8_y1 + lightLabelsVerticalSpacing };
	static const auto row9_y2{ row9_y1 + lightLabels_h };
	static const auto row10_y1{ row9_y1 + lightLabelsVerticalSpacing };
	static const auto row10_y2{ row10_y1 + lightLabels_h };
	static const auto row11_y1{ row10_y1 + lightLabelsVerticalSpacing };
	static const auto row11_y2{ row11_y1 + lightLabels_h };
	static const auto row12_y1{ row11_y1 + lightLabelsVerticalSpacing };
	static const auto row12_y2{ row12_y1 + lightLabels_h };
	static const auto column1_x1{ 20 };
	static const auto column1_x2{ 96 };
	static const auto column2_x1{ 242 };
	static const auto column2_x2{ 348 };
	static const auto column3_x1{ 430 };
	static const auto column3_x2{ 504 };
	static const auto vcfFmColumn_x2{ 516 };
	static const auto column4_x1{ 596 };
	static const auto column4_x2{ 692 };
	static const auto column5_x1{ 840 };
	static const auto column5_x2{ 860 };
	static const auto heavyLabels_h{ 18 };
	static const auto heavyNumberLabels_w{ 16 };
	static const auto sourceDestinationLabels_w{ 82 };
	static const auto topRowHeavyLabels_y1{ 36 };
	static const auto topRowHeavyLabels_y2{ topRowHeavyLabels_y1 + heavyLabels_h };
	static const auto oscBalanceHeavyLabels_y1{ 359 };
	static const auto oscBalanceHeavyLabels_y2{ oscBalanceHeavyLabels_y1 + heavyLabels_h };
	static const auto trackingNumberLabel_y1{ 289 };
	static const auto trackingNumberLabel_y2{ trackingNumberLabel_y1 + heavyLabels_h };
	static const auto trackingNumberLabel_w{ 26 };
	static const auto trackingNumberLabelHorizontalSpacing{ 31 };
	static const auto matrixModNumberLabel_x1{ 1006 };
	static const auto matrixModNumberLabel_x2{ 1014 };
	static const auto envColumnHorizontalSpacing{ 410 };
	static const auto envColumn_w{ 74 };
	static const auto envRow1_y1{ 440 };
	static const auto envRow1_y2{ envRow1_y1 + lightLabels_h };
	static const auto envRow2_y1{ envRow1_y1 + lightLabelsVerticalSpacing };
	static const auto envRow2_y2{ envRow2_y1 + lightLabels_h };
	static const auto envRow3_y1{ envRow2_y1 + lightLabelsVerticalSpacing };
	static const auto envRow3_y2{ envRow3_y1 + lightLabels_h };
	static const auto envRow4_y1{ envRow3_y1 + lightLabelsVerticalSpacing };
	static const auto envRow4_y2{ envRow4_y1 + lightLabels_h };
	static const auto envRow5_y1{ envRow4_y1 + lightLabelsVerticalSpacing };
	static const auto envRow5_y2{ envRow5_y1 + lightLabels_h };

	//======================================================

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("PITCH");
	startPoints.add(Point<int>(column1_x1, row1_y1));
	endPoints.add(Point<int>(column1_x2, row1_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("LFO 1 FM AMOUNT");
	startPoints.add(Point<int>(column1_x1, row2_y1));
	endPoints.add(Point<int>(column1_x2, row2_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("SYNC 1 / DETUNE 2");
	startPoints.add(Point<int>(column1_x1, row3_y1));
	endPoints.add(Point<int>(column1_x2, row3_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("TYPE SELECT");
	startPoints.add(Point<int>(column1_x1, row4_y1));
	endPoints.add(Point<int>(column1_x2, row4_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("PULSE WIDTH");
	startPoints.add(Point<int>(column1_x1, row5_y1));
	endPoints.add(Point<int>(column1_x2, row5_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("SAW / TRI WAVE");
	startPoints.add(Point<int>(column1_x1, row6_y1));
	endPoints.add(Point<int>(column1_x2, row6_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("PWM BY LFO 2 AMT");
	startPoints.add(Point<int>(column1_x1, row7_y1));
	endPoints.add(Point<int>(column1_x2, row7_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("KEY CLICK");
	startPoints.add(Point<int>(column1_x1, row8_y1));
	endPoints.add(Point<int>(column1_x2, row8_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("KEY TRACKING");
	startPoints.add(Point<int>(column1_x1, row9_y1));
	endPoints.add(Point<int>(column1_x2, row9_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("LEVER CONTROL");
	startPoints.add(Point<int>(column1_x1, row10_y1));
	endPoints.add(Point<int>(column1_x2, row10_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("OSC BALANCE");
	startPoints.add(Point<int>(column1_x1, row11_y1));
	endPoints.add(Point<int>(column1_x2, row11_y2));

	//======================================================

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("CUTOFF FREQUENCY");
	startPoints.add(Point<int>(column2_x1, row1_y1));
	endPoints.add(Point<int>(column2_x2, row1_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("RESONANCE");
	startPoints.add(Point<int>(column2_x1, row2_y1));
	endPoints.add(Point<int>(column2_x2, row2_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("ENVELOPE 1 AMOUNT");
	startPoints.add(Point<int>(column2_x1, row3_y1));
	endPoints.add(Point<int>(column2_x2, row3_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("PRESSURE AMOUNT");
	startPoints.add(Point<int>(column2_x1, row4_y1));
	endPoints.add(Point<int>(column2_x2, row4_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("LEVER CONTROL");
	startPoints.add(Point<int>(column2_x1, row5_y1));
	endPoints.add(Point<int>(column2_x2, row5_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("KEY TRACKING");
	startPoints.add(Point<int>(column2_x1, row6_y1));
	endPoints.add(Point<int>(column2_x2, row6_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("VCA 1 VOLUME");
	startPoints.add(Point<int>(column2_x1, row9_y1));
	endPoints.add(Point<int>(column2_x2, row9_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("VCA 1 VELOCITY AMOUNT");
	startPoints.add(Point<int>(column2_x1, row10_y1));
	endPoints.add(Point<int>(column2_x2, row10_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("VCA 2 ENV 2 AMOUNT");
	startPoints.add(Point<int>(column2_x1, row11_y1));
	endPoints.add(Point<int>(column2_x2, row11_y2));

	//======================================================

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("OSC 1 AMOUNT");
	startPoints.add(Point<int>(column3_x1, row1_y1));
	endPoints.add(Point<int>(vcfFmColumn_x2, row1_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("ENVELOPE 3 AMOUNT");
	startPoints.add(Point<int>(column3_x1, row2_y1));
	endPoints.add(Point<int>(vcfFmColumn_x2, row2_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("PRESSURE AMOUNT");
	startPoints.add(Point<int>(column3_x1, row3_y1));
	endPoints.add(Point<int>(vcfFmColumn_x2, row3_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("RATE");
	startPoints.add(Point<int>(column3_x1, row6_y1));
	endPoints.add(Point<int>(column3_x2, row6_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("VELOCITY AMOUNT");
	startPoints.add(Point<int>(column3_x1, row7_y1));
	endPoints.add(Point<int>(column3_x2, row7_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("MODE");
	startPoints.add(Point<int>(column3_x1, row8_y1));
	endPoints.add(Point<int>(column3_x2, row8_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("LEGATO");
	startPoints.add(Point<int>(column3_x1, row9_y1));
	endPoints.add(Point<int>(column3_x2, row9_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("KEYBOARD MODE");
	startPoints.add(Point<int>(column3_x1, row12_y1));
	endPoints.add(Point<int>(column3_x2, row12_y2));

	//======================================================

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("SPEED");
	startPoints.add(Point<int>(column4_x1, row1_y1));
	endPoints.add(Point<int>(column4_x2, row1_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("WAVE TYPE");
	startPoints.add(Point<int>(column4_x1, row2_y1));
	endPoints.add(Point<int>(column4_x2, row2_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("SAMPLE SOURCE");
	startPoints.add(Point<int>(column4_x1, row3_y1));
	endPoints.add(Point<int>(column4_x2, row3_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("AMPLITUDE");
	startPoints.add(Point<int>(column4_x1, row4_y1));
	endPoints.add(Point<int>(column4_x2, row4_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("PRESSURE 1 / KEY 2");
	startPoints.add(Point<int>(column4_x1, row5_y1));
	endPoints.add(Point<int>(column4_x2, row5_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("RAMP 1 / RAMP 2");
	startPoints.add(Point<int>(column4_x1, row6_y1));
	endPoints.add(Point<int>(column4_x2, row6_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("TRIGGER MODE");
	startPoints.add(Point<int>(column4_x1, row7_y1));
	endPoints.add(Point<int>(column4_x2, row7_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("RETRIGGER POINT");
	startPoints.add(Point<int>(column4_x1, row8_y1));
	endPoints.add(Point<int>(column4_x2, row8_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("LAG");
	startPoints.add(Point<int>(column4_x1, row9_y1));
	endPoints.add(Point<int>(column4_x2, row9_y2));

	//======================================================

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("RATE");
	startPoints.add(Point<int>(column5_x1, row1_y1));
	endPoints.add(Point<int>(column5_x2, row1_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("TRIG");
	startPoints.add(Point<int>(column5_x1, row2_y1));
	endPoints.add(Point<int>(column5_x2, row2_y2));

	labelTypes.add(ControlLabelType::light);
	labelStrings.add("INPUT");
	startPoints.add(Point<int>(column5_x1, 155));
	endPoints.add(Point<int>(892, 155 + lightLabels_h));

	//======================================================

	labelTypes.add(ControlLabelType::subHeader);
	labelStrings.add("1");
	startPoints.add(Point<int>(122, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(122 + heavyNumberLabels_w, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::subHeader);
	labelStrings.add("2");
	startPoints.add(Point<int>(188, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(188 + heavyNumberLabels_w, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::subHeader);
	labelStrings.add("1");
	startPoints.add(Point<int>(718, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(718 + heavyNumberLabels_w, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::subHeader);
	labelStrings.add("2");
	startPoints.add(Point<int>(784, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(784 + heavyNumberLabels_w, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::subHeader);
	labelStrings.add("1");
	startPoints.add(Point<int>(886, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(886 + heavyNumberLabels_w, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::subHeader);
	labelStrings.add("2");
	startPoints.add(Point<int>(952, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(952 + heavyNumberLabels_w, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::subHeader);
	labelStrings.add("SOURCE");
	startPoints.add(Point<int>(1016, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(1016 + sourceDestinationLabels_w, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::subHeader);
	labelStrings.add("AMT");
	startPoints.add(Point<int>(1104, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(1144, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::subHeader);
	labelStrings.add("DESTINATION");
	startPoints.add(Point<int>(1150, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(1150 + sourceDestinationLabels_w, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::subHeader);
	labelStrings.add("1");
	startPoints.add(Point<int>(100, oscBalanceHeavyLabels_y1));
	endPoints.add(Point<int>(100 + heavyNumberLabels_w, oscBalanceHeavyLabels_y2));

	labelTypes.add(ControlLabelType::subHeader);
	labelStrings.add("2");
	startPoints.add(Point<int>(210, oscBalanceHeavyLabels_y1));
	endPoints.add(Point<int>(210 + heavyNumberLabels_w, oscBalanceHeavyLabels_y2));

	//======================================================

	for (auto i = 0; i != 5; ++i) {
		labelTypes.add(ControlLabelType::trackingAndMatrixNumbers);
		labelStrings.add((String)(i + 1));
		auto label_x{ column5_x1 + i * trackingNumberLabelHorizontalSpacing };
		startPoints.add(Point<int>(label_x, trackingNumberLabel_y1));
		endPoints.add(Point<int>(label_x + trackingNumberLabel_w, trackingNumberLabel_y2));
	}

	for (auto i = 0; i != 10; ++i) {
		labelTypes.add(ControlLabelType::trackingAndMatrixNumbers);
		labelStrings.add((String)i);
		auto label_y1{ row1_y1 + i * lightLabelsVerticalSpacing };
		auto label_y2{ label_y1 + lightLabels_h };
		startPoints.add(Point<int>(matrixModNumberLabel_x1, label_y1));
		endPoints.add(Point<int>(matrixModNumberLabel_x2, label_y2));
	}

	//======================================================

	for (auto i = 0; i != 3; ++i) {
		auto label_x1{ column1_x1 + i * envColumnHorizontalSpacing };
		auto label_x2{ label_x1 + envColumn_w };
		auto envShapeLabels_y1{ 550 };
		auto envShapeLabels_y2{ envShapeLabels_y1 + lightLabels_h };
		auto envShapeLabels_w{ 34 };
		auto envShapeLabelsHorizontalSpacing{ 50 };
		auto envDelayLabel_x1{ 181 + i * envColumnHorizontalSpacing };
		auto envDelayLabel_x2{ envDelayLabel_x1 + envShapeLabels_w };
		auto envAttackLabel_x1{ envDelayLabel_x1 + envShapeLabelsHorizontalSpacing };
		auto envAttackLabel_x2{ envAttackLabel_x1 + envShapeLabels_w };
		auto envDecayLabel_x1{ envAttackLabel_x1 + envShapeLabelsHorizontalSpacing };
		auto envDecayLabel_x2{ envDecayLabel_x1 + envShapeLabels_w };
		auto envSustainLabel_x1{ envDecayLabel_x1 + envShapeLabelsHorizontalSpacing };
		auto envSustainLabel_x2{ envSustainLabel_x1 + envShapeLabels_w };
		auto envReleaseLabel_x1{ envSustainLabel_x1 + envShapeLabelsHorizontalSpacing };
		auto envReleaseLabel_x2{ envReleaseLabel_x1 + envShapeLabels_w };

		labelTypes.add(ControlLabelType::light);
		labelStrings.add("AMPLITUDE");
		startPoints.add(Point<int>(label_x1, envRow1_y1));
		endPoints.add(Point<int>(label_x2, envRow1_y2));

		labelTypes.add(ControlLabelType::light);
		labelStrings.add("VELOCITY AMOUNT");
		startPoints.add(Point<int>(label_x1, envRow2_y1));
		endPoints.add(Point<int>(label_x2, envRow2_y2));

		labelTypes.add(ControlLabelType::light);
		labelStrings.add("TRIGGER MODE");
		startPoints.add(Point<int>(label_x1, envRow3_y1));
		endPoints.add(Point<int>(label_x2, envRow3_y2));

		labelTypes.add(ControlLabelType::light);
		labelStrings.add("ENVELOPE MODE");
		startPoints.add(Point<int>(label_x1, envRow4_y1));
		endPoints.add(Point<int>(label_x2, envRow4_y2));

		labelTypes.add(ControlLabelType::light);
		labelStrings.add("LFO 1 TRIGGER");
		startPoints.add(Point<int>(label_x1, envRow5_y1));
		endPoints.add(Point<int>(label_x2, envRow5_y2));

		labelTypes.add(ControlLabelType::envShapeControls);
		labelStrings.add("DELAY");
		startPoints.add(Point<int>(envDelayLabel_x1, envShapeLabels_y1));
		endPoints.add(Point<int>(envDelayLabel_x2, envShapeLabels_y2));

		labelTypes.add(ControlLabelType::envShapeControls);
		labelStrings.add("ATTACK");
		startPoints.add(Point<int>(envAttackLabel_x1, envShapeLabels_y1));
		endPoints.add(Point<int>(envAttackLabel_x2, envShapeLabels_y2));

		labelTypes.add(ControlLabelType::envShapeControls);
		labelStrings.add("DECAY");
		startPoints.add(Point<int>(envDecayLabel_x1, envShapeLabels_y1));
		endPoints.add(Point<int>(envDecayLabel_x2, envShapeLabels_y2));

		labelTypes.add(ControlLabelType::envShapeControls);
		labelStrings.add("SUSTAIN");
		startPoints.add(Point<int>(envSustainLabel_x1, envShapeLabels_y1));
		endPoints.add(Point<int>(envSustainLabel_x2, envShapeLabels_y2));

		labelTypes.add(ControlLabelType::envShapeControls);
		labelStrings.add("RELEASE");
		startPoints.add(Point<int>(envReleaseLabel_x1, envShapeLabels_y1));
		endPoints.add(Point<int>(envReleaseLabel_x2, envShapeLabels_y2));
	}
}

InfoForControlLabels& InfoForControlLabels::get() noexcept {
	static InfoForControlLabels labelsInfo;
	return labelsInfo;
}

int InfoForControlLabels::labelOutOfRange() const noexcept {
	return labelTypes.size();
}

ControlLabelType InfoForControlLabels::typeFor(int labelNumber) {
	return labelTypes[labelNumber];
}

String InfoForControlLabels::textFor(int labelNumber) {
	return labelStrings[labelNumber];
}

Point<int> InfoForControlLabels::startPointFor(int labelNumber) {
	return startPoints[labelNumber];
}

Point<int> InfoForControlLabels::endPointFor(int labelNumber) {
	return endPoints[labelNumber];
}
