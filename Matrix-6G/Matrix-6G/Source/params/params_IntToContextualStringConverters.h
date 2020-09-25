#pragma once

#include <JuceHeader.h>



struct IntToPitchName {
	static String convert(const uint8& i) noexcept;
};




struct IntToContextualStringConverter
{
protected:
	virtual String conversionAlgorithm(const uint8& i) noexcept = 0;
	virtual String verboseConversionAlgorithm(const uint8& i) noexcept = 0;

public:
	String convert(const uint8& i) noexcept;
	String verboseConvert(const uint8& i) noexcept;
};




struct IntToNullString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToNullString* get() noexcept;
};




struct IntToPlainValueString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToPlainValueString* get() noexcept;
};




struct IntToPosNegValueString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToPosNegValueString* get() noexcept;
};




struct IntToOscPitchString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToOscPitchString* get() noexcept;
};

