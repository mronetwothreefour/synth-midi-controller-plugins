#pragma once

template <typename T>
struct StaticProperty
{
	T value;

	explicit StaticProperty(const T initial_value) { value = initial_value; }

	operator T() { return value; }

	T operator = (T new_value) = delete; // the value of a static property cannot be modified
};

