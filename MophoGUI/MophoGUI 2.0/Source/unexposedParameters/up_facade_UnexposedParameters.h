#pragma once

#include <JuceHeader.h>

#include "up_tree_TooltipsOptions.h"



class UnexposedParameters
{
	std::unique_ptr<TooltipsOptions> tooltipsOptions;
	std::unique_ptr<UndoManager> undoManager;

public:
	UnexposedParameters();
	TooltipsOptions* getTooltipsOptions();
	UndoManager* getUndoManager();
	XmlElement getStateXml();
	void replaceState(const ValueTree& newState);
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)

};