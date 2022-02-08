#pragma once

#include <JuceHeader.h>



class FactoryPatchDataHexStrings
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

	FactoryPatchDataHexStrings();
	void fillAllStringArrays();

public:
	FactoryPatchDataHexStrings(FactoryPatchDataHexStrings&&) = delete;
	FactoryPatchDataHexStrings& operator=(FactoryPatchDataHexStrings&&) = delete;

	static FactoryPatchDataHexStrings& get() noexcept;
	int patchSlotOutOfRange();
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
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FactoryPatchDataHexStrings)
};
