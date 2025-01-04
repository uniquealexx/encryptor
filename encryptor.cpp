#include "encryptor.hpp"

[[nodiscard]] std::string Encryptor::Encrypt(const std::string& data, const std::string& key) const {
    return algorithm->Encrypt(data, key);
}

[[nodiscard]] std::string Encryptor::Decrypt(const std::string& data, const std::string& key) const {
    return algorithm->Decrypt(data, key);
}