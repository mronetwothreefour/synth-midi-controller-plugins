#include "up_facade_UnexposedParameters.h"

UnexposedParameters::UnexposedParameters() :
	undoManager{ new UndoManager() }
{
}

UndoManager* UnexposedParameters::getUndoManager() {
	return undoManager.get();
}

UnexposedParameters::~UnexposedParameters() {
	undoManager = nullptr;
}
