#include "component_TooltipUpdaterForExposedParamControl.h"

#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace mophoConstants;



TooltipUpdaterForExposedParamControl::TooltipUpdaterForExposedParamControl(
    uint8 paramIndex, SettableTooltipClient& paramControl, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    paramIndex{ paramIndex },
    clientControl{ paramControl },
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams }
{
    auto& info{ InfoForExposedParameters::get() };
    auto paramID{ info.IDfor(paramIndex) };
    exposedParams->getParameter(paramID)->addListener(this);

    auto tooltipsOptions{ unexposedParams->getTooltipsOptions() };
    tooltipsOptions->addListener(this);
}

void TooltipUpdaterForExposedParamControl::setTooltip() {
    auto tooltipText{ generateTooltipText() };
    clientControl.setTooltip(tooltipText);
}

String TooltipUpdaterForExposedParamControl::generateTooltipText() {
    String tooltipText{ "" };
    auto tooltips{ unexposedParams->getTooltipsOptions() };
    auto& info{ InfoForExposedParameters::get() };
    if (tooltips->shouldShowDescriptions())
        tooltipText += info.descriptionFor(paramIndex) + "\n";
    if (tooltips->shouldShowCurrentValue()) {
        auto paramID{ info.IDfor(paramIndex) };
        auto paramaterPtr{ exposedParams->getParameter(paramID) };
        auto currentChoice{ roundToInt(paramaterPtr->convertFrom0to1(paramaterPtr->getValue())) };
        auto choiceName{ info.verboseChoiceNameFor(currentChoice, paramIndex) };
        tooltipText += "Current Setting: " + choiceName;
    }
    return tooltipText;
}

void TooltipUpdaterForExposedParamControl::parameterValueChanged(int changedParamIndex, float /*newValue*/) {
    if (changedParamIndex == paramIndex)
        setTooltip();
}

void TooltipUpdaterForExposedParamControl::parameterGestureChanged(int /*paramIndex*/, bool /*gestureIsStarting*/) {
}

void TooltipUpdaterForExposedParamControl::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
    if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription)
        setTooltip();
}

TooltipUpdaterForExposedParamControl::~TooltipUpdaterForExposedParamControl() {
    auto& info{ InfoForExposedParameters::get() };
    auto paramID{ info.IDfor(paramIndex) };
    exposedParams->getParameter(paramID)->removeListener(this);
}
