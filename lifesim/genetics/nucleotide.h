#pragma once

#include <iostream>
#include <cstdint>
#include <memory>

#include "lifesim/genetics/constants.h"

namespace lifesim {

class Nucleotide {
    public:
        Nucleotide(double value);
        Nucleotide();
        Nucleotide(const Nucleotide& n, std::shared_ptr<NatureConstants> constants);

        std::size_t GetId() const;
        double GetValue() const;

        friend std::ostream& operator<< (std::ostream& stream, const Nucleotide& nucleotide);
    
    private:
        double value_;
};

}
