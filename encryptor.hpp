#ifndef ENCRYPTOR_HPP
#define ENCRYPTOR_HPP

#include "includes.hpp"
#include "encryptor_algorithm.hpp"

class Encryptor {
    std::unique_ptr<EncryptionAlgorithm> algorithm;

public:
    explicit Encryptor(std::unique_ptr<EncryptionAlgorithm> algo)
            : algorithm(std::move(algo)) {}

    [[nodiscard]] std::string Encrypt(const std::string& data, const std::string& key) const;
    [[nodiscard]] std::string Decrypt(const std::string& data, const std::string& key) const;

};

#endif //ENCRYPTOR_HPP
