#pragma once

#include <iostream>
#include <cstdint>

namespace lifesim {

enum FeatureType {
    MOVING_AVERAGE_PRICE_DELTA = 0,
    MOVING_AVERAGE_VOLUME_DELTA = 1,
    PRICE_MOMENTUM = 2,
    VOLUME_MOMENTUM = 3,
    // INTEREST_RATE = 4,
    // INFLATION = 5
};

class Feature {
    public:
        Feature(double value, FeatureType type, int64_t weight);

        friend std::ostream& operator<< (std::ostream& stream, const Feature& feature);
    
    private:
        double value_;
        FeatureType type_;
        int64_t weight_;
};

}
