#include "G_LAYER_Pgm_Num_P.h"

#include "C_GET_P.h"
#include "C_ID_A.h"

using namespace LAYER;
using namespace WIDGET;

Pgm_Num::Pgm_Num(Data_Hub* hub) :
	Data_User{ hub },
	val_pgm_num{ app_p.get_param_as_value(ID::app_curr_pgm_num) },
	sli_pgm_num{ ID::app_curr_pgm_num, val_pgm_num, hub },
	init_bounds_pgm_num{ GET::init_bounds_for(ID::app_curr_pgm_num) }
{
	setInterceptsMouseClicks(false, true);
	addAndMakeVisible(sli_pgm_num);
}

void Pgm_Num::resized() {
	sli_pgm_num.setBounds(init_bounds_pgm_num.transformedBy(AffineTransform::scale(scale_f)));
}
