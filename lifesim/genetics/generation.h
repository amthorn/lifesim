#pragma once

#include <memory>
#include <vector>

#include "lifesim/genetics/constants.h"
#include "lifesim/genetics/organism.h"
#include "lifesim/stocks/stock.h"

namespace lifesim {

class Generation {
    public:
        // Brand new initial generation
        Generation(std::shared_ptr<Stock> stock, StockKey stock_key, std::shared_ptr<NatureConstants> constants);

        // Generation to be mutated from previous surviving organisms
        Generation(std::unique_ptr<std::vector<Organism>> initial, std::shared_ptr<NatureConstants> constants);

        void Drift();

        std::vector<Organism>* GetPopulation() const;
        std::vector<Organism> FitnessFunction() const;
        double FitnessFunction(const Organism& organism) const;

    private:
        std::shared_ptr<NatureConstants> constants_;
        std::shared_ptr<Stock> stock_;
        std::unique_ptr<std::vector<Organism>> population_;
};

}
