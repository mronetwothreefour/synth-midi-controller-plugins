#pragma once

#include <JuceHeader.h>

struct Tip_B
{
	static String from_string_literal(const char8_t* sl) {
        String s{ sl };
        s = s.trimCharactersAtStart("\n");
        return s;
    }
};