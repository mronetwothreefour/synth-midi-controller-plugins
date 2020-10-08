#pragma once

#include <JuceHeader.h>

#include "../gui/gui_Colors.h"
#include "../gui/gui_Path_LEDcharacters_Singleton.h"



struct PopupMenuItemRenderer {
	static void paintTextInArea(Graphics& g, const String& text, const Rectangle<int>& area) {
		g.setColour(Color::led_blue);
		auto& charPaths{ LEDcharacterPaths::get() };
		auto rightSideInset{ 1.0f };
		auto character_w{ 11.0f };
		auto lastCharacter_x{ area.getWidth() - rightSideInset - character_w };
		auto y{ 3.0f };
		Path positionPath;
		auto lastCharacterIndex{ (int)text.toStdString().size() - 1 };
		for (auto i = lastCharacterIndex; i != -1; --i) {
			auto charNum{ (uint8)text[i] };
			auto character_x{ lastCharacter_x - character_w * (lastCharacterIndex - i) };
			positionPath.addPath(charPaths.getPathForChar(charNum), AffineTransform::translation(character_x, y));
		}
		g.fillPath(positionPath);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PopupMenuItemRenderer)
};