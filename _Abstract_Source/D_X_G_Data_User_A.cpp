#include "D_X_G_Data_User_A.h"

#include "C_ID_A.h"

Data_User_A::Data_User_A(Data_Hub* hub) :
	hub{ hub },
	app_p{ hub->get_app_params() },
	exp_state{ hub->get_exposed_params_state() },
	u_m{ hub->get_undo_mngr() }
{}

const float Data_User_A::scale_factor() {
	return app_p.scale_factor();
}
