#pragma once

namespace lifesim {

// One for each feature within a featurepoint.
const int8_t kNucleotideCount = 4;

struct GeneticDriftConfig {
    // Likelihood of genetic drift within 1 generation
    const float drift_probability = 0.001;  // 0.1%
    // Percentage of organisms that will be affected by each genetic drift event.
    // Set to -1 to have the impact percentage be random.
    const float impact = -1.0;
};

// These can be tweaked per-generation to simulate mass extinction.
struct NatureConstants {
    // the +-range that a particular nucleotide can mutate.
    const float mutation_variability = 0.15;
    // The number of children that each organismm should have.
    const int8_t number_of_children = 3;
    // The number of organisms that exist in each generation.
    const int8_t generation_size = 50;
    // The percentage (as a decimal) of the generation that (at most) survives to reproduce.
    const float survival_percentage = 0.1;
    // Total number of generations.
    const int32_t generations = 10000;
    // The number of stockpoints that will be used simply for historical analysis on future featurepoints rather
    // than as a gene.
    const int8_t historical_points_needed = 10;
    // Configure genetic drift.
    const GeneticDriftConfig genetic_drift_config;
};

}
