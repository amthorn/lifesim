#include "lifesim/genetics/featurepoint.h"
#include "lifesim/genetics/feature.h"

#include <iostream>
#include <numeric>

#include "lifesim/macros.h"
#include "lifesim/util.h"

namespace lifesim {

FeaturePoint::FeaturePoint(std::unique_ptr<std::vector<StockPoint>> stockpoints, StockKey stock_key,
            std::vector<double> weights) :
        stockpoints_(std::move(stockpoints)),
        stock_key_(stock_key),
        features_(std::make_unique<std::vector<Feature>>()) {
    LOG(TRACE, "Entering FeaturePoint::FeaturePoint with arguments");
    // Calculate moving average delta
    features_->push_back(Feature(GetMovingAveragePriceDelta(), FeatureType::MOVING_AVERAGE_PRICE_DELTA, weights.at(0)));
    
    // Calculate price momentum
    features_->push_back(Feature(GetPriceMomentum(), FeatureType::PRICE_MOMENTUM, weights.at(1)));

    // Get volume
    features_->push_back(Feature(GetMovingAverageVolumeDelta(), FeatureType::MOVING_AVERAGE_VOLUME_DELTA, weights.at(2)));
    
    // Calculate volume momentum
    features_->push_back(Feature(GetVolumeMomentum(), FeatureType::VOLUME_MOMENTUM, weights.at(3)));
    LOG(TRACE, "Exiting FeaturePoint::FeaturePoint with arguments");
}

FeaturePoint::FeaturePoint(const FeaturePoint& f) :
    stockpoints_(std::make_unique<std::vector<StockPoint>>(*f.stockpoints_)),
    stock_key_(f.stock_key_),
    features_(std::make_unique<std::vector<Feature>>(*f.features_)),
    dna_(f.dna_) {}

std::size_t FeaturePoint::GetId() const {
    return std::hash<std::vector<StockPoint>>{}(*stockpoints_) ^ 
        std::hash<StockKey>{}(stock_key_) ^
        std::hash<std::vector<Feature>>{}(*features_) ^ dna_.GetId();
}

std::ostream& operator<< (std::ostream& stream, const FeaturePoint& featurepoint) {
    stream << "FeaturePoint(stock_key=" << featurepoint.stock_key_ << ")" << std::endl;
    for (const Feature& feature : *featurepoint.features_) {
        stream << feature << std::endl;
    }
    return stream;
}

// multiple feature value * weight to get a positive or negative number.
// add each term together to get a final positive or negative number for this feature point
// if feature point is positive, prediction is that the next stock should go up, vice versa for negative
double FeaturePoint::GetPrediction() const {
    LOG(TRACE, "Entering FeaturePoint::GetPrediction");
    double prediction = 0;
    for (const Feature& feature : *features_) {
        prediction += feature.GetValue() * feature.GetWeight();
    }
    LOG(TRACE, "Exiting FeaturePoint::GetPrediction");
    return prediction;
}

double FeaturePoint::GetAverageVolume(const std::vector<StockPoint>& stockpoints) const {
    std::vector<double> values;
    for (StockPoint s : stockpoints) { values.push_back(s.GetVolume()); }
    return std::accumulate(values.begin(), values.end(), /*init=*/0.0) / values.size();
}

double FeaturePoint::GetMovingAveragePriceDelta() const {
    LOG(TRACE, "Entering FeaturePoint::GetMovingAveragePriceDelta");
    double h_0 = GetAverage(SliceVector<StockPoint>(*stockpoints_, 0, stockpoints_->size()-1));
    double h_1 = GetAverage(SliceVector<StockPoint>(*stockpoints_, 1, stockpoints_->size()-1));
    LOG(TRACE, "Exiting FeaturePoint::GetMovingAveragePriceDelta");
    return h_1 - h_0;
}

double FeaturePoint::GetMovingAverageVolumeDelta() const {
    LOG(TRACE, "Entering FeaturePoint::GetMovingAverageVolumeDelta");
    double h_0 = GetAverageVolume(SliceVector<StockPoint>(*stockpoints_, 0, stockpoints_->size()-1));
    double h_1 = GetAverageVolume(SliceVector<StockPoint>(*stockpoints_, 1, stockpoints_->size()-1));
    return h_1 - h_0;
    LOG(TRACE, "Exiting FeaturePoint::GetMovingAverageVolumeDelta");
}

std::vector<double> FeaturePoint::GetValuesFromStockKey(const std::vector<StockPoint>& stockpoints) const {
    std::vector<double> values;
    for (StockPoint s : stockpoints) {
        values.push_back(GetValueFromStockKey(s));
    }
    return values;
}

double FeaturePoint::GetValueFromStockKey(StockPoint s) const {
    switch(stock_key_) {
        case StockKey::OPEN:
            return s.GetOpen();
        case StockKey::CLOSE:
            return s.GetClose();
        case StockKey::HIGH:
            return s.GetHigh();
        case StockKey::LOW:
        default:
            return s.GetLow();
    }
}

double FeaturePoint::GetValue() const {
    return GetValueFromStockKey(stockpoints_->at(stockpoints_->size()-1));
}
        
double FeaturePoint::GetAverage(const std::vector<StockPoint>& stockpoints) const {
    std::vector<double> values = GetValuesFromStockKey(stockpoints);
    return std::accumulate(values.begin(), values.end(), /*init=*/0.0) / values.size();
}

double FeaturePoint::GetPriceMomentum() const {
    LOG(TRACE, "Entering FeaturePoint::GetPriceMomentum");
    return GetBestFitLine(GetValuesFromStockKey(*stockpoints_)).first;
}

double FeaturePoint::GetVolumeMomentum() const {
    std::vector<double> values;
    for (StockPoint s : *stockpoints_) { values.push_back(s.GetVolume()); }
    return GetBestFitLine(values).first;
}

std::pair<double, double> FeaturePoint::GetBestFitLine(const std::vector<double>& y_values) const {
    int n = y_values.size();
    double sum_x = n * (n + 1) / 2;
    double sum_y = std::accumulate(y_values.begin(), y_values.end(), 0.0);
    double sum_xy = 0;
    double sum_xx = sum_x * sum_x;
    for (int i = 0; i < n; ++i) {
        sum_xy += (i + 1) * y_values[i];
    }
    double slope = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    double y_intercept = (sum_y - slope * sum_x) / n;
    return {slope, y_intercept};
}

}
