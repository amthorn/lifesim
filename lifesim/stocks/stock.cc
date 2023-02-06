#include "lifesim/stocks/stock.h"

#include <string>
#include <vector>

#include "lifesim/stocks/stockpoint.h"

namespace lifesim {

Stock::Stock(std::string name, std::vector<StockPoint> stockpoints) : name_(name), stockpoints_(stockpoints) {}

std::vector<StockPoint> Stock::GetStockpoints() const { return stockpoints_; }
std::string Stock::GetName() const { return name_; }

std::ostream& operator<< (std::ostream& stream, const Stock& stock) {
    stream << "Name: " << stock.name_ << std::endl;
    stream << "Stock Points: " << std::endl;

    for (auto& stockpoint : stock.GetStockpoints()) {
        stream << stockpoint << std::endl;
    }

    return stream;
}

}
