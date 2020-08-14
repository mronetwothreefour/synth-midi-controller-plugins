#include "widget_ComboBoxWithExposedParamAttacher.h"

#include "../params/params_ExposedParamsInfo_Singleton.h"



ComboBoxWithExposedParamAttacher::ComboBoxWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams) :
	param{ param },
	tooltipSetter{ comboBox, param, unexposedParams }
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

void ComboBoxWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	attachment.reset(new ComboBoxAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), comboBox));
}

void ComboBoxWithExposedParamAttacher::deleteAttachment() {
	attachment = nullptr;
}

ComboBoxWithExposedParamAttacher::~ComboBoxWithExposedParamAttacher() {
}
