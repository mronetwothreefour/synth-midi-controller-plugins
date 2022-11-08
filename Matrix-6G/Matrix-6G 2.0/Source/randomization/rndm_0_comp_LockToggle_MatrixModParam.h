#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"
#include "../constants/constants_MatrixMod.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace Matrix_6G_Constants;
using MM_Type = MatrixModParamType;

class LockToggle_MatrixModParam :
	public ToggleButton,
	public Value::Listener
{
	int modNum;
	MM_Type paramType;
	Value paramIsLockedAsValue;

public:
	LockToggle_MatrixModParam() = delete;

	LockToggle_MatrixModParam(int modNum, MM_Type paramType, ExposedParameters* exposedParams) :
		modNum{ modNum },
		paramType{ paramType },
		paramIsLockedAsValue{ exposedParams->randomization->getMatrixModParamIsLockedAsValue(modNum, paramType) }
	{
		jassert(modNum < MMOD::numberOfModulators);

		paramIsLockedAsValue.addListener(this);

		setComponentID(ID::comp_LockToggle.toString());
		setToggleState(exposedParams->randomization->matrixModParamIsLocked(modNum, paramType), dontSendNotification);
		auto toggle_w{ paramType == MM_Type::amount ? GUI::matrixModSlider_w : GUI::matrixModComboBox_w };
		setSize(toggle_w, GUI::control_h);

	}

	void valueChanged(Value& /*value*/) override {
		setToggleState((bool)paramIsLockedAsValue.getValue(), dontSendNotification);
	}

	~LockToggle_MatrixModParam() {
		paramIsLockedAsValue.removeListener(this);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LockToggle_MatrixModParam)
};