#include "GlobalOptionsWindow.h"

GlobalOptionsComponent::GlobalOptionsComponent
(
	PluginProcessor& p,
	PrivateParameters* privateParameters
) :
	processor{ p },
	privateParams{ privateParameters },
	knob_Transpose{ "MASTER", "TRANSPOSE", p, privateParameters, ID::masterTranspose, MophoParameterIndex::masterTranspose, MophoParameterType::masterTranspose, MophoParameterNRPN::masterTranspose, 24, MophoKnobSensitivity::masterTranspose },
	knob_FineTune{ "MASTER", "FINE TUNE", p, privateParameters, ID::masterFineTune, MophoParameterIndex::masterFineTune, MophoParameterType::oscFineTune, MophoParameterNRPN::masterFineTune, 100, MophoKnobSensitivity::oscFineTune },
	knob_MIDIchannel{ "MIDI", "CHANNEL", p, privateParameters, ID::midiChannel, MophoParameterIndex::midiChannel, MophoParameterType::midiChannel, MophoParameterNRPN::midiChannel, 16, MophoKnobSensitivity::midiChannel }
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
