#include "splits_SplitsComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../midi/midi_SysExHelpers.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



SplitsComponent::SplitsComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_ForClosingSplitsComponent{ "" }
{
	setSize(GUI::editor_w, GUI::editor_h);

	button_ForClosingSplitsComponent.setComponentID(ID::button_X_Splits.toString());
	addAndMakeVisible(button_ForClosingSplitsComponent);
	button_ForClosingSplitsComponent.setBounds(GUI::bounds_SplitsComponentXbutton);
	button_ForClosingSplitsComponent.onClick = [this] { hideThisComponent(); };
	button_ForClosingSplitsComponent.setAlwaysOnTop(true);
}

void SplitsComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	MemoryInputStream memInputStream{ BinaryData::SplitsWindow_png, BinaryData::SplitsWindow_pngSize, false };
	PNGImageFormat imageFormat;
	auto windowImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(windowImage, GUI::splitsWindow_x, GUI::splitsWindow_y);
}

void SplitsComponent::buttonClicked(Button* button) {
}

void SplitsComponent::hideThisComponent() {
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	auto activateQuickPatchEditingMessage{ RawSysExDataVector::createActivateQuickPatchEditingMessage() };
	outgoingMidiBuffers->addDataMessage(activateQuickPatchEditingMessage);
	setVisible(false);
}

SplitsComponent::~SplitsComponent() {
}
