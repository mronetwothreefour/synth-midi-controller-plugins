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
	// Returns the amount of time (in milliseconds) necessary for the complete
	// transmission of a program between the plugin and the hardware. 
	int getProgramTransmitTime();

	// Sets the amount of time (in milliseconds) necessary for the complete
	// transmission of a program between the plugin and the hardware. 
	bool setProgramTransmitTime(int txTimeInMilliseconds);

	//==============================================================================
	// Resets all the programs stored in the three
	// program banks to the factory defaults
	void setProgramBanksToDefaults();

	// Returns all the parameter values for the program stored
	// in the specified bank and slot as a hex String
	const uint8* getProgramDataFromStorageString(int bank, int pgmSlot);

	// Saves a program data buffer as a hex value String in the specified bank and storage slot
	void setProgramDataString(const uint8* data, int bank, int pgmSlot);

	// Extracts the values of the program name character parameters
	// from the hex data for the program stored in the specified bank
	// and slot and combines them into a String
	String getStoredProgramName(int bank, int pgmSlot);

	// Copies the String for the selected program to a buffer
	void copySelectedProgramToBuffer(int bank, int pgmSlot);

	// Replaces the selected program String with the String in the buffer
	void replaceSelectedProgramWithBuffer(int bank, int pgmSlot);

private:
	std::unique_ptr<ValueTree> globalOptionsTree;
	std::unique_ptr<ValueTree> tooltipOptionsTree;
	std::unique_ptr<ValueTree> programBank1Tree;
	std::unique_ptr<ValueTree> programBank2Tree;
	std::unique_ptr<ValueTree> programBank3Tree;

	Value updateFromPreset;

	String programBuffer{ "" };

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PrivateParameters)
};