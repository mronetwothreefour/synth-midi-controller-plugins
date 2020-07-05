#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_ControlTypes.h"
#include "../helpers/helper_Identifiers.h"
#include "../helpers/helper_IntToContextualStringConverters.h"
#include "../parameters/parameters_ExposedParameterInfo.h"



struct ExposedParamsInfo_Singleton
{
	Array<ExposedParameterInfo> exposedParamInfoArray;

	ExposedParamsInfo_Singleton(ExposedParamsInfo_Singleton&&) = delete;
	ExposedParamsInfo_Singleton& operator=(ExposedParamsInfo_Singleton&&) = delete;

	static Array<ExposedParameterInfo>& get();

private:
	ExposedParamsInfo_Singleton();
	~ExposedParamsInfo_Singleton();

	void fillExposedSynthParamArray();

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamsInfo_Singleton)
};