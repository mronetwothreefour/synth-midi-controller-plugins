#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using KnobType = GlobalParamKnobType;

class UnexposedParameters;

class TextEditorForGlobalParamKnob :
	public Component,
	public Value::Listener
{
	KnobType knobType;
	Label textEditor;
	Value globalParamAsValue;

public:
	TextEditorForGlobalParamKnob() = delete;

	TextEditorForGlobalParamKnob(KnobType knobType, UnexposedParameters* unexposedParams);

private:
	void setEditorTextUsingStoredValue();

public:
	void showEditor();
	void valueChanged(Value& value) override;
	~TextEditorForGlobalParamKnob();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextEditorForGlobalParamKnob)
};