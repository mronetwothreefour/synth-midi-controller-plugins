#include "guiRenderer_ForEnvelopes.h"

#include "../gui/gui_Colors.h"



RendererForEnvelopes::RendererForEnvelopes(String envelopeID, AudioProcessorValueTreeState* exposedParams) :
	delayAttachment{ *exposedParams, envelopeID + "Delay", delay },
	attackAttachment{ *exposedParams, envelopeID + "Attack", attack },
	decayAttachment{ *exposedParams, envelopeID + "Decay", decay },
	sustainAttachment{ *exposedParams, envelopeID + "Sustain", sustain },
	releaseAttachment{ *exposedParams, envelopeID + "Release", release }
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
	auto envelopeRenderer_w{ 210 };
	auto envelopeRenderer_h{ 90 };
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
	attackStart_x = envelopeStart_x + (((float)delay.getValue() / 127.0f) * maxSegment_w);
}

void RendererForEnvelopes::set_decayStart_x() {
	decayStart_x = attackStart_x + (((float)attack.getValue() / 127.0f) * maxSegment_w);
}

void RendererForEnvelopes::set_sustainStart_x() {
	sustainStart_x = decayStart_x + (((float)decay.getValue() / 127.0f) * maxSegment_w);
}

void RendererForEnvelopes::set_releaseStart_x() {
	releaseStart_x = sustainStart_x + sustainSegment_w;
}

void RendererForEnvelopes::set_releaseEnd_x() {
	releaseEnd_x = releaseStart_x + (((float)release.getValue() / 127.0f) * maxSegment_w);
}

void RendererForEnvelopes::set_sustain_y() {
	sustain_y = minimum_y - (((float)sustain.getValue() / 127.0f) * 60.0f);
}

void RendererForEnvelopes::paint(Graphics& g) {
	g.setColour(Color::controlText);
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
