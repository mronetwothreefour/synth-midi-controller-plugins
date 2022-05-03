#include "randomization_OptionsComponent_Pitch.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



RandomizationOptionsComponent_Pitch::RandomizationOptionsComponent_Pitch(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams },
	allowedNotes{ paramIndex, unexposedParams },
	allowedOctaves{ paramIndex, unexposedParams },
	repeatValues{ paramIndex, unexposedParams }
{
	addAndMakeVisible(allowedNotes);
	addAndMakeVisible(allowedOctaves);
	addAndMakeVisible(repeatValues);

	button_ForClosingComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingComponent.onClick = [this] { hideThisComponent(); };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions())
		button_ForClosingComponent.setTooltip("Click to close this window.");
	addAndMakeVisible(button_ForClosingComponent);

	auto& info{ InfoForExposedParameters::get() };
	auto controlCenter{ info.controlCenterPointFor(paramIndex) };
	if (controlCenter.x < 1100)
		background_x = controlCenter.x + GUI::knob_diameter;
	else
		background_x = controlCenter.x - GUI::knob_diameter - GUI::randomizationOptionsComponent_Pitch_w;
	if (controlCenter.y < 450)
		background_y = controlCenter.y - GUI::knob_diameter / 2;
	else
		background_y = controlCenter.y - GUI::randomizationOptionsComponent_Pitch_h + GUI::knob_diameter / 2;

	setSize(GUI::editor_w, GUI::editor_h);
}

void RandomizationOptionsComponent_Pitch::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	auto& info{ InfoForExposedParameters::get() };
	auto controlCenter{ info.controlCenterPointFor(paramIndex) };
	g.setColour(Color::switchOn);
	g.drawEllipse((float)controlCenter.x - 20.0f, (float)controlCenter.y - 20.0f, GUI::knob_diameter, GUI::knob_diameter, 2);
	MemoryInputStream memInputStream{ BinaryData::RandomizationOptionsPitchBackground_png, BinaryData::RandomizationOptionsPitchBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, background_x, background_y);
}

void RandomizationOptionsComponent_Pitch::resized() {
	allowedNotes.setBounds(background_x + GUI::randomizationOptionsComponent_Pitch_AllowedNotes_x, background_y + GUI::randomizationOptionsComponent_Pitch_AllowedNotes_y, GUI::randomizationAllowedNotesComponent_w, GUI::randomizationAllowedNotesComponent_h);
	allowedOctaves.setBounds(background_x + GUI::randomizationOptionsComponent_Pitch_AllowedOctaves_x, background_y + GUI::randomizationOptionsComponent_Pitch_AllowedOctaves_y, GUI::randomizationAllowedOctavesComponent_w, GUI::randomizationAllowedOctavesComponent_h);
	repeatValues.setBounds(background_x + GUI::randomizationOptionsComponent_Pitch_RepeatValues_x, background_y + GUI::randomizationOptionsComponent_Pitch_RepeatValues_y, GUI::randomizationRepeatValuesComponents_w, GUI::randomizationRepeatValuesComponents_h);
	button_ForClosingComponent.setBounds(background_x + GUI::randomizationOptionsComponent_Pitch_CloseButton_x, background_y + GUI::randomizationOptionsComponent_Pitch_CloseButton_y, GUI::secondaryWindowsControls_w, GUI::secondaryWindowsControls_h);
}

void RandomizationOptionsComponent_Pitch::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}
