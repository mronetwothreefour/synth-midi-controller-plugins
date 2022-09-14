#pragma once

#include <JuceHeader.h>

class VoiceDataFileFilter :
	public FileFilter
{
public:
	VoiceDataFileFilter() :
		FileFilter{ ".m6gPatch" }
	{
	}

	bool isFileSuitable(const File& file) const override {
		return (file.getFileExtension() == description);
	}

	bool isDirectorySuitable(const File& /*file*/) 	const override {
		return true;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceDataFileFilter)
};




class VoicesBankFileFilter :
	public FileFilter
{
public:
	VoicesBankFileFilter() :
		FileFilter{ ".m6gBank" }
	{
	}

	bool isFileSuitable(const File& file) const override {
		return (file.getFileExtension() == description);
	}

	bool isDirectorySuitable(const File& /*file*/) 	const override {
		return true;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoicesBankFileFilter)
};