#include "D_BUILD_Font_For_P.h"

using namespace BinaryData;
using namespace BUILD;

const FontOptions Font_For::bold() {
	return Typeface::createSystemTypefaceFor(OverpassBold_ttf, OverpassBold_ttfSize);
}

inline const Font Font_For::file_browser(const float scale_factor) {
	return Font{ bold() }.withPointHeight(14.0f * scale_factor);
}

inline const Font Font_For::knob(const float scale_factor) {
	return Font{ bold() }.withPointHeight(10.0f * scale_factor);
}

inline const Font Font_For::knob_txt_edit(const float scale_factor) {
	return Font{ bold() }.withPointHeight(10.0f * scale_factor);
}

inline const Font Font_For::tip() {
	return Font{ bold() }.withPointHeight(12.0f);
}
