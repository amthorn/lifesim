#include "lifesim/genetics/nucleotide.h"

namespace lifesim {

Nucleotide::Nucleotide(double value) : value_(value) {}

std::ostream& operator<< (std::ostream& stream, const Nucleotide& nucleotide) {
    stream << "Nucleotide(value=" << nucleotide << ")";
    return stream;
}

}
