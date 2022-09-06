#include "global_1_comp_DisplayLabelForGlobalParam.h"

#include "global_0_build_ChoiceName.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace MophoConstants;
using ChoiceName = GlobalParamChoiceName;
using Description = GlobalParamDescription;



DisplayLabelForGlobalParameter::DisplayLabelForGlobalParameter(GlobalParamDisplayLabelType labelType, UnexposedParameters* unexposedParams) :
	labelType{ labelType },
	global{ unexposedParams->getGlobalOptions() }
{
	label_GlobalParam.setComponentID(ID::label_DisplayLabel.toString());
	label_GlobalParam.setColour(Label::textColourId, GUI::color_Black);
	label_GlobalParam.setEditable(false, false);
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

	globalParamAsValue = global->getGobalParamAsValue(paramID);
	globalParamAsValue.addListener(this);

	auto tooltips{ unexposedParams->getTooltipsOptions() };
	shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
	shouldShowDescriptionAsValue.addListener(this);
	updateTooltip();

	setSize(245, GUI::comboBox_h);
	label_GlobalParam.setBounds(getLocalBounds());
	addAndMakeVisible(label_GlobalParam);
}

void DisplayLabelForGlobalParameter::setTextAccordingToParameterSetting() {
	auto textShouldBeRed{ (bool)false };
	switch (labelType)
	{
	case GlobalParamDisplayLabelType::paramChangeReceiveType: {
		if (global->hardwareIsNotSetToReceiveNRPNcontrollers())
			textShouldBeRed = true;
		auto receiveType{ global->paramChangeReceiveType() };
		label_GlobalParam.setText(ChoiceName::buildForParamChangeReceiveType(receiveType), dontSendNotification);
		break;
	}
	case GlobalParamDisplayLabelType::midiControllersStatus: {
		auto controllersAreEnabled{ global->controllersAreEnabled() };
		if (controllersAreEnabled == false)
			textShouldBeRed = true;
		label_GlobalParam.setText(ChoiceName::buildForMIDI_Controllers(controllersAreEnabled ? true : false), dontSendNotification);
		break;
	}
	case GlobalParamDisplayLabelType::sysExStatus: {
		auto sysExIsEnabled{ global->sysExIsEnabled() };
		if (sysExIsEnabled == false)
			textShouldBeRed = true;
		label_GlobalParam.setText(ChoiceName::buildForSysEx(sysExIsEnabled ? true : false), dontSendNotification);
		break;
	}
	case GlobalParamDisplayLabelType::audioOutput: {
		auto outputIsMono{ global->hardwareOutputIsMono() };
		label_GlobalParam.setText(ChoiceName::buildForAudioOutput(outputIsMono), dontSendNotification);
		break;
	}
	case GlobalParamDisplayLabelType::hardwareOutputBalance: {
		auto currentChoice{ (int)global->hardwareOutputBalance() };
		label_GlobalParam.setText(ChoiceName::buildForHardwareOutputBalance(currentChoice), dontSendNotification);
		break;
	}
	default:
		break;
	}
	setColour(label_GlobalParam.textColourId, textShouldBeRed ? GUI::color_ToggleOn : GUI::color_Black);
}

void DisplayLabelForGlobalParameter::updateTooltip() {
	auto shouldShowDescription{ (bool)shouldShowDescriptionAsValue.getValue() };
	String tip{ "" };
	switch (labelType)
	{
	case GlobalParamDisplayLabelType::paramChangeReceiveType:
		if (shouldShowDescription)
			tip += Description::buildForParamChangeReceiveType();
		break;
	case GlobalParamDisplayLabelType::midiControllersStatus:
		if (shouldShowDescription)
			tip += Description::buildForMIDI_ControllersStatus();
		break;
	case GlobalParamDisplayLabelType::sysExStatus:
		if (shouldShowDescription)
			tip += Description::buildForSysExStatus();
		break;
	case GlobalParamDisplayLabelType::audioOutput:
		if (shouldShowDescription)
			tip += Description::buildForAudioOutput();
		break;
	case GlobalParamDisplayLabelType::hardwareOutputBalance:
		if (shouldShowDescription)
			tip += Description::buildForHardwareOutputBalance();
		break;
	default:
		break;
	}
	label_GlobalParam.setTooltip(tip);
}

void DisplayLabelForGlobalParameter::valueChanged(Value& value) {
	if (value.refersToSameSourceAs(globalParamAsValue))
		setTextAccordingToParameterSetting();
	else
		updateTooltip();
}

DisplayLabelForGlobalParameter::~DisplayLabelForGlobalParameter() {
	globalParamAsValue.removeListener(this);
	shouldShowDescriptionAsValue.removeListener(this);
}
