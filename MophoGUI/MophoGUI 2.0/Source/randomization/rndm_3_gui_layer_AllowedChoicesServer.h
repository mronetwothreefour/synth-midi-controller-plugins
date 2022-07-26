#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using Track = SeqTrackNum;

class GUI_Layer_AllowedChoices_Binary;
class GUI_Layer_AllowedChoices_LFO_Freq;
class GUI_Layer_AllowedChoices_OscShape;
class GUI_Layer_AllowedChoices_SeqTrack;
class GUI_Layer_AllowedChoices_Standard;
class GUI_Layer_AllowedChoices_VoiceNameChar;
class ExposedParameters;
class UnexposedParameters;

class GUI_Layer_AllowedChoicesServer :
	public Component
{
	UnexposedParameters* unexposedParams;
	ExposedParameters* exposedParams;
	std::unique_ptr<GUI_Layer_AllowedChoices_Binary> allowedChoices_Binary;
	std::unique_ptr<GUI_Layer_AllowedChoices_LFO_Freq> allowedChoices_LFO_Freq;
	std::unique_ptr<GUI_Layer_AllowedChoices_OscShape> allowedChoices_OscShape;
	std::unique_ptr<GUI_Layer_AllowedChoices_SeqTrack> allowedChoices_SeqTrack;
	std::unique_ptr<GUI_Layer_AllowedChoices_Standard> allowedChoices_Standard;
	std::unique_ptr<GUI_Layer_AllowedChoices_VoiceNameChar> allowedChoices_VoiceNameChar;

public:
	GUI_Layer_AllowedChoicesServer() = delete;

	GUI_Layer_AllowedChoicesServer(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	void showAllowedChoicesLayerForBinaryParam(uint8 paramIndex);
	void showAllowedChoicesLayerForLFO_FreqParam(uint8 paramIndex);
	void showAllowedChoicesLayerForOscShapeParam(uint8 paramIndex);
	void showAllowedChoicesLayerForSeqTrack(Track track, bool destIsPitched);
	void showAllowedChoicesLayerForStandardParam(uint8 paramIndex);
	void showAllowedChoicesLayerForVoiceNameCharParam(uint8 paramIndex);
	~GUI_Layer_AllowedChoicesServer();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_AllowedChoicesServer)
};