#pragma once

#include <JuceHeader.h>

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_PathData.h"

using namespace P_600_G_Constants;

struct LED_NumeralPath
{
	static Path buildForNumeral(uint8 numeral) {
		jassert(numeral < 10);
		switch (numeral)
		{
		case 0: {
			Path path_0;
			path_0.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
			path_0.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
			path_0.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
			path_0.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
			path_0.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
			path_0.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
			return path_0;
		}
		case 1: {
			Path path_1;
			path_1.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
			path_1.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
			return path_1;
		}
		case 2: {
			Path path_2;
			path_2.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
			path_2.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
			path_2.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
			path_2.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
			path_2.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
			return path_2;
		}
		case 3: {
			Path path_3;
			path_3.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
			path_3.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
			path_3.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
			path_3.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
			path_3.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
			return path_3;
		}
		case 4: {
			Path path_4;
			path_4.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
			path_4.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
			path_4.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
			path_4.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
			return path_4;
		}
		case 5: {
			Path path_5;
			path_5.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
			path_5.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
			path_5.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
			path_5.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
			path_5.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
			return path_5;
		}
		case 6: {
			Path path_6;
			path_6.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
			path_6.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
			path_6.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
			path_6.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
			path_6.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
			return path_6;
		}
		case 7: {
			Path path_7;
			path_7.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
			path_7.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
			path_7.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
			return path_7;
		}
		case 8: {
			Path path_8;
			path_8.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
			path_8.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
			path_8.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
			path_8.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
			path_8.loadPathFromData(GUI::pathDataForSegment_E.data(), GUI::pathDataForSegment_E.size());
			path_8.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
			path_8.loadPathFromData(GUI::pathDataForSegment_G.data(), GUI::pathDataForSegment_G.size());
			return path_8;
		}
		case 9: {
			Path path_9;
			path_9.loadPathFromData(GUI::pathDataForSegment_A.data(), GUI::pathDataForSegment_A.size());
			path_9.loadPathFromData(GUI::pathDataForSegment_B.data(), GUI::pathDataForSegment_B.size());
			path_9.loadPathFromData(GUI::pathDataForSegment_C.data(), GUI::pathDataForSegment_C.size());
			path_9.loadPathFromData(GUI::pathDataForSegment_D.data(), GUI::pathDataForSegment_D.size());
			path_9.loadPathFromData(GUI::pathDataForSegment_F.data(), GUI::pathDataForSegment_F.size());
			return path_9;
		}
		default:
			return Path{};
		}
	}
};