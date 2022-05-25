#include "gui_comp_EnvelopePainter.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"

using namespace MophoConstants;



EnvelopePainter::EnvelopePainter(EnvelopeType envType, AudioProcessorValueTreeState* exposedParams) :
	exposedParams{ exposedParams },
	attackStart_x{ 0.0f },
	decayStart_x{ 0.0f },
	sustainStart_x{ 0.0f },
	sustain_y{ 0.0f },
	releaseStart_x{ 0.0f },
	releaseEnd_x{ 0.0f }
{
	switch (envType)
	{
	case MophoConstants::EnvelopeType::env_3: {
		delayParamID = ID::ep_064_Env_3_Delay;
		attackParamID = ID::ep_065_Env_3_Attack;
		decayParamID = ID::ep_066_Env_3_Decay;
		sustainParamID = ID::ep_067_Env_3_Sustain;
		releaseParamID = ID::ep_068_Env_3_Release;
		break;
	}
	case MophoConstants::EnvelopeType::lpf:
		delayParamID = ID::ep_027_LPF_Delay;
		attackParamID = ID::ep_028_LPF_Attack;
		decayParamID = ID::ep_029_LPF_Decay;
		sustainParamID = ID::ep_030_LPF_Sustain;
		releaseParamID = ID::ep_031_LPF_Release;
		break;
	case MophoConstants::EnvelopeType::vca:
		delayParamID = ID::ep_035_VCA_Delay;
		attackParamID = ID::ep_036_VCA_Attack;
		decayParamID = ID::ep_037_VCA_Decay;
		sustainParamID = ID::ep_038_VCA_Sustain;
		releaseParamID = ID::ep_039_VCA_Release;
		break;
	default:
		break;
	}

	auto delayParamPtr{ exposedParams->getParameter(delayParamID) };
	delayParamPtr->addListener(this);
	delayParamIndex = delayParamPtr->getParameterIndex();

	auto attackParamPtr{ exposedParams->getParameter(attackParamID) };
	attackParamPtr->addListener(this);
	attackParamIndex = attackParamPtr->getParameterIndex();

	auto decayParamPtr{ exposedParams->getParameter(decayParamID) };
	decayParamPtr->addListener(this);
	decayParamIndex = decayParamPtr->getParameterIndex();

	auto sustainParamPtr{ exposedParams->getParameter(sustainParamID) };
	sustainParamPtr->addListener(this);
	sustainParamIndex = sustainParamPtr->getParameterIndex();

	auto releaseParamPtr{ exposedParams->getParameter(releaseParamID) };
	releaseParamPtr->addListener(this);
	releaseParamIndex = releaseParamPtr->getParameterIndex();

	const int envelopePainters_w{ 210 };
	const int envelopePainters_h{ 90 };
	setSize(envelopePainters_w, envelopePainters_h);

	parameterValueChanged(delayParamIndex, delayParamPtr->getValue());
}

void EnvelopePainter::parameterValueChanged(int changedParamIndex, float /*newValue*/) {
	if (changedParamIndex >= delayParamIndex && changedParamIndex <= releaseParamIndex) {
		setEnvelopeCoordinates();
		repaint();
	}
}

void EnvelopePainter::parameterGestureChanged(int /*paramIndex*/, bool /*gestureIsStarting*/) {
}

void EnvelopePainter::setEnvelopeCoordinates() {
	auto delayParamPtr{ exposedParams->getParameter(delayParamID) };
	auto attackParamPtr{ exposedParams->getParameter(attackParamID) };
	auto decayParamPtr{ exposedParams->getParameter(decayParamID) };
	auto sustainParamPtr{ exposedParams->getParameter(sustainParamID) };
	auto releaseParamPtr{ exposedParams->getParameter(releaseParamID) };
	attackStart_x = envStart_x + (delayParamPtr->getValue() * envSegmentMax_w);
	decayStart_x = attackStart_x + (attackParamPtr->getValue() * envSegmentMax_w);
	sustainStart_x = decayStart_x + (decayParamPtr->getValue() * envSegmentMax_w);
	sustain_y = envMin_y - (sustainParamPtr->getValue() * env_h);
	releaseStart_x = sustainStart_x + sustainSegment_w;
	releaseEnd_x = releaseStart_x + (releaseParamPtr->getValue() * envSegmentMax_w);
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

EnvelopePainter::~EnvelopePainter() {
	auto delayParamPtr{ exposedParams->getParameter(delayParamID) };
	delayParamPtr->removeListener(this);

	auto attackParamPtr{ exposedParams->getParameter(attackParamID) };
	attackParamPtr->removeListener(this);

	auto decayParamPtr{ exposedParams->getParameter(decayParamID) };
	decayParamPtr->removeListener(this);

	auto sustainParamPtr{ exposedParams->getParameter(sustainParamID) };
	sustainParamPtr->removeListener(this);

	auto releaseParamPtr{ exposedParams->getParameter(releaseParamID) };
	releaseParamPtr->removeListener(this);
}
