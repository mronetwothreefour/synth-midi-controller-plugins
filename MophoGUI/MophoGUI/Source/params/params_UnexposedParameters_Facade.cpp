#include "params_UnexposedParameters_Facade.h"



UnexposedParameters::UnexposedParameters() {
}




void UnexposedParameters::tooltips_addListener(ValueTree::Listener* listener) {
	tooltips.addListener(listener);
}

void UnexposedParameters::tooltips_removeListener(ValueTree::Listener* listener) {
	tooltips.removeListener(listener);
}

bool UnexposedParameters::tooltips_shouldShowCurrentValue() {
	return tooltips.shouldShowCurrentValue();
}

bool UnexposedParameters::tooltips_shouldShowDescription() {
	return tooltips.shouldShowDescription();
}

void UnexposedParameters::tooltips_setShouldShowCurrentValue() {
	tooltips.setShouldShowCurrentValue();
}

void UnexposedParameters::tooltips_setShouldNotShowCurrentValue() {
	tooltips.setShouldNotShowCurrentValue();
}

void UnexposedParameters::tooltips_setShouldShowDescription() {
	tooltips.setShouldShowDescription();
}

void UnexposedParameters::tooltips_setShouldNotShowDescription() {
	tooltips.setShouldNotShowDescription();
}

int UnexposedParameters::tooltips_delayInMilliseconds() {
	return tooltips.delayInMilliseconds();
}

void UnexposedParameters::tooltips_setDelayInMilliseconds(int newDelay) {
	tooltips.setDelayInMilliseconds(newDelay);
}




UnexposedParameters::~UnexposedParameters() {
}
