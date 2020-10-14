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




struct IntToUnsignedValueString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToUnsignedValueString* get() noexcept;
};




struct IntToSigned7bitValueString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToSigned7bitValueString* get() noexcept;
};




struct IntToSigned6bitValueString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToSigned6bitValueString* get() noexcept;
};




struct IntToOscPitchString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToOscPitchString* get() noexcept;
};




struct IntToOsc1SyncString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToOsc1SyncString* get() noexcept;
};




struct IntToOscTypeString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToOscTypeString* get() noexcept;
};




struct IntToLeverControlString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToLeverControlString* get() noexcept;
};




struct IntToOsc1KeyTrackString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToOsc1KeyTrackString* get() noexcept;
};




struct IntToOsc2AndVCFKeyTrackString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToOsc2AndVCFKeyTrackString* get() noexcept;
};




struct IntToOffOnString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToOffOnString* get() noexcept;
};




struct IntToModSourceString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToModSourceString* get() noexcept;
};




struct IntToRampTrigString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToRampTrigString* get() noexcept;
};




struct IntToPortaModeString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToPortaModeString* get() noexcept;
};

