#pragma once

#include <JuceHeader.h>

#include "../helpers/Identifiers.h"

namespace CtrlType
{
	enum HardwareCtrlType
	{
		button_toggle,
		knob_undecorated, knob_oscPitch, knob_fineTune, knob_oscShape
	};
};

// Stores immutable information for the device's hard-wired parameters.
// The data is treated as properties of a HardwareParameter and can be
// accessed using the format param.data  (e.g. osc1Pitch.nrpn). 
// The data cannot be altered at runtime.
class HardwareParameter
{
public:
	HardwareParameter() :
		identifier_{ "" },
		index_{ -1 },
		nrpn_{ -1 },
		numberOfSteps_{ 0 },
		ctrlType_{ -1 }
	{}

	HardwareParameter(Identifier identifier, int index, int nrpn, int numberOfSteps, int ctrlType) :
		identifier_{ identifier },
		index_{ index },
		nrpn_{ nrpn },
		numberOfSteps_{ numberOfSteps },
		ctrlType_{ ctrlType }
	{}

	Identifier get_identifier() const noexcept { return identifier_; }
	void set_identifier() {}
	__declspec(property(get = get_identifier, put = set_identifier)) Identifier identifier;

	int get_index() const noexcept { return index_; }
	void set_index() {}
	__declspec(property(get = get_index, put = set_index)) int index;

	int get_nrpn() const noexcept { return nrpn_; }
	void set_nrpn() {}
	__declspec(property(get = get_nrpn, put = set_nrpn)) int nrpn;

	int get_numberOfSteps() const noexcept { return numberOfSteps_; }
	void set_numberOfSteps() {}
	__declspec(property(get = get_numberOfSteps, put = set_numberOfSteps)) int numberOfSteps;

	int get_ctrlType() const noexcept { return ctrlType_; }
	void set_ctrlType() {}
	__declspec(property(get = get_ctrlType, put = set_ctrlType)) int ctrlType;

private:
	Identifier identifier_;

	int index_;
	int nrpn_;
	int numberOfSteps_;
	int ctrlType_;
};

struct HardwareParameters
{
	Array<HardwareParameter> hardwareParameters{};

	HardwareParameters()
	{
		HardwareParameter osc1Pitch		{ ID::osc1Pitch		, 0  , 0  , 121, CtrlType::knob_oscPitch		}; hardwareParameters.add(osc1Pitch);
		HardwareParameter osc1Fine		{ ID::osc1Fine		, 1  , 1  , 101, CtrlType::knob_fineTune		}; hardwareParameters.add(osc1Fine);
		HardwareParameter osc1Shape		{ ID::osc1Shape		, 2  , 2  , 104, CtrlType::knob_oscShape		}; hardwareParameters.add(osc1Shape);
		HardwareParameter osc1Glide		{ ID::osc1Glide		, 3  , 3  , 128, CtrlType::knob_undecorated		}; hardwareParameters.add(osc1Glide);
		HardwareParameter osc1KeyTrack	{ ID::osc1KeyTrack	, 4  , 4  , 2  , CtrlType::button_toggle		}; hardwareParameters.add(osc1KeyTrack);
		HardwareParameter osc1SubLevel	{ ID::osc1SubLevel	, 5  , 114, 128, CtrlType::knob_undecorated		}; hardwareParameters.add(osc1SubLevel);
		HardwareParameter osc2Pitch		{ ID::osc2Pitch		, 6  , 5  , 121, CtrlType::knob_oscPitch		}; hardwareParameters.add(osc2Pitch);
		HardwareParameter osc2Fine		{ ID::osc2Fine		, 7  , 6  , 101, CtrlType::knob_fineTune		}; hardwareParameters.add(osc2Fine);
		HardwareParameter osc2Shape		{ ID::osc2Shape		, 8  , 7  , 104, CtrlType::knob_oscShape		}; hardwareParameters.add(osc2Shape);
		HardwareParameter osc2Glide		{ ID::osc2Glide		, 9  , 8  , 128, CtrlType::knob_undecorated		}; hardwareParameters.add(osc2Glide);
		HardwareParameter osc2KeyTrack	{ ID::osc2KeyTrack	, 10 , 9  , 2  , CtrlType::button_toggle		}; hardwareParameters.add(osc2KeyTrack);
		HardwareParameter osc2SubLevel	{ ID::osc2SubLevel	, 11 , 115, 128, CtrlType::knob_undecorated		}; hardwareParameters.add(osc2SubLevel);
	}
};

