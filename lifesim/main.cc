#include <stdio.h>
#include <string>
#include <vector>

#include "lifesim/genetics/organism.h"
#include "lifesim/macros.h"
#include "lifesim/stocks/market.h"
#include "lifesim/stocks/stock.h"

int main() {
    LOG(DEBUG, "Starting...");
    lifesim::Market market;
    auto stock = std::make_unique<lifesim::Stock>(market.GetStock("GOOG"));
    // std::cout << *stock << std::endl;
    // std::cout << "Number of Stockpoints: " << stock->GetStockpoints().size();
    lifesim::Organism organism(std::move(stock), lifesim::StockKey::OPEN);
    std::cout << organism << std::endl;
    return 0;
}
