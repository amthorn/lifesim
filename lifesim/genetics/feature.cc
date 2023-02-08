#include "lifesim/genetics/feature.h"

namespace lifesim {

Feature::Feature(double value, FeatureType type, double weight) : value_(value), type_(type), weight_(weight) {}
Feature::Feature(const Feature& f) :
    value_(f.value_),
    type_(f.type_),
    weight_(f.weight_) {}

std::ostream& operator<< (std::ostream& stream, const Feature& feature) {
    stream << "Feature(id=" << feature.GetId() << ", value=" << feature.value_ <<
        ", type=" << feature.type_ <<
        ", weight=" << feature.weight_ << ")";
    return stream;
}

std::size_t Feature::GetId() const {
    return std::hash<double>{}(value_) ^ 
        std::hash<lifesim::FeatureType>{}(type_) ^
        std::hash<double>{}(weight_);
}
double Feature::GetValue() const { return value_; }
double Feature::GetWeight() const { return weight_; }

}
