#include "lifesim/genetics/organism.h"

#include <iostream>
#include <stdexcept>

#include "lifesim/macros.h"
#include "lifesim/stocks/stockpoint.h"
#include "lifesim/util.h"

namespace lifesim {

/*
An organism should consist of multiple features for each data point calculated for that stock.
algorithm should determine how much each feature determines the stocks performance
*/
Organism::Organism(std::shared_ptr<Stock> stock, StockKey stock_key, std::shared_ptr<std::vector<Dna>> genes, std::shared_ptr<NatureConstants> constants) :
        stock_(std::move(stock)),
        stock_key_(stock_key),
        genes_(std::move(genes)),
        constants_(constants) {
    LOG(TRACE, "Entering Generation Constructor with dna strands.");
    Create();
    LOG(TRACE, "Exiting Generation Constructor with dna strands.");
}
Organism::Organism(std::shared_ptr<Stock> stock, StockKey stock_key, std::shared_ptr<NatureConstants> constants) : 
        stock_(std::move(stock)),
        stock_key_(stock_key),
        constants_(constants) {
    LOG(TRACE, "Entering Generation Constructor without dna strands.");
    Create();
    LOG(TRACE, "Exiting Generation Constructor without dna strands.");
}

Organism::Organism(const Organism& o) :
    stock_(o.stock_),
    stock_key_(o.stock_key_),
    feature_points_(std::make_unique<std::vector<FeaturePoint>>(*o.feature_points_)),
    genes_(std::make_unique<std::vector<Dna>>(*o.genes_)),
    constants_(o.constants_) {}

Organism Organism::Reproduce() const {
    Organism organism(stock_, stock_key_, genes_, constants_);
    return organism;
}

double Organism::GetPrediction() const {
    // Negative means a prediction to go down, positive means a prediction to go up.
    // The greater the absolute value, the stronger the confidence.
    // Note: This obviously assumes stocks can be predicted based on stock history, which is not necessarily true
    // as stocks are affected by millions of factors outside the representation of the historical values of the stock
    // market. This is only going to be accurate within a reasonable margin of error and may not be accurate at all.
    return feature_points_->at(feature_points_->size()-1).GetPrediction();
}

std::pair<double, int64_t> Organism::GetFitnessValues() const {
    if (feature_points_->size() <= 1) {
        // this should never happen
        throw std::runtime_error("Cannot calculate fitness with only one featurepoint");
    }
    int64_t corrects = 0;
    int64_t longest_consecutive = 0;
    int64_t current_consecutive = 0;
    for (uint64_t i = 0; i<feature_points_->size() - 1; i++) {
        double prediction = feature_points_->at(i).GetPrediction();
        LOG(DEBUG, "Prediction: " + std::to_string(prediction));
        if (feature_points_->at(i).GetValue() < feature_points_->at(i+1).GetValue()) {
            // stock actually went up.
            LOG(DEBUG, "Stock went up!");
            if (prediction > 0) {
                LOG(DEBUG, "Prediction was accurate!");
                corrects++;
                current_consecutive++;
            } else if (current_consecutive > 0) {
                // chain is broken.
                longest_consecutive = std::max(current_consecutive, longest_consecutive);
                current_consecutive = 0;
            }
        } else if (feature_points_->at(i).GetValue() == feature_points_->at(i+1).GetValue()) {
            LOG(DEBUG, "Stock stayed the same!");
            if (prediction == 0) {
                LOG(DEBUG, "Prediction was accurate!");
                corrects++;
                current_consecutive++;
            } else if (current_consecutive > 0) {
                // chain is broken.
                longest_consecutive = std::max(current_consecutive, longest_consecutive);
                current_consecutive = 0;
            }
        } else {
            LOG(DEBUG, "Stock went down!");
            if (prediction < 0) {
                LOG(DEBUG, "Prediction was accurate!");
                corrects++;
                current_consecutive++;
            } else if (current_consecutive > 0) {
                // chain is broken.
                longest_consecutive = std::max(current_consecutive, longest_consecutive);
                current_consecutive = 0;
            }
        }
    }
    if (current_consecutive > 0) {
        // chain is broken.
        longest_consecutive = std::max(current_consecutive, longest_consecutive);
        current_consecutive = 0;
    }
    // Calculate percentage of predictions we got correct;
    double correctness = (double)corrects / (feature_points_->size() - 1);

    return std::pair<double, int64_t>(correctness, longest_consecutive);
}

// Take each featurepoint's prediction and compare it with the subsequent featurepoint (excluding the last one)
// count the number of predictions that are correct and divide that by the total to get a floating point value
// representing the organism's fitness
double Organism::GetFitness() const {
    std::pair<double, double> fitness_values = GetFitnessValues();
    // The order of correctness also matters. The more in a row we get right, the better.
    // take (1 - correctness) * (longest_consecutive / size) + correctness
    // this will improve fitness but it will never be more than one since it only takes the difference
    // between 1 and the correctness.
    return ((1 - fitness_values.first) * (fitness_values.second / (feature_points_->size() - 1))) + fitness_values.first;
}

std::size_t Organism::GetId() const {
    return stock_->GetId() ^ 
        std::hash<StockKey>{}(stock_key_) ^
        std::hash<std::vector<FeaturePoint>>{}(*feature_points_) ^
        std::hash<std::vector<Dna>>{}(*genes_);
}

void Organism::Create() {
    LOG(TRACE, "Entering Organism::Create");
    feature_points_ = std::make_unique<std::vector<FeaturePoint>>();

    if (stock_ == nullptr) {
        throw std::runtime_error("Stock cannot be null");
    }

    std::vector<StockPoint> stockpoints = stock_->GetStockpoints();
    if ((int32_t)stockpoints.size() <= constants_->historical_points_needed) {
        throw std::runtime_error("Not enough stockpoints for a valid analysis");
    }
    auto genes = std::make_shared<std::vector<Dna>>();
    for (uint64_t i = constants_->historical_points_needed; i<stockpoints.size(); i++) {
        if (genes_ == nullptr) {
            genes->push_back(Dna());
        } else {
            genes->push_back(Dna(genes_->at(i - constants_->historical_points_needed ), constants_));
        }
        feature_points_->push_back(FeaturePoint(
            std::make_unique<std::vector<StockPoint>>(
                SliceVector<StockPoint>(stockpoints, i - constants_->historical_points_needed, constants_->historical_points_needed)),
                stock_key_, genes->at(i-constants_->historical_points_needed).GetNucleotideValues()));
    }
    genes_ = genes;
    LOG(TRACE, "Exiting Organism::Create");
}

std::shared_ptr<std::vector<Dna>> Organism::GetGenes() const {
    return genes_;
}

std::shared_ptr<Stock> Organism::GetStock() const {
    return stock_;
}

std::ostream& operator<< (std::ostream& stream, const Organism& organism) {
    stream << "Organism(id=" << organism.GetId() << ", featurepoints=size(" <<
        organism.feature_points_->size() << "), fitness=" << organism.GetFitness() << ")";
    return stream;
}

}
