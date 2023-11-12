#include "epc_1_comp_KnobAndAttachment_ForVoiceNameChar.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../gui/gui_build_LCD_CharacterPath.h"

using namespace MophoConstants;

KnobAndAttachment_ForVoiceNameChar::KnobAndAttachment_ForVoiceNameChar(
	const uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	paramIndex{ paramIndex },
	state{ exposedParams->state.get() },
	info{ exposedParams->info.get() },
	knob{ &exposedParams->undoManager },
	tooltipUpdater{ paramIndex, knob, exposedParams, tooltips }
{
	addAndMakeVisible(knob);
	knob.setMouseDragSensitivity(info->mouseDragSensitivityFor(paramIndex));
	knob.setAlpha(0.0f);
	knob.isModifyingPitch = false;
	setSize(GUI::voiceNameChars_w, GUI::voiceNameChars_h);
	knob.setBounds(getLocalBounds());
}

void KnobAndAttachment_ForVoiceNameChar::paint(Graphics& g) {
	auto charNum{ roundToInt(knob.getValue()) };
	g.setColour(GUI::color_White);
	g.fillPath(LCD_CharacterPath::buildForChar((uint8)charNum));
}

void KnobAndAttachment_ForVoiceNameChar::attachKnobToExposedParameter() {
	attachment.reset(new SliderAttachment{ *state, info->IDfor(paramIndex).toString(), knob });
	limitKnobRangeToBasic_ASCII_CharsThatAreVisible();
}

void KnobAndAttachment_ForVoiceNameChar::limitKnobRangeToBasic_ASCII_CharsThatAreVisible() {
	knob.setRange(32.0, 127.0, 1.0);
}

void KnobAndAttachment_ForVoiceNameChar::deleteAttachmentBeforeKnobToPreventMemLeak() {
	attachment = nullptr;
}
