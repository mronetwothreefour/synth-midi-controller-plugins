#pragma once

#include <JuceHeader.h>

#include "C_COLOR_P.h"
#include "C_FONT_P.h"
#include "C_ID_P.h"

class Look_And_Feel_B :
	public LookAndFeel_V4
{
//==============================================================================
public: Look_And_Feel_B();

public: void drawComboBox(Graphics& /*g*/, int /*w*/, int /*h*/, bool /*down*/, int /*x*/, int /*y*/,
						  int /*w*/, int /*h*/, ComboBox& /*cbox*/) override {}

public: void drawTextEditorOutline(Graphics& /*g*/, int /*w*/, int /*h*/, TextEditor& /*editor*/) override {}

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Look_And_Feel_B)
};