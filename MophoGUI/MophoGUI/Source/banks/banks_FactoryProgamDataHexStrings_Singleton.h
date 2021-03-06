#pragma once

#include <JuceHeader.h>



class FactoryProgramDataHexStrings
{
	StringArray bank1;
	StringArray bank2;
	StringArray bank3;

	FactoryProgramDataHexStrings();
	void fillAllStringArrays();

public:
	FactoryProgramDataHexStrings(FactoryProgramDataHexStrings&&) = delete;
	FactoryProgramDataHexStrings& operator=(FactoryProgramDataHexStrings&&) = delete;

	static FactoryProgramDataHexStrings& get() noexcept;
	const StringArray& getBank1();
	const StringArray& getBank2();
	const StringArray& getBank3();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FactoryProgramDataHexStrings)
};