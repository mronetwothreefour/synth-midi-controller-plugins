#pragma once

#include <JuceHeader.h>



class FactoryVoiceDataHexStrings
{
	StringArray bank1;
	StringArray bank2;
	StringArray bank3;

	FactoryVoiceDataHexStrings();
	void fillAllStringArrays();

public:
	FactoryVoiceDataHexStrings(FactoryVoiceDataHexStrings&&) = delete;
	FactoryVoiceDataHexStrings& operator=(FactoryVoiceDataHexStrings&&) = delete;

	static FactoryVoiceDataHexStrings& get() noexcept;
	const StringArray& getBank1();
	const StringArray& getBank2();
	const StringArray& getBank3();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FactoryVoiceDataHexStrings)
};