cmake_minimum_required(VERSION 3.30)
project(encryptor)

set(CMAKE_CXX_STANDARD 20)

add_executable(encryptor main.cpp
        encryptor.cpp
        encryptor.hpp
        xor_string.cpp
        xor_string.hpp
        encryptor_algorithm.hpp
        includes.hpp)
