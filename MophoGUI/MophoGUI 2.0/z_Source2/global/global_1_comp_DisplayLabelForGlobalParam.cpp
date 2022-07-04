#include "global_1_comp_DisplayLabelForGlobalParam.h"

#include "global_0_build_ChoiceName.h"
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
	global{ unexposedParams->getGlobalOptions() },
	tooltips{ unexposedParams->getTooltipsOptions() }
{
	global->addListener(this);
	tooltips->addListener(this);
	
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
	auto textShouldBeRed{ (bool)false };
	switch (labelType)
	{
	case GlobalParamDisplayLabelType::paramChangeReceiveType: {
		if (global->hardwareIsNotSetToReceiveNRPNcontrollers())
			textShouldBeRed = true;
		auto receiveType{ global->paramChangeReceiveType() };
		setText(ChoiceName::buildFor_ParamChangeReceiveType(receiveType), dontSendNotification);
		break;
	}
	case GlobalParamDisplayLabelType::midiControllersStatus: {
		auto controllersAreEnabled{ global->controllersAreEnabled() };
		if (controllersAreEnabled == false)
			textShouldBeRed = true;
		setText(ChoiceName::buildFor_MIDI_Controllers(controllersAreEnabled ? true : false), dontSendNotification);
		break;
	}
	case GlobalParamDisplayLabelType::sysExStatus: {
		auto sysExIsEnabled{ global->sysExIsEnabled() };
		if (sysExIsEnabled == false)
			textShouldBeRed = true;
		setText(ChoiceName::buildFor_SysEx(sysExIsEnabled ? true : false), dontSendNotification);
		break;
	}
	case GlobalParamDisplayLabelType::audioOutput: {
		auto outputIsMono{ global->hardwareOutputIsMono() };
		setText(ChoiceName::buildFor_AudioOutput(outputIsMono), dontSendNotification);
		break;
	}
	case GlobalParamDisplayLabelType::hardwareOutputBalance: {
		auto currentChoice{ (int)global->hardwareOutputBalance() };
		setText(ChoiceName::buildFor_HardwareOutputBalance(currentChoice), dontSendNotification);
		break;
	}
	default:
		break;
	}
	setColour(textColourId, textShouldBeRed ? GUI::color_ToggleOn : GUI::color_Black);
}

void DisplayLabelForGlobalParameter::updateTooltip() {
	auto shouldShowDescription{ tooltips->shouldShowDescriptions() };
	String tip{ "" };
	switch (labelType)
	{
	case GlobalParamDisplayLabelType::paramChangeReceiveType:
		if (shouldShowDescription)
			tip += Description::buildFor_ParamChangeReceiveType();
		break;
	case GlobalParamDisplayLabelType::midiControllersStatus:
		if (shouldShowDescription)
			tip += Description::buildFor_MIDI_ControllersStatus();
		break;
	case GlobalParamDisplayLabelType::sysExStatus:
		if (shouldShowDescription)
			tip += Description::buildFor_SysExStatus();
		break;
	case GlobalParamDisplayLabelType::audioOutput:
		if (shouldShowDescription)
			tip += Description::buildFor_AudioOutput();
		break;
	case GlobalParamDisplayLabelType::hardwareOutputBalance:
		if (shouldShowDescription)
			tip += Description::buildFor_HardwareOutputBalance();
		break;
	default:
		break;
	}
	setTooltip(tip);
}

void DisplayLabelForGlobalParameter::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == paramID)
		setTextAccordingToParameterSetting();
	if (property == ID::tooltips_ShowDescription)
		updateTooltip();
}

DisplayLabelForGlobalParameter::~DisplayLabelForGlobalParameter() {
	tooltips->removeListener(this);
	global->removeListener(this);
}
