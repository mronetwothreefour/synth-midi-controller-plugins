#pragma once

#include <JuceHeader.h>

#include "gui_Colors.h"
#include "gui_Fonts.h"
#include "gui_InfoForControlLabels_Singleton.h"



class ControlLabelsLayer :
	public Component
{
public:
	ControlLabelsLayer() = default;

	void paint(Graphics& g) override {
		auto& info{ InfoForControlLabels::get() };
		for (auto label = 0; label != info.labelOutOfRange(); ++label) {
			g.setColour(Color::offWhite);
			const auto labelType{ info.typeFor(label) };
			const auto fontFamily{ labelType == ControlLabelType::light ? FontsDB::family_LightText : FontsDB::family_HeavyText };
			const auto fontStyle{ labelType == ControlLabelType::light ? FontsDB::style_ForLightText : FontsDB::style_ForHeavyText };
			const auto fontSize{ labelType == ControlLabelType::heavy ? FontsDB::size_ForControlLabelHeavyText : FontsDB::size_ForControlLabelLightText };
			const Font font{ fontFamily, fontStyle, fontSize };
			g.setFont(font);
			const auto justification{ labelType == ControlLabelType::light ? Justification::right : Justification::centred };
			Rectangle<int> labelArea{ info.startPointFor(label), info.endPointFor(label) };
			g.drawFittedText(info.textFor(label), labelArea, justification, 1, 1.0f);
		}
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlLabelsLayer)
};

