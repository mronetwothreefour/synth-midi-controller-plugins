#include "widget_ComboBoxWithExposedParamAttacher.h"

#include "../gui/gui_Constants.h"
#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"

using namespace constants;



ComboBoxWithExposedParamAttacher::ComboBoxWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams) :
	param{ param },
	tooltipSetter{ comboBox, param, unexposedParams },
	converter{ InfoForExposedParameters::get().converterFor(param) }
{
	StringArray choices;
	for (uint8 i = 0; i != InfoForExposedParameters::get().numberOfStepsFor(param); ++i)
		choices.add(converter->convert(i));
	comboBox.addItemList(choices, 1);
	comboBox.setColour(ComboBox::ColourIds::textColourId, Colours::transparentBlack);
	addAndMakeVisible(comboBox);
	auto ctrlWidth{ InfoForExposedParameters::get().controlWidthFor(param) };
	setSize(ctrlWidth, GUI::controls_h);
	comboBox.setSize(ctrlWidth, GUI::controls_h);
}

void ComboBoxWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	attachment.reset(new ComboBoxAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), comboBox));
}

void ComboBoxWithExposedParamAttacher::deleteAttachment() {
	attachment = nullptr;
}

void ComboBoxWithExposedParamAttacher::paint(Graphics& g) {
	auto currentValue{ (int8)roundToInt(comboBox.getSelectedItemIndex()) };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}
