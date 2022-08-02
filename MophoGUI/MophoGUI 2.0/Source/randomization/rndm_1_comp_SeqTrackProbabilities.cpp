#include "rndm_1_comp_SeqTrackProbabilities.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace MophoConstants;
using KnobType = SeqTrackProbabilityKnobType;

SeqTrackProbabilities::SeqTrackProbabilities(Track track, ExposedParamsRandomizationOptions* randomization, UnexposedParameters* unexposedParams) :
	track{ track },
	knob_ResetProbability{ KnobType::reset, track, randomization, unexposedParams }
{
	auto isTrackOne{ track == Track::one };

	knob_ResetProbability.setTopLeftPosition(12, 1);
	addAndMakeVisible(knob_ResetProbability);

	if (isTrackOne) {
		knob_RestProbability.reset(new KnobForSeqTrackProbability{ KnobType::rest, track, randomization, unexposedParams });
		if (knob_RestProbability != nullptr) {
			knob_RestProbability->setTopLeftPosition(96, 1);
			addAndMakeVisible(knob_RestProbability.get());
		}
	}

	setSize(isTrackOne ? 148 : 64, 68);
}

void SeqTrackProbabilities::paint(Graphics& g) {
	MemoryBlock mBlock{};
	if (track == Track::one)
		mBlock = MemoryBlock{ BinaryData::bkgrnd_SeqTrack_1_Probabilities_png, BinaryData::bkgrnd_SeqTrack_1_Probabilities_pngSize };
	else
		mBlock = MemoryBlock{ BinaryData::bkgrnd_SeqTracks_2_3_4_Probability_png, BinaryData::bkgrnd_SeqTracks_2_3_4_Probability_pngSize };
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ mBlock, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);

	g.setFont(GUI::font_KnobValueDisplays);
	g.setColour(GUI::color_White);
	auto currentValue{ 0 };

	currentValue = roundToInt(knob_ResetProbability.getValue() * 100.0);
	g.drawText((String)currentValue + "%", knob_ResetProbability.getBounds(), Justification::centred);

	if (track == Track::one) {
		currentValue = roundToInt(knob_RestProbability->getValue() * 100.0);
		g.drawText((String)currentValue + "%", knob_RestProbability->getBounds(), Justification::centred);
	}
}

SeqTrackProbabilities::~SeqTrackProbabilities() {
	knob_RestProbability = nullptr;
}
