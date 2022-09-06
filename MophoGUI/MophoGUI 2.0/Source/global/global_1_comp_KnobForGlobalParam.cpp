#include "global_1_comp_KnobForGlobalParam.h"

#include "global_0_build_ChoiceName.h"
#include "../constants/constants_GlobalParameters.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../midi/midi_1_ParameterChangeMessage.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using ChoiceName = GlobalParamChoiceName;
using Description = GlobalParamDescription;
using ParamChange = ParameterChangeMessage;

KnobForGlobalParameter::KnobForGlobalParameter(KnobType knobType, UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMoveOverride{ nullptr },
	knobType{ knobType },
	global{ unexposedParams->getGlobalOptions() },
	textEditor{ knobType, unexposedParams },
	unexposedParams{ unexposedParams }
{
	switch (knobType)
	{
	case KnobType::globalTranspose:
		paramID = ID::global_Transpose;
		setRange(0.0, 24.0, 1.0);
		setValue((double)global->globalTranspose(), dontSendNotification);
		setMouseDragSensitivity(90);
		break;
	case KnobType::globalFineTune:
		paramID = ID::global_FineTune;
		setRange(0.0, 100.0, 1.0);
		setValue((double)global->globalFineTune(), dontSendNotification);
		setMouseDragSensitivity(105);
		break;
	case KnobType::hardwareReceiveChannel:
		paramID = ID::global_HardwareReceiveChannel;
		setRange(0.0, 16.0, 1.0);
		setValue((double)global->hardwareReceiveChannel(), dontSendNotification);
		setMouseDragSensitivity(90);
		break;
	default:
		break;
	}

	textEditor.setTopLeftPosition(0, 0);
	addAndMakeVisible(textEditor);

	globalParamAsValue = global->getGobalParamAsValue(paramID);
	globalParamAsValue.addListener(this);

	auto tooltips{ unexposedParams->getTooltipsOptions() };
	shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
	shouldShowDescriptionAsValue.addListener(this);
	shouldShowCurrentChoiceAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowCurrentChoice);
	shouldShowCurrentChoiceAsValue.addListener(this);
	updateTooltip();

	setSize(GUI::knob_diameter, GUI::knob_diameter);
}

void KnobForGlobalParameter::updateTooltip() {
	auto shouldShowDescription{ (bool)shouldShowDescriptionAsValue.getValue() };
	auto shouldShowCurrentChoice{ (bool)shouldShowCurrentChoiceAsValue.getValue() };
	auto currentChoice{ roundToInt(getValue()) };
	auto verbose{ (bool)true };
	String tip{ "" };
	switch (knobType)
	{
	case KnobType::globalTranspose:
		if (shouldShowDescription)
			tip += Description::buildForGlobalTranspose();
		if (shouldShowCurrentChoice)
			tip += "Current setting: " + ChoiceName::buildForGlobalTranspose(currentChoice, verbose);
		break;
	case KnobType::globalFineTune:
		if (shouldShowDescription)
			tip += Description::buildForGlobalFineTune();
		if (shouldShowCurrentChoice)
			tip += "Current setting: " + ChoiceName::buildForGlobalFineTune(currentChoice, verbose);
		break;
	case KnobType::hardwareReceiveChannel:
		if (shouldShowDescription)
			tip += Description::buildForHardwareReceiveChannel();
		if (shouldShowCurrentChoice)
			tip += "Current setting: " + ChoiceName::buildForHardwareReceiveChannel(currentChoice, verbose);
		break;
	default:
		break;
	}
	setTooltip(tip);
}

void KnobForGlobalParameter::mouseDoubleClick(const MouseEvent& /*event*/) {
	textEditor.showEditor();
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

void KnobForGlobalParameter::valueChanged(Value& value) {
	MessageManagerLock mmLock;
	if (value.refersToSameSourceAs(globalParamAsValue))
		setValue((double)value.getValue(), sendNotification);
	updateTooltip();
}

KnobForGlobalParameter::~KnobForGlobalParameter() {
	globalParamAsValue.removeListener(this);
	shouldShowDescriptionAsValue.removeListener(this);
	shouldShowCurrentChoiceAsValue.removeListener(this);
}
