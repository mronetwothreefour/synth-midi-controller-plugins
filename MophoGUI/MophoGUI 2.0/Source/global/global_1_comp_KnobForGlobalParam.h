#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"
#include "../exposedParamControls/sliders/epc_0_slider_JuceSlidersWithMouseMods.h"

using namespace MophoConstants;
using KnobType = GlobalParamKnobType;



class GlobalOptions;
class TooltipsOptions;
class UnexposedParameters;

class KnobForGlobalParameter :
	public RotarySliderWithMouseWheelMoveOverride,
	public ValueTree::Listener
{
	KnobType knobType;
	Identifier paramID;
	GlobalOptions* global;
	TooltipsOptions* tooltips;
	UnexposedParameters* unexposedParams;

public:
	KnobForGlobalParameter() = delete;

	KnobForGlobalParameter(KnobType knobType, UnexposedParameters* unexposedParams);
	void updateTooltip();
	void valueChanged() override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~KnobForGlobalParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobForGlobalParameter)

};