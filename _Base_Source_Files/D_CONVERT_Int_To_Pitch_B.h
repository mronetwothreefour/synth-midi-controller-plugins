#pragma once

#include <JuceHeader.h>

struct Int_To_Pitch
{
    static String convert(const int i) {
        auto note{ i % 12 };
        String pitch;
        switch (note) {
        case 0:  pitch = "C "; break;
        case 1:  pitch = "C# "; break;
        case 2:  pitch = "D "; break;
        case 3:  pitch = "D# "; break;
        case 4:  pitch = "E "; break;
        case 5:  pitch = "F "; break;
        case 6:  pitch = "F# "; break;
        case 7:  pitch = "G "; break;
        case 8:  pitch = "G# "; break;
        case 9:  pitch = "A "; break;
        case 10: pitch = "A# "; break;
        case 11: pitch = "B "; break;
        default: break;
        }
        return pitch + String{ i / 12 };
    }
};