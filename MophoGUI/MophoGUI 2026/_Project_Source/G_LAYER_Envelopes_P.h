#pragma once

#include "G_DRAW_Envelope_P.h"

namespace LAYER
{

	class Envelopes :
		public Component,
		public Data_User
	{
	private: DRAW::Envelope env_lpf;
	private: DRAW::Envelope env_vca;
	private: DRAW::Envelope env_3;

	//==============================================================================
	public: explicit Envelopes(Data_Hub* hub);

	public: void resized() override;

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Envelopes)
	};

}
