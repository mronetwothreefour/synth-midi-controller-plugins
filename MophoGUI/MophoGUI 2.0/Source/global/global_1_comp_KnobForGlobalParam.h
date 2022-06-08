#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"
#include "../exposedParamControls/sliders/epc_0_slider_JuceSlidersWithMouseMods.h"

using namespace MophoConstants;



class UnexposedParameters;

class KnobForGlobalParameter :
	public RotarySliderWithMouseWheelMoveOverride,
	public ValueTree::Listener
{
	GlobalParamKnobType knobType;
	Identifier paramID;
	UnexposedParameters* unexposedParams;

public:
	KnobForGlobalParameter() = delete;

	KnobForGlobalParameter(GlobalParamKnobType knobType, UnexposedParameters* unexposedParams);
	void updateTooltip();
	void valueChanged() override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~KnobForGlobalParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobForGlobalParameter)

};