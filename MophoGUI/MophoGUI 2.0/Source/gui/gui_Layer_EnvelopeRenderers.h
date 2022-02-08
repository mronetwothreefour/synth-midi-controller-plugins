#pragma once

#include <JuceHeader.h>

#include "gui_Constants.h"
#include "../guiRenderers/guiRenderer_ForEnvelopes.h"

using namespace constants;



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
        rendererForEnvelope_LPF.setBounds(GUI::bounds_EnvelopeRenderer_LPF);
        rendererForEnvelope_VCA.setBounds(GUI::bounds_EnvelopeRenderer_VCA);
        rendererForEnvelope_Env3.setBounds(GUI::bounds_EnvelopeRenderer_Env3);
    }

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EnvelopeRenderersLayer)
};