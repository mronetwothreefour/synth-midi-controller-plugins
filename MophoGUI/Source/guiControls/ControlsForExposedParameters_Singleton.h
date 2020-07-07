#pragma once

#include <JuceHeader.h>

#include "ControlForExposedParameter.h"



struct ControlsForExposedParameters_Singleton
{
	std::vector<std::unique_ptr<ControlForExposedParameter>> controlsVector;

	ControlsForExposedParameters_Singleton(ControlsForExposedParameters_Singleton const&) = delete;
	ControlsForExposedParameters_Singleton(ControlsForExposedParameters_Singleton&&) = delete;
	ControlsForExposedParameters_Singleton& operator=(ControlsForExposedParameters_Singleton const&) = delete;
	ControlsForExposedParameters_Singleton& operator=(ControlsForExposedParameters_Singleton&&) = delete;

	static std::vector<std::unique_ptr<ControlForExposedParameter>>& get() {
		static ControlsForExposedParameters_Singleton controlDatabase;
		return controlDatabase.controlsVector;
	}

private:
	ControlsForExposedParameters_Singleton() {
		fillControlsVector();
	}

	~ControlsForExposedParameters_Singleton() {
		controlsVector.clear();
	}

	void fillControlsVector() {
		auto& paramInfoArray{ InfoForExposedParameters_Singleton::get() };
		for (uint16 index = 0; index != paramInfoArray.size(); ++index) {
			controlsVector.push_back(std::make_unique<ControlForExposedParameter>(index));
		}
	}
};
