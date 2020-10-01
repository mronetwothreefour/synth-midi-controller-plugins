#include "gui_InfoForControlLabels_Singleton.h"



InfoForControlLabels::InfoForControlLabels() {
	fillAllInfoContainers();
}

void InfoForControlLabels::fillAllInfoContainers() {
	static const auto heavyLabels_h{ 18 };
	static const auto heavyNumberLabels_w{ 16 };
	static const auto sourceDestinationLabels_w{ 82 };
	static const auto topRowHeavyLabels_y1{ 36 };
	static const auto topRowHeavyLabels_y2{ topRowHeavyLabels_y1 + heavyLabels_h };
	static const auto oscBalanceHeavyLabels_y1{ 359 };
	static const auto oscBalanceHeavyLabels_y2{ oscBalanceHeavyLabels_y1 + heavyLabels_h };

	//======================================================

	labelTypes.add(ControlLabelType::heavy);
	labelStrings.add("1");
	startPoints.add(Point<int>(122, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(122 + heavyNumberLabels_w, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::heavy);
	labelStrings.add("2");
	startPoints.add(Point<int>(188, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(188 + heavyNumberLabels_w, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::heavy);
	labelStrings.add("1");
	startPoints.add(Point<int>(718, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(718 + heavyNumberLabels_w, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::heavy);
	labelStrings.add("2");
	startPoints.add(Point<int>(784, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(784 + heavyNumberLabels_w, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::heavy);
	labelStrings.add("1");
	startPoints.add(Point<int>(886, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(886 + heavyNumberLabels_w, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::heavy);
	labelStrings.add("2");
	startPoints.add(Point<int>(952, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(952 + heavyNumberLabels_w, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::heavy);
	labelStrings.add("SOURCE");
	startPoints.add(Point<int>(1016, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(1016 + sourceDestinationLabels_w, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::heavy);
	labelStrings.add("AMT");
	startPoints.add(Point<int>(1104, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(1144, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::heavy);
	labelStrings.add("DESTINATION");
	startPoints.add(Point<int>(1150, topRowHeavyLabels_y1));
	endPoints.add(Point<int>(1150 + sourceDestinationLabels_w, topRowHeavyLabels_y2));

	labelTypes.add(ControlLabelType::heavy);
	labelStrings.add("1");
	startPoints.add(Point<int>(100, oscBalanceHeavyLabels_y1));
	endPoints.add(Point<int>(100 + heavyNumberLabels_w, oscBalanceHeavyLabels_y2));

	labelTypes.add(ControlLabelType::heavy);
	labelStrings.add("2");
	startPoints.add(Point<int>(210, oscBalanceHeavyLabels_y1));
	endPoints.add(Point<int>(210 + heavyNumberLabels_w, oscBalanceHeavyLabels_y2));
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
