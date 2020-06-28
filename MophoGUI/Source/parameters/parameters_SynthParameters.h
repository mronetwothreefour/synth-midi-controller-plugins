#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_Identifiers.h"
#include "../helpers/helper_IntToContextualStringConverters.h"
#include "../helpers/helper_Property.h"

enum class ControlType
{
	nullControl = -1,
	knobWithValueStringDisplay,
	knobWithWaveShapeDisplay
};

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

class ExposedSynthParametersDatabase
{
	Array<SynthParameter> ExposedSynthParamArray{};

	void fillExposedSynthParamArray();

	ExposedSynthParametersDatabase()
	{
		fillExposedSynthParamArray();
	}

	~ExposedSynthParametersDatabase() {}

public:
	ExposedSynthParametersDatabase(ExposedSynthParametersDatabase const&) = delete;
	ExposedSynthParametersDatabase(ExposedSynthParametersDatabase&&) = delete;
	ExposedSynthParametersDatabase& operator=(ExposedSynthParametersDatabase const&) = delete;
	ExposedSynthParametersDatabase& operator=(ExposedSynthParametersDatabase&&) = delete;

	static ExposedSynthParametersDatabase& get()
	{
		static ExposedSynthParametersDatabase synthParameterDatabase;
		return synthParameterDatabase;
	}

	SynthParameter getSynthParameter(uint16 index) const { return ExposedSynthParamArray[index]; }
	int size() const noexcept { return ExposedSynthParamArray.size(); }
};