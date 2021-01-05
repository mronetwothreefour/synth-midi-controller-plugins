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
		static const float patchNameFirstCharacter_x{ 881.0f };
		static const float patchNameCharacters_y{ 370.0f };
		static const float patchNameCharacter_w{ 11.0f };
		static const float patchNameGapBetweenCharacters{ 2.0f };
		static const float tooltipMaxWidth{ 400.0f };
		static const float trackingGeneratorMaximum_y{ 10.0f };
		static const float trackingGeneratorMinimum_y{ 70.0f };
		static const float trackingGenerator_h{ trackingGeneratorMinimum_y - trackingGeneratorMaximum_y };
		static const float trackingGeneratorSegment_w{ 33.0f };
		static const float trackingGeneratorPoint1_x{ 9.0f };
		static const float trackingGeneratorPoint2_x{ trackingGeneratorPoint1_x + trackingGeneratorSegment_w };
		static const float trackingGeneratorPoint3_x{ trackingGeneratorPoint2_x + trackingGeneratorSegment_w };
		static const float trackingGeneratorPoint4_x{ trackingGeneratorPoint3_x + trackingGeneratorSegment_w };
		static const float trackingGeneratorPoint5_x{ trackingGeneratorPoint4_x + trackingGeneratorSegment_w };

		static const int controls_h{ 20 };
		static const int controlsHorizontalGap{ 6 };
		static const int controlsVerticalGap{ 28 };
		static const int controlsRow1_y{ 69 };
		static const int controlsRow2_y{ controlsRow1_y + controlsVerticalGap };
		static const int controlsRow3_y{ controlsRow2_y + controlsVerticalGap };
		static const int controlsRow4_y{ controlsRow3_y + controlsVerticalGap };
		static const int controlsRow5_y{ controlsRow4_y + controlsVerticalGap };
		static const int controlsRow6_y{ controlsRow5_y + controlsVerticalGap };
		static const int controlsRow7_y{ controlsRow6_y + controlsVerticalGap };
		static const int controlsRow8_y{ controlsRow7_y + controlsVerticalGap };
		static const int controlsRow9_y{ controlsRow8_y + controlsVerticalGap };
		static const int controlsRow10_y{ controlsRow9_y + controlsVerticalGap };
		static const int controlsRow11_y{ controlsRow10_y + controlsVerticalGap };
		static const int controlsRow12_y{ controlsRow11_y + controlsVerticalGap };
		static const int defaultControl_w{ 60 };
		static const int editor_w{ 1252 };
		static const int editor_h{ 596 };
		static const int envShapeControls_w{ 28 };
		static const int envShapeControlsHorizontalGap{ 22 };
		static const int env1Delay_x{ 198 };
		static const int env1Attack_x{ env1Delay_x + envShapeControls_w + envShapeControlsHorizontalGap };
		static const int env1Decay_x{ env1Attack_x + envShapeControls_w + envShapeControlsHorizontalGap };
		static const int env1Sustain_x{ env1Decay_x + envShapeControls_w + envShapeControlsHorizontalGap };
		static const int env1Release_x{ env1Sustain_x + envShapeControls_w + envShapeControlsHorizontalGap };
		static const int envControls_w{ 72 };
		static const int env1Controls_x{ 134 };
		static const int envControlsRow1_y{ 450 };
		static const int envControlsRow2_y{ envControlsRow1_y + controlsVerticalGap };
		static const int envControlsRow3_y{ envControlsRow2_y + controlsVerticalGap };
		static const int envControlsRow4_y{ envControlsRow3_y + controlsVerticalGap };
		static const int envControlsRow5_y{ envControlsRow4_y + controlsVerticalGap };
		static const int envRenderersHorizontalSpacing{ 410 };
		static const int env1Renderer_x{ 184 };
		static const int env2Renderer_x{ env1Renderer_x + envRenderersHorizontalSpacing };
		static const int env3Renderer_x{ env2Renderer_x + envRenderersHorizontalSpacing };
		static const int envelopeRenderers_h{ 108 };
		static const int envelopeRenderers_w{ 228 };
		static const int envelopeRenderers_y{ 408 };
		static const int envSectionsHorizontalSpacing{ 410 };
		static const int lfo1Controls_x{ 726 };
		static const int lfo2Controls_x{ 792 };
		static const int mainWindowSmallButtons_y{ 367 };
		static const int mainWindowSmallButtons_w{ 34 };
		static const int matrixModComboBoxes_w{ 82 };
		static const int matrixModSlotControls_y{ 0 };
		static const int matrixModFirstSlot_y{ 59 };
		static const int matrixModSlots_w{ 216 };
		static const int matrixModSlots_x{ 1016 };
		static const int matrixModVerticalSpacingBetweenSlots{ 28 };
		static const int oscBalanceControl_x{ 163 };
		static const int oscBalanceControl_w{ 126 };
		static const int oscControlsCol1_x{ 130 };
		static const int oscControlsCol2_x{ 196 };
		static const int portaControls_w{ 72 };
		static const int portaControls_x{ 544 };
		static const int quickEditButton_w{ 70 };
		static const int quickEditButton_x{ 596 };
		static const int rampControlsCol1_x{ 894 };
		static const int rampControlsCol2_x{ 960 };
		static const int smallButtons_h{ 20 };
		static const int trackingGeneratorRenderer_h{ 80 };
		static const int trackingGeneratorRenderer_w{ 150 };
		static const int trackingGeneratorRenderer_x{ 840 };
		static const int trackingGeneratorRenderer_y{ 183 };
		static const int trackPointControls_w{ 26 };
		static const int trackPointControlsHorizontalGap{ 5 };
		static const int trackPoint1Control_x{ 853 };
		static const int trackPoint2Control_x{ trackPoint1Control_x + trackPointControls_w + trackPointControlsHorizontalGap };
		static const int trackPoint3Control_x{ trackPoint2Control_x + trackPointControls_w + trackPointControlsHorizontalGap };
		static const int trackPoint4Control_x{ trackPoint3Control_x + trackPointControls_w + trackPointControlsHorizontalGap };
		static const int trackPoint5Control_x{ trackPoint4Control_x + trackPointControls_w + trackPointControlsHorizontalGap };
		static const int trackPointControls_y{ 279 };
		static const int vcfCol_x{ 382 };
		static const int vcfFMcontrols_x{ 550 };

		static const PathStrokeType envelopeStrokeType{ 2.0f, PathStrokeType::JointStyle::curved, PathStrokeType::EndCapStyle::rounded };

		static const Rectangle<int> bounds_MatrixModSlot_0{ matrixModSlots_x, matrixModFirstSlot_y, matrixModSlots_w, controls_h };
		static const Rectangle<int> bounds_MatrixModSlot_1{ matrixModSlots_x, matrixModFirstSlot_y + matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, controls_h };
		static const Rectangle<int> bounds_MatrixModSlot_2{ matrixModSlots_x, matrixModFirstSlot_y + 2 * matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, controls_h };
		static const Rectangle<int> bounds_MatrixModSlot_3{ matrixModSlots_x, matrixModFirstSlot_y + 3 * matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, controls_h };
		static const Rectangle<int> bounds_MatrixModSlot_4{ matrixModSlots_x, matrixModFirstSlot_y + 4 * matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, controls_h };
		static const Rectangle<int> bounds_MatrixModSlot_5{ matrixModSlots_x, matrixModFirstSlot_y + 5 * matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, controls_h };
		static const Rectangle<int> bounds_MatrixModSlot_6{ matrixModSlots_x, matrixModFirstSlot_y + 6 * matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, controls_h };
		static const Rectangle<int> bounds_MatrixModSlot_7{ matrixModSlots_x, matrixModFirstSlot_y + 7 * matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, controls_h };
		static const Rectangle<int> bounds_MatrixModSlot_8{ matrixModSlots_x, matrixModFirstSlot_y + 8 * matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, controls_h };
		static const Rectangle<int> bounds_MatrixModSlot_9{ matrixModSlots_x, matrixModFirstSlot_y + 9 * matrixModVerticalSpacingBetweenSlots, matrixModSlots_w, controls_h };
		static const Rectangle<int> bounds_MatrixModSlotComboBoxForDestination{ 134, matrixModSlotControls_y, matrixModComboBoxes_w, controls_h };
		static const Rectangle<int> bounds_MatrixModSlotComboBoxForSource{ 0, matrixModSlotControls_y, matrixModComboBoxes_w, controls_h };
		static const Rectangle<int> bounds_MatrixModSlotSliderForAmount{ 88, matrixModSlotControls_y, 40, controls_h };
		static const Rectangle<int> bounds_PatchNameEditor{ 873, 367, 117, controls_h };
		static const Rectangle<int> bounds_PatchNumberSlider{ 840, 367, 28, controls_h };

		static const String apostrophe{ CharPointer_UTF8("\xe2\x80\x99") };
		static const String openQuote{ CharPointer_UTF8("\xe2\x80\x9c") };
		static const String closeQuote{ CharPointer_UTF8("\xe2\x80\x9d") };

		static const std::vector<uint8> pathDataForSegment_A{ 110,109,113,61,234,63,0,0,0,0,108,31,133,3,65,0,0,0,0,108,31,133,3,65,236,81,184,62,108,215,163,248,64,195,245,40,63,108,82,184,230,64,215,163,48,63,108,133,235,217,64,102,102,102,63,108,133,235,169,64,102,102,102,63,108,102,102,158,64,0,0,0,63,108,215,163,136,64,0,0,0,63,108,82,184,126,64,123,20,110,63,108,82,184,78,64,123,20,110,63,108,123,20,62,64,246,40,28,63,108,92,143,18,64,246,40,28,63,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_B{ 110,109,61,10,255,64,113,61,138,63,108,143,194,253,64,236,81,56,64,108,133,235,241,64,154,153,89,64,108,123,20,230,64,205,204,188,64,108,143,194,237,64,20,174,207,64,108,184,30,253,64,20,174,207,64,108,154,153,5,65,164,112,189,64,108,72,225,10,65,225,122,180,63,108,72,225,6,65,10,215,35,63,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_C{ 110,109,143,194,221,64,10,215,251,64,108,184,30,237,64,133,235,233,64,108,154,153,249,64,154,153,233,64,108,51,51,3,65,20,174,255,64,108,123,20,238,64,123,20,82,65,108,92,143,226,64,236,81,88,65,108,205,204,212,64,51,51,79,65,108,246,40,220,64,164,112,49,65,108,61,10,215,64,72,225,42,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_D{ 110,109,20,174,7,63,184,30,89,65,108,102,102,102,63,246,40,80,65,108,133,235,241,63,174,71,81,65,108,102,102,6,64,20,174,75,65,108,164,112,29,64,31,133,75,65,108,195,245,56,64,143,194,85,65,108,82,184,110,64,143,194,85,65,108,72,225,130,64,123,20,78,65,108,154,153,177,64,82,184,78,65,108,0,0,184,64,225,122,84,65,108,82,184,206,64,246,40,84,65,108,20,174,215,64,82,184,90,65,108,20,174,207,64,0,0,96,65,108,133,235,81,63,0,0,96,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_E{ 110,109,215,163,112,63,123,20,230,64,108,92,143,162,63,123,20,230,64,108,123,20,206,63,10,215,251,64,108,246,40,188,63,61,10,19,65,108,195,245,136,63,82,184,26,65,108,143,194,53,63,61,10,75,65,108,41,92,143,62,143,194,85,65,108,0,0,0,0,0,0,76,65,108,205,204,12,63,174,71,241,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_F{ 110,109,0,0,160,63,113,61,10,63,108,195,245,200,63,225,122,148,62,108,61,10,247,63,102,102,102,63,108,51,51,211,63,246,40,92,64,108,246,40,252,63,184,30,133,64,108,113,61,234,63,164,112,189,64,108,51,51,179,63,164,112,205,64,108,0,0,128,63,164,112,205,64,108,143,194,53,63,246,40,188,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_G{ 110,109,154,153,25,64,92,143,162,63,108,102,102,6,64,154,153,89,64,108,123,20,62,64,61,10,191,64,108,143,194,85,64,41,92,191,64,108,0,0,96,64,82,184,134,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_H{ 110,109,31,133,131,64,143,194,149,63,108,143,194,149,64,205,204,76,63,108,225,122,164,64,184,30,165,63,108,246,40,148,64,143,194,189,64,108,61,10,135,64,246,40,204,64,108,61,10,119,64,246,40,204,64,108,184,30,101,64,133,235,193,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_I{ 110,109,41,92,159,64,82,184,158,64,108,51,51,227,64,51,51,147,63,108,133,235,241,64,205,204,140,63,108,174,71,241,64,61,10,39,64,108,184,30,173,64,0,0,192,64,108,184,30,157,64,0,0,192,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_J{ 110,109,215,163,144,64,123,20,214,64,108,133,235,153,64,102,102,198,64,108,154,153,217,64,102,102,198,64,108,102,102,230,64,20,174,215,64,108,246,40,228,64,184,30,229,64,108,164,112,213,64,225,122,244,64,108,205,204,156,64,225,122,244,64,108,0,0,144,64,41,92,231,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_K{ 110,109,61,10,151,64,225,122,252,64,108,195,245,160,64,225,122,252,64,108,133,235,209,64,10,215,51,65,108,246,40,204,64,225,122,76,65,108,143,194,189,64,205,204,76,65,108,113,61,146,64,184,30,21,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_L{ 110,109,61,10,87,64,143,194,245,64,108,246,40,108,64,72,225,234,64,108,164,112,125,64,113,61,234,64,108,31,133,139,64,82,184,246,64,108,164,112,125,64,92,143,66,65,108,51,51,99,64,215,163,80,65,108,184,30,69,64,195,245,80,65,108,41,92,47,64,205,204,72,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_M{ 110,109,61,10,39,64,205,204,252,64,108,246,40,60,64,205,204,252,64,108,82,184,46,64,184,30,37,65,108,92,143,226,63,31,133,75,65,108,195,245,136,63,61,10,75,65,108,51,51,179,63,154,153,41,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_N{ 110,109,61,10,183,63,164,112,213,64,108,195,245,232,63,20,174,199,64,108,113,61,90,64,20,174,199,64,108,82,184,110,64,133,235,209,64,108,31,133,107,64,92,143,226,64,108,20,174,71,64,72,225,242,64,108,20,174,231,63,10,215,243,64,108,51,51,179,63,0,0,224,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_O{ 110,109,102,102,6,65,41,92,59,65,108,195,245,16,65,143,194,53,65,108,102,102,30,65,0,0,60,65,108,143,194,29,65,154,153,77,65,108,195,245,16,65,92,143,82,65,108,184,30,5,65,195,245,76,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_P{ 110,109,184,30,5,65,123,20,86,65,108,72,225,2,65,236,81,116,65,108,246,40,8,65,236,81,116,65,108,31,133,27,65,215,163,96,65,108,195,245,28,65,31,133,87,65,99,101,0,0 };
		static const std::vector<uint8> verticalBarPathData{ 110,109,0,0,128,63,0,0,16,65,108,0,0,0,63,0,0,32,65,108,0,0,0,0,0,0,16,65,108,0,0,0,0,0,0,0,64,108,0,0,0,63,0,0,128,63,108,0,0,128,63,0,0,0,64,108,0,0,128,63,0,0,16,65,99,109,0,0,128,63,0,0,144,65,108,0,0,0,63,0,0,152,65,108,0,0,0,0,0,0,144,65,108,0,0,0,0,0,0,48,65,108,0,0,0,63,0,0,32,65,108,0,0,128,63,0,0,48,65,108,0,0,128,63,0,0,144,65,99,101,0,0 };
	}
}