#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;

class ButtonForHidingLayer :
	public TextButton,
	public Value::Listener
{
	TooltipsOptions* tooltips;
	Value shouldShowDescriptionAsValue;

public:
	ButtonForHidingLayer() = delete;

	explicit ButtonForHidingLayer(BorderColor borderColor, UnexposedParameters* unexposedParams) :
		tooltips{ unexposedParams->getTooltipsOptions() }
	{
		shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
		shouldShowDescriptionAsValue.addListener(this);
		switch (borderColor)
		{
		case BorderColor::blue: { setComponentID(ID::btn_X_Blue.toString()); break; }
		case BorderColor::grey: { setComponentID(ID::btn_X_Grey.toString()); break; }
		case BorderColor::orange: { setComponentID(ID::btn_X_Orange.toString()); break; }
		default: break;
		}
		onClick = [this, borderColor, unexposedParams] {
			SysExMessages::addActivateQuickEditMessageToOutgoingBuffers(unexposedParams->getOutgoing_MIDI_Buffers());
			getParentComponent()->getParentComponent()->grabKeyboardFocus();
			getParentComponent()->setVisible(false);
		};
		addShortcut(KeyPress{ KeyPress::escapeKey });
		updateTooltip();
		setSize(18, 18);
	}

	void updateTooltip() {
		setTooltip(tooltips->shouldShowDescription() ? "Click to close this window." : "");
	}

	void valueChanged(Value& /*value*/) override {
		updateTooltip();
	}

	~ButtonForHidingLayer() {
		shouldShowDescriptionAsValue.removeListener(this);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForHidingLayer)
};