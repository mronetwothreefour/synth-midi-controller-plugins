#pragma once

#include <JuceHeader.h>

#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../guiRenderers/guiRenderer_ControlValue.h"



class EditableLabel :
	public Label
{
public:
	EditableLabel() = delete;

	EditableLabel(const String& componentName, const String& labelText) :
		Label{ componentName, labelText }
	{
		setFont(FontsMenu::fontFor_LabelEditors);
		setColour(Label::textColourId, Colours::transparentWhite);
		setColour(Label::backgroundColourId, Colours::transparentBlack);
		setColour(Label::outlineColourId, Colours::transparentBlack);
		setColour(Label::textWhenEditingColourId, Color::led_blue);
		setColour(Label::backgroundWhenEditingColourId, Color::black);
		setColour(Label::outlineWhenEditingColourId, Color::black);
		setEditable(true);
	}

	void paint(Graphics& g) override {
		ControlValueRenderer::paintValueStringInComponent(g, getText(), this);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EditableLabel)
};