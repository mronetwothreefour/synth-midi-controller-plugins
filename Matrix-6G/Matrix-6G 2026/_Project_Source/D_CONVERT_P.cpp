#include "D_CONVERT_P.h"

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

const String& CONVERT::to_hex_string(const std::vector<uint8> data) {
    String hex_string;
    auto checksum_index{ data.size() - 1 };
    for (auto i = 0; i < checksum_index; ++i)
        hex_string += String::toHexString(&data[i], 1, 0)[1];
    hex_string += String::toHexString(&data[checksum_index], 1, 0);
    return hex_string;
}
