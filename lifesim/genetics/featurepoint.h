#pragma once

#include <memory>
#include <vector>

#include "lifesim/genetics/dna.h"
#include "lifesim/genetics/feature.h"
#include "lifesim/stocks/stockpoint.h"


namespace lifesim {

/* 
Featurepoint represents a stockpoint's featureset. The featurepoint represents an instant in time but calculates
features based on historical data. Features that are worth measuring related to stocks include:

moving average delta (defined by average(h_1, h_n) - average(h_0, h_(n-1)) )
momentum  (defined by linear regression of historical stockpoints)
volume (amplifies momentum slope)

interest rate (todo)
inflation (todo)
*/
class FeaturePoint {
    public:
        /* 
        stockpoints should be an in-order vector of StockPoints where the last object in the vector is the stockpoint
        whose timestamp matches this feature point.
        */
        FeaturePoint(std::unique_ptr<std::vector<StockPoint>> stockpoints, StockKey stock_key,
            std::vector<double> weights);
        std::vector<double> GetValuesFromStockKey(const std::vector<StockPoint>& stockpoints) const;
        double GetMovingAveragePriceDelta() const;
        double GetMovingAverageVolumeDelta() const;
        double GetAverage(const std::vector<StockPoint>& stockpoints) const;
        double GetAverageVolume(const std::vector<StockPoint>& stockpoints) const;
        double GetPriceMomentum() const;
        double GetVolumeMomentum() const;
        std::pair<double, double> GetBestFitLine(const std::vector<double>& y_values) const;

        friend std::ostream& operator<< (std::ostream& stream, const FeaturePoint& featurepoint);
    
    private:
        std::unique_ptr<std::vector<StockPoint>> stockpoints_;
        // This value tells the featurepoint which key it should use to evaluate the value of the stockpoint
        StockKey stock_key_;
        std::vector<Feature> features_;
        Dna dna_;
};

}
