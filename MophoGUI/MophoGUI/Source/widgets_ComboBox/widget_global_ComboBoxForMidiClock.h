#pragma once

#include <JuceHeader.h>


class UnexposedParameters;

class ComboBoxForMidiClock :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ComboBoxForMidiClock() = delete;

	explicit ComboBoxForMidiClock(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~ComboBoxForMidiClock();

private:

};

