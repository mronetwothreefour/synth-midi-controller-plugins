#include "helper_ProgressDisplayComponent.h"

#include "helper_CustomColors.h"



ProgressDisplayComponent::ProgressDisplayComponent(const String& title, const String& message) :
	title{ title },
	message{ message },
	progress{ 0.0 },
	progressBar{ progress }
{
	setSize(1273, 626);
}

ProgressDisplayComponent::~ProgressDisplayComponent() {
}

void ProgressDisplayComponent::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	Rectangle<int> dimBanksWindow{ 104, 113, 1065, 400 };
	g.fillRect(dimBanksWindow);
	g.setColour(Color::black);
	Rectangle<int> progressDisplayOutline{ 464, 236, 345, 154 };
	g.fillRect(progressDisplayOutline);
	g.setColour(Color::device);
	Rectangle<int> progressDisplayBackground{ 466, 238, 341, 150 };
	g.fillRect(progressDisplayBackground);
}

void ProgressDisplayComponent::setMessage(const String& message) {
}
