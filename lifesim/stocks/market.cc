#include "lifesim/stocks/market.h"

#include "lifesim/macros.h"
#include "lifesim/stocks/stockpoint.h"


namespace lifesim {

const std::string kStockUrl = "https://query1.finance.yahoo.com/v8/finance/chart/";
const std::string kRange = "1mo";
const std::string kInterval = "1h";

Market::Market() {}

template <typename T>
std::vector<T> Market::GetDataPoints(nlohmann::json raw, std::string key) {
    std::vector<T> values;
    for (auto it : raw[key]) {
        values.push_back(it);
    }
    return values;
}

std::unique_ptr<Stock> Market::GetStock(std::string name) {
    std::string full_url = kStockUrl + name + "?range=" + kRange + "&interval=" + kInterval;
    LOG(DEBUG, "Getting stock from URL: " + full_url);

    nlohmann::json parsed = nlohmann::json::parse(http_.GetRequest(full_url.c_str()).c_str());

    nlohmann::json values = parsed["chart"]["result"][0]["indicators"]["quote"][0];
    std::vector<double> closes = GetDataPoints<double>(values, "close");
    std::vector<double> opens = GetDataPoints<double>(values, "open");
    std::vector<double> highs = GetDataPoints<double>(values, "high");
    std::vector<double> lows = GetDataPoints<double>(values, "low");
    std::vector<int64_t> volumes = GetDataPoints<int64_t>(values, "volume");
    std::vector<int64_t> timestamps = GetDataPoints<int64_t>(parsed["chart"]["result"][0], "timestamp");

    std::vector<StockPoint> stock_points;

    for (uint64_t i = 0; i<timestamps.size(); i++) {
        stock_points.push_back(StockPoint(name, timestamps[i], opens[i], closes[i], highs[i], lows[i], volumes[i]));
    }

    return std::make_unique<Stock>(name, stock_points);
}

}
