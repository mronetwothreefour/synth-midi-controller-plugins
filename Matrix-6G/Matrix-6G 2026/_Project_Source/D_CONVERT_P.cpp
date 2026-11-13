#include "D_CONVERT_P.h"

#include "C_MIDI_P.h"

const std::vector<uint8> CONVERT::to_data_vector(const String& hex_string) {
    std::vector<uint8> data;
    for (auto i = 0; i < hex_string.length() - 2; ++i) {
        String c{ hex_string[i] };
        data.push_back((uint8)c.getHexValue32());
    }
    auto checksum{ hex_string.getLastCharacters(2) };
    data.push_back((uint8)checksum.getHexValue32());
    return data;
}

const String CONVERT::to_hex_string(const std::vector<uint8> data) {
    String hex_string;
    auto checksum_index{ data.size() - 1 };
    for (auto i = 0; i < checksum_index; ++i)
        hex_string += String::toHexString(&data[i], 1, 0)[1];
    hex_string += String::toHexString(&data[checksum_index], 1, 0);
    return hex_string;
}

void CONVERT::signed_val_from_app_to_device_format(bool s_7_bit, uint8& v) {
    auto formatted_val = v - (s_7_bit ? 63 : 31);
    if (formatted_val < 0)
        formatted_val += 256;
    v = (uint8)formatted_val;
}

void CONVERT::signed_val_from_device_to_app_format(bool s_7_bit, uint8& v) {
    int formatted_val{ v };
    if (formatted_val > 127)
        formatted_val -= 256;
    formatted_val += (s_7_bit ? 63 : 31);
    v = (uint8)formatted_val;
}
