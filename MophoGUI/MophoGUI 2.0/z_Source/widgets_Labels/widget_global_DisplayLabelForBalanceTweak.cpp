#include "widget_global_DisplayLabelForBalanceTweak.h"

#include "../gui/gui_Constants.h"
#include "../gui/gui_Colors.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



DisplayLabelForBalanceTweak::DisplayLabelForBalanceTweak(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::global_Balance }
{
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setComponentID(ID::component_DisplayLabel.toString());
	setColour(textColourId, Color::black);
	setEditable(false, false);
	setTextAccordingToParameterSetting();
	setTooltip(generateTooltipString());
}

void DisplayLabelForBalanceTweak::setTextAccordingToParameterSetting() {
	auto globalOptions{ unexposedParams->globalOptions_get() };
	auto paramValue{ globalOptions->globalBalance() };
	setText(IntToBalanceTweakString::get()->verboseConvert(paramValue), dontSendNotification);
}

String DisplayLabelForBalanceTweak::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		tooltipText += "Applies a small adjustment to the balance of the hardware" + GUI::apostrophe + "s\n";
		tooltipText += "audio output jacks. This option cannot be changed remotely\n";
		tooltipText += "and must be set within the hardware" + GUI::apostrophe + "s Global Parameters menus.\n";
		tooltipText += "(This option was added in Mopho firmware version 1.4)";
	}
	return tooltipText;
}

void DisplayLabelForBalanceTweak::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setTextAccordingToParameterSetting();
	}
	if (property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

DisplayLabelForBalanceTweak::~DisplayLabelForBalanceTweak() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->removeListener(this);
}
