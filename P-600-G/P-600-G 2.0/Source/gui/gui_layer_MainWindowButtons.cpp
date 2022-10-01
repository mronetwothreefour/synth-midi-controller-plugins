#include "gui_layer_MainWindowButtons.h"

#include "gui_layer_TooltipsOptions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_MainWindowButtonDescription.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"
#include "../voices/voices_5_gui_layer_VoicesBank.h"

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
    btn_Push.setComponentID(ID::btn_Push_Voice.toString());
    btn_Push.onClick = [this, exposedParams, unexposedParams] {
        auto transmitOptions{ unexposedParams->getVoiceTransmissionOptions() };
        auto outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() };
        SysExMessages::addDataMessageForCurrentVoiceToOutgoingBuffers(exposedParams, transmitOptions, outgoingBuffers);
        addProgramChangeMessageToOutgoingBuffersAfterDelay(10);
    };
    btn_Push.setBounds(478, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
    btn_Push.addShortcut(KeyPress{ 'p', ModifierKeys::ctrlModifier + ModifierKeys::altModifier, 0 });
    addAndMakeVisible(btn_Push);

    btn_Pull.setComponentID(ID::btn_Pull_Voice.toString());
    btn_Pull.onClick = [this, unexposedParams] {
        auto transmitOptions{ unexposedParams->getVoiceTransmissionOptions() };
        auto currentVoiceNumber{ transmitOptions->currentVoiceNumber() };
        auto outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() };
        SysExMessages::addRequestForVoiceDataStoredInSlotToOutgoingBuffers(currentVoiceNumber, outgoingBuffers);
        addProgramChangeMessageToOutgoingBuffersAfterDelay(transmitOptions->voiceTransmitTime());
    };
    btn_Pull.setBounds(528, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
    btn_Pull.addShortcut(KeyPress{ 'p', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_Pull);

    btn_ShowVoicesBank.setComponentID(ID::btn_PgmBank.toString());
    btn_ShowVoicesBank.onClick = [this] { showVoicesBankLayer(); };
    btn_ShowVoicesBank.setBounds(578, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
    btn_ShowVoicesBank.addShortcut(KeyPress{ 'b', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_ShowVoicesBank);

    btn_ShowTooltipsOptions.setComponentID(ID::btn_Tips.toString());
    btn_ShowTooltipsOptions.onClick = [this] { showTooltipsOptionsLayer(); };
    btn_ShowTooltipsOptions.setBounds(687, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
    btn_ShowTooltipsOptions.addShortcut(KeyPress{ 't', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_ShowTooltipsOptions);

    updateTooltips();

    setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_MainWindowButtons::updateTooltips() {
    auto shouldShow{ tooltips->shouldShowDescription() };

    auto tipFor_btn_Pull{ shouldShow ? Description::buildForPull() : String{ "" } };
    btn_Pull.setTooltip(tipFor_btn_Pull);

    auto tipFor_btn_Push{ shouldShow ? Description::buildForPush() : String{ "" } };
    btn_Push.setTooltip(tipFor_btn_Push);

    auto tipFor_btn_ShowVoicesBank{ shouldShow ? Description::buildForShowVoicesBankLayer() : String{ "" } };
    btn_ShowVoicesBank.setTooltip(tipFor_btn_ShowVoicesBank);

    auto tipFor_btn_ShowTooltipsOptions{ shouldShow ? Description::buildForShowTooltipsOptionsLayer() : String{ "" } };
    btn_ShowTooltipsOptions.setTooltip(tipFor_btn_ShowTooltipsOptions);
}

void GUI_Layer_MainWindowButtons::timerCallback() {
}

void GUI_Layer_MainWindowButtons::addProgramChangeMessageToOutgoingBuffersAfterDelay(int delayInMilliseconds) {
    callAfterDelay(delayInMilliseconds, [this] {
        auto currentVoiceNumber{ unexposedParams->getVoiceTransmissionOptions()->currentVoiceNumber() };
        unexposedParams->getOutgoing_MIDI_Buffers()->addProgramChangeMessage(currentVoiceNumber); 
    });
}

void GUI_Layer_MainWindowButtons::showVoicesBankLayer() {
    layer_VoicesBank.reset(new GUI_Layer_VoicesBank{ exposedParams, unexposedParams });
    if (layer_VoicesBank != nullptr) {
        addAndMakeVisible(layer_VoicesBank.get());
        layer_VoicesBank->setBounds(getLocalBounds());
        layer_VoicesBank->grabKeyboardFocus();
    }
}

void GUI_Layer_MainWindowButtons::showTooltipsOptionsLayer() {
    layer_TooltipsOptions.reset(new GUI_Layer_TooltipsOptions{ tooltips, &exposedParams->undoManager });
    if (layer_TooltipsOptions != nullptr) {
        addAndMakeVisible(layer_TooltipsOptions.get());
        layer_TooltipsOptions->setBounds(getLocalBounds());
        layer_TooltipsOptions->grabKeyboardFocus();
    }
}

void GUI_Layer_MainWindowButtons::mouseDown(const MouseEvent& /*event*/) {
}

void GUI_Layer_MainWindowButtons::buttonClicked(Button* /*button*/) {
}

void GUI_Layer_MainWindowButtons::valueChanged(Value& /*value*/) {
    updateTooltips();
}

GUI_Layer_MainWindowButtons::~GUI_Layer_MainWindowButtons() {
    layer_VoicesBank = nullptr;
    layer_TooltipsOptions = nullptr;
    shouldShowDescriptionAsValue.removeListener(this);
}
