#pragma once



namespace constants
{
	namespace GUI
	{
		static const float envelopeRenderEnvelopeEnd_x{ 205.0f };
		static const float envelopeRenderEnvelopeStart_x{ 5.0f };
		static const float envelopeRenderMaxSegment_w{ 43.0f };
		static const float envelopeRenderMaximum_y{ 15.0f };
		static const float envelopeRenderMinimum_y{ 75.0f };
		static const float envelopeRenderEnvelope_h{ envelopeRenderMinimum_y - envelopeRenderMaximum_y };
		static const float envelopeRenderSustainSegment_w{ 28.0f };
		static const float tooltipMaxWidth{ 400.0f };

		static const int alertWindowCloseButton_x{ 612 };
		static const int alertWindowCloseButton_y{ 310 };
		static const int bankTransmitTitleLabel_x{ 454 };
		static const int bankTransmitTitleLabel_y{ 260 };
		static const int comboBox_h{ 16 };
		static const int horizGapBtwnControls{ 5 };
		static const int knob_diameter{ 40 };
		static const int clearButtons_h{ 18 };
		static const int clearButtons_w{ 46 };
		static const int clearButtons_x{ 1166 };
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
		static const int editVoiceNameButtonAndLabel_h{ 50 };
		static const int editVoiceNameButtonAndLabel_w{ 222 };
		static const int env3ControlsRow1_y{ 531 };
		static const int env3ControlsRow2_y{ 583 };
		static const int envelopeRenderers_h{ 90 };
		static const int envelopeRenderers_w{ 210 };
		static const int envelopeRenderers_x{ 168 };
		static const int envelopeRenderersVerticalSpacing{ 158 };
		static const int envelopeRenderer_LPF_y{ 154 };
		static const int envelopeRenderer_VCA_y{ envelopeRenderer_LPF_y + envelopeRenderersVerticalSpacing };
		static const int envelopeRenderer_Env3_y{ envelopeRenderer_VCA_y + envelopeRenderersVerticalSpacing };
		static const int fileBrowserIcon_h{ 22 };
		static const int fileBrowserIcon_w{ 32 };
		static const int fileNotValidAlert_x{ 566 };
		static const int fileNotValidAlert_y{ 274 };
		static const int fileOverwriteConfirmBoxButtons_w{ 52 };
		static const int fileOverwriteConfirmBoxButtons_y{ 321 };
		static const int fileOverwriteConfirmBoxCancelButton_x{ 582 };
		static const int fileOverwriteConfirmBoxWriteButton_x{ fileOverwriteConfirmBoxCancelButton_x + fileOverwriteConfirmBoxButtons_w + horizGapBtwnControls };
		static const int fileOverwriteConfirmBox_x{ 556 };
		static const int fileOverwriteConfirmBox_y{ 264 };
		static const int folderExistAlert_x{ 541 };
		static const int folderExistAlert_y{ 274 };
		static const int folderNameDialogBoxButtons_w{ fileOverwriteConfirmBoxButtons_w };
		static const int folderNameDialogBoxButtons_y{ 326 };
		static const int folderNameDialogBoxCancelButton_x{ fileOverwriteConfirmBoxCancelButton_x };
		static const int folderNameDialogBoxCreateButton_x{ fileOverwriteConfirmBoxWriteButton_x };
		static const int folderNameDialogBoxEditor_h{ 26 };
		static const int folderNameDialogBoxEditor_w{ 191 };
		static const int folderNameDialogBoxEditor_x{ 541 };
		static const int folderNameDialogBoxEditor_y{ 293 };
		static const int folderNameDialogBox_h{ 101 };
		static const int folderNameDialogBox_w{ 221 };
		static const int folderNameDialogBox_x{ 526 };
		static const int folderNameDialogBox_y{ 259 };
		static const int globalParametersComboBoxAndDisplayLabel_h{ 16 };
		static const int globalParametersComboBoxes_w{ 117 };
		static const int globalParametersComboBoxes_x{ 630 };
		static const int globalParametersVertSpaceBetweenControls{ 20 };
		static const int globalParametersControlRow1_y{ 226 };
		static const int globalParametersControlRow2_y{ globalParametersControlRow1_y + globalParametersVertSpaceBetweenControls };
		static const int globalParametersControlRow3_y{ globalParametersControlRow2_y + globalParametersVertSpaceBetweenControls };
		static const int globalParametersControlRow4_y{ globalParametersControlRow3_y + globalParametersVertSpaceBetweenControls };
		static const int globalParametersControlRow5_y{ 311 };
		static const int globalParametersControlRow6_y{ globalParametersControlRow5_y + globalParametersVertSpaceBetweenControls };
		static const int globalParametersControlRow7_y{ globalParametersControlRow6_y + globalParametersVertSpaceBetweenControls };
		static const int globalParametersControlRow8_y{ globalParametersControlRow7_y + globalParametersVertSpaceBetweenControls };
		static const int globalParametersControlRow9_y{ globalParametersControlRow8_y + globalParametersVertSpaceBetweenControls };
		static const int globalParametersControlRow10_y{ 441 };
		static const int globalParametersControlRow11_y{ globalParametersControlRow10_y + globalParametersVertSpaceBetweenControls };
		static const int globalParametersControlRow12_y{ globalParametersControlRow11_y + globalParametersVertSpaceBetweenControls };
		static const int globalParametersTooltipControls_x{ 678 };
		static const int globalParametersDisplayLabels_w{ 245 };
		static const int globalParametersDisplayLabels_x{ 514 };
		static const int globalParametersHorizSpaceBetweenKnobs{ 75 };
		static const int globalParametersKnobCol1_x{ 542 };
		static const int globalParametersKnobCol2_x{ globalParametersKnobCol1_x + globalParametersHorizSpaceBetweenKnobs };
		static const int globalParametersKnobCol3_x{ globalParametersKnobCol2_x + globalParametersHorizSpaceBetweenKnobs };
		static const int globalParametersKnobRow_y{ 153 };
		static const int globalParametersTogglesDiameter{ 16 };
		static const int globalParametersWindow_x{ 514 };
		static const int globalParametersWindow_y{ 115 };
		static const int imptExptBrowserComponent_h{ 245 };
		static const int imptExptBrowserComponent_w{ 471 };
		static const int imptExptBrowserComponent_x{ 401 };
		static const int imptExptBrowserComponent_y{ 187 };
		static const int imptExptButtonsRow_y{ 442 };
		static const int imptExptCancelAndOKbuttons_w{ 52 };
		static const int imptExptCancelButton_x{ 763 };
		static const int imptExptCurrentPathBox_h{ 26 };
		static const int imptExptCurrentPathBox_w{ 446 };
		static const int imptExptCurrentPathBox_x{ 0 };
		static const int imptExptCurrentPathBox_y{ 0 };
		static const int imptExptDirContentsBox_h{ 173 };
		static const int imptExptDirContentsBox_w{ imptExptBrowserComponent_w };
		static const int imptExptDirContentsBox_x{ imptExptCurrentPathBox_x };
		static const int imptExptDirContentsBox_y{ 36 };
		static const int imptExptFileNameBox_h{ imptExptCurrentPathBox_h };
		static const int imptExptFileNameBox_w{ 385 };
		static const int imptExptFileNameBox_x{ 86 };
		static const int imptExptFileNameBox_y{ 219 };
		static const int imptExptGoUpButton_h{ imptExptCurrentPathBox_h };
		static const int imptExptGoUpButton_w{ 20 };
		static const int imptExptGoUpButton_x{ 450 };
		static const int imptExptGoUpButton_y{ imptExptCurrentPathBox_y };
		static const int imptExptNewFolderButton_w{ 78 };
		static const int imptExptNewFolderButton_x{ 401 };
		static const int imptExptOKbutton_x{ imptExptCancelButton_x + imptExptCancelAndOKbuttons_w + horizGapBtwnControls };
		static const int imptExptWindow_h{ 332 };
		static const int imptExptWindow_w{ 501 };
		static const int imptExptWindow_x{ 386 };
		static const int imptExptWindow_y{ 147 };
		static const int knobAssignComboBoxes_w{ 134 };
		static const int knobAssignComboBoxes_x{ 1089 };
		static const int lockIcon_h{ 20 };
		static const int lockIcon_w{ 14 };
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
		static const int nrpnIsOffWarningWindow_x{ 396 };
		static const int nrpnIsOffWarningWindow_y{ 205 };
		static const int oscControlsRow1_y{ 50 };
		static const int oscControlsRow2_y{ 110 };
		static const int randomizationButtonsRow_y{ 64 };
		static const int randomizationButtons_w{ 76 };
		static const int randomizationLockAllButton_x{ 909 };
		static const int randomizationUnlockAllButton_x{ randomizationLockAllButton_x + randomizationButtons_w + horizGapBtwnControls };
		static const int randomizeButton_x{ randomizationUnlockAllButton_x + randomizationButtons_w + horizGapBtwnControls };
		static const int randomizationCloseButton_x{ 1152 };
		static const int randomizationLockAndUnlockButtons_h{ clearButtons_h };
		static const int randomizationLockButton_w{ 40 };
		static const int randomizationUnlockButton_w{ 52 };
		static const int randomizationVoiceNameLockButton_x{ 707 };
		static const int randomizationVoiceNameUnlockButton_x{ randomizationVoiceNameLockButton_x + randomizationLockButton_w + horizGapBtwnControls };
		static const int randomizationSeqTrackLockButton_x{ 1161 };
		static const int randomizationSeqTrackUnlockButton_x{ randomizationSeqTrackLockButton_x + randomizationLockButton_w + horizGapBtwnControls };
		static const int secondaryWindowsControls_w{ 50 };
		static const int secondaryWindowsControls_h{ 22 };
		static const int sequencerStep1_x{ 825 };
		static const int sequencerStepsHorizontalSpacer{ 28 };
		static const int sequencerTrack1Steps_y{ 196 };
		static const int sequencerTracksVerticalSpacer{ 83 };
		static const int SeqTrack1RandomizationButtons_y{ 160 };
		static const int seqSteps_w{ 26 };
		static const int seqSteps_h{ 26 };
		static const int SeqTrack1ClearButton_y{ 160 };
		static const int SeqTrack2ClearButton_y{ SeqTrack1ClearButton_y + sequencerTracksVerticalSpacer };
		static const int SeqTrack3ClearButton_y{ SeqTrack2ClearButton_y + sequencerTracksVerticalSpacer };
		static const int SeqTrack4ClearButton_y{ SeqTrack3ClearButton_y + sequencerTracksVerticalSpacer };
		static const int seqTrackDestComboBoxes_w{ 126 };
		static const int seqTrackDestComboBoxes_x{ 1055 };
		static const int sysexIsOffWarningWindow_x{ 386 };
		static const int sysexIsOffWarningWindow_y{ 143 };
		static const int tabBarDepth{ 30 };
		static const int tabForVoicesBank_h{ 370 };
		static const int tabForVoicesBank_w{ 1065 };
		static const int tabbedComponentForVoicesBanks_w{ tabForVoicesBank_w + tabBarDepth };
		static const int tabbedComponentForVoicesBanks_h{ tabForVoicesBank_h };
		static const int tabbedComponentForAllVoicesBanks_w{ tabbedComponentForVoicesBanks_w };
		static const int tabbedComponentForAllVoicesBanks_h{ tabbedComponentForVoicesBanks_h + tabBarDepth };
		static const int toggle_diameter{ 14 };
		static const int toggleLock_diameter{ 22 };
		static const int undoRedoButtons_h{ 22 };
		static const int undoRedoButtons_w{ 44 };
		static const int undoRedoButtons_x{ 837 };
		static const int vcaControlsRow1_y{ 373 };
		static const int vcaControlsRow2_y{ 425 };
		static const int voiceNameCharacter1_x{ 596 };
		static const int voiceNameCharactersHorizontalSpacer{ 14 };
		static const int voiceNameCharacters_h{ 17 };
		static const int voiceNameCharacters_w{ 12 };
		static const int voiceNameCharacters_y{ 52 };
		static const int voiceNameEditButton_y{ 11 };
		static const int voicesBankButtons_y{ 334 };
		static const int voicesBankButtons_horizontalSpacing{ 55 };
		static const int voicesBankLoadButton_x{ 183 };
		static const int voicesBankFactoryPushButton_x{ voicesBankLoadButton_x + voicesBankButtons_horizontalSpacing };
		static const int voicesBankSaveButton_x{ voicesBankLoadButton_x + voicesBankButtons_horizontalSpacing };
		static const int voicesBankCustomPushButton_x{ voicesBankSaveButton_x + voicesBankButtons_horizontalSpacing };
		static const int voicesBankPullButton_x{ voicesBankCustomPushButton_x + voicesBankButtons_horizontalSpacing };
		static const int voicesBankExportButton_x{ voicesBankPullButton_x + voicesBankButtons_horizontalSpacing };
		static const int voicesBankImportButton_x{ voicesBankExportButton_x + voicesBankButtons_horizontalSpacing };
		static const int voicesBankPushEntireBankButton_x{ 638 };
		static const int voicesBankPullEntireBankButton_x{ voicesBankPushEntireBankButton_x + voicesBankButtons_horizontalSpacing };
		static const int voicesBankExportEntireBankButton_x{ voicesBankPullEntireBankButton_x + voicesBankButtons_horizontalSpacing };
		static const int voicesBankImportEntireBankButton_x{ voicesBankExportEntireBankButton_x + voicesBankButtons_horizontalSpacing };
		static const int voicesBanksControls_y{ 477 };
		static const int voiceSlotRadioButtton_w{ 125 };
		static const int voiceSlotRadioButtton_h{ 19 };
		static const int voiceSlotRadioButtonsHorizontalGap{ 7 };
		static const int voiceSlotsWidget_w{ (8 * voiceSlotRadioButtton_w) + (7 * voiceSlotRadioButtonsHorizontalGap) };
		static const int voiceSlotsWidget_h{ 16 * voiceSlotRadioButtton_h };
		static const int windowOutlineThickness{ 2 };
		static const int writeReadBanksGlobalButtons_h{ 22 };
		static const int writeReadBanksGlobalButtons_w{ 53 };
		static const int writeReadBanksGlobalButtons_y{ 83 };

