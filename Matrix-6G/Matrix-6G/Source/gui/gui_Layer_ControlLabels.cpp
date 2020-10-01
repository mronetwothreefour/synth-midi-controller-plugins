#include "gui_Layer_ControlLabels.h"

#include "gui_Colors.h"
#include "gui_Fonts.h"



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
}

Font ControlLabelsLayer::getFontForLabelType(ControlLabelType labelType) const {
	auto fontFamily{ labelType == ControlLabelType::light ? FontsDB::family_LightText : FontsDB::family_HeavyText };
	auto fontStyle{ labelType == ControlLabelType::light ? FontsDB::style_ForLightText : FontsDB::style_ForHeavyText };
	auto fontSize{ labelType == ControlLabelType::heavy ? FontsDB::size_ForControlLabelHeavyText : FontsDB::size_ForControlLabelLightText };
	Font font{ fontFamily, fontStyle, fontSize };
	return font;
}
