#!/usr/bin/perl

use strict;
use warnings;

# Initialize variables to store overall amino acid composition
my %overall_composition = map { $_ => 0 } qw(A C D E F G H I K L M N P Q R S T V W Y);
my $overall_aa_count = 0;

if (@ARGV != 1) {
    print "Usage: perl script.pl <fasta_file>\n";
    exit(1);
}

my $fasta_file_path = $ARGV[0];

open my $fasta_file, "<", $fasta_file_path or die "Cannot open file: $!\n";

my $current_sequence = "";
while (my $line = <$fasta_file>) {
    if ($line =~ /^>/) {  # Header line
        if ($current_sequence) {
            # Update overall composition
            $overall_aa_count += length($current_sequence);
            $overall_composition{$_}++ for split //, $current_sequence;
        }
        $current_sequence = "";
    } else {
        chomp $line;
        $current_sequence .= $line;
    }
}
close $fasta_file;

print "$fasta_file_path\n";

# Calculate and print overall amino acid composition
print "Overall Amino Acid Composition:\n";
my %overall_composition_percentage = map { $_ => $overall_composition{$_} / $overall_aa_count * 100 } keys %overall_composition;
printf "%s: %.2f%%\n", $_, $overall_composition_percentage{$_} for keys %overall_composition_percentage;
