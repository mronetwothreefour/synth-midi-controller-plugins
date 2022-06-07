#include "1_global_comp_KnobForGlobalParam.h"

#include "0_global_build_ChoiceName.h"
#include "../constants/constants_GlobalParameters.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../midi/1_midi_ParameterChangeMessage.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using ChoiceName = GlobalParamChoiceName;
using Description = GlobalParamDescription;
using ParamChange = ParameterChangeMessage;



KnobForGlobalParameter::KnobForGlobalParameter(GlobalParamKnobType knobType, UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMoveOverride{ unexposedParams },
	knobType{ knobType },
	unexposedParams{ unexposedParams }
{
	auto globalOptions{ unexposedParams->getGlobalOptions() };
	globalOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	tooltipOptions->addListener(this);

	setComponentID(ID::component_Knob.toString());
	switch (knobType)
	{
	case GlobalParamKnobType::globalTranspose:
		paramID = ID::global_Transpose;
		setRange(0.0, 24.0, 1.0);
		setDoubleClickReturnValue(true, 12.0);
		setValue((double)globalOptions->globalTranspose(), dontSendNotification);
		setMouseDragSensitivity(90);
		break;
	case GlobalParamKnobType::globalFineTune:
		paramID = ID::global_FineTune;
		setRange(0.0, 100.0, 1.0);
		setDoubleClickReturnValue(true, 50.0);
		setValue((double)globalOptions->globalFineTune(), dontSendNotification);
		setMouseDragSensitivity(105);
		break;
	case GlobalParamKnobType::hardwareReceiveChannel:
		paramID = ID::global_HardwareReceiveChannel;
		setRange(0.0, 16.0, 1.0);
		setDoubleClickReturnValue(true, 0.0);
		setValue((double)globalOptions->hardwareReceiveChannel(), dontSendNotification);
		setMouseDragSensitivity(90);
		break;
	default:
		break;
	}

	updateTooltip();

	setSize(GUI::knob_diameter, GUI::knob_diameter);
}

void KnobForGlobalParameter::updateTooltip() {
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescription{ tooltipOptions->shouldShowDescriptions() };
	auto shouldShowCurrentChoice{ tooltipOptions->shouldShowCurrentValue() };
	auto currentChoice{ roundToInt(getValue()) };
	auto verbose{ (bool)true };
	String tipString{ "" };
	switch (knobType)
	{
	case GlobalParamKnobType::globalTranspose:
		if (shouldShowDescription)
			tipString += Description::buildFor_GlobalTranspose();
		if (shouldShowCurrentChoice)
			tipString += "Current setting: " + ChoiceName::buildFor_GlobalTranspose(currentChoice, verbose);
		break;
	case GlobalParamKnobType::globalFineTune:
		if (shouldShowDescription)
			tipString += Description::buildFor_GlobalFineTune();
		if (shouldShowCurrentChoice)
			tipString += "Current setting: " + ChoiceName::buildFor_GlobalFineTune(currentChoice, verbose);
		break;
	case GlobalParamKnobType::hardwareReceiveChannel:
		if (shouldShowDescription)
			tipString += Description::buildFor_HardwareReceiveChannel();
		if (shouldShowCurrentChoice)
			tipString += "Current setting: " + ChoiceName::buildFor_HardwareReceiveChannel(currentChoice, verbose);
		break;
	default:
		break;
	}
	setTooltip(tipString);
}

void KnobForGlobalParameter::valueChanged() {
	auto globalOptions{ unexposedParams->getGlobalOptions() };
	auto currentChoice{ (uint8)roundToInt(getValue()) };
	switch (knobType)
	{
	case GlobalParamKnobType::globalTranspose:
		globalOptions->setGlobalTranspose(currentChoice);
		ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling(currentChoice, GP::nrpnType_GlobalTranspose, unexposedParams);
		break;
	case GlobalParamKnobType::globalFineTune:
		globalOptions->setGlobalFineTune(currentChoice);
		ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling(currentChoice, GP::nrpnType_GlobalFineTune, unexposedParams);
		break;
	case GlobalParamKnobType::hardwareReceiveChannel:
		globalOptions->setHardwareReceiveChannel(currentChoice);
		ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling(currentChoice, GP::nrpnType_HardwareReceiveChannel, unexposedParams);
		if (currentChoice == 0)
			globalOptions->setTransmitChannel(currentChoice);
		else
			globalOptions->setTransmitChannel(currentChoice - 1);
		break;
	default:
		break;
	}
}

void KnobForGlobalParameter::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == paramID) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), sendNotification);
		updateTooltip();
	}
	if (property == ID::tooltips_ShowCurrentValue || property == ID::tooltips_ShowDescription)
		updateTooltip();
}

KnobForGlobalParameter::~KnobForGlobalParameter() {
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	tooltipOptions->removeListener(this);
	auto globalOptions{ unexposedParams->getGlobalOptions() };
	globalOptions->removeListener(this);
}
