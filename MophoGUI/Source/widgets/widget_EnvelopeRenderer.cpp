#include "widget_EnvelopeRenderer.h"

#include "../helpers/helper_CustomColors.h"



EnvelopeRenderer::EnvelopeRenderer(String envelopeID, AudioProcessorValueTreeState* exposedParams) :
	delayAttachment{ *exposedParams, envelopeID + "Delay", delay },
	attackAttachment{ *exposedParams, envelopeID + "Attack", attack },
	decayAttachment{ *exposedParams, envelopeID + "Decay", decay },
	sustainAttachment{ *exposedParams, envelopeID + "Sustain", sustain },
	releaseAttachment{ *exposedParams, envelopeID + "Release", release },
	attackStart_x{ set_attackStart_x() },
	decayStart_x{ set_decayStart_x() },
	sustainStart_x{ set_sustainStart_x() },
	releaseStart_x{ set_releaseStart_x() },
	releaseEnd_x{ set_releaseEnd_x() },
	sustain_y{ set_sustain_y() }
{
	delay.addListener(this);
	attack.addListener(this);
	decay.addListener(this);
	sustain.addListener(this);
	release.addListener(this);
	auto envelopeRenderer_w{ 210 };
	auto envelopeRenderer_h{ 90 };
	setSize(envelopeRenderer_w, envelopeRenderer_h);
}

EnvelopeRenderer::~EnvelopeRenderer() {
	release.removeListener(this);
	sustain.removeListener(this);
	decay.removeListener(this);
	attack.removeListener(this);
	delay.removeListener(this);
}

void EnvelopeRenderer::sliderValueChanged(Slider* /*slider*/) {
	set_attackStart_x();
	set_decayStart_x();
	set_sustainStart_x();
	set_releaseStart_x();
	set_releaseEnd_x();
	set_sustain_y();
	repaint();
}

float EnvelopeRenderer::set_attackStart_x() {
	attackStart_x = envelopeStart_x + (((float)delay.getValue() / 127.0f) * maxSegment_w);
	return attackStart_x;
}

float EnvelopeRenderer::set_decayStart_x() {
	decayStart_x = attackStart_x + (((float)attack.getValue() / 127.0f) * maxSegment_w);
	return decayStart_x;
}

float EnvelopeRenderer::set_sustainStart_x() {
	sustainStart_x = decayStart_x + (((float)decay.getValue() / 127.0f) * maxSegment_w);
	return sustainStart_x;
}

float EnvelopeRenderer::set_releaseStart_x() {
	releaseStart_x = sustainStart_x + sustainSegment_w;
	return releaseStart_x;
}

float EnvelopeRenderer::set_releaseEnd_x() {
	releaseEnd_x = releaseStart_x + (((float)release.getValue() / 127.0f) * maxSegment_w);
	return releaseEnd_x;
}

float EnvelopeRenderer::set_sustain_y() {
	sustain_y = minimum_y - (((float)sustain.getValue() / 127.0f) * 60.0f);
	return sustain_y;
}

void EnvelopeRenderer::paint(Graphics& g) {
	g.fillAll(Color::black);
	g.setColour(Color::controlText);
	paintBaseline(g);
}

void EnvelopeRenderer::paintBaseline(Graphics& g) {
	Line<float> baseline{ envelopeStart_x, minimum_y, envelopeEnd_x, minimum_y };
	float dashes[2];
	dashes[0] = 5.0f;
	dashes[1] = 5.0f;
	g.drawDashedLine(baseline, dashes, 2);
	paintEnvelope(g);
}

void EnvelopeRenderer::paintEnvelope(Graphics& g) {
	Path path;
	path.startNewSubPath(envelopeStart_x, minimum_y);
	path.lineTo(attackStart_x, minimum_y);
	path.lineTo(decayStart_x, maximum_y);
	path.lineTo(sustainStart_x, sustain_y);
	path.lineTo(releaseStart_x, sustain_y);
	path.lineTo(releaseEnd_x, minimum_y);
	path.lineTo(envelopeEnd_x, minimum_y);
	PathStrokeType strokeType{ 2.0f, PathStrokeType::mitered, PathStrokeType::rounded };
	g.strokePath(path, strokeType);
}
