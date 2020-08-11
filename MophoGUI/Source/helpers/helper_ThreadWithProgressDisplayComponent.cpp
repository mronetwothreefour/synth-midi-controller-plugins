#include "helper_ThreadWithProgressDisplayComponent.h"



ThreadWithProgressDisplayComponent::ThreadWithProgressDisplayComponent
(
	const String& componentTitle, 
	bool hasProgressBar, 
	int timeOutMsWhenCancelling, 
	const String& cancelButtonText
) :
	Thread{"ThreadWithProgressDisplayComponent"},
	progress{ 0.0 },
	timeOutMsWhenCancelling{ timeOutMsWhenCancelling },
	wasCancelledByUser{ false }
{
	progressDisplay.reset(new ProgressDisplayComponent(componentTitle, "TODO"));
}

ThreadWithProgressDisplayComponent::~ThreadWithProgressDisplayComponent() {
	stopThread(timeOutMsWhenCancelling);
	progressDisplay = nullptr;
}

void ThreadWithProgressDisplayComponent::runThreadWithPriority(int priority) {
	JUCE_ASSERT_MESSAGE_THREAD
	startThread(priority);
	startTimer(100);
	const ScopedLock sl(messageLock);
	progressDisplay->setMessage(message);
	addAndMakeVisible(progressDisplay.get());
	progressDisplay->setBounds(0, 0, progressDisplay->getWidth(), progressDisplay->getHeight());
}

void ThreadWithProgressDisplayComponent::launchThreadWithPriority(int priority) {
}

void ThreadWithProgressDisplayComponent::updateProgress(double newProgress) {
}

void ThreadWithProgressDisplayComponent::setStatusMessage(const String& newStatusMessage) {
}

void ThreadWithProgressDisplayComponent::threadComplete(bool userPressedCancel) {
}

void ThreadWithProgressDisplayComponent::timerCallback() {
}
