#include "mMod_0_comp_TextEditorForMatrixModAmountSlider.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_0_tree_MatrixModOptions.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

TextEditorForMatrixModAmountSlider::TextEditorForMatrixModAmountSlider(int modNum, MatrixModOptions* matrixModOptions, TooltipsOptions* tooltips)
{
	modAmountAsValue = matrixModOptions->getMatrixModPropertyAsValue("matrixMod_Mod_" + (String)modNum + "_Amount");
	modAmountAsValue.addListener(this);

	setInterceptsMouseClicks(false, true);
	textEditor.setInterceptsMouseClicks(false, true);
	textEditor.setComponentID(ID::comp_TextEditorForSlider.toString());
	textEditor.onEditorShow = [this, tooltips] {
		auto editor{ textEditor.getCurrentTextEditor() };
		editor->setInputRestrictions(3, "-0123456789");
		if (tooltips->shouldShowDescription())
			editor->setTooltip("Type in a new setting.\n(Range: -63 to 63)");
	};
	textEditor.onTextChange = [this, modNum, matrixModOptions] {
		auto newSettingString{ textEditor.getText() };
		if (newSettingString.isNotEmpty()) {
			auto newSetting{ newSettingString.getIntValue() };
			if (newSetting < -63)
				newSetting = -63;
			if (newSetting > 63)
				newSetting = 63;
			matrixModOptions->setModAmount(modNum, uint8(newSetting + 63));
		}
		else
			setEditorTextUsingStoredValue();
	};
	setEditorTextUsingStoredValue();
	setSize(GUI::matrixModSlider_w, GUI::control_h);
	textEditor.setBounds(getLocalBounds());
	addAndMakeVisible(textEditor);
}

void TextEditorForMatrixModAmountSlider::setEditorTextUsingStoredValue() {
	auto modAmountValue{ (int)modAmountAsValue.getValue() };
	textEditor.setText(String(modAmountValue - EP::offsetForSigned_7_BitRange), dontSendNotification);
}

void TextEditorForMatrixModAmountSlider::showEditor() {
	textEditor.showEditor();
}

void TextEditorForMatrixModAmountSlider::valueChanged(Value& /*value*/) {
	setEditorTextUsingStoredValue();
}

TextEditorForMatrixModAmountSlider::~TextEditorForMatrixModAmountSlider() {
	modAmountAsValue.removeListener(this);
}
