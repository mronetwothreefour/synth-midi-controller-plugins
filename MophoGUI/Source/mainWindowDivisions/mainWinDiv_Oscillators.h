#pragma once

#include <JuceHeader.h>

#include "..\core_PluginProcessor.h"
#include "..\widgets\widget_Sliders.h"

class MainWindowDivision_Oscillators : public Component
{
	PluginProcessor& processor;

public:
	explicit MainWindowDivision_Oscillators(PluginProcessor& processor) :
		processor{ processor }
	{
		//auto& controlDB{ ControlWithPublicParameterAttacherDatabase::get() };
		//auto* control{ controlDB.getControl(0) };
		//addAndMakeVisible(control);
		//control->attachToPublicParameter(processor.exposedParams.get(), ID::pitchOsc1);
		//control->setCentrePosition(33, 35);

		auto div_Oscillators_w{ 437 };
		auto div_Oscillators_h{ 106 };
		setSize(div_Oscillators_w, div_Oscillators_h);
	}

	void paint(Graphics& /*g*/) override
	{}


	void resized() override
	{
	}
};