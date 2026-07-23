#include "D_X_G_Data_Hub_P.h"

#include "D_TREE_Aux_Voice_P.h"

Data_Hub_P::Data_Hub_P(AudioProcessor* processor) :
	Data_Hub_G{ processor },
	aux_voice_params{ undo_mngr.get() }
{
}

Tree_Aux_Voice_P& Data_Hub_P::get_aux_voice_params() {
	return aux_voice_params;
}
