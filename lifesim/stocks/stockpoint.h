#pragma once

#include <ostream>
#include <string>
#include <vector>

namespace lifesim {

enum StockKey {
    OPEN = 0,
    CLOSE = 1,
    HIGH = 2,
    LOW = 3
};

class StockPoint {
    public:
        /*
        timestamp: The timestamp for the start of the period
        open: the value of the stockpoint at the open of the period
        close: the value of the stockpoint at the close of the period
        high: the highest value of the stockpoint during the period
        low: the lowest value of the stockpoint during the period
        volume: the volume of stocks traded during the period
        */
        StockPoint(std::string name, int64_t timestamp, double open, double close, double high, double low, int64_t volume);
        StockPoint(const StockPoint& s);

        std::size_t GetId() const;
        std::string GetName() const;
        int64_t GetTimestamp() const;
        double GetOpen() const;
        double GetClose() const;
        double GetHigh() const;
        double GetLow() const;
        int64_t GetVolume() const;
        
        friend std::ostream& operator<< (std::ostream& stream, const StockPoint& stockpoint);

    private:
        std::string name_;
        int64_t timestamp_;
        double open_;
        double close_;
        double high_;
        double low_;
        int64_t volume_;
};

}
