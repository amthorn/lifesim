#include "lifesim/genetics/dna.h"

#include "lifesim/genetics/constants.h"
#include "lifesim/macros.h"
#include "lifesim/util.h"

namespace lifesim {

Dna::Dna(std::shared_ptr<std::vector<Nucleotide>> nucleotides) : nucleotides_(std::move(nucleotides)) {}
Dna::Dna() {
    LOG(TRACE, "Entering Dna::Dna without arguments");
    // Create new nucleotides
    std::vector<Nucleotide> nucleotides;
    for (int i = 0; i < kNucleotideCount; i ++) {
        nucleotides.push_back(Nucleotide());
    }
    nucleotides_ = std::make_shared<std::vector<Nucleotide>>(nucleotides);
    LOG(TRACE, "Exiting Dna::Dna without arguments");
}

Dna::Dna(const Dna& d, std::shared_ptr<NatureConstants> constants) {
    // This is where nucleotides are mutated based on the NatureConstants config
    nucleotides_ = std::make_shared<std::vector<Nucleotide>>();
    for (const Nucleotide& nucleotide : *d.nucleotides_) {
        // Mutate nucleotide
        nucleotides_->push_back(Nucleotide(nucleotide, constants));
    }
}

std::size_t Dna::GetId() const {
    return std::hash<std::vector<lifesim::Nucleotide>>{}(*nucleotides_);
}

std::shared_ptr<std::vector<Nucleotide>> Dna::GetNucleotides() const {
    return nucleotides_;
}

std::vector<double> Dna::GetNucleotideValues() const {
    LOG(TRACE, "Entering Dna::GetNucleotideValues");
    std::vector<double> nucleotides;
    for (const Nucleotide& nucleotide : *nucleotides_) {
        nucleotides.push_back(nucleotide.GetValue());
    }
    LOG(TRACE, "Exiting Dna::GetNucleotideValues");
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
