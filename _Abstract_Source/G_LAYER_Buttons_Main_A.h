#pragma once

#include "D_X_G_Data_User_P.h"

using Mods = ModifierKeys;

namespace LAYER
{

	class Buttons_Main_A :
		public Component,
		public Data_User
	{
	protected: TextButton btn_push;
	protected: TextButton btn_pull;
	protected: TextButton btn_undo;
	protected: TextButton btn_redo;

	protected: const Rectangle<int> init_bounds_btn_push;
	protected: const Rectangle<int> init_bounds_btn_pull;
	protected: const Rectangle<int> init_bounds_btn_undo;
	protected: const Rectangle<int> init_bounds_btn_redo;

	//==============================================================================
	public: explicit Buttons_Main_A(Data_Hub* hub);

	public: void resized() override;
	public: void modifierKeysChanged(const Mods& mods) override;

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Buttons_Main_A)
	};

}

