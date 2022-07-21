#include "gui_comp_EnvelopePainter.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace MophoConstants;

EnvelopePainter::EnvelopePainter(const EnvelopeType envType, ExposedParameters* exposedParams) :
	attackStart_x{ 0.0f },
	decayStart_x{ 0.0f },
	sustainStart_x{ 0.0f },
	sustain_y{ 0.0f },
	releaseStart_x{ 0.0f },
	releaseEnd_x{ 0.0f }
{
	String delayParamID{ "" };
	String attackParamID{ "" };
	String decayParamID{ "" };
	String sustainParamID{ "" };
	String releaseParamID{ "" };
	switch (envType)
	{
	case MophoConstants::EnvelopeType::env_3: {
		delayParamID = ID::ep_064_Env_3_Delay.toString();
		attackParamID = ID::ep_065_Env_3_Attack.toString();
		decayParamID = ID::ep_066_Env_3_Decay.toString();
		sustainParamID = ID::ep_067_Env_3_Sustain.toString();
		releaseParamID = ID::ep_068_Env_3_Release.toString();
		break;
	}
	case MophoConstants::EnvelopeType::lpf:
		delayParamID = ID::ep_027_LPF_Delay.toString();
		attackParamID = ID::ep_028_LPF_Attack.toString();
		decayParamID = ID::ep_029_LPF_Decay.toString();
		sustainParamID = ID::ep_030_LPF_Sustain.toString();
		releaseParamID = ID::ep_031_LPF_Release.toString();
		break;
	case MophoConstants::EnvelopeType::vca:
		delayParamID = ID::ep_035_VCA_Delay.toString();
		attackParamID = ID::ep_036_VCA_Attack.toString();
		decayParamID = ID::ep_037_VCA_Decay.toString();
		sustainParamID = ID::ep_038_VCA_Sustain.toString();
		releaseParamID = ID::ep_039_VCA_Release.toString();
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
	delayAttachment.reset( new SliderAttachment{ *state, delayParamID, delay } );
	attackAttachment.reset( new SliderAttachment{ *state, attackParamID, attack } );
	decayAttachment.reset( new SliderAttachment{ *state, decayParamID, decay } );
	sustainAttachment.reset( new SliderAttachment{ *state, sustainParamID, sustain } );
	releaseAttachment.reset( new SliderAttachment{ *state, releaseParamID, release } );

	const int envelopePainters_w{ 210 };
	const int envelopePainters_h{ 90 };
	setSize(envelopePainters_w, envelopePainters_h);

	sliderValueChanged(&delay);
}

void EnvelopePainter::sliderValueChanged(Slider* /*slider*/) {
	setEnvelopeCoordinates();
	repaint();
}

void EnvelopePainter::setEnvelopeCoordinates() {
	attackStart_x = envStart_x + (((float)delay.getValue() / 127.0f) * envSegmentMax_w);
	decayStart_x = attackStart_x + (((float)attack.getValue() / 127.0f) * envSegmentMax_w);
	sustainStart_x = decayStart_x + (((float)decay.getValue() / 127.0f) * envSegmentMax_w);
	sustain_y = envMin_y - (((float)sustain.getValue() / 127.0f) * env_h);
	releaseStart_x = sustainStart_x + sustainSegment_w;
	releaseEnd_x = releaseStart_x + (((float)release.getValue() / 127.0f) * envSegmentMax_w);
}

void EnvelopePainter::paint(Graphics& g) {
	g.setColour(GUI::color_White);
	Path path;
	path.startNewSubPath(envStart_x, envMin_y);
	path.lineTo(attackStart_x, envMin_y);
	path.lineTo(decayStart_x, envMax_y);
	path.lineTo(sustainStart_x, sustain_y);
	path.lineTo(releaseStart_x, sustain_y);
	path.lineTo(releaseEnd_x, envMin_y);
	path.lineTo(envEnd_x, envMin_y);
	PathStrokeType strokeType{ 2.0f, PathStrokeType::JointStyle::curved, PathStrokeType::EndCapStyle::rounded };
	g.strokePath(path, strokeType);
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
