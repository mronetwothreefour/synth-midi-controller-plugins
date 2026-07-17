#include "gui_layer_TooltipsOptions.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

GUI_Layer_TooltipsOptions::GUI_Layer_TooltipsOptions(TooltipsOptions* tooltips, UndoManager* undoManager) :
	tooltips{ tooltips },
	btn_Exit{ tooltips },
	switch_Descriptions{ undoManager },
	switch_CurrentChoice{ undoManager }
{
	shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
	shouldShowDescriptionAsValue.addListener(this);

	btn_Exit.setTopLeftPosition(782, 82);
	addAndMakeVisible(btn_Exit);

	auto switches_y{ 157 };
	switch_Descriptions.setRange(0.0, 1.0, 1.0);
	if (tooltips->shouldShowDescription())
		switch_Descriptions.setValue(1.0, dontSendNotification);
	switch_Descriptions.onValueChange = [this, tooltips] {
		auto shouldShowDescription{ switch_Descriptions.getValue() == 1.0 };
		tooltips->setShouldShowDescription(shouldShowDescription);
	};
	switch_Descriptions.setBounds(646, switches_y, GUI::switch_w, GUI::switch_2_Pole_h);
	addAndMakeVisible(switch_Descriptions);

	switch_CurrentChoice.setRange(0.0, 1.0, 1.0);
	if (tooltips->shouldShowCurrentChoice())
		switch_CurrentChoice.setValue(1.0, dontSendNotification);
	switch_CurrentChoice.onValueChange = [this, tooltips] {
		auto shouldShowCurrentChoice{ switch_CurrentChoice.getValue() == 1.0 };
		tooltips->setShouldShowCurrentChoice(shouldShowCurrentChoice);
	};
	switch_CurrentChoice.setBounds(736, switches_y, GUI::switch_w, GUI::switch_2_Pole_h);
	addAndMakeVisible(switch_CurrentChoice);

	lbl_delayTimeEditor.setComponentID(ID::comp_TextEditorForTooltipDelayTime.toString());
	lbl_delayTimeEditor.setEditable(true);
	lbl_delayTimeEditor.onEditorShow = [this, tooltips] {
		auto editor{ lbl_delayTimeEditor.getCurrentTextEditor() };
		editor->setInputRestrictions(4, "0123456789");
		editor->setText((String)tooltips->delayInMilliseconds());
		editor->selectAll();
		if (tooltips->shouldShowDescription())
			editor->setTooltip("Type a new tooltip delay\ntime in milliseconds.\n(Range: 0 to 5000)");
	};
	lbl_delayTimeEditor.onTextChange = [this, tooltips] {
		if (lbl_delayTimeEditor.getText().isNotEmpty()) {
			auto newValue{ lbl_delayTimeEditor.getText().getIntValue() };
			if (newValue < 5001)
				tooltips->setDelayInMilliseconds(newValue);
		}
		lbl_delayTimeEditor.setText(String(tooltips->delayInMilliseconds()).paddedLeft('0', 4), dontSendNotification);
	};
	lbl_delayTimeEditor.setBounds(645, 241, 112, 50);
	addAndMakeVisible(lbl_delayTimeEditor);
	lbl_delayTimeEditor.onTextChange();

	updateTooltips();

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_TooltipsOptions::updateTooltips() {
	auto shouldShowDescription{ tooltips->shouldShowDescription() };

	String tip{ "" };

	if (shouldShowDescription) {
		tip += "When enabled, a descriptive tooltip will appear if the mouse\n";
		tip += "hovers over a control for the amount of time specified below.\n";
	}
	switch_Descriptions.setTooltip(tip);

	if (shouldShowDescription) {
		tip = "";
		tip += "When enabled, a tooltip with a verbose\n";
		tip += "version of the current setting will appear\n";
		tip += "if the mouse hovers over a control for\n";
		tip += "the amount of time specified below.\n";
	}
	switch_CurrentChoice.setTooltip(tip);

	if (shouldShowDescription) {
		tip = "";
		tip += "Sets the amount of time (in milliseconds) the mouse cursor\n";
		tip += "must hover over a control before a tooltip box is shown.\n";
		tip += "Maximum delay: 5000 milliseconds.\n";
	}
	lbl_delayTimeEditor.setTooltip(tip);
}

void GUI_Layer_TooltipsOptions::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_TooltipsOptions_png, BinaryData::bkgrnd_TooltipsOptions_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 565, 67);
}

void GUI_Layer_TooltipsOptions::valueChanged(Value& /*value*/) {
	MessageManagerLock mmLock;
	updateTooltips();
}

GUI_Layer_TooltipsOptions::~GUI_Layer_TooltipsOptions() {
	shouldShowDescriptionAsValue.removeListener(this);
}
