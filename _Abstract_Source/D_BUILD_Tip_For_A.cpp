#include "D_BUILD_Tip_For_A.h"

#include "C_SL_Tip_Widget_A.h"

using namespace BUILD;

String Tip_For_A::from_string_literal(const char8_t* sl) {
    String s{ sl };
    s = s.trimCharactersAtStart("\n");
    return s;
}

String Tip_For_A::txt_editor_pitch(const String& example_name, const int example_num,
								   const String& min_name, const int min_num,
								   const String& max_name, const int max_num)
{
    return from_string_literal(SL::edit_pitch_tip).replace("~", example_name)
                                                  .replace("!", (String)example_num)
                                                  .replace("@", min_name)
                                                  .replace("#", (String)min_num)
                                                  .replace("$", max_name)
                                                  .replace("%", (String)max_num);
}

String Tip_For_A::txt_editor_s_int(const int limit) {
    return from_string_literal(SL::edit_s_int_tip).replace("_", (String)abs(limit));
}

String Tip_For_A::txt_editor_u_int(const int max) {
    return from_string_literal(SL::edit_u_int_tip).replace("_", (String)max);
}
