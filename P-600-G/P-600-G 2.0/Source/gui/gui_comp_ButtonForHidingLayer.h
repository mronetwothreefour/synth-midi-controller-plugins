#pragma once

#include <JuceHeader.h>

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using namespace P_600_G_Constants;

class ButtonForHidingLayer :
	public TextButton,
	public Value::Listener
{
	TooltipsOptions* tooltips;
	Value shouldShowDescriptionAsValue;

public:
	ButtonForHidingLayer() = delete;

	explicit ButtonForHidingLayer(TooltipsOptions* tooltips) :
		tooltips{ tooltips }
	{
		shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
		shouldShowDescriptionAsValue.addListener(this);
		setComponentID(ID::btn_Exit.toString());
		onClick = [this] {
			getParentComponent()->getParentComponent()->grabKeyboardFocus();
			getParentComponent()->setVisible(false);
		};
		addShortcut(KeyPress{ KeyPress::escapeKey });
		updateTooltip();
		setSize(GUI::buttons_w, GUI::buttons_h);
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