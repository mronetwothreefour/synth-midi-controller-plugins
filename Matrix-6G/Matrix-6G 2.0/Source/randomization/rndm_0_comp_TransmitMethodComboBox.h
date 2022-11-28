#pragma once

#include <JuceHeader.h>

#include "../constants/constants_GUI_Dimensions.h"
#include "../exposedParameters/ep_2_tree_ParamRandomizationOptions.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using namespace Matrix_6G_Constants;

class TransmitMethodComboBox :
	public ComboBox
{
public:
	TransmitMethodComboBox() = delete;

	explicit TransmitMethodComboBox(ParamRandomizationOptions* randomization, TooltipsOptions* tooltips) {
		StringArray choiceNamesList{ "PATCH", "QUICK" };
		addItemList(choiceNamesList, 1);
		setSelectedItemIndex(randomization->transmitMethodIsQuickEdit() ? 1 : 0, dontSendNotification);
		onChange = [this, randomization] {
			auto currentChoice{ getSelectedItemIndex() };
			randomization->setTransmitMethodIsQuickEdit(currentChoice == 1 ? true : false);
			if (randomization->transmitMethodIsQuickEdit()) {
				randomization->forbidAllNegativeChoicesForAllSignedParams();
				for (auto modNum = 0; modNum != MMOD::numberOfModulators; ++modNum) {
					for (auto modType = (int)MM_Type::source; modType <= (int)MM_Type::destination; ++modType)
						randomization->setMatrixModParamIsLocked(modNum, MM_Type{ modType }, true);
				}
			}
			else {
				randomization->allowAllNegativeChoicesForAllSignedParams();
				for (auto modNum = 0; modNum != MMOD::numberOfModulators; ++modNum) {
					for (auto modType = (int)MM_Type::source; modType <= (int)MM_Type::destination; ++modType)
						randomization->setMatrixModParamIsLocked(modNum, MM_Type{ modType }, false);
				}
			}
		};
		if (tooltips->shouldShowDescription()) {
			String tip{ "" };
			tip += "Selects the type of message which will be used to transmit new\n";
			tip += "randomly generated parameter settings to the Matrix-6R hardware.\n";
			tip += "PATCH: A data dump of the entire patch will be sent. Pro: changes\n";
			tip += "to a large number of parameters can be transmitted quickly; Matrix\n";
			tip += "Mod parameters can be randomized; negative values for signed parame-\n";
			tip += "ters can be generated. Con: disrupts currently playing audio.\n";
			tip += "QUICK: An individual Quick Edit message will be sent for each\n";
			tip += "parameter that is changed. Pro: will not disrupt currently playing\n";
			tip += "audio. Con: much slower when randomizing more than a few parameters;\n";
			tip += "Matrix Mod parameters cannot be randomized; negative values cannot\n";
			tip += "be generated for signed parameters.";
			setTooltip(tip);
		}
		setSize(60, GUI::control_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TransmitMethodComboBox)
};