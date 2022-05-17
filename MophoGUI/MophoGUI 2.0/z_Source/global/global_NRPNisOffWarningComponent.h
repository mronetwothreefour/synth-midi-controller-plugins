#pragma once

#include <JuceHeader.h>

#include "global_HardwareSettingsWarningComponent.h"



class UnexposedParameters;

class NRPNisOffWarningComponent :
	public HardwareSettingsWarningComponent
{
public:
	NRPNisOffWarningComponent() = delete;

	explicit NRPNisOffWarningComponent(UnexposedParameters* unexposedParams);

private:
	void checkHardwareSettings() override;

public:
	void paint(Graphics& g) override;
	void resized() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NRPNisOffWarningComponent)
};

