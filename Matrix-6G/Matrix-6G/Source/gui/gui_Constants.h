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
		static const int quickEditButton_w{ 70 };
		static const int quickEditButton_x{ 596 };
		static const int smallButtons_h{ 20 };
		static const int trackingGeneratorRenderer_h{ 80 };
		static const int trackingGeneratorRenderer_w{ 150 };
		static const int trackingGeneratorRenderer_x{ 840 };
		static const int trackingGeneratorRenderer_y{ 183 };

		static const PathStrokeType envelopeStrokeType{ 2.0f, PathStrokeType::JointStyle::curved, PathStrokeType::EndCapStyle::rounded };
	}
}