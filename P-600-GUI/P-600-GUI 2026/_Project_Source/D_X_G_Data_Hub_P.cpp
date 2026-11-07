#include "D_X_G_Data_Hub_P.h"

#include "C_RES_Backdrop_Main_P.h"
#include "G_DRAW_Images_A.h"

using namespace RES;

Data_Hub::Data_Hub(AudioProcessor* processor) :
	Data_Hub_A{ processor },
	img_texture{ Images_A::load_from_jpg_data(texture_jpg_data, texture_jpg_size) }
{}

const Image& Data_Hub::get_img_texture() { return img_texture; }
