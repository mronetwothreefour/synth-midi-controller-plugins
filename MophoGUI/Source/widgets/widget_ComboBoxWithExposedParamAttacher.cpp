#include "widget_ComboBoxWithExposedParamAttacher.h"



ComboBoxWithExposedParamAttacher::ComboBoxWithExposedParamAttacher(uint8 param) :
	param{ param },
	tooltipSetter{ comboBox, param }
{
	StringArray choices;
	auto converter{ InfoForExposedParameters::get().converterFor(param) };
	for (uint8 i = 0; i != InfoForExposedParameters::get().numberOfStepsFor(param); ++i) {
		choices.add(converter->convert(i));
	}
	comboBox.addItemList(choices, 1);
	addAndMakeVisible(comboBox);
	auto ctrlWidth{ InfoForExposedParameters::get().ctrlWidthFor(param) };
	auto ctrlHeight{ InfoForExposedParameters::get().ctrlHeightFor(param) };
	setSize(ctrlWidth, ctrlHeight);
	comboBox.setSize(ctrlWidth, ctrlHeight);
}

ComboBoxWithExposedParamAttacher::~ComboBoxWithExposedParamAttacher() {
}

void ComboBoxWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	attachment.reset(new ComboBoxAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), comboBox));
}

void ComboBoxWithExposedParamAttacher::deleteAttachment() {
	attachment = nullptr;
}
