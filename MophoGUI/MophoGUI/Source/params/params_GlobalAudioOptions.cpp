#include "params_GlobalAudioOptions.h"

#include "params_Identifiers.h"



GlobalAudioOptions::GlobalAudioOptions() :
	globalAudioOptionsTree{ ID::global_AudioOptions }
{
	fillglobalAudioOptionsTreeWithProperties();
}

void GlobalAudioOptions::fillglobalAudioOptionsTreeWithProperties() {
	globalAudioOptionsTree.setProperty(ID::global_Balance, (uint8)7, nullptr);
	globalAudioOptionsTree.setProperty(ID::global_FineTune, (uint8)50, nullptr);
	globalAudioOptionsTree.setProperty(ID::global_HardwareOutputIsStereo, (bool)true, nullptr);
	globalAudioOptionsTree.setProperty(ID::global_Transpose, (uint8)12, nullptr);
}

void GlobalAudioOptions::resetGlobalAudioOptionsToDefaults() {
	fillglobalAudioOptionsTreeWithProperties();
}

void GlobalAudioOptions::addListener(ValueTree::Listener* listener) {
	globalAudioOptionsTree.addListener(listener);
}

void GlobalAudioOptions::removeListener(ValueTree::Listener* listener) {
	globalAudioOptionsTree.removeListener(listener);
}

uint8 GlobalAudioOptions::globalTranspose() {
	return (uint8)(int)globalAudioOptionsTree.getProperty(ID::global_Transpose);
}

void GlobalAudioOptions::setGlobalTranspose(uint8 newTransposition) {
	globalAudioOptionsTree.setProperty(ID::global_Transpose, newTransposition, nullptr);
}

uint8 GlobalAudioOptions::globalFineTune() {
	return (uint8)(int)globalAudioOptionsTree.getProperty(ID::global_FineTune);
}

void GlobalAudioOptions::setGlobalFineTune(uint8 newFineTune) {
	globalAudioOptionsTree.setProperty(ID::global_FineTune, newFineTune, nullptr);
}

bool GlobalAudioOptions::hardwareOutputIsStereo() {
	return (bool)globalAudioOptionsTree.getProperty(ID::global_HardwareOutputIsStereo);
}

void GlobalAudioOptions::setHardwareOutputStereo() {
	globalAudioOptionsTree.setProperty(ID::global_HardwareOutputIsStereo, (bool)true, nullptr);
}

void GlobalAudioOptions::setHardwareOutputMono() {
	globalAudioOptionsTree.setProperty(ID::global_HardwareOutputIsStereo, (bool)false, nullptr);
}

uint8 GlobalAudioOptions::globalBalance() {
	return (uint8)(int)globalAudioOptionsTree.getProperty(ID::global_Balance);
}

void GlobalAudioOptions::setGlobalBalance(uint8 newBalance) {
	globalAudioOptionsTree.setProperty(ID::global_FineTune, newBalance, nullptr);
}

GlobalAudioOptions::~GlobalAudioOptions() {
}
