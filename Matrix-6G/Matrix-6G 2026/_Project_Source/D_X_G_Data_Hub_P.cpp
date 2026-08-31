#include "D_X_G_Data_Hub_P.h"

Data_Hub::Data_Hub(AudioProcessor* processor) :
	Data_Hub_A{ processor },
	matrix_mod_params{ undo_mngr.get() }
{
}

Matrix_Mod_Params& Data_Hub::get_matrix_mod_params() {
	return matrix_mod_params;
}
