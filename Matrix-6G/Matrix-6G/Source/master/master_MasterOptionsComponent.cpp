#include "master_MasterOptionsComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



MasterOptionsComponent::MasterOptionsComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_ForClosingMasterOptionsComponent{ "" },
	slider_ForSettingBasicChannel{ unexposedParams },
	comboBox_ForSelectingOmniModeEnabled{ unexposedParams },
	comboBox_ForSelectingControllersEnabled{ unexposedParams },
	comboBox_ForSelectingPatchChangesEnabled{ unexposedParams },
	comboBox_ForSelectingSysExEnabled{ unexposedParams },
	comboBox_ForSelectingSpilloverEnabled{ unexposedParams },
	comboBox_ForSelectingMIDIechoEnabled{ unexposedParams },
	comboBox_ForSelectingMIDImonoEnabled{ unexposedParams },
	button_ForPullingMasterOptionsFromHardware{ unexposedParams }
{
	button_ForClosingMasterOptionsComponent.setComponentID(ID::button_X_Master.toString());
	addAndMakeVisible(button_ForClosingMasterOptionsComponent);
	button_ForClosingMasterOptionsComponent.onClick = [this] { hideThisComponent(); };
	button_ForClosingMasterOptionsComponent.setAlwaysOnTop(true);

	slider_ForSettingBasicChannel.addListener(this);
	addAndMakeVisible(slider_ForSettingBasicChannel);

	comboBox_ForSelectingOmniModeEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingOmniModeEnabled);

	comboBox_ForSelectingControllersEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingControllersEnabled);

	comboBox_ForSelectingPatchChangesEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingPatchChangesEnabled);

	comboBox_ForSelectingSysExEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingSysExEnabled);

	comboBox_ForSelectingSpilloverEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingSpilloverEnabled);

	comboBox_ForSelectingMIDIechoEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingMIDIechoEnabled);

	comboBox_ForSelectingMIDImonoEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingMIDImonoEnabled);

	addAndMakeVisible(button_ForPullingMasterOptionsFromHardware);

	setSize(GUI::editor_w, GUI::editor_h);
}

void MasterOptionsComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	MemoryInputStream memInputStream{ BinaryData::MasterWindow_png, BinaryData::MasterWindow_pngSize, false };
	PNGImageFormat imageFormat;
	auto windowImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(windowImage, GUI::masterOptionsWindow_x, GUI::masterOptionsWindow_y);
}

void MasterOptionsComponent::resized() {
	button_ForClosingMasterOptionsComponent.setBounds(GUI::bounds_MasterOptionsComponentXbutton);
	slider_ForSettingBasicChannel.setBounds(GUI::bounds_MasterOptionsComponentSliderForBasicChannel);
	comboBox_ForSelectingOmniModeEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForOmniMode);
	comboBox_ForSelectingControllersEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForControllers);
	comboBox_ForSelectingPatchChangesEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForPatchChanges);
	comboBox_ForSelectingSysExEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForSysEx);
	comboBox_ForSelectingSpilloverEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForSpillover);
	comboBox_ForSelectingMIDIechoEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForMIDIecho);
	comboBox_ForSelectingMIDImonoEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForMIDImono);
	button_ForPullingMasterOptionsFromHardware.setBounds(GUI::bounds_MasterOptionsComponentPullbutton);
}

void MasterOptionsComponent::comboBoxChanged(ComboBox* comboBox) {
	auto currentSelection{ (uint8)comboBox->getSelectedItemIndex() };
	auto masterOptions{ unexposedParams->masterOptions_get() };
	if (comboBox == &comboBox_ForSelectingOmniModeEnabled)
		masterOptions->setOmniModeEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingControllersEnabled)
		masterOptions->setControllersEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingPatchChangesEnabled)
		masterOptions->setPatchChangesEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingSysExEnabled)
		masterOptions->setSysExEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingSpilloverEnabled)
		masterOptions->setSpilloverEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingMIDIechoEnabled)
		masterOptions->setMIDIechoEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingMIDImonoEnabled)
		masterOptions->setMIDImonoEnabled(currentSelection);
}

void MasterOptionsComponent::sliderValueChanged(Slider* slider) {
	auto masterOptions{ unexposedParams->masterOptions_get() };
	auto currentValue{ (uint8)roundToInt(slider->getValue()) };
	if (slider == &slider_ForSettingBasicChannel)
		masterOptions->setBasicChannel(currentValue);
}

void MasterOptionsComponent::hideThisComponent() {
	setVisible(false);
}

MasterOptionsComponent::~MasterOptionsComponent() {
	comboBox_ForSelectingMIDImonoEnabled.removeListener(this);
	comboBox_ForSelectingMIDIechoEnabled.removeListener(this);
	comboBox_ForSelectingSpilloverEnabled.removeListener(this);
	comboBox_ForSelectingSysExEnabled.removeListener(this);
	comboBox_ForSelectingPatchChangesEnabled.removeListener(this);
	comboBox_ForSelectingControllersEnabled.removeListener(this);
	comboBox_ForSelectingOmniModeEnabled.removeListener(this);
	slider_ForSettingBasicChannel.removeListener(this);
}
