#pragma once

#include "G_DRAW_Envelope_A.h"

namespace DRAW
{

	class Envelope :
		public Envelope_A
	{
	//==============================================================================
	public: Envelope(const int env_num, Data_Hub* hub);

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Envelope)
	};

}
