#pragma once

#include <JuceHeader.h>



class FactoryProgramBanks
{
	StringArray factoryProgramBank1;
	StringArray factoryProgramBank2;
	StringArray factoryProgramBank3;

	FactoryProgramBanks();
	void fillAllStringArrays();
	~FactoryProgramBanks();

public:
	FactoryProgramBanks(FactoryProgramBanks&&) = delete;
	FactoryProgramBanks& operator=(FactoryProgramBanks&&) = delete;

	static FactoryProgramBanks& get() noexcept;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FactoryProgramBanks)
};