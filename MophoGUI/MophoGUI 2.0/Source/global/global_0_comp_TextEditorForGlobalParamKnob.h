#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using KnobType = GlobalParamKnobType;

class GlobalOptions;
class UnexposedParameters;

class TextEditorForGlobalParamKnob :
	public Component,
	public Value::Listener
{
	KnobType knobType;
	Label textEditor;
	Value globalParamValue;

public:
	TextEditorForGlobalParamKnob() = delete;

	TextEditorForGlobalParamKnob(KnobType knobType, UnexposedParameters* unexposedParams);
	void setEditorText();
	void showEditor();
	void valueChanged(Value& value) override;
	~TextEditorForGlobalParamKnob();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextEditorForGlobalParamKnob)
};