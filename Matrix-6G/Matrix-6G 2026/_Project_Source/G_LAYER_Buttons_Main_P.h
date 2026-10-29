#pragma once

#include "G_LAYER_Buttons_Main_A.h"

using Mods = ModifierKeys;

namespace LAYER
{

	class Buttons_Main :
		public Buttons_Main_A
	{
	private: TextButton btn_quick;

	private: const Rectangle<int> init_bounds_btn_quick;

	//==============================================================================
	public: explicit Buttons_Main(Data_Hub* hub);

	public: void resized() override;
	private: void flash_btn_quick();
	public: void modifierKeysChanged(const Mods& mods) override;

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Buttons_Main)
	};

}
