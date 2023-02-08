#pragma once

#include <memory>
#include <vector>

#include "lifesim/genetics/dna.h"
#include "lifesim/genetics/featurepoint.h"
#include "lifesim/stocks/stock.h"

namespace lifesim {

class Organism {
    public:
        Organism(Organism&& other) = default;
        Organism& operator=(Organism&& other) = default;
        Organism(std::shared_ptr<Stock> stock, StockKey stock_key, std::shared_ptr<std::vector<Dna>> genes_, std::shared_ptr<NatureConstants> constant);
        Organism(std::shared_ptr<Stock> stock, StockKey stock_key, std::shared_ptr<NatureConstants> constant);
        Organism(const Organism& o);
        Organism Reproduce() const;
        std::size_t GetId() const;
        std::shared_ptr<Stock> GetStock() const;
        double GetPrediction() const;
        std::pair<double, int64_t> GetFitnessValues() const;
        double GetFitness() const;
        std::shared_ptr<std::vector<Dna>> GetGenes() const;

        friend std::ostream& operator<< (std::ostream& stream, const Organism& organism);

    private:
        void Create();
        void SetDnaStrands();

        std::shared_ptr<Stock> stock_;
        StockKey stock_key_;
        std::unique_ptr<std::vector<FeaturePoint>> feature_points_;
        // Needs to be a shared pointer for reproduction.
        std::shared_ptr<std::vector<Dna>> genes_;
        std::shared_ptr<NatureConstants> constants_;
};

}
