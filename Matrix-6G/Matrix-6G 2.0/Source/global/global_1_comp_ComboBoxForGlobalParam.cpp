#include "global_1_comp_ComboBoxForGlobalParam.h"

#include "global_0_build_ChoiceName.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using ChoiceName = GlobalParamChoiceName;
using Description = GlobalParamDescription;

ComboBoxForGlobalParameter::ComboBoxForGlobalParameter(GlobalParamComboBoxType comboBoxType, UnexposedParameters* unexposedParams) :
	comboBoxType{ comboBoxType }
{
	auto global{ unexposedParams->getGlobalOptions() };
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	auto comboBox_w{ GUI::global_MIDI_Control_w };
	switch (comboBoxType)
	{
	case GlobalParamComboBoxType::omniModeOffOn:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_OmniModeIsEnabled);
		addItemList(choiceNamesList_OffOn(), 1);
		setSelectedItemIndex((int)global->omniModeIsEnabled(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeEnabled{ currentChoice == 1 };
			global->setOmniModeIsEnabled(shouldBeEnabled ? true : false);
		};
		break;
	case GlobalParamComboBoxType::controllersOffOn:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_ControllersAreEnabled);
		addItemList(choiceNamesList_OffOn(), 1);
		setSelectedItemIndex((int)global->controllersAreEnabled(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeEnabled{ currentChoice == 1 };
			global->setControllersAreEnabled(shouldBeEnabled ? true : false);
		};
		break;
	case GlobalParamComboBoxType::voiceChangesOffOn:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VoiceChangesAreEnabled);
		addItemList(choiceNamesList_OffOn(), 1);
		setSelectedItemIndex((int)global->voiceChangesAreEnabled(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeEnabled{ currentChoice == 1 };
			global->setVoiceChangesAreEnabled(shouldBeEnabled ? true : false);
		};
		break;
	case GlobalParamComboBoxType::sysExOffOn:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_SysExIsEnabled);
		addItemList(choiceNamesList_OffOn(), 1);
		setSelectedItemIndex((int)global->sysExIsEnabled(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeEnabled{ currentChoice == 1 };
			global->setSysExIsEnabled(shouldBeEnabled ? true : false);
		};
		break;
	case GlobalParamComboBoxType::spilloverOffOn:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_SpilloverIsEnabled);
		addItemList(choiceNamesList_OffOn(), 1);
		setSelectedItemIndex((int)global->spilloverIsEnabled(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeEnabled{ currentChoice == 1 };
			global->setSpilloverIsEnabled(shouldBeEnabled ? true : false);
		};
		break;
	case GlobalParamComboBoxType::midiEchoOffOn:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_MIDI_EchoIsEnabled);
		addItemList(choiceNamesList_OffOn(), 1);
		setSelectedItemIndex((int)global->midiEchoIsEnabled(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeEnabled{ currentChoice == 1 };
			global->set_MIDI_EchoIsEnabled(shouldBeEnabled ? true : false);
		};
		break;
	case GlobalParamComboBoxType::midiMonoOffOn:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_MIDI_MonoIsEnabled);
		addItemList(choiceNamesList_OffOn(), 1);
		setSelectedItemIndex((int)global->midiMonoIsEnabled(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeEnabled{ currentChoice == 1 };
			global->set_MIDI_MonoIsEnabled(shouldBeEnabled ? true : false);
		};
		break;
	case GlobalParamComboBoxType::activeSensingOffOn:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_ActiveSensingIsEnabled);
		addItemList(choiceNamesList_OffOn(), 1);
		setSelectedItemIndex((int)global->activeSensingIsEnabled(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeEnabled{ currentChoice == 1 };
			global->setActiveSensingIsEnabled(shouldBeEnabled ? true : false);
		};
		break;
	case GlobalParamComboBoxType::localControlOffOn:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_LocalControIsEnabled);
		addItemList(choiceNamesList_OffOn(), 1);
		setSelectedItemIndex((int)global->localControlIsEnabled(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeEnabled{ currentChoice == 1 };
			global->setLocalControIsEnabled(shouldBeEnabled ? true : false);
		};
		break;
	case GlobalParamComboBoxType::vibratoWaveType:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VibratoWaveType);
		addItemList(choiceNamesList_VibratoWaveType(), 1);
		setSelectedItemIndex((int)global->vibratoWaveType(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			global->setVibratoWaveType(VibratoWaveType{ currentChoice });
		};
		comboBox_w = GUI::global_VibratoControl_w;
		break;
	case GlobalParamComboBoxType::vibratoSpeedModSource:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VibratoSpeedModSource);
		addItemList(choiceNamesList_VibratoModSource(), 1);
		setSelectedItemIndex((int)global->vibratoSpeedModSource(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			global->setVibratoSpeedModSource(VibratoModSource{ currentChoice });
		};
		comboBox_w = GUI::global_VibratoControl_w;
		break;
	case GlobalParamComboBoxType::vibratoAmpModSource:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VibratoAmpModSource);
		addItemList(choiceNamesList_VibratoModSource(), 1);
		setSelectedItemIndex((int)global->vibratoAmpModSource(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			global->setVibratoAmpModSource(VibratoModSource{ currentChoice });
		};
		comboBox_w = GUI::global_VibratoControl_w;
		break;
	case GlobalParamComboBoxType::splitStereoOffOn:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_SplitStereoIsEnabled);
		addItemList(choiceNamesList_OffOn(), 1);
		setSelectedItemIndex((int)global->splitStereoIsEnabled(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeEnabled{ currentChoice == 1 };
			global->setSplitStereoIsEnabled(shouldBeEnabled ? true : false);
		};
		comboBox_w = GUI::global_MiscControl_w;
		break;
	case GlobalParamComboBoxType::voiceMapOffOn:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VoiceMapIsEnabled);
		addItemList(choiceNamesList_OffOn(), 1);
		setSelectedItemIndex((int)global->voiceMapIsEnabled(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeEnabled{ currentChoice == 1 };
			global->setVoiceMapIsEnabled(shouldBeEnabled ? true : false);
		};
		comboBox_w = GUI::global_MiscControl_w;
		break;
	case GlobalParamComboBoxType::voiceMapEchoOffOn:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VoiceMapEchoIsEnabled);
		addItemList(choiceNamesList_OffOn(), 1);
		setSelectedItemIndex((int)global->voiceMapEchoIsEnabled(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeEnabled{ currentChoice == 1 };
			global->setVoiceMapEchoIsEnabled(shouldBeEnabled ? true : false);
		};
		comboBox_w = GUI::global_MiscControl_w;
		break;
	case GlobalParamComboBoxType::squickOffOn:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_SQUICK_IsEnabled);
		addItemList(choiceNamesList_OffOn(), 1);
		setSelectedItemIndex((int)global->squickIsEnabled(), dontSendNotification);
		onChange = [this, global, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldBeEnabled{ currentChoice == 1 };
			global->set_SQUICK_IsEnabled(shouldBeEnabled ? true : false);
		};
		comboBox_w = GUI::global_MiscControl_w;
		break;
	case GlobalParamComboBoxType::descriptionTipsOffOn:
		addItemList(choiceNamesList_OffOn(), 1);
		setSelectedItemIndex((int)tooltips->shouldShowDescription(), dontSendNotification);
		onChange = [this, tooltips, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldShowDescription{ currentChoice == 1 };
			tooltips->setShouldShowDescription(shouldShowDescription ? true : false);
		};
		comboBox_w = GUI::global_MiscControl_w;
		break;
	case GlobalParamComboBoxType::currentChoiceTipsOffOn:
		addItemList(choiceNamesList_OffOn(), 1);
		setSelectedItemIndex((int)tooltips->shouldShowCurrentChoice(), dontSendNotification);
		onChange = [this, tooltips, unexposedParams] {
			auto currentChoice{ getSelectedItemIndex() };
			auto shouldShowCurrentChoice{ currentChoice == 1 };
			tooltips->setShouldShowCurrentChoice(shouldShowCurrentChoice ? true : false);
		};
		comboBox_w = GUI::global_MiscControl_w;
		break;
	default:
		break;
	}

	globalParamAsValue.addListener(this);

	shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
	shouldShowDescriptionAsValue.addListener(this);
	shouldShowCurrentChoiceAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowCurrentChoice);
	shouldShowCurrentChoiceAsValue.addListener(this);
	updateTooltip();

	setSize(comboBox_w, GUI::control_h);
}

