#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../helpers/ValueConverters.h"
#include "../parameters/PrivateParameters.h"

using MenuAttachment = AudioProcessorValueTreeState::ComboBoxAttachment;

//==============================================================================
// Base class for menu widgets. Derived classes must
// override createChoices() and createTooltipString()
class MenuWidget : public Component, public ComboBox::Listener
{
public:
	PrivateParameters* privateParams;

	ValueConverters valueConverters;

	MenuWidget
	(
		String menuName,
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		Identifier parameterID,
		MophoLookAndFeel* mophoLaF,
		int width,
		bool placelabelBesideMenu
	) :
		name{ menuName },
		paramID{ parameterID },
		menu{ name },
		privateParams{ privateParameters },
		publicParams{ publicParameters },
		labelIsBesideMenu{ placelabelBesideMenu }
	{
		menu.setLookAndFeel(mophoLaF);
		menu.addListener(this);
		addAndMakeVisible(menu);

		auto menuWidget_w{ labelIsBesideMenu ? width + 75 : width };
		auto menuWidget_h{ labelIsBesideMenu ? 16 : 35 };
		setSize(menuWidget_w, menuWidget_h);
	}

	~MenuWidget()
	{
		menuAttachment = nullptr;
		menu.removeListener(this);
		menu.setLookAndFeel(nullptr);
	}

	void paint(Graphics& g) override
	{
		// Draw menu label
		g.setColour(Color::black);
		Font menuLabel{ "Arial", "Black", 12.0f };
		g.setFont(menuLabel);
		if (labelIsBesideMenu)
		{
			Rectangle<int> menuLabelArea{ 0, 0, 70, 16 };
			g.drawText(name, menuLabelArea, Justification::centredRight);
		}
		else
		{
			Rectangle<int> menuLabelArea{ 0, 16, getWidth(), 14 };
			g.drawText(name, menuLabelArea, Justification::centred);
		}
	}

	void resized() override
	{
		auto menu_x{ labelIsBesideMenu ? 75 : 0 };
		auto menu_y{ 0 };
		auto menu_w{ labelIsBesideMenu ? getWidth() - 75 : getWidth() };
		menu.setBounds(menu_x, menu_y, menu_w, 16);
	}

	void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override
	{
		if (comboBoxThatHasChanged == &menu)
		{
			auto currentValue{ menu.getSelectedItemIndex() };
			auto tooltip{ createTooltipString(currentValue) };
			setMenuTooltip(tooltip);
		}
	}

	// Adding choice strings to a menu sets the selected item index to -1 (no selection).
	// Creating the parameter attachment after the choices have been added ensures
	// that the initial menu selection is synced with the parameter.
	void addChoicesToMenuAndAttach(StringArray& choices) 
	{ 
		menu.addItemList(choices, 1); 
		menuAttachment.reset(new MenuAttachment(*publicParams, paramID.toString(), menu));
	}

	void setMenuTooltip(String text) { menu.setTooltip(text); }

private:
	String name;
	Identifier paramID;

	AudioProcessorValueTreeState* publicParams;

	ComboBox menu;
	std::unique_ptr<MenuAttachment> menuAttachment;

	bool labelIsBesideMenu;

	// Override this funtion to create the list of
	// choices that will be displayed in the menu
	virtual StringArray createChoices() const = 0;

	// Override this function to create a tooltip String with a parameter
	// description and/or a verbose version of the parameter's current value
	virtual String createTooltipString(const int& currentValue) const noexcept = 0;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MenuWidget)
};

//==============================================================================
// A MenuWidget appropriate for controlling the note priority parameter.
// Derives from MenuWidget and overrides createChoices() and createTooltipString()
class MenuWidget_NotePriority : public MenuWidget
{
public:
	MenuWidget_NotePriority
	(
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF,
		int width
	) :
		MenuWidget{ "NOTE PRIORITY", publicParameters, privateParameters, ID::notePriority, mophoLaF, width, false }
	{
		auto choices{ createChoices() };
		addChoicesToMenuAndAttach(choices);
	}
	~MenuWidget_NotePriority() {}

private:
	StringArray createChoices() const override;
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MenuWidget_NotePriority)
};

//==============================================================================
// A MenuWidget appropriate for controlling the glide mode parameter.
// Derives from MenuWidget and overrides createChoices() and createTooltipString()
class MenuWidget_GlideMode : public MenuWidget
{
public:
	MenuWidget_GlideMode
	(
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF,
		int width
	) :
		MenuWidget{ "GLIDE MODE", publicParameters, privateParameters, ID::glideMode, mophoLaF, width, false }
	{
		auto choices{ createChoices() };
		addChoicesToMenuAndAttach(choices);
	}
	~MenuWidget_GlideMode() {}

private:
	StringArray createChoices() const override;
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MenuWidget_GlideMode)
};

