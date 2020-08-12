#include "gui_InfoForMainWindowLabels_Singleton.h"

#include "gui_Fonts.h"



InfoForMainWindowLabels::InfoForMainWindowLabels() {
	fillAllInfoContainers();
}

void InfoForMainWindowLabels::fillAllInfoContainers() {
	static const auto ctrlLabel_h{ 14 };
	static const auto sectionLabel_h{ 20 };
	static const auto knobLabel_w{ 44 };
	static const auto largeNumLabel_w{ 16 };
	static const auto largeNumLabel_h{ 26 };
	static const auto horizGapBtwnLabels{ 1 };
	static const auto labelsCol1_x{ 48 };
	static const auto labelsCol2_x{ labelsCol1_x + knobLabel_w + horizGapBtwnLabels };
	static const auto labelsCol3_x{ labelsCol2_x + knobLabel_w + horizGapBtwnLabels };
	static const auto labelsCol4_x{ labelsCol3_x + knobLabel_w + horizGapBtwnLabels };
	static const auto labelsCol5_x{ labelsCol4_x + knobLabel_w + horizGapBtwnLabels };
	static const auto labelsCol6_x{ labelsCol5_x + knobLabel_w + horizGapBtwnLabels };
	static const auto labelsCol7_x{ labelsCol6_x + knobLabel_w + horizGapBtwnLabels };
	static const auto labelsCol8_x{ labelsCol7_x + knobLabel_w + horizGapBtwnLabels };
	static const auto labelsCol9_x{ labelsCol8_x + knobLabel_w + horizGapBtwnLabels };
	static const auto labelsCol10_x{ 500 };
	static const auto oscCtrlLabelsRow1_y{ 73 };
	static const auto oscCtrlLabelsRow2_y{ 133 };
	static const auto lpfCtrlLabelsRow1_y{ 176 };
	static const auto lpfCtrlLabelsRow2_y{ 238 };
	static const auto lpfCtrlLabelsRow3_y{ 290 };
	static const auto vcaCtrlLabelsRow1_y{ 396 };
	static const auto vcaCtrlLabelsRow2_y{ 448 };
	static const auto env3CtrlLabelsRow1_y{ 554 };
	static const auto env3CtrlLabelsRow2_y{ 606 };
	static const auto modulatorNumLabel_x{ 412 };
	static const auto modulatorLabelsCol1_x{ 486 };
	static const auto modulatorLabelsCol2_x{ 575 };
	static const auto modulatorComboBoxLabels_w{ 126 };
	static const auto midiControllerLabelsCol1_x{ 680 };
	static const auto midiControllerLabelsCol2_x{ 776 };
	static const auto midiControllerComboBoxLabels_w{ 1326 };
	static const auto seqTrackLabels_x{ 846 };
	static const auto seqTrackLabels_w{ 68 };
	static const auto seqTrackDestLabels_x{ 951 };
	static const auto seqTrackDestLabels_w{ 74 };
	static const auto seqStepLabels_w{ 26 };
	static const auto seqStepLabels_h{ 14 };
	static const auto seqStep1Labels_x{ 825 };
	static const auto sequencerStepLabelsHorizontalSpacer{ 28 };
	static const auto seqTrack1StepLabels_y{ 216 };
	static const auto sequencerTracksVerticalSpacer{ 83 };
	static const auto lfoSectionLabels_y{ 485 };
	static const auto lfoCtrlLabelsRow1_y{ 538 };
	static const auto lfoCtrlLabelsRow2_y{ 575 };
	static const auto lfoCtrlLabelsRow3_y{ 609 };
	static const auto lfoKeyLabels_y{ 530 };
	static const auto lfoSyncLabels_y{ 539 };
	static const auto knobAssignLargeNumLabels_x{ 1011 };

	//======================================================

	labelTexts.add("OSCILLATORS");
	centerPoints.add(juce::Point<int>(67, 19));
	widths.add(104);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("HARD SYNC");
	centerPoints.add(juce::Point<int>(231, 22));
	widths.add(62);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centredRight);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("1");
	centerPoints.add(juce::Point<int>(23, 48));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(juce::Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("PITCH");
	centerPoints.add(juce::Point<int>(labelsCol1_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("FINE");
	centerPoints.add(juce::Point<int>(labelsCol2_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SHAPE");
	centerPoints.add(juce::Point<int>(labelsCol3_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("GLIDE");
	centerPoints.add(juce::Point<int>(labelsCol4_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SUB");
	centerPoints.add(juce::Point<int>(labelsCol5_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(juce::Point<int>(labelsCol6_x, 65));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("TRACK");
	centerPoints.add(juce::Point<int>(labelsCol6_x, 74));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("2");
	centerPoints.add(juce::Point<int>(23, 108));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(juce::Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("PITCH");
	centerPoints.add(juce::Point<int>(labelsCol1_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("FINE");
	centerPoints.add(juce::Point<int>(labelsCol2_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SHAPE");
	centerPoints.add(juce::Point<int>(labelsCol3_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("GLIDE");
	centerPoints.add(juce::Point<int>(labelsCol4_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SUB");
	centerPoints.add(juce::Point<int>(labelsCol5_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(juce::Point<int>(labelsCol6_x, 125));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("TRACK");
	centerPoints.add(juce::Point<int>(labelsCol6_x, 134));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("SLOP");
	centerPoints.add(juce::Point<int>(labelsCol7_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("MIX");
	centerPoints.add(juce::Point<int>(labelsCol8_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("1");
	centerPoints.add(juce::Point<int>(347, 68));
	widths.add(10);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForOscMix1and2Labels);
	labelTexts.add("2");
	centerPoints.add(juce::Point<int>(379, 68));
	widths.add(10);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForOscMix1and2Labels);

	labelTexts.add("BEND");
	centerPoints.add(juce::Point<int>(labelsCol9_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("NOISE");
	centerPoints.add(juce::Point<int>(labelsCol7_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("EXT IN");
	centerPoints.add(juce::Point<int>(labelsCol8_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("ARPEG");
	centerPoints.add(juce::Point<int>(labelsCol9_x, 125));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("NOTE PRIORITY");
	centerPoints.add(juce::Point<int>(labelsCol10_x, 53));
	widths.add(124);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("GLIDE MODE");
	centerPoints.add(juce::Point<int>(labelsCol10_x, 93));
	widths.add(124);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("ARPEGGIATOR MODE");
	centerPoints.add(juce::Point<int>(labelsCol10_x, 133));
	widths.add(124);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("PROGRAM NAME");
	centerPoints.add(juce::Point<int>(642, 20));
	widths.add(124);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	//======================================================

	labelTexts.add("LPF");
	centerPoints.add(juce::Point<int>(30, 161));
	widths.add(30);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("4-POLE");
	centerPoints.add(juce::Point<int>(labelsCol2_x, lpfCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("FREQ");
	centerPoints.add(juce::Point<int>(labelsCol1_x, lpfCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("RESO");
	centerPoints.add(juce::Point<int>(labelsCol2_x, lpfCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(juce::Point<int>(labelsCol3_x, lpfCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("ENV");
	centerPoints.add(juce::Point<int>(labelsCol1_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("VELO");
	centerPoints.add(juce::Point<int>(labelsCol2_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("FM");
	centerPoints.add(juce::Point<int>(labelsCol3_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DELAY");
	centerPoints.add(juce::Point<int>(labelsCol4_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("ATTACK");
	centerPoints.add(juce::Point<int>(labelsCol5_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DECAY");
	centerPoints.add(juce::Point<int>(labelsCol6_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SUST");
	centerPoints.add(juce::Point<int>(labelsCol7_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("RELEASE");
	centerPoints.add(juce::Point<int>(labelsCol8_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("VCA");
	centerPoints.add(juce::Point<int>(30, 319));
	widths.add(34);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("LEVEL");
	centerPoints.add(juce::Point<int>(labelsCol1_x, vcaCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("ENV");
	centerPoints.add(juce::Point<int>(labelsCol2_x, vcaCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("VELO");
	centerPoints.add(juce::Point<int>(labelsCol3_x, vcaCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("VOLUME");
	centerPoints.add(juce::Point<int>(labelsCol2_x, vcaCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DELAY");
	centerPoints.add(juce::Point<int>(labelsCol4_x, vcaCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("ATTACK");
	centerPoints.add(juce::Point<int>(labelsCol5_x, vcaCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DECAY");
	centerPoints.add(juce::Point<int>(labelsCol6_x, vcaCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SUST");
	centerPoints.add(juce::Point<int>(labelsCol7_x, vcaCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("RELEASE");
	centerPoints.add(juce::Point<int>(labelsCol8_x, vcaCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("ENVELOPE 3");
	centerPoints.add(juce::Point<int>(63, 477));
	widths.add(96);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("REPEAT");
	centerPoints.add(juce::Point<int>(labelsCol1_x, 546));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(juce::Point<int>(labelsCol2_x, env3CtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("VELO");
	centerPoints.add(juce::Point<int>(labelsCol3_x, env3CtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(juce::Point<int>(labelsCol2_x, 598));
	widths.add(126);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DELAY");
	centerPoints.add(juce::Point<int>(labelsCol4_x, env3CtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("ATTACK");
	centerPoints.add(juce::Point<int>(labelsCol5_x, env3CtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DECAY");
	centerPoints.add(juce::Point<int>(labelsCol6_x, env3CtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SUST");
	centerPoints.add(juce::Point<int>(labelsCol7_x, env3CtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("RELEASE");
	centerPoints.add(juce::Point<int>(labelsCol8_x, env3CtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("MODULATORS");
	centerPoints.add(juce::Point<int>(457, 161));
	widths.add(106);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("1");
	centerPoints.add(juce::Point<int>(modulatorNumLabel_x, 199));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(juce::Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("SOURCE");
	centerPoints.add(juce::Point<int>(modulatorLabelsCol1_x, 199));
	widths.add(modulatorComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(juce::Point<int>(modulatorLabelsCol2_x, 224));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(juce::Point<int>(modulatorLabelsCol1_x, 233));
	widths.add(modulatorComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("2");
	centerPoints.add(juce::Point<int>(modulatorNumLabel_x, 277));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(juce::Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("SOURCE");
	centerPoints.add(juce::Point<int>(modulatorLabelsCol1_x, 277));
	widths.add(modulatorComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(juce::Point<int>(modulatorLabelsCol2_x, 302));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(juce::Point<int>(modulatorLabelsCol1_x, 311));
	widths.add(modulatorComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("3");
	centerPoints.add(juce::Point<int>(modulatorNumLabel_x, 355));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(juce::Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("SOURCE");
	centerPoints.add(juce::Point<int>(modulatorLabelsCol1_x, 355));
	widths.add(modulatorComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(juce::Point<int>(modulatorLabelsCol2_x, 380));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(juce::Point<int>(modulatorLabelsCol1_x, 389));
	widths.add(modulatorComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("4");
	centerPoints.add(juce::Point<int>(modulatorNumLabel_x, 433));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(juce::Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("SOURCE");
	centerPoints.add(juce::Point<int>(modulatorLabelsCol1_x, 433));
	widths.add(modulatorComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(juce::Point<int>(modulatorLabelsCol2_x, 458));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(juce::Point<int>(modulatorLabelsCol1_x, 467));
	widths.add(modulatorComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("MIDI CONTROLLERS");
	centerPoints.add(juce::Point<int>(687, 161));
	widths.add(150);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("MOD WHEEL DESTINATION");
	centerPoints.add(juce::Point<int>(midiControllerLabelsCol1_x, 206));
	widths.add(midiControllerComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(juce::Point<int>(midiControllerLabelsCol2_x, 214));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("PRESSURE DESTINATION");
	centerPoints.add(juce::Point<int>(midiControllerLabelsCol1_x, 268));
	widths.add(midiControllerComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(juce::Point<int>(midiControllerLabelsCol2_x, 276));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("BREATH DESTINATION");
	centerPoints.add(juce::Point<int>(midiControllerLabelsCol1_x, 330));
	widths.add(midiControllerComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(juce::Point<int>(midiControllerLabelsCol2_x, 338));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("VELOCITY DESTINATION");
	centerPoints.add(juce::Point<int>(midiControllerLabelsCol1_x, 392));
	widths.add(midiControllerComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(juce::Point<int>(midiControllerLabelsCol2_x, 400));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("FOOT PEDAL DESTINATION");
	centerPoints.add(juce::Point<int>(midiControllerLabelsCol1_x, 454));
	widths.add(midiControllerComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(juce::Point<int>(midiControllerLabelsCol2_x, 462));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("SEQUENCER");
	centerPoints.add(juce::Point<int>(877, 127));
	widths.add(94);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("TRIGGER MODE");
	centerPoints.add(juce::Point<int>(998, 141));
	widths.add(124);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("CLOCK DIVISION");
	centerPoints.add(juce::Point<int>(1139, 141));
	widths.add(114);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("BPM");
	centerPoints.add(juce::Point<int>(1236, 149));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("TRACK 1");
	centerPoints.add(juce::Point<int>(seqTrackLabels_x, 170));
	widths.add(seqTrackLabels_w);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(juce::Point<int>(seqTrackDestLabels_x, 169));
	widths.add(seqTrackDestLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centredRight);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("TRACK 2");
	centerPoints.add(juce::Point<int>(seqTrackLabels_x, 253));
	widths.add(seqTrackLabels_w);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(juce::Point<int>(seqTrackDestLabels_x, 252));
	widths.add(seqTrackDestLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centredRight);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("TRACK 3");
	centerPoints.add(juce::Point<int>(seqTrackLabels_x, 336));
	widths.add(seqTrackLabels_w);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(juce::Point<int>(seqTrackDestLabels_x, 335));
	widths.add(seqTrackDestLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centredRight);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("TRACK 4");
	centerPoints.add(juce::Point<int>(seqTrackLabels_x, 419));
	widths.add(seqTrackLabels_w);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(juce::Point<int>(seqTrackDestLabels_x, 418));
	widths.add(seqTrackDestLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centredRight);
	fontSizes.add(FontsDB::size_ForControlLabels);

	for (auto track = 0; track != 4; ++track) {
		for (auto step = 0; step != 16; ++step) {
			labelTexts.add((String)(step + 1));
			auto label_x{ seqStep1Labels_x + (step * sequencerStepLabelsHorizontalSpacer) };
			auto label_y{ seqTrack1StepLabels_y + (track * sequencerTracksVerticalSpacer) };
			centerPoints.add(juce::Point<int>(label_x, label_y));
			widths.add(seqStepLabels_w);
			heights.add(seqStepLabels_h);
			justificationFlags.add(juce::Justification::centred);
			fontSizes.add(FontsDB::size_ForSeqStepLabels);
		}
	}

	//======================================================

	labelTexts.add("LFO 1");
	centerPoints.add(juce::Point<int>(418, lfoSectionLabels_y));
	widths.add(44);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("FREQ");
	centerPoints.add(juce::Point<int>(416, lfoCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(juce::Point<int>(461, lfoCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(juce::Point<int>(507, lfoKeyLabels_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("SYNC");
	centerPoints.add(juce::Point<int>(507, lfoSyncLabels_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SHAPE");
	centerPoints.add(juce::Point<int>(463, lfoCtrlLabelsRow2_y));
	widths.add(134);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(juce::Point<int>(463, lfoCtrlLabelsRow3_y));
	widths.add(134);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("LFO 2");
	centerPoints.add(juce::Point<int>(573, lfoSectionLabels_y));
	widths.add(44);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("FREQ");
	centerPoints.add(juce::Point<int>(571, lfoCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(juce::Point<int>(616, lfoCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(juce::Point<int>(662, lfoKeyLabels_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("SYNC");
	centerPoints.add(juce::Point<int>(662, lfoSyncLabels_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SHAPE");
	centerPoints.add(juce::Point<int>(618, lfoCtrlLabelsRow2_y));
	widths.add(134);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(juce::Point<int>(618, lfoCtrlLabelsRow3_y));
	widths.add(134);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("LFO 3");
	centerPoints.add(juce::Point<int>(726, lfoSectionLabels_y));
	widths.add(44);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("FREQ");
	centerPoints.add(juce::Point<int>(724, lfoCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(juce::Point<int>(769, lfoCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(juce::Point<int>(815, lfoKeyLabels_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("SYNC");
	centerPoints.add(juce::Point<int>(815, lfoSyncLabels_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SHAPE");
	centerPoints.add(juce::Point<int>(771, lfoCtrlLabelsRow2_y));
	widths.add(134);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(juce::Point<int>(771, lfoCtrlLabelsRow3_y));
	widths.add(134);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("LFO 4");
	centerPoints.add(juce::Point<int>(879, lfoSectionLabels_y));
	widths.add(44);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("FREQ");
	centerPoints.add(juce::Point<int>(877, lfoCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(juce::Point<int>(922, lfoCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(juce::Point<int>(968, lfoKeyLabels_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("SYNC");
	centerPoints.add(juce::Point<int>(968, lfoSyncLabels_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SHAPE");
	centerPoints.add(juce::Point<int>(924, lfoCtrlLabelsRow2_y));
	widths.add(134);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(juce::Point<int>(924, lfoCtrlLabelsRow3_y));
	widths.add(134);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("KNOB ASSIGN");
	centerPoints.add(juce::Point<int>(1056, 494));
	widths.add(106);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("1");
	centerPoints.add(juce::Point<int>(knobAssignLargeNumLabels_x, 520));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(juce::Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("2");
	centerPoints.add(juce::Point<int>(knobAssignLargeNumLabels_x, 548));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(juce::Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("3");
	centerPoints.add(juce::Point<int>(knobAssignLargeNumLabels_x, 576));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(juce::Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("4");
	centerPoints.add(juce::Point<int>(knobAssignLargeNumLabels_x, 604));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(juce::Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	//======================================================

	labelTexts.add("PUSH IT!");
	centerPoints.add(juce::Point<int>(1206, 494));
	widths.add(70);
	heights.add(sectionLabel_h);
	justificationFlags.add(juce::Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("PITCH");
	centerPoints.add(juce::Point<int>(1191, 551));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("VELO");
	centerPoints.add(juce::Point<int>(1238, 551));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SWITCH MODE");
	centerPoints.add(juce::Point<int>(1215, 592));
	widths.add(88);
	heights.add(ctrlLabel_h);
	justificationFlags.add(juce::Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
}

InfoForMainWindowLabels::~InfoForMainWindowLabels() {
}

InfoForMainWindowLabels& InfoForMainWindowLabels::get() noexcept {
	static InfoForMainWindowLabels labelsInfo;
	return labelsInfo;
}

const int InfoForMainWindowLabels::labelOutOfRange() const noexcept {
	return labelTexts.size();
}

const juce::String InfoForMainWindowLabels::textFor(juce::uint16 labelIndex) const {
	return labelTexts[labelIndex];
}

const juce::Point<int> InfoForMainWindowLabels::centerPointFor(juce::uint16 labelIndex) const {
	return centerPoints[labelIndex];
}

const int InfoForMainWindowLabels::widthFor(juce::uint16 labelIndex) const {
	return widths[labelIndex];
}

const int InfoForMainWindowLabels::heightFor(juce::uint16 labelIndex) const {
	return heights[labelIndex];
}

const int InfoForMainWindowLabels::justificationFlagFor(juce::uint16 labelIndex) const {
	return justificationFlags[labelIndex];
}

const float InfoForMainWindowLabels::fontSizeFor(juce::uint16 labelIndex) const {
	return fontSizes[labelIndex];
}

