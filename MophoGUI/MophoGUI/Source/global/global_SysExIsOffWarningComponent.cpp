#include "global_SysExIsOffWarningComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"



SysExIsOffWarningComponent::SysExIsOffWarningComponent(UnexposedParameters* unexposedParams) :
	HardwareSettingsWarningComponent{ unexposedParams }
{
	addButtonsToComponent();
	resized();
}

void SysExIsOffWarningComponent::checkHardwareSettings() {
	auto midiOptions{ unexposedParams->midiOptions_get() };
	if (midiOptions->sysExIsOn())
		hideThisComponent();
}

void SysExIsOffWarningComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::NoSysexWarningBackground_png, BinaryData::NoSysexWarningBackground_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 386, 143);
}

void SysExIsOffWarningComponent::resized() {
	auto button_h{ 22 };
	button_ForClosingComponent.setBounds(830, 150, 50, button_h);
	button_ForSendingGlobalParametersDumpRequest.setBounds(611, 449, 51, button_h);
}

SysExIsOffWarningComponent::~SysExIsOffWarningComponent() {
}
