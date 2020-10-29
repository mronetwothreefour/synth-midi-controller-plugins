#pragma once

#include <JuceHeader.h>



struct FontCreator {
	static Font createFontFromTypeface_Size_Kerning(Typeface::Ptr typeface, float size, float kerning) {
		Font font{ typeface };
		font.setSizeAndStyle(size, font.getTypefaceStyle(), 1.0f, kerning);
		return font;
	}
};

namespace FontsMenu
{
	static const Typeface::Ptr Overpass_Bold{ Typeface::createSystemTypefaceFor(BinaryData::OverpassBold_ttf, BinaryData::OverpassBold_ttfSize) };

	static const Font fontFor_Labels{ FontCreator::createFontFromTypeface_Size_Kerning(Overpass_Bold, 14.5f, 0.0f) };
	static const Font fontFor_PopupMenuItems{ FontCreator::createFontFromTypeface_Size_Kerning(Overpass_Bold, 14.5f, 0.0f) };

	static const String family_Global{ "Arial" };

	static const String style_ForProgressDisplayMessage{ "Bold" };
	static const String style_ForProgressDisplayTitle{ "Black" };
	static const String style_ForButtonText{ "Black" };
	static const String style_ForControlLabels{ "Black" };
	static const String style_ForComponentTitle{ "Black" };
	static const String style_ForKnobValueDisplay{ "Narrow Bold" };
	static const String style_ForLabelText{ "Narrow Bold" };
	static const String style_ForPgmNameEditorText{ "Black" };
	static const String style_ForPgmSlotButtonText{ "Regular" };
	static const String style_ForPulseWidthText{ "Narrow" };
	static const String style_ForSeqStepValueDisplay{ "Narrow Bold" };
	static const String style_ForTabText{ "Black" };
	static const String style_ForTooltipText{ "Narrow Bold" };
	static const String style_ForBoldHardwareSettingsWarningMessage{ "Bold" };
	static const String style_ForHardwareSettingsWarningMessage{ "Regular" };

	static const float size_ForProgressDisplayMessage{ 17.0f };
	static const float size_ForProgressDisplayTitle{ 25.0f };
	static const float size_ForButtonText{ 11.0f };
	static const float size_ForControlLabels{ 12.0f };
	static const float size_ForComponentTitle{ 18.0f };
	static const float size_ForKnobValueDisplay{ 13.0f };
	static const float size_ForLabelText{ 13.0f };
	static const float size_ForLargeNumLabels{ 24.0f };
	static const float size_ForPgmNameEditorText{ 18.0f };
	static const float size_ForPgmSlotButtonText{ 12.0f };
	static const float size_ForPgmBanksWindowLabels{ 18.0f };
	static const float size_ForPulseWidthText{ 11.0f };
	static const float size_ForSectionLabels{ 18.0f };
	static const float size_ForSeqStepLabels{ 12.0f };
	static const float size_ForSeqStepValueDisplay{ 13.0f };
	static const float size_ForTabText{ 18.0f };
	static const float size_ForTooltipText{ 14.0f };
	static const float size_ForOscMix1and2Labels{ 13.0f };
	static const float size_ForBoldHardwareSettingsWarningMessage{ 13.0f };
	static const float size_ForHardwareSettingsWarningMessage{ 12.0f };
};
