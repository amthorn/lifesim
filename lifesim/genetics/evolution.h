#pragma once

#include <memory>
#include <vector>

#include "lifesim/genetics/constants.h"
#include "lifesim/genetics/organism.h"
#include "lifesim/stocks/stock.h"

namespace lifesim {

class Evolution {
    public:
        Evolution(std::shared_ptr<Stock> stock, StockKey stock_key);

    private:
        std::shared_ptr<Stock> stock_;
        StockKey stock_key_;

};

}
