#pragma once

#include <JuceHeader.h>

#include "../helpers/Identifiers.h"

// Contains a ValueTree in which plugin parameters that are not 
// exposed to the host are stored, as well as tools for 
// accessing and manipulating the stored data.
class PrivateParameters
{
public:
	PrivateParameters();
	~PrivateParameters();

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

private:
	ValueTree privateParamsTree;

	//==============================================================================
	// Returns true if the specified property
	// has been set in the specified child tree
	bool properyIsSet(Identifier childID, Identifier propertyID) const;

	// Returns the value of the specified property in the specified child tree.
	// Returns a void variant if the property has not been set
	var getPropertyValue(Identifier childID, Identifier propertyID) const;

	// Sets the value of the specified property in the specified child tree.
	// Returns true if the property was set successfully
	bool setPropertyValue(Identifier childID, Identifier propertyID, const juce::var& newValue);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PrivateParameters)
};