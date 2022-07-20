#pragma once

#include <JuceHeader.h>



class ExposedParameters;

class LockToggleForParam :
	public ToggleButton,
	public Value::Listener
{
	uint8 paramIndex;
	Value lockStateValue;

public:
	LockToggleForParam() = delete;

	LockToggleForParam(uint8 paramIndex, ExposedParameters* exposedParams);
	void valueChanged(Value& value) override;
	~LockToggleForParam();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LockToggleForParam)
};