#include "EP _1_Exp_Param_Info.h"

#include "C_EP.h"
#include "C_ID.h"

using namespace EP;

Exposed_Parameter_Info::Exposed_Parameter_Info() :
	Exposed_Parameter_Info_Base{ EP::exp_param_count }
{
}

const Ctrl_Type Exposed_Parameter_Info::ctrl_type_for(const uint8 i) const {
	if (i < exp_param_count)
		return Ctrl_Type{ (int)param(i)[ID::param_ctrl_type] };
	return Ctrl_Type::dummy;
}