StringArray ComboBoxForGlobalParameter::choiceNamesList_OffOn() {
	StringArray choiceNamesList;
	choiceNamesList.add(ChoiceName::buildForEnabledDisabled(disabled, ChoiceNameType::concise));
	choiceNamesList.add(ChoiceName::buildForEnabledDisabled(enabled, ChoiceNameType::concise));
	return choiceNamesList;
}

StringArray ComboBoxForGlobalParameter::choiceNamesList_VibratoWaveType() {
	StringArray choiceNamesList;
	for (auto choiceNum = (uint8)VibratoWaveType::triangle; choiceNum <= (uint8)VibratoWaveType::noise; ++choiceNum)
		choiceNamesList.add(ChoiceName::buildForVibratoWaveType(VibratoWaveType{ choiceNum }, ChoiceNameType::concise));
	return choiceNamesList;
}

StringArray ComboBoxForGlobalParameter::choiceNamesList_VibratoModSource() {
	StringArray choiceNamesList;
	for (auto choiceNum = (uint8)VibratoModSource::off; choiceNum <= (uint8)VibratoModSource::pedal_1; ++choiceNum)
		choiceNamesList.add(ChoiceName::buildForVibratoModSource(VibratoModSource{ choiceNum }, ChoiceNameType::concise));
	return choiceNamesList;
}

