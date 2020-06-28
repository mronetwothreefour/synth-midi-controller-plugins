#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_Identifiers.h"
#include "../helpers/helper_IntToContextualStringConverters.h"
#include "../helpers/helper_Property.h"
#include "parameters_SynthParametersFactory.h"

class SynthParametersDatabase
{
	Array<SynthParameter> synthParamArray_{};

	SynthParametersDatabase() : 
		firstNonPublicParam { SynthParameterArrayFactory::fillArray(synthParamArray_) }
	{
	}

	~SynthParametersDatabase() {}

public:
	const int firstNonPublicParam;

	SynthParametersDatabase(SynthParametersDatabase const&) = delete;
	SynthParametersDatabase(SynthParametersDatabase&&) = delete;
	SynthParametersDatabase& operator=(SynthParametersDatabase const&) = delete;
	SynthParametersDatabase& operator=(SynthParametersDatabase&&) = delete;

	static SynthParametersDatabase& get()
	{
		static SynthParametersDatabase synthParameterDatabase;
		return synthParameterDatabase;
	}

	SynthParameter getSynthParameter(uint16 index) const { return synthParamArray_[index]; }
};