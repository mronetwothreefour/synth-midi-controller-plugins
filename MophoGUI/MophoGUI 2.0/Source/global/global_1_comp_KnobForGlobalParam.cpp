#include "global_1_comp_KnobForGlobalParam.h"

#include "global_0_build_ChoiceName.h"
#include "../constants/constants_GlobalParameters.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../midi/midi_1_ParameterChangeMessage.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using ChoiceName = GlobalParamChoiceName;
using Description = GlobalParamDescription;
using ParamChange = ParameterChangeMessage;



KnobForGlobalParameter::KnobForGlobalParameter(KnobType knobType, UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMoveOverride{ nullptr },
	knobType{ knobType },
	global{ unexposedParams->getGlobalOptions() },
	tooltips{ unexposedParams->getTooltipsOptions() },
	unexposedParams{ unexposedParams }
{
	global->addListener(this);
	tooltips->addListener(this);

	setComponentID(ID::component_Knob.toString());
	switch (knobType)
	{
	case KnobType::globalTranspose:
		paramID = ID::global_Transpose;
		setRange(0.0, 24.0, 1.0);
		setDoubleClickReturnValue(true, 12.0);
		setValue((double)global->globalTranspose(), dontSendNotification);
		setMouseDragSensitivity(90);
		break;
	case KnobType::globalFineTune:
		paramID = ID::global_FineTune;
		setRange(0.0, 100.0, 1.0);
		setDoubleClickReturnValue(true, 50.0);
		setValue((double)global->globalFineTune(), dontSendNotification);
		setMouseDragSensitivity(105);
		break;
	case KnobType::hardwareReceiveChannel:
		paramID = ID::global_HardwareReceiveChannel;
		setRange(0.0, 16.0, 1.0);
		setDoubleClickReturnValue(true, 0.0);
		setValue((double)global->hardwareReceiveChannel(), dontSendNotification);
		setMouseDragSensitivity(90);
		break;
	default:
		break;
	}

	updateTooltip();

	setSize(GUI::knob_diameter, GUI::knob_diameter);
}

void KnobForGlobalParameter::updateTooltip() {
	auto shouldShowDescription{ tooltips->shouldShowDescriptions() };
	auto shouldShowCurrentChoice{ tooltips->shouldShowCurrentValue() };
	auto currentChoice{ roundToInt(getValue()) };
	auto verbose{ (bool)true };
	String tip{ "" };
	switch (knobType)
	{
	case KnobType::globalTranspose:
		if (shouldShowDescription)
			tip += Description::buildFor_GlobalTranspose();
		if (shouldShowCurrentChoice)
			tip += "Current setting: " + ChoiceName::buildFor_GlobalTranspose(currentChoice, verbose);
		break;
	case KnobType::globalFineTune:
		if (shouldShowDescription)
			tip += Description::buildFor_GlobalFineTune();
		if (shouldShowCurrentChoice)
			tip += "Current setting: " + ChoiceName::buildFor_GlobalFineTune(currentChoice, verbose);
		break;
	case KnobType::hardwareReceiveChannel:
		if (shouldShowDescription)
			tip += Description::buildFor_HardwareReceiveChannel();
		if (shouldShowCurrentChoice)
			tip += "Current setting: " + ChoiceName::buildFor_HardwareReceiveChannel(currentChoice, verbose);
		break;
	default:
		break;
	}
	setTooltip(tip);
}

void KnobForGlobalParameter::valueChanged() {
	auto currentChoice{ (uint8)roundToInt(getValue()) };
	switch (knobType)
	{
	case KnobType::globalTranspose:
		global->setGlobalTranspose(currentChoice);
		ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling(currentChoice, GP::nrpnType_GlobalTranspose, unexposedParams);
		break;
	case KnobType::globalFineTune:
		global->setGlobalFineTune(currentChoice);
		ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling(currentChoice, GP::nrpnType_GlobalFineTune, unexposedParams);
		break;
	case KnobType::hardwareReceiveChannel:
		global->setHardwareReceiveChannel(currentChoice);
		ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling(currentChoice, GP::nrpnType_HardwareReceiveChannel, unexposedParams);
		if (currentChoice == 0)
			global->setTransmitChannel(currentChoice);
		else
			global->setTransmitChannel(currentChoice - 1);
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
	tooltips->removeListener(this);
	global->removeListener(this);
}
