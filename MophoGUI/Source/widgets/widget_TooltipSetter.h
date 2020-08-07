#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_Identifiers.h"
#include "../helpers/helper_IntToContextualStringConverters.h"
#include "../parameters/params_InfoForExposedParameters_Singleton.h"
#include "../parameters/params_TooltipOptions_Singleton.h"



class TooltipSetter : public ValueTree::Listener
{
protected:
	TooltipSetter() {
		auto& tooltipOptions{ TooltipOptions::get() };
		tooltipOptions.addListener(this);
	}

	~TooltipSetter() {
		auto& tooltipOptions{ TooltipOptions::get() };
		tooltipOptions.removeListener(this);
	}

	virtual void setTooltip() noexcept = 0;
	virtual String generateTooltipText() noexcept = 0;

public:
	void valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) override {
		if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription)
			setTooltip();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipSetter)
};



