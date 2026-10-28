#pragma once

#include "D_X_G_Data_User_P.h"

using Mods = ModifierKeys;

namespace LAYER
{

	class Buttons_Main :
		public Component,
		public Data_User
	{
	//==============================================================================
	public: explicit Buttons_Main(Data_Hub* hub);

	public: void resized() override;
	public: void modifierKeysChanged(const Mods& mods) override;

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Buttons_Main)
	};

}
