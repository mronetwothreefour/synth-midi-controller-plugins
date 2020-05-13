#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/Identifiers.h"
#include "../helpers/ValueConverters.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/KnobWidgets.h"
#include "../widgets/LCDcharacterRenderer.h"
#include "../widgets/ProgramBanksWindow.h"

// A set of controls targeting the program name characters
class ProgramNameSection : 
	public Component,
	public Label::Listener,
	public Button::Listener
{
public:
	ProgramNameSection
	(
		PluginProcessor& p,
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParameters,
		ValueConverters* vc
	) :
		processor{ p },
		privateParams{ privateParameters },
		knob_NameChar01{ 1 , publicParams, privateParams, vc },
		knob_NameChar02{ 2 , publicParams, privateParams, vc },
		knob_NameChar03{ 3 , publicParams, privateParams, vc },
		knob_NameChar04{ 4 , publicParams, privateParams, vc },
		knob_NameChar05{ 5 , publicParams, privateParams, vc },
		knob_NameChar06{ 6 , publicParams, privateParams, vc },
		knob_NameChar07{ 7 , publicParams, privateParams, vc },
		knob_NameChar08{ 8 , publicParams, privateParams, vc },
		knob_NameChar09{ 9 , publicParams, privateParams, vc },
		knob_NameChar10{ 10, publicParams, privateParams, vc },
		knob_NameChar11{ 11, publicParams, privateParams, vc },
		knob_NameChar12{ 12, publicParams, privateParams, vc },
		knob_NameChar13{ 13, publicParams, privateParams, vc },
		knob_NameChar14{ 14, publicParams, privateParams, vc },
		knob_NameChar15{ 15, publicParams, privateParams, vc },
		knob_NameChar16{ 16, publicParams, privateParams, vc },
		button_Edit{ "EDIT" },
		button_Write{ "WRITE" },
		button_Read{ "READ" },
		button_Banks{ "BANKS" },
		button_Global{ "GLOBAL" },
		pgmNameEditor{ "pgmNameEditor", "" }
	{
		addAndMakeVisible(pgmBankAndSlotChar01);
		addAndMakeVisible(pgmBankAndSlotChar02);
		addAndMakeVisible(pgmBankAndSlotChar03);
		addAndMakeVisible(pgmBankAndSlotChar04);
		addAndMakeVisible(pgmBankAndSlotChar05);
		addAndMakeVisible(pgmBankAndSlotChar06);
		addAndMakeVisible(pgmBankAndSlotChar07);
		addAndMakeVisible(pgmBankAndSlotChar08);
		addAndMakeVisible(pgmBankAndSlotChar09);
		addAndMakeVisible(pgmBankAndSlotChar10);
		addAndMakeVisible(pgmBankAndSlotChar11);
		addAndMakeVisible(pgmBankAndSlotChar12);
		addAndMakeVisible(pgmBankAndSlotChar13);
		addAndMakeVisible(pgmBankAndSlotChar14);
		addAndMakeVisible(pgmBankAndSlotChar15);
		addAndMakeVisible(pgmBankAndSlotChar16);

		addAndMakeVisible(knob_NameChar01);
		addAndMakeVisible(knob_NameChar02);
		addAndMakeVisible(knob_NameChar03);
		addAndMakeVisible(knob_NameChar04);
		addAndMakeVisible(knob_NameChar05);
		addAndMakeVisible(knob_NameChar06);
		addAndMakeVisible(knob_NameChar07);
		addAndMakeVisible(knob_NameChar08);
		addAndMakeVisible(knob_NameChar09);
		addAndMakeVisible(knob_NameChar10);
		addAndMakeVisible(knob_NameChar11);
		addAndMakeVisible(knob_NameChar12);
		addAndMakeVisible(knob_NameChar13);
		addAndMakeVisible(knob_NameChar14);
		addAndMakeVisible(knob_NameChar15);
		addAndMakeVisible(knob_NameChar16);

		setPgmBankAndSlotDisplay();

		pgmNameEditor.setInterceptsMouseClicks(false, true);
		pgmNameEditor.setComponentID("pgmNameEditor");
		pgmNameEditor.setJustificationType(Justification::centredLeft);
		pgmNameEditor.setText(getPgmName(), dontSendNotification);
		pgmNameEditor.setColour(Label::backgroundColourId, Colours::transparentBlack);
		pgmNameEditor.setColour(Label::outlineColourId, Colours::transparentBlack);
		pgmNameEditor.setColour(Label::textWhenEditingColourId, Color::controlText);
		pgmNameEditor.setColour(Label::backgroundWhenEditingColourId, Color::black);
		pgmNameEditor.setColour(Label::outlineWhenEditingColourId, Color::black);
		pgmNameEditor.addListener(this);
		addAndMakeVisible(pgmNameEditor);

		String button_EditTooltip{ "" };
		if (privateParams->shouldShowInfoTip())
		{
			button_EditTooltip += "Opens an editor where you can\n";
			button_EditTooltip += "type in a new program name.";
		}
		button_Edit.setTooltip(button_EditTooltip);
		button_Edit.addListener(this);
		addAndMakeVisible(button_Edit);

		String button_ReadTooltip{ "" };
		if (privateParams->shouldShowInfoTip())
		{
			button_ReadTooltip += "Requests a program edit buffer dump from\n";
			button_ReadTooltip += "the Mopho and applies it to the plugin GUI.";
		}
		button_Read.setTooltip(button_ReadTooltip);
		button_Read.addListener(this);
		addAndMakeVisible(button_Read);

		String button_WriteTooltip{ "" };
		if (privateParams->shouldShowInfoTip())
		{
			button_WriteTooltip += "Sends the plugin's parameter settings\n";
			button_WriteTooltip += "to the Mopho's program edit buffer.";
		}
		button_Write.setTooltip(button_WriteTooltip);
		button_Write.addListener(this);
		addAndMakeVisible(button_Write);

		String button_BanksTooltip{ "" };
		if (privateParams->shouldShowInfoTip())
		{
			button_BanksTooltip += "Opens a window where you can manage the\n";
			button_BanksTooltip += "three storage banks for program presets.";
		}
		button_Banks.setTooltip(button_BanksTooltip);
		button_Banks.addListener(this);
		button_Banks.onClick = [this] { showProgramBanksWindow(); };
		addAndMakeVisible(button_Banks);

		String button_GlobalTooltip{ "" };
		if (privateParams->shouldShowInfoTip())
		{
			button_GlobalTooltip += "Opens a window where you can change\n";
			button_GlobalTooltip += "the Mopho's global parameter settings.";
		}
		button_Global.setTooltip(button_GlobalTooltip);
		button_Global.addListener(this);
		addAndMakeVisible(button_Global);

		auto section_w{ 230 };
		auto section_h{ 98 };
		setSize(section_w, section_h);
	}

	~ProgramNameSection() 
	{
		if (programBanksDialogWindow != nullptr)
		{
			programBanksDialogWindow->exitModalState(0);
			delete programBanksDialogWindow;
		}

		programBanksOptions = nullptr;
		programBanksWindow = nullptr;

		button_Banks.removeListener(this);
		button_Banks.removeListener(this);
		button_Write.removeListener(this);
		button_Read.removeListener(this);
		button_Edit.removeListener(this);

		pgmNameEditor.removeListener(this);
	}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);

		// Draw section label
		Font sectionLabel{ "Arial", "Black", 18.0f };
		g.setFont(sectionLabel);
		Rectangle<int> sectionLabelArea{ 0, 0, 125, 16 };
		g.drawText("PROGRAM NAME", sectionLabelArea, Justification::left);

		// draw LCD background
		g.fillRect(0, 20, 230, 52);
	}

	void resized() override
	{
		button_Edit.setBounds(125, 0, 42, 16);

		auto char_w{ knob_NameChar01.getWidth() };
		auto char_h{ knob_NameChar01.getHeight() };
		auto charGap{ 2 };
		auto char01_x{ 4 };
		auto char02_x{ char01_x + char_w + charGap };
		auto char03_x{ char02_x + char_w + charGap };
		auto char04_x{ char03_x + char_w + charGap };
		auto char05_x{ char04_x + char_w + charGap };
		auto char06_x{ char05_x + char_w + charGap };
		auto char07_x{ char06_x + char_w + charGap };
		auto char08_x{ char07_x + char_w + charGap };
		auto char09_x{ char08_x + char_w + charGap };
		auto char10_x{ char09_x + char_w + charGap };
		auto char11_x{ char10_x + char_w + charGap };
		auto char12_x{ char11_x + char_w + charGap };
		auto char13_x{ char12_x + char_w + charGap };
		auto char14_x{ char13_x + char_w + charGap };
		auto char15_x{ char14_x + char_w + charGap };
		auto char16_x{ char15_x + char_w + charGap };
		auto charRow1_y{ 27 };
		auto charRow2_y{ 49 };
		pgmBankAndSlotChar01.setBounds(char01_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar02.setBounds(char02_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar03.setBounds(char03_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar04.setBounds(char04_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar05.setBounds(char05_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar06.setBounds(char06_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar07.setBounds(char07_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar08.setBounds(char08_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar09.setBounds(char09_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar10.setBounds(char10_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar11.setBounds(char11_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar12.setBounds(char12_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar13.setBounds(char13_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar14.setBounds(char14_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar15.setBounds(char15_x, charRow1_y, char_w, char_h);
		pgmBankAndSlotChar16.setBounds(char16_x, charRow1_y, char_w, char_h);

		knob_NameChar01.setBounds(char01_x, charRow2_y, char_w, char_h);
		knob_NameChar02.setBounds(char02_x, charRow2_y, char_w, char_h);
		knob_NameChar03.setBounds(char03_x, charRow2_y, char_w, char_h);
		knob_NameChar04.setBounds(char04_x, charRow2_y, char_w, char_h);
		knob_NameChar05.setBounds(char05_x, charRow2_y, char_w, char_h);
		knob_NameChar06.setBounds(char06_x, charRow2_y, char_w, char_h);
		knob_NameChar07.setBounds(char07_x, charRow2_y, char_w, char_h);
		knob_NameChar08.setBounds(char08_x, charRow2_y, char_w, char_h);
		knob_NameChar09.setBounds(char09_x, charRow2_y, char_w, char_h);
		knob_NameChar10.setBounds(char10_x, charRow2_y, char_w, char_h);
		knob_NameChar11.setBounds(char11_x, charRow2_y, char_w, char_h);
		knob_NameChar12.setBounds(char12_x, charRow2_y, char_w, char_h);
		knob_NameChar13.setBounds(char13_x, charRow2_y, char_w, char_h);
		knob_NameChar14.setBounds(char14_x, charRow2_y, char_w, char_h);
		knob_NameChar15.setBounds(char15_x, charRow2_y, char_w, char_h);
		knob_NameChar16.setBounds(char16_x, charRow2_y, char_w, char_h);

		pgmNameEditor.setBounds(char01_x, 47, 222, 22);

		auto utilityButtons_y{ 77 };
		auto utilityButtons_w{ 50 };
		auto utilityButtons_h{ 21 };
		auto utilityButtonsGap{ 10 };
		auto utilityButton1_x{ 0 };
		auto utilityButton2_x{ utilityButton1_x + utilityButtons_w + utilityButtonsGap };
		auto utilityButton3_x{ utilityButton2_x + utilityButtons_w + utilityButtonsGap };
		auto utilityButton4_x{ utilityButton3_x + utilityButtons_w + utilityButtonsGap };
		button_Write .setBounds(utilityButton1_x, utilityButtons_y, utilityButtons_w, utilityButtons_h);
		button_Read  .setBounds(utilityButton2_x, utilityButtons_y, utilityButtons_w, utilityButtons_h);
		button_Banks .setBounds(utilityButton3_x, utilityButtons_y, utilityButtons_w, utilityButtons_h);
		button_Global.setBounds(utilityButton4_x, utilityButtons_y, utilityButtons_w, utilityButtons_h);
	}

	//==============================================================================

	// Default setting is "Edit Buffer"
	void setPgmBankAndSlotDisplay
	(
		char char01 = 'E', char char02 = 'd', char char03 = 'i', char char04 = 't',
		char char05 = ' ', char char06 = 'B', char char07 = 'u', char char08 = 'f',
		char char09 = 'f', char char10 = 'e', char char11 = 'r', char char12 = ' ',
		char char13 = ' ', char char14 = ' ', char char15 = ' ', char char16 = ' '
	)
	{
		pgmBankAndSlotChar01.drawChar(char01);
		pgmBankAndSlotChar02.drawChar(char02);
		pgmBankAndSlotChar03.drawChar(char03);
		pgmBankAndSlotChar04.drawChar(char04);
		pgmBankAndSlotChar05.drawChar(char05);
		pgmBankAndSlotChar06.drawChar(char06);
		pgmBankAndSlotChar07.drawChar(char07);
		pgmBankAndSlotChar08.drawChar(char08);
		pgmBankAndSlotChar09.drawChar(char09);
		pgmBankAndSlotChar10.drawChar(char10);
		pgmBankAndSlotChar11.drawChar(char11);
		pgmBankAndSlotChar12.drawChar(char12);
		pgmBankAndSlotChar13.drawChar(char13);
		pgmBankAndSlotChar14.drawChar(char14);
		pgmBankAndSlotChar15.drawChar(char15);
		pgmBankAndSlotChar16.drawChar(char16);
	}

	String getPgmName()
	{
		std::string pgmName{ "" };
		pgmName += std::string(1, char(knob_NameChar01.getSliderValue()));
		pgmName += std::string(1, char(knob_NameChar02.getSliderValue()));
		pgmName += std::string(1, char(knob_NameChar03.getSliderValue()));
		pgmName += std::string(1, char(knob_NameChar04.getSliderValue()));
		pgmName += std::string(1, char(knob_NameChar05.getSliderValue()));
		pgmName += std::string(1, char(knob_NameChar06.getSliderValue()));
		pgmName += std::string(1, char(knob_NameChar07.getSliderValue()));
		pgmName += std::string(1, char(knob_NameChar08.getSliderValue()));
		pgmName += std::string(1, char(knob_NameChar09.getSliderValue()));
		pgmName += std::string(1, char(knob_NameChar10.getSliderValue()));
		pgmName += std::string(1, char(knob_NameChar11.getSliderValue()));
		pgmName += std::string(1, char(knob_NameChar12.getSliderValue()));
		pgmName += std::string(1, char(knob_NameChar13.getSliderValue()));
		pgmName += std::string(1, char(knob_NameChar14.getSliderValue()));
		pgmName += std::string(1, char(knob_NameChar15.getSliderValue()));
		pgmName += std::string(1, char(knob_NameChar16.getSliderValue()));

		return pgmName;
	}

	void buttonClicked(Button* buttonThatWasClicked) override
	{
		if (buttonThatWasClicked == &button_Edit)
		{
			pgmNameEditor.showEditor();
			// restrict editor input to basic ASCII, 16 characters maximum
			pgmNameEditor.getCurrentTextEditor()->setInputRestrictions(16,
				" !\"#$ % &'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
			String nameEditorTooltip{ "" };
			if (privateParams->shouldShowInfoTip())
			{
				nameEditorTooltip += "Type in a new name for the program (max. 16 characters) and hit Enter to apply it.\n";
				nameEditorTooltip += "Hit Esc to cancel. The Mopho's hardware LCD characters use the basic ASCII character\n";
				nameEditorTooltip += "set, with a few exceptions: 'backslash' becomes a yen sign and 'tilde' becomes a\n";
				nameEditorTooltip += "right arrow. The 'delete' character becomes a left arrow; obviously, you can't type\n";
				nameEditorTooltip += "that in the editor. However, you can access it by clicking-and-dragging an individual\n";
				nameEditorTooltip += "character in the GUI's name display. The hardware display will not be updated with the\n";
				nameEditorTooltip += "new name until the Program Mode button is pressed on the Mopho.";
			}
			pgmNameEditor.getCurrentTextEditor()->setTooltip(nameEditorTooltip);
		}

		if (buttonThatWasClicked == &button_Read)
			processor.sendPgmEditBufferDumpRequest();

		if (buttonThatWasClicked == &button_Write)
			processor.sendPgmEditBufferDump();
	}

	void labelTextChanged(Label* labelThatHasChanged) override
	{
		if (labelThatHasChanged == &pgmNameEditor)
		{
			String newName{ labelThatHasChanged->getText() };
			for (auto i = newName.length(); i < 16; ++i)
				newName += " ";
			processor.updateProgramName(newName);
		}
	}

private:
	PluginProcessor& processor;

	PrivateParameters* privateParams;

	LCDcharacterRenderer pgmBankAndSlotChar01;
	LCDcharacterRenderer pgmBankAndSlotChar02;
	LCDcharacterRenderer pgmBankAndSlotChar03;
	LCDcharacterRenderer pgmBankAndSlotChar04;
	LCDcharacterRenderer pgmBankAndSlotChar05;
	LCDcharacterRenderer pgmBankAndSlotChar06;
	LCDcharacterRenderer pgmBankAndSlotChar07;
	LCDcharacterRenderer pgmBankAndSlotChar08;
	LCDcharacterRenderer pgmBankAndSlotChar09;
	LCDcharacterRenderer pgmBankAndSlotChar10;
	LCDcharacterRenderer pgmBankAndSlotChar11;
	LCDcharacterRenderer pgmBankAndSlotChar12;
	LCDcharacterRenderer pgmBankAndSlotChar13;
	LCDcharacterRenderer pgmBankAndSlotChar14;
	LCDcharacterRenderer pgmBankAndSlotChar15;
	LCDcharacterRenderer pgmBankAndSlotChar16;

	KnobWidget_PgmNameChar	knob_NameChar01;
	KnobWidget_PgmNameChar	knob_NameChar02;
	KnobWidget_PgmNameChar	knob_NameChar03;
	KnobWidget_PgmNameChar	knob_NameChar04;
	KnobWidget_PgmNameChar	knob_NameChar05;
	KnobWidget_PgmNameChar	knob_NameChar06;
	KnobWidget_PgmNameChar	knob_NameChar07;
	KnobWidget_PgmNameChar	knob_NameChar08;
	KnobWidget_PgmNameChar	knob_NameChar09;
	KnobWidget_PgmNameChar	knob_NameChar10;
	KnobWidget_PgmNameChar	knob_NameChar11;
	KnobWidget_PgmNameChar	knob_NameChar12;
	KnobWidget_PgmNameChar	knob_NameChar13;
	KnobWidget_PgmNameChar	knob_NameChar14;
	KnobWidget_PgmNameChar	knob_NameChar15;
	KnobWidget_PgmNameChar	knob_NameChar16;

	Label pgmNameEditor;

	TextButton button_Edit;
	TextButton button_Read;
	TextButton button_Write;
	TextButton button_Banks;
	TextButton button_Global;

	ValueConverters valueConverters;

	char charBuffer[16];

	int charCounter{ 1 };
	int timerInterval{ 10 };

	SafePointer<DialogWindow> programBanksDialogWindow;
	std::unique_ptr<DialogWindow::LaunchOptions> programBanksOptions;
	std::unique_ptr<ProgramBanksWindow> programBanksWindow;

	void showProgramBanksWindow()
	{
		programBanksWindow.reset(new ProgramBanksWindow(processor, privateParams));
		programBanksOptions.reset(new DialogWindow::LaunchOptions());
		programBanksOptions->content.setNonOwned(programBanksWindow->contentComponent.get());
		programBanksOptions->dialogTitle = "PROGRAM STORAGE BANKS";
		programBanksOptions->escapeKeyTriggersCloseButton = true;
		programBanksOptions->useNativeTitleBar = false;
		programBanksOptions->dialogBackgroundColour = Color::device;
		programBanksOptions->resizable = false;
		programBanksOptions->content->setInterceptsMouseClicks(true, true);
		programBanksDialogWindow = programBanksOptions->launchAsync();

		if (programBanksDialogWindow != nullptr)
		{
			programBanksDialogWindow->setTitleBarHeight(30);
			programBanksDialogWindow->setTitleBarTextCentred(false);

			static const int dialogWindow_w{ programBanksWindow->contentComponent->getWidth() };
			static const int dialogWindow_h{ programBanksWindow->contentComponent->getHeight() + programBanksDialogWindow->getTitleBarHeight() };
			programBanksDialogWindow->centreAroundComponent(getParentComponent(), dialogWindow_w, dialogWindow_h);
			programBanksDialogWindow->setResizeLimits(dialogWindow_w, dialogWindow_h, dialogWindow_w, dialogWindow_h);
		}
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramNameSection)
};