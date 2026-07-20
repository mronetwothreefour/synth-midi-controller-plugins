#pragma once

namespace XYWH
{

	constexpr double editor_aspect_ratio{ 2.10067 };

	constexpr float led_display_y{ 3 };
	constexpr float rotary_slider_begin_angle{ degreesToRadians(225.0f) };
	constexpr float rotary_slider_end_angle{ degreesToRadians(495.0f) };

	constexpr int editor_init_w{ 1252 }, editor_init_h{ 596 };

	constexpr int led_display_left_inset{ 6 };
	constexpr int led_display_right_inset{ 1 };
	constexpr int led_display_char_w{ 11 };

}