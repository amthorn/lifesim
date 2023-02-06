#pragma once

#include <iostream>
#include <memory>
#include <cstdint>
#include <vector>

#include "lifesim/genetics/nucleotide.h"

namespace lifesim {

class Dna {
    public:
        Dna(std::shared_ptr<std::vector<Nucleotide>> nucleotides);
        Dna();
        std::shared_ptr<std::vector<Nucleotide>> GetNucleotides() const;
        std::vector<double> GetNucleotideValues() const;

        friend std::ostream& operator<< (std::ostream& stream, const Dna& dna);
    
    private:
        std::shared_ptr<std::vector<Nucleotide>> nucleotides_;
};

}
