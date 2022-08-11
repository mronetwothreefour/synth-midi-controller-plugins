#pragma once

#include <JuceHeader.h>

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace P_600_G_Constants;

namespace P_600_G_Constants
{
	namespace GUI
	{
		const Colour color_Black{ 0xff000000 };
		const Colour color_KnobGray{ 0xff171717 };
		const Colour color_LED_Red{ 0xffed1c24 };
		const Colour color_LED_RedUnlit{ 0xff460000 };
		const Colour color_OffWhite{ 0xffaeaeae };
		const Colour color_ProgressBarGray{ 0xff333333 };
	}
}
