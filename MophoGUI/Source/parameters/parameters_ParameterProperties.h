#pragma once



template <typename T>
struct StaticProperty
{
	T value;

	explicit StaticProperty(const T initial_value) { 
		value = initial_value; 
	}

	operator T() { 
		return value; 
	}

	T operator = (T new_value) = delete; // the value of a static property cannot be modified
};



// Constructor arguments order:
// ID, publicName, controlType, 
// NRPN, converter, maxValue, defaultValue, 
// width, height, centerPoint
struct ParameterProperties
{
	StaticProperty<String> ID;
	StaticProperty<String> publicName;
	StaticProperty<ControlType> controlType;
	StaticProperty<uint16> NRPN;
	StaticProperty<IntToContextualStringConverter*> converter;
	StaticProperty<uint8> maxValue;
	StaticProperty<uint16> numberOfSteps{ maxValue + 1 };
	StaticProperty<uint8> defaultValue;
	StaticProperty<uint8> width;
	StaticProperty<uint8> height;
	StaticProperty<Point<int>> centerPoint;

	ParameterProperties() :
		ID{ "null" },
		publicName{ "null" },
		controlType{ ControlType::nullControl },
		NRPN{ 16383 },
		converter{ IntToNullString::get() },
		maxValue{ 0 },
		defaultValue{ 0 },
		width{ 0 },
		height{ 0 },
		centerPoint{ Point<int>(0, 0) }
	{
	}

	ParameterProperties
	(
		String ID, String publicName, ControlType controlType, uint16 NRPN,
		IntToContextualStringConverter* converter, uint8 maxValue, uint8 defaultValue,
		uint8 width, uint8 height, Point<int> centerPoint
	) :
		ID{ ID },
		publicName{ publicName },
		controlType{ controlType },
		NRPN{ NRPN },
		converter{ converter },
		maxValue{ maxValue },
		defaultValue{ defaultValue },
		width{ width },
		height{ height },
		centerPoint{ centerPoint }
	{
	}
};



