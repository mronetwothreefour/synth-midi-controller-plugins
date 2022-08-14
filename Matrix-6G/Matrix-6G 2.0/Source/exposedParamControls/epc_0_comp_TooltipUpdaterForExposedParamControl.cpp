#include "epc_0_comp_TooltipUpdaterForExposedParamControl.h"

#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

TooltipUpdaterForExposedParamControl::TooltipUpdaterForExposedParamControl(
    const uint8 paramIndex, SettableTooltipClient& clientComponent, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    paramIndex{ paramIndex },
    clientComponent{ clientComponent },
    state{ exposedParams->state.get() },
    info{ exposedParams->info.get() }
{
    auto paramID{ info->IDfor(paramIndex) };
    parameterValue = state->getParameterAsValue(paramID);
    parameterValue.addListener(this);

    shouldShowDescriptionValue = unexposedParams->getTooltipsOptions()->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
    shouldShowDescriptionValue.addListener(this);

    shouldShowCurrentChoiceValue = unexposedParams->getTooltipsOptions()->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowCurrentChoice);
    shouldShowCurrentChoiceValue.addListener(this);

    updateTooltip();
}

void TooltipUpdaterForExposedParamControl::updateTooltip() {
    auto tip{ generateTooltipText() };
    clientComponent.setTooltip(tip);
}

String TooltipUpdaterForExposedParamControl::generateTooltipText() {
    auto shouldShowDescription{ (bool)shouldShowDescriptionValue.getValue() };
    auto shouldShowCurrentChoice{ (bool)shouldShowCurrentChoiceValue.getValue() };
    String tip{ "" };
    if (shouldShowDescription)
        tip += info->descriptionFor(paramIndex) + "\n";
    if (shouldShowCurrentChoice) {
        auto paramID{ info->IDfor(paramIndex) };
        auto paramaterPtr{ state->getParameter(paramID) };
        auto currentChoice{ roundToInt(paramaterPtr->convertFrom0to1(paramaterPtr->getValue())) };
        auto choiceName{ info->verboseChoiceNameFor((uint8)currentChoice, paramIndex) };
        tip += "Current Setting: " + choiceName;
    }
    return tip;
}

void TooltipUpdaterForExposedParamControl::valueChanged(Value& /*value*/) {
    updateTooltip();
}

TooltipUpdaterForExposedParamControl::~TooltipUpdaterForExposedParamControl() {
    parameterValue.removeListener(this);
    shouldShowDescriptionValue.removeListener(this);
    shouldShowCurrentChoiceValue.removeListener(this);
}
