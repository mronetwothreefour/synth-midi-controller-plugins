#pragma once

#include <JuceHeader.h>

#include "C_GET_A.h"

struct GET :
	public GET_A
{
	static const StringArray bit_locations_for(const std::string& id);

	static const bool init_sli_is_mapped(const std::string& id);
	static const int init_sli_increment_shift(const std::string& id);
	static const int init_sli_increment_ctrl(const std::string& id);
	static const bool init_sli_alt_snaps(const std::string& id);

	static const int init_txt_editor_offset(const std::string& id);
};
