#include "GlobalOptionsWindow.h"

GlobalOptionsComponent::GlobalOptionsComponent
(
	PluginProcessor& p,
	PrivateParameters* privateParameters,
	ValueConverters* vc
) :
	processor{ p },
	privateParams{ privateParameters },
	knob_Transpose{ p, privateParameters, vc},
	knob_FineTune{ p, privateParameters, vc},
	knob_MIDIchannel{ p, privateParameters, vc}
{
	addAndMakeVisible(knob_Transpose);
	addAndMakeVisible(knob_FineTune);
	addAndMakeVisible(knob_MIDIchannel);

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
	knob_FineTune.setBounds(85, knobRow_y, knob_Transpose.getWidth(), knob_Transpose.getHeight());
	knob_MIDIchannel.setBounds(160, knobRow_y, knob_Transpose.getWidth(), knob_Transpose.getHeight());
}
