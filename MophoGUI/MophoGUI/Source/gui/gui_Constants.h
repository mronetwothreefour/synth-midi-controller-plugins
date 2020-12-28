#pragma once



namespace constants
{
	namespace GUI
	{
		static const int bankTransmitTitleLabel_x{ 454 };
		static const int bankTransmitTitleLabel_y{ 260 };
		static const int comboBox_h{ 16 };
		static const int controlsCol1_x{ 48 };
		static const int controlsCol2_x{ controlsCol1_x + knob_diameter + horizGapBtwnControls };
		static const int controlsCol3_x{ controlsCol2_x + knob_diameter + horizGapBtwnControls };
		static const int controlsCol4_x{ controlsCol3_x + knob_diameter + horizGapBtwnControls };
		static const int controlsCol5_x{ controlsCol4_x + knob_diameter + horizGapBtwnControls };
		static const int controlsCol6_x{ controlsCol5_x + knob_diameter + horizGapBtwnControls };
		static const int controlsCol7_x{ controlsCol6_x + knob_diameter + horizGapBtwnControls };
		static const int controlsCol8_x{ controlsCol7_x + knob_diameter + horizGapBtwnControls };
		static const int controlsCol9_x{ controlsCol8_x + knob_diameter + horizGapBtwnControls };
		static const int controlsCol10_x{ 500 };
		static const int editor_w{ 1273 };
		static const int editor_h{ 626 };
		static const int env3ControlsRow1_y{ 531 };
		static const int env3ControlsRow2_y{ 583 };
		static const int horizGapBtwnControls{ 5 };
		static const int knobAssignComboBoxes_w{ 134 };
		static const int knobAssignComboBoxes_x{ 1089 };
		static const int knob_diameter{ 40 };
		static const int lfoControlsRow1_y{ 515 };
		static const int lfoControlsRow2_y{ 560 };
		static const int lfoControlsRow3_y{ 594 };
		static const int lfoControlsHorizontalSpacing{ 155 };
		static const int lpfControlsRow1_y{ 161 };
		static const int lpfControlsRow2_y{ 215 };
		static const int lpfControlsRow3_y{ 267 };
		static const int midiControllerComboBox_w{ 136 };
		static const int midiControllersCol1_x{ 680 };
		static const int midiControllersCol2_x{ 776 };
		static const int modulatorComboBox_w{ 126 };
		static const int modulatorControlsCol1_x{ 486 };
		static const int modulatorControlsCol2_x{ 575 };
		static const int modulatorControlsVerticalSpacing{ 78 };
		static const int oscControlsRow1_y{ 50 };
		static const int oscControlsRow2_y{ 110 };
		static const int pgmNameCharacter1_x{ 596 };
		static const int pgmNameCharactersHorizontalSpacer{ 14 };
		static const int pgmNameCharacters_h{ 17 };
		static const int pgmNameCharacters_w{ 12 };
		static const int pgmNameCharacters_y{ 52 };
		static const int programBanksControls_w{ 50 };
		static const int programBanksControls_h{ 22 };
		static const int programBanksControls_y{ 477 };
		static const int programSlotRadioButtton_w{ 125 };
		static const int programSlotRadioButtton_h{ 19 };
		static const int programSlotRadioButtonsHorizontalGap{ 7 };
		static const int programSlotsWidget_w{ (8 * programSlotRadioButtton_w) + (7 * programSlotRadioButtonsHorizontalGap) };
		static const int programSlotsWidget_h{ 16 * programSlotRadioButtton_h };
		static const int sequencerStep1_x{ 825 };
		static const int sequencerStepsHorizontalSpacer{ 28 };
		static const int sequencerTrack1Steps_y{ 196 };
		static const int sequencerTracksVerticalSpacer{ 83 };
		static const int seqSteps_w{ 26 };
		static const int seqSteps_h{ 26 };
		static const int seqTrackDestComboBoxes_w{ 126 };
		static const int seqTrackDestComboBoxes_x{ 1055 };
		static const int toggle_diameter{ 14 };
		static const int vcaControlsRow1_y{ 373 };
		static const int vcaControlsRow2_y{ 425 };

		static const Rectangle<int> bounds_BanksWindow{ 89, 113, 1095, 400 };
		static const Rectangle<int> bounds_BankTransmitButtons{ 611, 344, programBanksControls_w, programBanksControls_h };
		static const Rectangle<int> bounds_BankTransmitMessage{ 461, 290, 351, 28 };
		static const Rectangle<int> bounds_BankTransmitProgressDisplayWindow{ 444, 251, 385, 124 };
		static const Rectangle<int> bounds_BankTransmitProgressBar{ 461, 319,351, 18 };
		static const Rectangle<int> bounds_ProgramBanksCloseButton{ 1130, 117, programBanksControls_w, programBanksControls_h };
		static const Rectangle<int> bounds_ProgramBanksTabbedComponent{ 89, 113, 1095, 400 };
		static const Rectangle<int> bounds_ProgramBanksTransmitTimeLabel{ 1119, programBanksControls_y, programBanksControls_w, programBanksControls_h };

	}
}