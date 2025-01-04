#include "encryptor.hpp"
#include "xor_string.hpp"

namespace fs = std::filesystem;

int main(const int argc, char* argv[]) {
    std::unordered_map<std::string, std::string> options;
    std::vector<std::string> lines;
    std::vector<std::string> encryptedLines;

#pragma region Parameters
    for (int i = 1; i < argc; ++i) {
        if (std::string arg = argv[i]; arg == "-h" || arg == "--help") {
            std::cout << "Usage: " << argv[0] << "[options]\n"
                      << "Options:\n"
                      << "  -h, --help              Displays the help message with usage instructions\n"
                      << "  -i <input_file>         Specifies the input text file\n"
                      << "  -o <output_file>        Specifies the output file for the encrypted/decrypted data\n"
                      << "  -xor <value>            Encrypts/decrypts the input file using XOR with the provided key\n"
                      << "  -aes <key>              Encrypts/decrypts the input file using AES with the provided key\n";
            return 0;
        } else if (arg == "-xor") {
            if (i + 1 < argc) {
                options["xor"] = argv[++i];
            } else {
                std::cerr << "Error: -xor requires a value." << std::endl;
                return 1;
            }
        } else if (arg == "-aes") {
            if (i + 1 < argc) {
                options["aes"] = argv[++i];
            } else {
                std::cerr << "Error: -aes requires a key." << std::endl;
                return 1;
            }
        } else if (arg == "-i") {
            if (i + 1 < argc) {
                options["input"] = argv[++i];
            } else {
                std::cerr << "Error: -i requires an input file." << std::endl;
                return 1;
            }
        } else if (arg == "-o") {
            if (i + 1 < argc) {
                options["output"] = argv[++i];
            } else {
                std::cerr << "Error: -o requires an output file." << std::endl;
                return 1;
            }
        } else {
            std::cerr << "Unknown option: " << arg << std::endl;
            return 1;
        }
    }
#pragma endregion

#pragma region Input Files
    if (options.contains("input")) {
        if (std::ifstream inputFile(options["input"]); inputFile.good()) {
            inputFile.seekg(0, std::ios::end);
            if (std::streampos fileSize = inputFile.tellg(); fileSize == 0) {
                std::cerr << "Error: Input file '" << options["input"] << "' is empty." << std::endl;
                return 1;
            }
            inputFile.seekg(0, std::ios::beg); // wayback
            std::string line;
            while (std::getline(inputFile, line)) {
                lines.push_back(line);
            }
        } else {
            std::cerr << "Error: Input file '" << options["input"] << "' does not exist or cannot be opened." << std::endl;
            return 1;
        }
    }
#pragma endregion

#pragma region XOR
    if (options.contains("xor")) {
        std::cout << "XOR enabled with value: " << options["xor"] << std::endl;
        Encryptor xorEncryptor(std::make_unique<XorString>());

        for (const auto& line : lines) {
            encryptedLines.push_back(xorEncryptor.Encrypt(line, options["xor"]));
        }
    }

    if (options.contains("aes")) {
        std::cout << "AES enabled with key: " << options["aes"] << std::endl;
    }
#pragma endregion

#pragma region Output Files
    if (options.contains("output")) {
        std::ofstream outputFile(options["output"]);
        if (!outputFile) {
            std::cerr << "Error: Output file '" << options["output"] << "' cannot be created or opened." << std::endl;
            return 1;
        }

        if (!encryptedLines.empty()) {
            for (const auto& encryptedLine : encryptedLines) {
                outputFile << encryptedLine << std::endl;
            }
            std::cout << "Encrypted data written to '" << options["output"] << "'." << std::endl;
        } else {
            std::cerr << "Error: No data to write to output file." << std::endl;
            return 1;
        }
    }
#pragma endregion

    std::cout << "Input file: " << options["input"] << std::endl;
    std::cout << "Output file: " << options["output"] << std::endl;

    return 0;
}