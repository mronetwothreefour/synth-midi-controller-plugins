#pragma once

#include <JuceHeader.h>



class FactoryVoiceDataHexStrings
{
	StringArray analogSynthsBankA;
	StringArray analogSynthsBankB;
	StringArray bassesBank;
	StringArray brassAndWoodwindsBank;
	StringArray fxAndPercussionBank;
	StringArray keyboardsBankA;
	StringArray keyboardsBankB;
	StringArray leadsBank;
	StringArray stringsBank;
	StringArray miscellaneousBankA;
	StringArray miscellaneousBankB;

	FactoryVoiceDataHexStrings();
	void fillAllStringArrays();

public:
	FactoryVoiceDataHexStrings(FactoryVoiceDataHexStrings&&) = delete;
	FactoryVoiceDataHexStrings& operator=(FactoryVoiceDataHexStrings&&) = delete;

	static FactoryVoiceDataHexStrings& get() noexcept;
	int slotOutOfRange();
	const StringArray& getAnalogSynthsBankA();
	const StringArray& getAnalogSynthsBankB();
	const StringArray& getBassesBank();
	const StringArray& getBrassAndWoodwindsBank();
	const StringArray& getFXandPercussionBank();
	const StringArray& getKeyboardsBankA();
	const StringArray& getKeyboardsBankB();
	const StringArray& getLeadsBank();
	const StringArray& getStringsBank();
	const StringArray& getMiscellaneousBankA();
	const StringArray& getMiscellaneousBankB();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FactoryVoiceDataHexStrings)
};
