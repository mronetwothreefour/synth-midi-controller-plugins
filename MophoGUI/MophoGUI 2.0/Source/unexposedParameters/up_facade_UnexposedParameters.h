#pragma once

#include <JuceHeader.h>



class UnexposedParameters
{
	std::unique_ptr<UndoManager> undoManager;

public:
	UnexposedParameters();
	UndoManager* getUndoManager();
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)

};