#include "D_BUILD_Init_Bounds_For_A.h"

#include "C_XYWH_P.h"

using namespace XYWH;

const Rectangle<int> BUILD::Init_Bounds_For_A::gui_editor() {
	return Rectangle<int>{ 0, 0, editor_init_w, editor_init_h };
}
