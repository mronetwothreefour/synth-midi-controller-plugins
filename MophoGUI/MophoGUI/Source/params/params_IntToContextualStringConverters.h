#pragma once

#include <JuceHeader.h>



struct IntToPitchName
{
	static String convert(const uint8& i) noexcept;
	static String convertToSeqStepPitchName(const uint8& i) noexcept;
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




struct IntToOscPitchString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToOscPitchString* get() noexcept;
};




struct IntToFineTuneString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToFineTuneString* get() noexcept;
};




struct IntToOscWaveShapeString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToOscWaveShapeString* get() noexcept;
};




struct IntToOffOnString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToOffOnString* get() noexcept;
};




struct IntToGlideModeString : public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToGlideModeString* get() noexcept;
};




struct IntToBendRangeString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToBendRangeString* get() noexcept;
};




struct IntToNotePriorityString : public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToNotePriorityString* get() noexcept;
};




struct IntToLPFfreqString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToLPFfreqString* get() noexcept;
};




struct IntToLPFtypeString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToLPFtypeString* get() noexcept;
};




struct IntToPlusMinus127String : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToPlusMinus127String* get() noexcept;
};




struct IntToLFOfreqString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToLFOfreqString* get() noexcept;
};




struct IntToLFOshapeString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToLFOshapeString* get() noexcept;
};




struct IntToModDestinationString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToModDestinationString* get() noexcept;
};




struct IntToSeqTrack2DestinationString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToSeqTrack2DestinationString* get() noexcept;
};




struct IntToSeqTrack4DestinationString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToSeqTrack4DestinationString* get() noexcept;
};




struct IntToModSourceString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToModSourceString* get() noexcept;
};




struct IntToPushItModeString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToPushItModeString* get() noexcept;
};




struct IntToClockTempoString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToClockTempoString* get() noexcept;
};




struct IntToClockDivString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToClockDivString* get() noexcept;
};




struct IntToArpegModeString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToArpegModeString* get() noexcept;
};




struct IntToSeqTrigModeString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToSeqTrigModeString* get() noexcept;
};




struct IntToParamNameString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToParamNameString* get() noexcept;
};




struct IntToSeqStepValueString : public IntToContextualStringConverter
{
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToSeqStepValueString* get() noexcept;
};




struct IntToPgmNameCharString : public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToPgmNameCharString* get() noexcept;
};




struct IntToGlobalTransposeString : public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToGlobalTransposeString* get() noexcept;
};




struct IntToGlobalMidiChannelString : public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToGlobalMidiChannelString* get() noexcept;
};




struct IntToMidiControllersOffOnString : public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToMidiControllersOffOnString* get() noexcept;
};




struct IntToMidiClockString : public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToMidiClockString* get() noexcept;
};




struct IntToBalanceTweakString : public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToBalanceTweakString* get() noexcept;
};




struct IntToParameterSendTypeString : public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToParameterSendTypeString* get() noexcept;
};




struct IntToParameterReceiveTypeString : public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToParameterReceiveTypeString* get() noexcept;
};




struct IntToPedalModeString : public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToPedalModeString* get() noexcept;
};




struct IntToMonoStereoString : public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToMonoStereoString* get() noexcept;
};




struct IntToDisabledEnabledString : public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToDisabledEnabledString* get() noexcept;
};




struct IntToSysExOffOnString : public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToSysExOffOnString* get() noexcept;
};




struct IntToShowDontShowString : public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override;
	String verboseConversionAlgorithm(const uint8& i) noexcept override;

public:
	static IntToShowDontShowString* get() noexcept;
};
