#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;

class ComboBoxAndAttachment;
class ExposedParameters;
class KnobAndAttachment;
class KnobAndAttachment_ForOscShape;
class KnobAndAttachment_ForSeqStep;
class KnobAndAttachment_ForVoiceNameChar;
class ToggleButtonAndAttachment;
class TooltipsOptions;

class ExposedParamControl : 
	public Component
{
	const uint8 paramIndex;
	ExposedParameters* exposedParams;
	TooltipsOptions* tooltips;
	ControlType controlType;
	std::unique_ptr<KnobAndAttachment> knobAndAttachment;
	std::unique_ptr<KnobAndAttachment_ForOscShape> knobAndAttachment_ForOscShape;
	std::unique_ptr<KnobAndAttachment_ForSeqStep> knobAndAttachment_ForSeqStep;
	std::unique_ptr<KnobAndAttachment_ForVoiceNameChar> knobAndAttachment_ForVoiceNameChar;
	std::unique_ptr<ToggleButtonAndAttachment> toggleButtonAndAttachment;
	std::unique_ptr<ComboBoxAndAttachment> comboBoxAndAttachment;

	ExposedParamControl(); 

public:
	ExposedParamControl(const uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);

private:
	void buildKnobAndAttachmentControlForExposedParam();
	void buildKnobAndAttachment_ForOscShape_ControlForExposedParam();
	void buildKnobAndAttachment_ForSeqStep_ControlForExposedParam();
	void buildKnobAndAttachment_ForVoiceNameChar_ControlForExposedParam();
	void buildToggleButtonAndAttachmentControlForExposedParam();
	void buildComboBoxAndAttachmentControlForExposedParam();

public:
	void attachControlToExposedParameter() const;
	void mouseDown(const MouseEvent& event) override;
	void deleteAttachmentBeforeControlToPreventMemLeak() const;
	~ExposedParamControl();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamControl)
};

