#pragma once

#include <JuceHeader.h>

// This file is used just for trying out code ideas
// without cluttering up any actual project files

//====================== Builder
//struct HtmlBuilder;
//
//struct HtmlElement
//{
//	String name;
//	String text;
//	Array<HtmlElement> elements;
//
//	static std::unique_ptr<HtmlBuilder> build(const String& root_name) // factory method
//	{
//		return std::make_unique<HtmlBuilder>(root_name);
//	}
//
//	friend struct HtmlBuilder;
//
//protected:
//	HtmlElement() {}
//	HtmlElement(const String& name, const String& text) :
//		name{ name },
//		text{ text }
//	{}
//};
//
//struct HtmlBuilder
//{
//	HtmlBuilder(String root_name)
//	{
//		root.name = root_name;
//	}
//
//	HtmlBuilder* add_child(String child_name, String child_text)
//	{
//		HtmlElement elem{ child_name, child_text };
//		root.elements.add(elem);
//		return this;
//	}
//
//	operator HtmlElement() const { return root; }
//	HtmlElement root;
//};
//
//struct Dingle
//{
//	Dingle()
//	{
//		auto elem{ HtmlElement::build("ul")
//			->add_child("li", "hello")
//			->add_child("li", "world")
//		};
//	}
//};

//****************************************************************

//====================== CompositeBuilder
//class PersonBuilder;
//
//class Person
//{
//	//address
//	String street_address_;
//	String post_code_;
//	String city_;
//
//	//employment
//	String company_name_;
//	String position_;
//	int annual_income_{ 0 };
//
//	Person() {}
//
//public:
//	static PersonBuilder createPerson();
//
//	friend class PersonBuilder;
//	friend class PersonAddressBuilder;
//	friend class PersonJobBuilder;
//};
//
//class PersonAddressBuilder;
//class PersonJobBuilder;
//
//class PersonBuilderBase
//{
//protected:
//	Person& person; // reference to what we're creating; the actual instance of Person is not in this class
//
//	explicit PersonBuilderBase(Person& person) :
//		person{ person }
//	{}
//
//public:
//	operator Person()
//	{
//		return std::move(person);
//	}
//
//	PersonAddressBuilder lives() const;
//	PersonJobBuilder works() const;
//};
//
//class PersonBuilder : public PersonBuilderBase
//{
//	Person person; // this is the actual instance of the object we are building.
//
//public:
//	PersonBuilder() :
//		PersonBuilderBase{ person }
//	{}
//};
//
//PersonBuilder Person::createPerson()
//{
//	return PersonBuilder{};
//}
//
//class PersonAddressBuilder : public PersonBuilderBase // if this inherited from PersonBuilder, another instance of Person would be created, which we don't want
//{
//	typedef PersonAddressBuilder Self;
//
//public:
//	explicit PersonAddressBuilder(Person& person) :
//		PersonBuilderBase{ person }
//	{}
//
//	Self& at(String street_address)
//	{
//		person.street_address_ = street_address;
//		return *this;
//	}
//
//	Self& with_postcode(String post_code)
//	{
//		person.post_code_ = post_code;
//		return *this;
//	}
//
//	Self& in(String city)
//	{
//		person.city_ = city;
//		return *this;
//	}
//};
//
//class PersonJobBuilder : public PersonBuilderBase
//{
//	typedef PersonJobBuilder Self;
//
//public:
//	explicit PersonJobBuilder(Person& person) :
//		PersonBuilderBase{ person }
//	{}
//
//	Self& at(String company_name)
//	{
//		person.company_name_ = company_name;
//		return *this;
//	}
//
//	Self& as_a(String position)
//	{
//		person.position_ = position;
//		return *this;
//	}
//
//	Self& earning(int annual_income)
//	{
//		person.annual_income_ = annual_income;
//		return *this;
//	}
//};
//
//PersonAddressBuilder PersonBuilderBase::lives() const
//{
//	return PersonAddressBuilder{ person };
//}
//
//inline PersonJobBuilder PersonBuilderBase::works() const
//{
//	return PersonJobBuilder{ person };
//}
//
//struct Oompa
//{
//	Oompa()
//	{
//		Person theDevil = Person::createPerson()
//			.lives()	.at("666 Satan Street")
//						.with_postcode("666 666")
//						.in("The Details")
//			.works()	.at("The Ninth Ring")
//						.as_a("Arch Demon")
//						.earning(-666);
//	}
//};


//****************************************************************

//====================== Factory
//class MyPoint
//{
//	MyPoint(float x, float y) :
//		x{ x },
//		y{ y }
//	{}
//
//public:
//	float x;
//	float y;
//
//	friend struct MyPointFactory;
//};
//
//struct MyPointFactory
//{
//	static MyPoint NewCartesian(float x, float y)
//	{
//		return MyPoint{ x, y };
//	}
//
//	static MyPoint NewPolar(float r, float theta)
//	{
//		return MyPoint{ r * cos(theta), r * sin(theta) };
//	}
//};
//
//struct Dingle
//{
//	MyPoint my_point{ MyPointFactory::NewCartesian(3, 4) };
//};

//****************************************************************

//====================== Inner Factory
class MyPoint
{
	MyPoint(float x, float y) :
		x{ x },
		y{ y }
	{}

	struct MyPointFactory
	{
	private:
		MyPointFactory() {}

	public:
		static MyPoint NewCartesian(float x, float y)
		{
			return MyPoint{ x, y };
		}

		static MyPoint NewPolar(float r, float theta)
		{
			return MyPoint{ r * cos(theta), r * sin(theta) };
		}
	};

public:
	float x;
	float y;

	static MyPointFactory Factory;
};

struct Dingle
{
	MyPoint my_point{ MyPoint::Factory.NewCartesian(3, 4) };
};