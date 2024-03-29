#pragma once

#include <JuceHeader.h>

using Browser = FileBrowserComponent;
using DirContents = DirectoryContentsDisplayComponent;
using Preview = FilePreviewComponent;

class P_600_LookAndFeel :
	public LookAndFeel_V4
{
public:
	P_600_LookAndFeel() = default;

	void drawButtonBackground(Graphics& g, Button& button, const Colour& background, bool isHighlighted, bool isDown) override;
	void drawButtonText(Graphics& g, TextButton& button, bool isHighlighted, bool isDown) override;

	void drawComboBox(Graphics& g, int width, int height, bool isDown, int x, int y, int w, int h, ComboBox& comboBox) override;
	void drawPopupMenuBackground(Graphics& g, int w, int h) override;
	void drawPopupMenuItem(Graphics& g, const Rectangle<int>& area, const bool isSeparator, const bool isActive,
		const bool isHighlighted, const bool isTicked, const bool hasSubMenu, const String& text, const String& shortcutText,
		const Drawable* icon, const Colour* const textColor) override;

	void layoutFileBrowserComponent(
		Browser& browser, DirContents* dirContents, Preview* preview, ComboBox* currentPath, TextEditor* fileName, Button* goUpButton) override;
	void drawFileBrowserRow(Graphics& g, int w, int h, const File& file, const String& fileName, Image* icon, const String& fileSizeString,
		const String& fileTimeString, bool isDirectory, bool isSelected, int itemIndex, DirContents& dirContents) override;
	Button* createFileBrowserGoUpButton() override;

	void drawLabel(Graphics& g, Label& label) override;
	void fillTextEditorBackground(Graphics& g, int w, int h, TextEditor& textEditor) override;
	void drawTextEditorOutline(Graphics& g, int w, int h, TextEditor& textEditor) override;

	void drawProgressBar(Graphics& g, ProgressBar& bar, int w, int h, double percentDone, const String& textToShow) override;

	int getDefaultScrollbarWidth() override;
	void drawScrollbar(
		Graphics& g, ScrollBar& scrollbar, int x, int y, int w, int h, bool isVertical,
		int thumbStartPosition, int thumbSize, bool mouseIsOver, bool mouseIsDown) override;

	void drawLinearSlider(
		Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos,
		float maxSliderPos, const Slider::SliderStyle style, Slider& slider) override;
	void drawRotarySlider(
		Graphics& g, int x, int y, int w, int h, float sliderPos, const float startAngle, const float endAngle, Slider& slider) override;

	void drawToggleButton(Graphics& g, ToggleButton& button, bool isHighlighted, bool isDown) override;
	void drawTickBox(
		Graphics& g, Component& component, float x, float y, float w, float h, const bool isTicked,
		const bool isEnabled, const bool isHighlighted, const bool isDown) override;

	void drawTooltip(Graphics& g, const String& text, int width, int height) override;
	Rectangle<int> getTooltipBounds(const String& tipText, Point<int> screenPos, Rectangle<int> parentArea) override;
	TextLayout layoutTooltipText(const String& text, Colour colour) noexcept;
};