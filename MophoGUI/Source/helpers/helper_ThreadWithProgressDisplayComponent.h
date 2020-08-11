#pragma once

#include <JuceHeader.h>

#include "helper_ProgressDisplayComponent.h"


class ThreadWithProgressDisplayComponent :
	public Thread,
	public Component,
	private Timer
{
	double progress;
	std::unique_ptr<ProgressDisplayComponent> progressDisplay;
	String message;
	CriticalSection messageLock;
	const int timeOutMsWhenCancelling;
	bool wasCancelledByUser;

public:
	ThreadWithProgressDisplayComponent() = delete;

	ThreadWithProgressDisplayComponent
	(
		const String& componentTitle,
		bool hasProgressBar,
		int timeOutMsWhenCancelling = 10000,
		const String& cancelButtonText = String()
	);
	~ThreadWithProgressDisplayComponent() override;
	void runThreadWithPriority(int priority = 5);
	void launchThreadWithPriority(int priority = 5);
	void updateProgress(double newProgress);
	void setStatusMessage(const String& newStatusMessage);
	virtual void threadComplete(bool userPressedCancel);

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ThreadWithProgressDisplayComponent)
};

