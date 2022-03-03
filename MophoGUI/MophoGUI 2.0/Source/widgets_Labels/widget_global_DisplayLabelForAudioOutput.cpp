#include "widget_global_DisplayLabelForAudioOutput.h"

#include "../gui/gui_Constants.h"
#include "../gui/gui_Colors.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



DisplayLabelForAudioOutput::DisplayLabelForAudioOutput(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::global_HardwareOutputIsStereo }
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

void DisplayLabelForAudioOutput::setTextAccordingToParameterSetting() {
	auto globalOptions{ unexposedParams->globalOptions_get() };
	auto paramValue{ (uint8)globalOptions->hardwareOutputIsStereo() };
	setText(IntToMonoStereoString::get()->verboseConvert(paramValue), dontSendNotification);
}

String DisplayLabelForAudioOutput::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		tooltipText += "Selects whether the hardware should output audio in mono\n";
		tooltipText += "or in stereo. This option cannot be changed remotely and\n";
		tooltipText += "must be set within the hardware" + GUI::apostrophe + "s Global Parameters menus.";
	}
	return tooltipText;
}

void DisplayLabelForAudioOutput::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setTextAccordingToParameterSetting();
	}
	if (property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

DisplayLabelForAudioOutput::~DisplayLabelForAudioOutput() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->removeListener(this);
}
