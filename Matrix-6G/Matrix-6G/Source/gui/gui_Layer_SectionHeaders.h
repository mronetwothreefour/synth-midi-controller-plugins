#pragma once

#include <JuceHeader.h>

#include "gui_Colors.h"
#include "gui/gui_Fonts.h"
#include "gui_InfoForSectionHeaders_Singleton.h"



class SectionHeadersLayer :
	public Component
{
public:
	SectionHeadersLayer() = default;

	void paint(Graphics& g) override {
		const auto textGapHorizontalOffset{ 10.0f };
		const auto textGapVerticalOffset{ -1.0f };
		const auto textGap_h{ 18.0f };
		const auto textGapWidthBuffer{ 10.0f };
		auto& info{ InfoForSectionHeaders::get() };
		Font headerFont(FontsDB::family_HeavyText, FontsDB::style_ForHeavyText, FontsDB::size_ForSectionHeaderText);
		for (auto header = 0; header != info.headerOutOfRange(); ++header) {
			g.setColour(Color::dividerLine_blue);
			Rectangle<int> blueBar{ info.startPointFor(header), info.endPointFor(header) };
			g.fillRect(blueBar);

			AttributedString text;
			text.setJustification(Justification::centred);
			text.append(info.textFor(header), headerFont, Color::offWhite);
			TextLayout layout;
			layout.createLayout(text, 150.0f);
			auto textGap_x{ blueBar.getX() + textGapHorizontalOffset };
			auto textGap_y{ blueBar.getY() + textGapVerticalOffset };
			auto textGap_w{ layout.getWidth() + textGapWidthBuffer };
			Rectangle<float> textGap{ textGap_x, textGap_y, textGap_w, textGap_h };
			g.setColour(Color::device);
			g.fillRect(textGap);
			layout.draw(g, textGap);
		}
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SectionHeadersLayer)
};

