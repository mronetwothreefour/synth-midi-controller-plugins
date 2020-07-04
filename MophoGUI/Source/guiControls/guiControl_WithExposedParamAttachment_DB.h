#pragma once

#include <JuceHeader.h>

#include "guiControl_WithExposedParameterAttachment.h"

class ControlWithExposedParameterAttachment_Database
{
	std::vector<std::unique_ptr<ControlWithExposedParameterAttachment>> controlVector;

	ControlWithExposedParameterAttachment_Database() {
		fillControlVector();
	}

	~ControlWithExposedParameterAttachment_Database() {
		controlVector.clear();
	}

	void fillControlVector() {
		auto& paramInfoArray{ ExposedParamInfoArray_Singleton::get() };
		for (uint16 index = 0; index != paramInfoArray.size(); ++index) {
			controlVector.push_back(std::make_unique<ControlWithExposedParameterAttachment>(index));
		}
	}

public:
	ControlWithExposedParameterAttachment_Database(ControlWithExposedParameterAttachment_Database const&) = delete;
	ControlWithExposedParameterAttachment_Database(ControlWithExposedParameterAttachment_Database&&) = delete;
	ControlWithExposedParameterAttachment_Database& operator=(ControlWithExposedParameterAttachment_Database const&) = delete;
	ControlWithExposedParameterAttachment_Database& operator=(ControlWithExposedParameterAttachment_Database&&) = delete;

	static ControlWithExposedParameterAttachment_Database& get() {
		static ControlWithExposedParameterAttachment_Database controlDatabase;
		return controlDatabase;
	}

	ControlWithExposedParameterAttachment* getControl(uint16 index) const { 
		return controlVector[index].get(); 
	}
};
