#pragma once

#include <JuceHeader.h>

struct IntToStringConverter
{
	virtual String convert(const int /*i*/, bool /*isVerbose*/) noexcept { return ""; }
};

struct IntToOscPitchConverter : IntToStringConverter
{
	String convert(const int /*i*/, bool /*isVerbose*/) noexcept override { /* conversion operations */ return /* value String */ ""; }
};

struct IntToFineTuneConverter : IntToStringConverter
{
	String convert(const int /*i*/, bool /*isVerbose*/) noexcept override { /* conversion operations */ return /* value String */ ""; }
};

struct IntToStringConverterCatalog
{
	IntToOscPitchConverter intToOscPitchConverter;
	IntToFineTuneConverter intToFineTuneConverter;
};

struct IntToStringConverterBuilder
{
	IntToOscPitchConverter intToOscPitch;
	IntToStringConverter& get(int ctrlType) 
	{ 
		if (ctrlType == 0)
		{
			return intToStringConverterCatalog.intToOscPitchConverter;
		}
		if (ctrlType == 1)
		{
			return intToStringConverterCatalog.intToFineTuneConverter;
		}
		else return intToStringConverterCatalog.intToOscPitchConverter;
	}

	IntToStringConverterCatalog intToStringConverterCatalog;

};

struct Wubba {};

struct Dingle
{
	static int returnInt() { return 1; }
	friend struct Wubba;
};

struct Murple
{
	int fleeb = Dingle::returnInt();
};
