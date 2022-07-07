#include "global_1_comp_ToggleForTooltipParam.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;
using Description = GlobalParamDescription;



ToggleForTooltipParameter::ToggleForTooltipParameter(GlobalParamToggleType toggleType, UnexposedParameters* unexposedParams) :
	toggleType{ toggleType },
	tooltips{ unexposedParams->getTooltipsOptions() }
{
	tooltips->addListener(this);

	setComponentID(ID::component_RedToggle.toString());
	switch (toggleType)
	{
	case GlobalParamToggleType::currentValueTooltip:
		setToggleState(tooltips->shouldShowCurrentValue(), dontSendNotification);
		onClick = [this] { tooltips->setShouldShowCurrentValue(getToggleState()); };
		break;
	case GlobalParamToggleType::descriptionTooltip:
		setToggleState(tooltips->shouldShowDescriptions(), dontSendNotification);
		onClick = [this] { tooltips->setShouldShowDescription(getToggleState()); };
		break;
	default:
		break;
	}

	updateTooltip();

	setSize(GUI::toggle_diameter, GUI::toggle_diameter);
}

void ToggleForTooltipParameter::updateTooltip() {
	auto shouldShowDescription{ tooltips->shouldShowDescriptions() };
	String tip{ "" };
	switch (toggleType)
	{
	case GlobalParamToggleType::currentValueTooltip:
		tip += (shouldShowDescription ? Description::buildFor_CurrentValueTooltip() : "");
		break;
	case GlobalParamToggleType::descriptionTooltip:
		tip += (shouldShowDescription ? Description::buildFor_DescriptionTooltip() : "");
		break;
	default:
		break;
	}
	setTooltip(tip);
}

void ToggleForTooltipParameter::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == ID::tooltips_ShowDescription) {
		MessageManagerLock mmLock;
		updateTooltip();
	}
}

ToggleForTooltipParameter::~ToggleForTooltipParameter() {
	tooltips->removeListener(this);
}
