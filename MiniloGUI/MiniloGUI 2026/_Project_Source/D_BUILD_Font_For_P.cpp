#include "D_BUILD_Font_For_P.h"

#include "C_RES_Fonts_P.h"

using namespace BUILD;

const Font BUILD::Font_For::cbox(const float scale_factor) {
	return Font{ RES::semi }.withPointHeight(10.5f * scale_factor);
}

const Font Font_For::file_browser(const float scale_factor) {
	return Font{ RES::bold }.withPointHeight(14.0f * scale_factor);
}

const Font Font_For::knob(const float scale_factor) {
	return Font{ RES::bold }.withPointHeight(10.0f * scale_factor);
}

const Font Font_For::knob_txt_edit(const float scale_factor) {
	return Font{ RES::bold }.withPointHeight(10.0f * scale_factor);
}

const Font Font_For::tip() {
	return Font{ RES::bold }.withPointHeight(12.0f);
}
