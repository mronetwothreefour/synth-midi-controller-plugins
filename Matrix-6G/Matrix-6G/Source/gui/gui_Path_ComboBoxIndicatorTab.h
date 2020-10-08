#pragma once

#include <JuceHeader.h>

namespace ComboBoxIndicatorTabPathData {
	static const std::vector<uint8> pathData{ 110,109,0,0,192,64,0,0,192,64,108,0,0,160,64,0,0,160,64,108,0,0,160,64,0,0,128,63,108,0,0,192,64,0,0,0,0,108,0,0,192,64,0,0,192,64,99,109,0,0,128,63,0,0,160,64,108,0,0,0,0,0,0,192,64,108,0,0,160,64,0,0,192,64,108,0,0,128,64,0,0,160,64,108,0,0,128,63,
		0,0,160,64,99,101,0,0 };
}

struct ComboBoxIndicatorTab  {
	static Path createPath() {
		Path path;
		path.loadPathFromData(ComboBoxIndicatorTabPathData::pathData.data(), ComboBoxIndicatorTabPathData::pathData.size());
		return path;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxIndicatorTab)
};