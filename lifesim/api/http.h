#pragma once

#include <string>
#include <vector>

namespace lifesim {

class Http {
    public:
        Http();

        std::string GetRequest(const char* url);
    
        static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
};

}
