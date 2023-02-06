#include "lifesim/genetics/featurepoint.h"
#include "lifesim/genetics/feature.h"

#include <iostream>
#include <numeric>

#include "lifesim/util.h"

namespace lifesim {

FeaturePoint::FeaturePoint(std::unique_ptr<std::vector<StockPoint>> stockpoints, StockKey stock_key,
            std::vector<double> weights) :
        stockpoints_(std::move(stockpoints)),
        stock_key_(stock_key){
    // Calculate moving average delta
    features_.push_back(Feature(GetMovingAveragePriceDelta(), FeatureType::MOVING_AVERAGE_PRICE_DELTA, weights.at(0)));
    
    // Calculate price momentum
    features_.push_back(Feature(GetPriceMomentum(), FeatureType::PRICE_MOMENTUM, weights.at(1)));

    // Get volume
    features_.push_back(Feature(GetMovingAverageVolumeDelta(), FeatureType::MOVING_AVERAGE_VOLUME_DELTA, weights.at(2)));
    
    // Calculate volume momentum
    features_.push_back(Feature(GetVolumeMomentum(), FeatureType::VOLUME_MOMENTUM, weights.at(3)));
}

std::ostream& operator<< (std::ostream& stream, const FeaturePoint& featurepoint) {
    stream << "FeaturePoint(stock_key=" << featurepoint.stock_key_ << ")" << std::endl;
    for (const Feature& f : featurepoint.features_) {
        stream << f << std::endl;
    }
    return stream;
}

double FeaturePoint::GetAverageVolume(const std::vector<StockPoint>& stockpoints) const {
    std::vector<double> values;
    for (StockPoint s : stockpoints) { values.push_back(s.GetVolume()); }
    return std::accumulate(values.begin(), values.end(), /*init=*/0.0) / values.size();
}

double FeaturePoint::GetMovingAveragePriceDelta() const {
    double h_0 = GetAverage(SliceVector<StockPoint>(*stockpoints_, 0, stockpoints_->size()-1));
    double h_1 = GetAverage(SliceVector<StockPoint>(*stockpoints_, 1, stockpoints_->size()-1));
    return h_1 - h_0;
}

double FeaturePoint::GetMovingAverageVolumeDelta() const {
    double h_0 = GetAverageVolume(SliceVector<StockPoint>(*stockpoints_, 0, stockpoints_->size()-1));
    double h_1 = GetAverageVolume(SliceVector<StockPoint>(*stockpoints_, 1, stockpoints_->size()-1));
    return h_1 - h_0;
}

std::vector<double> FeaturePoint::GetValuesFromStockKey(const std::vector<StockPoint>& stockpoints) const {
    std::vector<double> values;
    switch(stock_key_) {
        case StockKey::OPEN:
            for (StockPoint s : stockpoints) { values.push_back(s.GetOpen()); }
            break;
        case StockKey::CLOSE:
            for (StockPoint s : stockpoints) { values.push_back(s.GetClose()); }
            break;
        case StockKey::HIGH:
            for (StockPoint s : stockpoints) { values.push_back(s.GetHigh()); }
            break;
        case StockKey::LOW:
            for (StockPoint s : stockpoints) { values.push_back(s.GetLow()); }
            break;
    }
    return values;
}
        
double FeaturePoint::GetAverage(const std::vector<StockPoint>& stockpoints) const {
    std::vector<double> values = GetValuesFromStockKey(stockpoints);
    return std::accumulate(values.begin(), values.end(), /*init=*/0.0) / values.size();
}

double FeaturePoint::GetPriceMomentum() const {
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
