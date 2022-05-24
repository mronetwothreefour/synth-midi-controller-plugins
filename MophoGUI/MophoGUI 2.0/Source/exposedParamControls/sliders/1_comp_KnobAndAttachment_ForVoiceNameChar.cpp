#include "1_comp_KnobAndAttachment_ForVoiceNameChar.h"

#include "../../constants/constants_GUI_Dimensions.h"
#include "../../constants/constants_ExposedParameters.h"
#include "../../constants/constants_GUI_Colors.h"
#include "../../constants/constants_Identifiers.h"
#include "../../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../../gui/gui_build_LCD_CharacterPath.h"

using namespace MophoConstants;



KnobAndAttachment_ForVoiceNameChar::KnobAndAttachment_ForVoiceNameChar(
	uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	knob{ unexposedParams },
	tooltipsUpdater{ paramIndex, knob, exposedParams, unexposedParams },
	charNum{ 0 }
{
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex) };
	auto paramaterPtr{ exposedParams->getParameter(paramID) };
	paramaterPtr->addListener(this);

	addAndMakeVisible(knob);
	knob.setMouseDragSensitivity(info.mouseDragSensitivityFor(paramIndex));
	knob.setComponentID(ID::component_Knob.toString());
	knob.setAlpha(0.0f);
	knob.isModifyingPitch = false;
	setSize(GUI::voiceNameCharacters_w, GUI::voiceNameCharacters_h);
	knob.setBounds(getLocalBounds());

	parameterValueChanged(paramIndex, paramaterPtr->getValue());
}

void KnobAndAttachment_ForVoiceNameChar::paint(Graphics& g) {
	g.setColour(GUI::color_White);
	g.fillPath(LCD_CharacterPath::buildForChar((uint8)charNum));
}

void KnobAndAttachment_ForVoiceNameChar::attachKnobToExposedParameter() {
	attachment.reset(new SliderAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(paramIndex).toString(), knob));
	limitKnobRangeToBasic_ASCII_CharsThatAreVisible();
}

void KnobAndAttachment_ForVoiceNameChar::limitKnobRangeToBasic_ASCII_CharsThatAreVisible() {
	knob.setRange(32.0, 127.0, 1.0);
}

void KnobAndAttachment_ForVoiceNameChar::parameterValueChanged(int changedParamIndex, float newValue) {
	if (changedParamIndex == paramIndex) {
		auto& info{ InfoForExposedParameters::get() };
		auto paramID{ info.IDfor(paramIndex) };
		auto paramaterPtr{ exposedParams->getParameter(paramID) };
		auto currentChoice{ roundToInt(paramaterPtr->convertFrom0to1(newValue)) };
		charNum = currentChoice;
		repaint();
	}
}

void KnobAndAttachment_ForVoiceNameChar::parameterGestureChanged(int /*paramIndex*/, bool /*gestureIsStarting*/) {
}

void KnobAndAttachment_ForVoiceNameChar::deleteAttachmentBeforeKnobToPreventMemLeak() {
	attachment = nullptr;
}

KnobAndAttachment_ForVoiceNameChar::~KnobAndAttachment_ForVoiceNameChar() {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex) };
	auto paramaterPtr{ exposedParams->getParameter(paramID) };
	paramaterPtr->removeListener(this);
}
