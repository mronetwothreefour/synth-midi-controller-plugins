#include "helper_ProgressDisplayComponent.h"

#include "helper_CustomColors.h"



ProgressDisplayComponent::ProgressDisplayComponent(const String& title, const String& message) :
	title{ title },
	message{ message }
{
	setSize(1273, 626);
}

ProgressDisplayComponent::~ProgressDisplayComponent() {
}

void ProgressDisplayComponent::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	Rectangle<int> dimBanksWindow{ 104, 113, 1065, 400 };
	g.fillRect(dimBanksWindow);
}

void ProgressDisplayComponent::setMessage(const String& message) {
}
