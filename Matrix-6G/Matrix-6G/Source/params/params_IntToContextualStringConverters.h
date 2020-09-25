#pragma once

#include <JuceHeader.h>



struct IntToPitchName {
	static String convert(const uint8& i) noexcept;
};




struct IntToContextualStringConverter
{
protected:
	virtual String conversionAlgorithm(const int8 & i) noexcept = 0;
	virtual String verboseConversionAlgorithm(const int8 & i) noexcept = 0;

public:
	String convert(const int8 & i) noexcept;
	String verboseConvert(const int8 & i) noexcept;
};




struct IntToNullString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const int8& i) noexcept override;
	String verboseConversionAlgorithm(const int8& i) noexcept override;

public:
	static IntToNullString* get() noexcept;
};




struct IntToPlainValueString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const int8& i) noexcept override;
	String verboseConversionAlgorithm(const int8& i) noexcept override;

public:
	static IntToPlainValueString* get() noexcept;
};




struct IntToSignedValueString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const int8& i) noexcept override;
	String verboseConversionAlgorithm(const int8& i) noexcept override;

public:
	static IntToSignedValueString* get() noexcept;
};




struct IntToOscPitchString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const int8& i) noexcept override;
	String verboseConversionAlgorithm(const int8& i) noexcept override;

public:
	static IntToOscPitchString* get() noexcept;
};

