#include "lifesim/api/http.h"

#include <iostream>
#include <stdexcept>

#include <curl/curl.h>

#include "lifesim/macros.h"

namespace lifesim {

Http::Http() {}

size_t Http::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string Http::GetRequest(const char* url) {
  CURL *curl;
  std::string readBuffer;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Http::WriteCallback);
    if (LOG_LEVEL >= DEBUG) {
        curl_easy_setopt(curl, CURLOPT_VERBOSE, true);
    }
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    if (curl_easy_perform(curl)){
        throw std::runtime_error("HTTP Request failed");
    }
    curl_easy_cleanup(curl);

    return readBuffer;
  } else {
      throw std::runtime_error("libcurl failed to initialized.");
  }
}

}
