#include "global_1_comp_ComboBoxForGlobalParam.h"

#include "global_0_build_ChoiceName.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_GlobalParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../midi/midi_1_ParameterChangeMessage.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;
using ChoiceName = GlobalParamChoiceName;
using Description = GlobalParamDescription;
using ParamChange = ParameterChangeMessage;



ComboBoxForGlobalParameter::ComboBoxForGlobalParameter(GlobalParamComboBoxType comboBoxType, UnexposedParameters* unexposedParams) :
	comboBoxType{ comboBoxType },
	global{ unexposedParams->getGlobalOptions() },
	tooltips{ unexposedParams->getTooltipsOptions() }
{
	global->addListener(this);
	tooltips->addListener(this);

	StringArray choiceNamesList{};
	auto concise{ (bool)false };
	switch (comboBoxType)
	{
	case GlobalParamComboBoxType::midiClockSource:
		paramID = ID::global_MIDI_ClockSource;
		for (auto choiceNum = 0; choiceNum != 4; ++choiceNum)
			choiceNamesList.add(ChoiceName::buildFor_MIDI_ClockSource(MIDI_ClockSource{ choiceNum }, concise));
		addItemList(choiceNamesList, 1);
		setSelectedItemIndex((int)global->midiClockSource(), dontSendNotification);
		onChange = [this, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			global->setMIDI_ClockSource(MIDI_ClockSource{ currentChoice });
			ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling((uint8)currentChoice, GP::nrpnType_MIDI_ClockSource, unexposedParams);
		};
		break;
	case GlobalParamComboBoxType::pedalMode:
		paramID = ID::global_PedalModeIsArpLatch;
		choiceNamesList.add(ChoiceName::buildFor_PedalMode(false));
		choiceNamesList.add(ChoiceName::buildFor_PedalMode(true));
		addItemList(choiceNamesList, 1);
		setSelectedItemIndex((int)global->pedalModeIsArpLatch(), dontSendNotification);
		onChange = [this, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeArpLatch{ currentChoice == 1 };
			global->setPedalModeIsArpLatch(shouldBeArpLatch ? true : false);
			ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling((uint8)currentChoice, GP::nrpnType_PedalMode, unexposedParams);
		};
		break;
	case GlobalParamComboBoxType::voiceChanges:
		paramID = ID::global_VoiceChangesAreEnabled;
		choiceNamesList.add(ChoiceName::buildFor_VoiceChanges(false));
		choiceNamesList.add(ChoiceName::buildFor_VoiceChanges(true));
		addItemList(choiceNamesList, 1);
		setSelectedItemIndex((int)global->voiceChangesAreEnabled(), dontSendNotification);
		onChange = [this, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeEnabled{ currentChoice == 1 };
			global->setVoiceChangesAreEnabled(shouldBeEnabled ? true : false);
			ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling((uint8)currentChoice, GP::nrpnType_VoiceChanges, unexposedParams);
		};
		break;
	case GlobalParamComboBoxType::paramChangeSendType:
		paramID = ID::global_ParamChangeSendType;
		for (auto choiceNum = 0; choiceNum != 3; ++choiceNum)
			choiceNamesList.add(ChoiceName::buildFor_ParamChangeSendType(ParamChangeSendType{ choiceNum }));
		addItemList(choiceNamesList, 1);
		setSelectedItemIndex((int)global->paramChangeSendType(), dontSendNotification);
		onChange = [this, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			global->setParamChangeSendType(ParamChangeSendType{ currentChoice });
			ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling((uint8)currentChoice, GP::nrpnType_ParamChangeSendType, unexposedParams);
		};
		break;
	default:
		break;
	}

	updateTooltip();

	setSize(117, GUI::comboBox_h);
}

void ComboBoxForGlobalParameter::updateTooltip() {
	auto shouldShowDescription{ tooltips->shouldShowDescriptions() };
	auto shouldShowCurrentChoice{ tooltips->shouldShowCurrentValue() };
	auto verbose{ (bool)true };
	String tipString{ "" };
	switch (comboBoxType)
	{
	case GlobalParamComboBoxType::midiClockSource:
		if (shouldShowDescription)
			tipString += Description::buildFor_MIDI_ClockSource();
		if (shouldShowCurrentChoice) {
			auto currentChoice{ global->midiClockSource() };
			tipString += "Current setting: " + ChoiceName::buildFor_MIDI_ClockSource(currentChoice, verbose);
		}
		break;
	case GlobalParamComboBoxType::pedalMode:
		if (shouldShowDescription)
			tipString += Description::buildFor_PedalMode();
		if (shouldShowCurrentChoice) {
			auto isArpLatch{ global->pedalModeIsArpLatch() };
			tipString += "Current setting: " + ChoiceName::buildFor_PedalMode(isArpLatch);
		}
		break;
	case GlobalParamComboBoxType::voiceChanges:
		if (shouldShowDescription)
			tipString += Description::buildFor_VoiceChanges();
		if (shouldShowCurrentChoice) {
			auto currentChoice{ getSelectedItemIndex() };
			tipString += "Current setting: " + ChoiceName::buildFor_VoiceChanges(currentChoice);
		}
		break;
	case GlobalParamComboBoxType::paramChangeSendType:
		if (shouldShowDescription)
			tipString += Description::buildFor_ParamChangeSendType();
		if (shouldShowCurrentChoice) {
			auto currentChoice{ global->paramChangeSendType() };
			tipString += "Current setting: " + ChoiceName::buildFor_ParamChangeSendType(currentChoice);
		}
		break;
	default:
		break;
	}
	setTooltip(tipString);
}

void ComboBoxForGlobalParameter::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == paramID) {
		MessageManagerLock mmLock;
		setSelectedItemIndex((int)tree.getProperty(property));
		updateTooltip();
	}
	if (property == ID::tooltips_ShowCurrentValue || property == ID::tooltips_ShowDescription) {
		MessageManagerLock mmLock;
		updateTooltip();
	}
}

ComboBoxForGlobalParameter::~ComboBoxForGlobalParameter() {
	tooltips->removeListener(this);
	global->removeListener(this);
}
