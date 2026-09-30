#include "G_DRAW_Images_A.h"

Image DRAW::Images_A::load_from_jpg_data(const unsigned char* data, const size_t data_size) {
	MemoryInputStream img_stream{ data, data_size, false };
	JPEGImageFormat img_format;
	return img_format.decodeImage(img_stream);
}
