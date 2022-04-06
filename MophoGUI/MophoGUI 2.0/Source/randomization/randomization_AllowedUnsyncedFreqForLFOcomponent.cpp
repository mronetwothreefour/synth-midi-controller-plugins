#include "randomization_AllowedUnsyncedFreqForLFOcomponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



AllowedUnsyncedFreqForLFOcomponent::AllowedUnsyncedFreqForLFOcomponent(int lfoNum, UnexposedParameters* unexposedParams) :
	lfoNum{ lfoNum },
	unexposedParams{ unexposedParams },
	knob_ForMinUnsyncedFreq{ unexposedParams },
	valueDisplay_ForMinUnsyncedFreq{ &knob_ForMinUnsyncedFreq, IntToLFOfreqString::get() },
	knob_ForMaxUnsyncedFreq{ unexposedParams },
	valueDisplay_ForMaxUnsyncedFreq{ &knob_ForMaxUnsyncedFreq, IntToLFOfreqString::get() }
{
	jassert(lfoNum > 0 && lfoNum < 5);

	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };

	knob_ForMinUnsyncedFreq.setComponentID(ID::component_KnobForMinUnsyncedFreqForLFO.toString() + (String)lfoNum);
	knob_ForMinUnsyncedFreq.setRange(0.0, (double)params::maxUnsyncedLFOfreq, 1.0);
	knob_ForMinUnsyncedFreq.setValue((double)randomizationOptions->minUnsyncedFreqForLFO(lfoNum));
	knob_ForMinUnsyncedFreq.setMouseDragSensitivity(128);
	knob_ForMinUnsyncedFreq.addListener(this);
	if (shouldShowDescriptions) {
		String knobTooltip{ "" };
		knobTooltip += "Sets the minimum un-synced\n";
		knobTooltip += "frequency allowed for LFO " + (String)lfoNum + ".\n";
		knobTooltip += "Range: 0 (1 cycle lasts 30 sec.) to 89 (8 Hz)";
		knob_ForMinUnsyncedFreq.setTooltip(knobTooltip);
	}
	addAndMakeVisible(knob_ForMinUnsyncedFreq);

	addAndMakeVisible(valueDisplay_ForMinUnsyncedFreq);
	valueDisplay_ForMinUnsyncedFreq.setInterceptsMouseClicks(false, false);

	knob_ForMaxUnsyncedFreq.setComponentID(ID::component_KnobForMaxUnsyncedFreqForLFO.toString() + (String)lfoNum);
	knob_ForMaxUnsyncedFreq.setRange(0.0, (double)params::maxUnsyncedLFOfreq, 1.0);
	knob_ForMaxUnsyncedFreq.setValue((double)randomizationOptions->maxUnsyncedFreqForLFO(lfoNum));
	knob_ForMaxUnsyncedFreq.setMouseDragSensitivity(128);
	knob_ForMaxUnsyncedFreq.addListener(this);
	if (shouldShowDescriptions) {
		String knobTooltip{ "" };
		knobTooltip += "Sets the maximum un-synced\n";
		knobTooltip += "frequency allowed for LFO " + (String)lfoNum + ".\n";
		knobTooltip += "Range: 0 (1 cycle lasts 30 sec.) to 89 (8 Hz)";
		knob_ForMinUnsyncedFreq.setTooltip(knobTooltip);
	}
	addAndMakeVisible(knob_ForMaxUnsyncedFreq);

	addAndMakeVisible(valueDisplay_ForMaxUnsyncedFreq);
	valueDisplay_ForMaxUnsyncedFreq.setInterceptsMouseClicks(false, false);

	setSize(GUI::randomizationAllowedUnsyncedFreqForLFOComponent_w, GUI::randomizationAllowedUnsyncedFreqForLFOComponent_h);
}

void AllowedUnsyncedFreqForLFOcomponent::resized() {
	knob_ForMinUnsyncedFreq.setBounds(0, 0, GUI::knob_diameter, GUI::knob_diameter);
	valueDisplay_ForMinUnsyncedFreq.setBounds(knob_ForMinUnsyncedFreq.getBounds());
	knob_ForMaxUnsyncedFreq.setBounds(0, GUI::randomizationMaxUnsyncedFreqForLFO_y, GUI::knob_diameter, GUI::knob_diameter);
	valueDisplay_ForMaxUnsyncedFreq.setBounds(knob_ForMaxUnsyncedFreq.getBounds());
}

void AllowedUnsyncedFreqForLFOcomponent::sliderValueChanged(Slider* slider) {
	auto sliderID{ slider->getComponentID() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (sliderID == ID::component_KnobForMinUnsyncedFreqForLFO.toString() + (String)lfoNum) {
		auto newMinFreq{ (uint8)slider->getValue() };
		randomizationOptions->setMinUnsyncedFreqForLFO(newMinFreq, lfoNum);
		auto maxFreq{ randomizationOptions->maxUnsyncedFreqForLFO(lfoNum) };
		if (newMinFreq > maxFreq) {
			knob_ForMaxUnsyncedFreq.setValue((double)newMinFreq, sendNotification);
			randomizationOptions->setMaxUnsyncedFreqForLFO(newMinFreq, lfoNum);
		}
	}
	if (sliderID == ID::component_KnobForMaxUnsyncedFreqForLFO.toString() + (String)lfoNum) {
		auto newMaxFreq{ (uint8)slider->getValue() };
		randomizationOptions->setMaxUnsyncedFreqForLFO(newMaxFreq, lfoNum);
		auto minFreq{ randomizationOptions->minUnsyncedFreqForLFO(lfoNum) };
		if (newMaxFreq < minFreq) {
			knob_ForMinUnsyncedFreq.setValue((double)newMaxFreq, sendNotification);
			randomizationOptions->setMinUnsyncedFreqForLFO(newMaxFreq, lfoNum);
		}
	}
}

AllowedUnsyncedFreqForLFOcomponent::~AllowedUnsyncedFreqForLFOcomponent() {
	knob_ForMaxUnsyncedFreq.removeListener(this);
	knob_ForMinUnsyncedFreq.removeListener(this);
}
