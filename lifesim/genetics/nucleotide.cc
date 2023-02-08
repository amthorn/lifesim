#include "lifesim/genetics/nucleotide.h"

#include <chrono>
#include <iostream>
#include <random>

#include "lifesim/macros.h"

namespace lifesim {

Nucleotide::Nucleotide(double value) : value_(value) {}

Nucleotide::Nucleotide() {
    LOG(TRACE, "Entering Nucleotide::Nucleotide without arguments");
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    value_ = distribution(generator);
    LOG(TRACE, "Exiting Nucleotide::Nucleotide without arguments");
}

Nucleotide::Nucleotide(const Nucleotide& n, std::shared_ptr<NatureConstants> constants) {
    LOG(TRACE, "Entering Nucleotide::Nucleotide mutation constructor");
    float lower_bound = n.value_ - constants->mutation_variability;
    float upper_bound = n.value_ + constants->mutation_variability;
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distribution(lower_bound, upper_bound);

    value_ = distribution(generator);
    LOG(TRACE, "Exiting Nucleotide::Nucleotide mutation constructor");
}

std::size_t Nucleotide::GetId() const { return std::hash<double>{}(value_); }
double Nucleotide::GetValue() const { return value_; }

std::ostream& operator<< (std::ostream& stream, const Nucleotide& nucleotide) {
    stream << "Nucleotide(id=" << nucleotide.GetId() << ", value=" << nucleotide.value_ << ")";
    return stream;
}

}
