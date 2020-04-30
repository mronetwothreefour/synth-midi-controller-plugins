#pragma once

#include <JuceHeader.h>

#include "DefaultProgramBanks.h"
#include "../helpers/Identifiers.h"

// Contains ValueTrees in which plugin parameters that are not 
// exposed to the host are stored, as well as tools for 
// accessing and manipulating the stored data.
class PrivateParameters
{
public:
	PrivateParameters();
	~PrivateParameters();

	//==============================================================================
	void addistenerToUpdateFromPreset(Value::Listener* listener) { updateFromPreset.addListener(listener); }
	void removeListenerFromUpdateFromPreset(Value::Listener* listener) { updateFromPreset.removeListener(listener); }

	// Returns whether GUI controls that are linked to private paramaeters need to
	// update their display values, specifically after a plugin preset is loaded
	bool shouldUpdateFromPreset() { return (bool)updateFromPreset.getValue(); }
	void setUpdateFromPreset(bool shouldUpdate) { updateFromPreset.setValue(shouldUpdate); }

	//==============================================================================
	// Returns whether a verbose version of a control's current
	// value should show when the mouse hovers over the control
	bool shouldShowValueTip() const;

	// Sets whether a verbose version of a control's current
	// value should show when the mouse hovers over the control.
	// Returns true if the property was set successfully
	bool setShouldShowValueTip(bool shouldShow);

	// Returns whether information about a what a control does
	// should show when the mouse hovers over the control
	bool shouldShowInfoTip() const;

	// Sets whether information about a what a control does
	// should show when the mouse hovers over the control
	// Returns true if the property was set successfully
	bool setShouldShowInfoTip(bool shouldShow);

	// Returns the amount of time (in milliseconds) before a
	// tooltip should show when the mouse hovers over a control
	int getTooltipDelay() const;

	// Sets the amount of time (in milliseconds) before a
	// tooltip should show when the mouse hovers over a control
	// Returns true if the property was set successfully
	bool setTooltipDelay(int delay);

	//==============================================================================
	// Resets all the programs stored in the three
	// program banks to the factory defaults
	void setProgramBanksToDefaults();

private:
	std::unique_ptr<ValueTree> tooltipOptionsTree;

	std::unique_ptr<ValueTree> programBankATree;
	std::unique_ptr<ValueTree> programBankBTree;
	std::unique_ptr<ValueTree> programBankCTree;

	Value updateFromPreset;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PrivateParameters)
};