#pragma once

#include <JuceHeader.h>



enum class PatchBank {
	factory1 = 0,
	factory2,
	factory3,
	custom1,
	custom2,
	custom3
};



class PatchBanks :
	public ValueTree::Listener
{

};