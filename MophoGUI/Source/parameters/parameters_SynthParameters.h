#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_ControlTypes.h"
#include "../helpers/helper_Identifiers.h"
#include "../helpers/helper_IntToContextualStringConverters.h"
#include "../helpers/helper_Property.h"

// Constructor arguments order:
// ID, publicName, controlType, 
// NRPN, converter, maxValue, defaultValue, centerPoint
struct SynthParameter
{
	StaticProperty<Identifier> ID;
	StaticProperty<String> publicName;
	StaticProperty<ControlType> controlType;
	StaticProperty<uint16> NRPN;
	StaticProperty<IntToContextualStringConverter*> converter;
	StaticProperty<uint8> maxValue;
	StaticProperty<uint16> numberOfSteps{ maxValue + 1 };
	StaticProperty<uint8> defaultValue;
	StaticProperty<Point<int>> centerPoint;

	SynthParameter() :
		ID{ "null" },
		publicName{ "null" },
		controlType{ ControlType::nullControl },
		NRPN{ 16383 },
		converter{ IntToNullString::get() },
		maxValue{ 0 },
		defaultValue{ 0 },
		centerPoint{ Point<int>(0, 0) }
	{}

	SynthParameter
	(
		Identifier ID, String publicName, ControlType controlType, uint16 NRPN,
		IntToContextualStringConverter* converter, uint8 maxValue, uint8 defaultValue, Point<int> centerPoint
	) :
		ID{ ID },
		publicName{ publicName },
		controlType{ controlType },
		NRPN{ NRPN },
		converter{ converter },
		maxValue{ maxValue },
		defaultValue{ defaultValue },
		centerPoint{ centerPoint }
	{}
};

class ExposedSynthParameters_Database
{
	Array<SynthParameter> ExposedSynthParamArray{};

	void fillExposedSynthParamArray();

	ExposedSynthParameters_Database()
	{
		fillExposedSynthParamArray();
	}

	~ExposedSynthParameters_Database() {}

public:
	ExposedSynthParameters_Database(ExposedSynthParameters_Database const&) = delete;
	ExposedSynthParameters_Database(ExposedSynthParameters_Database&&) = delete;
	ExposedSynthParameters_Database& operator=(ExposedSynthParameters_Database const&) = delete;
	ExposedSynthParameters_Database& operator=(ExposedSynthParameters_Database&&) = delete;

	static ExposedSynthParameters_Database& get()
	{
		static ExposedSynthParameters_Database synthParameterDatabase;
		return synthParameterDatabase;
	}

	SynthParameter getSynthParameter(uint16 index) const { return ExposedSynthParamArray[index]; }
	int size() const noexcept { return ExposedSynthParamArray.size(); }
};