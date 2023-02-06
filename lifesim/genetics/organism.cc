#include "lifesim/genetics/organism.h"

#include <iostream>
#include <stdexcept>

#include "lifesim/stocks/stockpoint.h"
#include "lifesim/util.h"

namespace lifesim {

const int8_t kHistoricalPointsNeeded = 10;

/* 
An organism should consist of multiple features for each data point calculated for that stock.
algorithm should determine how much each feature determines the stocks performance
*/
Organism::Organism(std::unique_ptr<Stock> stock, StockKey stock_key, std::unique_ptr<std::vector<Dna>> dna_strands) :
        stock_(std::move(stock)),
        stock_key_(stock_key),
        dna_strands_(std::move(dna_strands)) {
    Create();
}
Organism::Organism(std::unique_ptr<Stock> stock, StockKey stock_key) : stock_(std::move(stock)), stock_key_(stock_key) {
    Create();
}

void Organism::Create() {
    // Throw away the first 10 stockpoints as they will only be used for historical analysis on future featurepoints
    if (stock_ == nullptr) {
        throw std::runtime_error("Stock cannot be null");
    }

    std::vector<StockPoint> stockpoints = stock_->GetStockpoints();
    if (stockpoints.size() < kHistoricalPointsNeeded) {
        throw std::runtime_error("Not enough stockpoints for a valid analysis");
    }
    bool new_organism = dna_strands_ == nullptr;
    if (dna_strands_ == nullptr) {
        dna_strands_ = std::make_unique<std::vector<Dna>>();
    }
    for (uint64_t i = kHistoricalPointsNeeded; i<stockpoints.size(); i++) {
        if (new_organism) {
            dna_strands_->push_back(Dna());
        }
        feature_points_.push_back(FeaturePoint(
            std::make_unique<std::vector<StockPoint>>(
                SliceVector<StockPoint>(stockpoints, i - kHistoricalPointsNeeded, kHistoricalPointsNeeded)),
                stock_key_, dna_strands_->at(i-kHistoricalPointsNeeded).GetNucleotides()));
    }
}

std::ostream& operator<< (std::ostream& stream, const Organism& organism) {
    stream << "Organism()" << std::endl;
    for (const FeaturePoint& f : organism.feature_points_) {
        stream << f << std::endl;
    }
    return stream;
}

}
