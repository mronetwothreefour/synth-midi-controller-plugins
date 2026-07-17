#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace P_600_G_Constants;

class ExposedParameters;
class KnobAndAttachment;
class SwitchSliderAndAttachment;
class TooltipsOptions;

class ExposedParamControl :
	public Component
{
	const uint8 paramIndex;
	ExposedParameters* exposedParams;
	TooltipsOptions* tooltips;
	ControlType controlType;
	std::unique_ptr<KnobAndAttachment> knobAndAttachment;
	std::unique_ptr<SwitchSliderAndAttachment> switchSliderAndAttachment;

	ExposedParamControl();

public:
	ExposedParamControl(const uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);

private:
	void buildKnobAndAttachmentControlForExposedParam();
	void buildSwitchSliderAndAttachmentControlForExposedParam();

public:
	void attachControlToExposedParameter() const;
	void mouseDown(const MouseEvent& event) override;
	void deleteAttachmentBeforeControlToPreventMemLeak() const;
	~ExposedParamControl();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamControl)
};

