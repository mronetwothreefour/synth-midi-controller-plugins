#pragma once

#include <JuceHeader.h>



class ProgramDataFileFilter :
	public FileFilter
{
public:
	ProgramDataFileFilter() :
		FileFilter{ ".p600gPgm" }
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
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramDataFileFilter)
};




class ProgramDataBankFileFilter :
	public FileFilter
{
public:
	ProgramDataBankFileFilter() :
		FileFilter{ ".p600gBank" }
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
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramDataBankFileFilter)
};