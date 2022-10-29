#include "global_1_comp_SliderForGlobalParam.h"

#include "global_0_build_ChoiceName.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../gui/gui_build_LED_Path.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using ChoiceName = GlobalParamChoiceName;
using Description = GlobalParamDescription;

SliderForGlobalParameter::SliderForGlobalParameter(GlobalParamSliderType sliderType, UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMoveOverride{ nullptr },
	sliderType{ sliderType },
	global{ unexposedParams->getGlobalOptions() },
	textEditor{ sliderType, unexposedParams },
	unexposedParams{ unexposedParams }
{
	slider_w = GUI::global_MIDI_Control_w;
	setRange(0.0, 121.0, 1.0);
	setMouseDragSensitivity(140);
	switch (sliderType)
	{
	case GlobalParamSliderType::basicChannel:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_BasicChannel);
		setRange(1.0, 16.0, 1.0);
		setValue((double)global->basicChannel(), dontSendNotification);
		setMouseDragSensitivity(90);
		break;
	case GlobalParamSliderType::pedal_1_ControllerNum:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_Pedal_1_ControllerNumber);
		setValue((double)global->pedal_1_ControllerNumber(), dontSendNotification);
		break;
	case GlobalParamSliderType::pedal_2_ControllerNum:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_Pedal_2_ControllerNumber);
		setValue((double)global->pedal_2_ControllerNumber(), dontSendNotification);
		break;
	case GlobalParamSliderType::lever_2_ControllerNum:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_Lever_2_ControllerNumber);
		setValue((double)global->lever_2_ControllerNumber(), dontSendNotification);
		break;
	case GlobalParamSliderType::lever_3_ControllerNum:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_Lever_3_ControllerNumber);
		setValue((double)global->lever_3_ControllerNumber(), dontSendNotification);
		break;
	case GlobalParamSliderType::vibratoSpeed:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VibratoSpeed);
		setRange(0.0, 63.0, 1.0);
		setValue((double)global->vibratoSpeed(), dontSendNotification);
		setMouseDragSensitivity(110);
		slider_w = GUI::global_VibratoControl_w;
		break;
	case GlobalParamSliderType::vibratoAmplitude:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VibratoAmplitude);
		setRange(0.0, 63.0, 1.0);
		setValue((double)global->vibratoAmplitude(), dontSendNotification);
		setMouseDragSensitivity(110);
		slider_w = GUI::global_VibratoControl_w;
		break;
	case GlobalParamSliderType::vibratoSpeedModAmount:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VibratoSpeedModAmount);
		setRange(0.0, 63.0, 1.0);
		setValue((double)global->vibratoSpeedModAmount(), dontSendNotification);
		setMouseDragSensitivity(110);
		slider_w = GUI::global_VibratoControl_w;
		break;
	case GlobalParamSliderType::vibratoAmpModAmount:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VibratoAmpModAmount);
		setRange(0.0, 63.0, 1.0);
		setValue((double)global->vibratoAmpModAmount(), dontSendNotification);
		setMouseDragSensitivity(110);
		slider_w = GUI::global_VibratoControl_w;
		break;
	case GlobalParamSliderType::globalTune:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_Tune);
		setRange(0.0, 126.0, 1.0);
		setValue((double)global->globalTune(), dontSendNotification);
		setMouseDragSensitivity(143);
		slider_w = GUI::global_MiscControl_w;
		break;
	case GlobalParamSliderType::displayBrightness:
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
		case GlobalParamSliderType::basicChannel:
			tip += Description::buildForBasicChannel();
			break;
		case GlobalParamSliderType::pedal_1_ControllerNum:
			tip += Description::buildForControllerNumForPedal(1);
			break;
		case GlobalParamSliderType::pedal_2_ControllerNum:
			tip += Description::buildForControllerNumForPedal(2);
			break;
		case GlobalParamSliderType::lever_2_ControllerNum:
			tip += Description::buildForControllerNumForLever_2();
			break;
		case GlobalParamSliderType::lever_3_ControllerNum:
			tip += Description::buildForControllerNumForLever_3();
			break;
		case GlobalParamSliderType::vibratoSpeed:
			tip += Description::buildForVibratoSpeed();
			break;
		case GlobalParamSliderType::vibratoAmplitude:
			tip += Description::buildForVibratoAmplitude();
			break;
		case GlobalParamSliderType::vibratoSpeedModAmount:
			tip += Description::buildForVibratoModAmount(true);
			break;
		case GlobalParamSliderType::vibratoAmpModAmount:
			tip += Description::buildForVibratoModAmount(false);
			break;
		case GlobalParamSliderType::globalTune:
			tip += Description::buildForGlobalTune();
			break;
		case GlobalParamSliderType::displayBrightness:
			tip += Description::buildForDisplayBrightness();
			break;
		default:
			break;
		}
	}
	if (shouldShowCurrentChoice) {
		tip += "Current setting: ";
		auto currentChoice{ (int)getValue() };
		if (sliderType == GlobalParamSliderType::globalTune) {
			currentChoice -= EP::offsetForSigned_7_BitRange;
			if (currentChoice > 0)
				tip += "+";
		}
		tip += (String)currentChoice;
	}
	setTooltip(tip);
}

void SliderForGlobalParameter::paint(Graphics& g) {
	g.setColour(GUI::color_LED_Blue);
	auto currentChoice{ roundToInt(getValue()) };
	String choiceNameString{ "" };
	if (sliderType == GlobalParamSliderType::globalTune) {
		currentChoice -= EP::offsetForSigned_7_BitRange;
		if (currentChoice > 0)
			choiceNameString += "+";
		choiceNameString += (String)currentChoice;
	}
	else
		choiceNameString += (String)currentChoice;
	auto choiceNamePath{ LED_Path::buildLabelText(choiceNameString, slider_w) };
	g.fillPath(choiceNamePath);
}

void SliderForGlobalParameter::mouseDoubleClick(const MouseEvent& /*event*/) {
	textEditor.showEditor();
}

void SliderForGlobalParameter::valueChanged() {
	auto currentChoice{ (uint8)roundToInt(getValue()) };
	switch (sliderType)
	{
	case GlobalParamSliderType::basicChannel:
		global->setBasicChannel(currentChoice);
		break;
	case GlobalParamSliderType::pedal_1_ControllerNum:
		global->setPedal_1_ControllerNumber(currentChoice);
		break;
	case GlobalParamSliderType::pedal_2_ControllerNum:
		global->setPedal_2_ControllerNumber(currentChoice);
		break;
	case GlobalParamSliderType::lever_2_ControllerNum:
		global->setLever_2_ControllerNumber(currentChoice);
		break;
	case GlobalParamSliderType::lever_3_ControllerNum:
		global->setLever_3_ControllerNumber(currentChoice);
		break;
	case GlobalParamSliderType::vibratoSpeed:
		global->setVibratoSpeed(currentChoice);
		break;
	case GlobalParamSliderType::vibratoAmplitude:
		global->setVibratoAmplitude(currentChoice);
		break;
	case GlobalParamSliderType::vibratoSpeedModAmount:
		global->setVibratoSpeedModAmount(currentChoice);
		break;
	case GlobalParamSliderType::vibratoAmpModAmount:
		global->setVibratoAmpModAmount(currentChoice);
		break;
	case GlobalParamSliderType::globalTune:
		global->setGlobalTune(currentChoice);
		break;
	case GlobalParamSliderType::displayBrightness:
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
