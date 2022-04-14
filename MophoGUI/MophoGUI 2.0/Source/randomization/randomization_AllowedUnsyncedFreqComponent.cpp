#include "randomization_AllowedUnsyncedFreqComponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



AllowedUnsyncedFreqComponent::AllowedUnsyncedFreqComponent(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams },
	knob_ForMinUnsyncedFreq{ unexposedParams },
	valueDisplay_ForMinUnsyncedFreq{ &knob_ForMinUnsyncedFreq, IntToLFOfreqString::get() },
	knob_ForMaxUnsyncedFreq{ unexposedParams },
	valueDisplay_ForMaxUnsyncedFreq{ &knob_ForMaxUnsyncedFreq, IntToLFOfreqString::get() }
{
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	String paramName{ info.exposedNameFor(paramIndex) };
	String lfoName{ paramName.upToFirstOccurrenceOf(" Frequency", false, false) };

	knob_ForMinUnsyncedFreq.setComponentID(ID::component_KnobForMinUnsyncedFreqFor_.toString() + paramID);
	knob_ForMinUnsyncedFreq.setRange(0.0, (double)params::maxUnsyncedLFOfreq, 1.0);
	knob_ForMinUnsyncedFreq.setValue((double)randomizationOptions->minUnsyncedFreqForParam(paramIndex));
	knob_ForMinUnsyncedFreq.setMouseDragSensitivity(128);
	knob_ForMinUnsyncedFreq.addListener(this);
	if (shouldShowDescriptions) {
		String knobTooltip{ "" };
		knobTooltip += "Sets the minimum un-synced\n";
		knobTooltip += "frequency allowed for " + lfoName + ".\n";
		knobTooltip += "Range: 0 (1 cycle lasts 30 sec.) to 89 (8 Hz).";
		knob_ForMinUnsyncedFreq.setTooltip(knobTooltip);
	}
	addAndMakeVisible(knob_ForMinUnsyncedFreq);

	addAndMakeVisible(valueDisplay_ForMinUnsyncedFreq);
	valueDisplay_ForMinUnsyncedFreq.setInterceptsMouseClicks(false, false);

	knob_ForMaxUnsyncedFreq.setComponentID(ID::component_KnobForMaxUnsyncedFreqFor_.toString() + paramID);
	knob_ForMaxUnsyncedFreq.setRange(0.0, (double)params::maxUnsyncedLFOfreq, 1.0);
	knob_ForMaxUnsyncedFreq.setValue((double)randomizationOptions->maxUnsyncedFreqForParam(paramIndex));
	knob_ForMaxUnsyncedFreq.setMouseDragSensitivity(128);
	knob_ForMaxUnsyncedFreq.addListener(this);
	if (shouldShowDescriptions) {
		String knobTooltip{ "" };
		knobTooltip += "Sets the maximum un-synced\n";
		knobTooltip += "frequency allowed for LFO " + lfoName + ".\n";
		knobTooltip += "Range: 0 (1 cycle lasts 30 sec.) to 89 (8 Hz).";
		knob_ForMinUnsyncedFreq.setTooltip(knobTooltip);
	}
	addAndMakeVisible(knob_ForMaxUnsyncedFreq);

	addAndMakeVisible(valueDisplay_ForMaxUnsyncedFreq);
	valueDisplay_ForMaxUnsyncedFreq.setInterceptsMouseClicks(false, false);

	setSize(GUI::randomizationAllowedUnsyncedFreqComponent_w, GUI::randomizationAllowedUnsyncedFreqComponent_h);
}

void AllowedUnsyncedFreqComponent::resized() {
	knob_ForMinUnsyncedFreq.setBounds(0, 0, GUI::knob_diameter, GUI::knob_diameter);
	valueDisplay_ForMinUnsyncedFreq.setBounds(knob_ForMinUnsyncedFreq.getBounds());
	knob_ForMaxUnsyncedFreq.setBounds(0, GUI::randomizationMaxUnsyncedFreqKnob_y, GUI::knob_diameter, GUI::knob_diameter);
	valueDisplay_ForMaxUnsyncedFreq.setBounds(knob_ForMaxUnsyncedFreq.getBounds());
}

void AllowedUnsyncedFreqComponent::sliderValueChanged(Slider* slider) {
	auto sliderID{ slider->getComponentID() };
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (sliderID == ID::component_KnobForMinUnsyncedFreqFor_.toString() + paramID) {
		auto newMinFreq{ (uint8)slider->getValue() };
		randomizationOptions->setMinUnsyncedFreqForParam(newMinFreq, paramIndex);
		auto maxFreq{ randomizationOptions->maxUnsyncedFreqForParam(paramIndex) };
		if (newMinFreq > maxFreq) {
			knob_ForMaxUnsyncedFreq.setValue((double)newMinFreq, sendNotification);
			randomizationOptions->setMaxUnsyncedFreqForParam(newMinFreq, paramIndex);
		}
	}
	if (sliderID == ID::component_KnobForMaxUnsyncedFreqFor_.toString() + paramID) {
		auto newMaxFreq{ (uint8)slider->getValue() };
		randomizationOptions->setMaxUnsyncedFreqForParam(newMaxFreq, paramIndex);
		auto minFreq{ randomizationOptions->minUnsyncedFreqForParam(paramIndex) };
		if (newMaxFreq < minFreq) {
			knob_ForMinUnsyncedFreq.setValue((double)newMaxFreq, sendNotification);
			randomizationOptions->setMinUnsyncedFreqForParam(newMaxFreq, paramIndex);
		}
	}
}

AllowedUnsyncedFreqComponent::~AllowedUnsyncedFreqComponent() {
	knob_ForMaxUnsyncedFreq.removeListener(this);
	knob_ForMinUnsyncedFreq.removeListener(this);
}
