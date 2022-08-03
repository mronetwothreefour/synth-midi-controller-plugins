#include "rndm_0_comp_TransmitTypeToggles.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_2_tree_ExposedParamsRandomizationOptions.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace MophoConstants;

TransmitTypeToggles::TransmitTypeToggles(ExposedParamsRandomizationOptions* randomization, UnexposedParameters* unexposedParams)
{
	setInterceptsMouseClicks(true, false);

	auto tooltips{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltips->shouldShowDescription() };
	toggle_TransmitViaNRPN.setComponentID(ID::comp_RedToggle.toString());
	toggle_TransmitViaNRPN.setToggleState(randomization->transmitMethodIsSysEx() == false, dontSendNotification);
	toggle_TransmitViaNRPN.setRadioGroupId(1, dontSendNotification);
	toggle_TransmitViaNRPN.addShortcut(KeyPress{ 'n', ModifierKeys::ctrlModifier, 0 });
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "When NRPN is selected, new randomly generated parameter\n";
		tip += "settings will be transmitted to the Mopho hardware via\n";
		tip += "individual NRPN messages. Updating more than a few param-\n";
		tip += "eters will be slow, butthe hardware will not be interrupted\n";
		tip += "if it is generating audio. Shortcut key: CTRL+N";
		toggle_TransmitViaNRPN.setTooltip(tip);
	}
	toggle_TransmitViaNRPN.onClick = [this, randomization] {
		auto shouldBeSysEx{ toggle_TransmitViaNRPN.getToggleState() == false };
		randomization->setTransmitMethodIsSysEx(shouldBeSysEx);
	};
	toggle_TransmitViaNRPN.setBounds(0, 0, GUI::redToggle_diameter, GUI::redToggle_diameter);
	addAndMakeVisible(toggle_TransmitViaNRPN);

	toggle_TransmitViaSysEx.setComponentID(ID::comp_RedToggle.toString());
	toggle_TransmitViaSysEx.setToggleState(randomization->transmitMethodIsSysEx() == true, dontSendNotification);
	toggle_TransmitViaSysEx.setRadioGroupId(1, dontSendNotification);
	toggle_TransmitViaNRPN.addShortcut(KeyPress{ 'S', ModifierKeys::ctrlModifier, 0 });
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "When SysEx is selected, all new randomly generated parameter\n";
		tip += "settings will be transmitted to the Mopho hardware via a single\n";
		tip += "system exclusive program edit buffer dump message. This is faster\n";
		tip += "for sending a large number of parameter changes, but it will inter-\n";
		tip += "rupt the hardware if it is generating audio. Shortcut key: CTRL+S";
		toggle_TransmitViaSysEx.setTooltip(tip);
	}
	toggle_TransmitViaSysEx.onClick = [this, randomization] {
		auto shouldBeSysEx{ toggle_TransmitViaSysEx.getToggleState() == true };
		randomization->setTransmitMethodIsSysEx(shouldBeSysEx);
	};
	toggle_TransmitViaSysEx.setBounds(63, 0, GUI::redToggle_diameter, GUI::redToggle_diameter);
	addAndMakeVisible(toggle_TransmitViaSysEx);

	setSize(119, GUI::redToggle_diameter);
}

void TransmitTypeToggles::mouseDown(const MouseEvent& event) {
	if (event.getMouseDownX() < 56)
		toggle_TransmitViaNRPN.triggerClick();
	if (event.getMouseDownX() > 62)
		toggle_TransmitViaSysEx.triggerClick();
}
