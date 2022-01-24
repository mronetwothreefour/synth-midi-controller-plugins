#pragma once

#include <JuceHeader.h>



namespace constants
{
	namespace GUI
	{
		static const float knobEndAngleInDegrees{ 330.0f };
		static const float knobStartAngleInDegrees{ 30.0f };
		static const float programNumberInset_x{ 4.0f };
		static const float programNumberInset_y{ 8.0f };
		static const float tooltipMaxWidth{ 400.0f };

		static const int buttons_h{ 40 };
		static const int buttons_w{ buttons_h };
		static const int buttonsHorizSpacingForGroupedButtons{ 50 };
		static const int buttonMainWindowPush_x{ 478 };
		static const int buttonMainWindowPull_x{ buttonMainWindowPush_x + buttonsHorizSpacingForGroupedButtons };
		static const int buttonMainWindowPgmBank_x{ buttonMainWindowPull_x + buttonsHorizSpacingForGroupedButtons };
		static const int buttonMainWindowTips_x{ 687 };
		static const int buttonImptExptEsc_x{ 846 };
		static const int buttonImptExptOK_x{ buttonImptExptEsc_x + buttonsHorizSpacingForGroupedButtons };
		static const int buttonImptExptNewFldr_x{ 466 };
		static const int buttonPgmBankWindowExit_x{ 1336 };
		static const int buttonPgmBankWindowLoadSelectedPgm_x{ 360 };
		static const int buttonPgmBankWindowSavePgm_x{ buttonPgmBankWindowLoadSelectedPgm_x + buttonsHorizSpacingForGroupedButtons };
		static const int buttonPgmBankWindowPullSelectedPgm_x{ buttonPgmBankWindowSavePgm_x + buttonsHorizSpacingForGroupedButtons };
		static const int buttonPgmBankWindowImptSelectedPgm_x{ buttonPgmBankWindowPullSelectedPgm_x + buttonsHorizSpacingForGroupedButtons };
		static const int buttonPgmBankWindowExptSelectedPgm_x{ buttonPgmBankWindowImptSelectedPgm_x + buttonsHorizSpacingForGroupedButtons };
		static const int buttonPgmBankWindowNameSelectedPgm_x{ buttonPgmBankWindowExptSelectedPgm_x + buttonsHorizSpacingForGroupedButtons };
		static const int buttonRand_x{ 979 };
		static const int buttonUndo_x{ 795 };
		static const int buttonRedo_x{ buttonUndo_x + buttonsHorizSpacingForGroupedButtons };
		static const int editor_w{ 1402 };
		static const int editor_h{ 392 };
		static const int fileBrowserIcon_h{ 22 };
		static const int fileBrowserIcon_w{ 32 };
		static const int imptExptBrowserComponent_h{ 245 };
		static const int imptExptBrowserComponent_w{ 470 };
		static const int imptExptBrowserComponent_x{ 466 };
		static const int imptExptBrowserComponent_y{ 61 };
		static const int imptExptCurrentPathBox_h{ 26 };
		static const int imptExptCurrentPathBox_w{ 445 };
		static const int imptExptCurrentPathBox_x{ 0 };
		static const int imptExptCurrentPathBox_y{ 0 };
		static const int imptExptDirContentsBox_h{ 173 };
		static const int imptExptDirContentsBox_w{ imptExptBrowserComponent_w };
		static const int imptExptDirContentsBox_x{ imptExptCurrentPathBox_x };
		static const int imptExptDirContentsBox_y{ 36 };
		static const int imptExptFileNameBox_h{ imptExptCurrentPathBox_h };
		static const int imptExptFileNameBox_w{ 384 };
		static const int imptExptFileNameBox_x{ 86 };
		static const int imptExptFileNameBox_y{ 219 };
		static const int imptExptGoUpButton_h{ imptExptCurrentPathBox_h };
		static const int imptExptGoUpButton_w{ 20 };
		static const int imptExptGoUpButton_x{ 450 };
		static const int imptExptGoUpButton_y{ imptExptCurrentPathBox_y };
		static const int imptExptWindow_x{ 451 };
		static const int imptExptWindow_y{ 21 };
		static const int imptExptButtonsRow_y{ 316 };
		static const int knobLFOamount_x{ 232 };
		static const int knobOscB_Fine_x{ 609 };
		static const int knobPmodOscB_x{ 204 };
		static const int knobsFilterAndAmplifierHorizSpacing_x{ 75 };
		static const int knobsCutoffAndAttack_x{ 1117 };
		static const int knobsResoAndDecay_x{ knobsCutoffAndAttack_x + knobsFilterAndAmplifierHorizSpacing_x };
		static const int knobsEnvAmtAndSustain_x{ knobsResoAndDecay_x + knobsFilterAndAmplifierHorizSpacing_x };
		static const int knobsRelease_x{ knobsEnvAmtAndSustain_x + knobsFilterAndAmplifierHorizSpacing_x };
		static const int knobsMixerAndGlide_x{ 999 };
		static const int knobsOscFrequency_x{ 523 };
		static const int knobsOscPulseWidth_x{ 877 };
		static const int knobsPmodFilterEnvAndLFOfreq_x{ 60 };
		static const int knobRow1_y{ 67 };
		static const int knobRow2_y{ 170 };
		static const int knobRow3_y{ 308 };
		static const int knobs_h{ 34 };
		static const int knobs_w{ knobs_h };
		static const int lcdDigit_w{ 26 };
		static const int mainWindowButtonsRow_y{ 47 };
		static const int pgmDataBankWindowButtonsRow_y{ 84 };
		static const int pgmDataBankWindow_h{ 270 };
		static const int pgmDataBankWindow_w{ 1380 };
		static const int pgmDataBankWindow_x{ 11 };
		static const int pgmDataBankWindow_y{ 61 };
		static const int pgmDataSlotRadioButton_h{ 16 };
		static const int pgmDataSlotRadioButton_w{ 135 };
		static const int pgmDataSlotsComponent_h{ 160 };
		static const int pgmDataSlotsComponent_w{ 1350 };
		static const int pgmDataSlotsComponent_x{ 26 };
		static const int pgmDataSlotsComponent_y{ 156 };
		static const int pgmNameEditorLabel_horizInset{ 43 };
		static const int pgmNameEditorLabel_w{ 118 };
		static const int switches_w{ 20 };
		static const int switchesHorizSpacing{ 60 };
		static const int switchesOscSaw_x{ 683 };
		static const int switchesOscTri_x{ switchesOscSaw_x + switchesHorizSpacing };
		static const int switchesOscPulse_x{ switchesOscTri_x + switchesHorizSpacing };
		static const int switchesPmodDestOscAandLFOdestFreq_x{ 307 };
		static const int switchesPmodDestFilterandLFOdestPW_x{ switchesPmodDestOscAandLFOdestFreq_x + switchesHorizSpacing };
		static const int switchLFOdestFilter_x{ switchesPmodDestFilterandLFOdestPW_x + switchesHorizSpacing };
		static const int switchLFOshape_x{ 146 };
		static const int switchOscA_Sync_x{ knobOscB_Fine_x };
		static const int switchPmodFilter_x{ switchesPmodDestOscAandLFOdestFreq_x + switchesHorizSpacing };
		static const int switchKeyFollow_x{ 1338 };
		static const int switchRow1_y{ 72 };
		static const int switchRow2_y{ 177 };
		static const int switchRow3_y{ 315 };
		static const int switchTabs_h{ 16 };
		static const int switchThreePole_h{ 3 * switchTabs_h };
		static const int switchTwoPole_h{ 2 * switchTabs_h };
		static const int switchUnison_x{ 441 };
		static const int theWeirdOffsetThatJucePutsOnLinearSliders{ 4 };

