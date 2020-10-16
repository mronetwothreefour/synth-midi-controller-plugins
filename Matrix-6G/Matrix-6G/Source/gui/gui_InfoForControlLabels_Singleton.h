#pragma once

#include <JuceHeader.h>



enum class ControlLabelType {
	subHeader = 0,
	light,
	envShapeControls,
	trackingAndMatrixNumbers
};




class InfoForControlLabels
{
	Array<ControlLabelType> labelTypes;
	Array<String> labelStrings;
	Array<Point<int>> startPoints;
	Array<Point<int>> endPoints;

	InfoForControlLabels();
	void fillAllInfoContainers();

public:
	InfoForControlLabels(InfoForControlLabels&&) = delete;
	InfoForControlLabels& operator=(InfoForControlLabels&&) = delete;

	static InfoForControlLabels& get() noexcept;
	int labelOutOfRange() const noexcept;
	ControlLabelType typeFor(int labelNumber);
	String textFor(int labelNumber);
	Point<int> startPointFor(int labelNumber);
	Point<int> endPointFor(int labelNumber);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForControlLabels)
};

