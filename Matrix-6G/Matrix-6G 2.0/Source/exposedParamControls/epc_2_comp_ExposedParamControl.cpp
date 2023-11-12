#include "epc_2_comp_ExposedParamControl.h"

#include "epc_1_comp_ComboBoxAndAttachment.h"
#include "epc_1_comp_SliderAndAttachment.h"
#include "epc_1_comp_SliderAndAttachment_ForOscBalance.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

ExposedParamControl::ExposedParamControl() :
	paramIndex{ (uint8)255 },
	exposedParams{ nullptr },
	tooltips{ nullptr },
	controlType{ ControlType::nullControl }
{
	// this default constructor is needed when initializing the vector in ExposedParamControlsServer
}

ExposedParamControl::ExposedParamControl(
	const uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	tooltips{ tooltips },
	controlType{ exposedParams->info->controlTypeFor(paramIndex) }
{
	jassert(controlType != ControlType::nullControl);
	if (controlType == ControlType::slider || controlType == ControlType::sliderForPitch)
		buildSliderAndAttachmentControlForExposedParam();
	if (controlType == ControlType::sliderForOscBalance)
		buildSliderAndAttachmentControlForOscBalance();
	if (controlType == ControlType::comboBox)
		buildComboBoxAndAttachmentControlForExposedParam();
}

void ExposedParamControl::buildSliderAndAttachmentControlForExposedParam() {
	sliderAndAttachment.reset(new SliderAndAttachment(paramIndex, exposedParams, tooltips));
	if (sliderAndAttachment != nullptr) {
		addAndMakeVisible(sliderAndAttachment.get());
		setSize(sliderAndAttachment->getWidth(), sliderAndAttachment->getHeight());
		sliderAndAttachment->addMouseListener(this, true);
		if (controlType == ControlType::sliderForPitch)
			sliderAndAttachment->setKnobIsModifyingPitch(true);
		else
			sliderAndAttachment->setKnobIsModifyingPitch(false);
	}
}

void ExposedParamControl::buildSliderAndAttachmentControlForOscBalance() {
	sliderAndAttachment_ForOscBalance.reset(new SliderAndAttachment_ForOscBalance(exposedParams, tooltips));
	if (sliderAndAttachment_ForOscBalance != nullptr) {
		addAndMakeVisible(sliderAndAttachment_ForOscBalance.get());
		setSize(sliderAndAttachment_ForOscBalance->getWidth(), sliderAndAttachment_ForOscBalance->getHeight());
		sliderAndAttachment_ForOscBalance->addMouseListener(this, true);
	}
}

void ExposedParamControl::buildComboBoxAndAttachmentControlForExposedParam() {
	comboBoxAndAttachment.reset(new ComboBoxAndAttachment(paramIndex, exposedParams, tooltips));
	if (comboBoxAndAttachment != nullptr) {
		addAndMakeVisible(comboBoxAndAttachment.get());
		setSize(comboBoxAndAttachment->getWidth(), comboBoxAndAttachment->getHeight());
		comboBoxAndAttachment->addMouseListener(this, true);
	}
}

void ExposedParamControl::attachControlToExposedParameter() const {
	jassert(exposedParams != nullptr);
	if (controlType == ControlType::slider || controlType == ControlType::sliderForPitch)
		if (sliderAndAttachment != nullptr)
			sliderAndAttachment->attachSliderToExposedParameter();
	if (controlType == ControlType::sliderForOscBalance)
		if (sliderAndAttachment_ForOscBalance != nullptr)
			sliderAndAttachment_ForOscBalance->attachSliderToExposedParameter();
	if (controlType == ControlType::comboBox)
		if (comboBoxAndAttachment != nullptr)
			comboBoxAndAttachment->attachComboBoxToExposedParameter();
}

void ExposedParamControl::mouseDown(const MouseEvent& event) {
	if (event.mods == ModifierKeys::rightButtonModifier)
		exposedParams->randomize->randomizeExposedParameter(paramIndex);
}

void ExposedParamControl::deleteAttachmentBeforeControlToPreventMemLeak() const {
	if (sliderAndAttachment != nullptr)
		sliderAndAttachment->deleteAttachmentBeforeSliderToPreventMemLeak();
	if (sliderAndAttachment_ForOscBalance != nullptr)
		sliderAndAttachment_ForOscBalance->deleteAttachmentBeforeSliderToPreventMemLeak();
	if (comboBoxAndAttachment != nullptr)
		comboBoxAndAttachment->deleteAttachmentBeforeComboBoxToPreventMemLeak();
}

ExposedParamControl::~ExposedParamControl() {
	if (sliderAndAttachment != nullptr) {
		sliderAndAttachment->removeMouseListener(this);
		sliderAndAttachment = nullptr;
	}
	if (sliderAndAttachment_ForOscBalance != nullptr) {
		sliderAndAttachment_ForOscBalance->removeMouseListener(this);
		sliderAndAttachment_ForOscBalance = nullptr;
	}
	if (comboBoxAndAttachment != nullptr) {
		comboBoxAndAttachment->removeMouseListener(this);
		comboBoxAndAttachment = nullptr;
	}
}
