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
		int width
	) :
		name{ menuName },
		paramID{ parameterID },
		menu{ name },
		privateParams{ privateParameters },
		publicParams{ publicParameters }
	{
		menu.setLookAndFeel(mophoLaF);
		menu.addListener(this);
		addAndMakeVisible(menu);

		auto menuWidget_w{ width };
		auto menuWidget_h{ 35 };
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
		Rectangle<int> menuLabelArea{ 0, 16, getWidth(), 14 };
		g.drawText(name, menuLabelArea, Justification::centred);
	}

	void resized() override
	{
		menu.setBounds(0, 0, getWidth(), 16);
	}

	void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override
	{
		if (comboBoxThatHasChanged == &menu)
		{
			auto currentValue{ menu.getSelectedItemIndex() };
			auto tooltip{ createTooltipString(currentValue) };
			setSliderTooltip(tooltip);
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

	void setSliderTooltip(String text) { menu.setTooltip(text); }

private:
	String name;
	Identifier paramID;

	ComboBox menu;
	std::unique_ptr<MenuAttachment> menuAttachment;

	AudioProcessorValueTreeState* publicParams;


	// Override this funtion to create the list of
	// choices that will be displayed in the menu
	virtual StringArray createChoices() const = 0;

	// Override this function to create a tooltip String with a parameter
	// description and/or a verbose version of the parameter's current value
	virtual String createTooltipString(const int& currentValue) const noexcept = 0;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MenuWidget)
};

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
		MenuWidget{ "NOTE PRIORITY", publicParameters, privateParameters, ID::notePriority, mophoLaF, width }
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

