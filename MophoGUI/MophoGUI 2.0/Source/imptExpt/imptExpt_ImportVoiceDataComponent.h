#pragma once

#include <JuceHeader.h>

#include "imptExpt_BaseImptExptComponent.h"



class VoiceSlotsComponent;
class UnexposedParameters;

class ImportVoiceDataComponent :
	public BaseImportExportComponent
{
public:
	ImportVoiceDataComponent() = delete;

	ImportVoiceDataComponent(VoicesBank bank, VoiceSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	void okButtonClicked() override;
	void importVoiceDataFromString(String incomingString);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ImportVoiceDataComponent)
};