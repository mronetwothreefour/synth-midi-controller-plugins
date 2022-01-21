#include "imptExpt_ExportPgmDataComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../pgmData/pgmData_PgmDataSlotsComponent.h"

using namespace constants;



ExportProgramDataComponent::ExportProgramDataComponent(ProgramDataSlotsComponent& slotsComponent, UnexposedParameters* unexposedParams) :
	slotsComponent{ slotsComponent },
	unexposedParams{ unexposedParams }
{
	auto browserFlags{ FileBrowserComponent::saveMode | FileBrowserComponent::canSelectFiles | FileBrowserComponent::warnAboutOverwriting | FileBrowserComponent::doNotClearFileNameOnRootChange };
	browserComponent.reset(new FileBrowserComponent(browserFlags, File::getSpecialLocation(File::userDocumentsDirectory), &pgmDataFileFilter, nullptr));
	if (browserComponent != nullptr) {
		addAndMakeVisible(browserComponent.get());
		browserComponent->addListener(this);
	}

	addAndMakeVisible(button_NewFolder);
	button_NewFolder.setComponentID(ID::button_NewFldr.toString());
	button_NewFolder.onClick = [this] { createNewFolder(); };

	addAndMakeVisible(button_Esc);
	button_Esc.setComponentID(ID::button_Esc.toString());
	button_Esc.addShortcut(KeyPress(KeyPress::escapeKey));
	button_Esc.onClick = [this] { hideThisComponent(); };

	addAndMakeVisible(button_OK);
	button_OK.setComponentID(ID::button_OK.toString());
	button_OK.addShortcut(KeyPress(KeyPress::returnKey));
	button_OK.onClick = [this] { okButtonClicked(); };

	setSize(GUI::editor_w, GUI::editor_h);
}

void ExportProgramDataComponent::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_PgmBankWindow);
	g.setOpacity(1.0f);
	MemoryInputStream memInputStream{ BinaryData::ImportExportWindowBackground_png, BinaryData::ImportExportWindowBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::imptExptWindow_x, GUI::imptExptWindow_y);
}

void ExportProgramDataComponent::resized() {
	browserComponent->setBounds(GUI::bounds_ImptExptWindowBrowserComponent);
	button_NewFolder.setBounds(GUI::bounds_ImptExptWindowNewFldrButton);
	button_Esc.setBounds(GUI::bounds_ImptExptWindowEscButton);
	button_OK.setBounds(GUI::bounds_ImptExptWindowOKbutton);
}

void ExportProgramDataComponent::selectionChanged()
{
}

void ExportProgramDataComponent::fileClicked(const File&, const MouseEvent&) {
}

void ExportProgramDataComponent::fileDoubleClicked(const File&) {
}

void ExportProgramDataComponent::browserRootChanged(const File&) {
}

void ExportProgramDataComponent::createNewFolder() {
}

void ExportProgramDataComponent::okButtonClicked() {
}

void ExportProgramDataComponent::hideThisComponent() {
	setVisible(false);
}

ExportProgramDataComponent::~ExportProgramDataComponent() {
	if (browserComponent != nullptr) {
		browserComponent->removeListener(this);
		browserComponent = nullptr;
	}
}
