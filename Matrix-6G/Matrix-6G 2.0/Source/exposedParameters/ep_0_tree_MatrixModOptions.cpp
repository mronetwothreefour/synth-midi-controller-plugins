#include "ep_0_tree_MatrixModOptions.h"

#include "../constants/constants_Identifiers.h"
#include "../constants/constants_MatrixMod.h"

using namespace Matrix_6G_Constants;

MatrixModOptions::MatrixModOptions(UndoManager* undoManager) :
    matrixModOptionsTree{ ID::tree_MatrixModOptions },
	undoManager{ undoManager }
{
	for (auto modNum = 0; modNum != MMOD::numberOfModulators; ++modNum) {
		uint8 defaultSource{ 0 };
		uint8 defaultDest{ 0 };
		if (modNum == 0) {
			defaultSource = 17;
			defaultDest = 16;
		}
		if (modNum == 1) {
			defaultSource = 17;
			defaultDest = 21;
		}
		if (modNum == 2) {
			defaultSource = 11;
			defaultDest = 9;
		}
		if (modNum == 3) {
			defaultSource = 20;
			defaultDest = 8;
		}
		matrixModOptionsTree.setProperty(buildMatrixModParamID(modNum, MM_Type::source), defaultSource, nullptr);
		matrixModOptionsTree.setProperty(buildMatrixModParamID(modNum, MM_Type::amount), 63, nullptr);
		matrixModOptionsTree.setProperty(buildMatrixModParamID(modNum, MM_Type::destination), defaultDest, nullptr);
	}
}

Identifier MatrixModOptions::buildMatrixModParamID(int modNum, MM_Type paramType) {
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto modID{ "matrixMod_Mod_" + (String)modNum };
	switch (paramType)
	{
	case MM_Type::source: modID += "_Source"; break;
	case MM_Type::amount: modID += "_Amount"; break;
	case MM_Type::destination: modID += "_Dest"; break;
	default: break;
	}
	return Identifier{ modID };
}

const uint8 MatrixModOptions::modSource(int modNum) {
	return (uint8)(int)matrixModOptionsTree.getProperty(buildMatrixModParamID(modNum, MM_Type::source));
}

void MatrixModOptions::setModSource(int modNum, uint8 newSource) {
	jassert(newSource < MMOD::numberOfSrcChoices);
	jassert(modNum < MMOD::numberOfModulators);
	undoManager->beginNewTransaction();
	matrixModOptionsTree.setProperty(buildMatrixModParamID(modNum, MM_Type::source), newSource, undoManager);
}

const uint8 MatrixModOptions::modAmount(int modNum) {
	return (uint8)(int)matrixModOptionsTree.getProperty(buildMatrixModParamID(modNum, MM_Type::amount));
}

void MatrixModOptions::setModAmount(int modNum, uint8 newAmount) {
	jassert(newAmount < MMOD::numberOfAmtChoices);
	jassert(modNum < MMOD::numberOfModulators);
	undoManager->beginNewTransaction();
	matrixModOptionsTree.setProperty(buildMatrixModParamID(modNum, MM_Type::amount), newAmount, undoManager);
}

const uint8 MatrixModOptions::modDest(int modNum) {
	return (uint8)(int)matrixModOptionsTree.getProperty(buildMatrixModParamID(modNum, MM_Type::destination));
}

void MatrixModOptions::setModDest(int modNum, uint8 newDest) {
	jassert(newDest < MMOD::numberOfDestChoices);
	jassert(modNum < MMOD::numberOfModulators);
	undoManager->beginNewTransaction();
	matrixModOptionsTree.setProperty(buildMatrixModParamID(modNum, MM_Type::destination), newDest, undoManager);
}

Value MatrixModOptions::getMatrixModPropertyAsValue(const Identifier propertyID) {
	return matrixModOptionsTree.getPropertyAsValue(propertyID, nullptr);
}

XmlElement* MatrixModOptions::getStateXml() {
	auto matrixModOptionsTreeStateXml{ matrixModOptionsTree.createXml() };
	if (matrixModOptionsTreeStateXml != nullptr)
		matrixModOptionsTreeStateXml->setTagName(ID::state_MatrixModOptions);
	return matrixModOptionsTreeStateXml.release();
}

void MatrixModOptions::replaceState(const ValueTree& newState) {
	if (newState.isValid())
		matrixModOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}
