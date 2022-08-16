#pragma once

#include <JuceHeader.h>

class MatrixModOptions
{
	ValueTree matrixModOptionsTree;
	UndoManager* undoManager;

public:
	MatrixModOptions() = delete;

	explicit MatrixModOptions(UndoManager* undoManager);

	const uint8 modSource(int modNum);
	void setModSource(int modNum, uint8 newSource);

	const uint8 modAmount(int modNum);
	void setModAmount(int modNum, uint8 newAmount);

	const uint8 modDest(int modNum);
	void setModDest(int modNum, uint8 newDest);

	Value getMatrixModPropertyAsValue(const Identifier propertyID);

	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MatrixModOptions)
};