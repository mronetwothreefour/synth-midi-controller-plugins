#pragma once

#include <JuceHeader.h>

using Mod_Keys = ModifierKeys;
using Tip_Client = SettableTooltipClient;

struct Tooltip_Updater_B
{
String tip_info;
String tip_value;

void on_mod_keys_changed(const Mod_Keys& mods, Tip_Client* client, Component* client_cmpnt) const {
    if (client_cmpnt->isMouseOver()) {
        if (mods == Mod_Keys::ctrlModifier || mods == Mod_Keys::shiftModifier)
            client->setTooltip(mods == Mod_Keys::ctrlModifier ? tip_info : tip_value);
        else
            client->setTooltip("");
    }
    else
        client->setTooltip("");
}
};