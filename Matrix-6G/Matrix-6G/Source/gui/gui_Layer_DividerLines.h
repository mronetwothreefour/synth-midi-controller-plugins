#pragma once

#include <JuceHeader.h>

#include "gui_Colors.h"
#include "gui_InfoForDividerLines_Singleton.h"



class DividerLinesLayer :
	public Component
{
public:
	DividerLinesLayer() = default;

	void paint(Graphics& g) override {
		auto& info{ InfoForDividerLines::get() };
		for (auto path = 0; path != info.pathOutOfRange(); ++path) {
			g.setColour(info.typeFor(path) == DividerType::blue ? Color::dividerLine_blue : Color::dividerLine_gray);
			PathStrokeType stroke{ info.typeFor(path) == DividerType::blue ? 3.0f : 0.75f, PathStrokeType::JointStyle::mitered, PathStrokeType::EndCapStyle::butt };
			Path p;
			p.startNewSubPath(info.startPointFor(path));
			p.lineTo(info.endPointFor(path));
			g.strokePath(p, stroke);
		}
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DividerLinesLayer)
};

