#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_Enums.h"
#include "../helpers/helper_Identifiers.h"

class HardwareParameterDatabase
{
public:
	HardwareParameterDatabase() :
		identifier_{ "" },
		nrpn_{ -1 },
		numberOfSteps_{ 0 },
		ctrlType_{ -1 }
	{}

	HardwareParameterDatabase(Identifier identifier, int nrpn, int numberOfSteps, int ctrlType) :
		identifier_{ identifier },
		nrpn_{ nrpn },
		numberOfSteps_{ numberOfSteps },
		ctrlType_{ ctrlType }
	{}


	Identifier get_identifier() const noexcept { return identifier_; }
	void set_identifier() {}
	__declspec(property(get = get_identifier, put = set_identifier)) Identifier identifier;

	int get_nrpn() const noexcept { return nrpn_; }
	void set_nrpn() {}
	__declspec(property(get = get_nrpn, put = set_nrpn)) int nrpn;

	int get_numberOfSteps() const noexcept { return numberOfSteps_; }
	void set_numberOfSteps() {}
	__declspec(property(get = get_numberOfSteps, put = set_numberOfSteps)) int numberOfSteps;

	int get_maxValue() const noexcept { return numberOfSteps_ - 1; }
	void set_maxValue() {}
	__declspec(property(get = get_maxValue, put = set_maxValue)) int maxValue;

	int get_ctrlType() const noexcept { return ctrlType_; }
	void set_ctrlType() {}
	__declspec(property(get = get_ctrlType, put = set_ctrlType)) int ctrlType;

private:
	const Identifier identifier_;

	const int nrpn_;
	const int numberOfSteps_;
	const int ctrlType_;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HardwareParameterDatabase)
};

class HardwareParameterDBSet
{
public:
	HardwareParameterDatabase& getDB(Identifier identifier)
	{
		for (HardwareParameterDatabase& db : hardwareParamDBs_)
		{
			if (db.identifier == identifier) return db;
		}
		return {};
	}

	HardwareParameterDatabase& getDB(int index)
	{
		if (index > -1 && index < hardwareParamDBs_.size())
			return hardwareParamDBs_[index];
		else return {};
	}

private:
	Array<HardwareParameterDatabase&> hardwareParamDBs_{};
	HardwareParameterDBSet()
	{
		/*0  */HardwareParameterDatabase pitchOsc1		{ ID::pitchOsc1		, 0, 121, CTRLTYPE::knob_oscPitch		}; hardwareParamDBs_.add(pitchOsc1		);
		/*1  */HardwareParameterDatabase fineTuneOsc1	{ ID::fineTuneOsc1	, 1, 101, CTRLTYPE::knob_fineTune		}; hardwareParamDBs_.add(pitchOsc1		);
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HardwareParameterDBSet)
};