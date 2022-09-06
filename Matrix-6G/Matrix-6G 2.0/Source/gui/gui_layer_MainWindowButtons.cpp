#include "gui_layer_MainWindowButtons.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;

GUI_Layer_MainWindowButtons::GUI_Layer_MainWindowButtons(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    tooltips{ unexposedParams->getTooltipsOptions() }
{
    setInterceptsMouseClicks(false, true);

    shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
    shouldShowDescriptionAsValue.addListener(this);

    updateTooltips();

    setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_MainWindowButtons::updateTooltips() {
}

void GUI_Layer_MainWindowButtons::timerCallback() {
}

void GUI_Layer_MainWindowButtons::mouseDown(const MouseEvent& /*event*/) {
}

void GUI_Layer_MainWindowButtons::buttonClicked(Button* /*button*/) {
}

void GUI_Layer_MainWindowButtons::valueChanged(Value& value) {
    if (value.refersToSameSourceAs(shouldShowDescriptionAsValue))
        updateTooltips();
}

GUI_Layer_MainWindowButtons::~GUI_Layer_MainWindowButtons() {
    shouldShowDescriptionAsValue.removeListener(this);
}
