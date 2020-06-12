#pragma once

#include <JuceHeader.h>

#include "../core_PluginProcessor.h"

class PublicParameters
{
	std::unique_ptr<AudioProcessorValueTreeState> publicParameters;

	PublicParameters() {}
	~PublicParameters() {}

public:
	void build(AudioProcessor* processor)
	{
		if (publicParameters == nullptr)
		{
			publicParameters.reset
			(new AudioProcessorValueTreeState
				(*processor, nullptr, ID::publicParams,
					{
						std::make_unique<AudioParameterBool>("dingle", "Dingle", false),
						std::make_unique<AudioParameterBool>("dongle", "Dongle", false)
					}
				)
			);
		}
	}

	AudioProcessorValueTreeState* get() { return publicParameters.get(); }
};

class PublicParametersBuilder
{
	static PublicParameters publicParameters;

public:
	static void build(AudioProcessor* processor) { publicParameters.build(processor); }
	static AudioProcessorValueTreeState* get() { return publicParameters.get(); }
};