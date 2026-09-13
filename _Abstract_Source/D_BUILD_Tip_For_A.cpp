#include "D_BUILD_Tip_For_A.h"

#include <JuceHeader.h>

#include "C_SL_Tip_Widget_A.h"
#include "D_CONVERT_A.h"

using namespace BUILD;

std::string Tip_For_A::from_SL(const char8_t* sl) {
    String s{ sl };
    s = s.trimCharactersAtStart("\n");
    return s.toStdString();
}

std::string Tip_For_A::txt_editor_pitch(const unsigned int example,
                                        const unsigned int min,
                                        const unsigned int max) 
{
    String s{ from_SL(SL::edit_pitch_tip) };
    s = s.replace("~", CONVERT_A::int_to_pitch(example).removeCharacters(" "))
        .replace("!", (String)example)
        .replace("@", CONVERT_A::int_to_pitch(min).removeCharacters(" "))
        .replace("&", (String)min)
        .replace("$", CONVERT_A::int_to_pitch(max).removeCharacters(" "))
        .replace("%", (String)max);
    return s.toStdString();
}

std::string Tip_For_A::txt_editor_s_int(const int limit) {
    String s{ from_SL(SL::edit_s_int_tip) };
    s = s.replace("_", (String)abs(limit));
    return s.toStdString();
}

std::string Tip_For_A::txt_editor_u_int(const unsigned int max) {
    String s{ from_SL(SL::edit_u_int_tip) };
    s = s.replace("_", (String)max);
    return s.toStdString();
}
