#include "rndm_0_comp_SeqTrackTargetStep.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_2_tree_ExposedParamsRandomizationOptions.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

SeqTrackTargetStep::SeqTrackTargetStep(Track track, ExposedParamsRandomizationOptions* randomization, TooltipsOptions* tooltips) :
	track{ track },
	randomization{ randomization }
{
	auto shouldShowDescriptions{ tooltips->shouldShowDescription() };

	stepSelector.setComponentID(ID::comp_SeqTrackStepSelector.toString());
	stepSelector.addListener(this);
	StringArray stepList;
	stepList.add("All");
	for (auto step = (int)Step::one; step <= (int)Step::sixteen; ++step)
		stepList.add((String)step);
	stepSelector.addItemList(stepList, 1);
	stepSelector.setSelectedId((int)randomization->targetStepForSeqTrack(track) + 1, dontSendNotification);
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Selects which step in sequencer\n";
		tip += "track " + String((int)track) + " is targeted for editing.";
		stepSelector.setTooltip(tip);
	}
	stepSelector.setBounds(22, 22, 46, GUI::comboBox_h);
	addAndMakeVisible(stepSelector);

	setSize(90, 46);
}

void SeqTrackTargetStep::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_SeqTrackTargetStep_png, BinaryData::bkgrnd_SeqTrackTargetStep_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void SeqTrackTargetStep::comboBoxChanged(ComboBox* /*comboBox*/) {
	auto selectedStep{ stepSelector.getSelectedId() - 1 };
	randomization->setTargetStepForSeqTrack(Step{ selectedStep }, track);
	getParentComponent()->repaint();
}

SeqTrackTargetStep::~SeqTrackTargetStep() {
	stepSelector.removeListener(this);
}
