#pragma once



namespace constants
{
	namespace GUI
	{
		static const int bankTransmitTitleLabel_x{ 454 };
		static const int bankTransmitTitleLabel_y{ 260 };
		static const int buttons_BanksWindow_w{ 50 };
		static const int buttons_BanksWindow_h{ 22 };

		static const int editor_w{ 1273 };
		static const int editor_h{ 626 };

		static const Rectangle<int> bounds_BanksWindow{ 89, 113, 1095, 400 };
		static const Rectangle<int> bounds_BankTransmitButtons{ 611, 344, buttons_BanksWindow_w, buttons_BanksWindow_h };
		static const Rectangle<int> bounds_BankTransmitMessage{ 461, 290, 351, 28 };
		static const Rectangle<int> bounds_BankTransmitProgressDisplayWindow{ 444, 251, 385, 124 };
		static const Rectangle<int> bounds_BankTransmitProgressBar{ 461, 319,351, 18 };
	}
}