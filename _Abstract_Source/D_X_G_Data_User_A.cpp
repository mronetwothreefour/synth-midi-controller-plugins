#include "D_X_G_Data_User_A.h"

Data_User_A::Data_User_A(Data_Hub* hub) :
	hub{ hub },
	//app_options{ hub->get_app_options() },
	exp_state{ hub->get_exposed_params_state() },
	scale_factor{ hub->get_scale_factor() },
	u_m{ hub->get_undo_mngr() }
{}
