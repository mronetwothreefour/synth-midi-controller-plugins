#include "1_global_comp_ComboBoxForGlobalParam.h"

#include "0_global_build_ChoiceName.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_GlobalParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../midi/1_midi_ParameterChangeMessage.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;
using ChoiceName = GlobalParamChoiceName;
using Description = GlobalParamDescription;
using ParamChange = ParameterChangeMessage;



ComboBoxForGlobalParameter::ComboBoxForGlobalParameter(GlobalParamComboBoxType comboBoxType, UnexposedParameters* unexposedParams) :
	comboBoxType{ comboBoxType },
	unexposedParams{ unexposedParams }
{
	auto globalOptions{ unexposedParams->getGlobalOptions() };
	globalOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	tooltipOptions->addListener(this);

	StringArray choiceNamesList{};
	auto concise{ (bool)false };
	switch (comboBoxType)
	{
	case GlobalParamComboBoxType::midiClockSource:
		paramID = ID::global_MIDI_ClockSource;
		for (auto choiceNum = 0; choiceNum != 4; ++choiceNum)
			choiceNamesList.add(ChoiceName::buildFor_MIDI_ClockSource(MIDI_ClockSource{ choiceNum }, concise));
		addItemList(choiceNamesList, 1);
		setSelectedItemIndex((int)globalOptions->midiClockSource(), dontSendNotification);
		onChange = [this, globalOptions, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			globalOptions->setMIDI_ClockSource(MIDI_ClockSource{ currentChoice });
			ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling((uint8)currentChoice, GP::nrpnType_MIDI_ClockSource, unexposedParams);
		};
		break;
	case GlobalParamComboBoxType::pedalMode:
		paramID = ID::global_PedalModeIsArpLatch;
		choiceNamesList.add(ChoiceName::buildFor_PedalMode(false));
		choiceNamesList.add(ChoiceName::buildFor_PedalMode(true));
		addItemList(choiceNamesList, 1);
		setSelectedItemIndex((int)globalOptions->pedalModeIsArpLatch(), dontSendNotification);
		onChange = [this, globalOptions, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			if (currentChoice == 0)
				globalOptions->setPedalModeToNormal();
			else
				globalOptions->setPedalModeToArpLatch();
			ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling((uint8)currentChoice, GP::nrpnType_PedalMode, unexposedParams);
		};
		break;
	case GlobalParamComboBoxType::voiceChange:
		paramID = ID::global_VoiceChangeIsEnabled;
		choiceNamesList.add(ChoiceName::buildFor_VoiceChange(false));
		choiceNamesList.add(ChoiceName::buildFor_VoiceChange(true));
		addItemList(choiceNamesList, 1);
		setSelectedItemIndex((int)globalOptions->voiceChangeIsEnabled(), dontSendNotification);
		onChange = [this, globalOptions, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			if (currentChoice == 0)
				globalOptions->setVoiceChangeDisabled();
			else
				globalOptions->setVoiceChangeEnabled();
			ParamChange::sendNewValueForNRPNtypeToUnexposedParamsForHandling((uint8)currentChoice, GP::nrpnType_PedalMode, unexposedParams);
		};
		break;
	case GlobalParamComboBoxType::paramChangeSendType:
		paramID = ID::global_ParamChangeSendType;
		for (auto choiceNum = 0; choiceNum != 3; ++choiceNum)
			choiceNamesList.add(ChoiceName::buildFor_ParamChangeSendType(ParamChangeSendType{ choiceNum }));
		addItemList(choiceNamesList, 1);
		setSelectedItemIndex((int)globalOptions->paramChangeSendType(), dontSendNotification);
		onChange = [this, globalOptions, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			globalOptions->setParamChangeSendType(ParamChangeSendType{ currentChoice });
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
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescription{ tooltipOptions->shouldShowDescriptions() };
	auto shouldShowCurrentChoice{ tooltipOptions->shouldShowCurrentValue() };
	auto verbose{ (bool)true };
	String tipString{ "" };
	auto globalOptions{ unexposedParams->getGlobalOptions() };
	switch (comboBoxType)
	{
	case GlobalParamComboBoxType::midiClockSource:
		if (shouldShowDescription)
			tipString += Description::buildFor_MIDI_ClockSource();
		if (shouldShowCurrentChoice) {
			auto currentChoice{ globalOptions->midiClockSource() };
			tipString += "Current setting: " + ChoiceName::buildFor_MIDI_ClockSource(currentChoice, verbose);
		}
		break;
	case GlobalParamComboBoxType::pedalMode:
		if (shouldShowDescription)
			tipString += Description::buildFor_PedalMode();
		if (shouldShowCurrentChoice) {
			auto isArpLatch{ globalOptions->pedalModeIsArpLatch() };
			tipString += "Current setting: " + ChoiceName::buildFor_PedalMode(isArpLatch);
		}
		break;
	case GlobalParamComboBoxType::voiceChange:
		if (shouldShowDescription)
			tipString += Description::buildFor_VoiceChange();
		if (shouldShowCurrentChoice) {
			auto currentChoice{ getSelectedItemIndex() };
			tipString += "Current setting: " + ChoiceName::buildFor_VoiceChange(currentChoice);
		}
		break;
	case GlobalParamComboBoxType::paramChangeSendType:
		if (shouldShowDescription)
			tipString += Description::buildFor_ParamChangeSendType();
		if (shouldShowCurrentChoice) {
			auto currentChoice{ globalOptions->paramChangeSendType() };
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
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		MessageManagerLock mmLock;
		updateTooltip();
	}
}

ComboBoxForGlobalParameter::~ComboBoxForGlobalParameter() {
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	tooltipOptions->removeListener(this);
	auto globalOptions{ unexposedParams->getGlobalOptions() };
	globalOptions->removeListener(this);
}
