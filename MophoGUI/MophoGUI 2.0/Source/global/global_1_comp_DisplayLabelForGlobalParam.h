#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;



class UnexposedParameters;

class DisplayLabelForGlobalParameter :
	public::Label,
	public ValueTree::Listener
{
	GlobalParamDisplayLabelType labelType;
	Identifier paramID;
	UnexposedParameters* unexposedParams;

public:
	DisplayLabelForGlobalParameter() = delete;

	DisplayLabelForGlobalParameter(GlobalParamDisplayLabelType labelType, UnexposedParameters* unexposedParams);
	void setTextAccordingToParameterSetting();
	void updateTooltip();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~DisplayLabelForGlobalParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DisplayLabelForGlobalParameter)
};