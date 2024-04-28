#include <iostream>
#include <fstream>
#include <unordered_map>

int main(int argc, char *argv[]) {
    // Initialize variables to store overall nucleotide composition
    std::unordered_map<char, int> overall_composition = {
        {'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}, {'U', 0}
    };

    int overall_nt_count = 0;

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
                overall_nt_count += current_sequence.length();
                for (char nt : current_sequence) {
                    if (overall_composition.find(nt) != overall_composition.end()) {
                        overall_composition[nt]++;
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

    // Calculate and print overall nucleotide composition
    std::cout << "Overall Nucleotide Composition:" << std::endl;
    for (const auto& entry : overall_composition) {
        char nt = entry.first;
        double percentage = static_cast<double>(entry.second) / overall_nt_count * 100;
        std::cout << nt << ": " << std::fixed << percentage << "%" << std::endl;
    }

    return 0;
}

