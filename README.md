### About Program

This C++ program provides a command-line tool for encrypting and decrypting text files using two encryption algorithms: **XOR** and **AES** (Advanced Encryption Standard). It is designed to offer a simple yet secure way to protect sensitive information stored in text files.

---

#### Features:
- **XOR Encryption**: A lightweight encryption method using a user-provided key. Ideal for basic obfuscation of text data.
- **AES Encryption**: A robust and industry-standard encryption algorithm for securing text files with a high level of security.
- **Command-Line Interface**: Supports command-line arguments for specifying the encryption method, input/output files, and keys.
- **File Handling**: Reads plaintext from input files and writes encrypted data to output files, ensuring easy integration into workflows.

---

#### Usage:
The program accepts the following command-line options:
- `-xor <key>`: Encrypts/decrypts the input file using XOR with the provided key.
- `-aes <key>`: Encrypts/decrypts the input file using AES with the provided key.
- `-e`: Encrypts the input file (used with `-aes`).
- `-d`: Decrypts the input file (used with `-aes`).
- `-i <input_file>`: Specifies the input text file.
- `-o <output_file>`: Specifies the output file for the encrypted/decrypted data.
- `-h` or `--help`: Displays the help message with usage instructions.

---

#### Example Commands:
1. **Encrypt a file using XOR**:
   ```
   ./encrypt_tool -xor mykey -i input.txt -o encrypted.txt
   ```

2. **Decrypt a file using XOR**:
   ```
   ./encrypt_tool -xor mykey -i encrypted.txt -o decrypted.txt
   ```

3. **Encrypt a file using AES**:
   ```
   ./encrypt_tool -aes mysecretkey -i input.txt -o encrypted.txt -e
   ```

4. **Decrypt a file using AES**:
   ```
   ./encrypt_tool -aes mysecretkey -i encrypted.txt -o decrypted.txt -d
   ```

---

#### Requirements:
- **C++20 or later**: The program uses modern C++ features.
- **OpenSSL**: Required for AES encryption/decryption.
- **Compiler**: A compiler with support for the `<filesystem>` library and cryptographic libraries (e.g., OpenSSL for AES).

---

#### Installation Instructions:

##### 1. **Install OpenSSL**:
- **Ubuntu/Debian**:
  ```bash
  sudo apt update
  sudo apt install libssl-dev
  ```
- **macOS** (using Homebrew):
  ```bash
  brew install openssl
  ```
- **Windows**:
   - Download and install OpenSSL from the [official website](https://slproweb.com/products/Win32OpenSSL.html).
   - Alternatively, use a package manager like `vcpkg`:
     ```bash
     vcpkg install openssl
     ```

##### 2. **Build the Program**:
- Clone the repository or download the source code.
- Navigate to the project directory:
  ```bash
  cd /path/to/project
  ```
- Create a build directory and compile the program:
  ```bash
  mkdir build
  cd build
  cmake ..
  make
  ```
- The executable `encrypt_tool` will be generated in the `build` directory.

##### 3. **Run the Program**:
- Use the command-line interface to encrypt or decrypt files as described in the **Usage** section.

---

#### Notes:
- **AES Key Length**: The AES key must be 32 bytes (256 bits) long. If the key is shorter, pad it with zeros or truncate it to meet the requirement.
- **XOR Key**: The XOR key can be of any length, but longer keys provide better security.
- **File Handling**: Ensure that the input and output files are accessible and have the correct permissions.

---

#### Example Workflow:
1. **Encrypt a file with AES**:
   ```bash
   ./encrypt_tool -aes "my_32_byte_aes_key_1234567890abcdef" -i secret.txt -o encrypted_secret.txt -e
   ```

2. **Decrypt the file with AES**:
   ```bash
   ./encrypt_tool -aes "my_32_byte_aes_key_1234567890abcdef" -i encrypted_secret.txt -o decrypted_secret.txt -d
   ```

3. **Encrypt a file with XOR**:
   ```bash
   ./encrypt_tool -xor "my_xor_key" -i plaintext.txt -o encrypted.txt
   ```

4. **Decrypt the file with XOR**:
   ```bash
   ./encrypt_tool -xor "my_xor_key" -i encrypted.txt -o decrypted.txt
   ```

---

#### Troubleshooting:
- **OpenSSL Not Found**: If the build process fails with errors related to OpenSSL, ensure that OpenSSL is installed and properly linked in your `CMakeLists.txt` file.
  ```cmake
  find_package(OpenSSL REQUIRED)
  target_link_libraries(encrypt_tool PRIVATE OpenSSL::Crypto)
  ```
- **Invalid Key Length**: If the AES key is not 32 bytes, the program will throw an error. Ensure the key is exactly 32 bytes long.

---