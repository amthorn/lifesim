#include "lifesim/genetics/nucleotide.h"

#include <chrono>
#include <iostream>
#include <random>

namespace lifesim {

Nucleotide::Nucleotide(double value) : value_(value) {}

Nucleotide::Nucleotide() {
  std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
  std::uniform_real_distribution<double> distribution(0.0, 1.0);

  value_ = distribution(generator);
}

double Nucleotide::GetValue() const {
    return value_;
}

std::ostream& operator<< (std::ostream& stream, const Nucleotide& nucleotide) {
    stream << "Nucleotide(value=" << nucleotide << ")";
    return stream;
}

}
