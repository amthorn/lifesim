#include "lifesim/genetics/evolution.h"

#include <iostream>

#include "lifesim/genetics/generation.h"
#include "lifesim/macros.h"

namespace lifesim {

Evolution::Evolution(std::shared_ptr<Stock> stock, StockKey stock_key) : stock_(stock), stock_key_(stock_key) {
    auto constants = std::make_shared<NatureConstants>();

    Generation current_generation(stock_, stock_key_, constants);
    auto fittest = std::make_unique<std::vector<Organism>>(current_generation.FitnessFunction());

    for (int i = 0; i < constants->generations; i++){
        LOG(INFO, "Generation " + std::to_string(i) + " beginning.");
        // Create new generation
        current_generation = Generation(std::move(fittest), constants);
        fittest = std::make_unique<std::vector<Organism>>(current_generation.FitnessFunction());
        LOG(INFO, "Fittest is: " + std::to_string(fittest->at(0).GetFitness()));
    }

    int32_t stockpoint_size = stock->GetStockpoints().size();
    int64_t prediction = fittest->at(0).GetPrediction();
    LOG(INFO, "Evolution Complete.");
    LOG(INFO, "Percentage Correct: " + std::to_string(fittest->at(0).GetFitnessValues().first * 100) + "%");
    LOG(INFO, "Longest Segment: " + std::to_string(fittest->at(0).GetFitnessValues().second) + "/" + std::to_string(stockpoint_size - 1));
    LOG(INFO, "Prediction: " + std::to_string(prediction) + (prediction > 0 ? " (stock will go up)" : " (stock will go down)"));
}

}
