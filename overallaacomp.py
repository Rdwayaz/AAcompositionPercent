import sys

# Initialize variables to store overall amino acid composition
overall_composition = {aa: 0 for aa in "ACDEFGHIKLMNPQRSTVWY"}
overall_aa_count = 0

if len(sys.argv) != 2:
    print("Usage: python script.py <fasta_file>")
    sys.exit(1)

fasta_file_path = sys.argv[1]

with open(fasta_file_path, "r") as fasta_file:
    current_sequence = ""
    for line in fasta_file:
        if line.startswith(">"):  # Header line
            if current_sequence:
                # Update overall composition
                overall_aa_count += len(current_sequence)
                for aa in current_sequence:
                    if aa in overall_composition:
                        overall_composition[aa] += 1
            current_sequence = ""
        else:
            current_sequence += line.strip()
print(f"{fasta_file_path}")
# Calculate and print overall amino acid composition
print("Overall Amino Acid Composition:")
overall_composition_percentage = {aa: count / overall_aa_count * 100 for aa, count in overall_composition.items()}
for aa, percentage in overall_composition_percentage.items():
    print(f"{aa}: {percentage:.2f}%")

