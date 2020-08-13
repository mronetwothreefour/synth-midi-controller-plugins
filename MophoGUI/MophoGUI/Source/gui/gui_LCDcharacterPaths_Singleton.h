#pragma once

#include <JuceHeader.h>



class LCDcharacterPaths
{
	Array<Path> characterPaths;

	LCDcharacterPaths();
	void fillCharacterPaths();

public:
	LCDcharacterPaths(LCDcharacterPaths&&) = delete;
	LCDcharacterPaths& operator=(LCDcharacterPaths&&) = delete;

	static LCDcharacterPaths& get() noexcept;
	Path getPathForChar(uint8 charNum);
	~LCDcharacterPaths();
	
private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LCDcharacterPaths)
};