#include "D_X_G_Data_Hub_P.h"

Data_Hub_P::Data_Hub_P(AudioProcessor* processor) :
	Data_Hub_G{ processor }/*,
	additional_voice_params{ undo_mngr.get() }*/
{
}

//Tree_Aux_Voice_P& Data_Hub_P::get_additional_voice_params() {
//	return additional_voice_params;
//}
