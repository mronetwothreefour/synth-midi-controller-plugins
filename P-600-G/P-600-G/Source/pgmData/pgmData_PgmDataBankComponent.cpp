#include "pgmData_PgmDataBankComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;




ProgramDataBankComponent::ProgramDataBankComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	slotsComponent{ exposedParams, unexposedParams }
{
	addAndMakeVisible(slotsComponent);

	addAndMakeVisible(button_ForClosingPgmDataBank);
	button_ForClosingPgmDataBank.setComponentID(ID::button_Exit.toString());
	button_ForClosingPgmDataBank.onClick = [this] { hideThisComponent(); };

	setSize(GUI::editor_w, GUI::editor_h);
}

void ProgramDataBankComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	MemoryInputStream memInputStream{ BinaryData::PgmBankWindowBackground_png, BinaryData::PgmBankWindowBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::pgmDataBankWindowInset_x, GUI::pgmDataBankWindowInset_y);
}

void ProgramDataBankComponent::resized() {
	button_ForClosingPgmDataBank.setBounds(GUI::bounds_PgmDataBankWindowExitButton);
	slotsComponent.setBounds(GUI::bounds_PgmDataSlotsComponent);
}

void ProgramDataBankComponent::buttonClicked(Button* /*button*/) {
}

void ProgramDataBankComponent::hideThisComponent() {
	setVisible(false);
}

ProgramDataBankComponent::~ProgramDataBankComponent() {
}
