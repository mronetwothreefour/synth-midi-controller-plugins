#include "gui_layer_MainWindowButtons.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_MainWindowButtonDescription.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace P_600_G_Constants;
using Description = MainWindowButtonDescription;

GUI_Layer_MainWindowButtons::GUI_Layer_MainWindowButtons(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    tooltips{ unexposedParams->getTooltipsOptions() }
{
    setInterceptsMouseClicks(false, true);

    shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
    shouldShowDescriptionAsValue.addListener(this);

    const int buttonsRow_y{ 47 };
    btn_Pull.setComponentID(ID::btn_Pull_Voice.toString());
    btn_Pull.onClick = [this, unexposedParams] {
        auto transmitOptions{ unexposedParams->getVoiceTransmissionOptions() };
        auto currentVoiceNumber{ transmitOptions->currentVoiceNumber() };
        auto outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() };
        SysExMessages::addRequestForVoiceDataStoredInSlotToOutgoingBuffers(currentVoiceNumber, outgoingBuffers);
        addProgramChangeMessageToOutgoingBuffersAfterDelay(transmitOptions->voiceTransmitTime());
    };
    btn_Pull.setBounds(478, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
    btn_Pull.addShortcut(KeyPress{ 'p', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_Pull);

    btn_Push.setComponentID(ID::btn_Push_Voice.toString());
    btn_Push.onClick = [this, exposedParams, unexposedParams] {
        auto transmitOptions{ unexposedParams->getVoiceTransmissionOptions() };
        auto outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() };
        SysExMessages::addDataMessageForCurrentVoiceToOutgoingBuffers(exposedParams, transmitOptions, outgoingBuffers);
        addProgramChangeMessageToOutgoingBuffersAfterDelay(10);
    };
    btn_Push.setBounds(528, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
    btn_Push.addShortcut(KeyPress{ 'p', ModifierKeys::ctrlModifier + ModifierKeys::altModifier, 0 });
    addAndMakeVisible(btn_Push);

    updateTooltips();

    setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_MainWindowButtons::updateTooltips() {
    auto shouldShow{ tooltips->shouldShowDescription() };

    auto tipFor_btn_Pull{ shouldShow ? Description::buildForPull() : String{ "" } };
    btn_Pull.setTooltip(tipFor_btn_Pull);

    auto tipFor_btn_Push{ shouldShow ? Description::buildForPush() : String{ "" } };
    btn_Push.setTooltip(tipFor_btn_Push);
}

void GUI_Layer_MainWindowButtons::timerCallback() {
}

void GUI_Layer_MainWindowButtons::addProgramChangeMessageToOutgoingBuffersAfterDelay(int delayInMilliseconds) {
    callAfterDelay(delayInMilliseconds, [this] {
        auto currentVoiceNumber{ unexposedParams->getVoiceTransmissionOptions()->currentVoiceNumber() };
        unexposedParams->getOutgoing_MIDI_Buffers()->addProgramChangeMessage(currentVoiceNumber); 
    });
}

void GUI_Layer_MainWindowButtons::mouseDown(const MouseEvent& /*event*/) {
}

void GUI_Layer_MainWindowButtons::buttonClicked(Button* /*button*/) {
}

void GUI_Layer_MainWindowButtons::valueChanged(Value& /*value*/) {
    updateTooltips();
}

GUI_Layer_MainWindowButtons::~GUI_Layer_MainWindowButtons() {
    shouldShowDescriptionAsValue.removeListener(this);
}
