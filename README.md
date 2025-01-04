### About program

This C++ program provides a command-line tool for encrypting and decrypting text files using two encryption algorithms: **XOR** and **AES** (Advanced Encryption Standard). It is designed to offer a simple yet secure way to protect sensitive information stored in text files.

#### Features:
- **XOR Encryption**: A lightweight encryption method using a user-provided key. Ideal for basic obfuscation of text data.
- **AES Encryption**: A robust and industry-standard encryption algorithm for securing text files with a high level of security.
- **Command-Line Interface**: Supports command-line arguments for specifying the encryption method, input/output files, and keys.
- **File Handling**: Reads plaintext from input files and writes encrypted data to output files, ensuring easy integration into workflows.

#### Usage:
The program accepts the following command-line options:
- `-xor <key>`: Encrypts/decrypts the input file using XOR with the provided key.
- `-aes <key>`: Encrypts/decrypts the input file using AES with the provided key.
- `-i <input_file>`: Specifies the input text file.
- `-o <output_file>`: Specifies the output file for the encrypted/decrypted data.
- `-h` or `--help`: Displays the help message with usage instructions.

#### Example Commands:
1. Encrypt a file using XOR:
   ```
   ./encrypt_tool -xor mykey -i input.txt -o encrypted.txt
   ```
2. Decrypt a file using AES:
   ```
   ./encrypt_tool -aes mysecretkey -i encrypted.txt -o decrypted.txt
   ```

#### Requirements:
- C++20 or later.
- A compiler with support for the `<filesystem>` and cryptographic libraries (e.g., OpenSSL for AES).

This tool is ideal for developers, security enthusiasts, or anyone looking to quickly encrypt text files using simple command-line operations.
