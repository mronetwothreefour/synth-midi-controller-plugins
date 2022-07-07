#include "rndm_1_comp_SeqTrackProbabilities.h"

using KnobType = SeqTrackProbabilityKnobType;



SeqTrackProbabilities::SeqTrackProbabilities(Track track, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	track{ track },
	knob_DuplicateProbability{ KnobType::duplicate, track, exposedParams, unexposedParams },
	knob_ResetProbability{ KnobType::reset, track, exposedParams, unexposedParams }
{
	auto isTrackOne{ track == Track::one };
	auto knobRow_y{ 19 };

	if (isTrackOne) {
		knob_RestProbability.reset(new KnobForSeqTrackProbability{ KnobType::rest, track, exposedParams, unexposedParams });
		if (knob_RestProbability != nullptr) {
			knob_RestProbability->setTopLeftPosition(0, knobRow_y);
			addAndMakeVisible(knob_RestProbability.get());
		}
	}

	knob_DuplicateProbability.setTopLeftPosition(isTrackOne ? 64 : 8, knobRow_y);
	addAndMakeVisible(knob_DuplicateProbability);

	knob_ResetProbability.setTopLeftPosition(isTrackOne ? 128 : 82, knobRow_y);
	addAndMakeVisible(knob_ResetProbability);

	setSize(isTrackOne ? 168 : 122, 78);
}

void SeqTrackProbabilities::paint(Graphics& g) {
	MemoryBlock mBlock{};
	if (track == Track::one)
		mBlock = MemoryBlock{ BinaryData::bkgrnd_SeqTrack_1_Probabilities_png, BinaryData::bkgrnd_SeqTrack_1_Probabilities_pngSize };
	else
		mBlock = MemoryBlock{ BinaryData::bkgrnd_SeqTracks_2_3_4_Probabilities_png, BinaryData::bkgrnd_SeqTracks_2_3_4_Probabilities_pngSize };
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ mBlock, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

SeqTrackProbabilities::~SeqTrackProbabilities() {
	knob_RestProbability = nullptr;
}
