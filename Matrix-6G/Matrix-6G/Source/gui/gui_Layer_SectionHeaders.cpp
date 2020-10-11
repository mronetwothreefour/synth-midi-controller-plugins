#include "gui_Layer_SectionHeaders.h"

#include "gui_Colors.h"
#include "gui_InfoForSectionHeaders_Singleton.h"



void SectionHeadersLayer::paint(Graphics& g) {
	auto& info{ InfoForSectionHeaders::get() };
	for (auto header = 0; header != info.headerOutOfRange(); ++header) {
		paintBlueBarForHeader(g, header);
	}
}

void SectionHeadersLayer::paintBlueBarForHeader(Graphics& g, int header) {
	auto& info{ InfoForSectionHeaders::get() };
	g.setColour(Color::dividerLine_blue);
	Rectangle<int> blueBar{ info.startPointFor(header), info.endPointFor(header) };
	g.fillRect(blueBar);
	createHeaderTextLayout(g, info.textFor(header), blueBar);
}

void SectionHeadersLayer::createHeaderTextLayout(Graphics& g, String headerText, Rectangle<int> blueBar) {
	AttributedString text;
	text.setJustification(Justification::centred);
	text.append(headerText, FontsMenu::fontFor_SectionHeaderText, Color::offWhite);
	TextLayout layout;
	layout.createLayout(text, 150.0f);
	paintTextLayoutInBlueBar(g, layout, blueBar);
}

void SectionHeadersLayer::paintTextLayoutInBlueBar(Graphics& g, TextLayout layout, Rectangle<int> blueBar) {
	auto textGap_x{ blueBar.getX() + textGapHorizontalOffset };
	auto textGap_y{ blueBar.getY() + textGapVerticalOffset };
	auto textGap_w{ layout.getWidth() + textGapWidthBuffer };
	Rectangle<float> textGap{ textGap_x, textGap_y, textGap_w, textGap_h };
	g.setColour(Color::device);
	g.fillRect(textGap);
	layout.draw(g, textGap);
}
