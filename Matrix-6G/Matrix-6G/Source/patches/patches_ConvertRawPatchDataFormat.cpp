#include "patches_ConvertRawPatchDataFormat.h"



const std::vector<uint8> ConvertRawPatchDataFormat::hexStringToDataVector(const String& hexString) {
	std::vector<uint8> programData;
	for (auto i = 0; i != hexString.length(); i += 2) {
		auto hexValueString{ hexString.substring(i, i + 2) };
		programData.push_back((uint8)hexValueString.getHexValue32());
	}
	return programData;
}

const String ConvertRawPatchDataFormat::dataVectorToHexString(const std::vector<uint8>& dataVector) {
	auto hexString{ String::toHexString(dataVector.data(), (int)dataVector.size(), 0) };
	return hexString;
}
