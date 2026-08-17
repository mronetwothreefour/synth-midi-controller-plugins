#include "D_BUILD_Font_For_P.h"

using namespace BinaryData;
using namespace BUILD;

inline const FontOptions Font_For::bold() {
	return Typeface::createSystemTypefaceFor(OverpassBold_ttf, OverpassBold_ttfSize);
}

inline const FontOptions Font_For::semi() {
	return Typeface::createSystemTypefaceFor(OverpassSemiBold_ttf, OverpassSemiBold_ttfSize);
}

inline const Font Font_For::cbox(const float scale_factor) {
	return Font{ semi() }.withPointHeight(10.5f * scale_factor);
}

inline const Font Font_For::file_browser(const float scale_factor) {
	return Font{ bold() }.withPointHeight(12.0f * scale_factor);
}

inline const Font Font_For::knob(const float scale_factor) {
	return Font{ bold() }.withPointHeight(11.0f * scale_factor);
}

inline const Font Font_For::knob_txt_edit(const float scale_factor) {
	return Font{ bold() }.withPointHeight(11.0f * scale_factor);
}

inline const Font Font_For::pulse_w_txt(const float scale_factor) {
	return Font{ bold() }.withPointHeight(9.0f * scale_factor);
}

inline const Font Font_For::seq_step(const float scale_factor) {
	return Font{ bold() }.withPointHeight(9.5f * scale_factor);
}

inline const Font Font_For::tip() {
	return Font{ bold() }.withPointHeight(12.0f);
}
