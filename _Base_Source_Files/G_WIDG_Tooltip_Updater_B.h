#pragma once

#include <JuceHeader.h>

using Mods = ModifierKeys;
using Tip_Client = SettableTooltipClient;

struct Tooltip_Updater_B
{
String tip_info;
String tip_value;

void on_mod_keys_changed(const Mods& mods, Tip_Client* client, Component* client_cmpnt) const {
    if (client_cmpnt->isMouseOver()) {
        if (mods == Mods::ctrlAltCommandModifiers)
            client->setTooltip(tip_info + "\nCurrent value: " + tip_value);
        else
            client->setTooltip("");
    }
    else
        client->setTooltip("");
}
};