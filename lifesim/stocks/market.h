#pragma once

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "lifesim/api/http.h"
#include "lifesim/stocks/stock.h"

namespace lifesim {

class Market {
    public:
        Market();

        Stock GetStock(std::string name);

    template <typename T> std::vector<T> GetDataPoints(nlohmann::json raw, std::string key);
    
    private:
        Http http_;
};

}
