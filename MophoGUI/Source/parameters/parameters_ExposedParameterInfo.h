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



struct ExposedParameterInfo
{
	StaticProperty<String> ID;
	StaticProperty<String> publicName;
	StaticProperty<ControlType> controlType;
	StaticProperty<uint16> NRPN;
	StaticProperty<IntToContextualStringConverter*> converter;
	StaticProperty<uint8> maxValue;
	StaticProperty<uint16> numberOfSteps{ maxValue + 1 };
	StaticProperty<uint8> defaultValue;
	StaticProperty<String> description;
	StaticProperty<uint8> ctrlWidth;
	StaticProperty<uint8> ctrlHeight;
	StaticProperty<Point<int>> ctrlCenterPoint;

	ExposedParameterInfo() :
		ID{ "null" },
		publicName{ "null" },
		controlType{ ControlType::nullControl },
		NRPN{ 16383 },
		converter{ IntToNullString::get() },
		maxValue{ 0 },
		defaultValue{ 0 },
		description{ "null" },
		ctrlWidth{ 0 },
		ctrlHeight{ 0 },
		ctrlCenterPoint{ Point<int>(0, 0) }
	{
	}

	ExposedParameterInfo
	(
		String ID, String publicName, ControlType controlType, uint16 NRPN,
		IntToContextualStringConverter* converter, uint8 maxValue, uint8 defaultValue,
		String description, uint8 ctrlWidth, uint8 ctrlHeight, Point<int> ctrlCenterPoint
	) :
		ID{ ID },
		publicName{ publicName },
		controlType{ controlType },
		NRPN{ NRPN },
		converter{ converter },
		maxValue{ maxValue },
		defaultValue{ defaultValue },
		description{ description },
		ctrlWidth{ ctrlWidth },
		ctrlHeight{ ctrlHeight },
		ctrlCenterPoint{ ctrlCenterPoint }
	{
	}
};



