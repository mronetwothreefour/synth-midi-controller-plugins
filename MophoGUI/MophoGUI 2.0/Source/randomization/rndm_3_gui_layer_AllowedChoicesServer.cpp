#include "rndm_3_gui_layer_AllowedChoicesServer.h"

#include "rndm_0_ParamRandomizationMethods.h"
#include "rndm_2_gui_layer_AllowedChoices_Binary.h"
#include "rndm_2_gui_layer_AllowedChoices_LFO_Freq.h"
#include "rndm_2_gui_layer_AllowedChoices_OscShape.h"
#include "rndm_2_gui_layer_AllowedChoices_SeqTrack.h"
#include "rndm_2_gui_layer_AllowedChoices_Standard.h"
#include "rndm_2_gui_layer_AllowedChoices_VoiceNameChar.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../exposedParameters/ep_facade_ExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using Type = AllowedChoicesType;



GUI_Layer_AllowedChoicesServer::GUI_Layer_AllowedChoicesServer(
	ParamRandomizationMethods* randomize, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	randomize{ randomize },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
	setInterceptsMouseClicks(false, true);
	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoicesServer::showAllowedChoicesLayerForBinaryParam(uint8 paramIndex) {
	jassert(exposedParams->info.allowedChoicesTypeFor(paramIndex) == Type::binary);
	allowedChoices_LFO_Freq = nullptr;
	allowedChoices_OscShape = nullptr;
	allowedChoices_SeqTrack = nullptr;
	allowedChoices_Standard = nullptr;
	allowedChoices_VoiceNameChar = nullptr;
	allowedChoices_Binary.reset(new GUI_Layer_AllowedChoices_Binary{ paramIndex, exposedParams, randomize, unexposedParams });
	addAndMakeVisible(allowedChoices_Binary.get());
	allowedChoices_Binary->setTopLeftPosition(0, 0);
}

void GUI_Layer_AllowedChoicesServer::showAllowedChoicesLayerForLFO_FreqParam(uint8 paramIndex) {
	jassert(exposedParams->info.allowedChoicesTypeFor(paramIndex) == Type::lfoFreq);
	allowedChoices_Binary = nullptr;
	allowedChoices_OscShape = nullptr;
	allowedChoices_SeqTrack = nullptr;
	allowedChoices_Standard = nullptr;
	allowedChoices_VoiceNameChar = nullptr;
	allowedChoices_LFO_Freq.reset(new GUI_Layer_AllowedChoices_LFO_Freq{ paramIndex, exposedParams, randomize, unexposedParams });
	addAndMakeVisible(allowedChoices_LFO_Freq.get());
	allowedChoices_LFO_Freq->setTopLeftPosition(0, 0);
}

void GUI_Layer_AllowedChoicesServer::showAllowedChoicesLayerForOscShapeParam(uint8 paramIndex) {
	jassert(exposedParams->info.allowedChoicesTypeFor(paramIndex) == Type::oscShape);
	allowedChoices_Binary = nullptr;
	allowedChoices_LFO_Freq = nullptr;
	allowedChoices_SeqTrack = nullptr;
	allowedChoices_Standard = nullptr;
	allowedChoices_VoiceNameChar = nullptr;
	allowedChoices_OscShape.reset(new GUI_Layer_AllowedChoices_OscShape{ paramIndex, exposedParams, randomize, unexposedParams });
	addAndMakeVisible(allowedChoices_OscShape.get());
	allowedChoices_OscShape->setTopLeftPosition(0, 0);
}

void GUI_Layer_AllowedChoicesServer::showAllowedChoicesLayerForSeqTrack(Track track, bool destIsPitched) {
	allowedChoices_Binary = nullptr;
	allowedChoices_LFO_Freq = nullptr;
	allowedChoices_OscShape = nullptr;
	allowedChoices_Standard = nullptr;
	allowedChoices_VoiceNameChar = nullptr;
	allowedChoices_SeqTrack.reset(new GUI_Layer_AllowedChoices_SeqTrack{ track, destIsPitched, randomize, unexposedParams });
}

void GUI_Layer_AllowedChoicesServer::showAllowedChoicesLayerForStandardParam(uint8 paramIndex) {
	jassert(exposedParams->info.allowedChoicesTypeFor(paramIndex) == Type::standard);
	allowedChoices_Binary = nullptr;
	allowedChoices_LFO_Freq = nullptr;
	allowedChoices_OscShape = nullptr;
	allowedChoices_SeqTrack = nullptr;
	allowedChoices_VoiceNameChar = nullptr;
	allowedChoices_Standard.reset(new GUI_Layer_AllowedChoices_Standard{ paramIndex, exposedParams, randomize, unexposedParams });
	addAndMakeVisible(allowedChoices_Standard.get());
	allowedChoices_Standard->setTopLeftPosition(0, 0);
}

void GUI_Layer_AllowedChoicesServer::showAllowedChoicesLayerForVoiceNameCharParam(uint8 paramIndex) {
	jassert(exposedParams->info.allowedChoicesTypeFor(paramIndex) == Type::voiceNameChar);
	allowedChoices_Binary = nullptr;
	allowedChoices_LFO_Freq = nullptr;
	allowedChoices_OscShape = nullptr;
	allowedChoices_SeqTrack = nullptr;
	allowedChoices_Standard = nullptr;
	allowedChoices_VoiceNameChar.reset(new GUI_Layer_AllowedChoices_VoiceNameChar{ paramIndex, exposedParams, randomize, unexposedParams });
	addAndMakeVisible(allowedChoices_VoiceNameChar.get());
	allowedChoices_VoiceNameChar->setTopLeftPosition(0, 0);
}

GUI_Layer_AllowedChoicesServer::~GUI_Layer_AllowedChoicesServer() {
	allowedChoices_Binary = nullptr;
	allowedChoices_LFO_Freq = nullptr;
	allowedChoices_OscShape = nullptr;
	allowedChoices_SeqTrack = nullptr;
	allowedChoices_Standard = nullptr;
	allowedChoices_VoiceNameChar = nullptr;
}
