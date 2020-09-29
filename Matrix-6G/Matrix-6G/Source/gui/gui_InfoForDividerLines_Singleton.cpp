#include "gui_InfoForDividerLines_Singleton.h"




InfoForDividerLines::InfoForDividerLines() {
	fillAllInfoContainers();
}

void InfoForDividerLines::fillAllInfoContainers() {
	static const auto topRow_y{ 55.0f };
	static const auto buildLine_y{ 391.0f };
	static const auto topEnvRow_y{ 436.0f };
	static const auto bottomEnvRow_y{ 576.0f };
	static const auto verticalSpacing{ 28.0f };
	static const auto leftmostColumn_x{ 20.0f };
	static const auto oscColumnEnd_x{ 226.0f };
	static const auto env1ColumnEnd_x{ 170.0f };
	static const auto column2Start_x{ 242.0f };
	static const auto column2End_x{ 412.0f };
	static const auto column3Start_x{ 430.0f };
	static const auto column3End_x{ 580.0f };
	static const auto column4Start_x{ 596.0f };
	static const auto column4End_x{ 822.0f };
	static const auto column5Start_x{ 840.0f };
	static const auto column5End_x{ 990.0f };
	static const auto column6Start_x{ 1006.0f };
	static const auto column6End_x{ 1232.0f };

	//======================================================

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(leftmostColumn_x, topRow_y));
	endPoints.add(Point<float>(oscColumnEnd_x, topRow_y));

	for (auto i = 1; i != 11; ++i) {
		dividerTypes.add(DividerType::gray);
		auto divider_y{ topRow_y + verticalSpacing * i };
		startPoints.add(Point<float>(leftmostColumn_x, divider_y));
		endPoints.add(Point<float>(oscColumnEnd_x, divider_y));
	}

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(leftmostColumn_x, topEnvRow_y));
	endPoints.add(Point<float>(env1ColumnEnd_x, topEnvRow_y));

	for (auto i = 1; i != 5; ++i) {
		dividerTypes.add(DividerType::gray);
		auto divider_y{ topEnvRow_y + verticalSpacing * i };
		startPoints.add(Point<float>(leftmostColumn_x, divider_y));
		endPoints.add(Point<float>(env1ColumnEnd_x, divider_y));
	}

	//======================================================

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column2Start_x, topRow_y));
	endPoints.add(Point<float>(column2End_x, topRow_y));

	for (auto i = 1; i != 6; ++i) {
		dividerTypes.add(DividerType::gray);
		auto divider_y{ topRow_y + verticalSpacing * i };
		startPoints.add(Point<float>(column2Start_x, divider_y));
		endPoints.add(Point<float>(column2End_x, divider_y));
	}

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column2Start_x, topRow_y + verticalSpacing * 6));
	endPoints.add(Point<float>(column2End_x, topRow_y + verticalSpacing * 6));

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column2Start_x, topRow_y + verticalSpacing * 8));
	endPoints.add(Point<float>(column2End_x, topRow_y + verticalSpacing * 8));

	for (auto i = 9; i != 11; ++i) {
		dividerTypes.add(DividerType::gray);
		auto divider_y{ topRow_y + verticalSpacing * i };
		startPoints.add(Point<float>(column2Start_x, divider_y));
		endPoints.add(Point<float>(column2End_x, divider_y));
	}

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column2Start_x, topRow_y + verticalSpacing * 11));
	endPoints.add(Point<float>(column2End_x, topRow_y + verticalSpacing * 11));

	//======================================================

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column3Start_x, topRow_y));
	endPoints.add(Point<float>(column3End_x, topRow_y));

	for (auto i = 1; i != 3; ++i) {
		dividerTypes.add(DividerType::gray);
		auto divider_y{ topRow_y + verticalSpacing * i };
		startPoints.add(Point<float>(column3Start_x, divider_y));
		endPoints.add(Point<float>(column3End_x, divider_y));
	}

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column3Start_x, topRow_y + verticalSpacing * 3));
	endPoints.add(Point<float>(column3End_x, topRow_y + verticalSpacing * 3));

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column3Start_x, topRow_y + verticalSpacing * 5));
	endPoints.add(Point<float>(column3End_x, topRow_y + verticalSpacing * 5));

	for (auto i = 6; i != 9; ++i) {
		dividerTypes.add(DividerType::gray);
		auto divider_y{ topRow_y + verticalSpacing * i };
		startPoints.add(Point<float>(column3Start_x, divider_y));
		endPoints.add(Point<float>(column3End_x, divider_y));
	}

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column3Start_x, topRow_y + verticalSpacing * 9));
	endPoints.add(Point<float>(column3End_x, topRow_y + verticalSpacing * 9));

	for (auto i = 11; i != 13; ++i) {
		dividerTypes.add(DividerType::blue);
		auto divider_y{ topRow_y + verticalSpacing * i };
		startPoints.add(Point<float>(column3Start_x, divider_y));
		endPoints.add(Point<float>(column3End_x, divider_y));
	}

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column3Start_x, topEnvRow_y));
	endPoints.add(Point<float>(column3End_x, topEnvRow_y));

	for (auto i = 1; i != 5; ++i) {
		dividerTypes.add(DividerType::gray);
		auto divider_y{ topEnvRow_y + verticalSpacing * i };
		startPoints.add(Point<float>(column3Start_x, divider_y));
		endPoints.add(Point<float>(column3End_x, divider_y));
	}

	//======================================================

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column4Start_x, topRow_y));
	endPoints.add(Point<float>(column4End_x, topRow_y));

	for (auto i = 1; i != 9; ++i) {
		dividerTypes.add(DividerType::gray);
		auto divider_y{ topRow_y + verticalSpacing * i };
		startPoints.add(Point<float>(column4Start_x, divider_y));
		endPoints.add(Point<float>(column4End_x, divider_y));
	}

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column4Start_x, topRow_y + verticalSpacing * 9));
	endPoints.add(Point<float>(column4End_x, topRow_y + verticalSpacing * 9));

	for (auto i = 11; i != 13; ++i) {
		dividerTypes.add(DividerType::blue);
		auto divider_y{ topRow_y + verticalSpacing * i };
		startPoints.add(Point<float>(column4Start_x, divider_y));
		endPoints.add(Point<float>(column4End_x, divider_y));
	}

	//======================================================

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column5Start_x, topRow_y));
	endPoints.add(Point<float>(column5End_x, topRow_y));

	dividerTypes.add(DividerType::gray);
	startPoints.add(Point<float>(column5Start_x, topRow_y + verticalSpacing));
	endPoints.add(Point<float>(column5End_x, topRow_y + verticalSpacing));

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column5Start_x, topRow_y + verticalSpacing * 2));
	endPoints.add(Point<float>(column5End_x, topRow_y + verticalSpacing * 2));

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column5Start_x, topRow_y + verticalSpacing * 9));
	endPoints.add(Point<float>(column5End_x, topRow_y + verticalSpacing * 9));

	for (auto i = 11; i != 13; ++i) {
		dividerTypes.add(DividerType::blue);
		auto divider_y{ topRow_y + verticalSpacing * i };
		startPoints.add(Point<float>(column5Start_x, divider_y));
		endPoints.add(Point<float>(column5End_x, divider_y));
	}

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column5Start_x, topEnvRow_y));
	endPoints.add(Point<float>(column5End_x, topEnvRow_y));

	for (auto i = 1; i != 5; ++i) {
		dividerTypes.add(DividerType::gray);
		auto divider_y{ topEnvRow_y + verticalSpacing * i };
		startPoints.add(Point<float>(column5Start_x, divider_y));
		endPoints.add(Point<float>(column5End_x, divider_y));
	}

	//======================================================

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column6Start_x, topRow_y));
	endPoints.add(Point<float>(column6End_x, topRow_y));

	for (auto i = 1; i != 10; ++i) {
		dividerTypes.add(DividerType::gray);
		auto divider_y{ topRow_y + verticalSpacing * i };
		startPoints.add(Point<float>(column6Start_x, divider_y));
		endPoints.add(Point<float>(column6End_x, divider_y));
	}

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column6Start_x, topRow_y + verticalSpacing * 10));
	endPoints.add(Point<float>(column6End_x, topRow_y + verticalSpacing * 10));

	//======================================================

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(leftmostColumn_x, buildLine_y));
	endPoints.add(Point<float>(113, buildLine_y));

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(319, buildLine_y));
	endPoints.add(Point<float>(412, buildLine_y));

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(leftmostColumn_x, bottomEnvRow_y));
	endPoints.add(Point<float>(column2End_x, bottomEnvRow_y));

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column3Start_x, bottomEnvRow_y));
	endPoints.add(Point<float>(column4End_x, bottomEnvRow_y));

	dividerTypes.add(DividerType::blue);
	startPoints.add(Point<float>(column5Start_x, bottomEnvRow_y));
	endPoints.add(Point<float>(column6End_x, bottomEnvRow_y));
}

InfoForDividerLines& InfoForDividerLines::get() noexcept {
	static InfoForDividerLines dividerLinesInfo;
	return dividerLinesInfo;
}

int InfoForDividerLines::pathOutOfRange() const noexcept {
	return startPoints.size();
}

DividerType InfoForDividerLines::typeFor(int pathNumber) {
	return dividerTypes[pathNumber];
}

Point<float> InfoForDividerLines::startPointFor(int pathNumber) {
	return startPoints[pathNumber];
}

Point<float> InfoForDividerLines::endPointFor(int pathNumber) {
	return endPoints[pathNumber];
}
