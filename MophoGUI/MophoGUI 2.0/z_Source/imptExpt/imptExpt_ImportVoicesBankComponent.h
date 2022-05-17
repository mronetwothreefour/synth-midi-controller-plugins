#pragma once

#include <JuceHeader.h>

#include "imptExpt_BaseImptExptComponent.h"



class VoiceSlotsComponent;
class UnexposedParameters;

class ImportVoicesBankComponent :
	public BaseImportExportComponent
{
public:
	ImportVoicesBankComponent() = delete;

	ImportVoicesBankComponent(VoicesBank bank, VoiceSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	void okButtonClicked() override;
	void importVoiceDataFromStringArray(StringArray stringArray);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ImportVoicesBankComponent)
};