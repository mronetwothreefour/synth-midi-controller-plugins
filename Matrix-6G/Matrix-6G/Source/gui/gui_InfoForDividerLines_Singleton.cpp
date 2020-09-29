#include "gui_InfoForDividerLines_Singleton.h"




InfoForDividerLines::InfoForDividerLines() {
	fillAllInfoContainers();
}

void InfoForDividerLines::fillAllInfoContainers() {
	static const auto topRow_y{ 55.0f };
	static const auto verticalSpacing{ 28.0f };
	static const auto leftmostColumn_x{ 20.0f };
	static const auto oscColumnEnd_x{ 226.0f };

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
