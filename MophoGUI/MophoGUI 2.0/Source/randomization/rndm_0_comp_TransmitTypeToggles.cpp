#include "rndm_0_comp_TransmitTypeToggles.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_2_tree_ExposedParamsRandomizationOptions.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



TransmitTypeToggles::TransmitTypeToggles(ExposedParamsRandomizationOptions* randomization, UnexposedParameters* unexposedParams)
{
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltips->shouldShowDescriptions() };
	toggle_TransmitViaNRPN.setComponentID(ID::component_RedToggle.toString());
	toggle_TransmitViaNRPN.setToggleState(randomization->transmitMethodIsSysEx() == false, dontSendNotification);
	toggle_TransmitViaNRPN.setRadioGroupId(1, dontSendNotification);
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "When NRPN is selected, newly generated random parameter settings\n";
		tip += "will be transmitted to the Mopho hardware via individual NRPN\n";
		tip += "messages. Updating more than a few parameters will be slow, but\n";
		tip += "the hardware will not be interrupted if it is generating audio.\n";
		toggle_TransmitViaNRPN.setTooltip(tip);
	}
	toggle_TransmitViaNRPN.onClick = [this, randomization] {
		auto shouldBeSysEx{ toggle_TransmitViaNRPN.getToggleState() == false };
		randomization->setTransmitMethodIsSysEx(shouldBeSysEx);
	};
	toggle_TransmitViaNRPN.setBounds(0, 0, GUI::toggle_diameter, GUI::toggle_diameter);
	addAndMakeVisible(toggle_TransmitViaNRPN);

	toggle_TransmitViaSysEx.setComponentID(ID::component_RedToggle.toString());
	toggle_TransmitViaSysEx.setToggleState(randomization->transmitMethodIsSysEx() == true, dontSendNotification);
	toggle_TransmitViaSysEx.setRadioGroupId(1, dontSendNotification);
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "When SysEx is selected, all newly generated random parameter settings will\n";
		tip += "be transmitted to the Mopho hardware via a single system exclusive program\n";
		tip += "edit buffer dump message. This is faster for sending a large number of param-\n";
		tip += "eter changes, but it will interrupt the hardware if it is generating audio.\n";
		toggle_TransmitViaSysEx.setTooltip(tip);
	}
	toggle_TransmitViaSysEx.onClick = [this, randomization] {
		auto shouldBeSysEx{ toggle_TransmitViaSysEx.getToggleState() == true };
		randomization->setTransmitMethodIsSysEx(shouldBeSysEx);
	};
	toggle_TransmitViaSysEx.setBounds(63, 0, GUI::toggle_diameter, GUI::toggle_diameter);
	addAndMakeVisible(toggle_TransmitViaSysEx);

	setSize(77, GUI::toggle_diameter);
}
