#pragma once

#include <JuceHeader.h>

#include "C_COLOR_P.h"
#include "C_FONT_P.h"
#include "C_ID_P.h"
#include "C_XYWH_P.h"

class Look_And_Feel_B :
	public LookAndFeel_V4
{
protected: float& scale_factor;

//==============================================================================
public: explicit Look_And_Feel_B(float& scale_factor);

public: void drawComboBox(Graphics& /*g*/, int /*w*/, int /*h*/, bool /*down*/, int /*x*/, int /*y*/,
						  int /*w*/, int /*h*/, ComboBox& /*cbox*/) override {}
public: void getIdealPopupMenuItemSizeWithOptions(const String& txt, bool separator,
												  int standard_h, int& ideal_w, int& ideal_h,
												  const PopupMenu::Options& o) override;

public: void drawLabel(Graphics& g, Label& lbl) override;
public: virtual void draw_label_p(Graphics& g, Label& lbl, String& id)=0;
public: void fillTextEditorBackground(Graphics& g, int w, int h, TextEditor& editor) override;
public: void drawTextEditorOutline(Graphics& /*g*/, int /*w*/, int /*h*/, TextEditor& /*editor*/) override {}

public: void drawToggleButton(Graphics& g, ToggleButton& btn, bool hilited, bool down) override;

public: void drawTooltip(Graphics& g, const String& txt, int w, int h) override;
public: Rectangle<int> getTooltipBounds(const String& tip_txt, Point<int> position, Rectangle<int> parent_area) override;
public: TextLayout layout_tip_text(const String& txt) noexcept;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Look_And_Feel_B)
};