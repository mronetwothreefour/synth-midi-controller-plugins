#include "D_X_G_Data_Hub_P.h"

Data_Hub::Data_Hub(AudioProcessor* processor) :
	Data_Hub_A{ processor },
	aux_voice_params{ undo_mngr.get() }
{
}

Aux_Voice_Params& Data_Hub::get_aux_voice_params() {
	return aux_voice_params;
}
