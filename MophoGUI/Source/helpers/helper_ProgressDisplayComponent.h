#pragma once

#include <JuceHeader.h>



class ProgressDisplayComponent :
	public Component
{
	String title;
	String message;
	ProgressBar progressBar;
	double progress;

public:
	ProgressDisplayComponent() = delete;

	ProgressDisplayComponent(const String& title, const String& message);
	~ProgressDisplayComponent();
	void paint(Graphics& g) override;
	void setMessage(const String& message);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgressDisplayComponent)
};

