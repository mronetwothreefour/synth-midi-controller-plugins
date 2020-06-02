#pragma once

#include <JuceHeader.h>

#include "../helpers/Identifiers.h"
#include "../helpers/IntToStringConverters.h"

namespace CtrlType
{
	enum HardwareCtrlType
	{
		button_toggle,
		knob_undecorated, knob_oscPitch, knob_fineTune, knob_oscShape, knob_bendRange, knob_lpfFreq,
		knob_modAmount, knob_lfoFreq,
		menu_glideMode, menu_notePriority, menu_lfoShape, menu_modDestination
	};
};

// Stores immutable information for the device's hard-wired parameters.
// The data are treated as properties of a HardwareParameter and can be
// accessed using the format param.string  (e.g. osc1Pitch.nrpn). 
// The data cannot be altered at runtime.
class HardwareParameter
{
public:
	HardwareParameter() :
		identifier_{ "" },
		nrpn_{ -1 },
		numberOfSteps_{ 0 },
		ctrlType_{ -1 },
		converter_{ defaultConverter }
	{}

	HardwareParameter(Identifier identifier, int nrpn, int numberOfSteps, int ctrlType, IntToStringConverter& converter) :
		identifier_{ identifier },
		nrpn_{ nrpn },
		numberOfSteps_{ numberOfSteps },
		ctrlType_{ ctrlType },
		converter_{ converter }
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

	int get_ctrlType() const noexcept { return ctrlType_; }
	void set_ctrlType() {}
	__declspec(property(get = get_ctrlType, put = set_ctrlType)) int ctrlType;

private:
	const Identifier identifier_;

	const int nrpn_;
	const int numberOfSteps_;
	const int ctrlType_;

	IntToStringConverter& converter_;
	IntToStringConverter defaultConverter;
};

struct HardwareParameters
{
	Array<HardwareParameter> propertiesForParameter{};

