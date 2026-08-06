#pragma once

#include <JuceHeader.h>

using Mods = ModifierKeys;
using Tip_Client = SettableTooltipClient;

struct Tip_Updater_G
{
    String tip_info;
    String tip_value;

    void on_mod_keys_changed(const Mods& mods, Tip_Client* client) const {
        if (mods == Mods::ctrlAltCommandModifiers)
            client->setTooltip(tip_info + "\nCurrent value: " + tip_value);
        else
            client->setTooltip("");
    }
};