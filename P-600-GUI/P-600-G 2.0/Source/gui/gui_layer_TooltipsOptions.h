#pragma once

#include <JuceHeader.h>

#include "gui_comp_ButtonForHidingLayer.h"
#include "gui_comp_JuceSlidersWithMouseMods.h"

class TooltipsOptions;

class GUI_Layer_TooltipsOptions :
	public Component,
	public Value::Listener
{
	TooltipsOptions* tooltips;
	ButtonForHidingLayer btn_Exit;
	LinearSliderWithMouseWheelMoveOverride switch_Descriptions;
	LinearSliderWithMouseWheelMoveOverride switch_CurrentChoice;
	Label lbl_delayTimeEditor;
	Value shouldShowDescriptionAsValue;

public:
	GUI_Layer_TooltipsOptions() = delete;

	GUI_Layer_TooltipsOptions(TooltipsOptions* tooltips, UndoManager* undoManager);

private:
	void updateTooltips();

public:
	void paint(Graphics& g) override;
	void valueChanged(Value& value) override;
	~GUI_Layer_TooltipsOptions();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_TooltipsOptions)

};