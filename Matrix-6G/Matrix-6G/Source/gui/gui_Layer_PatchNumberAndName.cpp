#include "gui_Layer_PatchNumberAndName.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



PatchNumberAndNameLayer::PatchNumberAndNameLayer(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	slider_ForPatchNumber{ unexposedParams },
	pgmNameEditor{ "pgmNameEditor", "" }
{
	setInterceptsMouseClicks(false, true);
	slider_ForPatchNumber.addListener(this);
	addAndMakeVisible(slider_ForPatchNumber);
	setSize(1273, 626);
}

void PatchNumberAndNameLayer::resized() {
	slider_ForPatchNumber.setBounds(840, 367, 28, 20);
}

void PatchNumberAndNameLayer::editorShown(Label* label, TextEditor& editor) {
}

void PatchNumberAndNameLayer::labelTextChanged(Label* label) {
}

void PatchNumberAndNameLayer::sliderValueChanged(Slider* slider) {
	if (slider == &slider_ForPatchNumber) {
		auto currentKnobValue{ (uint8)roundToInt(slider->getValue()) };
		auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
		currentPatchOptions->setCurrentPatchNumber(currentKnobValue);
	}
}

PatchNumberAndNameLayer::~PatchNumberAndNameLayer() {
	slider_ForPatchNumber.removeListener(this);
}
