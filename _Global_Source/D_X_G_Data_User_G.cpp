#include "D_X_G_Data_User_G.h"

Data_User_G::Data_User_G(Data_Hub_P* hub) :
	hub{ hub },
	exp_info{ hub->get_exposed_info() },
	u_m{ hub->get_undo_mngr() },
	exp_state{ hub->get_exposed_state() },
	scale_factor{ hub->get_scale_factor() }
{}
