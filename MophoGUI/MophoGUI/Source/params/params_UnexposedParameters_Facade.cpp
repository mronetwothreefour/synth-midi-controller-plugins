#include "params_UnexposedParameters_Facade.h"



UnexposedParameters::UnexposedParameters() :
	tooltipOptions{ new TooltipOptions() },
	undoManager{ new UndoManager() }
{
}

TooltipOptions* UnexposedParameters::tooltipOptions_get() {
	return tooltipOptions.get();
}

UndoManager* UnexposedParameters::undoManager_get() {
	return undoManager.get();
}

UnexposedParameters::~UnexposedParameters() {
	undoManager = nullptr;
	tooltipOptions = nullptr;
}
