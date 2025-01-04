#include "xor_string.hpp"

std::string XorString::Encrypt(const std::string& data, const std::string& key) {
    std::string result = data;
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = static_cast<char>(data[i] ^ key[i % key.size()]);
    }
    return result;
}

std::string XorString::Decrypt(const std::string& data, const std::string& key) {
    return Encrypt(data, key);
}