#include "gui_comp_ButtonForHidingLayer.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



ButtonForHidingLayer::ButtonForHidingLayer(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams }
{
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	tooltipOptions->addListener(this);

	setComponentID(ID::button_Close.toString());
	onClick = [this] {
		getParentComponent()->getParentComponent()->grabKeyboardFocus();
		getParentComponent()->setVisible(false);
	};
	addShortcut(KeyPress(KeyPress::escapeKey));

	updateTooltip();

	setSize(50, GUI::redButton_h);
}

void ButtonForHidingLayer::updateTooltip() {
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescription{ tooltipOptions->shouldShowDescriptions() };
	setTooltip(shouldShowDescription ? "Click to close this window." : "");
}

void ButtonForHidingLayer::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == ID::tooltips_Description)
		updateTooltip();
}

ButtonForHidingLayer::~ButtonForHidingLayer() {
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	tooltipOptions->removeListener(this);
}
