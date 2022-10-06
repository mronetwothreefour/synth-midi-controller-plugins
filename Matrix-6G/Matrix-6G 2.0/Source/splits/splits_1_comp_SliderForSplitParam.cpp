#include "splits_1_comp_SliderForSplitParam.h"

#include "splits_0_build_ChoiceName.h"
#include "../constants/constants_Splits.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_SplitParamDescription.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using ChoiceName = SplitParamChoiceName;
using Description = SplitParamDescription;

RotarySliderForSplitParameter::RotarySliderForSplitParameter(SliderType sliderType, UnexposedParameters* unexposedParams, UndoManager* undoManager) :
	RotarySliderWithMouseWheelMoveOverride{ undoManager },
	sliderType{ sliderType },
	splitOptions{ unexposedParams->getSplitOptions() },
	tooltips{ unexposedParams->getTooltipsOptions() },
	textEditor{ sliderType, unexposedParams }
{
	jassert(sliderType != SliderType::zoneVolumeBalance);

	auto slider_w{ 0 };
	auto lowerZone{ true };
	auto upperZone{ false };

	switch (sliderType)
	{
	case SliderType::zoneVolumeBalance:
		break;
	case SliderType::lowerZoneLimit:
		splitParamAsValue = splitOptions->getSplitParamAsValue(ID::split_LowerZoneLimit);
		setRange(0.0, 127.0, 1.0);
		setValue((double)splitOptions->lowerZoneLimit(), dontSendNotification);
		setMouseDragSensitivity(144);
		slider_w = GUI::splitZoneLimitSlider_w;
		break;
	case SliderType::lowerZoneVoiceNum:
		splitParamAsValue = splitOptions->getSplitParamAsValue(ID::split_LowerZoneVoiceNumber);
		setRange(0.0, 99.0, 1.0);
		setValue((double)splitOptions->lowerZoneVoiceNumber(), dontSendNotification);
		setMouseDragSensitivity(130);
		slider_w = GUI::splitZoneVoiceNumSlider_w;
		break;
	case SliderType::lowerZoneTranspose:
		splitParamAsValue = splitOptions->getSplitParamAsValue(ID::split_LowerZoneTranspose);
		setRange(0.0, 60.0, 1.0);
		setValue((double)splitOptions->lowerZoneTranspose(), dontSendNotification);
		setMouseDragSensitivity(110);
		slider_w = GUI::splitZoneTransposeSlider_w;
		break;
	case SliderType::upperZoneLimit:
		splitParamAsValue = splitOptions->getSplitParamAsValue(ID::split_UpperZoneLimit);
		setRange(0.0, 127.0, 1.0);
		setValue((double)splitOptions->upperZoneLimit(), dontSendNotification);
		setMouseDragSensitivity(144);
		slider_w = GUI::splitZoneLimitSlider_w;
		break;
	case SliderType::upperZoneVoiceNum:
		splitParamAsValue = splitOptions->getSplitParamAsValue(ID::split_UpperZoneVoiceNumber);
		setRange(0.0, 99.0, 1.0);
		setValue((double)splitOptions->upperZoneVoiceNumber(), dontSendNotification);
		setMouseDragSensitivity(130);
		slider_w = GUI::splitZoneVoiceNumSlider_w;
		break;
	case SliderType::upperZoneTranspose:
		splitParamAsValue = splitOptions->getSplitParamAsValue(ID::split_UpperZoneTranspose);
		setRange(0.0, 60.0, 1.0);
		setValue((double)splitOptions->upperZoneTranspose(), dontSendNotification);
		setMouseDragSensitivity(110);
		slider_w = GUI::splitZoneTransposeSlider_w;
		break;
	default:
		break;
	}

	splitParamAsValue.addListener(this);

	textEditor.setTopLeftPosition(0, 0);
	addAndMakeVisible(textEditor);

	updateTooltip();

	setSize(slider_w, GUI::control_h);
}

