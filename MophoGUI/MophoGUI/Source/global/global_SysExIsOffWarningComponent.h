#pragma once

#include <JuceHeader.h>

#include "global_HardwareSettingsWarningComponent.h"



class UnexposedParameters;

class SysExIsOffWarningComponent :
	public HardwareSettingsWarningComponent
{
public:
	SysExIsOffWarningComponent() = delete;

	explicit SysExIsOffWarningComponent(UnexposedParameters* unexposedParams);

private:
	void checkHardwareSettings() override;

public:
	void paint(Graphics& g) override;
	void resized() override;
	~SysExIsOffWarningComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SysExIsOffWarningComponent)
};

