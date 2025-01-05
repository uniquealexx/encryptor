#ifndef AES_STRING_HPP
#define AES_STRING_HPP

#include "includes.hpp"
#include "encryptor_algorithm.hpp"

class AESString final : public EncryptionAlgorithm{
public:
    std::string Encrypt(const std::string& data, const std::string& key) override;
    std::string Decrypt(const std::string& data, const std::string& key) override;
private:
    static std::vector<unsigned char> AESEncrypt(const std::vector<unsigned char>& plaintext, const std::vector<unsigned char>& key, const std::vector<unsigned char>& iv);
    static std::vector<unsigned char> AESDecrypt(const std::vector<unsigned char>& ciphertext, const std::vector<unsigned char>& key, const std::vector<unsigned char>& iv);
};

#endif //AES_STRING_HPP
