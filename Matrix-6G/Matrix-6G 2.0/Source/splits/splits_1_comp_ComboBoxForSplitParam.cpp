#include "splits_1_comp_ComboBoxForSplitParam.h"

#include "splits_0_build_ChoiceName.h"
#include "../constants/constants_Splits.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_SplitParamDescription.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using ChoiceName = SplitParamChoiceName;
using Description = SplitParamDescription;
using VoiceAssignment = SplitZoneVoiceAssignment;

ComboBoxForSplitParameter::ComboBoxForSplitParameter(SplitParamComboBoxType comboBoxType, UnexposedParameters* unexposedParams) :
	comboBoxType{ comboBoxType },
	splitOptions{ unexposedParams->getSplitOptions() },
	tooltips{ unexposedParams->getTooltipsOptions() }
{
	StringArray choiceNamesList{};
	auto disabled{ false };
	auto enabled{ true };
	switch (comboBoxType)
	{
	case SplitParamComboBoxType::zoneVoiceAssignment:
		splitParamAsValue = splitOptions->getSplitParamAsValue(ID::split_ZoneVoiceAssignment);
		for (auto choiceNum = (int)VoiceAssignment::lower_2_Upper_4; choiceNum <= (int)VoiceAssignment::lower_0_Upper_6; ++choiceNum)
			choiceNamesList.add(ChoiceName::buildForZoneVoiceAssignment(VoiceAssignment{ choiceNum }, ChoiceNameType::concise));
		addItemList(choiceNamesList, 1);
		setSelectedItemIndex((int)splitOptions->zoneVoiceAssignment(), dontSendNotification);
		onChange = [this, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			splitOptions->setZoneVoiceAssignment(VoiceAssignment{ currentChoice });
		};
		break;
	case SplitParamComboBoxType::lowerZone_MIDI_IsEnabled:
		splitParamAsValue = splitOptions->getSplitParamAsValue(ID::split_LowerZone_MIDI_OutIsEnabled);
		choiceNamesList.add(ChoiceName::buildForZone_MIDI_OutIsEnabled(disabled, ChoiceNameType::concise));
		choiceNamesList.add(ChoiceName::buildForZone_MIDI_OutIsEnabled(enabled, ChoiceNameType::concise));
		addItemList(choiceNamesList, 1);
		setSelectedItemIndex((int)splitOptions->zone_MIDI_OutIsEnabled(SplitZone::lower), dontSendNotification);
		onChange = [this, unexposedParams, enabled, disabled] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeEnabled{ currentChoice == 1 };
			splitOptions->setZone_MIDI_OutIsEnabled(SplitZone::lower, shouldBeEnabled ? enabled : disabled);
		};
		break;
	case SplitParamComboBoxType::upperZone_MIDI_IsEnabled:
		splitParamAsValue = splitOptions->getSplitParamAsValue(ID::split_UpperZone_MIDI_OutIsEnabled);
		choiceNamesList.add(ChoiceName::buildForZone_MIDI_OutIsEnabled(disabled, ChoiceNameType::concise));
		choiceNamesList.add(ChoiceName::buildForZone_MIDI_OutIsEnabled(enabled, ChoiceNameType::concise));
		addItemList(choiceNamesList, 1);
		setSelectedItemIndex((int)splitOptions->zone_MIDI_OutIsEnabled(SplitZone::upper), dontSendNotification);
		onChange = [this, unexposedParams, enabled, disabled] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeEnabled{ currentChoice == 1 };
			splitOptions->setZone_MIDI_OutIsEnabled(SplitZone::upper, shouldBeEnabled ? enabled : disabled);
		};
		break;
	default:
		break;
	}

	splitParamAsValue.addListener(this);

	setSize(37, GUI::control_h);
}

void ComboBoxForSplitParameter::updateTooltip() {
	auto shouldShowDescription{ tooltips->shouldShowDescription() };
	auto shouldShowCurrentChoice{ tooltips->shouldShowCurrentChoice() };
	auto currentChoice{ getSelectedItemIndex() };
	String tip{ "" };
	switch (comboBoxType)
	{
	case SplitParamComboBoxType::zoneVoiceAssignment:
		if (shouldShowDescription)
			tip += Description::buildForZoneVoiceAssignment();
		if (shouldShowCurrentChoice) {
			tip += "Current setting: " + ChoiceName::buildForZoneVoiceAssignment(VoiceAssignment{ currentChoice }, ChoiceNameType::verbose);
		}
		break;
	case SplitParamComboBoxType::lowerZone_MIDI_IsEnabled:
		if (shouldShowDescription)
			tip += Description::buildForZone_MIDI_OutIsEnabled(SplitZone::lower);
		if (shouldShowCurrentChoice) {
			auto isEnabled{ currentChoice == 1 };
			tip += "Current setting: " + ChoiceName::buildForZone_MIDI_OutIsEnabled(isEnabled, ChoiceNameType::verbose);
		}
		break;
	case SplitParamComboBoxType::upperZone_MIDI_IsEnabled:
		if (shouldShowDescription)
			tip += Description::buildForZone_MIDI_OutIsEnabled(SplitZone::upper);
		if (shouldShowCurrentChoice) {
			auto isEnabled{ currentChoice == 1 };
			tip += "Current setting: " + ChoiceName::buildForZone_MIDI_OutIsEnabled(isEnabled, ChoiceNameType::verbose);
		}
		break;
	default:
		break;
	}
	setTooltip(tip);
}

void ComboBoxForSplitParameter::valueChanged(Value& value) {
	MessageManagerLock mmLock;
	if (value.refersToSameSourceAs(splitParamAsValue))
		setSelectedItemIndex((int)value.getValue());
	repaint();
	updateTooltip();
}

ComboBoxForSplitParameter::~ComboBoxForSplitParameter() {
	splitParamAsValue.removeListener(this);
}
