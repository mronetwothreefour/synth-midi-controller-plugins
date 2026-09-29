#include "D_BUILD_Font_For_P.h"

#include "C_RES_Fonts_P.h"

using namespace BUILD;

const Font Font_For::cbox(const float scale_factor) {
	return Font{ RES::semi }.withPointHeight(10.5f * scale_factor);
}

const Font Font_For::file_browser(const float scale_factor) {
	return Font{ RES::bold }.withPointHeight(12.0f * scale_factor);
}

const Font Font_For::knob(const float scale_factor) {
	return Font{ RES::bold }.withPointHeight(11.0f * scale_factor);
}

const Font Font_For::knob_txt_edit(const float scale_factor) {
	return Font{ RES::bold }.withPointHeight(11.0f * scale_factor);
}

const Font Font_For::pulse_w_txt(const float scale_factor) {
	return Font{ RES::bold }.withPointHeight(9.0f * scale_factor);
}

const Font Font_For::seq_step(const float scale_factor) {
	return Font{ RES::bold }.withPointHeight(9.5f * scale_factor);
}

const Font Font_For::tip() {
	return Font{ RES::bold }.withPointHeight(12.0f);
}
