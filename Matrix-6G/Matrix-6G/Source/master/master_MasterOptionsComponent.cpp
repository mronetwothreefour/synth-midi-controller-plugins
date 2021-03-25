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
	button_ForPullingMasterOptionsFromHardware{ unexposedParams }
{
	button_ForClosingMasterOptionsComponent.setComponentID(ID::button_X_Master.toString());
	addAndMakeVisible(button_ForClosingMasterOptionsComponent);
	button_ForClosingMasterOptionsComponent.onClick = [this] { hideThisComponent(); };
	button_ForClosingMasterOptionsComponent.setAlwaysOnTop(true);

	slider_ForSettingBasicChannel.addListener(this);
	addAndMakeVisible(slider_ForSettingBasicChannel);

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
	button_ForPullingMasterOptionsFromHardware.setBounds(GUI::bounds_MasterOptionsComponentPullbutton);
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
	slider_ForSettingBasicChannel.removeListener(this);
}
