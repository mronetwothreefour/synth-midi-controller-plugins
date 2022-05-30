#include "1_global_comp_ToggleForTooltipParam.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;
using Description = GlobalParamDescription;



ToggleForTooltipParam::ToggleForTooltipParam(GlobalParamToggleType toggleType, UnexposedParameters* unexposedParams) :
	toggleType{ toggleType },
	unexposedParams{ unexposedParams }
{
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	tooltipOptions->addListener(this);

	setComponentID(ID::component_ParamToggle.toString());
	switch (toggleType)
	{
	case GlobalParamToggleType::currentValueTooltip:
		setToggleState(tooltipOptions->shouldShowCurrentValue(), dontSendNotification);
		break;
	case GlobalParamToggleType::descriptionTooltip:
		setToggleState(tooltipOptions->shouldShowDescriptions(), dontSendNotification);
		break;
	default:
		break;
	}

	updateTooltip();

	setSize(GUI::toggle_diameter, GUI::toggle_diameter);
}

void ToggleForTooltipParam::updateTooltip() {
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescription{ tooltipOptions->shouldShowDescriptions() };
	String tipString{ "" };
	switch (toggleType)
	{
	case GlobalParamToggleType::currentValueTooltip:
		tipString += (shouldShowDescription ? Description::buildFor_CurrentValueTooltip() : "");
		break;
	case GlobalParamToggleType::descriptionTooltip:
		tipString += (shouldShowDescription ? Description::buildFor_DescriptionTooltip() : "");
		break;
	default:
		break;
	}
	setTooltip(tipString);
}

void ToggleForTooltipParam::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == ID::tooltips_ShouldShowDescription) {
		MessageManagerLock mmLock;
		updateTooltip();
	}
}

ToggleForTooltipParam::~ToggleForTooltipParam() {
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	tooltipOptions->removeListener(this);
}
