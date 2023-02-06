#pragma once

#include <iostream>
#include <memory>
#include <cstdint>
#include <vector>

namespace lifesim {

class Dna {
    public:
        Dna(std::shared_ptr<std::vector<double>> nucleotides);
        Dna();
        std::shared_ptr<std::vector<double>> GetNucleotides() const;

        friend std::ostream& operator<< (std::ostream& stream, const Dna& dna);
    
    private:
        std::shared_ptr<std::vector<double>> nucleotides_;
};

}
