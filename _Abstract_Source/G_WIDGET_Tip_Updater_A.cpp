#include "G_WIDGET_Tip_Updater_A.h"

void WIDGET::Tip_Updater_A::on_mod_keys_changed(const Mods& mods, Tip_Client* client) const {
    if (mods == Mods::ctrlAltCommandModifiers)
        client->setTooltip(tip_info + "\nCurrent value: " + tip_value);
    else
        client->setTooltip("");
}
