#include "gui_Layer_PatchNumberAndName.h"

#include "gui_Colors.h"
#include "gui_Constants.h"
#include "gui_Fonts.h"
#include "gui_Path_LEDcharacters_Singleton.h"
#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



PatchNumberAndNameLayer::PatchNumberAndNameLayer(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	slider_ForPatchNumber{ unexposedParams },
	patchNameEditor{ "patchNameEditor", "" }
{
	setInterceptsMouseClicks(false, true);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);

	slider_ForPatchNumber.addListener(this);
	slider_ForPatchNumber.setTooltip(generatePatchNumberTooltipString());
	addAndMakeVisible(slider_ForPatchNumber);

	patchNameEditor.setComponentID(ID::label_PatchNameEditor.toString());
	patchNameEditor.addListener(this);
	auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
	patchNameEditor.setText(currentPatchOptions->currentPatchName(), dontSendNotification);
	patchNameEditor.setTooltip(generatePatchNameTooltipString());
	addAndMakeVisible(patchNameEditor);
	setSize(GUI::editor_w, GUI::editor_h);
}

void PatchNumberAndNameLayer::resized() {
	slider_ForPatchNumber.setBounds(GUI::bounds_PatchNumberSlider);
	patchNameEditor.setBounds(GUI::bounds_PatchNameEditor);
}

void PatchNumberAndNameLayer::editorShown(Label* /*label*/, TextEditor& editor) {
	editor.setInputRestrictions(matrixParams::maxPatchNameLength, "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ?<>;:.,-+*/=()'\"&%$#!_^\\|[");
}

void PatchNumberAndNameLayer::labelTextChanged(Label* label) {
	if (label == &patchNameEditor) {
		String labelText{ label->getText() };
		String newName(labelText.toUpperCase());
		padNameLessThan8CharactersLongWithSpaces(newName);
		patchNameEditor.setText(newName, dontSendNotification);
		auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
		currentPatchOptions->setCurrentPatchName(newName);
		repaint();
	}
}

void PatchNumberAndNameLayer::padNameLessThan8CharactersLongWithSpaces(String& name) {
	for(auto i = name.length(); i != matrixParams::maxPatchNameLength; ++i)
		name += " ";
}

void PatchNumberAndNameLayer::sliderValueChanged(Slider* slider) {
	if (slider == &slider_ForPatchNumber) {
		auto currentKnobValue{ (uint8)roundToInt(slider->getValue()) };
		auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
		currentPatchOptions->setCurrentPatchNumber(currentKnobValue);
		slider_ForPatchNumber.setTooltip(generatePatchNumberTooltipString());
	}
}

String PatchNumberAndNameLayer::generatePatchNumberTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects which patch storage slot\n";
		tooltipText += "on the hardware is the target of the\n";
		tooltipText += "Push and Pull buttons to the left.\n";
		tooltipText += "Range: 0 to 99.";
	}
	return tooltipText;
}

String PatchNumberAndNameLayer::generatePatchNameTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Click to edit the name of the patch (8 characters max.)\n";
		tooltipText += "The name cannot be changed via Quick Edit. Use the\n";
		tooltipText += "Push button to the left to send the entire patch to\n";
		tooltipText += "the selected storage slot on the hardware.";
	}
	return tooltipText;
}

void PatchNumberAndNameLayer::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		slider_ForPatchNumber.setTooltip(generatePatchNumberTooltipString());
		patchNameEditor.setTooltip(generatePatchNameTooltipString());
	}
}

PatchNumberAndNameLayer::~PatchNumberAndNameLayer() {
	patchNameEditor.removeListener(this);
	slider_ForPatchNumber.removeListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
}
