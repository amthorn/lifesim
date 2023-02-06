#pragma once

#include <memory>
#include <vector>

#include "lifesim/genetics/dna.h"
#include "lifesim/genetics/featurepoint.h"
#include "lifesim/stocks/stock.h"

namespace lifesim {

class Organism {
    public:
        Organism(std::unique_ptr<Stock> stock, StockKey stock_key, std::unique_ptr<std::vector<Dna>> dna_strands);
        Organism(std::unique_ptr<Stock> stock, StockKey stock_key);

        friend std::ostream& operator<< (std::ostream& stream, const Organism& organism);

    private:
        void Create();
        void SetDnaStrands();

        std::unique_ptr<Stock> stock_;
        StockKey stock_key_;
        std::vector<FeaturePoint> feature_points_;
        std::unique_ptr<std::vector<Dna>> dna_strands_;
};

}
