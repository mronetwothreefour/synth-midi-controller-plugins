#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"
#include "../gui/gui_comp_JuceSlidersWithMouseMods.h"

using namespace MophoConstants;
using KnobType = GlobalParamKnobType;

class GlobalOptions;
class UnexposedParameters;

class KnobForGlobalParameter :
	public RotarySliderWithMouseWheelMoveOverride,
	public Value::Listener
{
	KnobType knobType;
	Identifier paramID;
	GlobalOptions* global;
	UnexposedParameters* unexposedParams;
	Value globalParamValue;
	Value shouldShowDescriptionValue;
	Value shouldShowCurrentChoiceValue;

public:
	KnobForGlobalParameter() = delete;

	KnobForGlobalParameter(KnobType knobType, UnexposedParameters* unexposedParams);
	void updateTooltip();
	void valueChanged() override;
	void valueChanged(Value& value) override;
	~KnobForGlobalParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobForGlobalParameter)
};