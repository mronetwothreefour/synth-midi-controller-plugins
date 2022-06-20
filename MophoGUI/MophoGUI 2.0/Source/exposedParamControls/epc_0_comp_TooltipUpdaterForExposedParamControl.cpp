#include "epc_0_comp_TooltipUpdaterForExposedParamControl.h"

#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



TooltipUpdaterForExposedParamControl::TooltipUpdaterForExposedParamControl(
    uint8 paramIndex, SettableTooltipClient& paramControl, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    paramIndex{ paramIndex },
    clientControl{ paramControl },
    exposedParams{ exposedParams },
    tooltips{ unexposedParams->getTooltipsOptions() }
{
    auto& info{ InfoForExposedParameters::get() };
    auto paramID{ info.IDfor(paramIndex) };
    auto paramaterPtr{ exposedParams->getParameter(paramID) };
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
    auto& info{ InfoForExposedParameters::get() };
    if (tooltips->shouldShowDescriptions())
        tip += info.descriptionFor(paramIndex) + "\n";
    if (tooltips->shouldShowCurrentValue()) {
        auto paramID{ info.IDfor(paramIndex) };
        auto paramaterPtr{ exposedParams->getParameter(paramID) };
        auto currentChoice{ roundToInt(paramaterPtr->convertFrom0to1(paramaterPtr->getValue())) };
        auto choiceName{ info.verboseChoiceNameFor((uint8)currentChoice, paramIndex) };
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

    auto& info{ InfoForExposedParameters::get() };
    auto paramID{ info.IDfor(paramIndex) };
    exposedParams->getParameter(paramID)->removeListener(this);
}
