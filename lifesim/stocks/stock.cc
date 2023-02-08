#include "lifesim/stocks/stock.h"

#include <string>
#include <vector>

#include "lifesim/stocks/stockpoint.h"
#include "lifesim/util.h"

namespace lifesim {

Stock::Stock(std::string name, std::vector<StockPoint> stockpoints) : name_(name), stockpoints_(stockpoints) {}

std::vector<StockPoint> Stock::GetStockpoints() const { return stockpoints_; }
std::string Stock::GetName() const { return name_; }

std::size_t Stock::GetId() const {
    return std::hash<std::string>{}(name_) ^
            std::hash<std::vector<lifesim::StockPoint>>{}(stockpoints_);
}

std::ostream& operator<< (std::ostream& stream, const Stock& stock) {
    stream << "Stock(id=" << stock.GetId() << ", name=" << stock.name_ << ")" << std::endl;
    return stream;
}

}
