#include "H_99-B_Misc.h"

String Int_To_Pitch_Name::convert(const int i) {
    auto note{ i % 12 };
    String pitch_name;
    switch (note) {
    case 0:  pitch_name = "C "; break;
    case 1:  pitch_name = "C# "; break;
    case 2:  pitch_name = "D "; break;
    case 3:  pitch_name = "D# "; break;
    case 4:  pitch_name = "E "; break;
    case 5:  pitch_name = "F "; break;
    case 6:  pitch_name = "F# "; break;
    case 7:  pitch_name = "G "; break;
    case 8:  pitch_name = "G# "; break;
    case 9:  pitch_name = "A "; break;
    case 10: pitch_name = "A# "; break;
    case 11: pitch_name = "B "; break;
    default: break;
    }
    return pitch_name + String{ i / 12 };
}
