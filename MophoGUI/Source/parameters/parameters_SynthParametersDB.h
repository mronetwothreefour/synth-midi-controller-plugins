#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_Identifiers.h"
#include "../helpers/helper_IntToStringConverters.h"
#include "../helpers/helper_Property.h"
#include "parameters_SynthParametersFactory.h"

class SynthParametersDatabase
{
	Array<SynthParameter> synthParamArray_{};

	SynthParametersDatabase() : 
		firstNonPublicParam { SynthParameterArrayFactory::fillArray(synthParamArray_) }
	{}

	~SynthParametersDatabase() {}

public:
	const int firstNonPublicParam;

	static SynthParametersDatabase& get()
	{
		static SynthParametersDatabase synthParameterDatabase;
		return synthParameterDatabase;
	}
	SynthParametersDatabase(SynthParametersDatabase const&) = delete;
	SynthParametersDatabase(SynthParametersDatabase&&) = delete;
	SynthParametersDatabase& operator=(SynthParametersDatabase const&) = delete;
	SynthParametersDatabase& operator=(SynthParametersDatabase&&) = delete;

	SynthParameter getSynthParameter(uint16 index) const { return synthParamArray_[index]; }
};