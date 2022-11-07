#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;
using MM_Type = MatrixModParamType;

class InfoForExposedParameters;
class MatrixModOptions;

class ParamRandomizationOptions
{
	ValueTree randomizationOptionsTree;
	InfoForExposedParameters* info;
	MatrixModOptions* matrixModOptions;

public:
	ParamRandomizationOptions() = delete;

	explicit ParamRandomizationOptions(InfoForExposedParameters* info, MatrixModOptions* matrixModOptions);

	const bool transmitMethodIsQuickEdit();
	void setTransmitMethodIsQuickEdit(bool shouldBeQuickEdit);

	const bool paramIsLocked(uint8 paramIndex);
	const bool paramIsUnlocked(uint8 paramIndex);
	void setParamIsLocked(uint8 paramIndex, bool shouldBeLocked);
	Value getParamIsLockedAsValue(uint8 paramIndex);

	const bool choiceIsAllowedForParam(uint8 choiceNum, uint8 paramIndex);
	void setChoiceIsAllowedForParam(uint8 choiceNum, bool shouldBeAllowed, uint8 paramIndex);
	void clearAllowedChoicesForParam(uint8 paramIndex);
	void allowAllChoicesForParam(uint8 paramIndex);

private:
	void checkNumberOfChoicesAllowedForParam(uint8 paramIndex);

public:
	const bool onlyOneChoiceIsAllowedForParam(uint8 paramIndex);
	Value getOnlyOneChoiceIsAllowedForParamAsValue(uint8 paramIndex);
	const bool noChoiceIsAllowedForParam(uint8 paramIndex);

	const bool repeatChoicesAreAllowedForParam(uint8 paramIndex);
	const bool repeatChoicesAreForbiddenForParam(uint8 paramIndex);
	void setRepeatChoicesAreAllowedForParam(bool shouldBeAllowed, uint8 paramIndex);

	ValueTree getCopyOfAllowedChoicesTreeForParam(uint8 paramIndex);

	const bool matrixModParamIsLocked(int modNum, MM_Type paramType);
	const bool matrixModParamIsUnlocked(int modNum, MM_Type paramType);
	void setMatrixModParamIsLocked(int modNum, MM_Type paramType, bool shouldBeLocked);
	Value getMatrixModParamIsLockedAsValue(int modNum, MM_Type paramType);

	const bool choiceIsAllowedForMatrixModParam(uint8 choiceNum, int modNum, MM_Type paramType);
	void setChoiceIsAllowedForMatrixModParam(uint8 choiceNum, bool shouldBeAllowed, int modNum, MM_Type paramType);
	void clearAllowedChoicesForMatrixModParam(int modNum, MM_Type paramType);
	void allowAllChoicesForMatrixModParam(int modNum, MM_Type paramType);

private:
	void checkNumberOfChoicesAllowedForMatrixModParam(int modNum, MM_Type paramType);

public:
	const bool onlyOneChoiceIsAllowedForMatrixModParam(int modNum, MM_Type paramType);
	Value getOnlyOneChoiceIsAllowedForMatrixModParamAsValue(int modNum, MM_Type paramType);
	const bool noChoiceIsAllowedForMatrixModParam(int modNum, MM_Type paramType);

	const bool repeatChoicesAreAllowedForMatrixModParam(int modNum, MM_Type paramType);
	const bool repeatChoicesAreForbiddenForMatrixModParam(int modNum, MM_Type paramType);
	void setRepeatChoicesAreAllowedForMatrixModParam(bool shouldBeAllowed, int modNum, MM_Type paramType);

	ValueTree getCopyOfAllowedChoicesTreeForMatrixModParam(int modNum, MM_Type paramType);

	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParamRandomizationOptions)

};
