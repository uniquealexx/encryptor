cmake_minimum_required(VERSION 3.30)
project(encryptor)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenSSL REQUIRED)

add_executable(encryptor main.cpp
        encryptor.cpp
        encryptor.hpp
        xor_string.cpp
        xor_string.hpp
        encryptor_algorithm.hpp
        includes.hpp
        aes_string.cpp
        aes_string.hpp
)

target_link_libraries(encryptor PRIVATE OpenSSL::Crypto OpenSSL::SSL)
target_include_directories(encryptor PRIVATE ${OPENSSL_INCLUDE_DIR})