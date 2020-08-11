#include "helper_ProgressDisplayComponent.h"

#include "helper_CustomColors.h"
#include "helper_Fonts.h"



ProgressDisplayComponent::ProgressDisplayComponent(const String& title, const String& message) :
	title{ title },
	message{ message },
	progress{ 0.0 },
	progressBar{ progress }
{
	setMessage(message);
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
	g.setColour(Color::black);
	Font titleFont{ FontsDB::family_Global, FontsDB::style_ForProgressDisplayTitle, FontsDB::size_ForProgressDisplayTitle };
	g.setFont(titleFont);
	Rectangle<int> titleArea{ 476, 248, 321, 30 };
	g.drawFittedText(title, titleArea, Justification::centred, 1, 1.0f);
	Font messageFont{ FontsDB::family_Global, FontsDB::style_ForProgressDisplayMessage, FontsDB::size_ForProgressDisplayMessage };
	g.setFont(messageFont);
	Rectangle<int> messageArea{ 476, 278, 321, 30 };
	g.drawFittedText(message, messageArea, Justification::centred, 1, 1.0f);
}

void ProgressDisplayComponent::setMessage(const String& newMessage) {
	message = newMessage;
	repaint();
}
