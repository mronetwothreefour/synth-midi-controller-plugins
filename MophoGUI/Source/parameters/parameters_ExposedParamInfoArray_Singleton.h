#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_ControlTypes.h"
#include "../helpers/helper_Identifiers.h"
#include "../helpers/helper_IntToContextualStringConverters.h"
#include "../parameters/parameters_ExposedParameterInfo.h"



struct ExposedParamInfoArray_Singleton
{
	Array<ExposedParameterInfo> exposedParamInfoArray;

	ExposedParamInfoArray_Singleton(ExposedParamInfoArray_Singleton const&) = delete;
	ExposedParamInfoArray_Singleton(ExposedParamInfoArray_Singleton&&) = delete;
	ExposedParamInfoArray_Singleton& operator=(ExposedParamInfoArray_Singleton const&) = delete;
	ExposedParamInfoArray_Singleton& operator=(ExposedParamInfoArray_Singleton&&) = delete;

	static Array<ExposedParameterInfo>& get();

private:
	ExposedParamInfoArray_Singleton();
	~ExposedParamInfoArray_Singleton();

	void fillExposedSynthParamArray();
};