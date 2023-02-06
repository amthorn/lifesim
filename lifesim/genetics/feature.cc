#include "lifesim/genetics/feature.h"

namespace lifesim {

Feature::Feature(double value, FeatureType type, double weight) : value_(value), type_(type), weight_(weight) {}

std::ostream& operator<< (std::ostream& stream, const Feature& feature) {
    stream << "Feature(value=" << feature.value_ <<
        ", type=" << feature.type_ <<
        ", weight=" << feature.weight_ << ")";
    return stream;
}

}
