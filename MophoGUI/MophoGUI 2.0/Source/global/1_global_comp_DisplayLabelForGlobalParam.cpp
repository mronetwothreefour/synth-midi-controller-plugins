#include "1_global_comp_DisplayLabelForGlobalParam.h"

#include "0_global_build_ChoiceName.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;
using ChoiceName = GlobalParamChoiceName;
using Description = GlobalParamDescription;



DisplayLabelForGlobalParameter::DisplayLabelForGlobalParameter(GlobalParamDisplayLabelType labelType, UnexposedParameters* unexposedParams) :
	labelType{ labelType },
	unexposedParams{ unexposedParams }
{
	auto globalOptions{ unexposedParams->getGlobalOptions() };
	globalOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	tooltipOptions->addListener(this);
	
	setComponentID(ID::label_DisplayLabel.toString());
	setEditable(false, false);
	setTextAccordingToParameterSetting();

	switch (labelType)
	{
	case GlobalParamDisplayLabelType::paramChangeReceiveType:
		paramID = ID::global_ParamChangeReceiveType;
		break;
	case GlobalParamDisplayLabelType::midiControllersStatus:
		paramID = ID::global_ControllersAreEnabled;
		break;
	case GlobalParamDisplayLabelType::sysExStatus:
		paramID = ID::global_SysExIsEnabled;
		break;
	case GlobalParamDisplayLabelType::audioOutput:
		paramID = ID::global_HardwareOutputIsMono;
		break;
	case GlobalParamDisplayLabelType::hardwareOutputBalance:
		paramID = ID::global_HardwareOutputBalance;
		break;
	default:
		break;
	}

	updateTooltip();

	setSize(245, GUI::comboBox_h);
}

void DisplayLabelForGlobalParameter::setTextAccordingToParameterSetting() {
	auto globalOptions{ unexposedParams->getGlobalOptions() };
	auto textShouldBeRed{ (bool)false };
	switch (labelType)
	{
	case GlobalParamDisplayLabelType::paramChangeReceiveType: {
		if (globalOptions->hardwareIsNotSetToReceiveNRPNcontrollers())
			textShouldBeRed = true;
		auto receiveType{ globalOptions->paramChangeReceiveType() };
		setText(ChoiceName::buildFor_ParamChangeReceiveType(receiveType), dontSendNotification);
		break;
	}
	case GlobalParamDisplayLabelType::midiControllersStatus: {
		auto controllersAreEnabled{ globalOptions->controllersAreEnabled() };
		if (controllersAreEnabled == false)
			textShouldBeRed = true;
		setText(ChoiceName::buildFor_MIDI_Controllers(controllersAreEnabled ? true : false), dontSendNotification);
		break;
	}
	case GlobalParamDisplayLabelType::sysExStatus: {
		auto sysExIsEnabled{ globalOptions->sysExIsEnabled() };
		if (sysExIsEnabled == false)
			textShouldBeRed = true;
		setText(ChoiceName::buildFor_SysEx(sysExIsEnabled ? true : false), dontSendNotification);
		break;
	}
	case GlobalParamDisplayLabelType::audioOutput: {
		auto outputIsMono{ globalOptions->hardwareOutputIsMono() };
		setText(ChoiceName::buildFor_AudioOutput(outputIsMono), dontSendNotification);
		break;
	}
	case GlobalParamDisplayLabelType::hardwareOutputBalance: {
		auto currentChoice{ (int)globalOptions->hardwareOutputBalance() };
		setText(ChoiceName::buildFor_HardwareOutputBalance(currentChoice), dontSendNotification);
		break;
	}
	default:
		break;
	}
	setColour(textColourId, textShouldBeRed ? GUI::color_ToggleOn : GUI::color_Black);
}

void DisplayLabelForGlobalParameter::updateTooltip() {
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescription{ tooltipOptions->shouldShowDescriptions() };
	String tipString{ "" };
	switch (labelType)
	{
	case GlobalParamDisplayLabelType::paramChangeReceiveType:
		if (shouldShowDescription)
			tipString += Description::buildFor_ParamChangeReceiveType();
		break;
	case GlobalParamDisplayLabelType::midiControllersStatus:
		if (shouldShowDescription)
			tipString += Description::buildFor_MIDI_ControllersStatus();
		break;
	case GlobalParamDisplayLabelType::sysExStatus:
		if (shouldShowDescription)
			tipString += Description::buildFor_SysExStatus();
		break;
	case GlobalParamDisplayLabelType::audioOutput:
		if (shouldShowDescription)
			tipString += Description::buildFor_AudioOutput();
		break;
	case GlobalParamDisplayLabelType::hardwareOutputBalance:
		if (shouldShowDescription)
			tipString += Description::buildFor_HardwareOutputBalance();
		break;
	default:
		break;
	}
	setTooltip(tipString);
}

void DisplayLabelForGlobalParameter::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == paramID)
		setTextAccordingToParameterSetting();
	if (property == ID::tooltips_ShowDescription)
		updateTooltip();
}

DisplayLabelForGlobalParameter::~DisplayLabelForGlobalParameter() {
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	tooltipOptions->removeListener(this);
	auto globalOptions{ unexposedParams->getGlobalOptions() };
	globalOptions->removeListener(this);
}
