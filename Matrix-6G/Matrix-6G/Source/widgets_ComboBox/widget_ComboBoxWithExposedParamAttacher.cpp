#include "widget_ComboBoxWithExposedParamAttacher.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Path_ComboBoxIndicatorTab.h"
#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"



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
	auto ctrlHeight{ 20 };
	setSize(ctrlWidth, ctrlHeight);
	comboBox.setSize(ctrlWidth, ctrlHeight);
}

void ComboBoxWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	attachment.reset(new ComboBoxAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), comboBox));
}

void ComboBoxWithExposedParamAttacher::deleteAttachment() {
	attachment = nullptr;
}

void ComboBoxWithExposedParamAttacher::paint(Graphics& g) {
	g.fillAll(Color::black);
	Path indicatorTab;
	auto tab_x{ getWidth() - 6.0f };
	auto tab_y{ getHeight() - 6.0f };
	indicatorTab.addPath(ComboBoxIndicatorTab::createPath(), AffineTransform::translation(tab_x, tab_y));
	g.setColour(Color::led_blue);
	g.fillPath(indicatorTab);
	auto currentValue{ (int8)roundToInt(comboBox.getSelectedItemIndex()) };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}
