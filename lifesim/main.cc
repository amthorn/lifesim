#include <stdio.h>
#include <string>
#include <vector>

#include "lifesim/genetics/evolution.h"
#include "lifesim/macros.h"
#include "lifesim/stocks/market.h"
#include "lifesim/stocks/stock.h"

int main() {
    LOG(DEBUG, "Starting...");
    lifesim::Market market;
    lifesim::Evolution evolution(market.GetStock("CHGG"), lifesim::StockKey::OPEN);
    return 0;
}
