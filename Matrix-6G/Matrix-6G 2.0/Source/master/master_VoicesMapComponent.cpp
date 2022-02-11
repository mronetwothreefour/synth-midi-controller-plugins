#include "master_VoicesMapComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_Constants.h"

using namespace constants;



VoicesMapComponent::VoicesMapComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_ForClosingVoicesMapComponent{ "" },
	button_ForResettingVoicesMap{ "" },
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
	button_ForClosingVoicesMapComponent.setComponentID(ID::button_X_VoicesMap.toString());
	addAndMakeVisible(button_ForClosingVoicesMapComponent);
	button_ForClosingVoicesMapComponent.onClick = [this] { hideThisComponent(); };
	button_ForClosingVoicesMapComponent.setAlwaysOnTop(true);

	button_ForResettingVoicesMap.setComponentID(ID::button_Reset.toString());
	addAndMakeVisible(button_ForResettingVoicesMap);
	auto masterOptions{ unexposedParams->masterOptions_get() };
	button_ForResettingVoicesMap.onClick = [this, masterOptions] { masterOptions->resetVoicesMap(); };
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Resets the Patch Map to the default state.\n";
		tooltipText += "NOTE: Changes to the Patch Map will not\n";
		tooltipText += "be updated on the hardware until the PUSH\n";
		tooltipText += "button in the Master window is clicked.\n";
	}
	button_ForResettingVoicesMap.setTooltip(tooltipText);

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

void VoicesMapComponent::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::PatchMapWindow_png, BinaryData::PatchMapWindow_pngSize, false };
	PNGImageFormat imageFormat;
	auto windowImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(windowImage, GUI::voicesMapWindow_x, GUI::voicesMapWindow_y);
}

void VoicesMapComponent::resized() {
	button_ForClosingVoicesMapComponent.setBounds(GUI::bounds_VoicesMapComponentXbutton);
	button_ForResettingVoicesMap.setBounds(GUI::bounds_VoicesMapResetButton);
	slotsColumn_0.setBounds(GUI::bounds_VoicesMapSlotsColumn_0);
	slotsColumn_1.setBounds(GUI::bounds_VoicesMapSlotsColumn_1);
	slotsColumn_2.setBounds(GUI::bounds_VoicesMapSlotsColumn_2);
	slotsColumn_3.setBounds(GUI::bounds_VoicesMapSlotsColumn_3);
	slotsColumn_4.setBounds(GUI::bounds_VoicesMapSlotsColumn_4);
	slotsColumn_5.setBounds(GUI::bounds_VoicesMapSlotsColumn_5);
	slotsColumn_6.setBounds(GUI::bounds_VoicesMapSlotsColumn_6);
	slotsColumn_7.setBounds(GUI::bounds_VoicesMapSlotsColumn_7);
	slotsColumn_8.setBounds(GUI::bounds_VoicesMapSlotsColumn_8);
	slotsColumn_9.setBounds(GUI::bounds_VoicesMapSlotsColumn_9);
}

void VoicesMapComponent::hideThisComponent() {
	setVisible(false);
}


