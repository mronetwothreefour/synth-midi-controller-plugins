#pragma once

#include "G_DRAW_Envelope_P.h"
#include "G_DRAW_Tracking_Env_P.h"

namespace LAYER
{

	class Envelopes :
		public Component,
		public Data_User
	{
	private: DRAW::Tracking_Env tracking_env;
	private: DRAW::Envelope env_1;
	private: DRAW::Envelope env_2;
	private: DRAW::Envelope env_3;

	//==============================================================================
	public: explicit Envelopes(Data_Hub* hub);

	public: void resized() override;

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Envelopes)
	};

}
