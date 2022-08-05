#pragma once

#include <JuceHeader.h>

#include "gui_Constants.h"
#include "../guiRenderers/guiRenderer_Envelopes.h"
#include "../guiRenderers/guiRenderer_Tracking.h"

using namespace constants;



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
        rendererForEnvelope_Env1.setBounds(GUI::env1Renderer_x, GUI::envelopeRenderers_y, GUI::envelopeRenderers_w, GUI::envelopeRenderers_h);
        rendererForEnvelope_Env2.setBounds(GUI::env2Renderer_x, GUI::envelopeRenderers_y, GUI::envelopeRenderers_w, GUI::envelopeRenderers_h);
        rendererForEnvelope_Env3.setBounds(GUI::env3Renderer_x, GUI::envelopeRenderers_y, GUI::envelopeRenderers_w, GUI::envelopeRenderers_h);
        rendererForTrackingGenerator.setBounds(GUI::trackingGeneratorRenderer_x, GUI::trackingGeneratorRenderer_y, GUI::trackingGeneratorRenderer_w, GUI::trackingGeneratorRenderer_h);
        setSize(GUI::editor_w, GUI::editor_h);
    }

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EnvelopeRenderersLayer)
};