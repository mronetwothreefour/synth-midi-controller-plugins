#pragma once

#include <JuceHeader.h>



class FactoryProgramDataHexStrings
{
	StringArray factoryPgmData;

	FactoryProgramDataHexStrings();
	void fillPgmDataStringArray();

public:
	FactoryProgramDataHexStrings(FactoryProgramDataHexStrings&&) = delete;
	FactoryProgramDataHexStrings& operator=(FactoryProgramDataHexStrings&&) = delete;

	static FactoryProgramDataHexStrings& get() noexcept;
	int pgmSlotOutOfRange();
	const StringArray& getFactoryPgmDataBank();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FactoryProgramDataHexStrings)
};