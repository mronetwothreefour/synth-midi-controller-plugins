#include "guiRenderer_Envelopes.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"

using namespace constants;



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
	setSize(GUI::envelopeRenderers_w, GUI::envelopeRenderers_h);
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
	attackStart_x = GUI::envelopeStart_x + (((float)delay.getValue() / 63.0f) * GUI::envelopeMaxSegment_w);
}

void RendererForEnvelopes::set_decayStart_x() {
	decayStart_x = attackStart_x + (((float)attack.getValue() / 63.0f) * GUI::envelopeMaxSegment_w);
}

void RendererForEnvelopes::set_sustainStart_x() {
	sustainStart_x = decayStart_x + (((float)decay.getValue() / 63.0f) * GUI::envelopeMaxSegment_w);
}

void RendererForEnvelopes::set_releaseStart_x() {
	releaseStart_x = sustainStart_x + GUI::envelopeSustainSegment_w;
}

void RendererForEnvelopes::set_releaseEnd_x() {
	releaseEnd_x = releaseStart_x + (((float)release.getValue() / 63.0f) * GUI::envelopeMaxSegment_w);
}

void RendererForEnvelopes::set_sustain_y() {
	sustain_y = GUI::envelopeMinimum_y - (((float)sustain.getValue() / 63.0f) * GUI::envelope_h);
}

void RendererForEnvelopes::paint(Graphics& g) {
	g.setColour(Color::led_blue);
	Path path;
	path.startNewSubPath(GUI::envelopeStart_x, GUI::envelopeMinimum_y);
	path.lineTo(attackStart_x, GUI::envelopeMinimum_y);
	path.lineTo(decayStart_x, GUI::envelopeMaximum_y);
	path.lineTo(sustainStart_x, sustain_y);
	path.lineTo(releaseStart_x, sustain_y);
	path.lineTo(releaseEnd_x, GUI::envelopeMinimum_y);
	path.lineTo(GUI::envelopeEnd_x, GUI::envelopeMinimum_y);
	g.strokePath(path, GUI::envelopeStrokeType);
}

RendererForEnvelopes::~RendererForEnvelopes() {
	release.removeListener(this);
	sustain.removeListener(this);
	decay.removeListener(this);
	attack.removeListener(this);
	delay.removeListener(this);
}
