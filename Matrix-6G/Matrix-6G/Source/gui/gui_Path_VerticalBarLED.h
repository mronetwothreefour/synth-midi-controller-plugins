#pragma once

#include <JuceHeader.h>

namespace VerticalBarLEDpathData {
	static const std::vector<uint8> pathData{ 110,109,0,0,128,63,0,0,16,65,108,0,0,0,63,0,0,32,65,108,0,0,0,0,0,0,16,65,108,0,0,0,0,0,0,0,64,108,0,0,0,63,0,0,128,63,108,0,0,128,63,0,0,0,64,108,0,0,128,63,0,0,16,65,99,109,0,0,128,63,0,0,144,65,108,0,0,0,63,0,0,152,65,108,0,0,0,0,0,0,144,65,108,0,
		0,0,0,0,0,48,65,108,0,0,0,63,0,0,32,65,108,0,0,128,63,0,0,48,65,108,0,0,128,63,0,0,144,65,99,101,0,0 };
}

struct VerticalBarLED {
	static Path createPath() {
		Path path;
		path.loadPathFromData(VerticalBarLEDpathData::pathData.data(), VerticalBarLEDpathData::pathData.size());
		return path;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VerticalBarLED)
};