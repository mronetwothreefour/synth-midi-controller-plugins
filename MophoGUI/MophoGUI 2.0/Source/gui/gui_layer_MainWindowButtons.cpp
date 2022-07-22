#include "gui_layer_MainWindowButtons.h"

#include "../descriptions/build_MainWindowButtonDescription.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace MophoConstants;
using Description = MainWindowButtonDescription;

GUI_Layer_MainWindowButtons::GUI_Layer_MainWindowButtons(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    state{ exposedParams->state.get() },
    info{ exposedParams->info.get() },
    unexposedParams{ unexposedParams },
    tooltips{ unexposedParams->getTooltipsOptions() }
{
    setInterceptsMouseClicks(false, true);

    shouldShowDescriptionValue = unexposedParams->getTooltipsOptions()->getShouldShowDescriptionValue();
    shouldShowDescriptionValue.addListener(this);

    const int undoRedoButtons_w{ 44 };
    const int undoRedoButtons_x{ 832 };
    btn_Undo.setComponentID(ID::btn_Undo.toString());
    btn_Undo.onClick = [exposedParams] {
        exposedParams->undoManager.undo();
    };
    btn_Undo.setBounds(undoRedoButtons_x, 19, undoRedoButtons_w, GUI::redButton_h);
    btn_Undo.addShortcut(KeyPress{ 'z', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_Undo);

    btn_Redo.setComponentID(ID::btn_Redo.toString());
    btn_Redo.onClick = [exposedParams] {
        exposedParams->undoManager.redo();
    };
    btn_Redo.setBounds(undoRedoButtons_x, 48, undoRedoButtons_w, GUI::redButton_h);
    btn_Redo.addShortcut(KeyPress{ 'z', ModifierKeys::ctrlModifier + ModifierKeys::shiftModifier, 0 });
    addAndMakeVisible(btn_Redo);

    updateTooltips();

    setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_MainWindowButtons::updateTooltips() {
    auto shouldShow{ tooltips->shouldShowDescription() };

    auto tipFor_btn_Undo{ shouldShow ? Description::buildForUndo() : String{ "" } };
    btn_Undo.setTooltip(tipFor_btn_Undo);

    auto tipFor_btn_Redo{ shouldShow ? Description::buildForRedo() : String{ "" } };
    btn_Redo.setTooltip(tipFor_btn_Redo);
}

void GUI_Layer_MainWindowButtons::valueChanged(Value& /*value*/) {
    updateTooltips();
}

GUI_Layer_MainWindowButtons::~GUI_Layer_MainWindowButtons() {
    shouldShowDescriptionValue.removeListener(this);
}
