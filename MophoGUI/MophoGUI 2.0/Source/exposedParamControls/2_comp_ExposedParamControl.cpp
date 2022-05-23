#include "2_comp_ExposedParamControl.h"

#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"



ExposedParamControl::ExposedParamControl() :
	paramIndex{ (uint8)255 },
	exposedParams{ nullptr },
	unexposedParams{ nullptr },
	controlType{ ControlType::nullControl }
{
	// this default constructor is needed when initializing the vector in ExposedParamControlsServer
}

ExposedParamControl::ExposedParamControl(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	controlType{ InfoForExposedParameters::get().controlTypeFor(paramIndex) }
{
	switch (controlType) {
	case ControlType::knob:
		buildKnobAndAttachmentControlForExposedParam();
		break;
	case ControlType::knobForPitch:
		buildKnobAndAttachmentControlForExposedParam();
		break;
	case ControlType::knobForOscShape:
		buildKnobAndAttachmentControl_ForOscShape_ForExposedParam();
		break;
	case ControlType::toggleButton:
		buildToggleButtonAndAttachment_ForExposedParam();
		break;
	case ControlType::comboBox:
		break;
	case ControlType::voiceNameChar:
		break;
	case ControlType::seqTrackStep:
		buildKnobAndAttachmentControl_ForSeqStep_ForExposedParam();
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
			knobAndAttachment->setKnobIsModifyingPitch();
		else
			knobAndAttachment->setKnobIsNotModifyingPitch();
	}
}

void ExposedParamControl::buildKnobAndAttachmentControl_ForOscShape_ForExposedParam() {
	knobAndAttachment_ForOscShape.reset(new KnobAndAttachment_ForOscShape(paramIndex, exposedParams, unexposedParams));
	if (knobAndAttachment_ForOscShape != nullptr) {
		addAndMakeVisible(knobAndAttachment_ForOscShape.get());
		setSize(knobAndAttachment_ForOscShape->getWidth(), knobAndAttachment_ForOscShape->getHeight());
		knobAndAttachment_ForOscShape->addMouseListener(this, true);
	}
}

void ExposedParamControl::buildKnobAndAttachmentControl_ForSeqStep_ForExposedParam() {
	knobAndAttachment_ForSeqStep.reset(new KnobAndAttachment_ForSeqStep(paramIndex, exposedParams, unexposedParams));
	if (knobAndAttachment_ForSeqStep != nullptr) {
		addAndMakeVisible(knobAndAttachment_ForSeqStep.get());
		setSize(knobAndAttachment_ForSeqStep->getWidth(), knobAndAttachment_ForSeqStep->getHeight());
		knobAndAttachment_ForSeqStep->addMouseListener(this, true);
	}
}

void ExposedParamControl::buildToggleButtonAndAttachment_ForExposedParam() {
	toggleButtonAndAttachment.reset(new ToggleButtonAndAttachment(paramIndex, exposedParams, unexposedParams));
	if (toggleButtonAndAttachment != nullptr) {
		addAndMakeVisible(toggleButtonAndAttachment.get());
		setSize(toggleButtonAndAttachment->getWidth(), toggleButtonAndAttachment->getHeight());
		toggleButtonAndAttachment->addMouseListener(this, true);
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
		break;
	case ControlType::seqTrackStep:
		if (knobAndAttachment_ForSeqStep != nullptr)
			knobAndAttachment_ForSeqStep->attachKnobToExposedParameter();
		break;
	case ControlType::voiceNameChar:
		break;
	default: break;
	}
}

void ExposedParamControl::mouseDown(const MouseEvent& /*event*/) {
	// todo: use this for randomizing control with right-click
}

void ExposedParamControl::deleteAttachmentBeforeControlToPreventMemLeak() const {
	if (knobAndAttachment != nullptr)
		knobAndAttachment->deleteAttachmentBeforeKnobToPreventMemLeak();
	if (knobAndAttachment_ForOscShape != nullptr)
		knobAndAttachment_ForOscShape->deleteAttachmentBeforeKnobToPreventMemLeak();
	if (knobAndAttachment_ForSeqStep != nullptr)
		knobAndAttachment_ForSeqStep->deleteAttachmentBeforeKnobToPreventMemLeak();
	if (toggleButtonAndAttachment != nullptr)
		toggleButtonAndAttachment->deleteAttachmentBeforeToggleToPreventMemLeak();
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
	if (toggleButtonAndAttachment != nullptr) {
		toggleButtonAndAttachment->removeMouseListener(this);
		toggleButtonAndAttachment = nullptr;
	}
}
