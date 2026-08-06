#pragma once

#include <JuceHeader.h>

namespace PATH
{

	static const unsigned char knob[] = {
		110,109,0,0,152,65,0,0,24,66,108,0,72,180,65,0,84,6,66,98,75,233,232,65,77,241,255,65,0,0,8,66,255,135,208,65,0,0,8,66,0,0,152,65,98,0,0,8,66,164,112,43,65,174,71,218,65,0,0,128,64,0,0,152,65,0,0,128,64,98,188,116,43,65,0,0,128,64,0,0,128,64,164,112,
		43,65,0,0,128,64,0,0,152,65,98,0,0,128,64,92,134,208,65,178,43,14,65,169,235,255,65,0,104,119,65,0,82,6,66,108,49,112,119,65,0,82,6,66,99,101,0,0
	};
	
	static Path pixel(float x, float y) {
		Path p;
		p.addRectangle(x, y, 2.0f, 2.0f);
		return p;
	}

	static const Path lcd_pixel_1_1{ pixel(0.0f , 0.0f ) };
	static const Path lcd_pixel_1_2{ pixel(2.5f , 0.0f ) };
	static const Path lcd_pixel_1_3{ pixel(5.0f , 0.0f ) };
	static const Path lcd_pixel_1_4{ pixel(7.5f , 0.0f ) };
	static const Path lcd_pixel_1_5{ pixel(10.0f, 0.0f ) };
	static const Path lcd_pixel_2_1{ pixel(0.0f , 2.5f ) };
	static const Path lcd_pixel_2_2{ pixel(2.5f , 2.5f ) };
	static const Path lcd_pixel_2_3{ pixel(5.0f , 2.5f ) };
	static const Path lcd_pixel_2_4{ pixel(7.5f , 2.5f ) };
	static const Path lcd_pixel_2_5{ pixel(10.0f, 2.5f ) };
	static const Path lcd_pixel_3_1{ pixel(0.0f , 5.0f ) };
	static const Path lcd_pixel_3_2{ pixel(2.5f , 5.0f ) };
	static const Path lcd_pixel_3_3{ pixel(5.0f , 5.0f ) };
	static const Path lcd_pixel_3_4{ pixel(7.5f , 5.0f ) };
	static const Path lcd_pixel_3_5{ pixel(10.0f, 5.0f ) };
	static const Path lcd_pixel_4_1{ pixel(0.0f , 7.5f ) };
	static const Path lcd_pixel_4_2{ pixel(2.5f , 7.5f ) };
	static const Path lcd_pixel_4_3{ pixel(5.0f , 7.5f ) };
	static const Path lcd_pixel_4_4{ pixel(7.5f , 7.5f ) };
	static const Path lcd_pixel_4_5{ pixel(10.0f, 7.5f ) };
	static const Path lcd_pixel_5_1{ pixel(0.0f , 10.0f) };
	static const Path lcd_pixel_5_2{ pixel(2.5f , 10.0f) };
	static const Path lcd_pixel_5_3{ pixel(5.0f , 10.0f) };
	static const Path lcd_pixel_5_4{ pixel(7.5f , 10.0f) };
	static const Path lcd_pixel_5_5{ pixel(10.0f, 10.0f) };
	static const Path lcd_pixel_6_1{ pixel(0.0f , 12.5f) };
	static const Path lcd_pixel_6_2{ pixel(2.5f , 12.5f) };
	static const Path lcd_pixel_6_3{ pixel(5.0f , 12.5f) };
	static const Path lcd_pixel_6_4{ pixel(7.5f , 12.5f) };
	static const Path lcd_pixel_6_5{ pixel(10.0f, 12.5f) };
	static const Path lcd_pixel_7_1{ pixel(0.0f , 15.0f) };
	static const Path lcd_pixel_7_2{ pixel(2.5f , 15.0f) };
	static const Path lcd_pixel_7_3{ pixel(5.0f , 15.0f) };
	static const Path lcd_pixel_7_4{ pixel(7.5f , 15.0f) };
	static const Path lcd_pixel_7_5{ pixel(10.0f, 15.0f) };

}