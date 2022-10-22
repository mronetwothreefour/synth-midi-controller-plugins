#include "global_1_comp_SliderForGlobalParam.h"

#include "global_0_build_ChoiceName.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using ChoiceName = GlobalParamChoiceName;
using Description = GlobalParamDescription;

SliderForGlobalParameter::SliderForGlobalParameter(SliderType sliderType, UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMoveOverride{ nullptr },
	sliderType{ sliderType },
	global{ unexposedParams->getGlobalOptions() },
	textEditor{ sliderType, unexposedParams },
	unexposedParams{ unexposedParams }
{
	auto slider_w{ GUI::global_MIDI_Control_w };
	setRange(0.0, 121.0, 1.0);
	setMouseDragSensitivity(140);
	switch (sliderType)
	{
	case SliderType::basicChannel:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_BasicChannel);
		setRange(1.0, 16.0, 1.0);
		setValue((double)global->basicChannel(), dontSendNotification);
		setMouseDragSensitivity(90);
		break;
	case SliderType::pedal_1_ControllerNum:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_Pedal_1_ControllerNumber);
		setValue((double)global->pedal_1_ControllerNumber(), dontSendNotification);
		break;
	case SliderType::pedal_2_ControllerNum:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_Pedal_2_ControllerNumber);
		setValue((double)global->pedal_2_ControllerNumber(), dontSendNotification);
		break;
	case SliderType::lever_2_ControllerNum:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_Lever_2_ControllerNumber);
		setValue((double)global->lever_2_ControllerNumber(), dontSendNotification);
		break;
	case SliderType::lever_3_ControllerNum:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_Lever_3_ControllerNumber);
		setValue((double)global->lever_3_ControllerNumber(), dontSendNotification);
		break;
	case SliderType::vibratoSpeed:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VibratoSpeed);
		setRange(0.0, 63.0, 1.0);
		setValue((double)global->vibratoSpeed(), dontSendNotification);
		setMouseDragSensitivity(110);
		slider_w = GUI::global_VibratoControl_w;
		break;
	case SliderType::vibratoAmplitude:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VibratoAmplitude);
		setRange(0.0, 63.0, 1.0);
		setValue((double)global->vibratoAmplitude(), dontSendNotification);
		setMouseDragSensitivity(110);
		slider_w = GUI::global_VibratoControl_w;
		break;
	case SliderType::vibratoSpeedModAmount:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VibratoSpeedModAmount);
		setRange(0.0, 63.0, 1.0);
		setValue((double)global->vibratoSpeedModAmount(), dontSendNotification);
		setMouseDragSensitivity(110);
		slider_w = GUI::global_VibratoControl_w;
		break;
	case SliderType::vibratoAmpModAmount:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VibratoAmpModAmount);
		setRange(0.0, 63.0, 1.0);
		setValue((double)global->vibratoAmpModAmount(), dontSendNotification);
		setMouseDragSensitivity(110);
		slider_w = GUI::global_VibratoControl_w;
		break;
	case SliderType::globalTune:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_Tune);
		setRange(0.0, 126.0, 1.0);
		setValue((double)global->globalTune(), dontSendNotification);
		setMouseDragSensitivity(143);
		slider_w = GUI::global_MiscControl_w;
		break;
	case SliderType::displayBrightness:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_DisplayBrightness);
		setRange(1.0, 31.0, 1.0);
		setValue((double)global->displayBrightness(), dontSendNotification);
		setMouseDragSensitivity(95);
		slider_w = GUI::global_MiscControl_w;
		break;
	default:
		break;
	}

	textEditor.setTopLeftPosition(0, 0);
	addAndMakeVisible(textEditor);

	globalParamAsValue.addListener(this);

	auto tooltips{ unexposedParams->getTooltipsOptions() };
	shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
	shouldShowDescriptionAsValue.addListener(this);
	shouldShowCurrentChoiceAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowCurrentChoice);
	shouldShowCurrentChoiceAsValue.addListener(this);
	updateTooltip();

	setSize(slider_w, GUI::control_h);
}

