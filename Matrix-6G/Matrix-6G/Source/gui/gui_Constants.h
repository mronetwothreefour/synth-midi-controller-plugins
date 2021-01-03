#pragma once

#include <JuceHeader.h>



namespace constants
{
	namespace GUI
	{
		static const float envelopeEnd_x{ 217.0f };
		static const float envelopeMaximum_y{ 10.0f };
		static const float envelopeMaxSegment_w{ 43.0f };
		static const float envelopeMinimum_y{ 98.0f };
		static const float envelope_h{ envelopeMinimum_y - envelopeMaximum_y };
		static const float envelopeStart_x{ 11.0f };
		static const float envelopeSustainSegment_w{ 34.0f };
		static const float ledDisplayRightSideInset{ 1.0f };
		static const float ledDisplayCharacter_w{ 11.0f };
		static const float ledDisplay_y{ 3.0f };
		static const float trackingGeneratorMaximum_y{ 10.0f };
		static const float trackingGeneratorMinimum_y{ 70.0f };
		static const float trackingGenerator_h{ trackingGeneratorMinimum_y - trackingGeneratorMaximum_y };
		static const float trackingGeneratorSegment_w{ 33.0f };
		static const float trackingGeneratorPoint1_x{ 9.0f };
		static const float trackingGeneratorPoint2_x{ trackingGeneratorPoint1_x + trackingGeneratorSegment_w };
		static const float trackingGeneratorPoint3_x{ trackingGeneratorPoint2_x + trackingGeneratorSegment_w };
		static const float trackingGeneratorPoint4_x{ trackingGeneratorPoint3_x + trackingGeneratorSegment_w };
		static const float trackingGeneratorPoint5_x{ trackingGeneratorPoint4_x + trackingGeneratorSegment_w };

		static const int editor_w{ 1252 };
		static const int editor_h{ 596 };
		static const int envRenderersHorizontalSpacing{ 410 };
		static const int env1Renderer_x{ 184 };
		static const int env2Renderer_x{ env1Renderer_x + envRenderersHorizontalSpacing };
		static const int env3Renderer_x{ env2Renderer_x + envRenderersHorizontalSpacing };
		static const int envelopeRenderers_h{ 108 };
		static const int envelopeRenderers_w{ 228 };
		static const int envelopeRenderers_y{ 408 };
		static const int mainWindowSmallButtons_y{ 367 };
		static const int mainWindowSmallButtons_w{ 34 };
		static const int matrixModComboBoxes_w{ 82 };
		static const int matrixModSlotControls_y{ 0 };
		static const int matrixModSlotControls_h{ 20 };
		static const int matrixModFirstSlot_y{ 59 };
		static const int matrixModSlots_w{ 216 };
		static const int matrixModSlots_x{ 1016 };
		static const int matrixModVerticalSpacingBetweenSlots{ 28 };
		static const int quickEditButton_w{ 70 };
		static const int quickEditButton_x{ 596 };
		static const int smallButtons_h{ 20 };
		static const int trackingGeneratorRenderer_h{ 80 };
		static const int trackingGeneratorRenderer_w{ 150 };
		static const int trackingGeneratorRenderer_x{ 840 };
		static const int trackingGeneratorRenderer_y{ 183 };

		static const PathStrokeType envelopeStrokeType{ 2.0f, PathStrokeType::JointStyle::curved, PathStrokeType::EndCapStyle::rounded };

		static const Rectangle<int> bounds_MatrixModSlot_0{ matrixModSlots_x, matrixModFirstSlot_y, matrixModSlots_w, matrixModSlotControls_h };
		static const Rectangle<int> bounds_MatrixModSlot_1{ matrixModSlots_x, matrixModFirstSlot_y + matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, matrixModSlotControls_h };
		static const Rectangle<int> bounds_MatrixModSlot_2{ matrixModSlots_x, matrixModFirstSlot_y + 2 * matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, matrixModSlotControls_h };
		static const Rectangle<int> bounds_MatrixModSlot_3{ matrixModSlots_x, matrixModFirstSlot_y + 3 * matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, matrixModSlotControls_h };
		static const Rectangle<int> bounds_MatrixModSlot_4{ matrixModSlots_x, matrixModFirstSlot_y + 4 * matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, matrixModSlotControls_h };
		static const Rectangle<int> bounds_MatrixModSlot_5{ matrixModSlots_x, matrixModFirstSlot_y + 5 * matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, matrixModSlotControls_h };
		static const Rectangle<int> bounds_MatrixModSlot_6{ matrixModSlots_x, matrixModFirstSlot_y + 6 * matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, matrixModSlotControls_h };
		static const Rectangle<int> bounds_MatrixModSlot_7{ matrixModSlots_x, matrixModFirstSlot_y + 7 * matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, matrixModSlotControls_h };
		static const Rectangle<int> bounds_MatrixModSlot_8{ matrixModSlots_x, matrixModFirstSlot_y + 8 * matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, matrixModSlotControls_h };
		static const Rectangle<int> bounds_MatrixModSlot_9{ matrixModSlots_x, matrixModFirstSlot_y + 9 * matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, matrixModSlotControls_h };
		static const Rectangle<int> bounds_MatrixModSlotComboBoxForDestination{ 134, matrixModSlotControls_y, matrixModComboBoxes_w, matrixModSlotControls_h };
		static const Rectangle<int> bounds_MatrixModSlotComboBoxForSource{ 0, matrixModSlotControls_y, matrixModComboBoxes_w, matrixModSlotControls_h };
		static const Rectangle<int> bounds_MatrixModSlotSliderForAmount{ 88, matrixModSlotControls_y, 40, matrixModSlotControls_h };
	}
}