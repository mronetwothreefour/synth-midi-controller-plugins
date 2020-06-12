#pragma once

#include <JuceHeader.h>

// This file is used just for trying out code ideas
// without cluttering up any actual project files

struct Class1
{
	explicit Class1(int) {}
};

struct Class2
{
	explicit Class2(float) {}
};

template <class classType>
class ClassBuilder
{
public:
	static classType build()
	{
		if (classType == Class1)
		{
			Class1 class1{ 1 };
			return class1;
		}

		if (classType == Class2)
		{
			Class1 class2{ 2.0f };
			return class2;
		}
	}
};

struct example
{
	example()
	{
		auto dingle{ ClassBuilder<Class1>::build() };
	}
};

template <typename T>
class Base
{
	public T a;
};

template <typename T>
class Derived : public Base<T>
{
	
};