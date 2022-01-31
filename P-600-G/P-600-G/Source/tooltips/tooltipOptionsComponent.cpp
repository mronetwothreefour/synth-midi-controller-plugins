#include "tooltipOptionsComponent.h"

#include "tooltips_Constants.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;




TooltipOptionsComponent::TooltipOptionsComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	slider_DescriptionsSwitch{ unexposedParams },
	slider_CurrentSettingsSwitch{ unexposedParams },
	editor_DelayTime{ "tooltipDelayTime", "" }
{
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);

	button_ForClosingTooltipOptions.setComponentID(ID::button_Exit.toString());
	button_ForClosingTooltipOptions.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingTooltipOptions.onClick = [this] { hideThisComponent(); };
	addAndMakeVisible(button_ForClosingTooltipOptions);

	slider_DescriptionsSwitch.setComponentID(ID::component_SwitchSliderDescriptionsTips.toString());
	slider_DescriptionsSwitch.setRange(0.0, 1.0, 1.0);
	slider_DescriptionsSwitch.addListener(this);
	if (tooltipOptions->shouldShowDescriptions())
		slider_DescriptionsSwitch.setValue(1.0, dontSendNotification);
	addAndMakeVisible(slider_DescriptionsSwitch);

	slider_CurrentSettingsSwitch.setComponentID(ID::component_SwitchSliderCurrentSettingsTips.toString());
	slider_CurrentSettingsSwitch.setRange(0.0, 1.0, 1.0);
	slider_CurrentSettingsSwitch.addListener(this);
	if (tooltipOptions->shouldShowCurrentSettings())
		slider_CurrentSettingsSwitch.setValue(1.0, dontSendNotification);
	addAndMakeVisible(slider_CurrentSettingsSwitch);

	editor_DelayTime.addListener(this);
	editor_DelayTime.setEditable(true);
	labelTextChanged(&editor_DelayTime);
	addAndMakeVisible(editor_DelayTime);

	setTooltipsForAllControls();

	setSize(GUI::editor_w, GUI::editor_h);
}

void TooltipOptionsComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	MemoryInputStream memInputStream{ BinaryData::TooltipOptionsWindowBackground_png, BinaryData::TooltipOptionsWindowBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::tooltipOptionsWindow_x, GUI::tooltipOptionsWindow_y);
}

void TooltipOptionsComponent::resized() {
	button_ForClosingTooltipOptions.setBounds(GUI::bounds_TooltipOptionsExitButton);
	slider_DescriptionsSwitch.setBounds(GUI::bounds_TooltipOptionsDescriptionsSwitch);
	slider_CurrentSettingsSwitch.setBounds(GUI::bounds_TooltipOptionsCurrentSettingsSwitch);
	editor_DelayTime.setBounds(GUI::bounds_TooltipOptionsDelayTimeEditor);
}

void TooltipOptionsComponent::editorShown(Label* label, TextEditor& editor) {
	if (label == &editor_DelayTime) {
		editor.setInputRestrictions(GUI::maxNumberOfDigitsInLCDeditor, "0123456789");
		editor.setFont(FontsMenu::fontFor_LCDdisplayEditor);
		auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
		editor.setText((String)tooltipOptions->delayInMilliseconds());
		editor.selectAll();
	}
}

void TooltipOptionsComponent::labelTextChanged(Label* label) {
	if (label == &editor_DelayTime) {
		auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
		if (label->getText().isNotEmpty())
		{
			auto newValue{ label->getText().getIntValue() };
			if (newValue >= tooltips::minDelayTime && newValue <= tooltips::maxDelayTime)
				tooltipOptions->setDelayInMilliseconds(newValue);
		}
		label->setText((String)tooltipOptions->delayInMilliseconds(), dontSendNotification);
	}
}

void TooltipOptionsComponent::sliderValueChanged(Slider* slider) {
	if (slider == &slider_DescriptionsSwitch) {
		auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
		if (slider->getValue() == 1.0)
			tooltipOptions->setShouldShowDescriptions();
		else
			tooltipOptions->setShouldNotShowDescriptions();
	}
	if (slider == &slider_CurrentSettingsSwitch) {
		auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
		if (slider->getValue() == 1.0)
			tooltipOptions->setShouldShowCurrentSettings();
		else
			tooltipOptions->setShouldNotShowCurrentSettings();
	}
}

void TooltipOptionsComponent::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == ID::tooltips_DelayInMilliseconds) {
		MessageManagerLock mmLock;
		editor_DelayTime.setText(tree.getProperty(property), dontSendNotification);
		setTooltipsForAllControls();
	}
	if (property == ID::tooltips_ShouldShowCurrentSettings || property == ID::tooltips_ShouldShowDescriptions)
		setTooltipsForAllControls();
}

void TooltipOptionsComponent::setTooltipsForAllControls() {
	String exitButtonTip{ "" };
	String descriptionsTip{ "" };
	String currentSettingsTip{ "" };
	String delayTimeTip{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		exitButtonTip += "Click to close the Tooltip Options Window.";

		descriptionsTip += "When enabled, a descriptive tooltip will appear if the mouse\n";
		descriptionsTip += "hovers over a control for the amount of time specified below.\n";

		currentSettingsTip += "When enabled, a tooltip with a verbose\n";
		currentSettingsTip += "version of the current setting will appear\n";
		currentSettingsTip += "if the mouse hovers over a control for\n";
		currentSettingsTip += "the amount of time specified below.\n";

		delayTimeTip += "Sets the amount of time (in milliseconds) the mouse cursor\n";
		delayTimeTip += "must hover over a control before a tooltip box is shown.\n";
		delayTimeTip += "Maximum delay: 5000 milliseconds.\n";
	}
	if (tooltipOptions->shouldShowCurrentSettings()) {
		auto converter{ IntToOffOnString::get() };

		auto descriptionsSetting{ (uint8)roundToInt(slider_DescriptionsSwitch.getValue()) };
		descriptionsTip += "Current setting: ";
		descriptionsTip += converter->verboseConvert(descriptionsSetting);

		auto currentSettingsSetting{ (uint8)roundToInt(slider_CurrentSettingsSwitch.getValue()) };
		currentSettingsTip += "Current setting: ";
		currentSettingsTip += converter->verboseConvert(currentSettingsSetting);

		auto delayTimeSetting{ (String)tooltipOptions->delayInMilliseconds() };
		delayTimeTip += "Current setting: " + delayTimeSetting + " milliseconds";
	}
	button_ForClosingTooltipOptions.setTooltip(exitButtonTip);
	slider_DescriptionsSwitch.setTooltip(descriptionsTip);
	slider_CurrentSettingsSwitch.setTooltip(currentSettingsTip);
	editor_DelayTime.setTooltip(delayTimeTip);
}

void TooltipOptionsComponent::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

TooltipOptionsComponent::~TooltipOptionsComponent() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	slider_DescriptionsSwitch.removeListener(this);
	slider_CurrentSettingsSwitch.removeListener(this);
	editor_DelayTime.removeListener(this);
}
