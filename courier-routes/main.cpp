#include <iostream>
#include "functions.h"

int main(int argc, char* argv[]) {
    if (argc < 5) {
        instruction();
        return 0;
    }

    std::string inputFile;
    std::string outputFile;

    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-i") {
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                inputFile = argv[++i];
            } else {
                std::cout << "Nie podano pliku wejsciowego" <<std::endl;
                return 0;
            }
        } else if (std::string(argv[i]) == "-d") {
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                outputFile = argv[++i];
            } else {
                std::cout << "Nie podano pliku wyjsciowego" <<std::endl;
                return 0;
            }
        }
    }

    processFile(inputFile, outputFile);
    return 0;
}
