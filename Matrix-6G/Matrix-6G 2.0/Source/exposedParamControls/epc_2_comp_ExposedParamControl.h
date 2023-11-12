#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

class ComboBoxAndAttachment;
class ExposedParameters;
class SliderAndAttachment;
class SliderAndAttachment_ForOscBalance;
class TooltipsOptions;

class ExposedParamControl :
	public Component
{
	const uint8 paramIndex;
	ExposedParameters* exposedParams;
	TooltipsOptions* tooltips;
	ControlType controlType;
	std::unique_ptr<SliderAndAttachment> sliderAndAttachment;
	std::unique_ptr<SliderAndAttachment_ForOscBalance> sliderAndAttachment_ForOscBalance;
	std::unique_ptr<ComboBoxAndAttachment> comboBoxAndAttachment;

	ExposedParamControl();

public:
	ExposedParamControl(const uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);

private:
	void buildSliderAndAttachmentControlForExposedParam();
	void buildSliderAndAttachmentControlForOscBalance();
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