void RotarySliderForSplitParameter::updateTooltip() {
	auto shouldShowDescription{ tooltips->shouldShowDescription() };
	auto shouldShowCurrentChoice{ tooltips->shouldShowCurrentChoice() };
	auto currentChoice{ roundToInt(getValue()) };
	auto lowerZone{ true };
	auto upperZone{ false };
	auto verbose{ true };
	String tip{ "" };
	switch (sliderType)
	{
	case SliderType::zoneVolumeBalance:
		break;
	case SliderType::lowerZoneLimit:
		if (shouldShowDescription)
			tip += Description::buildForZoneLimit(lowerZone);
		if (shouldShowCurrentChoice)
			tip += "Current setting: " + ChoiceName::buildForZoneLimit(currentChoice, verbose);
		break;
	case SliderType::lowerZoneVoiceNum:
		if (shouldShowDescription)
			tip += Description::buildForZoneVoiceNum(lowerZone);
		if (shouldShowCurrentChoice)
			tip += "Current setting: Patch " + String(currentChoice).paddedLeft('0', 2);
		break;
	case SliderType::lowerZoneTranspose:
		if (shouldShowDescription)
			tip += Description::buildForZoneTranspose(lowerZone);
		if (shouldShowCurrentChoice)
			tip += "Current setting: " + ChoiceName::buildForZoneTranspose(currentChoice, verbose);
		break;
	case SliderType::upperZoneLimit:
		if (shouldShowDescription)
			tip += Description::buildForZoneLimit(upperZone);
		if (shouldShowCurrentChoice)
			tip += "Current setting: " + ChoiceName::buildForZoneLimit(currentChoice, verbose);
		break;
	case SliderType::upperZoneVoiceNum:
		if (shouldShowDescription)
			tip += Description::buildForZoneVoiceNum(upperZone);
		if (shouldShowCurrentChoice)
			tip += "Current setting: Patch " + String(currentChoice).paddedLeft('0', 2);
		break;
	case SliderType::upperZoneTranspose:
		if (shouldShowDescription)
			tip += Description::buildForZoneTranspose(upperZone);
		if (shouldShowCurrentChoice)
			tip += "Current setting: " + ChoiceName::buildForZoneTranspose(currentChoice, verbose);
		break;
	default:
		break;
	}
}

void RotarySliderForSplitParameter::mouseDoubleClick(const MouseEvent& /*event*/) {
	textEditor.showEditor();
}

void RotarySliderForSplitParameter::valueChanged() {
	auto currentChoice{ (uint8)roundToInt(getValue()) };
	switch (sliderType)
	{
	case SliderType::zoneVolumeBalance:
		break;
	case SliderType::lowerZoneLimit:
		splitOptions->setLowerZoneLimit(currentChoice);
		break;
	case SliderType::lowerZoneVoiceNum:
		splitOptions->setLowerZoneVoiceNumber(currentChoice);
		break;
	case SliderType::lowerZoneTranspose:
		splitOptions->setLowerZoneTranspose(currentChoice);
		break;
	case SliderType::upperZoneLimit:
		splitOptions->setUpperZoneLimit(currentChoice);
		break;
	case SliderType::upperZoneVoiceNum:
		splitOptions->setUpperZoneVoiceNumber(currentChoice);
		break;
	case SliderType::upperZoneTranspose:
		splitOptions->setUpperZoneTranspose(currentChoice);
		break;
	default:
		break;
	}
}

void RotarySliderForSplitParameter::valueChanged(Value& value) {
	MessageManagerLock mmLock;
	if (value.refersToSameSourceAs(splitParamAsValue))
		setValue((double)value.getValue(), sendNotification);
	updateTooltip();
}

RotarySliderForSplitParameter::~RotarySliderForSplitParameter() {
	splitParamAsValue.removeListener(this);
}




LinearSliderForSplitZoneVolumeBalance::LinearSliderForSplitZoneVolumeBalance(UnexposedParameters* unexposedParams, UndoManager* undoManager) :
	LinearSliderWithMouseWheelMoveOverride{ undoManager },
	splitOptions{ unexposedParams->getSplitOptions() },
	tooltips{ unexposedParams->getTooltipsOptions() },
	textEditor{ SliderType::zoneVolumeBalance, unexposedParams }
{
	splitZoneVolumeBalanceAsValue = splitOptions->getSplitParamAsValue(ID::split_ZoneVolumeBalance);
	splitZoneVolumeBalanceAsValue.addListener(this);

	setRange(0.0, 62.0, 1.0);
	setValue((double)splitOptions->zoneVolumeBalance(), dontSendNotification);
	setMouseDragSensitivity(112);

	textEditor.setTopLeftPosition(0, 0);
	addAndMakeVisible(textEditor);

	updateTooltip();

	setSize(GUI::splitVolumeBalanceSlider_w, GUI::control_h);
}

void LinearSliderForSplitZoneVolumeBalance::updateTooltip()
{
	auto currentChoice{ roundToInt(getValue()) };
	auto verbose{ true };
	String tip{ "" };
	if (tooltips->shouldShowDescription())
		tip += Description::buildForZoneVolumeBalance();
	if (tooltips->shouldShowCurrentChoice())
		tip += "Current setting: " + String(currentChoice > 31 ? "+" : "") + String(currentChoice - 31);
}

void LinearSliderForSplitZoneVolumeBalance::mouseDoubleClick(const MouseEvent& /*event*/) {
	textEditor.showEditor();
}

void LinearSliderForSplitZoneVolumeBalance::valueChanged() {
	auto currentChoice{ (uint8)roundToInt(getValue()) };
	splitOptions->setZoneVolumeBalance(currentChoice);
}

void LinearSliderForSplitZoneVolumeBalance::valueChanged(Value& value) {
	MessageManagerLock mmLock;
	setValue((double)value.getValue(), sendNotification);
	updateTooltip();
}

LinearSliderForSplitZoneVolumeBalance::~LinearSliderForSplitZoneVolumeBalance() {
	splitZoneVolumeBalanceAsValue.removeListener(this);
}
