#pragma once

#include <JuceHeader.h>

#include "../guiRenderers/guiRenderer_Envelopes.h"
#include "../guiRenderers/guiRenderer_Tracking.h"



class EnvelopeRenderersLayer :
    public Component
{
    RendererForEnvelopes rendererForEnvelope_Env1;
    RendererForEnvelopes rendererForEnvelope_Env2;
    RendererForEnvelopes rendererForEnvelope_Env3;
    RendererForTrackingGenerator rendererForTrackingGenerator;

public:
    EnvelopeRenderersLayer() = delete;

    explicit EnvelopeRenderersLayer(AudioProcessorValueTreeState* exposedParams) :
        rendererForEnvelope_Env1{ 1, exposedParams },
        rendererForEnvelope_Env2{ 2, exposedParams },
        rendererForEnvelope_Env3{ 3, exposedParams },
        rendererForTrackingGenerator{ exposedParams }
    {
        setInterceptsMouseClicks(false, false);
        addAndMakeVisible(rendererForEnvelope_Env1);
        addAndMakeVisible(rendererForEnvelope_Env2);
        addAndMakeVisible(rendererForEnvelope_Env3);
        addAndMakeVisible(rendererForTrackingGenerator);
        auto renderersHorizontalSpacing{ 410 };
        auto env1Renderer_x{ 184 };
        auto env2Renderer_x{ env1Renderer_x + renderersHorizontalSpacing };
        auto env3Renderer_x{ env2Renderer_x + renderersHorizontalSpacing };
        auto envelopeRenderers_y{ 408 };
        auto envelopeRenderers_w{ rendererForEnvelope_Env1.getWidth() };
        auto envelopeRenderers_h{ rendererForEnvelope_Env1.getHeight() };
        rendererForEnvelope_Env1.setBounds(env1Renderer_x, envelopeRenderers_y, envelopeRenderers_w, envelopeRenderers_h);
        rendererForEnvelope_Env2.setBounds(env2Renderer_x, envelopeRenderers_y, envelopeRenderers_w, envelopeRenderers_h);
        rendererForEnvelope_Env3.setBounds(env3Renderer_x, envelopeRenderers_y, envelopeRenderers_w, envelopeRenderers_h);
        auto trackingRenderer_x{ 840 };
        auto trackingRenderer_y{ 183 };
        auto trackingRenderer_w{ rendererForTrackingGenerator.getWidth() };
        auto trackingRenderer_h{ rendererForTrackingGenerator.getHeight() };
        rendererForTrackingGenerator.setBounds(trackingRenderer_x, trackingRenderer_y, trackingRenderer_w, trackingRenderer_h);
        setSize(1252, 596);
    }

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EnvelopeRenderersLayer)
};