		static const Rectangle<int> bounds_ImptExptBrowserComponent{ imptExptBrowserComponent_x, imptExptBrowserComponent_y, imptExptBrowserComponent_w, imptExptBrowserComponent_h };
		static const Rectangle<int> bounds_ImptExptCurrentPathBox{ imptExptCurrentPathBox_x, imptExptCurrentPathBox_y, imptExptCurrentPathBox_w, imptExptCurrentPathBox_h };
		static const Rectangle<int> bounds_ImptExptDirContentsBox{ imptExptDirContentsBox_x, imptExptDirContentsBox_y, imptExptDirContentsBox_w, imptExptDirContentsBox_h };
		static const Rectangle<int> bounds_ImptExptEscButton{ buttonImptExptEsc_x, imptExptButtonsRow_y, buttons_w, buttons_h };
		static const Rectangle<int> bounds_ImptExptFileNameBox{ imptExptFileNameBox_x, imptExptFileNameBox_y, imptExptFileNameBox_w, imptExptFileNameBox_h };
		static const Rectangle<int> bounds_ImptExptGoUpButton{ imptExptGoUpButton_x, imptExptGoUpButton_y, imptExptGoUpButton_w, imptExptGoUpButton_h };
		static const Rectangle<int> bounds_ImptExptNewFldrButton{ buttonImptExptNewFldr_x, imptExptButtonsRow_y, buttons_w, buttons_h };
		static const Rectangle<int> bounds_ImptExptOKbutton{ buttonImptExptOK_x, imptExptButtonsRow_y, buttons_w, buttons_h };
		static const Rectangle<int> bounds_MainWindowPullButton{ buttonMainWindowPull_x, mainWindowButtonsRow_y, buttons_w, buttons_h };
		static const Rectangle<int> bounds_MainWindowPushButton{ buttonMainWindowPush_x, mainWindowButtonsRow_y, buttons_w, buttons_h };
		static const Rectangle<int> bounds_MainWindowPgmBankButton{ buttonMainWindowPgmBank_x, mainWindowButtonsRow_y, buttons_w, buttons_h };
		static const Rectangle<int> bounds_PgmBankWindow{ pgmDataBankWindow_x, pgmDataBankWindow_y, pgmDataBankWindow_w, pgmDataBankWindow_h };
		static const Rectangle<int> bounds_PgmBankWindowExitButton{ buttonPgmBankWindowExit_x, pgmDataBankWindowButtonsRow_y, buttons_w, buttons_h };
		static const Rectangle<int> bounds_PgmBankWindowExptSelectedPgmButton{ buttonPgmBankWindowExptSelectedPgm_x, pgmDataBankWindowButtonsRow_y, buttons_w, buttons_h };
		static const Rectangle<int> bounds_PgmBankWindowLoadSelectedPgmButton{ buttonPgmBankWindowLoadSelectedPgm_x, pgmDataBankWindowButtonsRow_y, buttons_w, buttons_h };
		static const Rectangle<int> bounds_PgmBankWindowPullSelectedPgmButton{ buttonPgmBankWindowPullSelectedPgm_x, pgmDataBankWindowButtonsRow_y, buttons_w, buttons_h };
		static const Rectangle<int> bounds_PgmBankWindowSavePgmButton{ buttonPgmBankWindowSavePgm_x, pgmDataBankWindowButtonsRow_y, buttons_w, buttons_h };
		static const Rectangle<int> bounds_PgmBankWindowNameButton{ buttonPgmBankWindowNameSelectedPgm_x, pgmDataBankWindowButtonsRow_y, buttons_w, buttons_h };
		static const Rectangle<int> bounds_PgmDataSlotsComponent{ pgmDataSlotsComponent_x, pgmDataSlotsComponent_y, pgmDataSlotsComponent_w, pgmDataSlotsComponent_h };
		static const Rectangle<int> bounds_RandButton{ buttonRand_x, mainWindowButtonsRow_y, buttons_w, buttons_h };
		static const Rectangle<int> bounds_RedoButton{ buttonRedo_x, mainWindowButtonsRow_y, buttons_w, buttons_h };
		static const Rectangle<int> bounds_TipsButton{ buttonMainWindowTips_x, mainWindowButtonsRow_y, buttons_w, buttons_h };
		static const Rectangle<int> bounds_UndoButton{ buttonUndo_x, mainWindowButtonsRow_y, buttons_w, buttons_h };
		static const Rectangle<int> bounds_ProgramNumberSlider{ 408, 42, 60, 50 };

