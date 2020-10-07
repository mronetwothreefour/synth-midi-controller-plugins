#include "gui_Layer_ControlLabels.h"

#include "gui_Colors.h"
#include "gui_Fonts.h"



ControlLabelsLayer::ControlLabelsLayer() {
	setInterceptsMouseClicks(false, true);
	URL url{ "https://programming.mr1234.com/" };
	button_ForGoingToWebSite.setURL(url);
	button_ForGoingToWebSite.setColour(HyperlinkButton::ColourIds::textColourId, Color::offWhite);
	button_ForGoingToWebSite.setTooltip("Click to go to programming.mr1234.com");
	addAndMakeVisible(button_ForGoingToWebSite);

}

void ControlLabelsLayer::paint(Graphics& g) {
	g.setColour(Color::offWhite);
	auto& info{ InfoForControlLabels::get() };
	for (auto label = 0; label != info.labelOutOfRange(); ++label) {
		auto labelType{ info.typeFor(label) };
		g.setFont(getFontForLabelType(labelType));
		auto justification{ labelType == ControlLabelType::light ? Justification::right : Justification::centred };
		Rectangle<int> labelArea{ info.startPointFor(label), info.endPointFor(label) };
		g.drawFittedText(info.textFor(label), labelArea, justification, 1, 1.0f);
	}
	Font buildInfoFont{ FontsDB::family_BuildInfoText, FontsDB::style_ForBuildInfoText, FontsDB::size_ForBuildInfoText };
	g.setFont(buildInfoFont);
	Rectangle<int> buildInfoLabelArea{ 105, 380, 222, 20 };
	g.setColour(Color::device);
	g.fillRect(buildInfoLabelArea);
	g.setColour(Color::offWhite);
	g.drawFittedText("BUILD " + (String)ProjectInfo::versionString + "  |  MISTER 1-2-3-4 PROGRAMMING", buildInfoLabelArea, Justification::centred, 1, 1.0f);
}

Font ControlLabelsLayer::getFontForLabelType(ControlLabelType labelType) const {
	auto fontFamily{ labelType == ControlLabelType::light ? FontsDB::family_LightText : FontsDB::family_HeavyText };
	auto fontStyle{ labelType == ControlLabelType::light ? FontsDB::style_ForLightText : FontsDB::style_ForHeavyText };
	auto fontSize{ labelType == ControlLabelType::heavy ? FontsDB::size_ForControlLabelHeavyText : FontsDB::size_ForControlLabelLightText };
	Font font{ fontFamily, fontStyle, fontSize };
	return font;
}

void ControlLabelsLayer::resized() {
	button_ForGoingToWebSite.setBounds(176, 386, 146, 9);
}
