#include "lifesim/genetics/dna.h"

namespace lifesim {

Dna::Dna(std::shared_ptr<std::vector<Nucleotide>> nucleotides) : nucleotides_(std::move(nucleotides)) {}
Dna::Dna() {
    // Create new nucleotides
    std::vector<Nucleotide> nucleotides = {
        Nucleotide(),
        Nucleotide(),
        Nucleotide(),
        Nucleotide()
    };
    nucleotides_ = std::make_shared<std::vector<Nucleotide>>(nucleotides);
}

std::shared_ptr<std::vector<Nucleotide>> Dna::GetNucleotides() const {
    return nucleotides_;
}

std::vector<double> Dna::GetNucleotideValues() const {
    std::vector<double> nucleotides;
    for (const Nucleotide& nucleotide : *nucleotides_) {
        nucleotides.push_back(nucleotide.GetValue());
    }
    return nucleotides;
}

std::ostream& operator<< (std::ostream& stream, const Dna& dna) {
    stream << "DNA()" << std::endl;
    for (Nucleotide nucleotide : *dna.nucleotides_) {
        stream << nucleotide << std::endl;
    }
    return stream;
}

}
