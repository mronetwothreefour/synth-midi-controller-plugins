#include "master_PatchMapComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



PatchMapComponent::PatchMapComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_ForClosingPatchMapComponent{ "" },
	slotsColumn_0{ unexposedParams, 0},
	slotsColumn_1{ unexposedParams, 10 },
	slotsColumn_2{ unexposedParams, 20 },
	slotsColumn_3{ unexposedParams, 30 },
	slotsColumn_4{ unexposedParams, 40 },
	slotsColumn_5{ unexposedParams, 50 },
	slotsColumn_6{ unexposedParams, 60 },
	slotsColumn_7{ unexposedParams, 70 },
	slotsColumn_8{ unexposedParams, 80 },
	slotsColumn_9{ unexposedParams, 90 }
{
	button_ForClosingPatchMapComponent.setComponentID(ID::button_X_PatchMap.toString());
	addAndMakeVisible(button_ForClosingPatchMapComponent);
	button_ForClosingPatchMapComponent.onClick = [this] { hideThisComponent(); };
	button_ForClosingPatchMapComponent.setAlwaysOnTop(true);

	addAndMakeVisible(slotsColumn_0);
	addAndMakeVisible(slotsColumn_1);
	addAndMakeVisible(slotsColumn_2);
	addAndMakeVisible(slotsColumn_3);
	addAndMakeVisible(slotsColumn_4);
	addAndMakeVisible(slotsColumn_5);
	addAndMakeVisible(slotsColumn_6);
	addAndMakeVisible(slotsColumn_7);
	addAndMakeVisible(slotsColumn_8);
	addAndMakeVisible(slotsColumn_9);

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
	slotsColumn_0.setBounds(GUI::bounds_PatchMapSlotsColumn_0);
	slotsColumn_1.setBounds(GUI::bounds_PatchMapSlotsColumn_1);
	slotsColumn_2.setBounds(GUI::bounds_PatchMapSlotsColumn_2);
	slotsColumn_3.setBounds(GUI::bounds_PatchMapSlotsColumn_3);
	slotsColumn_4.setBounds(GUI::bounds_PatchMapSlotsColumn_4);
	slotsColumn_5.setBounds(GUI::bounds_PatchMapSlotsColumn_5);
	slotsColumn_6.setBounds(GUI::bounds_PatchMapSlotsColumn_6);
	slotsColumn_7.setBounds(GUI::bounds_PatchMapSlotsColumn_7);
	slotsColumn_8.setBounds(GUI::bounds_PatchMapSlotsColumn_8);
	slotsColumn_9.setBounds(GUI::bounds_PatchMapSlotsColumn_9);
}

void PatchMapComponent::hideThisComponent() {
	setVisible(false);
}

