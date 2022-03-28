#include "randomization_OscillatorOptionsComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



OscillatorRandomizationOptionsComponent::OscillatorRandomizationOptionsComponent(UnexposedParameters* unexposedParams) :
	allowedNotesForOsc1{ 1, unexposedParams },
	allowedOctavesForOsc1{ 1, unexposedParams },
	allowedNotesForOsc2{ 2, unexposedParams },
	allowedOctavesForOsc2{ 2, unexposedParams }
{
	addAndMakeVisible(allowedNotesForOsc1);
	addAndMakeVisible(allowedOctavesForOsc1);
	addAndMakeVisible(allowedNotesForOsc2);
	addAndMakeVisible(allowedOctavesForOsc2);

	button_ForClosingOscOptionsComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingOscOptionsComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingOscOptionsComponent.onClick = [this] { hideThisComponent(); };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions())
		button_ForClosingOscOptionsComponent.setTooltip("Click to close this window.");
	addAndMakeVisible(button_ForClosingOscOptionsComponent);

	setSize(GUI::editor_w, GUI::editor_h);
}

void OscillatorRandomizationOptionsComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	MemoryInputStream memInputStream{ BinaryData::RandomizationOscOptionsBackground_png, BinaryData::RandomizationOscOptionsBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::randomizationOscOptionsBackground_x, GUI::randomizationOscOptionsBackground_y);
}

void OscillatorRandomizationOptionsComponent::resized() {
	allowedNotesForOsc1.setBounds(GUI::bounds_RandomizationAllowedNotesForOsc1);
	allowedOctavesForOsc1.setBounds(GUI::bounds_RandomizationAllowedOctavesForOsc1);
	allowedNotesForOsc2.setBounds(GUI::bounds_RandomizationAllowedNotesForOsc2);
	allowedOctavesForOsc2.setBounds(GUI::bounds_RandomizationAllowedOctavesForOsc2);
	button_ForClosingOscOptionsComponent.setBounds(GUI::bounds_RandomizationOscOptionsCloseButton);
}

void OscillatorRandomizationOptionsComponent::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}
