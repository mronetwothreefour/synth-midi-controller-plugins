#include "gui_comp_EnvelopePainter.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace Matrix_6G_Constants;

EnvelopePainter::EnvelopePainter(const int envNum, ExposedParameters* exposedParams) :
	attackStart_x{ 0.0f },
	decayStart_x{ 0.0f },
	sustainStart_x{ 0.0f },
	sustain_y{ 0.0f },
	releaseStart_x{ 0.0f },
	releaseEnd_x{ 0.0f }
{
	jassert(envNum > 0 && envNum < 4);
	String delayParamID{ "" };
	String attackParamID{ "" };
	String decayParamID{ "" };
	String sustainParamID{ "" };
	String releaseParamID{ "" };
	switch (envNum)
	{
	case 1:
		delayParamID = ID::ep_71_Env_1_Delay.toString();
		attackParamID = ID::ep_72_Env_1_Attack.toString();
		decayParamID = ID::ep_73_Env_1_Decay.toString();
		sustainParamID = ID::ep_74_Env_1_Sustain.toString();
		releaseParamID = ID::ep_75_Env_1_Release.toString();
		break;
	case 2:
		delayParamID = ID::ep_81_Env_2_Delay.toString();
		attackParamID = ID::ep_82_Env_2_Attack.toString();
		decayParamID = ID::ep_83_Env_2_Decay.toString();
		sustainParamID = ID::ep_84_Env_2_Sustain.toString();
		releaseParamID = ID::ep_85_Env_2_Release.toString();
		break;
	case 3:
		delayParamID = ID::ep_91_Env_3_Delay.toString();
		attackParamID = ID::ep_92_Env_3_Attack.toString();
		decayParamID = ID::ep_93_Env_3_Decay.toString();
		sustainParamID = ID::ep_94_Env_3_Sustain.toString();
		releaseParamID = ID::ep_95_Env_3_Release.toString();
		break;
	default:
		break;
	}

	delay.addListener(this);
	attack.addListener(this);
	decay.addListener(this);
	sustain.addListener(this);
	release.addListener(this);

	auto state{ exposedParams->state.get() };
	delayAttachment.reset(new SliderAttachment{ *state, delayParamID, delay });
	attackAttachment.reset(new SliderAttachment{ *state, attackParamID, attack });
	decayAttachment.reset(new SliderAttachment{ *state, decayParamID, decay });
	sustainAttachment.reset(new SliderAttachment{ *state, sustainParamID, sustain });
	releaseAttachment.reset(new SliderAttachment{ *state, releaseParamID, release });

	const int envelopePainters_w{ 228 };
	const int envelopePainters_h{ 108 };
	setSize(envelopePainters_w, envelopePainters_h);

	sliderValueChanged(&delay);
}

void EnvelopePainter::sliderValueChanged(Slider* /*slider*/) {
	setEnvelopeCoordinates();
	repaint();
}

void EnvelopePainter::setEnvelopeCoordinates() {
	attackStart_x = envStart_x + (((float)delay.getValue() / 63.0f) * envSegmentMax_w);
	decayStart_x = attackStart_x + (((float)attack.getValue() / 63.0f) * envSegmentMax_w);
	sustainStart_x = decayStart_x + (((float)decay.getValue() / 63.0f) * envSegmentMax_w);
	sustain_y = envMin_y - (((float)sustain.getValue() / 63.0f) * env_h);
	releaseStart_x = sustainStart_x + sustainSegment_w;
	releaseEnd_x = releaseStart_x + (((float)release.getValue() / 63.0f) * envSegmentMax_w);
}

void EnvelopePainter::paint(Graphics& g) {
	g.setColour(GUI::color_LED_Blue);
	Path path;
	path.startNewSubPath(envStart_x, envMin_y);
	path.lineTo(attackStart_x, envMin_y);
	path.lineTo(decayStart_x, envMax_y);
	path.lineTo(sustainStart_x, sustain_y);
	path.lineTo(releaseStart_x, sustain_y);
	path.lineTo(releaseEnd_x, envMin_y);
	path.lineTo(envEnd_x, envMin_y);
	g.strokePath(path, PathStrokeType{ 2.0f, PathStrokeType::JointStyle::curved, PathStrokeType::EndCapStyle::rounded });
}

void EnvelopePainter::deleteAttachmentsBeforeKnobsToPreventMemLeaks() {
	delayAttachment = nullptr;
	attackAttachment = nullptr;
	decayAttachment = nullptr;
	sustainAttachment = nullptr;
	releaseAttachment = nullptr;
}

EnvelopePainter::~EnvelopePainter() {
	delay.removeListener(this);
	attack.removeListener(this);
	decay.removeListener(this);
	sustain.removeListener(this);
	release.removeListener(this);
}
