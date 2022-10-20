#include "global_1_comp_SliderForVoiceMapSlot.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using Description = GlobalParamDescription;

SliderForVoiceMapSlot::SliderForVoiceMapSlot(uint8 mapSlotNum, SliderType type, UnexposedParameters* unexposedParams, UndoManager* undoManager) :
	RotarySliderWithMouseWheelMoveOverride{ undoManager },
	mapSlotNum{ mapSlotNum },
	type{ type },
	textEditor{ mapSlotNum, type, unexposedParams->getGlobalOptions(), unexposedParams->getTooltipsOptions() },
	tooltips{ unexposedParams->getTooltipsOptions() }
{
	setRange(0.0, 99.0, 1.0);
	setMouseDragSensitivity(130);
	if (type != SliderType::null) {
		auto global{ unexposedParams->getGlobalOptions() };

		if (type == SliderType::in) {
			globalParamAsValue = global->getGobalParamAsValue(ID::global_VoiceMapIn_.toString() + (String)mapSlotNum);
			setValue(global->inVoiceForVoiceMapSlot(mapSlotNum));
		}
		else {
			globalParamAsValue = global->getGobalParamAsValue(ID::global_VoiceMapOut_.toString() + (String)mapSlotNum);
			setValue(global->outVoiceForVoiceMapSlot(mapSlotNum));
		}
	}

	textEditor.setTopLeftPosition(0, 0);
	addAndMakeVisible(textEditor);

	globalParamAsValue.addListener(this);

	updateTooltip();

	setSize(GUI::voiceMapSlider_w, GUI::control_h);
}

void SliderForVoiceMapSlot::updateTooltip() {
	auto currentChoice{ (String)roundToInt(getValue()) };
	String tip{ "" };
	if (type != SliderType::null) {
		if (tooltips->shouldShowDescription())
			if (type == SliderType::in)
				tip += Description::buildForVoiceMapInVoice(mapSlotNum);
			else
				tip += Description::buildForVoiceMapOutVoice(mapSlotNum);
		if (tooltips->shouldShowCurrentChoice())
			if (type == SliderType::in)
				tip += "Current setting: Patch " + currentChoice.paddedLeft('0', 2);
			else
				tip += "Current setting: Program " + currentChoice;
	}
	setTooltip(tip);
}

void SliderForVoiceMapSlot::mouseDoubleClick(const MouseEvent& /*event*/) {
	textEditor.showEditor();
}

void SliderForVoiceMapSlot::valueChanged() {
	auto currentChoice{ (uint8)roundToInt(getValue()) };
	globalParamAsValue.setValue(currentChoice);
}

void SliderForVoiceMapSlot::valueChanged(Value& value) {
	MessageManagerLock mmLock;
	setValue((double)value.getValue(), sendNotification);
	updateTooltip();
}

SliderForVoiceMapSlot::~SliderForVoiceMapSlot() {
	globalParamAsValue.removeListener(this);
}
