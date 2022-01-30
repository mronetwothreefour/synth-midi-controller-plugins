#pragma once

#include <JuceHeader.h>

#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../guiRenderers/guiRenderer_LCDNumber.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"

using namespace constants;



class LCDdisplayEditor :
	public Label
{
public:
	LCDdisplayEditor() = delete;

	LCDdisplayEditor(const String& componentName, const String& labelText) :
		Label{ componentName, labelText }
	{
		setComponentID(ID::label_LCDdisplayEditor.toString());
		setFont(FontsMenu::fontFor_LCDdisplayEditor);
		setColour(Label::textColourId, Colours::transparentWhite);
		setColour(Label::backgroundColourId, Colours::transparentBlack);
		setColour(Label::outlineColourId, Colours::transparentBlack);
		setColour(Label::textWhenEditingColourId, Color::lcdRed);
		setColour(Label::backgroundWhenEditingColourId, Color::black);
		setColour(Label::outlineWhenEditingColourId, Color::black);
		setEditable(true);
	}

	void paint(Graphics& g) override {
		LCDnumberRenderer::paintValueStringInComponent(g, getText().paddedLeft('0', GUI::maxNumberOfDigitsInLCDeditor));
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LCDdisplayEditor)
};