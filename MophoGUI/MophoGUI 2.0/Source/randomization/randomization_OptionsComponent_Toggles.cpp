#include "randomization_OptionsComponent_Toggles.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



RandomizationOptionsComponent_Toggles::RandomizationOptionsComponent_Toggles(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	repeatValues{ paramIndex, unexposedParams }
{
	addAndMakeVisible(repeatValues);

	auto& info{ InfoForExposedParameters::get() };
	auto controlCenter{ info.controlCenterPointFor(paramIndex) };

	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	button_ForClosingComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingComponent.onClick = [this] { hideThisComponent(); };
	if (shouldShowDescriptions)
		button_ForClosingComponent.setTooltip("Click to close this window.");
	addAndMakeVisible(button_ForClosingComponent);

	background_x = controlCenter.x + 20;
	background_y = controlCenter.y - GUI::toggle_diameter / 2;

	setSize(GUI::editor_w, GUI::editor_h);
}

void RandomizationOptionsComponent_Toggles::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	auto& info{ InfoForExposedParameters::get() };
	auto controlCenter{ info.controlCenterPointFor(paramIndex) };
	g.setColour(Color::switchOn);
	g.drawEllipse((float)controlCenter.x - 11.0f, (float)controlCenter.y - 11.0f, GUI::toggleLockButton_diameter, GUI::toggleLockButton_diameter, 2);
	MemoryInputStream memInputStream{ BinaryData::RandomizationOptionsTogglesBackground_png, BinaryData::RandomizationOptionsTogglesBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, background_x, background_y);
}

void RandomizationOptionsComponent_Toggles::resized() {
	repeatValues.setBounds(background_x + GUI::randomizationOptionsComponent_Toggle_RepeatValues_x, background_y + GUI::randomizationOptionsComponent_Toggle_RepeatValues_y, GUI::randomizationRepeatValuesComponents_w, GUI::randomizationRepeatValuesComponents_h);
	button_ForClosingComponent.setBounds(background_x + GUI::randomizationOptionsComponent_Toggle_CloseButton_x, background_y + GUI::randomizationOptionsComponent_Toggle_CloseButton_y, GUI::secondaryWindowsControls_w, GUI::secondaryWindowsControls_h);
}

void RandomizationOptionsComponent_Toggles::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}
