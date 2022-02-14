#pragma once

#include <JuceHeader.h>

#include "imptExpt_BaseImptExptComponent.h"



class VoiceSlotsComponent;
class UnexposedParameters;

class ImportProgramDataComponent :
	public BaseImportExportComponent
{
public:
	ImportProgramDataComponent() = delete;

	ImportProgramDataComponent(VoiceSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	void okButtonClicked() override;
	void importProgramDataFromString(String incomingString);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ImportProgramDataComponent)
};