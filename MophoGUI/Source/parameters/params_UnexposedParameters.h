#pragma once

#include <JuceHeader.h>



struct TooltipOptions_Singleton
{
	ValueTree tooltipOptionsTree;

	TooltipOptions_Singleton(TooltipOptions_Singleton&&) = delete;
	TooltipOptions_Singleton& operator=(TooltipOptions_Singleton&&) = delete;

	static ValueTree& get() {
		static TooltipOptions_Singleton tooltipOptions_Singleton;
		return tooltipOptions_Singleton.tooltipOptionsTree;
	}

private:
	TooltipOptions_Singleton() :
		tooltipOptionsTree{ ID::tooltips_Options }
	{
		addTooltipOptionsProperties();
	}

	~TooltipOptions_Singleton() {
	}

	void addTooltipOptionsProperties() {
		tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowCurrentValue, (bool)true, nullptr);
		tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowDescription, (bool)true, nullptr);
		tooltipOptionsTree.setProperty(ID::tooltips_DelayInMilliseconds, 1000, nullptr);
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipOptions_Singleton)
};