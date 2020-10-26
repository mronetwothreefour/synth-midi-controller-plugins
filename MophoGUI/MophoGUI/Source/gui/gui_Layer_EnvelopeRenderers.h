#pragma once

#include <JuceHeader.h>

#include "../guiRenderers/guiRenderer_ForEnvelopes.h"



class EnvelopeRenderersLayer : 
	public Component
{
    RendererForEnvelopes rendererForEnvelope_LPF;
    RendererForEnvelopes rendererForEnvelope_VCA;
    RendererForEnvelopes rendererForEnvelope_Env3;

public:
    EnvelopeRenderersLayer() = delete;

    explicit EnvelopeRenderersLayer(AudioProcessorValueTreeState* exposedParams) :
        rendererForEnvelope_LPF{ "lpf", exposedParams },
        rendererForEnvelope_VCA{ "vca", exposedParams },
        rendererForEnvelope_Env3{ "env3", exposedParams }
    {
        setInterceptsMouseClicks(false, false);
        addAndMakeVisible(rendererForEnvelope_LPF);
        addAndMakeVisible(rendererForEnvelope_VCA);
        addAndMakeVisible(rendererForEnvelope_Env3);
        auto renderers_x{ 168 };
        auto renderersVerticalSpacing{ 158 };
        auto lpfRenderer_y{ 154 };
        auto vcaRenderer_y{ lpfRenderer_y + renderersVerticalSpacing };
        auto env3Renderer_y{ vcaRenderer_y + renderersVerticalSpacing };
        rendererForEnvelope_LPF.setBounds(renderers_x, lpfRenderer_y, rendererForEnvelope_LPF.getWidth(), rendererForEnvelope_LPF.getHeight());
        rendererForEnvelope_VCA.setBounds(renderers_x, vcaRenderer_y, rendererForEnvelope_VCA.getWidth(), rendererForEnvelope_VCA.getHeight());
        rendererForEnvelope_Env3.setBounds(renderers_x, env3Renderer_y, rendererForEnvelope_Env3.getWidth(), rendererForEnvelope_Env3.getHeight());
    }

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EnvelopeRenderersLayer)
};