void SliderForGlobalParameter::updateTooltip() {
	auto shouldShowDescription{ (bool)shouldShowDescriptionAsValue.getValue() };
	auto shouldShowCurrentChoice{ (bool)shouldShowCurrentChoiceAsValue.getValue() };
	String tip{ "" };
	if (shouldShowDescription) {
		switch (sliderType)
		{
		case SliderType::basicChannel:
			tip += Description::buildForBasicChannel();
			break;
		case SliderType::pedal_1_ControllerNum:
			tip += Description::buildForControllerNumForPedal(1);
			break;
		case SliderType::pedal_2_ControllerNum:
			tip += Description::buildForControllerNumForPedal(2);
			break;
		case SliderType::lever_2_ControllerNum:
			tip += Description::buildForControllerNumForLever_2();
			break;
		case SliderType::lever_3_ControllerNum:
			tip += Description::buildForControllerNumForLever_3();
			break;
		case SliderType::vibratoSpeed:
			tip += Description::buildForVibratoSpeed();
			break;
		case SliderType::vibratoAmplitude:
			tip += Description::buildForVibratoAmplitude();
			break;
		case SliderType::vibratoSpeedModAmount:
			tip += Description::buildForVibratoModAmount(true);
			break;
		case SliderType::vibratoAmpModAmount:
			tip += Description::buildForVibratoModAmount(false);
			break;
		case SliderType::globalTune:
			tip += Description::buildForGlobalTune();
			break;
		case SliderType::displayBrightness:
			tip += Description::buildForDisplayBrightness();
			break;
		default:
			break;
		}
		if (shouldShowCurrentChoice) {
			tip += "Current setting: ";
			auto currentChoice{ (int)getValue() };
			if (sliderType == SliderType::globalTune) {
				currentChoice -= EP::offsetForSigned_7_BitRange;
				if (currentChoice > 0)
					tip += "+";
			}
			tip += (String)currentChoice;
		}
	}
}

void SliderForGlobalParameter::mouseDoubleClick(const MouseEvent& /*event*/) {
	textEditor.showEditor();
}

void SliderForGlobalParameter::valueChanged() {
	auto currentChoice{ (uint8)roundToInt(getValue()) };
	switch (sliderType)
	{
	case SliderType::basicChannel:
		global->setBasicChannel(currentChoice);
		break;
	case SliderType::pedal_1_ControllerNum:
		global->setPedal_1_ControllerNumber(currentChoice);
		break;
	case SliderType::pedal_2_ControllerNum:
		global->setPedal_2_ControllerNumber(currentChoice);
		break;
	case SliderType::lever_2_ControllerNum:
		global->setLever_2_ControllerNumber(currentChoice);
		break;
	case SliderType::lever_3_ControllerNum:
		global->setLever_3_ControllerNumber(currentChoice);
		break;
	case SliderType::vibratoSpeed:
		global->setVibratoSpeed(currentChoice);
		break;
	case SliderType::vibratoAmplitude:
		global->setVibratoAmplitude(currentChoice);
		break;
	case SliderType::vibratoSpeedModAmount:
		global->setVibratoSpeedModAmount(currentChoice);
		break;
	case SliderType::vibratoAmpModAmount:
		global->setVibratoAmpModAmount(currentChoice);
		break;
	case SliderType::globalTune:
		global->setGlobalTune(currentChoice);
		break;
	case SliderType::displayBrightness:
		global->setDisplayBrightness(currentChoice);
		break;
	default:
		break;
	}
}

void SliderForGlobalParameter::valueChanged(Value& value) {
	MessageManagerLock mmLock;
	if (value.refersToSameSourceAs(globalParamAsValue))
		setValue((double)value.getValue(), sendNotification);
	updateTooltip();
}

SliderForGlobalParameter::~SliderForGlobalParameter() {
	globalParamAsValue.removeListener(this);
	shouldShowDescriptionAsValue.removeListener(this);
	shouldShowCurrentChoiceAsValue.removeListener(this);
}
