#include "rndm_1_comp_SeqTrackProbabilities.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace MophoConstants;
using KnobType = SeqTrackProbabilityKnobType;

SeqTrackProbabilities::SeqTrackProbabilities(Track track, ExposedParamsRandomizationOptions* randomization, UnexposedParameters* unexposedParams) :
	track{ track },
	knob_DuplicateProbability{ KnobType::duplicate, track, randomization, unexposedParams },
	knob_ResetProbability{ KnobType::reset, track, randomization, unexposedParams }
{
	auto isTrackOne{ track == Track::one };
	auto knobRow_y{ 19 };

	if (isTrackOne) {
		knob_RestProbability.reset(new KnobForSeqTrackProbability{ KnobType::rest, track, randomization, unexposedParams });
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

	g.setFont(GUI::font_KnobValueDisplays);
	g.setColour(GUI::color_White);
	auto currentValue{ 0 };

	if (track == Track::one) {
		currentValue = roundToInt(knob_RestProbability->getValue() * 100.0);
		g.drawText((String)currentValue + "%", knob_RestProbability->getBounds(), Justification::centred);
	}

	currentValue = roundToInt(knob_DuplicateProbability.getValue() * 100.0);
	g.drawText((String)currentValue + "%", knob_DuplicateProbability.getBounds(), Justification::centred);

	currentValue = roundToInt(knob_ResetProbability.getValue() * 100.0);
	g.drawText((String)currentValue + "%", knob_ResetProbability.getBounds(), Justification::centred);
}

SeqTrackProbabilities::~SeqTrackProbabilities() {
	knob_RestProbability = nullptr;
}