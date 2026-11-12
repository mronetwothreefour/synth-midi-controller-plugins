#pragma once

#include "G_LAYER_Buttons_Main_A.h"

using Mods = ModifierKeys;

namespace LAYER
{

	class Buttons_Main :
		public Buttons_Main_A
	{
	private: OwnedArray<TextButton> vmode_buttons;
	private: Array<Rectangle<int>> vmode_init_bounds;

	//==============================================================================
	public: explicit Buttons_Main(Data_Hub* hub);

	public: void resized() override;
	public: void modifierKeysChanged(const Mods& mods) override;
	public: ~Buttons_Main();

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Buttons_Main)
	};

}
