#ifndef ENCRYPTOR_ALGORITHM_HPP
#define ENCRYPTOR_ALGORITHM_HPP

class EncryptionAlgorithm {
public:
    virtual std::string Encrypt(const std::string& data, const std::string& key) = 0;
    virtual std::string Decrypt(const std::string& data, const std::string& key) = 0;
    virtual ~EncryptionAlgorithm() = default;
};

#endif //ENCRYPTOR_ALGORITHM_HPP
