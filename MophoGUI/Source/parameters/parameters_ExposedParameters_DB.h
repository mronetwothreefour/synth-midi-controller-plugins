#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_ControlTypes.h"
#include "../helpers/helper_Identifiers.h"
#include "../helpers/helper_IntToContextualStringConverters.h"
#include "../parameters/parameters_ParameterProperties.h"



class ExposedParameters_Database
{
	Array<ParameterProperties> exposedSynthParamArray;

	ExposedParameters_Database();
	~ExposedParameters_Database();

	void fillExposedSynthParamArray();

public:
	ExposedParameters_Database(ExposedParameters_Database const&) = delete;
	ExposedParameters_Database(ExposedParameters_Database&&) = delete;
	ExposedParameters_Database& operator=(ExposedParameters_Database const&) = delete;
	ExposedParameters_Database& operator=(ExposedParameters_Database&&) = delete;

	static ExposedParameters_Database& get();
	int size() const noexcept;
	ParameterProperties getSynthParameter(uint16 index);
};