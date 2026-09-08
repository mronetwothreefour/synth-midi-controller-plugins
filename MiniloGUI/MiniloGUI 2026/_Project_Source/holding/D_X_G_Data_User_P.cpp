#include "D_X_G_Data_User_P.h"

Data_User::Data_User(Data_Hub* hub) :
	Data_User_A{ hub },
	avp{ hub->get_aux_voice_params() }
{
}
