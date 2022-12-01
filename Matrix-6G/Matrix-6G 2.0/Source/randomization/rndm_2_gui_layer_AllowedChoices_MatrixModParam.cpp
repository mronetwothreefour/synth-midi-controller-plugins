#include "rndm_2_gui_layer_AllowedChoices_MatrixModParam.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_MatrixMod.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

GUI_Layer_AllowedChoices_MatrixModParam::GUI_Layer_AllowedChoices_MatrixModParam(
	int modNum, MM_Type paramType, ExposedParameters* exposedParams, TooltipsOptions* tooltips, Outgoing_MIDI_Buffers* outgoingBuffers) :
	modNum{ modNum },
	paramType{ paramType },
	matrixModOptions{ exposedParams->matrixModOptions.get() },
	btn_Close{ BorderColor::orange, tooltips, outgoingBuffers },
	comboBox_Repeats{ modNum, paramType, exposedParams, tooltips },
	allowChoiceToggles{ modNum, paramType, exposedParams, tooltips },
	btn_Randomize{ modNum, paramType, exposedParams, tooltips },
	background_x{ paramType == MM_Type::source ? 834 : paramType == MM_Type::amount ? 664 : 950 },
	background_y{ (59 + modNum * GUI::vertDistBtwnRows) },
	background_w{ paramType == MM_Type::source ? 178 : paramType == MM_Type::amount ? 434 : 194 },
	background_h{ paramType == MM_Type::source ? 222 : paramType == MM_Type::amount ? 238 : 286 },
	modDestOffset{ modNum > 7 && paramType == MM_Type::destination ? 143 : 0 }
{
	jassert(modNum < MMOD::numberOfModulators);

	btn_Close.setTopRightPosition(background_x + background_w, background_y - modDestOffset);
	addAndMakeVisible(btn_Close);

	auto center_x{ background_x + background_w / 2 };
	auto center_y{ background_y - modDestOffset + GUI::borders_w + GUI::allowedChoices_Inset + GUI::control_h / 2 };
	comboBox_Repeats.setCentrePosition(center_x, center_y);
	addAndMakeVisible(comboBox_Repeats);

	center_y += GUI::control_h / 2 + GUI::allowedChoices_VertGap + allowChoiceToggles.getHeight() / 2;
	allowChoiceToggles.setCentrePosition(center_x, center_y);
	allowChoiceToggles.restoreToggles();
	addAndMakeVisible(allowChoiceToggles);

	auto buttons_y{ center_y + allowChoiceToggles.getHeight() / 2 + GUI::allowedChoices_VertGap };
	auto paramName{ "Modulator " + (String)modNum };
	paramName += paramType == MM_Type::source ? " Source" : paramType == MM_Type::amount ? " Amount" : " Destination";
	auto shouldShowDescriptions{ tooltips->shouldShowDescription() };
	btn_AllowAll.setComponentID(ID::btn_AllowAll.toString());
	btn_AllowAll.onClick = [this, exposedParams, modNum, paramType] {
		auto randomization{ exposedParams->randomization.get() };
		randomization->allowAllChoicesForMatrixModParam(modNum, paramType);
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
	btn_AllowAll.setTopLeftPosition(background_x + GUI::borders_w + GUI::allowedChoices_Inset, buttons_y);
	addAndMakeVisible(btn_AllowAll);

	btn_Randomize.setTopRightPosition(background_x + background_w -  GUI::borders_w - GUI::allowedChoices_Inset, buttons_y);
	addAndMakeVisible(btn_Randomize);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_MatrixModParam::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	auto control_x{ paramType == MM_Type::source ? 1016 : paramType == MM_Type::amount ? 1104 : 1150 };
	auto control_w{ paramType == MM_Type::amount ? 40 : 82 };
	g.setColour(GUI::color_ButtonOrange);
	g.drawRect(control_x, background_y, control_w, GUI::control_h, 1);
	g.fillRect(background_x, background_y - modDestOffset, background_w, background_h);
	g.setColour(GUI::color_Device);
	g.fillRect(background_x + GUI::borders_w, background_y + GUI::borders_w - modDestOffset, background_w - 2 * GUI::borders_w, background_h - 2 * GUI::borders_w);
}

