#pragma once

#include <JuceHeader.h>



struct ConvertRawProgramDataFormat
{
	static const std::vector<uint8> hexStringToDataVector(const String& hexString);
	static const String dataVectorToHexString(const std::vector<uint8>& dataVector);
};

