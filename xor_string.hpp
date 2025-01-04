#ifndef XOR_STRING_HPP
#define XOR_STRING_HPP

#include "includes.hpp"
#include "encryptor_algorithm.hpp"

class XorString final : public EncryptionAlgorithm {
public:
    std::string Encrypt(const std::string& data, const std::string& key) override;
    std::string Decrypt(const std::string& data, const std::string& key) override;

};



#endif //XOR_STRING_HPP
