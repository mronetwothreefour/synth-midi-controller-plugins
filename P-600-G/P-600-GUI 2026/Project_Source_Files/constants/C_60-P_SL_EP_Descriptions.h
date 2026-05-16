#pragma once

namespace SL
{

    constexpr auto env_attack_description = u8R"(
Sets the amount of time it takes for the _type of_
envelope to rise from zero to maximum level.
Range: 0 (instantaneous) to 15 (longest time))";

    constexpr auto env_decay_description = u8R"(
Sets the amount of time it takes for the _type of_ envelope
to fall from maximum level down to the sustain level.
Range: 0 (instantaneous) to 15 (longest time))";

    constexpr auto env_release_description = u8R"(
Sets the amount of time it takes for the _type of_
envelope to fall to zero once the note is released.
Range: 0 (instantaneous) to 15 (longest time))";

    constexpr auto env_sustain_description = u8R"(
Sets the sustain level for the _type of_ envelope.
The envelope decays to this level and
holds there until the note is released.
Range: 0 to 15 (maximum level))";

};