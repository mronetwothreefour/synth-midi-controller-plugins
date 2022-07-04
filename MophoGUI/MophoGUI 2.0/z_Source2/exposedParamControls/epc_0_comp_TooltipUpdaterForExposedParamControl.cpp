#include "epc_0_comp_TooltipUpdaterForExposedParamControl.h"

#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_facade_ExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



TooltipUpdaterForExposedParamControl::TooltipUpdaterForExposedParamControl(
    uint8 paramIndex, SettableTooltipClient& paramControl, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    paramIndex{ paramIndex },
    clientControl{ paramControl },
    exposedParams{ exposedParams },
    tooltips{ unexposedParams->getTooltipsOptions() }
{
    auto paramID{ exposedParams->info.IDfor(paramIndex) };
    auto paramaterPtr{ exposedParams->state.getParameter(paramID) };
    paramaterPtr->addListener(this);

    auto tooltipsOptions{ unexposedParams->getTooltipsOptions() };
    tooltipsOptions->addListener(this);

    parameterValueChanged(paramIndex, paramaterPtr->getValue());
}

void TooltipUpdaterForExposedParamControl::setTooltip() {
    auto tooltipText{ generateTooltipText() };
    clientControl.setTooltip(tooltipText);
}

String TooltipUpdaterForExposedParamControl::generateTooltipText() {
    String tip{ "" };
    if (tooltips->shouldShowDescriptions())
        tip += exposedParams->info.descriptionFor(paramIndex) + "\n";
    if (tooltips->shouldShowCurrentValue()) {
        auto paramID{ exposedParams->info.IDfor(paramIndex) };
        auto paramaterPtr{ exposedParams->state.getParameter(paramID) };
        auto currentChoice{ roundToInt(paramaterPtr->convertFrom0to1(paramaterPtr->getValue())) };
        auto choiceName{ exposedParams->info.verboseChoiceNameFor((uint8)currentChoice, paramIndex) };
        tip += "Current Setting: " + choiceName;
    }
    return tip;
}

void TooltipUpdaterForExposedParamControl::parameterValueChanged(int changedParamIndex, float /*newValue*/) {
    if (changedParamIndex == paramIndex)
        setTooltip();
}

void TooltipUpdaterForExposedParamControl::parameterGestureChanged(int /*paramIndex*/, bool /*gestureIsStarting*/) {
}

void TooltipUpdaterForExposedParamControl::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
    if (property == ID::tooltips_ShowCurrentValue || property == ID::tooltips_ShowDescription)
        setTooltip();
}

TooltipUpdaterForExposedParamControl::~TooltipUpdaterForExposedParamControl() {
    tooltips->removeListener(this);

    auto paramID{ exposedParams->info.IDfor(paramIndex) };
    exposedParams->state.getParameter(paramID)->removeListener(this);
}
