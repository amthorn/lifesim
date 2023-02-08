#include "lifesim/genetics/generation.h"

#include <chrono>
#include <cmath>
#include <iostream>
#include <random>

#include "lifesim/macros.h"

namespace lifesim {

Generation::Generation(std::shared_ptr<Stock> stock, StockKey stock_key, std::shared_ptr<NatureConstants> constants) :
        constants_(constants),
        stock_(stock),
        population_(std::make_unique<std::vector<Organism>>()) {
    LOG(TRACE, "Entering Generation Constructor.");
    for (int8_t i = 0; i<constants_->generation_size; i++) {
        population_->push_back(Organism(stock, stock_key, constants));
    }
    LOG(TRACE, "Exiting Generation Constructor.");
}

Generation::Generation(std::unique_ptr<std::vector<Organism>> initial, std::shared_ptr<NatureConstants> constants) :
        constants_(constants),
        stock_(initial->at(0).GetStock()),
        population_(std::make_unique<std::vector<Organism>>()) {
    LOG(TRACE, "Entering Generation From Organisms Constructor.");
    for (const Organism& organism : *initial) {
        for (int8_t i = 0; i<constants_->number_of_children; i++) {
            population_->push_back(organism.Reproduce());
        }
    }
    LOG(TRACE, "Exiting Generation From Organisms Constructor.");

}

std::vector<Organism>* Generation::GetPopulation() const {
    return population_.get();
}

std::vector<Organism> Generation::FitnessFunction() const {
    std::vector<Organism> most_fittest = *population_;

    // Sort the input vector in descending order
    std::sort(most_fittest.begin(), most_fittest.end(), [](const Organism& a, const Organism& b) {
        return a.GetFitness() > b.GetFitness();
    });

    // Create a new vector with the first X elements of the sorted input vector
    auto count = std::min((int8_t)(constants_->survival_percentage*constants_->generation_size), (int8_t)most_fittest.size());
    std::vector<Organism> result(most_fittest.begin(), most_fittest.begin() + count);

    return result;
}

void Generation::Drift() {
    // This function implements a genetic drift
    // Randomly select a gene to drift
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());

    // size of the genepool within each organism in the generation is defined by the number of stockpoints minus
    // the number of stock points needed for historical analysis.
    std::uniform_int_distribution<int32_t> distribution(
        0, stock_->GetStockpoints().size() - constants_->historical_points_needed);
    std::uniform_int_distribution<int8_t> nucleotide_distribution(0, 3);
    std::uniform_real_distribution<double> percentage_distribution(0.0, 1.0);

    int32_t gene_number = distribution(generator);
    int8_t nucleotide_number = nucleotide_distribution(generator);

    // If impact is -1, randomly decide on an impact percentage
    int8_t impact = constants_->genetic_drift_config.impact;
    if (impact == -1) {
        impact = percentage_distribution(generator);
        LOG(DEBUG, "Impact percent randomly chosen to be: " + std::to_string(impact) + "%");
    }

    // Get upper and lower bound of nucleotide values so we know the range that needs to drift
    double lower_bound = INFINITY;
    double upper_bound = -INFINITY;
    for (const Organism& organism : *population_) {
        double current_nucleotide = organism.GetGenes()->at(gene_number).GetNucleotideValues().at(nucleotide_number);
        if (current_nucleotide > upper_bound) {
            upper_bound = current_nucleotide;
        }
        if (current_nucleotide < lower_bound) {
            lower_bound = current_nucleotide;
        }
    }

    // kill the organisms that are within a range 0.001 of a randomly chosen nucleotide value within the range.
    // If this does not measure up to the impact natural constant, then increase the range by 0.001 until
    // IMPACT% of the population will be affected or until one side of the range reaches an edge. If one side reaches
    // an edge, stop increasing that side but continuing increasing the other side until IMPACT% is killed off.
    // TODO(avathorn): finish this
    // LOG(INFO, "Genetic drift has occurred which affected " + std::to_string(x) + "% of the population");
}

}
