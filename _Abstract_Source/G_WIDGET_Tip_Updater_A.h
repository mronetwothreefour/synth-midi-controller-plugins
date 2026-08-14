#pragma once

#include <JuceHeader.h>

using Mods = ModifierKeys;
using Tip_Client = SettableTooltipClient;

namespace WIDGET
{

    struct Tip_Updater_A
    {
        String tip_info;
        String tip_value;

        void on_mod_keys_changed(const Mods& mods, Tip_Client* client) const;
    };

}