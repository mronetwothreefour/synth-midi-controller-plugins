#include "rndm_2_gui_layer_AllowedChoices_ExposedParam.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

GUI_Layer_AllowedChoices_ExposedParam::GUI_Layer_AllowedChoices_ExposedParam(
	uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips, Outgoing_MIDI_Buffers* outgoingBuffers) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	info{ exposedParams->info.get() },
	btn_Close{ BorderColor::orange, tooltips, outgoingBuffers },
	comboBox_Repeats{ paramIndex, exposedParams, tooltips },
	allowChoiceToggles{ paramIndex, exposedParams, tooltips },
	btn_Randomize{ paramIndex, exposedParams, tooltips },
	childrenShouldBeStackedVertically{ false },
	background_x{ info->allowedChoicesBackground_x_For(paramIndex) },
	background_y{ info->allowedChoicesBackground_y_For(paramIndex) }
{
	jassert(paramIndex < EP::numberOfExposedParams);

	addAndMakeVisible(btn_Close);

	addAndMakeVisible(comboBox_Repeats);

	if (info->numberOfChoicesFor(paramIndex) > 2) {
		allowChoiceToggles.restoreToggles();
		addAndMakeVisible(allowChoiceToggles);

		auto paramName{ info->exposedNameFor(paramIndex) };
		auto shouldShowDescriptions{ tooltips->shouldShowDescription() };
		btn_AllowAll.setComponentID(ID::btn_AllowAll.toString());
		btn_AllowAll.onClick = [this, exposedParams, paramIndex] {
			auto rangeIsSigned{ info->choiceNameFor(0, paramIndex).startsWith("-") ? true : false };
			auto randomization{ exposedParams->randomization.get() };
			randomization->allowAllChoicesForParam(paramIndex, rangeIsSigned);
			allowChoiceToggles.restoreToggles();
		};
		btn_AllowAll.addShortcut(KeyPress{ 'a', ModifierKeys::ctrlModifier, 0 });
		if (shouldShowDescriptions) {
			String tip{ "" };
			tip += "Click to allow all the choices when\n";
			tip += "generating a random setting for\n";
			tip += paramName + ".\n";
			tip += "Shortcut key: CTRL+A";
			btn_AllowAll.setTooltip(tip);
		}
		btn_AllowAll.setSize(GUI::btn_AllowAll_w, GUI::control_h);
		addAndMakeVisible(btn_AllowAll);

		background_w = 2 * GUI::allowedChoices_Inset;
		background_h = 2 * GUI::allowedChoices_Inset + allowChoiceToggles.getHeight();
		if (allowChoiceToggles.getWidth() < comboBox_Repeats.getWidth())
			childrenShouldBeStackedVertically = true;
		if (childrenShouldBeStackedVertically) {
			background_w += btn_Randomize.getWidth();
			background_h += 3 * GUI::control_h;
			background_h += 3 * GUI::allowedChoices_VertGap;
		}
		else {
			background_w += allowChoiceToggles.getWidth();
			background_h += 2 * GUI::control_h;
			background_h += 2 * GUI::allowedChoices_VertGap;
		}
	}
	else {
		background_w = 156;
		background_h = 100;
	}

	addAndMakeVisible(btn_Randomize);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_ExposedParam::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	auto controlCenter{ info->centerPointFor(paramIndex) };
	auto control_w{ info->widthFor(paramIndex) };
	g.setColour(GUI::color_ButtonOrange);
	g.drawRect(controlCenter.x - control_w / 2, controlCenter.y - GUI::control_h / 2, control_w, GUI::control_h, 1);
	g.fillRect(background_x, background_y, background_w, background_h);
	g.setColour(GUI::color_Device);
	g.fillRect(background_x + GUI::borders_w, background_y + GUI::borders_w, background_w - 2 * GUI::borders_w, background_h - 2 * GUI::borders_w);
}

void GUI_Layer_AllowedChoices_ExposedParam::resized() {
	btn_Close.setTopRightPosition(background_x + background_w, background_y);
	if (info->numberOfChoicesFor(paramIndex) > 2) 	{
		auto center_x{ background_x + (background_w / 2) };
		auto center_y{ background_y + GUI::borders_w + GUI::allowedChoices_Inset };
		if (childrenShouldBeStackedVertically) {
			center_y += GUI::control_h / 2;
			comboBox_Repeats.setCentrePosition(center_x, center_y);
			center_y += allowChoiceToggles.getHeight() / 2 + GUI::allowedChoices_VertGap + GUI::control_h / 2;
			allowChoiceToggles.setCentrePosition(center_x, center_y);
			center_y += GUI::control_h / 2 + GUI::allowedChoices_VertGap + allowChoiceToggles.getHeight() / 2;
			btn_AllowAll.setCentrePosition(center_x, center_y);
			center_y += GUI::control_h + GUI::allowedChoices_VertGap;
			btn_Randomize.setCentrePosition(center_x, center_y);
		}
		else {
			center_y += GUI::control_h / 2;
			comboBox_Repeats.setCentrePosition(center_x, center_y);
			center_y += GUI::control_h / 2 + GUI::allowedChoices_VertGap + allowChoiceToggles.getHeight() / 2;
			allowChoiceToggles.setCentrePosition(center_x, center_y);
			center_y += allowChoiceToggles.getHeight() / 2 + GUI::allowedChoices_VertGap + GUI::control_h / 2;
			btn_AllowAll.setTopLeftPosition(background_x + GUI::borders_w + GUI::allowedChoices_Inset, center_y);
			btn_Randomize.setTopRightPosition(background_x + background_w - (GUI::borders_w + GUI::allowedChoices_Inset), center_y);
		}
	}
	else {
		comboBox_Repeats.setTopLeftPosition(background_x + 25, background_y + 25);
		btn_Randomize.setTopLeftPosition(background_x + 48, background_y + 55);
	}
}
