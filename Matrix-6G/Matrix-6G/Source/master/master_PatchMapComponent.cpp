#include "master_PatchMapComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



PatchMapComponent::PatchMapComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_ForClosingPatchMapComponent{ "" }
{
	button_ForClosingPatchMapComponent.setComponentID(ID::button_X_PatchMap.toString());
	addAndMakeVisible(button_ForClosingPatchMapComponent);
	button_ForClosingPatchMapComponent.onClick = [this] { hideThisComponent(); };
	button_ForClosingPatchMapComponent.setAlwaysOnTop(true);

	setSize(GUI::editor_w, GUI::editor_h);
}

void PatchMapComponent::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::PatchMapWindow_png, BinaryData::PatchMapWindow_pngSize, false };
	PNGImageFormat imageFormat;
	auto windowImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(windowImage, GUI::patchMapWindow_x, GUI::patchMapWindow_y);
}

void PatchMapComponent::resized() {
	button_ForClosingPatchMapComponent.setBounds(GUI::bounds_PatchBanksXbutton);
}

void PatchMapComponent::sliderValueChanged(Slider* slider) {
}

void PatchMapComponent::hideThisComponent() {
	setVisible(false);
}

PatchMapComponent::~PatchMapComponent() {
}
