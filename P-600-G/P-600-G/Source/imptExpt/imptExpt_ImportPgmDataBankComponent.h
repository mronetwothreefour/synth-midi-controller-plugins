#pragma once

#include <JuceHeader.h>

#include "imptExpt_BaseImptExptComponent.h"



class VoiceSlotsComponent;
class UnexposedParameters;

class ImportProgramDataBankComponent :
	public BaseImportExportComponent
{
public:
	ImportProgramDataBankComponent() = delete;

	ImportProgramDataBankComponent(VoiceSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	void okButtonClicked() override;
	void importProgramDataFromStringArray(StringArray stringArray);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ImportProgramDataBankComponent)
};