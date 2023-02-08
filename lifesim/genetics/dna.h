#pragma once

#include <iostream>
#include <memory>
#include <cstdint>
#include <vector>

#include "lifesim/genetics/constants.h"
#include "lifesim/genetics/nucleotide.h"

namespace lifesim {

class Dna {
    public:
        Dna(std::shared_ptr<std::vector<Nucleotide>> nucleotides);
        Dna();
        Dna(const Dna& d, std::shared_ptr<NatureConstants> constants);

        std::size_t GetId() const;
        std::shared_ptr<std::vector<Nucleotide>> GetNucleotides() const;
        std::vector<double> GetNucleotideValues() const;

        friend std::ostream& operator<< (std::ostream& stream, const Dna& dna);
    
    private:
        std::shared_ptr<std::vector<Nucleotide>> nucleotides_;
};

}