	HardwareParameters()
	{
		/*0  */HardwareParameter osc1Pitch			{ ID::osc1Pitch			, 0  , 121, CtrlType::knob_oscPitch			, converterBuilder.get(0) }; propertiesForParameter.add(osc1Pitch			);
		/*1  */HardwareParameter osc1Fine			{ ID::osc1Fine			, 1  , 101, CtrlType::knob_fineTune			, converterBuilder.get(1) }; propertiesForParameter.add(osc1Fine			);
		/*2  */HardwareParameter osc1Shape			{ ID::osc1Shape			, 2  , 104, CtrlType::knob_oscShape			, converterBuilder.get(0) }; propertiesForParameter.add(osc1Shape			);
		/*3  */HardwareParameter osc1Glide			{ ID::osc1Glide			, 3  , 128, CtrlType::knob_undecorated		, converterBuilder.get(1) }; propertiesForParameter.add(osc1Glide			);
		/*4  */HardwareParameter osc1KeyTrack		{ ID::osc1KeyTrack		, 4  , 2  , CtrlType::button_toggle			, converterBuilder.get(0) }; propertiesForParameter.add(osc1KeyTrack		);
		/*5  */HardwareParameter osc1SubLevel		{ ID::osc1SubLevel		, 114, 128, CtrlType::knob_undecorated		, converterBuilder.get(1) }; propertiesForParameter.add(osc1SubLevel		);
		
		/*6  */HardwareParameter osc2Pitch			{ ID::osc2Pitch			, 5  , 121, CtrlType::knob_oscPitch			, converterBuilder.get(0) }; propertiesForParameter.add(osc2Pitch			);
		/*7  */HardwareParameter osc2Fine			{ ID::osc2Fine			, 6  , 101, CtrlType::knob_fineTune			, converterBuilder.get(0) }; propertiesForParameter.add(osc2Fine			);
		/*8  */HardwareParameter osc2Shape			{ ID::osc2Shape			, 7  , 104, CtrlType::knob_oscShape			, converterBuilder.get(0) }; propertiesForParameter.add(osc2Shape			);
		/*9  */HardwareParameter osc2Glide			{ ID::osc2Glide			, 8  , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(osc2Glide			);
		/*10 */HardwareParameter osc2KeyTrack		{ ID::osc2KeyTrack		, 9  , 2  , CtrlType::button_toggle			, converterBuilder.get(0) }; propertiesForParameter.add(osc2KeyTrack		);
		/*11 */HardwareParameter osc2SubLevel		{ ID::osc2SubLevel		, 115, 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(osc2SubLevel		);

		/*12 */HardwareParameter oscSync			{ ID::oscSync			, 10 , 2  , CtrlType::button_toggle			, converterBuilder.get(0) }; propertiesForParameter.add(oscSync				);
		/*13 */HardwareParameter glideMode			{ ID::glideMode			, 11 , 4  , CtrlType::menu_glideMode		, converterBuilder.get(0) }; propertiesForParameter.add(glideMode			);
		/*14 */HardwareParameter oscSlop			{ ID::oscSlop			, 12 , 6  , CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(oscSlop				);
		/*15 */HardwareParameter bendRange			{ ID::bendRange			, 93 , 13 , CtrlType::knob_bendRange		, converterBuilder.get(0) }; propertiesForParameter.add(bendRange			);
		/*16 */HardwareParameter notePriority		{ ID::notePriority		, 96 , 6  , CtrlType::menu_notePriority		, converterBuilder.get(0) }; propertiesForParameter.add(notePriority		);
		/*17 */HardwareParameter oscMix				{ ID::oscMix			, 13 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(oscMix				);
		/*18 */HardwareParameter noiseLevel			{ ID::noiseLevel		, 14 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(noiseLevel			);
		/*19 */HardwareParameter extInLevel			{ ID::extInLevel		, 116, 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(extInLevel			);

		/*20 */HardwareParameter lpfFreq			{ ID::lpfFreq			, 15 , 165, CtrlType::knob_lpfFreq			, converterBuilder.get(0) }; propertiesForParameter.add(lpfFreq				);
		/*21 */HardwareParameter lpfReso			{ ID::lpfReso			, 16 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(lpfReso				);
		/*22 */HardwareParameter lpfKeyAmount		{ ID::lpfKeyAmount		, 17 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(lpfKeyAmount		);
		/*23 */HardwareParameter lpfFMamount		{ ID::lpfFMamount		, 18 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(lpfFMamount			);
		/*24 */HardwareParameter lpfType			{ ID::lpfType			, 19 , 2  , CtrlType::button_toggle			, converterBuilder.get(0) }; propertiesForParameter.add(lpfType				);
		/*25 */HardwareParameter lpfEnvAmount		{ ID::lpfEnvAmount		, 20 , 255, CtrlType::knob_modAmount		, converterBuilder.get(0) }; propertiesForParameter.add(lpfEnvAmount		);
		/*26 */HardwareParameter lpfVelAmount		{ ID::lpfVelAmount		, 21 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(lpfVelAmount		);
		/*27 */HardwareParameter lpfDelay			{ ID::lpfDelay			, 22 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(lpfDelay			);
		/*28 */HardwareParameter lpfAttack			{ ID::lpfAttack			, 23 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(lpfAttack			);
		/*29 */HardwareParameter lpfDecay			{ ID::lpfDecay			, 24 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(lpfDecay			);
		/*30 */HardwareParameter lpfSustain			{ ID::lpfSustain		, 25 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(lpfSustain			);
		/*31 */HardwareParameter lpfRelease			{ ID::lpfRelease		, 26 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(lpfRelease			);

		/*32 */HardwareParameter vcaLevel			{ ID::vcaLevel			, 27 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(vcaLevel			);
		/*33 */HardwareParameter vcaEnvAmount		{ ID::vcaEnvAmount		, 30 , 255, CtrlType::knob_modAmount		, converterBuilder.get(0) }; propertiesForParameter.add(vcaEnvAmount		);
		/*34 */HardwareParameter vcaVelAmount		{ ID::vcaVelAmount		, 31 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(vcaVelAmount		);
		/*35 */HardwareParameter vcaDelay			{ ID::vcaDelay			, 32 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(vcaDelay			);
		/*36 */HardwareParameter vcaAttack			{ ID::vcaAttack			, 33 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(vcaAttack			);
		/*37 */HardwareParameter vcaDecay			{ ID::vcaDecay			, 34 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(vcaDecay			);
		/*38 */HardwareParameter vcaSustain			{ ID::vcaSustain		, 35 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(vcaSustain			);
		/*39 */HardwareParameter vcaRelease			{ ID::vcaRelease		, 36 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(vcaRelease			);
		/*40 */HardwareParameter pgmVolume			{ ID::pgmVolume			, 29 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(pgmVolume			);

		/*41 */HardwareParameter lfo1Freq			{ ID::lfo1Freq			, 37 , 167, CtrlType::knob_lfoFreq			, converterBuilder.get(0) }; propertiesForParameter.add(lfo1Freq			);
		/*42 */HardwareParameter lfo1Shape			{ ID::lfo1Shape			, 38 , 5  , CtrlType::menu_lfoShape			, converterBuilder.get(0) }; propertiesForParameter.add(lfo1Shape			);
		/*43 */HardwareParameter lfo1Amount			{ ID::lfo1Amount		, 39 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(lfo1Amount			);
		/*44 */HardwareParameter lfo1Destination	{ ID::lfo1Destination	, 40 , 47 , CtrlType::menu_modDestination	, converterBuilder.get(0) }; propertiesForParameter.add(lfo1Destination		);
		/*45 */HardwareParameter lfo1KeySync		{ ID::lfo1KeySync		, 41 , 2  , CtrlType::button_toggle			, converterBuilder.get(0) }; propertiesForParameter.add(lfo1KeySync			);
		/*46 */HardwareParameter lfo2Freq			{ ID::lfo2Freq			, 42 , 167, CtrlType::knob_lfoFreq			, converterBuilder.get(0) }; propertiesForParameter.add(lfo2Freq			);
		/*47 */HardwareParameter lfo2Shape			{ ID::lfo2Shape			, 43 , 5  , CtrlType::menu_lfoShape			, converterBuilder.get(0) }; propertiesForParameter.add(lfo2Shape			);
		/*48 */HardwareParameter lfo2Amount			{ ID::lfo2Amount		, 44 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(lfo2Amount			);
		/*49 */HardwareParameter lfo2Destination	{ ID::lfo2Destination	, 45 , 47 , CtrlType::menu_modDestination	, converterBuilder.get(0) }; propertiesForParameter.add(lfo2Destination		);
		/*50 */HardwareParameter lfo2KeySync		{ ID::lfo2KeySync		, 46 , 2  , CtrlType::button_toggle			, converterBuilder.get(0) }; propertiesForParameter.add(lfo2KeySync			);
		/*51 */HardwareParameter lfo3Freq			{ ID::lfo3Freq			, 47 , 167, CtrlType::knob_lfoFreq			, converterBuilder.get(0) }; propertiesForParameter.add(lfo3Freq			);
		/*52 */HardwareParameter lfo3Shape			{ ID::lfo3Shape			, 48 , 5  , CtrlType::menu_lfoShape			, converterBuilder.get(0) }; propertiesForParameter.add(lfo3Shape			);
		/*53 */HardwareParameter lfo3Amount			{ ID::lfo3Amount		, 49 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(lfo3Amount			);
		/*54 */HardwareParameter lfo3Destination	{ ID::lfo3Destination	, 50 , 47 , CtrlType::menu_modDestination	, converterBuilder.get(0) }; propertiesForParameter.add(lfo3Destination		);
		/*55 */HardwareParameter lfo3KeySync		{ ID::lfo3KeySync		, 51 , 2  , CtrlType::button_toggle			, converterBuilder.get(0) }; propertiesForParameter.add(lfo3KeySync			);
		/*56 */HardwareParameter lfo4Freq			{ ID::lfo4Freq			, 52 , 167, CtrlType::knob_lfoFreq			, converterBuilder.get(0) }; propertiesForParameter.add(lfo4Freq			);
		/*57 */HardwareParameter lfo4Shape			{ ID::lfo4Shape			, 53 , 5  , CtrlType::menu_lfoShape			, converterBuilder.get(0) }; propertiesForParameter.add(lfo4Shape			);
		/*58 */HardwareParameter lfo4Amount			{ ID::lfo4Amount		, 54 , 128, CtrlType::knob_undecorated		, converterBuilder.get(0) }; propertiesForParameter.add(lfo4Amount			);
		/*59 */HardwareParameter lfo4Destination	{ ID::lfo4Destination	, 55 , 47 , CtrlType::menu_modDestination	, converterBuilder.get(0) }; propertiesForParameter.add(lfo4Destination		);
		/*60 */HardwareParameter lfo4KeySync		{ ID::lfo4KeySync		, 56 , 2  , CtrlType::button_toggle			, converterBuilder.get(0) }; propertiesForParameter.add(lfo4KeySync			);
	}

	IntToStringConverterBuilder converterBuilder;
};

