#pragma once

#include <JuceHeader.h>

#include "guiControl_WithExposedParameterAttachment.h"
#include "../parameters/parameters_SynthParameters.h"

class ControlWithExposedParameterAttachment_Database
{
	std::vector<std::unique_ptr<ControlWithExposedParameterAttachment>> controlVector{};

	ControlWithExposedParameterAttachment_Database()
	{
		fillControlVector();
	}

	~ControlWithExposedParameterAttachment_Database()
	{
		controlVector.clear();
	}

	void fillControlVector()
	{
		auto& exposedParamsDB{ ExposedSynthParameters_Database::get() };
		for (uint8 index = 0; index != exposedParamsDB.size(); ++index)
		{
			auto param{ exposedParamsDB.getSynthParameter(index) };
			controlVector.push_back(std::make_unique<ControlWithExposedParameterAttachment>(param.controlType));
		}
	}

public:
	ControlWithExposedParameterAttachment_Database(ControlWithExposedParameterAttachment_Database const&) = delete;
	ControlWithExposedParameterAttachment_Database(ControlWithExposedParameterAttachment_Database&&) = delete;
	ControlWithExposedParameterAttachment_Database& operator=(ControlWithExposedParameterAttachment_Database const&) = delete;
	ControlWithExposedParameterAttachment_Database& operator=(ControlWithExposedParameterAttachment_Database&&) = delete;

	static ControlWithExposedParameterAttachment_Database& get()
	{
		static ControlWithExposedParameterAttachment_Database controlDatabase;
		return controlDatabase;
	}

	ControlWithExposedParameterAttachment* getControl(uint16 index) const { return controlVector[index].get(); }
};
