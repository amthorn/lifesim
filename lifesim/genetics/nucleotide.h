#pragma once

#include <iostream>
#include <cstdint>

namespace lifesim {

class Nucleotide {
    public:
        Nucleotide(double value);
        Nucleotide();

        friend std::ostream& operator<< (std::ostream& stream, const Nucleotide& nucleotide);
    
    private:
        double value_;
};

}
