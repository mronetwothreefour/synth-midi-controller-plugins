#include "up_0_tree_GlobalOptions.h"

#include "../constants/constants_Identifiers.h"

using namespace Matrix_6G_Constants;

GlobalOptions::GlobalOptions() :
    globalOptionsTree{ ID::tree_GlobalOptions }
{
    resetAllOptionsToDefaults();
}

void GlobalOptions::resetAllOptionsToDefaults() {
    setBasicChannel((uint8)1);
}

const uint8 GlobalOptions::basicChannel() {
    return (uint8)(int)globalOptionsTree.getProperty(ID::global_BasicChannel);
}

void GlobalOptions::setBasicChannel(const uint8 newChannel) {
    globalOptionsTree.setProperty(ID::global_BasicChannel, newChannel, nullptr);
}
