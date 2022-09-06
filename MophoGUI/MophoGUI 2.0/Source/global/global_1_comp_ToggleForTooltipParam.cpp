#include "global_1_comp_ToggleForTooltipParam.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace MophoConstants;
using Description = GlobalParamDescription;



ToggleForTooltipParameter::ToggleForTooltipParameter(GlobalParamToggleType toggleType, UnexposedParameters* unexposedParams) :
	toggleType{ toggleType }
{
	setInterceptsMouseClicks(true, false);
	redToggle.setComponentID(ID::comp_RedToggle.toString());
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	switch (toggleType)
	{
	case GlobalParamToggleType::currentChoiceTooltip:
		redToggle.setToggleState(tooltips->shouldShowCurrentChoice(), dontSendNotification);
		redToggle.onClick = [this, tooltips] { tooltips->setShouldShowCurrentChoice(redToggle.getToggleState()); };
		break;
	case GlobalParamToggleType::descriptionTooltip:
		redToggle.setToggleState(tooltips->shouldShowDescription(), dontSendNotification);
		redToggle.onClick = [this, tooltips] { tooltips->setShouldShowDescription(redToggle.getToggleState()); };
		break;
	default:
		break;
	}
	auto component_w{ toggleType == GlobalParamToggleType::currentChoiceTooltip ? 128 : 116 };
	redToggle.setSize(GUI::redToggle_diameter, GUI::redToggle_diameter);
	redToggle.setTopRightPosition(component_w, 0);
	addAndMakeVisible(redToggle);

	shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
	shouldShowDescriptionAsValue.addListener(this);
	updateTooltip();

	setSize(component_w, GUI::redToggle_diameter);
}

void ToggleForTooltipParameter::updateTooltip() {
	auto shouldShowDescription{ (bool)shouldShowDescriptionAsValue.getValue() };
	String tip{ "" };
	switch (toggleType)
	{
	case GlobalParamToggleType::currentChoiceTooltip:
		tip += (shouldShowDescription ? Description::buildForCurrentValueTooltip() : "");
		break;
	case GlobalParamToggleType::descriptionTooltip:
		tip += (shouldShowDescription ? Description::buildForDescriptionTooltip() : "");
		break;
	default:
		break;
	}
	redToggle.setTooltip(tip);
}

void ToggleForTooltipParameter::mouseDown(const MouseEvent& /*event*/) {
	redToggle.triggerClick();
}

void ToggleForTooltipParameter::valueChanged(Value& /*value*/) {
	MessageManagerLock mmLock;
	updateTooltip();
}

ToggleForTooltipParameter::~ToggleForTooltipParameter() {
	shouldShowDescriptionAsValue.removeListener(this);
}
