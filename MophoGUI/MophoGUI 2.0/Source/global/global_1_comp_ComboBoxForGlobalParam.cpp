#include "global_1_comp_ComboBoxForGlobalParam.h"

#include "global_0_build_ChoiceName.h"
#include "../constants/constants_GlobalParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../midi/midi_1_ParameterChangeMessage.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using ChoiceName = GlobalParamChoiceName;
using Description = GlobalParamDescription;
using ParamChange = ParameterChangeMessage;

ComboBoxForGlobalParameter::ComboBoxForGlobalParameter(ComboBoxType comboBoxType, UnexposedParameters* unexposedParams) :
	comboBoxType{ comboBoxType }
{
	auto global{ unexposedParams->getGlobalOptions() };

	StringArray choiceNamesList{};
	switch (comboBoxType)
	{
	case ComboBoxType::midiClockSource:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_MIDI_ClockSource);
		for (auto choiceNum = (int)MIDI_ClockSource::internalClock; choiceNum <= (int)MIDI_ClockSource::externalClock_Resend; ++choiceNum)
			choiceNamesList.add(ChoiceName::buildForMIDI_ClockSource(MIDI_ClockSource{ choiceNum }, ChoiceNameType::concise));
		addItemList(choiceNamesList, 1);
		setSelectedItemIndex((int)global->midiClockSource(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			global->setMIDI_ClockSource(MIDI_ClockSource{ currentChoice });
			ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling((uint8)currentChoice, GP::nrpnType_MIDI_ClockSource, unexposedParams);
		};
		break;
	case ComboBoxType::pedalMode:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_PedalModeIsArpLatch);
		choiceNamesList.add(ChoiceName::buildForPedalMode(false));
		choiceNamesList.add(ChoiceName::buildForPedalMode(true));
		addItemList(choiceNamesList, 1);
		setSelectedItemIndex((int)global->pedalModeIsArpLatch(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeArpLatch{ currentChoice == 1 };
			global->setPedalModeIsArpLatch(shouldBeArpLatch ? true : false);
			ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling((uint8)currentChoice, GP::nrpnType_PedalMode, unexposedParams);
		};
		break;
	case ComboBoxType::voiceChanges: {
			auto disabled{ false };
			auto enabled{ true };
			globalParamAsValue = global->getGobalParamAsValue(ID::global_VoiceChangesAreEnabled);
			choiceNamesList.add(ChoiceName::buildForVoiceChanges(disabled));
			choiceNamesList.add(ChoiceName::buildForVoiceChanges(enabled));
			addItemList(choiceNamesList, 1);
			setSelectedItemIndex((int)global->voiceChangesAreEnabled(), dontSendNotification);
			onChange = [this, global, unexposedParams, enabled, disabled] {
				auto currentChoice{ getSelectedItemIndex() };
				auto shouldBeEnabled{ currentChoice == 1 };
				global->setVoiceChangesAreEnabled(shouldBeEnabled ? enabled : disabled);
				ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling((uint8)currentChoice, GP::nrpnType_VoiceChanges, unexposedParams);
			};
		}
		break;
	case ComboBoxType::paramChangeSendType:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_ParamChangeSendType);
		for (auto choiceNum = 0; choiceNum != 3; ++choiceNum)
			choiceNamesList.add(ChoiceName::buildForParamChangeSendType(ParamChangeSendType{ choiceNum }));
		addItemList(choiceNamesList, 1);
		setSelectedItemIndex((int)global->paramChangeSendType(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			global->setParamChangeSendType(ParamChangeSendType{ currentChoice });
			ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling((uint8)currentChoice, GP::nrpnType_ParamChangeSendType, unexposedParams);
		};
		break;
	default:
		break;
	}

	globalParamAsValue.addListener(this);

	auto tooltips{ unexposedParams->getTooltipsOptions() };
	shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
	shouldShowDescriptionAsValue.addListener(this);
	shouldShowCurrentChoiceAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowCurrentChoice);
	shouldShowCurrentChoiceAsValue.addListener(this);
	updateTooltip();

	setSize(117, GUI::comboBox_h);
}

void ComboBoxForGlobalParameter::updateTooltip() {
	auto shouldShowDescription{ (bool)shouldShowDescriptionAsValue.getValue() };
	auto shouldShowCurrentChoice{ (bool)shouldShowCurrentChoiceAsValue.getValue() };
	auto currentChoice{ getSelectedItemIndex() };
	String tip{ "" };
	switch (comboBoxType)
	{
	case ComboBoxType::midiClockSource:
		if (shouldShowDescription)
			tip += Description::buildForMIDI_ClockSource();
		if (shouldShowCurrentChoice)
			tip += "Current setting: " + ChoiceName::buildForMIDI_ClockSource(MIDI_ClockSource{ currentChoice }, ChoiceNameType::verbose);
		break;
	case ComboBoxType::pedalMode:
		if (shouldShowDescription)
			tip += Description::buildForPedalMode();
		if (shouldShowCurrentChoice) {
			auto isArpLatch{ currentChoice == 1 };
			tip += "Current setting: " + ChoiceName::buildForPedalMode(isArpLatch);
		}
		break;
	case ComboBoxType::voiceChanges:
		if (shouldShowDescription)
			tip += Description::buildForVoiceChanges();
		if (shouldShowCurrentChoice) {
			auto areEnabled{ currentChoice == 1 };
			tip += "Current setting: " + ChoiceName::buildForVoiceChanges(areEnabled);
		}
		break;
	case ComboBoxType::paramChangeSendType:
		if (shouldShowDescription)
			tip += Description::buildForParamChangeSendType();
		if (shouldShowCurrentChoice)
			tip += "Current setting: " + ChoiceName::buildForParamChangeSendType(ParamChangeSendType{ currentChoice });
		break;
	default:
		tip += "Invalid Parameter";
		break;
	}
	setTooltip(tip);
}

void ComboBoxForGlobalParameter::valueChanged(Value& value) {
	MessageManagerLock mmLock;
	if (value.refersToSameSourceAs(globalParamAsValue))
		setSelectedItemIndex((int)value.getValue());
	updateTooltip();
}

ComboBoxForGlobalParameter::~ComboBoxForGlobalParameter() {
	globalParamAsValue.removeListener(this);
	shouldShowDescriptionAsValue.removeListener(this);
	shouldShowCurrentChoiceAsValue.removeListener(this);
}
