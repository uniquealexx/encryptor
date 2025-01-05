cmake_minimum_required(VERSION 3.30)
project(encrypt_tool)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenSSL REQUIRED)

add_executable(encrypt_tool main.cpp
        encryptor.cpp
        encryptor.hpp
        xor_string.cpp
        xor_string.hpp
        encryptor_algorithm.hpp
        includes.hpp
        aes_string.cpp
        aes_string.hpp
)

target_link_libraries(encrypt_tool PRIVATE OpenSSL::Crypto OpenSSL::SSL)
target_include_directories(encrypt_tool PRIVATE ${OPENSSL_INCLUDE_DIR})