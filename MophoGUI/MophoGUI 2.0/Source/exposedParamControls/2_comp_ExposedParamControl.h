#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;


class ComboBoxAndAttachment;
class KnobAndAttachment;
class KnobAndAttachment_ForOscShape;
class KnobAndAttachment_ForSeqStep;
class ToggleButtonAndAttachment;
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
	std::unique_ptr<ComboBoxAndAttachment> comboBoxAndAttachment;

	ExposedParamControl(); 

public:
	ExposedParamControl(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void buildKnobAndAttachmentControlForExposedParam();
	void buildKnobAndAttachmentControl_ForOscShape_ForExposedParam();
	void buildKnobAndAttachmentControl_ForSeqStep_ForExposedParam();
	void buildToggleButtonAndAttachment_ForExposedParam();
	void buildComboBoxAndAttachment_ForExposedParam();

public:
	void attachControlToExposedParameter() const;
	void mouseDown(const MouseEvent& event) override;
	void deleteAttachmentBeforeControlToPreventMemLeak() const;
	~ExposedParamControl();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamControl)
};
