#include "G_LAYER_Pgm_Num_And_Name_P.h"

#include "C_ID_A.h"
#include "C_NAME_P.h"

using namespace LAYER;

Pgm_Num_And_Name::Pgm_Num_And_Name(Data_Hub* hub) :
	Data_User{ hub },
	val_pgm_num{ app_p.get_param_as_value(ID::app_curr_pgm_num) },
	val_pgm_name{ app_p.get_param_as_value(ID::app_curr_pgm_name) },
	sli_pgm_num{ ID::app_curr_pgm_name, val_pgm_num, hub }
{
	setInterceptsMouseClicks(false, true);
	val_pgm_num.addListener(this);
	val_pgm_name.addListener(this);
	lbl_pgm_name.setName(NAME::lbl_led_pgm_name);
	lbl_pgm_name.setEditable(true);
}

void Pgm_Num_And_Name::resized()
{
}

void Pgm_Num_And_Name::valueChanged(Value& value)
{
}

Pgm_Num_And_Name::~Pgm_Num_And_Name() {
	val_pgm_name.removeListener(this);
	val_pgm_num.removeListener(this);
}
