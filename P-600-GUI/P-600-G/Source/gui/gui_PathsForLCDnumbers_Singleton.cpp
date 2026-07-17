#include "gui_PathsForLCDnumbers_Singleton.h"

#include "gui_Constants.h"

using namespace constants;



PathsForLCDdigits::PathsForLCDdigits() {
	fillDigitPaths();
}

void PathsForLCDdigits::fillDigitPaths() {
	digitPaths.add(createPathFor0());
	digitPaths.add(createPathFor1());
	digitPaths.add(createPathFor2());
	digitPaths.add(createPathFor3());
	digitPaths.add(createPathFor4());
	digitPaths.add(createPathFor5());
	digitPaths.add(createPathFor6());
	digitPaths.add(createPathFor7());
	digitPaths.add(createPathFor8());
	digitPaths.add(createPathFor9());
}

Path PathsForLCDdigits::createPathFor0() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
	return path;
}

Path PathsForLCDdigits::createPathFor1() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	return path;
}

Path PathsForLCDdigits::createPathFor2() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
	return path;
}

Path PathsForLCDdigits::createPathFor3() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
	return path;
}

Path PathsForLCDdigits::createPathFor4() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	return path;
}

Path PathsForLCDdigits::createPathFor5() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
	return path;
}

Path PathsForLCDdigits::createPathFor6() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
	return path;
}

Path PathsForLCDdigits::createPathFor7() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	return path;
}

Path PathsForLCDdigits::createPathFor8() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	path.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
	return path;
}

Path PathsForLCDdigits::createPathFor9() {
	Path path;
	path.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
	path.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
	path.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
	path.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
	path.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
	return path;
}

PathsForLCDdigits& PathsForLCDdigits::get() noexcept {
	static PathsForLCDdigits pathsForLCDdigits;
	return pathsForLCDdigits;
}

Path PathsForLCDdigits::getPathForDigit(uint8 digit) {
	jassert(digit < 10);
	return digitPaths[digit];
}
