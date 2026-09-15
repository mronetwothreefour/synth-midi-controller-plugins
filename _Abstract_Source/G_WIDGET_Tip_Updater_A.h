#pragma once

#include <JuceHeader.h>

using Mods = ModifierKeys;
using Tip_Client = SettableTooltipClient;

namespace WIDGET
{

    struct Tip_Updater_A
    {
        std::string tip_info;
        std::string tip_current_choice;

        void on_mod_keys_changed(const Mods& mods, Tip_Client* client) const;
    };

}