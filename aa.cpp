#include <iostream>
#include <fstream>
#include <unordered_map>

int main(int argc, char *argv[]) {
    // Initialize variables to store overall amino acid composition
    std::unordered_map<char, int> overall_composition = {
        {'A', 0}, {'C', 0}, {'D', 0}, {'E', 0}, {'F', 0},
        {'G', 0}, {'H', 0}, {'I', 0}, {'K', 0}, {'L', 0},
        {'M', 0}, {'N', 0}, {'P', 0}, {'Q', 0}, {'R', 0},
        {'S', 0}, {'T', 0}, {'V', 0}, {'W', 0}, {'Y', 0}
    };

    int overall_aa_count = 0;

    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <fasta_file>" << std::endl;
        return 1;
    }

    std::ifstream fasta_file(argv[1]);
    if (!fasta_file.is_open()) {
        std::cerr << "Cannot open file: " << argv[1] << std::endl;
        return 1;
    }

    std::string current_sequence;
    std::string line;
    while (std::getline(fasta_file, line)) {
        if (line[0] == '>') {  // Header line
            if (!current_sequence.empty()) {
                // Update overall composition
                overall_aa_count += current_sequence.length();
                for (char aa : current_sequence) {
                    if (overall_composition.find(aa) != overall_composition.end()) {
                        overall_composition[aa]++;
                    }
                }
            }
            current_sequence.clear();
        } else {
            current_sequence += line;
        }
    }

    fasta_file.close();

    std::cout << argv[1] << std::endl;

    // Calculate and print overall amino acid composition
    std::cout << "Overall Amino Acid Composition:" << std::endl;
    for (const auto& entry : overall_composition) {
        char aa = entry.first;
        double percentage = static_cast<double>(entry.second) / overall_aa_count * 100;
        std::cout << aa << ": " << std::fixed << percentage << "%" << std::endl;
    }

    return 0;
}

