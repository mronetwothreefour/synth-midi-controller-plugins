#include "randomization_SeqTrackOptionsComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



SeqTrackRandomizationOptionsComponent::SeqTrackRandomizationOptionsComponent(int trackNum, UnexposedParameters* unexposedParams) :
	trackNum{ trackNum },
	unexposedParams{ unexposedParams },
	editMode{ trackNum, unexposedParams },
	probabilites{ trackNum, unexposedParams },
	allowedValues{ trackNum, unexposedParams },
	allowedNotes{ trackNum, unexposedParams },
	allowedOctaves{ trackNum, unexposedParams }
{
	jassert(trackNum > 0 && trackNum < 5);

	addAndMakeVisible(editMode);
	addAndMakeVisible(probabilites);
	addAndMakeVisible(allowedValues);
	addAndMakeVisible(allowedNotes);
	addAndMakeVisible(allowedOctaves);

	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };

	button_ForClosingSeqTrackOptionsComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingSeqTrackOptionsComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingSeqTrackOptionsComponent.onClick = [this] { hideThisComponent(); };
	if (shouldShowDescriptions)
		button_ForClosingSeqTrackOptionsComponent.setTooltip("Click to close this window.");
	addAndMakeVisible(button_ForClosingSeqTrackOptionsComponent);

	setSize(GUI::editor_w, GUI::editor_h);
}

void SeqTrackRandomizationOptionsComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	MemoryInputStream memInputStreamForBackground{ BinaryData::RandomizationOptionsSeqStepsBackground_png, BinaryData::RandomizationOptionsSeqStepsBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStreamForBackground) };
	g.drawImageAt(backgroundImage, GUI::randomizationLFOoptionsBackground_x, GUI::randomizationLFOoptionsBackground_y);
}

void SeqTrackRandomizationOptionsComponent::resized() {
	editMode.setBounds(GUI::bounds_RandomizationEditModeForSeqTrack);
	probabilites.setBounds(trackNum == 1 ? GUI::bounds_RandomizationProbabilitiesForSeqTrack1 : GUI::bounds_RandomizationProbabilitiesForSeqTrack2_3_4);
	allowedValues.setBounds(GUI::bounds_RandomizationAllowedStepValuesForSeqTrack);
	allowedNotes.setBounds(GUI::bounds_RandomizationAllowedNotesForSeqTrack);
	allowedOctaves.setBounds(GUI::bounds_RandomizationAllowedOctavesForSeqTrack);
	button_ForClosingSeqTrackOptionsComponent.setBounds(GUI::bounds_RandomizationSeqTrackOptionsCloseButton);
}

void SeqTrackRandomizationOptionsComponent::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}
