#include "helper_InfoForMainWindowLabels_Singleton.h"

InfoForMainWindowLabels::InfoForMainWindowLabels() {
	fillAllInfoContainers();
}

void InfoForMainWindowLabels::fillAllInfoContainers() {
	const auto ctrlLabel_h{ 14 };
	const auto sectionLabel_h{ 20 };
	const auto knobLabel_w{ 44 };
	const auto largeNumLabel_w{ 16 };
	const auto largeNumLabel_h{ 26 };
	const auto horizGapBtwnLabels{ 1 };
	const auto labelsCol1_x{ 48 };
	const auto labelsCol2_x{ labelsCol1_x + knobLabel_w + horizGapBtwnLabels };
	const auto labelsCol3_x{ labelsCol2_x + knobLabel_w + horizGapBtwnLabels };
	const auto labelsCol4_x{ labelsCol3_x + knobLabel_w + horizGapBtwnLabels };
	const auto labelsCol5_x{ labelsCol4_x + knobLabel_w + horizGapBtwnLabels };
	const auto labelsCol6_x{ labelsCol5_x + knobLabel_w + horizGapBtwnLabels };
	const auto labelsCol7_x{ labelsCol6_x + knobLabel_w + horizGapBtwnLabels };
	const auto labelsCol8_x{ labelsCol7_x + knobLabel_w + horizGapBtwnLabels };
	const auto labelsCol9_x{ labelsCol8_x + knobLabel_w + horizGapBtwnLabels };
	const auto labelsCol10_x{ 500 };
	const auto oscCtrlLabelsRow1_y{ 73 };
	const auto oscCtrlLabelsRow2_y{ 133 };
	const auto lpfCtrlLabelsRow1_y{ 176 };
	const auto lpfCtrlLabelsRow2_y{ 238 };
	const auto lpfCtrlLabelsRow3_y{ 290 };
	const auto vcaCtrlLabelsRow1_y{ 396 };
	const auto vcaCtrlLabelsRow2_y{ 448 };
	const auto env3CtrlLabelsRow1_y{ 554 };
	const auto env3CtrlLabelsRow2_y{ 606 };
	const auto modulatorNumLabel_x{ 412 };
	const auto modulatorLabelsCol1_x{ 486 };
	const auto modulatorLabelsCol2_x{ 575 };
	const auto modulatorComboBoxLabels_w{ 126 };
	const auto midiControllerLabelsCol1_x{ 680 };
	const auto midiControllerLabelsCol2_x{ 776 };
	const auto midiControllerComboBoxLabels_w{ 1326 };
	const auto seqTrackLabels_x{ 846 };
	const auto seqTrackLabels_w{ 68 };
	const auto seqTrackDestLabels_x{ 951 };
	const auto seqTrackDestLabels_w{ 74 };
	const auto seqStepLabels_w{ 26 };
	const auto seqStepLabels_h{ 14 };
	const auto seqStep1Labels_x{ 825 };
	const auto sequencerStepLabelsHorizontalSpacer{ 28 };
	const auto seqTrack1StepLabels_y{ 216 };
	const auto sequencerTracksVerticalSpacer{ 83 };
	const auto lfoSectionLabels_y{ 485 };
	const auto lfoCtrlLabelsRow1_y{ 538 };
	const auto lfoCtrlLabelsRow2_y{ 575 };
	const auto lfoCtrlLabelsRow3_y{ 609 };
	const auto lfoKeyLabels_y{ 530 };
	const auto lfoSyncLabels_y{ 539 };
	const auto knobAssignLargeNumLabels_x{ 1011 };

	//======================================================

	labelTexts.add("OSCILLATORS");
	centerPoints.add(Point<int>(67, 19));
	widths.add(104);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("HARD SYNC");
	centerPoints.add(Point<int>(231, 22));
	widths.add(62);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centredRight);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("1");
	centerPoints.add(Point<int>(23, 48));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("PITCH");
	centerPoints.add(Point<int>(labelsCol1_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("FINE");
	centerPoints.add(Point<int>(labelsCol2_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SHAPE");
	centerPoints.add(Point<int>(labelsCol3_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("GLIDE");
	centerPoints.add(Point<int>(labelsCol4_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SUB");
	centerPoints.add(Point<int>(labelsCol5_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(Point<int>(labelsCol6_x, 65));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("TRACK");
	centerPoints.add(Point<int>(labelsCol6_x, 74));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("2");
	centerPoints.add(Point<int>(23, 108));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("PITCH");
	centerPoints.add(Point<int>(labelsCol1_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("FINE");
	centerPoints.add(Point<int>(labelsCol2_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SHAPE");
	centerPoints.add(Point<int>(labelsCol3_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("GLIDE");
	centerPoints.add(Point<int>(labelsCol4_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SUB");
	centerPoints.add(Point<int>(labelsCol5_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(Point<int>(labelsCol6_x, 125));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("TRACK");
	centerPoints.add(Point<int>(labelsCol6_x, 134));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("SLOP");
	centerPoints.add(Point<int>(labelsCol7_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("MIX");
	centerPoints.add(Point<int>(labelsCol8_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("1");
	centerPoints.add(Point<int>(347, 68));
	widths.add(10);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForOscMix1and2Labels);
	labelTexts.add("2");
	centerPoints.add(Point<int>(379, 68));
	widths.add(10);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForOscMix1and2Labels);

	labelTexts.add("BEND");
	centerPoints.add(Point<int>(labelsCol9_x, oscCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("NOISE");
	centerPoints.add(Point<int>(labelsCol7_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("EXT IN");
	centerPoints.add(Point<int>(labelsCol8_x, oscCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("ARPEG");
	centerPoints.add(Point<int>(labelsCol9_x, 125));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("GLIDE MODE");
	centerPoints.add(Point<int>(labelsCol10_x, 53));
	widths.add(124);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("NOTE PRIORITY");
	centerPoints.add(Point<int>(labelsCol10_x, 93));
	widths.add(124);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("ARPEGGIATOR MODE");
	centerPoints.add(Point<int>(labelsCol10_x, 133));
	widths.add(124);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("LPF");
	centerPoints.add(Point<int>(30, 161));
	widths.add(30);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("4-POLE");
	centerPoints.add(Point<int>(labelsCol2_x, lpfCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("FREQ");
	centerPoints.add(Point<int>(labelsCol1_x, lpfCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("RESO");
	centerPoints.add(Point<int>(labelsCol2_x, lpfCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(Point<int>(labelsCol3_x, lpfCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("ENV");
	centerPoints.add(Point<int>(labelsCol1_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("VELO");
	centerPoints.add(Point<int>(labelsCol2_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("FM");
	centerPoints.add(Point<int>(labelsCol3_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DELAY");
	centerPoints.add(Point<int>(labelsCol4_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("ATTACK");
	centerPoints.add(Point<int>(labelsCol5_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DECAY");
	centerPoints.add(Point<int>(labelsCol6_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SUST");
	centerPoints.add(Point<int>(labelsCol7_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("RELEASE");
	centerPoints.add(Point<int>(labelsCol8_x, lpfCtrlLabelsRow3_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("VCA");
	centerPoints.add(Point<int>(30, 319));
	widths.add(34);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("LEVEL");
	centerPoints.add(Point<int>(labelsCol1_x, vcaCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("ENV");
	centerPoints.add(Point<int>(labelsCol2_x, vcaCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("VELO");
	centerPoints.add(Point<int>(labelsCol3_x, vcaCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("VOLUME");
	centerPoints.add(Point<int>(labelsCol2_x, vcaCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DELAY");
	centerPoints.add(Point<int>(labelsCol4_x, vcaCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("ATTACK");
	centerPoints.add(Point<int>(labelsCol5_x, vcaCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DECAY");
	centerPoints.add(Point<int>(labelsCol6_x, vcaCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SUST");
	centerPoints.add(Point<int>(labelsCol7_x, vcaCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("RELEASE");
	centerPoints.add(Point<int>(labelsCol8_x, vcaCtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("ENVELOPE 3");
	centerPoints.add(Point<int>(63, 477));
	widths.add(96);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("REPEAT");
	centerPoints.add(Point<int>(labelsCol1_x, 546));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(Point<int>(labelsCol2_x, env3CtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("VELO");
	centerPoints.add(Point<int>(labelsCol3_x, env3CtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(Point<int>(labelsCol2_x, 598));
	widths.add(126);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DELAY");
	centerPoints.add(Point<int>(labelsCol4_x, env3CtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("ATTACK");
	centerPoints.add(Point<int>(labelsCol5_x, env3CtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DECAY");
	centerPoints.add(Point<int>(labelsCol6_x, env3CtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SUST");
	centerPoints.add(Point<int>(labelsCol7_x, env3CtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("RELEASE");
	centerPoints.add(Point<int>(labelsCol8_x, env3CtrlLabelsRow2_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("MODULATORS");
	centerPoints.add(Point<int>(457, 161));
	widths.add(106);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("1");
	centerPoints.add(Point<int>(modulatorNumLabel_x, 199));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("SOURCE");
	centerPoints.add(Point<int>(modulatorLabelsCol1_x, 199));
	widths.add(modulatorComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(Point<int>(modulatorLabelsCol2_x, 224));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(Point<int>(modulatorLabelsCol1_x, 233));
	widths.add(modulatorComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("2");
	centerPoints.add(Point<int>(modulatorNumLabel_x, 277));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("SOURCE");
	centerPoints.add(Point<int>(modulatorLabelsCol1_x, 277));
	widths.add(modulatorComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(Point<int>(modulatorLabelsCol2_x, 302));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(Point<int>(modulatorLabelsCol1_x, 311));
	widths.add(modulatorComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("3");
	centerPoints.add(Point<int>(modulatorNumLabel_x, 355));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("SOURCE");
	centerPoints.add(Point<int>(modulatorLabelsCol1_x, 355));
	widths.add(modulatorComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(Point<int>(modulatorLabelsCol2_x, 380));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(Point<int>(modulatorLabelsCol1_x, 389));
	widths.add(modulatorComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("4");
	centerPoints.add(Point<int>(modulatorNumLabel_x, 433));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("SOURCE");
	centerPoints.add(Point<int>(modulatorLabelsCol1_x, 433));
	widths.add(modulatorComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(Point<int>(modulatorLabelsCol2_x, 458));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(Point<int>(modulatorLabelsCol1_x, 467));
	widths.add(modulatorComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("MIDI CONTROLLERS");
	centerPoints.add(Point<int>(687, 161));
	widths.add(150);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("MOD WHEEL DESTINATION");
	centerPoints.add(Point<int>(midiControllerLabelsCol1_x, 206));
	widths.add(midiControllerComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(Point<int>(midiControllerLabelsCol2_x, 214));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("PRESSURE DESTINATION");
	centerPoints.add(Point<int>(midiControllerLabelsCol1_x, 268));
	widths.add(midiControllerComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(Point<int>(midiControllerLabelsCol2_x, 276));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("BREATH DESTINATION");
	centerPoints.add(Point<int>(midiControllerLabelsCol1_x, 330));
	widths.add(midiControllerComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(Point<int>(midiControllerLabelsCol2_x, 338));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("VELOCITY DESTINATION");
	centerPoints.add(Point<int>(midiControllerLabelsCol1_x, 392));
	widths.add(midiControllerComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(Point<int>(midiControllerLabelsCol2_x, 400));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("FOOT PEDAL DESTINATION");
	centerPoints.add(Point<int>(midiControllerLabelsCol1_x, 454));
	widths.add(midiControllerComboBoxLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(Point<int>(midiControllerLabelsCol2_x, 462));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("SEQUENCER");
	centerPoints.add(Point<int>(877, 127));
	widths.add(94);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("TRIGGER MODE");
	centerPoints.add(Point<int>(1139, 141));
	widths.add(124);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("CLOCK DIVISION");
	centerPoints.add(Point<int>(998, 141));
	widths.add(114);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("BPM");
	centerPoints.add(Point<int>(1236, 149));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("TRACK 1");
	centerPoints.add(Point<int>(seqTrackLabels_x, 170));
	widths.add(seqTrackLabels_w);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(Point<int>(seqTrackDestLabels_x, 169));
	widths.add(seqTrackDestLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centredRight);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("TRACK 2");
	centerPoints.add(Point<int>(seqTrackLabels_x, 253));
	widths.add(seqTrackLabels_w);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(Point<int>(seqTrackDestLabels_x, 252));
	widths.add(seqTrackDestLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centredRight);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("TRACK 3");
	centerPoints.add(Point<int>(seqTrackLabels_x, 336));
	widths.add(seqTrackLabels_w);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(Point<int>(seqTrackDestLabels_x, 335));
	widths.add(seqTrackDestLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centredRight);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("TRACK 4");
	centerPoints.add(Point<int>(seqTrackLabels_x, 419));
	widths.add(seqTrackLabels_w);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(Point<int>(seqTrackDestLabels_x, 418));
	widths.add(seqTrackDestLabels_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centredRight);
	fontSizes.add(FontsDB::size_ForControlLabels);

	for (auto track = 0; track != 4; ++track) {
		for (auto step = 0; step != 16; ++step) {
			labelTexts.add((String)(step + 1));
			auto label_x{ seqStep1Labels_x + (step * sequencerStepLabelsHorizontalSpacer) };
			auto label_y{ seqTrack1StepLabels_y + (track * sequencerTracksVerticalSpacer) };
			centerPoints.add(Point<int>(label_x, label_y));
			widths.add(seqStepLabels_w);
			heights.add(seqStepLabels_h);
			justificationFlags.add(Justification::centred);
			fontSizes.add(FontsDB::size_ForSeqStepLabels);
		}
	}

	//======================================================

	labelTexts.add("LFO 1");
	centerPoints.add(Point<int>(418, lfoSectionLabels_y));
	widths.add(44);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("FREQ");
	centerPoints.add(Point<int>(416, lfoCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(Point<int>(461, lfoCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(Point<int>(507, lfoKeyLabels_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("SYNC");
	centerPoints.add(Point<int>(507, lfoSyncLabels_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SHAPE");
	centerPoints.add(Point<int>(463, lfoCtrlLabelsRow2_y));
	widths.add(134);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(Point<int>(463, lfoCtrlLabelsRow3_y));
	widths.add(134);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("LFO 2");
	centerPoints.add(Point<int>(573, lfoSectionLabels_y));
	widths.add(44);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("FREQ");
	centerPoints.add(Point<int>(571, lfoCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(Point<int>(616, lfoCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(Point<int>(662, lfoKeyLabels_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("SYNC");
	centerPoints.add(Point<int>(662, lfoSyncLabels_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SHAPE");
	centerPoints.add(Point<int>(618, lfoCtrlLabelsRow2_y));
	widths.add(134);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(Point<int>(618, lfoCtrlLabelsRow3_y));
	widths.add(134);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("LFO 3");
	centerPoints.add(Point<int>(726, lfoSectionLabels_y));
	widths.add(44);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("FREQ");
	centerPoints.add(Point<int>(724, lfoCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(Point<int>(769, lfoCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(Point<int>(815, lfoKeyLabels_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("SYNC");
	centerPoints.add(Point<int>(815, lfoSyncLabels_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SHAPE");
	centerPoints.add(Point<int>(771, lfoCtrlLabelsRow2_y));
	widths.add(134);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(Point<int>(771, lfoCtrlLabelsRow3_y));
	widths.add(134);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("LFO 4");
	centerPoints.add(Point<int>(879, lfoSectionLabels_y));
	widths.add(44);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("FREQ");
	centerPoints.add(Point<int>(877, lfoCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("AMT");
	centerPoints.add(Point<int>(922, lfoCtrlLabelsRow1_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("KEY");
	centerPoints.add(Point<int>(968, lfoKeyLabels_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
	labelTexts.add("SYNC");
	centerPoints.add(Point<int>(968, lfoSyncLabels_y));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SHAPE");
	centerPoints.add(Point<int>(924, lfoCtrlLabelsRow2_y));
	widths.add(134);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("DESTINATION");
	centerPoints.add(Point<int>(924, lfoCtrlLabelsRow3_y));
	widths.add(134);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	//======================================================

	labelTexts.add("KNOB ASSIGN");
	centerPoints.add(Point<int>(1056, 494));
	widths.add(106);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("1");
	centerPoints.add(Point<int>(knobAssignLargeNumLabels_x, 520));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("2");
	centerPoints.add(Point<int>(knobAssignLargeNumLabels_x, 548));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("3");
	centerPoints.add(Point<int>(knobAssignLargeNumLabels_x, 576));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	labelTexts.add("4");
	centerPoints.add(Point<int>(knobAssignLargeNumLabels_x, 604));
	widths.add(largeNumLabel_w);
	heights.add(largeNumLabel_h);
	justificationFlags.add(Justification::centredLeft);
	fontSizes.add(FontsDB::size_ForLargeNumLabels);

	//======================================================

	labelTexts.add("PUSH IT!");
	centerPoints.add(Point<int>(1206, 494));
	widths.add(70);
	heights.add(sectionLabel_h);
	justificationFlags.add(Justification::topLeft);
	fontSizes.add(FontsDB::size_ForSectionLabels);

	labelTexts.add("PITCH");
	centerPoints.add(Point<int>(1191, 551));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("VELO");
	centerPoints.add(Point<int>(1238, 551));
	widths.add(knobLabel_w);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);

	labelTexts.add("SWITCH MODE");
	centerPoints.add(Point<int>(1215, 592));
	widths.add(88);
	heights.add(ctrlLabel_h);
	justificationFlags.add(Justification::centred);
	fontSizes.add(FontsDB::size_ForControlLabels);
}

InfoForMainWindowLabels::~InfoForMainWindowLabels() {
}

InfoForMainWindowLabels& InfoForMainWindowLabels::get() noexcept {
	static InfoForMainWindowLabels labelsInfo;
	return labelsInfo;
}

int InfoForMainWindowLabels::labelOutOfRange() const noexcept {
	return labelTexts.size();
}

String InfoForMainWindowLabels::textFor(uint16 labelIndex) const {
	return labelTexts[labelIndex];
}

Point<int> InfoForMainWindowLabels::centerPointFor(uint16 labelIndex) const {
	return centerPoints[labelIndex];
}

int InfoForMainWindowLabels::widthFor(uint16 labelIndex) const {
	return widths[labelIndex];
}

int InfoForMainWindowLabels::heightFor(uint16 labelIndex) const {
	return heights[labelIndex];
}

int InfoForMainWindowLabels::justificationFlagFor(uint16 labelIndex) const {
	return justificationFlags[labelIndex];
}

float InfoForMainWindowLabels::fontSizeFor(uint16 labelIndex) const {
	return fontSizes[labelIndex];
}

