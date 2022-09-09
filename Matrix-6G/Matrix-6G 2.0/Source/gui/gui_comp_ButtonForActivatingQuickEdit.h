#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Identifiers.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;

class ButtonForActivatingQuickEdit :
	public TextButton,
	private Timer
{
public:
	ButtonForActivatingQuickEdit() = delete;

	explicit ButtonForActivatingQuickEdit(UnexposedParameters* unexposedParams) {
		setComponentID(ID::btn_ActivateQuickEdit.toString());
		onClick = [this, unexposedParams] {
			SysExMessages::addActivateQuickEditMessageToOutgoingBuffers(unexposedParams->getOutgoing_MIDI_Buffers());
		};
		addShortcut(KeyPress{ 'q', ModifierKeys::ctrlModifier, 0 });
		callAfterDelay(100, [this] { setComponentID(ID::btn_ActivateQuickEdit_Flash.toString()); repaint(); });
		callAfterDelay(200, [this] { setComponentID(ID::btn_ActivateQuickEdit.toString()); repaint(); });
		callAfterDelay(300, [this] { setComponentID(ID::btn_ActivateQuickEdit_Flash.toString()); repaint(); });
		callAfterDelay(400, [this] { setComponentID(ID::btn_ActivateQuickEdit.toString()); repaint(); });
		callAfterDelay(500, [this] { setComponentID(ID::btn_ActivateQuickEdit_Flash.toString()); repaint(); });
		callAfterDelay(600, [this] { setComponentID(ID::btn_ActivateQuickEdit.toString()); repaint(); });
		callAfterDelay(700, [this] { setComponentID(ID::btn_ActivateQuickEdit_Flash.toString()); repaint(); });
		callAfterDelay(800, [this] { setComponentID(ID::btn_ActivateQuickEdit.toString()); repaint(); });
	}

private:
	void timerCallback() override {}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForActivatingQuickEdit)
};