//==============================================================================
// A MenuWidget appropriate for controlling the arpeggiator mode parameter.
// Derives from MenuWidget and overrides createChoices() and createTooltipString()
class MenuWidget_ArpegMode : public MenuWidget
{
public:
	MenuWidget_ArpegMode
	(
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF,
		int width
	) :
		MenuWidget{ "ARPEGGIATOR MODE", publicParameters, privateParameters, ID::arpegMode, mophoLaF, width, false }
	{
		auto choices{ createChoices() };
		addChoicesToMenuAndAttach(choices);
	}
	~MenuWidget_ArpegMode() {}

private:
	StringArray createChoices() const override;
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MenuWidget_ArpegMode)
};

//==============================================================================
// A MenuWidget appropriate for controlling most of the modulation destination parameters.
// Derives from MenuWidget and overrides createChoices() and createTooltipString()
class MenuWidget_ModDestination : public MenuWidget
{
public:
	MenuWidget_ModDestination
	(
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF,
		int width,
		bool labelIsBesideMenu
	) :
		MenuWidget{ "DESTINATION", publicParameters, privateParameters, paramID, mophoLaF, width, labelIsBesideMenu }
	{
		auto choices{ createChoices() };
		addChoicesToMenuAndAttach(choices);
	}
	~MenuWidget_ModDestination() {}

private:
	StringArray createChoices() const override;
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MenuWidget_ModDestination)
};

//==============================================================================
// A MenuWidget appropriate for controlling any of the modulation source parameters.
// Derives from MenuWidget and overrides createChoices() and createTooltipString()
class MenuWidget_ModSource : public MenuWidget
{
public:
	MenuWidget_ModSource
	(
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF,
		int width
	) :
		MenuWidget{ "SOURCE", publicParameters, privateParameters, paramID, mophoLaF, width, false }
	{
		auto choices{ createChoices() };
		addChoicesToMenuAndAttach(choices);
	}
	~MenuWidget_ModSource() {}

private:
	StringArray createChoices() const override;
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MenuWidget_ModSource)
};

//==============================================================================
// A MenuWidget appropriate for controlling any of the MIDI controller destination parameters.
// Derives from MenuWidget and overrides createChoices() and createTooltipString()
class MenuWidget_MidiDestination : public MenuWidget
{
public:
	MenuWidget_MidiDestination
	(
		String controllerName,
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF,
		int width
	) :
		MenuWidget{ controllerName + " DESTINATION", publicParameters, privateParameters, paramID, mophoLaF, width, false }
	{
		auto choices{ createChoices() };
		addChoicesToMenuAndAttach(choices);
	}
	~MenuWidget_MidiDestination() {}

private:
	StringArray createChoices() const override;
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MenuWidget_MidiDestination)
};

//==============================================================================
// A MenuWidget appropriate for selecting a low-frequency oscillator's wave shape.
// Derives from MenuWidget and overrides createChoices() and createTooltipString()
class MenuWidget_LFOshape : public MenuWidget
{
public:
	MenuWidget_LFOshape
	(
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF,
		int width
		) :
		MenuWidget{ "WAVE SHAPE", publicParameters, privateParameters, paramID, mophoLaF, width, false }
	{
		auto choices{ createChoices() };
		addChoicesToMenuAndAttach(choices);
	}
	~MenuWidget_LFOshape() {}

private:
	StringArray createChoices() const override;
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MenuWidget_LFOshape)
};

//==============================================================================
// A MenuWidget appropriate for selecting the sequencer's trigger mode.
// Derives from MenuWidget and overrides createChoices() and createTooltipString()
class MenuWidget_SeqTrigger : public MenuWidget
{
public:
	MenuWidget_SeqTrigger
	(
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF,
		int width
	) :
		MenuWidget{ "TRIGGER MODE", publicParameters, privateParameters, ID::sequencerTrig, mophoLaF, width, false }
	{
		auto choices{ createChoices() };
		addChoicesToMenuAndAttach(choices);
	}
	~MenuWidget_SeqTrigger() {}

private:
	StringArray createChoices() const override;
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MenuWidget_SeqTrigger)
};

//==============================================================================
// A MenuWidget appropriate for selecting a step length for the sequencer and arpeggiator.
// Derives from MenuWidget and overrides createChoices() and createTooltipString()
class MenuWidget_ClockDiv : public MenuWidget
{
public:
	MenuWidget_ClockDiv
	(
		AudioProcessorValueTreeState* publicParameters,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF,
		int width
	) :
		MenuWidget{ "CLOCK DIVIDE", publicParameters, privateParameters, ID::clockDivide, mophoLaF, width, false }
	{
		auto choices{ createChoices() };
		addChoicesToMenuAndAttach(choices);
	}
	~MenuWidget_ClockDiv() {}

private:
	StringArray createChoices() const override;
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MenuWidget_ClockDiv)
};
