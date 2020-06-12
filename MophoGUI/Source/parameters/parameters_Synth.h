#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_Enums.h"
#include "../helpers/helper_Identifiers.h"
#include "synthPropertyArrays/propertyArray_ID.h"
#include "synthPropertyArrays/propertyArray_intToStringConverters.h"
#include "synthPropertyArrays/propertyArray_NRPN.h"
#include "synthPropertyArrays/propertyArray_numberOfSteps.h"
#include "synthPropertyArrays/propertyArray_publicName.h"

// A Singleton set of hardware synth parameter property arrays.
// Provides operations for getting a property for a specified parameter
class SynthParamPropertiesDB
{
	Array<Identifier> idArray_;
	Array<uint16> nrpnArray_;
	Array<String> publicNameArray_;
	Array<IntToStringConverter*> intToStringConverterArray_;
	Array<uint8> numberOfStepsArray_;

	SynthParamPropertiesDB()
	{
		IDarrayFactory::fillArray(idArray_);
		NRPNarrayFactory::fillArray(nrpnArray_);
		PublicNameArrayFactory::fillArray(publicNameArray_);
		IntToStringConverterArrayFactory::fillArray(intToStringConverterArray_);
		NumberOfStepsArrayFactory::fillArray(numberOfStepsArray_);
	}

public:
	static SynthParamPropertiesDB& get()
	{
		static SynthParamPropertiesDB synthParamArraysBuilder;
		return synthParamArraysBuilder;
	}
	SynthParamPropertiesDB(SynthParamPropertiesDB const&) = delete;
	SynthParamPropertiesDB(SynthParamPropertiesDB&&) = delete;
	SynthParamPropertiesDB& operator=(SynthParamPropertiesDB const&) = delete;
	SynthParamPropertiesDB& operator=(SynthParamPropertiesDB&&) = delete;

	Identifier get_ID_forSynthParam(uint8 index) const noexcept { return idArray_[index]; }
	uint16 get_NRPN_forSynthParam(uint8 index) const noexcept { return nrpnArray_[index]; }
	String get_publicName_forSynthParam(uint8 index) const noexcept { return publicNameArray_[index]; }
	IntToStringConverter* get_intToStringConverter_forSynthParam(uint8 index) const noexcept { return intToStringConverterArray_[index]; }
	uint8 get_numberOfSteps_forSynthParam(uint8 index) const noexcept { return numberOfStepsArray_[index]; }
	uint8 get_maxValue_forSynthParam(uint8 index) const noexcept { return numberOfStepsArray_[index] - 1; }
};

