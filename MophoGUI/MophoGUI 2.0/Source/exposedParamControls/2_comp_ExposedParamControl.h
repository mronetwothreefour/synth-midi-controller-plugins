#pragma once

#include <JuceHeader.h>

#include "buttons/1_comp_ToggleButtonAndAttachment.h"
#include "sliders/1_comp_KnobAndAttachment.h"
#include "sliders/1_comp_KnobAndAttachment_ForOscShape.h"
#include "sliders/1_comp_KnobAndAttachment_ForSeqStep.h"
#include "../constants/constants_enum_ControlType.h"

using namespace MophoConstants;



class UnexposedParameters;

class ExposedParamControl : 
	public Component
{
	uint8 paramIndex;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	ControlType controlType;
	std::unique_ptr<KnobAndAttachment> knobAndAttachment;
	std::unique_ptr<KnobAndAttachment_ForOscShape> knobAndAttachment_ForOscShape;
	std::unique_ptr<KnobAndAttachment_ForSeqStep> knobAndAttachment_ForSeqStep;
	std::unique_ptr<ToggleButtonAndAttachment> toggleButtonAndAttachment;

	ExposedParamControl(); 

public:
	ExposedParamControl(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void buildKnobAndAttachmentControlForExposedParam();
	void buildKnobAndAttachmentControl_ForOscShape_ForExposedParam();
	void buildKnobAndAttachmentControl_ForSeqStep_ForExposedParam();
	void buildToggleButtonAndAttachment_ForExposedParam();

public:
	void attachControlToExposedParameter() const;
	void mouseDown(const MouseEvent& event) override;
	void deleteAttachmentBeforeControlToPreventMemLeak() const;
	~ExposedParamControl();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamControl)
};

