#include "D_BUILD_Tip_A.h"

String Build_Tip_A::from_string_literal(const char8_t* sl) {
    String s{ sl };
    s = s.trimCharactersAtStart("\n");
    return s;
}
