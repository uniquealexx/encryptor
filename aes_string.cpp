#include "aes_string.hpp"

std::string AESString::Encrypt(const std::string &data, const std::string &key) {
    if (key.size() != 32) {
        throw std::runtime_error("Key must be 32 bytes for AES-256");
    }

    std::vector<unsigned char> iv(16);
    if (1 != RAND_bytes(iv.data(), static_cast<int>(iv.size()))) {
        throw std::runtime_error("Failed to generate IV");
    }

    std::vector<unsigned char> ciphertext = AESEncrypt(
        std::vector<unsigned char>(data.begin(), data.end()),
        std::vector<unsigned char>(key.begin(), key.end()),
        iv
    );

    std::string result(iv.begin(), iv.end());
    result.append(ciphertext.begin(), ciphertext.end());

    return result;
}

std::string AESString::Decrypt(const std::string &data, const std::string &key) {
    if (key.size() != 32) {
        throw std::runtime_error("Key must be 32 bytes for AES-256");
    }

    if (data.size() < 16) {
        throw std::runtime_error("Invalid ciphertext: too short");
    }

    const std::vector<unsigned char> iv(data.begin(), data.begin() + 16);
    const std::vector<unsigned char> ciphertext(data.begin() + 16, data.end());

    std::vector<unsigned char> plaintext = AESDecrypt(
        ciphertext,
        std::vector<unsigned char>(key.begin(), key.end()),
        iv
    );

    return {plaintext.begin(), plaintext.end()};
}

std::vector<unsigned char> AESString::AESEncrypt(const std::vector<unsigned char> &plaintext,
    const std::vector<unsigned char> &key, const std::vector<unsigned char> &iv) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        throw std::runtime_error("Failed to create EVP_CIPHER_CTX");
    }

    int len;
    std::vector<unsigned char> ciphertext(plaintext.size() + AES_BLOCK_SIZE);

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key.data(), iv.data())) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Failed to initialize encryption");
    }

    if (1 != EVP_EncryptUpdate(ctx, ciphertext.data(), &len, plaintext.data(), static_cast<int>(plaintext.size()))) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Failed to encrypt plaintext");
    }

    int ciphertext_len = len;
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext.data() + len, &len)) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Failed to finalize encryption");
    }

    ciphertext_len += len;
    ciphertext.resize(ciphertext_len);

    EVP_CIPHER_CTX_free(ctx);
    return ciphertext;
}

std::vector<unsigned char> AESString::AESDecrypt(const std::vector<unsigned char>& ciphertext,
    const std::vector<unsigned char>& key, const std::vector<unsigned char>& iv) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        throw std::runtime_error("Failed to create EVP_CIPHER_CTX");
    }

    int len;
    std::vector<unsigned char> plaintext(ciphertext.size());

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key.data(), iv.data())) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Failed to initialize decryption");
    }

    if (1 != EVP_DecryptUpdate(ctx, plaintext.data(), &len, ciphertext.data(), static_cast<int>(ciphertext.size()))) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Failed to decrypt ciphertext");
    }

    int plaintext_len = len;
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext.data() + len, &len)) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Failed to finalize decryption");
    }

    plaintext_len += len;
    plaintext.resize(plaintext_len);

    EVP_CIPHER_CTX_free(ctx);
    return plaintext;
}
