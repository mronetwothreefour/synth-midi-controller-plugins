#include "params_UnexposedParameters_Facade.h"



UnexposedParameters::UnexposedParameters() :
	undoManager{ new UndoManager() }
{
}

UndoManager* UnexposedParameters::undoManager_get() {
	return undoManager.get();
}

UnexposedParameters::~UnexposedParameters() {
	undoManager = nullptr;
}
