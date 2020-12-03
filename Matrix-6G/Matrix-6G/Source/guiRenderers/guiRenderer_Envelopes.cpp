#include "guiRenderer_Envelopes.h"

#include "../gui/gui_Colors.h"



RendererForEnvelopes::RendererForEnvelopes(int envelopeNumber, AudioProcessorValueTreeState* exposedParams) :
	delayAttachment{ *exposedParams, "env" + (String)envelopeNumber + "_Delay", delay },
	attackAttachment{ *exposedParams, "env" + (String)envelopeNumber + "_Attack", attack },
	decayAttachment{ *exposedParams, "env" + (String)envelopeNumber + "_Decay", decay },
	sustainAttachment{ *exposedParams, "env" + (String)envelopeNumber + "_Sustain", sustain },
	releaseAttachment{ *exposedParams, "env" + (String)envelopeNumber + "_Release", release }
{
	delay.addListener(this);
	attack.addListener(this);
	decay.addListener(this);
	sustain.addListener(this);
	release.addListener(this);
	set_attackStart_x();
	set_decayStart_x();
	set_sustainStart_x();
	set_releaseStart_x();
	set_releaseEnd_x();
	set_sustain_y();
	auto envelopeRenderer_w{ 228 };
	auto envelopeRenderer_h{ 108 };
	setSize(envelopeRenderer_w, envelopeRenderer_h);
}

void RendererForEnvelopes::sliderValueChanged(Slider* /*slider*/) {
	set_attackStart_x();
	set_decayStart_x();
	set_sustainStart_x();
	set_releaseStart_x();
	set_releaseEnd_x();
	set_sustain_y();
	repaint();
}

void RendererForEnvelopes::set_attackStart_x() {
	attackStart_x = envelopeStart_x + (((float)delay.getValue() / 63.0f) * maxSegment_w);
}

void RendererForEnvelopes::set_decayStart_x() {
	decayStart_x = attackStart_x + (((float)attack.getValue() / 63.0f) * maxSegment_w);
}

void RendererForEnvelopes::set_sustainStart_x() {
	sustainStart_x = decayStart_x + (((float)decay.getValue() / 63.0f) * maxSegment_w);
}

void RendererForEnvelopes::set_releaseStart_x() {
	releaseStart_x = sustainStart_x + sustainSegment_w;
}

void RendererForEnvelopes::set_releaseEnd_x() {
	releaseEnd_x = releaseStart_x + (((float)release.getValue() / 63.0f) * maxSegment_w);
}

void RendererForEnvelopes::set_sustain_y() {
	sustain_y = minimum_y - (((float)sustain.getValue() / 63.0f) * envelope_h);
}

void RendererForEnvelopes::paint(Graphics& g) {
	g.setColour(Color::led_blue);
	Path path;
	path.startNewSubPath(envelopeStart_x, minimum_y);
	path.lineTo(attackStart_x, minimum_y);
	path.lineTo(decayStart_x, maximum_y);
	path.lineTo(sustainStart_x, sustain_y);
	path.lineTo(releaseStart_x, sustain_y);
	path.lineTo(releaseEnd_x, minimum_y);
	path.lineTo(envelopeEnd_x, minimum_y);
	PathStrokeType strokeType{ 2.0f, PathStrokeType::JointStyle::curved, PathStrokeType::EndCapStyle::rounded };
	g.strokePath(path, strokeType);
}

RendererForEnvelopes::~RendererForEnvelopes() {
	release.removeListener(this);
	sustain.removeListener(this);
	decay.removeListener(this);
	attack.removeListener(this);
	delay.removeListener(this);
}
