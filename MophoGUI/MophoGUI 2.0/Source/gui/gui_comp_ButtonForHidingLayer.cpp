#include "gui_comp_ButtonForHidingLayer.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



ButtonForHidingLayer::ButtonForHidingLayer(UnexposedParameters* unexposedParams) :
	tooltips{ unexposedParams->getTooltipsOptions() }
{
	tooltips->addListener(this);

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
	auto shouldShowDescription{ tooltips->shouldShowDescriptions() };
	setTooltip(shouldShowDescription ? "Click to close this window." : "");
}

void ButtonForHidingLayer::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
	if (propertyID == ID::tooltips_ShowDescription)
		updateTooltip();
}

ButtonForHidingLayer::~ButtonForHidingLayer() {
	tooltips->removeListener(this);
}
