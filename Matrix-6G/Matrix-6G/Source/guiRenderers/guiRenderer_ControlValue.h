#pragma once

#include <JuceHeader.h>

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Path_LEDcharacters_Singleton.h"
#include "../params/params_Identifiers.h"

using namespace constants;



struct ControlValueRenderer {
	static void paintValueStringInComponent(Graphics& g, const String& valueString, Component* component) {
		g.setColour(Color::led_blue);
		auto& charPaths{ LEDcharacterPaths::get() };
		Path positionPath;
		auto ledDisplayLastCharacter_x{ component->getWidth() - GUI::ledDisplayRightSideInset - GUI::ledDisplayCharacter_w };
		auto lastCharacterIndex{ (int)valueString.toStdString().size() - 1 };
		auto spaceBetweenCharacters{ 0 };
		if (component->getComponentID() == ID::label_PatchNameEditor.toString())
			spaceBetweenCharacters = 3;
		for (auto i = lastCharacterIndex; i != -1; --i) {
			auto charNum{ (uint8)valueString[i] };
			auto character_x{ ledDisplayLastCharacter_x - ((GUI::ledDisplayCharacter_w + spaceBetweenCharacters) * (lastCharacterIndex - i)) };
			positionPath.addPath(charPaths.getPathForChar(charNum), AffineTransform::translation(character_x, GUI::ledDisplay_y));
		}
		g.fillPath(positionPath);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlValueRenderer)
};