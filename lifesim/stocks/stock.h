#pragma once

#include <ostream>
#include <string>
#include <vector>

#include "lifesim/stocks/stockpoint.h"

namespace lifesim {

class Stock {
    public:
        Stock(std::string name, std::vector<StockPoint> stockpoints);
        std::size_t GetId() const;
        std::string GetName() const;
        std::vector<StockPoint> GetStockpoints() const;
        
        friend std::ostream& operator<< (std::ostream& stream, const Stock& stock);

    private:
        std::string name_;
        std::vector<StockPoint> stockpoints_;
};

}
