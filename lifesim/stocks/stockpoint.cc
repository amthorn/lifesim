#include "lifesim/stocks/stockpoint.h"

#include <string>
#include <vector>

namespace lifesim {

StockPoint::StockPoint(std::string name, int64_t timestamp, double open, double close, double high, double low, int64_t volume) :
    name_(name),
    timestamp_(timestamp),
    open_(open),
    close_(close),
    high_(high),
    low_(low),
    volume_(volume) {}    

StockPoint::StockPoint(const StockPoint& s) :
    name_(s.name_),
    timestamp_(s.timestamp_),
    open_(s.open_),
    close_(s.close_),
    high_(s.high_),
    low_(s.low_),
    volume_(s.volume_) {}

std::size_t StockPoint::GetId() const {
    return std::hash<std::string>{}(name_) ^ 
        std::hash<int64_t>{}(timestamp_) ^
        std::hash<double>{}(open_) ^
        std::hash<double>{}(close_) ^
        std::hash<double>{}(high_) ^
        std::hash<double>{}(low_) ^
        std::hash<int64_t>{}(volume_);
}

std::ostream& operator<< (std::ostream& stream, const StockPoint& stockpoint) {
    stream << "StockPoint(id=" << stockpoint.GetId() << ", timestamp=" << stockpoint.timestamp_ <<
        ", open=" << stockpoint.open_ << ", close=" << stockpoint.close_ <<
        ", high=" << stockpoint.high_ << ", low=" << stockpoint.low_ <<
        ", volume=" << stockpoint.volume_ << ")";
    return stream;
}

std::string StockPoint::GetName() const { return name_; }
int64_t StockPoint::GetTimestamp() const { return timestamp_; }
double StockPoint::GetOpen() const { return open_; }
double StockPoint::GetClose() const { return close_; }
double StockPoint::GetHigh() const { return high_; }
double StockPoint::GetLow() const { return low_; }
int64_t StockPoint::GetVolume() const { return volume_; }

}
