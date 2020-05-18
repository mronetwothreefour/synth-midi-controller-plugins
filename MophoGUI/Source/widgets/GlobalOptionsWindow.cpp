#include "GlobalOptionsWindow.h"

GlobalOptionsComponent::GlobalOptionsComponent
(
	PluginProcessor& p,
	PrivateParameters* privateParameters,
	ValueConverters* vc
) :
	processor{ p },
	privateParams{ privateParameters },
	knob_Transpose{ p, privateParameters, vc}
{
	addAndMakeVisible(knob_Transpose);

	auto globalOptions_w{ 240 };
	auto globalOptions_h{ 330 };
	setSize(globalOptions_w, globalOptions_h);
}

void GlobalOptionsComponent::paint(Graphics& g)
{
}

void GlobalOptionsComponent::resized()
{
	auto knobRow_y{ 10 };
	knob_Transpose.setBounds(10, knobRow_y, knob_Transpose.getWidth(), knob_Transpose.getHeight());
}
