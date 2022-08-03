#include "epc_2_comp_ExposedParamControl.h"

#include "epc_1_comp_ToggleButtonAndAttachment.h"
#include "epc_1_comp_ComboBoxAndAttachment.h"
#include "epc_1_comp_KnobAndAttachment.h"
#include "epc_1_comp_KnobAndAttachment_ForOscShape.h"
#include "epc_1_comp_KnobAndAttachment_ForSeqStep.h"
#include "epc_1_comp_KnobAndAttachment_ForVoiceNameChar.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using Track = SeqTrackNum;



ExposedParamControl::ExposedParamControl() :
	paramIndex{ (uint8)255 },
	exposedParams{ nullptr },
	unexposedParams{ nullptr },
	controlType{ ControlType::nullControl }
{
	// this default constructor is needed when initializing the vector in ExposedParamControlsServer
}

ExposedParamControl::ExposedParamControl(
	const uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	controlType{ exposedParams->info->controlTypeFor(paramIndex) }
{
	jassert((int)controlType > -1 && (int)controlType <= (int)ControlType::voiceNameChar);
	switch (controlType) {
	case ControlType::knob:
		buildKnobAndAttachmentControlForExposedParam();
		break;
	case ControlType::knobForPitch:
		buildKnobAndAttachmentControlForExposedParam();
		break;
	case ControlType::knobForOscShape:
		buildKnobAndAttachment_ForOscShape_ControlForExposedParam();
		break;
	case ControlType::toggleButton:
		buildToggleButtonAndAttachmentControlForExposedParam();
		break;
	case ControlType::comboBox:
		buildComboBoxAndAttachmentControlForExposedParam();
		break;
	case ControlType::seqTrackStep:
		buildKnobAndAttachment_ForSeqStep_ControlForExposedParam();
		break;
	case ControlType::voiceNameChar:
		buildKnobAndAttachment_ForVoiceNameChar_ControlForExposedParam();
		break;
	default:
		break;
	}
}

void ExposedParamControl::buildKnobAndAttachmentControlForExposedParam() {
	knobAndAttachment.reset(new KnobAndAttachment(paramIndex, exposedParams, unexposedParams));
	if (knobAndAttachment != nullptr) {
		addAndMakeVisible(knobAndAttachment.get());
		setSize(knobAndAttachment->getWidth(), knobAndAttachment->getHeight());
		knobAndAttachment->addMouseListener(this, true);
		if (controlType == ControlType::knobForPitch)
			knobAndAttachment->setKnobIsModifyingPitch(true);
		else
			knobAndAttachment->setKnobIsModifyingPitch(false);
	}
}

void ExposedParamControl::buildKnobAndAttachment_ForOscShape_ControlForExposedParam() {
	knobAndAttachment_ForOscShape.reset(new KnobAndAttachment_ForOscShape(paramIndex, exposedParams, unexposedParams));
	if (knobAndAttachment_ForOscShape != nullptr) {
		addAndMakeVisible(knobAndAttachment_ForOscShape.get());
		setSize(knobAndAttachment_ForOscShape->getWidth(), knobAndAttachment_ForOscShape->getHeight());
		knobAndAttachment_ForOscShape->addMouseListener(this, true);
	}
}

void ExposedParamControl::buildKnobAndAttachment_ForSeqStep_ControlForExposedParam() {
	auto paramID{ exposedParams->info->IDfor(paramIndex).toString()};
	auto trackNum{ paramID.fromFirstOccurrenceOf("Track_", false, false).upToFirstOccurrenceOf("_Step", false, false).getIntValue() };
	knobAndAttachment_ForSeqStep.reset(new KnobAndAttachment_ForSeqStep(paramIndex, Track{ trackNum }, exposedParams, unexposedParams));
	if (knobAndAttachment_ForSeqStep != nullptr) {
		addAndMakeVisible(knobAndAttachment_ForSeqStep.get());
		setSize(knobAndAttachment_ForSeqStep->getWidth(), knobAndAttachment_ForSeqStep->getHeight());
		knobAndAttachment_ForSeqStep->addMouseListener(this, true);
	}
}

void ExposedParamControl::buildKnobAndAttachment_ForVoiceNameChar_ControlForExposedParam() {
	knobAndAttachment_ForVoiceNameChar.reset(new KnobAndAttachment_ForVoiceNameChar(paramIndex, exposedParams, unexposedParams));
	if (knobAndAttachment_ForVoiceNameChar != nullptr) {
		addAndMakeVisible(knobAndAttachment_ForVoiceNameChar.get());
		setSize(knobAndAttachment_ForVoiceNameChar->getWidth(), knobAndAttachment_ForVoiceNameChar->getHeight());
		knobAndAttachment_ForVoiceNameChar->addMouseListener(this, true);
	}
}

void ExposedParamControl::buildToggleButtonAndAttachmentControlForExposedParam() {
	toggleButtonAndAttachment.reset(new ToggleButtonAndAttachment(paramIndex, exposedParams, unexposedParams));
	if (toggleButtonAndAttachment != nullptr) {
		addAndMakeVisible(toggleButtonAndAttachment.get());
		setSize(toggleButtonAndAttachment->getWidth(), toggleButtonAndAttachment->getHeight());
		toggleButtonAndAttachment->addMouseListener(this, true);
	}
}

void ExposedParamControl::buildComboBoxAndAttachmentControlForExposedParam() {
	comboBoxAndAttachment.reset(new ComboBoxAndAttachment(paramIndex, exposedParams, unexposedParams));
	if (comboBoxAndAttachment != nullptr) {
		addAndMakeVisible(comboBoxAndAttachment.get());
		setSize(comboBoxAndAttachment->getWidth(), comboBoxAndAttachment->getHeight());
		comboBoxAndAttachment->addMouseListener(this, true);
	}
}

void ExposedParamControl::attachControlToExposedParameter() const {
	jassert(exposedParams != nullptr);
	switch (controlType)
	{
	case ControlType::knob:
		if (knobAndAttachment != nullptr)
			knobAndAttachment->attachKnobToExposedParameter();
		break;
	case ControlType::knobForPitch:
		if (knobAndAttachment != nullptr)
			knobAndAttachment->attachKnobToExposedParameter();
		break;
	case ControlType::knobForOscShape:
		if (knobAndAttachment_ForOscShape != nullptr)
			knobAndAttachment_ForOscShape->attachKnobToExposedParameter();
		break;
	case ControlType::toggleButton:
		if (toggleButtonAndAttachment != nullptr)
			toggleButtonAndAttachment->attachToggleToExposedParameter();
		break;
	case ControlType::comboBox:
		if (comboBoxAndAttachment != nullptr)
			comboBoxAndAttachment->attachComboBoxToExposedParameter();
		break;
	case ControlType::seqTrackStep:
		if (knobAndAttachment_ForSeqStep != nullptr)
			knobAndAttachment_ForSeqStep->attachKnobsToExposedParameters();
		break;
	case ControlType::voiceNameChar:
		if (knobAndAttachment_ForVoiceNameChar != nullptr)
			knobAndAttachment_ForVoiceNameChar->attachKnobToExposedParameter();
		break;
	default: break;
	}
}

void ExposedParamControl::mouseDown(const MouseEvent& event) {
	if (event.mods == ModifierKeys::rightButtonModifier)
		exposedParams->randomize->randomizeParameter(paramIndex);
}

void ExposedParamControl::deleteAttachmentBeforeControlToPreventMemLeak() const {
	if (knobAndAttachment != nullptr)
		knobAndAttachment->deleteAttachmentBeforeKnobToPreventMemLeak();
	if (knobAndAttachment_ForOscShape != nullptr)
		knobAndAttachment_ForOscShape->deleteAttachmentBeforeKnobToPreventMemLeak();
	if (knobAndAttachment_ForSeqStep != nullptr)
		knobAndAttachment_ForSeqStep->deleteAttachmentsBeforeKnobsToPreventMemLeaks();
	if (knobAndAttachment_ForVoiceNameChar != nullptr)
		knobAndAttachment_ForVoiceNameChar->deleteAttachmentBeforeKnobToPreventMemLeak();
	if (toggleButtonAndAttachment != nullptr)
		toggleButtonAndAttachment->deleteAttachmentBeforeToggleToPreventMemLeak();
	if (comboBoxAndAttachment != nullptr)
		comboBoxAndAttachment->deleteAttachmentBeforeComboBoxToPreventMemLeak();
}

ExposedParamControl::~ExposedParamControl() {
	if (knobAndAttachment != nullptr) {
		knobAndAttachment->removeMouseListener(this);
		knobAndAttachment = nullptr;
	}
	if (knobAndAttachment_ForOscShape != nullptr) {
		knobAndAttachment_ForOscShape->removeMouseListener(this);
		knobAndAttachment_ForOscShape = nullptr;
	}
	if (knobAndAttachment_ForSeqStep != nullptr) {
		knobAndAttachment_ForSeqStep->removeMouseListener(this);
		knobAndAttachment_ForSeqStep = nullptr;
	}
	if (knobAndAttachment_ForVoiceNameChar != nullptr) {
		knobAndAttachment_ForVoiceNameChar->removeMouseListener(this);
		knobAndAttachment_ForVoiceNameChar = nullptr;
	}
	if (toggleButtonAndAttachment != nullptr) {
		toggleButtonAndAttachment->removeMouseListener(this);
		toggleButtonAndAttachment = nullptr;
	}
	if (comboBoxAndAttachment != nullptr) {
		comboBoxAndAttachment->removeMouseListener(this);
		comboBoxAndAttachment = nullptr;
	}
}
