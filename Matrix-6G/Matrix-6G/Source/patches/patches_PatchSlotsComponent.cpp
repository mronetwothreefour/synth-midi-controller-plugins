#include "patches_PatchSlotsComponent.h"


#include "patches_RawPatchData.h"
#include "patches_RawPatchData.h"
#include "../midi/midi_PatchDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



PatchSlotsComponent::PatchSlotsComponent(PatchBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	bank{ bank },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	buttton_w{ 125 },
	buttton_h{ 19 },
	buttonHorizontalGap{ 7 },
	selectedSlot{ 100 }
{
}