void ComboBoxForGlobalParameter::updateTooltip() {
	auto shouldShowDescription{ (bool)shouldShowDescriptionAsValue.getValue() };
	auto shouldShowCurrentChoice{ (bool)shouldShowCurrentChoiceAsValue.getValue() };
	String tip{ "" };
	if (shouldShowDescription) 	{
		switch (comboBoxType)
		{
		case GlobalParamComboBoxType::omniModeOffOn:
			tip += Description::buildForOmniMode();
			break;
		case GlobalParamComboBoxType::controllersOffOn:
			tip += Description::buildForControllers();
			break;
		case GlobalParamComboBoxType::voiceChangesOffOn:
			tip += Description::buildForVoiceChanges();
			break;
		case GlobalParamComboBoxType::sysExOffOn:
			tip += Description::buildForSysEx();
			break;
		case GlobalParamComboBoxType::spilloverOffOn:
			tip += Description::buildForSpillover();
			break;
		case GlobalParamComboBoxType::midiEchoOffOn:
			tip += Description::buildFor_MIDI_Echo();
			break;
		case GlobalParamComboBoxType::midiMonoOffOn:
			tip += Description::buildFor_MIDI_Mono();
			break;
		case GlobalParamComboBoxType::activeSensingOffOn:
			tip += Description::buildForActiveSensing();
			break;
		case GlobalParamComboBoxType::localControlOffOn:
			tip += Description::buildForLocalControl();
			break;
		case GlobalParamComboBoxType::vibratoWaveType:
			tip += Description::buildForVibratoWaveType();
			break;
		case GlobalParamComboBoxType::vibratoSpeedModSource:
			{
				bool speed{ true };
				tip += Description::buildForVibratoModSource(speed);
			}
			break;
		case GlobalParamComboBoxType::vibratoAmpModSource:
			{
				bool amplitude{ false };
				tip += Description::buildForVibratoModSource(amplitude);
			}
			break;
		case GlobalParamComboBoxType::splitStereoOffOn:
			tip += Description::buildForSplitStereo();
			break;
		case GlobalParamComboBoxType::voiceMapOffOn:
			tip += Description::buildForVoiceMap();
			break;
		case GlobalParamComboBoxType::voiceMapEchoOffOn:
			tip += Description::buildForVoiceMapEcho();
			break;
		case GlobalParamComboBoxType::squickOffOn:
			tip += Description::buildFor_SQUICK();
			break;
		case GlobalParamComboBoxType::descriptionTipsOffOn:
			tip += Description::buildForDescriptionTooltip();
			break;
		case GlobalParamComboBoxType::currentChoiceTipsOffOn:
			tip += Description::buildForCurrentValueTooltip();
			break;
		default:
			break;
		}
	}
	if (shouldShowCurrentChoice) {
		tip += "Current setting: ";
		auto currentChoice{ getSelectedItemIndex() };
		if (comboBoxType == GlobalParamComboBoxType::vibratoWaveType)
			tip += ChoiceName::buildForVibratoWaveType(VibratoWaveType{ currentChoice }, ChoiceNameType::verbose);
		else {
			if (comboBoxType == GlobalParamComboBoxType::vibratoSpeedModSource || comboBoxType == GlobalParamComboBoxType::vibratoAmpModSource)
				tip += ChoiceName::buildForVibratoModSource(VibratoModSource{ currentChoice }, ChoiceNameType::verbose);
			else
				tip += ChoiceName::buildForEnabledDisabled(currentChoice == 1 ? enabled : disabled, ChoiceNameType::verbose);
		}
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
