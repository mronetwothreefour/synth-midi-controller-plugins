#pragma once

#include <JuceHeader.h>

#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../exposedParamControls/epc_3_vector_ExposedParamControlsServer.h"

class GUI_Layer_ExposedParamControls :
	public Component,
	private ExposedParamControlsServer
{
public:
	GUI_Layer_ExposedParamControls() = delete;

	GUI_Layer_ExposedParamControls(ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
		ExposedParamControlsServer{ exposedParams, tooltips }
	{
		rebuildControlsVector();
		for (uint8 paramIndex = 0; paramIndex != paramIndexOutOfRange(); ++paramIndex) {
			auto controlPtr{ controlPtrFor(paramIndex) };
			addAndMakeVisible(controlPtr);
			controlPtr->attachControlToExposedParameter();
			controlPtr->setCentrePosition(exposedParams->info->centerPointFor(paramIndex));
		}
	}

	~GUI_Layer_ExposedParamControls() override {
		for (uint8 param = 0; param != paramIndexOutOfRange(); ++param) {
			auto controlPtr{ controlPtrFor(param) };
			controlPtr->deleteAttachmentBeforeControlToPreventMemLeak();
		}
		clearControlsVector();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_ExposedParamControls)
};