		static const std::vector<uint8> pathDataForFileIcon{ 110,109,133,235,143,65,0,0,0,64,108,0,0,16,65,0,0,0,64,108,0,0,16,65,0,0,160,65,108,0,0,184,65,0,0,160,65,108,0,0,184,65,133,235,225,64,108,133,235,143,65,0,0,0,64,99,109,123,20,146,65,236,81,104,64,108,62,10,171,65,195,245,216,64,108,124,20,146,65,195,245,216,64,108,124,20,146,65,236,81,104,64,99,109,51,51,31,65,236,81,152,65,108,51,51,31,65,164,112,61,64,108,92,143,138,65,164,112,61,64,108,92,143,138,65,21,174,247,64,108,225,122,176,65,21,174,247,64,108,225,122,176,65,236,81,152,65,108,51,51,31,65,236,81,152,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForFolderIcon{ 110,109,0,0,196,65,0,0,192,64,108,0,0,104,65,0,0,192,64,98,51,51,91,65,0,0,192,64,51,51,75,65,102,102,198,64,154,153,73,65,0,0,176,64,108,205,204,68,65,205,204,140,64,98,154,153,65,65,103,102,102,64,205,204,52,65,154,153,57,64,103,102,38,65,154,153,57,64,108,206,204,236,64,154,153,57,64,98,102,102,214,64,0,0,64,64,0,0,192,64,205,204,108,64,0,0,192,64,0,0,144,64,108,0,0,192,64,0,0,140,65,98,0,0,192,64,102,102,146,65,102,102,214,64,0,0,152,65,0,0,240,64,0,0,152,65,108,0,0,196,65,0,0,152,65,98,102,102,202,65,0,0,152,65,0,0,208,65,102,102,146,65,0,0,208,65,0,0,140,65,108,0,0,208,65,0,0,240,64,98,0,0,208,65,102,102,214,64,102,102,202,65,0,0,192,64,0,0,196,65,0,0,192,64,99,109,0,0,240,64,0,0,128,64,108,0,0,40,65,0,0,128,64,98,102,102,46,65,0,0,128,64,205,204,52,65,154,153,137,64,102,102,54,65,102,102,150,64,108,51,51,59,65,153,153,185,64,98,205,204,60,65,51,51,195,64,102,102,62,65,153,153,201,64,153,153,65,65,255,255,207,64,108,153,153,57,65,101,102,230,64,108,0,0,224,64,101,102,230,64,108,0,0,224,64,0,0,144,64,98,0,0,224,64,102,102,134,64,102,102,230,64,0,0,128,64,0,0,240,64,0,0,128,64,99,109,0,0,200,65,0,0,140,65,98,0,0,200,65,102,102,142,65,102,102,198,65,0,0,144,65,0,0,196,65,0,0,144,65,108,0,0,240,64,0,0,144,65,98,102,102,230,64,0,0,144,65,0,0,224,64,102,102,142,65,0,0,224,64,0,0,140,65,108,0,0,224,64,51,51,3,65,108,154,153,65,65,51,51,3,65,108,0,0,80,65,205,204,220,64,98,102,102,86,65,0,0,224,64,0,0,96,65,0,0,224,64,0,0,104,65,0,0,224,64,108,0,0,196,65,0,0,224,64,98,102,102,198,65,0,0,224,64,0,0,200,65,102,102,230,64,0,0,200,65,0,0,240,64,108,0,0,200,65,0,0,140,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row1Col1{ 110,109,0,0,0,64,0,0,0,64,108,0,0,0,0,0,0,0,64,108,0,0,0,0,0,0,0,0,108,0,0,0,64,0,0,0,0,108,0,0,0,64,0,0,0,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row1Col2{ 110,109,0,0,144,64,0,0,0,64,108,0,0,32,64,0,0,0,64,108,0,0,32,64,0,0,0,0,108,0,0,144,64,0,0,0,0,108,0,0,144,64,0,0,0,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row1Col3{ 110,109,0,0,224,64,0,0,0,64,108,0,0,160,64,0,0,0,64,108,0,0,160,64,0,0,0,0,108,0,0,224,64,0,0,0,0,108,0,0,224,64,0,0,0,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row1Col4{ 110,109,0,0,24,65,0,0,0,64,108,0,0,240,64,0,0,0,64,108,0,0,240,64,0,0,0,0,108,0,0,24,65,0,0,0,0,108,0,0,24,65,0,0,0,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row1Col5{ 110,109,0,0,64,65,0,0,0,64,108,0,0,32,65,0,0,0,64,108,0,0,32,65,0,0,0,0,108,0,0,64,65,0,0,0,0,108,0,0,64,65,0,0,0,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row2Col1{ 110,109,0,0,0,64,0,0,144,64,108,0,0,0,0,0,0,144,64,108,0,0,0,0,0,0,32,64,108,0,0,0,64,0,0,32,64,108,0,0,0,64,0,0,144,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row2Col2{ 110,109,0,0,144,64,0,0,144,64,108,0,0,32,64,0,0,144,64,108,0,0,32,64,0,0,32,64,108,0,0,144,64,0,0,32,64,108,0,0,144,64,0,0,144,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row2Col3{ 110,109,0,0,224,64,0,0,144,64,108,0,0,160,64,0,0,144,64,108,0,0,160,64,0,0,32,64,108,0,0,224,64,0,0,32,64,108,0,0,224,64,0,0,144,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row2Col4{ 110,109,0,0,24,65,0,0,144,64,108,0,0,240,64,0,0,144,64,108,0,0,240,64,0,0,32,64,108,0,0,24,65,0,0,32,64,108,0,0,24,65,0,0,144,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row2Col5{ 110,109,0,0,64,65,0,0,144,64,108,0,0,32,65,0,0,144,64,108,0,0,32,65,0,0,32,64,108,0,0,64,65,0,0,32,64,108,0,0,64,65,0,0,144,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row3Col1{ 110,109,0,0,0,64,0,0,224,64,108,0,0,0,0,0,0,224,64,108,0,0,0,0,0,0,160,64,108,0,0,0,64,0,0,160,64,108,0,0,0,64,0,0,224,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row3Col2{ 110,109,0,0,144,64,0,0,224,64,108,0,0,32,64,0,0,224,64,108,0,0,32,64,0,0,160,64,108,0,0,144,64,0,0,160,64,108,0,0,144,64,0,0,224,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row3Col3{ 110,109,0,0,224,64,0,0,224,64,108,0,0,160,64,0,0,224,64,108,0,0,160,64,0,0,160,64,108,0,0,224,64,0,0,160,64,108,0,0,224,64,0,0,224,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row3Col4{ 110,109,0,0,24,65,0,0,224,64,108,0,0,240,64,0,0,224,64,108,0,0,240,64,0,0,160,64,108,0,0,24,65,0,0,160,64,108,0,0,24,65,0,0,224,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row3Col5{ 110,109,0,0,64,65,0,0,224,64,108,0,0,32,65,0,0,224,64,108,0,0,32,65,0,0,160,64,108,0,0,64,65,0,0,160,64,108,0,0,64,65,0,0,224,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row4Col1{ 110,109,0,0,0,64,0,0,24,65,108,0,0,0,0,0,0,24,65,108,0,0,0,0,0,0,240,64,108,0,0,0,64,0,0,240,64,108,0,0,0,64,0,0,24,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row4Col2{ 110,109,0,0,144,64,0,0,24,65,108,0,0,32,64,0,0,24,65,108,0,0,32,64,0,0,240,64,108,0,0,144,64,0,0,240,64,108,0,0,144,64,0,0,24,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row4Col3{ 110,109,0,0,224,64,0,0,24,65,108,0,0,160,64,0,0,24,65,108,0,0,160,64,0,0,240,64,108,0,0,224,64,0,0,240,64,108,0,0,224,64,0,0,24,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row4Col4{ 110,109,0,0,24,65,0,0,24,65,108,0,0,240,64,0,0,24,65,108,0,0,240,64,0,0,240,64,108,0,0,24,65,0,0,240,64,108,0,0,24,65,0,0,24,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row4Col5{ 110,109,0,0,64,65,0,0,24,65,108,0,0,32,65,0,0,24,65,108,0,0,32,65,0,0,240,64,108,0,0,64,65,0,0,240,64,108,0,0,64,65,0,0,24,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row5Col1{ 110,109,0,0,0,64,0,0,64,65,108,0,0,0,0,0,0,64,65,108,0,0,0,0,0,0,32,65,108,0,0,0,64,0,0,32,65,108,0,0,0,64,0,0,64,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row5Col2{ 110,109,0,0,144,64,0,0,64,65,108,0,0,32,64,0,0,64,65,108,0,0,32,64,0,0,32,65,108,0,0,144,64,0,0,32,65,108,0,0,144,64,0,0,64,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row5Col3{ 110,109,0,0,224,64,0,0,64,65,108,0,0,160,64,0,0,64,65,108,0,0,160,64,0,0,32,65,108,0,0,224,64,0,0,32,65,108,0,0,224,64,0,0,64,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row5Col4{ 110,109,0,0,24,65,0,0,64,65,108,0,0,240,64,0,0,64,65,108,0,0,240,64,0,0,32,65,108,0,0,24,65,0,0,32,65,108,0,0,24,65,0,0,64,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row5Col5{ 110,109,0,0,64,65,0,0,64,65,108,0,0,32,65,0,0,64,65,108,0,0,32,65,0,0,32,65,108,0,0,64,65,0,0,32,65,108,0,0,64,65,0,0,64,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row6Col1{ 110,109,0,0,0,64,0,0,104,65,108,0,0,0,0,0,0,104,65,108,0,0,0,0,0,0,72,65,108,0,0,0,64,0,0,72,65,108,0,0,0,64,0,0,104,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row6Col2{ 110,109,0,0,144,64,0,0,104,65,108,0,0,32,64,0,0,104,65,108,0,0,32,64,0,0,72,65,108,0,0,144,64,0,0,72,65,108,0,0,144,64,0,0,104,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row6Col3{ 110,109,0,0,224,64,0,0,104,65,108,0,0,160,64,0,0,104,65,108,0,0,160,64,0,0,72,65,108,0,0,224,64,0,0,72,65,108,0,0,224,64,0,0,104,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row6Col4{ 110,109,0,0,24,65,0,0,104,65,108,0,0,240,64,0,0,104,65,108,0,0,240,64,0,0,72,65,108,0,0,24,65,0,0,72,65,108,0,0,24,65,0,0,104,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row6Col5{ 110,109,0,0,64,65,0,0,104,65,108,0,0,32,65,0,0,104,65,108,0,0,32,65,0,0,72,65,108,0,0,64,65,0,0,72,65,108,0,0,64,65,0,0,104,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row7Col1{ 110,109,0,0,0,64,0,0,136,65,108,0,0,0,0,0,0,136,65,108,0,0,0,0,0,0,112,65,108,0,0,0,64,0,0,112,65,108,0,0,0,64,0,0,136,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row7Col2{ 110,109,0,0,144,64,0,0,136,65,108,0,0,32,64,0,0,136,65,108,0,0,32,64,0,0,112,65,108,0,0,144,64,0,0,112,65,108,0,0,144,64,0,0,136,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row7Col3{ 110,109,0,0,224,64,0,0,136,65,108,0,0,160,64,0,0,136,65,108,0,0,160,64,0,0,112,65,108,0,0,224,64,0,0,112,65,108,0,0,224,64,0,0,136,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row7Col4{ 110,109,0,0,24,65,0,0,136,65,108,0,0,240,64,0,0,136,65,108,0,0,240,64,0,0,112,65,108,0,0,24,65,0,0,112,65,108,0,0,24,65,0,0,136,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForPixel_Row7Col5{ 110,109,0,0,64,65,0,0,136,65,108,0,0,32,65,0,0,136,65,108,0,0,32,65,0,0,112,65,108,0,0,64,65,0,0,112,65,108,0,0,64,65,0,0,136,65,99,101,0,0 };

		static const Rectangle<int> bounds_AlertWindowCloseButton{ alertWindowCloseButton_x, alertWindowCloseButton_y, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_BanksWindow{ 89, 113, 1095, 400 };
		static const Rectangle<int> bounds_BankTransmitButtons{ 611, 344, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_BankTransmitMessage{ 461, 290, 351, 28 };
		static const Rectangle<int> bounds_BankTransmitProgressDisplayWindow{ 446, 253, 381, 120 };
		static const Rectangle<int> bounds_BankTransmitProgressBar{ 461, 319, 351, 18 };
		static const Rectangle<int> bounds_EnvelopeRenderer_LPF{ envelopeRenderers_x, envelopeRenderer_LPF_y, envelopeRenderers_w, envelopeRenderers_h };
		static const Rectangle<int> bounds_EnvelopeRenderer_VCA{ envelopeRenderers_x, envelopeRenderer_VCA_y, envelopeRenderers_w, envelopeRenderers_h };
		static const Rectangle<int> bounds_EnvelopeRenderer_Env3{ envelopeRenderers_x, envelopeRenderer_Env3_y, envelopeRenderers_w, envelopeRenderers_h };
		static const Rectangle<int> bounds_FileOverwriteConfirmBoxCancelButton{ fileOverwriteConfirmBoxCancelButton_x, folderNameDialogBoxButtons_y, folderNameDialogBoxButtons_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_FileOverwriteConfirmBoxWriteButton{ fileOverwriteConfirmBoxWriteButton_x, fileOverwriteConfirmBoxButtons_y, fileOverwriteConfirmBoxButtons_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_FolderNameDialogBox{ folderNameDialogBox_x, folderNameDialogBox_y, folderNameDialogBox_w, folderNameDialogBox_h };
		static const Rectangle<int> bounds_FolderNameDialogBoxCancelButton{ folderNameDialogBoxCancelButton_x, folderNameDialogBoxButtons_y, folderNameDialogBoxButtons_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_FolderNameDialogBoxCreateButton{ folderNameDialogBoxCreateButton_x, folderNameDialogBoxButtons_y, folderNameDialogBoxButtons_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_FolderNameDialogBoxEditor{ folderNameDialogBoxEditor_x, folderNameDialogBoxEditor_y, folderNameDialogBoxEditor_w, folderNameDialogBoxEditor_h };
		static const Rectangle<int> bounds_GlobalParametersAudioOutputDisplayLabel{ globalParametersDisplayLabels_x, globalParametersControlRow8_y, globalParametersDisplayLabels_w, globalParametersComboBoxAndDisplayLabel_h };
		static const Rectangle<int> bounds_GlobalParametersBalanceTweakDisplayLabel{ globalParametersDisplayLabels_x, globalParametersControlRow9_y, globalParametersDisplayLabels_w, globalParametersComboBoxAndDisplayLabel_h };
		static const Rectangle<int> bounds_GlobalParametersCloseButton{ 703, 121, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_GlobalParametersCurrentSettingTooltipToggle{ globalParametersTooltipControls_x, globalParametersControlRow10_y, globalParametersTogglesDiameter, globalParametersTogglesDiameter };
		static const Rectangle<int> bounds_GlobalParametersDescriptionTooltipToggle{ globalParametersTooltipControls_x, globalParametersControlRow11_y, globalParametersTogglesDiameter, globalParametersTogglesDiameter };
		static const Rectangle<int> bounds_GlobalParametersFineTuneKnob{ globalParametersKnobCol2_x, globalParametersKnobRow_y, knob_diameter, knob_diameter };
		static const Rectangle<int> bounds_GlobalParametersMidiChannelKnob{ globalParametersKnobCol3_x, globalParametersKnobRow_y, knob_diameter, knob_diameter };
		static const Rectangle<int> bounds_GlobalParametersMidiClockComboBox{ globalParametersComboBoxes_x, globalParametersControlRow1_y, globalParametersComboBoxes_w, globalParametersComboBoxAndDisplayLabel_h };
		static const Rectangle<int> bounds_GlobalParametersMidiControllersDisplayLabel{ globalParametersDisplayLabels_x, globalParametersControlRow6_y, globalParametersDisplayLabels_w, globalParametersComboBoxAndDisplayLabel_h };
		static const Rectangle<int> bounds_GlobalParametersParameterReceiveDisplayLabel{ globalParametersDisplayLabels_x, globalParametersControlRow5_y, globalParametersDisplayLabels_w, globalParametersComboBoxAndDisplayLabel_h };
		static const Rectangle<int> bounds_GlobalParametersPedalModeComboBox{ globalParametersComboBoxes_x, globalParametersControlRow2_y, globalParametersComboBoxes_w, globalParametersComboBoxAndDisplayLabel_h };
		static const Rectangle<int> bounds_GlobalParametersVoiceChangeComboBox{ globalParametersComboBoxes_x, globalParametersControlRow3_y, globalParametersComboBoxes_w, globalParametersComboBoxAndDisplayLabel_h };
		static const Rectangle<int> bounds_GlobalParametersParameterSendComboBox{ globalParametersComboBoxes_x, globalParametersControlRow4_y, globalParametersComboBoxes_w, globalParametersComboBoxAndDisplayLabel_h };
		static const Rectangle<int> bounds_GlobalParametersSysExDisplayLabel{ globalParametersDisplayLabels_x, globalParametersControlRow7_y, globalParametersDisplayLabels_w, globalParametersComboBoxAndDisplayLabel_h };
		static const Rectangle<int> bounds_GlobalParametersTooltipDelayLabel{ globalParametersTooltipControls_x, globalParametersControlRow12_y, 50, 16 };
		static const Rectangle<int> bounds_GlobalParametersTransposeKnob{ globalParametersKnobCol1_x, globalParametersKnobRow_y, knob_diameter, knob_diameter };
		static const Rectangle<int> bounds_ImptExptBrowserComponent{ imptExptBrowserComponent_x, imptExptBrowserComponent_y, imptExptBrowserComponent_w, imptExptBrowserComponent_h };
		static const Rectangle<int> bounds_ImptExptCancelButton{ imptExptCancelButton_x, imptExptButtonsRow_y, imptExptCancelAndOKbuttons_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_ImptExptCurrentPathBox{ imptExptCurrentPathBox_x, imptExptCurrentPathBox_y, imptExptCurrentPathBox_w, imptExptCurrentPathBox_h };
		static const Rectangle<int> bounds_ImptExptDirContentsBox{ imptExptDirContentsBox_x, imptExptDirContentsBox_y, imptExptDirContentsBox_w, imptExptDirContentsBox_h };
		static const Rectangle<int> bounds_ImptExptFileNameBox{ imptExptFileNameBox_x, imptExptFileNameBox_y, imptExptFileNameBox_w, imptExptFileNameBox_h };
		static const Rectangle<int> bounds_ImptExptGoUpButton{ imptExptGoUpButton_x, imptExptGoUpButton_y, imptExptGoUpButton_w, imptExptGoUpButton_h };
		static const Rectangle<int> bounds_ImptExptNewFolderButton{ imptExptNewFolderButton_x, imptExptButtonsRow_y, imptExptNewFolderButton_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_ImptExptOKbutton{ imptExptOKbutton_x, imptExptButtonsRow_y, imptExptCancelAndOKbuttons_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_ImptExptWindow{ imptExptWindow_x, imptExptWindow_y, imptExptWindow_w, imptExptWindow_h };
		static const Rectangle<int> bounds_LoadSelectedVoiceButton{ voicesBankLoadButton_x, voicesBankButtons_y, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_MainWindowBanksButton{ 706, writeReadBanksGlobalButtons_y, writeReadBanksGlobalButtons_w, writeReadBanksGlobalButtons_h };
		static const Rectangle<int> bounds_MainWindowEditNameButtonAndEditor{ 590, voiceNameEditButton_y, 222, 50 };
		static const Rectangle<int> bounds_MainWindowGlobalButton{ 769, writeReadBanksGlobalButtons_y, writeReadBanksGlobalButtons_w, writeReadBanksGlobalButtons_h };
		static const Rectangle<int> bounds_MainWindowReadButton{ 643, writeReadBanksGlobalButtons_y, writeReadBanksGlobalButtons_w, writeReadBanksGlobalButtons_h };
		static const Rectangle<int> bounds_MainWindowRedoButton{ undoRedoButtons_x, 55, undoRedoButtons_w, undoRedoButtons_h };
		static const Rectangle<int> bounds_MainWindowSeqTrack1ClearButton{ clearButtons_x, SeqTrack1ClearButton_y, clearButtons_w, clearButtons_h };
		static const Rectangle<int> bounds_MainWindowSeqTrack2ClearButton{ clearButtons_x, SeqTrack2ClearButton_y, clearButtons_w, clearButtons_h };
		static const Rectangle<int> bounds_MainWindowSeqTrack3ClearButton{ clearButtons_x, SeqTrack3ClearButton_y, clearButtons_w, clearButtons_h };
		static const Rectangle<int> bounds_MainWindowSeqTrack4ClearButton{ clearButtons_x, SeqTrack4ClearButton_y, clearButtons_w, clearButtons_h };
		static const Rectangle<int> bounds_MainWindowUndoButton{ undoRedoButtons_x, 26, undoRedoButtons_w, undoRedoButtons_h };
		static const Rectangle<int> bounds_MainWindowWebLinkButton{ 644, 122, 157, 9 };
		static const Rectangle<int> bounds_MainWindowWriteButton{ 580, writeReadBanksGlobalButtons_y, writeReadBanksGlobalButtons_w, writeReadBanksGlobalButtons_h };
		static const Rectangle<int> bounds_NRPNisOffWarningComponentCloseButton{ 820, 212, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_NRPNisOffWarningComponentRetryButton{ 611, 387, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_RandomizationCloseButton{ randomizationCloseButton_x, randomizationButtonsRow_y, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_RandomizationLockAllButton{ randomizationLockAllButton_x, randomizationButtonsRow_y, randomizationButtons_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_RandomizationSeqTrack1LockButton{ randomizationSeqTrackLockButton_x, SeqTrack1ClearButton_y, randomizationLockButton_w, clearButtons_h };
		static const Rectangle<int> bounds_RandomizationSeqTrack2LockButton{ randomizationSeqTrackLockButton_x, SeqTrack2ClearButton_y, randomizationLockButton_w, clearButtons_h };
		static const Rectangle<int> bounds_RandomizationSeqTrack3LockButton{ randomizationSeqTrackLockButton_x, SeqTrack3ClearButton_y, randomizationLockButton_w, clearButtons_h };
		static const Rectangle<int> bounds_RandomizationSeqTrack4LockButton{ randomizationSeqTrackLockButton_x, SeqTrack4ClearButton_y, randomizationLockButton_w, clearButtons_h };
		static const Rectangle<int> bounds_RandomizationSeqTrack1UnlockButton{ randomizationSeqTrackUnlockButton_x, SeqTrack1ClearButton_y, randomizationUnlockButton_w, clearButtons_h };
		static const Rectangle<int> bounds_RandomizationSeqTrack2UnlockButton{ randomizationSeqTrackUnlockButton_x, SeqTrack2ClearButton_y, randomizationUnlockButton_w, clearButtons_h };
		static const Rectangle<int> bounds_RandomizationSeqTrack3UnlockButton{ randomizationSeqTrackUnlockButton_x, SeqTrack3ClearButton_y, randomizationUnlockButton_w, clearButtons_h };
		static const Rectangle<int> bounds_RandomizationSeqTrack4UnlockButton{ randomizationSeqTrackUnlockButton_x, SeqTrack4ClearButton_y, randomizationUnlockButton_w, clearButtons_h };
		static const Rectangle<int> bounds_RandomizationUnlockAllButton{ randomizationUnlockAllButton_x, randomizationButtonsRow_y, randomizationButtons_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_RandomizeButton{randomizeButton_x, randomizationButtonsRow_y, randomizationButtons_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_RandomizationVoiceNameLockButton{ randomizationVoiceNameLockButton_x, voiceNameEditButton_y, randomizationLockButton_w, clearButtons_h };
		static const Rectangle<int> bounds_RandomizationVoiceNameUnlockButton{ randomizationVoiceNameUnlockButton_x, voiceNameEditButton_y, randomizationUnlockButton_w, clearButtons_h };
		static const Rectangle<int> bounds_VoicesBanksCloseButton{ 1130, 117, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_VoicesBanksTabbedComponent{ 89, 113, tabbedComponentForAllVoicesBanks_w, tabbedComponentForAllVoicesBanks_h };
		static const Rectangle<int> bounds_VoicesBanksTransmitTimeLabel{ 1119, voicesBanksControls_y, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_VoiceNameEditorButton{ 118, 0, 44, 18 };
		static const Rectangle<int> bounds_VoiceNameEditorLabel{ 0, 32, 222, 18 };
		static const Rectangle<int> bounds_VoiceSlotsWidget{ 15, 14, voiceSlotsWidget_w, voiceSlotsWidget_h };
		static const Rectangle<int> bounds_ExportEntireBankButton{ voicesBankExportEntireBankButton_x, voicesBankButtons_y, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_ExportSelectedVoiceButton{ voicesBankExportButton_x, voicesBankButtons_y, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_ImportEntireBankButton{ voicesBankImportEntireBankButton_x, voicesBankButtons_y, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_ImportSelectedVoiceButton{ voicesBankImportButton_x, voicesBankButtons_y, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_PullEntireBankButton{ voicesBankPullEntireBankButton_x, voicesBankButtons_y, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_PullSelectedVoiceButton{ voicesBankPullButton_x, voicesBankButtons_y, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_PushSelectedCustomVoiceButton{ voicesBankCustomPushButton_x, voicesBankButtons_y, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_PushSelectedFactoryVoiceButton{ voicesBankFactoryPushButton_x, voicesBankButtons_y, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_PushEntireBankButton{ voicesBankPushEntireBankButton_x, voicesBankButtons_y, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_SaveVoiceIntoSelectedSlotButton{ voicesBankSaveButton_x, voicesBankButtons_y, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_SysexisOffWarningComponentCloseButton{ 830, 150, secondaryWindowsControls_w, secondaryWindowsControls_h };
		static const Rectangle<int> bounds_SysexisOffWarningComponentRetryButton{ 611, 449, secondaryWindowsControls_w, secondaryWindowsControls_h };

		static const String apostrophe{ CharPointer_UTF8("\xe2\x80\x99") };
		static const String openQuote{ CharPointer_UTF8("\xe2\x80\x9c") };
		static const String closeQuote{ CharPointer_UTF8("\xe2\x80\x9d") };
	}
}