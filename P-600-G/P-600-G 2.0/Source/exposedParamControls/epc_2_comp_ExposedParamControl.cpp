#include "epc_2_comp_ExposedParamControl.h"

#include "epc_1_comp_KnobAndAttachment.h"
#include "epc_1_comp_SwitchSliderAndAttachment.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

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
	jassert(controlType != ControlType::nullControl);
	if (controlType == ControlType::knob || controlType == ControlType::knobForPitch)
		buildKnobAndAttachmentControlForExposedParam();
	if (controlType == ControlType::twoPoleSwitch || controlType == ControlType::threePoleSwitch)
		buildSwitchSliderAndAttachmentControlForExposedParam();
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

void ExposedParamControl::buildSwitchSliderAndAttachmentControlForExposedParam() {
	switchSliderAndAttachment.reset(new SwitchSliderAndAttachment(paramIndex, exposedParams, unexposedParams));
	if (switchSliderAndAttachment != nullptr) {
		addAndMakeVisible(switchSliderAndAttachment.get());
		setSize(switchSliderAndAttachment->getWidth(), switchSliderAndAttachment->getHeight());
		switchSliderAndAttachment->addMouseListener(this, true);
	}
}

void ExposedParamControl::attachControlToExposedParameter() const {
	jassert(exposedParams != nullptr);
	if (controlType == ControlType::knob || controlType == ControlType::knobForPitch)
		if (knobAndAttachment != nullptr)
			knobAndAttachment->attachKnobToExposedParameter();
	if (controlType == ControlType::twoPoleSwitch || controlType == ControlType::threePoleSwitch)
		if (switchSliderAndAttachment != nullptr)
			switchSliderAndAttachment->attachSwitchSliderToExposedParameter();
}

void ExposedParamControl::mouseDown(const MouseEvent& event) {
	if (event.mods == ModifierKeys::rightButtonModifier)
		exposedParams->randomize->randomizeParameter(paramIndex);
}

void ExposedParamControl::deleteAttachmentBeforeControlToPreventMemLeak() const {
	if (knobAndAttachment != nullptr)
		knobAndAttachment->deleteAttachmentBeforeKnobToPreventMemLeak();
	if (switchSliderAndAttachment != nullptr)
		switchSliderAndAttachment->deleteAttachmentBeforeSwitchSliderToPreventMemLeak();
}

ExposedParamControl::~ExposedParamControl() {
	if (knobAndAttachment != nullptr) {
		knobAndAttachment->removeMouseListener(this);
		knobAndAttachment = nullptr;
	}
	if (switchSliderAndAttachment != nullptr) {
		switchSliderAndAttachment->removeMouseListener(this);
		switchSliderAndAttachment = nullptr;
	}
}
