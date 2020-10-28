#pragma once
#include "curl/curl.h"

std::string makeCurlRequest(std::string url);
struct deleter {
    void operator()(CURL* curl) {
        if (curl)
            curl_easy_cleanup(curl);
    }
};