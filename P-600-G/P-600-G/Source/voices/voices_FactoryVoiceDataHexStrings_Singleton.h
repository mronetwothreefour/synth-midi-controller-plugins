#pragma once

#include <JuceHeader.h>



class FactoryVoiceDataHexStrings
{
	StringArray factoryVoicesData;

	FactoryVoiceDataHexStrings();
	void fillFactoryVoiceDataStringArray();

public:
	FactoryVoiceDataHexStrings(FactoryVoiceDataHexStrings&&) = delete;
	FactoryVoiceDataHexStrings& operator=(FactoryVoiceDataHexStrings&&) = delete;

	static FactoryVoiceDataHexStrings& get() noexcept;
	int slotOutOfRange();
	const StringArray& getFactoryVoicesBank();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FactoryVoiceDataHexStrings)
};