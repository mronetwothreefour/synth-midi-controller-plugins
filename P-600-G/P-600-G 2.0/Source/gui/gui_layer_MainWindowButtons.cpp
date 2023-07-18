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
#include "../randomization/rndm_3_gui_layer_Randomization.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"
#include "../voices/voices_5_gui_layer_VoicesBank.h"

using namespace P_600_G_Constants;
using Description = MainWindowButtonDescription;

GUI_Layer_MainWindowButtons::GUI_Layer_MainWindowButtons(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    tooltips{ unexposedParams->getTooltipsOptions() },
    randomize{ exposedParams->randomize.get() },
    btn_Hyperlink{ "", URL("https://programming.mr1234.com/") }
{
    setInterceptsMouseClicks(false, true);

    shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
    shouldShowDescriptionAsValue.addListener(this);

    auto transmitOptions{ unexposedParams->getVoiceTransmissionOptions() };
    auto outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() };
    const int buttonsRow_y{ 47 };
    btn_Push.setComponentID(ID::btn_Push_Voice.toString());
    btn_Push.onClick = [this, exposedParams, transmitOptions, outgoingBuffers] {
        SysExMessages::addDataMessageForCurrentVoiceToOutgoingBuffers(exposedParams, transmitOptions, outgoingBuffers);
        outgoingBuffers->addProgramChangeMessageAfterDelay(transmitOptions->currentVoiceNumber(), 10);
    };
    btn_Push.setBounds(478, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
    btn_Push.addShortcut(KeyPress{ ']', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_Push);

    btn_Pull.setComponentID(ID::btn_Pull_Voice.toString());
    btn_Pull.onClick = [this, transmitOptions, outgoingBuffers] {
        auto currentVoiceNumber{ transmitOptions->currentVoiceNumber() };
        SysExMessages::addRequestForVoiceDataStoredInSlotToOutgoingBuffers(currentVoiceNumber, outgoingBuffers);
        outgoingBuffers->addProgramChangeMessageAfterDelay(currentVoiceNumber, transmitOptions->voiceTransmitTime());
    };
    btn_Pull.setBounds(528, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
    btn_Pull.addShortcut(KeyPress{ '[', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_Pull);

    btn_ShowVoicesBank.setComponentID(ID::btn_PgmBank.toString());
    btn_ShowVoicesBank.onClick = [this] {
        if (noOtherLayerIsVisble())
            showVoicesBankLayer();
    };
    btn_ShowVoicesBank.setBounds(578, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
    btn_ShowVoicesBank.addShortcut(KeyPress{ 'b', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_ShowVoicesBank);

    btn_ShowTooltipsOptions.setComponentID(ID::btn_Tips.toString());
    btn_ShowTooltipsOptions.onClick = [this] {
        if (noOtherLayerIsVisble())
            showTooltipsOptionsLayer();
    };
    btn_ShowTooltipsOptions.setBounds(687, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
    btn_ShowTooltipsOptions.addShortcut(KeyPress{ 't', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_ShowTooltipsOptions);

    btn_Undo.setComponentID(ID::btn_Undo.toString());
    btn_Undo.onClick = [exposedParams] { exposedParams->undoManager.undo(); };
    btn_Undo.setBounds(795, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
    btn_Undo.addShortcut(KeyPress{ 'z', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_Undo);

    btn_Redo.setComponentID(ID::btn_Redo.toString());
    btn_Redo.onClick = [exposedParams] { exposedParams->undoManager.redo(); };
    btn_Redo.setBounds(845, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
    btn_Redo.addShortcut(KeyPress{ 'z', ModifierKeys::ctrlModifier + ModifierKeys::shiftModifier, 0 });
    addAndMakeVisible(btn_Redo);

    btn_Randomize.setComponentID(ID::btn_Randomize.toString());
    btn_Randomize.addMouseListener(this, false);
    btn_Randomize.addListener(this);
    btn_Randomize.onClick = [this, transmitOptions, outgoingBuffers] {
        if (ModifierKeys::currentModifiers != ModifierKeys::ctrlModifier + ModifierKeys::altModifier && wasRightClicked == false) {
            randomize->randomizeAllUnlockedParameters();
            outgoingBuffers->addProgramChangeMessageAfterDelay(transmitOptions->currentVoiceNumber(), transmitOptions->voiceTransmitTime());
        }
        wasRightClicked = false;
    };
    btn_Randomize.setBounds(979, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
    btn_Randomize.addShortcut(KeyPress{ 'd', ModifierKeys::ctrlModifier, 0 });
    btn_Randomize.addShortcut(KeyPress{ 'd', ModifierKeys::ctrlModifier + ModifierKeys::altModifier, 0 });
    addAndMakeVisible(btn_Randomize);

    btn_Hyperlink.setComponentID(ID::btn_Hyperlink.toString());
    btn_Hyperlink.setBounds(100, 88, 187, 8);
    addAndMakeVisible(btn_Hyperlink);

    updateTooltips();

    setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_MainWindowButtons::updateTooltips() {
    auto shouldShow{ tooltips->shouldShowDescription() };

    auto tipFor_btn_Pull{ shouldShow ? Description::buildForPull() : String{ "" } };
    btn_Pull.setTooltip(tipFor_btn_Pull);

    auto tipFor_btn_Push{ shouldShow ? Description::buildForPush() : String{ "" } };
    btn_Push.setTooltip(tipFor_btn_Push);

    auto tipFor_btn_Randomize{ shouldShow ? Description::buildForRandomize() : String{ "" } };
    btn_Randomize.setTooltip(tipFor_btn_Randomize);

    auto tipFor_btn_ShowVoicesBank{ shouldShow ? Description::buildForShowVoicesBankLayer() : String{ "" } };
    btn_ShowVoicesBank.setTooltip(tipFor_btn_ShowVoicesBank);

    auto tipFor_btn_ShowTooltipsOptions{ shouldShow ? Description::buildForShowTooltipsOptionsLayer() : String{ "" } };
    btn_ShowTooltipsOptions.setTooltip(tipFor_btn_ShowTooltipsOptions);

    auto tipFor_btn_Hyperlink{ shouldShow ? Description::buildForHyperlink() : String{ "" } };
    btn_Hyperlink.setTooltip(tipFor_btn_Hyperlink);
}

bool GUI_Layer_MainWindowButtons::noOtherLayerIsVisble() {
    if (layer_TooltipsOptions != nullptr)
        if (layer_TooltipsOptions->isVisible())
            return false;
    if (layer_Randomization != nullptr)
        if (layer_Randomization->isVisible())
            return false;
    if (layer_VoicesBank != nullptr)
        if (layer_VoicesBank->isVisible())
            return false;
    return true;
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

void GUI_Layer_MainWindowButtons::showRandomizationLayer() {
    layer_Randomization = nullptr;
    layer_Randomization.reset(new GUI_Layer_Randomization{ exposedParams, unexposedParams });
    if (layer_Randomization != nullptr) {
        addAndMakeVisible(layer_Randomization.get());
        layer_Randomization->setBounds(getLocalBounds());
        layer_Randomization->grabKeyboardFocus();
    }
}

void GUI_Layer_MainWindowButtons::mouseDown(const MouseEvent& event) {
    if (btn_Randomize.isMouseOver() == true) {
        if (event.mods == ModifierKeys::rightButtonModifier) {
            wasRightClicked = true;
            showRandomizationLayer();
        }
    }
}

void GUI_Layer_MainWindowButtons::buttonClicked(Button* /*button*/) {
    if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier + ModifierKeys::altModifier)
        if (noOtherLayerIsVisble())
            showRandomizationLayer();
}

void GUI_Layer_MainWindowButtons::valueChanged(Value& /*value*/) {
    updateTooltips();
}

GUI_Layer_MainWindowButtons::~GUI_Layer_MainWindowButtons() {
    layer_VoicesBank = nullptr;
    layer_TooltipsOptions = nullptr;
    layer_Randomization = nullptr;
    shouldShowDescriptionAsValue.removeListener(this);
    btn_Randomize.removeListener(this);
    btn_Randomize.removeMouseListener(this);
}
