#include "global_GlobalParametersComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../midi/midi_NRPNbufferWithLeadingMSBs.h"
#include "../params/params_UnexposedParameters_Facade.h"



GlobalParametersComponent::GlobalParametersComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	nrpnType_SysExOn{ 395 },
	button_ForClosingGlobalParameters{ "CLOSE" },
	toggle_ForSysEx{ unexposedParams }
{
	addAndMakeVisible(button_ForClosingGlobalParameters);
	button_ForClosingGlobalParameters.onClick = [this] { hideThisComponent(); };

	addAndMakeVisible(toggle_ForSysEx);
	toggle_ForSysEx.addListener(this);

	setSize(1273, 626);
}

void GlobalParametersComponent::hideThisComponent() {
	setVisible(false);
}

void GlobalParametersComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	g.setColour(Color::black);
	auto componentOutline_w{ 245 };
	auto componentOutline_h{ 378 };
	auto componentOutline_x{ (getWidth() - componentOutline_w) / 2 };
	auto componentOutline_y{ (getHeight() - componentOutline_h) / 2 };
	Rectangle<int> componentOutline{ componentOutline_x, componentOutline_y, componentOutline_w, componentOutline_h };
	g.fillRect(componentOutline);
	g.setColour(Color::device);
	auto componentBackground{ componentOutline.reduced(2, 2) };
	g.fillRect(componentBackground);
}

void GlobalParametersComponent::resized() {
	button_ForClosingGlobalParameters.setBounds(703, 130, 50, 21);
	auto togglesDiameter{ 14 };
	auto toggles_x{ 673 };
	toggle_ForSysEx.setBounds(toggles_x, 297, togglesDiameter, togglesDiameter);
}

void GlobalParametersComponent::buttonClicked(Button* button) {
	if (button == &toggle_ForSysEx) {
		auto stateIsOn{ button->getToggleState() };
		auto midiOptions{ unexposedParams->midiOptions_get() };
		if (stateIsOn)
			midiOptions->setSysExOn();
		else
			midiOptions->setSysExOff();
		auto channel{ midiOptions->transmitChannel() };
		auto nrpnBuffer{ NRPNbufferWithLeadingMSBs::from_Channel_NRPNtype_NewValue(channel, nrpnType_SysExOn, stateIsOn ? 1 : 0) };
		auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
		outgoingMidiBuffers->aggregateOutgoingMidiBuffers(nrpnBuffer);
	}
}

void GlobalParametersComponent::comboBoxChanged(ComboBox* comboBox) {
}

void GlobalParametersComponent::editorShown(Label* label, TextEditor& editor) {
}

void GlobalParametersComponent::labelTextChanged(Label* label) {
}

void GlobalParametersComponent::sliderValueChanged(Slider* slider) {
}

void GlobalParametersComponent::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
}

void GlobalParametersComponent::timerCallback() {
}

GlobalParametersComponent::~GlobalParametersComponent() {
	toggle_ForSysEx.removeListener(this);
}
