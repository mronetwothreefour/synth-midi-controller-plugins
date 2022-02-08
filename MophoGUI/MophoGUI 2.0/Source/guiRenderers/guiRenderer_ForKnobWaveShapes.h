#pragma once

#include <JuceHeader.h>



class RendererForKnobWaveShapes :
	public Component,
	public Slider::Listener
{
	Slider* knob;
	enum class OscWaveShape { off, sawtooth, triangle, sawTriMix, pulse };

public:
	RendererForKnobWaveShapes() = delete;

	explicit RendererForKnobWaveShapes(Slider* knob);
	void sliderValueChanged(Slider* slider) override;
	void paint(Graphics& g) override;
	void paintText(Graphics& g, String text);
	void paintSawtooth(Graphics& g, Path path, PathStrokeType strokeType);
	void paintTriangle(Graphics& g, Path path, PathStrokeType strokeType);
	void paintSawTriMix(Graphics& g, Path path, PathStrokeType strokeType);
	void paintPulse(Graphics& g, Path path, PathStrokeType strokeType, int pulseWidth);
	~RendererForKnobWaveShapes() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RendererForKnobWaveShapes)
};
