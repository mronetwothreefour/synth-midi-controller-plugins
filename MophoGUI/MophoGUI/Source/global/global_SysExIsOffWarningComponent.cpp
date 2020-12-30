#include "global_SysExIsOffWarningComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



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
	g.drawImageAt(backgroundImage, GUI::sysexIsOffWarningWindow_x, GUI::sysexIsOffWarningWindow_y);
}

void SysExIsOffWarningComponent::resized() {
	button_ForClosingComponent.setBounds(GUI::bounds_SysexisOffWarningComponentCloseButton);
	button_ForSendingGlobalParametersDumpRequest.setBounds(GUI::bounds_SysexisOffWarningComponentRetryButton);
}

SysExIsOffWarningComponent::~SysExIsOffWarningComponent() {
}
