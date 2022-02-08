#pragma once

#include <JuceHeader.h>

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Path_LEDcharacters_Singleton.h"

using namespace constants;



struct PopupMenuItemRenderer {
	static void paintTextInArea(Graphics& g, const String& text, const Rectangle<int>& area) {
		g.setColour(Color::led_blue);
		auto& charPaths{ LEDcharacterPaths::get() };
		auto lastCharacter_x{ area.getWidth() - GUI::ledDisplayRightSideInset - GUI::ledDisplayCharacter_w };
		Path positionPath;
		auto lastCharacterIndex{ (int)text.toStdString().size() - 1 };
		for (auto i = lastCharacterIndex; i != -1; --i) {
			auto charNum{ (uint8)text[i] };
			auto character_x{ lastCharacter_x - GUI::ledDisplayCharacter_w * (lastCharacterIndex - i) };
			positionPath.addPath(charPaths.getPathForChar(charNum), AffineTransform::translation(character_x, GUI::ledDisplay_y));
		}
		g.fillPath(positionPath);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PopupMenuItemRenderer)
};