		static const String apostrophe{ CharPointer_UTF8("\xe2\x80\x99") };
		static const String openQuote{ CharPointer_UTF8("\xe2\x80\x9c") };
		static const String closeQuote{ CharPointer_UTF8("\xe2\x80\x9d") };

		static const std::vector<uint8> pathDataForFileIcon{ 110,109,133,235,143,65,0,0,0,64,108,0,0,16,65,0,0,0,64,108,0,0,16,65,0,0,160,65,108,0,0,184,65,0,0,160,65,108,0,0,184,65,133,235,225,64,108,133,235,143,65,0,0,0,64,99,109,123,20,146,65,236,81,104,64,108,62,10,171,65,195,245,216,64,108,124,20,146,65,195,245,216,64,108,124,20,146,65,236,81,104,64,99,109,51,51,31,65,236,81,152,65,108,51,51,31,65,164,112,61,64,108,92,143,138,65,164,112,61,64,108,92,143,138,65,21,174,247,64,108,225,122,176,65,21,174,247,64,108,225,122,176,65,236,81,152,65,108,51,51,31,65,236,81,152,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForFolderIcon{ 110,109,0,0,196,65,0,0,192,64,108,0,0,104,65,0,0,192,64,98,51,51,91,65,0,0,192,64,51,51,75,65,102,102,198,64,154,153,73,65,0,0,176,64,108,205,204,68,65,205,204,140,64,98,154,153,65,65,103,102,102,64,205,204,52,65,154,153,57,64,103,102,38,65,154,153,57,64,108,206,204,236,64,154,153,57,64,98,102,102,214,64,0,0,64,64,0,0,192,64,205,204,108,64,0,0,192,64,0,0,144,64,108,0,0,192,64,0,0,140,65,98,0,0,192,64,102,102,146,65,102,102,214,64,0,0,152,65,0,0,240,64,0,0,152,65,108,0,0,196,65,0,0,152,65,98,102,102,202,65,0,0,152,65,0,0,208,65,102,102,146,65,0,0,208,65,0,0,140,65,108,0,0,208,65,0,0,240,64,98,0,0,208,65,102,102,214,64,102,102,202,65,0,0,192,64,0,0,196,65,0,0,192,64,99,109,0,0,240,64,0,0,128,64,108,0,0,40,65,0,0,128,64,98,102,102,46,65,0,0,128,64,205,204,52,65,154,153,137,64,102,102,54,65,102,102,150,64,108,51,51,59,65,153,153,185,64,98,205,204,60,65,51,51,195,64,102,102,62,65,153,153,201,64,153,153,65,65,255,255,207,64,108,153,153,57,65,101,102,230,64,108,0,0,224,64,101,102,230,64,108,0,0,224,64,0,0,144,64,98,0,0,224,64,102,102,134,64,102,102,230,64,0,0,128,64,0,0,240,64,0,0,128,64,99,109,0,0,200,65,0,0,140,65,98,0,0,200,65,102,102,142,65,102,102,198,65,0,0,144,65,0,0,196,65,0,0,144,65,108,0,0,240,64,0,0,144,65,98,102,102,230,64,0,0,144,65,0,0,224,64,102,102,142,65,0,0,224,64,0,0,140,65,108,0,0,224,64,51,51,3,65,108,154,153,65,65,51,51,3,65,108,0,0,80,65,205,204,220,64,98,102,102,86,65,0,0,224,64,0,0,96,65,0,0,224,64,0,0,104,65,0,0,224,64,108,0,0,196,65,0,0,224,64,98,102,102,198,65,0,0,224,64,0,0,200,65,102,102,230,64,0,0,200,65,0,0,240,64,108,0,0,200,65,0,0,140,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_A{ 110,109,20,174,11,65,0,0,0,0,108,246,40,170,65,0,0,0,0,108,123,20,162,65,225,122,100,64,108,184,30,17,65,225,122,100,64,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_B{ 110,109,0,0,0,65,0,0,0,0,108,102,102,6,65,164,112,133,64,108,31,133,219,64,10,215,107,65,108,62,10,151,64,215,163,134,65,108,72,225,74,64,215,163,134,65,98,72,225,74,64,215,163,134,65,185,30,53,64,51,51,127,65,123,20,62,64,102,102,114,65,98,61,10,71,64,153,153,101,65,82,184,150,64,143,194,5,64,82,184,150,64,143,194,5,64,98,51,51,155,64,123,20,174,62,184,30,213,64,0,0,0,0,0,0,0,65,0,0,0,0,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_C{ 110,109,164,112,177,65,10,215,35,61,108,82,184,166,65,92,143,130,64,108,21,174,155,65,41,92,107,65,108,123,20,166,65,82,184,132,65,108,174,71,179,65,82,184,132,65,98,174,71,179,65,82,184,132,65,31,133,187,65,174,71,125,65,10,215,187,65,123,20,118,65,108,0,0,200,65,246,40,252,63,98,82,184,200,65,102,102,102,63,72,225,188,65,10,215,35,61,164,112,177,65,10,215,35,61,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_D{ 110,109,164,112,189,64,215,163,134,65,108,0,0,232,64,72,225,150,65,108,246,40,146,65,72,225,150,65,108,123,20,162,65,113,61,136,65,108,82,184,150,65,61,10,115,65,108,164,112,237,64,61,10,115,65,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_E{ 110,109,225,122,116,64,10,215,7,66,108,184,30,165,64,40,92,239,65,108,174,71,209,64,234,81,154,65,108,20,174,167,64,173,71,139,65,108,143,194,101,64,173,71,139,65,98,143,194,101,64,173,71,139,65,10,215,35,64,40,92,145,65,174,71,33,64,194,245,148,65,108,0,0,128,63,184,30,0,66,98,195,245,104,63,102,102,4,66,195,245,24,64,10,215,7,66,225,122,116,64,10,215,7,66,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_F{ 110,109,0,0,144,65,0,0,8,66,108,205,204,140,65,215,163,238,65,108,184,30,153,65,123,20,154,65,108,112,61,170,65,41,92,137,65,108,92,143,182,65,41,92,137,65,98,92,143,182,65,41,92,137,65,174,71,185,65,102,102,144,65,246,40,184,65,205,204,150,65,98,62,10,183,65,52,51,157,65,113,61,170,65,174,71,255,65,113,61,170,65,174,71,255,65,98,51,51,169,65,215,163,6,66,82,184,154,65,0,0,8,66,0,0,144,65,0,0,8,66,99,101,0,0 };
		static const std::vector<uint8> pathDataForSegment_G{ 110,109,246,40,138,65,0,0,8,66,108,41,92,151,64,0,0,8,66,108,20,174,183,64,164,112,243,65,108,164,112,135,65,164,112,243,65,99,101,0,0 };
	}
}