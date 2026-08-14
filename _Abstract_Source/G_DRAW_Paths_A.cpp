#include "G_DRAW_Paths_A.h"

Path DRAW::Paths_A::load_path(const void* data, size_t data_size) {
	Path path;
	path.loadPathFromData(data, data_size);
	return path;
}
