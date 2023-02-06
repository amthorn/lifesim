#include "lifesim/genetics/dna.h"

namespace lifesim {

Dna::Dna(std::shared_ptr<std::vector<double>> nucleotides) : nucleotides_(std::move(nucleotides)) {}
Dna::Dna() {
    // Create new nucleotides
    std::vector<double> foo = {0,0,1,0};
    nucleotides_ = std::make_shared<std::vector<double>>(foo);
}

std::shared_ptr<std::vector<double>> Dna::GetNucleotides() const {
    return nucleotides_;
}

std::ostream& operator<< (std::ostream& stream, const Dna& dna) {
    stream << "DNA()" << std::endl;
    for (double& nucleotide : *dna.nucleotides_) {
        stream << nucleotide << std::endl;
    }
    return stream;
}

}
